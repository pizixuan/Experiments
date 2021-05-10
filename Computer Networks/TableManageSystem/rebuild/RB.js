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

                //身份校验
                sex: '',
                age: '',
                birthday: '',
                birthplace: ''
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

            //身份证校验
            // 身份证校验
            area: {
                11: "北京", 12: "天津", 13: "河北", 14: "山西", 15: "内蒙古", 21: "辽宁", 22: "吉林", 23: "黑龙江",
                31: "上海", 32: "江苏", 33: "浙江", 34: "安徽", 35: "福建", 36: "江西", 37: "山东", 41: "河南", 42: "湖北",
                43: "湖南", 44: "广东", 45: "广西", 46: "海南", 50: "重庆", 51: "四川", 52: "贵州", 53: "云南", 54: "西藏",
                61: "陕西", 62: "甘肃", 63: "青海", 64: "宁夏", 65: "新疆", 71: "台湾", 81: "香港", 82: "澳门", 91: "国外"
            },
            Wi: [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2],
            ValideCode: [1, 0, "X", 9, 8, 7, 6, 5, 4, 3, 2],
        }
    },
    methods: {
        // 重置所有参数
        refresh() {
            this.isAdd = false;
            this.isEdit = false;
            this.tableData[this.index] = false;
            this.index = -1;
            this.disabledSno = false;
            this.disabledButton = false;
        },

        async deleteAllBro() {
            // this.pageSize = this.totalDataNum;
            console.log(`${this.pageSize}`);
            var that = this;
            await axios.get('https://water.hrenergy.cn/WeatherForecast/Subject', {
                params: {
                    pageIndex: that.pageIndex,
                    pageSize: this.totalDataNum
                }
            }).then((response) => {
                // console.log(response);
                const data = response.data.data.filter((val) => { return val.sname.includes('本接口将弃用') });
                for (var i = 0; i < data.length; i++) {
                    axios.get('https://water.hrenergy.cn/WeatherForecast/DelSubject', {
                        params: {
                            sno: data[i].sno
                        }
                    }).then((response) => { })
                }
            })

            await this.getData();
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
            // console.log(queryString);
            await this.queryData(queryString);
            var queryResults = this.queryResults;
            var results = queryString ? queryResults.filter(this.createStateFilter(queryString)) : queryResults;
            // cb(results);
            clearTimeout(this.timeout);
            this.timeout = setTimeout(() => {
                cb(results);
            }, 1000 * Math.random());
        },
        testInput() {
            console.log(this.state)
            if (!this.state) {
                this.getData();
            }
        },
        createStateFilter(queryString) {
            return (states) => {
                return (states.sname.toLowerCase().indexOf(queryString.toLowerCase()) !== -1);
            };
        },
        handleSelect(item) {
            this.isSearch = true;
            this.queryData(this.state);
        },
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
        async getData() {
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
                    if (that.isSearch) {
                        that.tableData = response.data;
                        that.totalDataNum = response.data.length;
                    }
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
        },


        // 检测身份证
        checkCard() {
            if (!this.form.certify)
                return;
            let CardId = this.form.certify;
            if (CardId.length == 15) {
                if (this.is15Card(CardId)) {
                    this.go(CardId.length);
                }
                else {
                    return this.$message({ type: 'error', message: '您的身份证号有误！请输入你真实的身份证号，确保你的利益得到保障！' });
                }
            } else if (CardId.length == 18) {
                let a_iden = CardId.split("");
                if (this.is18Card(CardId) && this.is18CardEnd(a_iden)) {
                    this.go(CardId.length);
                    return this.is18Card(CardId);
                }
                else {
                    return this.$message({ type: 'error', message: '您的身份证号有误！请输入你真实的身份证号，确保你的利益得到保障！' });
                }
            } else {
                return this.$message({ type: 'error', message: '您的身份证号有误！请输入你真实的身份证号，确保你的利益得到保障！' });
            }
        },

        // 检测18位身份证号最后一位是否符合要求
        is18CardEnd(a_idCard) {
            let sum = 0;
            if (a_idCard[17].toLowerCase() == 'x') {
                a_idCard[17] = 10;
            }
            for (var i = 0; i < 17; i++) {
                sum += this.Wi[i] * a_idCard[i];
            }
            let valCodePosition = sum % 11;
            if (a_idCard[17] == this.ValideCode[valCodePosition]) {
                return true;
            } else {
                return false;
            }
        },

        // 验证最后一位校正码
        is18Card(idCard18) {
            let year = idCard18.substring(6, 10);
            let month = idCard18.substring(10, 12);
            let day = idCard18.substring(12, 14);
            let temp_date = new Date(year, parseFloat(month) - 1, parseFloat(day));
            if (temp_date.getFullYear() != parseFloat(year)
                || temp_date.getMonth() != parseFloat(month) - 1
                || temp_date.getDate() != parseFloat(day)) {
                return false;
            } else {
                return true;
            }
        },

        is15Card(idCard15) {
            let year = idCard15.substring(6, 8);
            let month = idCard15.substring(8, 10);
            let day = idCard15.substring(10, 12);
            let temp_date = new Date(year, parseFloat(month) - 1, parseFloat(day));
            if (temp_date.getYear() != parseFloat(year) || temp_date.getMonth() != parseFloat(month) - 1 || temp_date.getDate() != parseFloat(day)) {
                return false;
            } else {
                return true;
            }
        },

        // 实现自动生成生日，性别，年龄
        go(val) {
            let iden = this.form.certify;
            let sex = null;
            let birth = null;
            let myDate = new Date();
            let month = myDate.getMonth() + 1;
            let day = myDate.getDate();
            let age = 0;

            if (val === 18) {
                age = myDate.getFullYear() - iden.substring(6, 10) - 1;
                sex = iden.substring(16, 17);
                birth = iden.substring(6, 10) + "-" + iden.substring(10, 12) + "-" + iden.substring(12, 14);
                if (iden.substring(10, 12) < month || iden.substring(10, 12) == month && iden.substring(12, 14) <= day) age++;

            }
            if (val === 15) {
                age = myDate.getFullYear() - iden.substring(6, 8) - 1901;
                sex = iden.substring(13, 14);
                birth = "19" + iden.substring(6, 8) + "-" + iden.substring(8, 10) + "-" + iden.substring(10, 12);
                if (iden.substring(8, 10) < month || iden.substring(8, 10) == month && iden.substring(10, 12) <= day) age++;
            }

            if (sex % 2 === 0)
                sex = '0';
            else
                sex = '1';
            this.form.sex = sex;
            this.form.age = age;
            this.form.birthday = birth;
            this.form.birthplace = this.area[iden.substring(0, 2)];
        },

    },
    created() {
        this.getData();
        this.MyBro();
    }
})