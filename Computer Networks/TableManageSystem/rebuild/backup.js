new Vue({
    el: '#app',
    data() {
        return {
            // 获取数据参数
            pageIndex: '1',
            pageSize: '10',
            // 表格数据
            tableData: [],
            // 查询
            search: '',
            // 分页
            totalDataNum: 0,
            currentPage: 1,
            // 表单
            form: {
                sno: '',
                sname: '',
                certify: '',
                titleno: '',
                titlename: '',
                isInput: false,
                // index: -1
            },
            formLabelWidth: '120px',
            // 状态
            isEdit: false,
            isAdd: false,
            isSearch: false,
            // 当前编辑行，-1说明无输入框
            index: -1,
            // 废除按钮
            disabledSno: false,
            disabledButton: false,
            // 校验规则
            rules: {
                sno: [
                    { required: true, message: '请输入sno', trigger: 'blur' },
                ],
                sname: [
                    { required: true, message: '请输入sname', trigger: 'blur' },
                ],
                certify: [
                    { required: true, message: '请输入certify', trigger: 'blur' },
                    { min: 18, max: 18, message: '请输入正确身份证号', trigger: 'change' },
                ],
                titleno: [
                    { min: 2, max: 2, message: '长度必须为2个字符', trigger: 'change' },
                    { required: true, message: '请输入titleno', trigger: 'blur' }
                ],
                titlename: [
                    { required: true, message: '请输入titlename', trigger: 'blur' }
                ]
            },
            // 上传文件列表
            fileList: [],
            // 查询
            state: '',
            queryResults: [],
            tempLen: 0,
            tempData: [],
        }
    },
    methods: {
        // 表单校验
        submitForm(formName) {
            this.$refs[formName].validate((valid) => {
                if (valid) {
                    alert('submit!');
                } else {
                    console.log('error submit!!');
                    return false;
                }
            });
        },
        resetForm(formName) {
            this.$refs[formName].resetFields();
        },


        // 重置所有参数
        refresh() {
            this.isAdd = false;
            this.isEdit = false;
            this.tableData[this.index] = false;
            this.index = -1;
            this.disabledSno = false;
            this.disabledButton = false;
        },

        test() {

        },

        alertMessage(message, type, duration) {
            this.$message({
                message: message,
                type: type,
                duration: duration
            });
        },

        // 切换页面
        handleSizeChange(val) {
            this.refresh();
            this.pageSize = `${val}`;
            this.getData();
        },
        handleCurrentChange(val) {
            this.refresh();
            this.pageIndex = `${val}`;
            this.getData();
        },

        // 点击 添加数据 按钮触发
        handleAdd() {
            this.isAdd = true;
            this.index = 0;
            this.disabledButton = true;
            this.form = { sno: '', sname: '', certify: '', titleno: '', titlename: '' };
            this.tableData.unshift(this.form);
            this.tableData[0].isInput = true;
            console.log(this.form);
        },

        // 点击 Delete 按钮触发
        deleteOrCancel(index, row) {
            // 无编辑框 => 删除当前行数据
            // Delete
            if (this.index == -1) {
                this.handleDelete(index, row);
                this.alertMessage("删除成功", "success", 1000);
            }

            // 有编辑框
            // 当前行的 Cancel
            else if (this.index != -1 && this.index == index) {
                this.refresh();
                this.getData();
                this.alertMessage("取消操作", "warning", 1000);
            }
            // 其他行的 Delete
            else {
                this.alertMessage("请完成当前操作", "error", 1000);
                // console.log("其他行的Delete");
            }
        },
        handleDelete(index, row) {
            this.deleteData(row.sno);
        },

        // 点击 Edit/Submit 按钮触发
        editOrSubmit(index, formName) {
            // 如果无输入框 而且 输入框与当前点击行不匹配
            // 则应将当前行变为输入框
            if (this.index == -1 && this.index != index) {
                // 更新输入框位置
                this.index = index;
                this.isEdit = true;
                // sno 不可编辑, button 失效
                this.disabledSno = true;
                this.disabledButton = true;

                // 变成输入框格式
                this.tableData[index].isInput = true;
                this.formGetData(this.index);
                // console.log(this.form);
            }

            // 为 Submit 状态
            else if (this.isEdit == true || this.isAdd == true) {
                // 有输入框处于编辑或添加状态 => 其他 Edit/Delte 应失效
                // Edit 提交
                if (this.isEdit == true && this.index == index) {
                    this.$refs[formName].validate((valid) => {
                        if (valid) {
                            // alert('submit!');
                            this.handleEdit();
                            // 重置参数
                            this.refresh();
                            this.alertMessage("编辑成功", "success", 1000);
                        } else {
                            console.log('error submit!!');
                            return false;
                        }
                    });

                } else if (this.isAdd == true && this.index == index) {
                    this.$refs[formName].validate((valid) => {
                        if (valid) {
                            this.addData();
                            this.refresh();
                            this.alertMessage("添加成功", "success", 1000);
                        } else {
                            console.log('error submit!!');
                            return false;
                        }
                    });

                } else {
                    this.alertMessage("请完成当前操作", "error", 1000);
                }
            }
            else {
                // console.log('edit/submit的第三种状态');
            }
        },

        handleEdit(index, row) {
            this.editData();
        },

        //查 ↓
        async querySearch(queryString, cb) {
            await this.queryData(queryString);
            var queryResults = this.queryResults;
            var results = queryString ? queryResults.filter(this.createStateFilter(queryString)) : queryResults;
            // cb(results);
            clearTimeout(this.timeout);
            this.timeout = setTimeout(() => {
                cb(results);
            }, 3000 * Math.random());
        },
        createStateFilter(queryString) {
            return (states) => {
                return (states.sname.toLowerCase().indexOf(queryString.toLowerCase()) !== -1);
            };
        },
        handleSelect(item) {

        },
        // handleFliter() {
        //     // 根据 item.sname 来筛选所有数据，将他们加入到 tableData 中
        //     // console.log(item);

        //     // 存下 pageSize
        //     var tempPageSize = this.pageSize;
        //     // 在所有数据中搜索
        //     this.pageSize = this.totalDataNum;
        //     this.getData()
        //     console.log(this.tableData);

        //     for (var i = 0; i < this.tableData.length; ++i) {
        //         //     this.form = { sno: '', sname: '', certify: '', titleno: '', titlename: '' };
        //         // this.tableData.unshift(this.form);
        //         // 包含该段字符串，则添加进 tempData
        //         if (this.tableData[i].sname.includes(item.sname)) {
        //             this.tempData.push(this.tableData[i]);
        //             console.log("this.tempData = " + this.tempData);
        //         }
        //     }

        //     // // 更换页面大小
        //     // this.pageSize = this.tempLen;
        //     // this.getData();
        //     // this.tableData = this.tempData;
        // },
        //查 ↑

        // 对 form 表单的操作
        clearForm() {
            this.form = {
                sno: '',
                sname: '',
                certify: '',
                titleno: '',
                titlename: '',
            };
        },
        // form表单 获取指定行数据
        formGetData(index) {
            this.form = this.tableData[index];
        },

        // 对 tableData[] 的操作
        isInputFalse(index) {
            for (var i = 0; i < this.tableData.length; i++) {
                this.tableData[i].isInput = false;
            }
        },

        // 增删改查调用接口 ↓
        getData(index) {
            var that = this;
            axios.get('https://water.hrenergy.cn/WeatherForecast/Subject', {
                params: {
                    pageIndex: that.pageIndex,
                    pageSize: that.pageSize
                }
            })
                .then(function (response) {
                    that.tableData = response.data.data;
                    that.totalDataNum = response.data.total;
                    that.isInputFalse();
                })
                .catch(function (error) {
                    console.log(error);
                })
                .then(function () {
                    // always executed
                });
        },
        addData() {
            var that = this;
            axios.post('https://water.hrenergy.cn/WeatherForecast/AddSubject', {
                sno: that.form.sno,
                sname: that.form.sname,
                certify: that.form.certify,
                titleno: that.form.titleno,
                titlename: that.form.titlename
            })
                .then(function (response) {
                    that.getData();
                })
                .catch(function (error) {
                    console.log(error);
                });
        },

        deleteData(str) {
            var that = this;
            axios.get('https://water.hrenergy.cn/WeatherForecast/DelSubject', {
                params: {
                    sno: str
                }
            })
                .then(function (response) {
                    that.getData();
                })
                .catch(function (error) {
                    console.log(error);
                })
                .then(function () {
                    // always executed
                });
        },

        editData() {
            var that = this;
            axios.post('https://water.hrenergy.cn/WeatherForecast/ModSubject', {
                sno: that.form.sno,
                sname: that.form.sname,
                certify: that.form.certify,
                titleno: that.form.titleno,
                titlename: that.form.titlename
            })
                .then(function (response) {
                    that.getData();
                })
                .catch(function (error) {
                    console.log(error);
                });
        },

        async queryData(str) {
            var that = this;
            await axios.get('https://water.hrenergy.cn/WeatherForecast/QuerySubject', {
                params: {
                    sname: str
                }
            })
                .then(function (response) {
                    that.queryResults = response.data;
                    that.tempLen = response.data.length;
                })
                .catch(function (error) {
                    console.log(error);
                })
                .then(function () {
                    // always executed
                });
        },

        // 增删改查调用接口 ↑


        // 上传文件 ↓
        handleRemove(file, fileList) {
            console.log(file, fileList);
        },
        handlePreview(file) {
            console.log(file);
        },
        handleExceed(files, fileList) {
            this.$message.warning(`当前限制选择 3 个文件，本次选择了 ${files.length} 个文件，共选择了 ${files.length + fileList.length} 个文件`);
        },
        beforeRemove(file, fileList) {
            return this.$confirm(`确定移除 ${file.name}？`);
        },
        submitUpload() {
            this.$refs.upload.submit();
        },
        uploadSuccess(response, file, fileList) {
            this.$message({
                message: '上传成功!',
                type: 'success',
                1000: 1000
            });
            this.alertMessage("上传成功", "success", 1000);
        },
        uploadError(err, file, fileList) {
            this.alertMessage("上传失败", "error", 1000);
        },
        // 上传文件 ↑

        MyBro() {
            this.$notify({
                title: '成功',
                message: '欢迎您，大哥大',
                type: 'success',
                duration: 1000
            });
        }

    },
    created() {
        this.getData();
        this.MyBro();
    }
})