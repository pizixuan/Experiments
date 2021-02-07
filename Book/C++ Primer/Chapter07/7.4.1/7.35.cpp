#include <iostream>
#include <string>
using namespace std;

typedef string Type;
Type initVal();
class Exercise {
    public:
        typedef double Type;
        Type setVal(Type);  //识别为 double Type
        Type initVal();
    private:
        int val;
};

Type Exercise::setVal(Type parm) {  //识别为 string Type 导致函数重载错误
    val = parm + initVal();
    return val;
}

//应修改为 steVal 在 class 内定义