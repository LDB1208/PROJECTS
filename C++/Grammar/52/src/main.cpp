#include <iostream>

/*
* 本程序演示虚析构函数
*/

class base_no_virtual {
public:
    base_no_virtual() { std::cout << "Base Constructed.(NV)\n"; }
    ~base_no_virtual() { std::cout << "Base Destructed.(NV)\n"; }
};

class derived_no_virtual : public base_no_virtual {
public:
    derived_no_virtual() { std::cout << "Derived Constructed.(NV)\n"; }
    ~derived_no_virtual() { std::cout << "Derived Destructed.(NV)\n"; }
};

class base {
public:
    base() { std::cout << "Base Constructed.\n"; }
    virtual ~base() { std::cout << "Base Destructed.\n"; } //只要一个类有派生类, 就把析构函数标记为virtual!
};

class derived : public base {
public:
    derived() { std::cout << "Derived Constructed.\n"; }
    ~derived() override { std::cout << "Derived Destructed.\n"; }
};


int main() {
    base_no_virtual* Base = new base_no_virtual();
    delete Base;
    std::cout << "--------------------\n";
    derived_no_virtual* Derived1 = new derived_no_virtual(); //先调用基类
    delete Derived1;
    std::cout << "--------------------\n";
    base_no_virtual* Derived2 = new derived_no_virtual(); //MEMORY LEAK
    //Derived2不知道有~derived_no_virtual()析构函数
    delete Derived2;
    std::cout << "--------------------\n";
    base* Derived3 = new derived();
    delete Derived3;
    return 0;
}
