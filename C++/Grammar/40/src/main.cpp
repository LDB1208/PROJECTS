/*
 * ��������ʾ�Ѻ�ջ�ڴ�ıȽ�
 */

struct Vec3 {
    double x, y, z;

    Vec3() : x(10), y(11), z(12) {}
};

int main() {
    //ջָ����ݴ�С�ƶ�
    {
        int val = 5; //Breakpoint: Memory View
        int array[5] = { 1, 2, 3, 4, 5 };
        Vec3 vec;
    } //�Զ��ͷ�

    int* hval = new int;
    *hval = 5;
    int* harray = new int[5];
    for (int i = 0; i < 5; ++i)
        harray[i] = (i + 1);
    Vec3* hvec = new Vec3();

    //�ֶ��ͷ�
    delete hval;
    delete[] harray;
    delete hvec;
    return 0;
}
