/*
 * 本程序演示堆和栈内存的比较
 */

struct Vec3 {
    double x, y, z;

    Vec3() : x(10), y(11), z(12) {}
};

int main() {
    //栈指针根据大小移动
    {
        int val = 5; //Breakpoint: Memory View
        int array[5] = { 1, 2, 3, 4, 5 };
        Vec3 vec;
    } //自动释放

    int* hval = new int;
    *hval = 5;
    int* harray = new int[5];
    for (int i = 0; i < 5; ++i)
        harray[i] = (i + 1);
    Vec3* hvec = new Vec3();

    //手动释放
    delete hval;
    delete[] harray;
    delete hvec;
    return 0;
}
