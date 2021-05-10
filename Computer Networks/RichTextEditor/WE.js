new Vue({
    el: '#RTE',
    data() {
        return {
            
        }
    },
    methods: {
        init: function () {
            const E = window.wangEditor;
            const editor = new E("#toolbar-container", "#text-container");
            editor.create();
        }
    },
    created() {
        this.init();
    }
})