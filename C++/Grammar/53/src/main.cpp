/*
* ��������ʾ����ת��
*/

class Base {
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    ~Derived() override {}
};

class AnotherClass : public Base {
public:
    AnotherClass() {}
    ~AnotherClass() override {}
};

int main() {
    int a = 5;
    double b = 5.25;
    double convert_int = a; //��ʽת��
    double convert_double = static_cast<int>(b); //��ʽת��(static_cast)

    double value = 5.5;
    auto s = reinterpret_cast<AnotherClass*>(&value); //����˫��(reinterpret_cast)
    double* double_ptr = &value;
    int* int_ptr = reinterpret_cast<int*>(double_ptr);

    Derived* derived = new Derived();
    Base* base = derived;
    //dynamic_cast:ת�����ɹ�����NULL
    AnotherClass* ac1 = dynamic_cast<AnotherClass*>(base); //NULL
    Derived* ac2 = dynamic_cast<Derived*>(base);

    const int const_value = 5;
    int* convert_const = const_cast<int*>(&const_value);
    *convert_const = 7; //const_value = 5
    return 0;
}
