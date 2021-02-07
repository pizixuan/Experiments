#include <iostream>
int height;
class Screen {
  public:
    typedef std::string::size_type pos; 
    void dummy_fcn(pos height) { cursor = width * height; } //pos需要先定义，因为只会考虑该函数之前的声明

  private:
    pos cursor = 0;
    pos height = 0, width = 0;
};