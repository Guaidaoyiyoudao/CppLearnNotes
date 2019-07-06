/*

    lambda expression:

    语法:
    1  2   3        4         5
    []() mutable throw() -> int {
        // body
    }

    1 表示该函数体内可以使用的外部变量
    [] 表示不使用任何外部变量, [&]表示可以使用所有外部变量的引用，[=]表示可以使用外部变量的值
    [a,&b],表示只能使用a的值，&b表示使用b的引用

    2 使参数列表

    3 mutable使函数可以修改const变量

    4 异常抛出

    5 返回类型
    


 */ 


#include<iostream>

int main()
{

    int a=5,b=3;

    auto f2 = [&](){
        a= 3;
        b = 4;
        return a+b;
    };
    
    std::cout<<f1()<<std::endl;
    std::cout<<"after a = "<<a<<std::endl;
    std::cout<<"after b = "<<b<<std::endl;
    return 0;
}