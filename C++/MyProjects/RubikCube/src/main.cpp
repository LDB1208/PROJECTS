#include <iostream>

using namespace std;

class RubikCube {
private:
    enum color {
        yellow, white, blue, green, orange, red //����ǰ������
    };

    color cube[6][9];

    int a[9] = { 6, 3, 0, 7, 4, 1, 8, 5, 2 }; //��z()��z_()����

    void CWRotate(int i) {
        swap(cube[i][0], cube[i][6]); //i��˳ʱ����ת90��
        swap(cube[i][1], cube[i][3]);
        swap(cube[i][2], cube[i][6]);
        swap(cube[i][3], cube[i][7]);
        swap(cube[i][5], cube[i][7]);
        swap(cube[i][6], cube[i][8]);
    }

    void CCWRotate(int i) {
        swap(cube[i][0], cube[i][2]); //i����ʱ����ת90��
        swap(cube[i][1], cube[i][5]);
        swap(cube[i][2], cube[i][8]);
        swap(cube[i][3], cube[i][5]);
        swap(cube[i][5], cube[i][7]);
        swap(cube[i][6], cube[i][8]);
    }

    void RotateTwice(int i) {
        swap(cube[i][0], cube[i][8]); //i����ת180��
        swap(cube[i][1], cube[i][7]);
        swap(cube[i][2], cube[i][6]);
        swap(cube[i][3], cube[i][5]);
    }

    void R() {
        swap(cube[0][2], cube[2][2]); //�ƻ���
        swap(cube[0][5], cube[2][5]);
        swap(cube[0][8], cube[2][8]);

        swap(cube[2][2], cube[1][2]); //������
        swap(cube[2][5], cube[1][5]);
        swap(cube[2][8], cube[1][8]);

        swap(cube[1][2], cube[3][2]); //�׻���
        swap(cube[1][5], cube[3][5]);
        swap(cube[1][8], cube[3][8]);

        CWRotate(5); //����

        cout << "R ";
    }

    void R_() {
        swap(cube[0][2], cube[3][2]); //�ƻ���
        swap(cube[0][5], cube[3][5]);
        swap(cube[0][8], cube[3][8]);

        swap(cube[3][2], cube[1][2]); //�̻���
        swap(cube[3][5], cube[1][5]);
        swap(cube[3][8], cube[1][8]);

        swap(cube[1][2], cube[2][2]); //�׻���
        swap(cube[1][5], cube[2][5]);
        swap(cube[1][8], cube[2][8]);

        CCWRotate(5); //����

        cout << "R' ";
    }

    void R2() {
        swap(cube[0][2], cube[1][2]); //�ƻ���
        swap(cube[0][5], cube[1][5]);
        swap(cube[0][8], cube[1][8]);

        swap(cube[2][2], cube[3][2]); //������
        swap(cube[2][5], cube[3][5]);
        swap(cube[2][8], cube[3][8]);

        RotateTwice(5); //����

        cout << "R2 ";
    }

    void R_2() {
        swap(cube[0][2], cube[1][2]); //�Ʊ��
        swap(cube[0][5], cube[1][5]);
        swap(cube[0][8], cube[1][8]);

        swap(cube[2][2], cube[3][2]); //������
        swap(cube[2][5], cube[3][5]);
        swap(cube[2][8], cube[3][8]);

        RotateTwice(5); //����

        cout << "R'2 ";
    }

    void r() {
        swap(cube[0][1], cube[2][1]); //�ƻ���
        swap(cube[0][2], cube[2][2]);
        swap(cube[0][4], cube[2][4]);
        swap(cube[0][5], cube[2][5]);
        swap(cube[0][7], cube[2][7]);
        swap(cube[0][8], cube[2][8]);

        swap(cube[2][1], cube[1][1]); //������
        swap(cube[2][2], cube[1][2]);
        swap(cube[2][4], cube[1][4]);
        swap(cube[2][5], cube[1][5]);
        swap(cube[2][7], cube[1][7]);
        swap(cube[2][8], cube[1][8]);

        swap(cube[1][1], cube[3][1]); //�׻���
        swap(cube[1][2], cube[3][2]);
        swap(cube[1][4], cube[3][4]);
        swap(cube[1][5], cube[3][5]);
        swap(cube[1][7], cube[3][7]);
        swap(cube[1][8], cube[3][8]);

        CWRotate(5); //����

        cout << "r ";
    }

    void L() {
        swap(cube[2][0], cube[0][0]); //������
        swap(cube[2][3], cube[0][3]);
        swap(cube[2][6], cube[0][6]);

        swap(cube[0][0], cube[3][0]); //�ƻ���
        swap(cube[0][3], cube[3][3]);
        swap(cube[0][6], cube[3][6]);

        swap(cube[3][0], cube[1][0]); //�̻���
        swap(cube[3][3], cube[1][3]);
        swap(cube[3][6], cube[1][6]);

        CWRotate(4); //����

        cout << "L ";
    }

    void l() {
        swap(cube[2][0], cube[0][0]); //������
        swap(cube[2][1], cube[0][1]);
        swap(cube[2][3], cube[0][3]);
        swap(cube[2][4], cube[0][4]);
        swap(cube[2][6], cube[0][6]);
        swap(cube[2][7], cube[0][7]);

        swap(cube[0][0], cube[3][0]); //�ƻ���
        swap(cube[0][1], cube[3][1]);
        swap(cube[0][3], cube[3][3]);
        swap(cube[0][4], cube[3][4]);
        swap(cube[0][6], cube[3][6]);
        swap(cube[0][7], cube[3][7]);

        swap(cube[3][0], cube[1][0]); //�̻���
        swap(cube[3][1], cube[1][1]);
        swap(cube[3][3], cube[1][3]);
        swap(cube[3][4], cube[1][4]);
        swap(cube[3][6], cube[1][6]);
        swap(cube[3][7], cube[1][7]);

        CWRotate(4); //����

        cout << "l ";
    }

    void U() {
        swap(cube[2][0], cube[5][0]); //������
        swap(cube[2][1], cube[5][1]);
        swap(cube[2][2], cube[5][2]);

        swap(cube[5][0], cube[3][8]); //�컻��
        swap(cube[5][1], cube[3][7]);
        swap(cube[5][2], cube[3][6]);

        swap(cube[3][6], cube[4][2]); //�̻���
        swap(cube[3][7], cube[4][1]);
        swap(cube[3][8], cube[4][0]);

        CWRotate(0); //����

        cout << "U ";
    }

    void U2() {
        swap(cube[2][0], cube[3][8]); //������
        swap(cube[2][1], cube[3][7]);
        swap(cube[2][2], cube[3][6]);

        swap(cube[4][0], cube[5][0]); //�Ȼ���
        swap(cube[4][1], cube[5][1]);
        swap(cube[4][2], cube[5][2]);

        RotateTwice(0); //����

        cout << "U2 ";
    }

    void U_() {
        swap(cube[2][0], cube[4][0]); //������
        swap(cube[2][1], cube[4][1]);
        swap(cube[2][2], cube[4][2]);

        swap(cube[4][0], cube[3][8]); //�Ȼ���
        swap(cube[4][1], cube[3][7]);
        swap(cube[4][2], cube[3][6]);

        swap(cube[3][8], cube[5][0]); //�̻���
        swap(cube[3][7], cube[5][1]);
        swap(cube[3][6], cube[5][2]);

        CCWRotate(0); //����

        cout << "U' ";
    }

    void u() {
        swap(cube[2][0], cube[5][0]); //������
        swap(cube[2][1], cube[5][1]);
        swap(cube[2][2], cube[5][2]);
        swap(cube[2][3], cube[5][3]);
        swap(cube[2][4], cube[5][4]);
        swap(cube[2][5], cube[5][5]);

        swap(cube[5][0], cube[3][8]); //�컻��
        swap(cube[5][1], cube[3][7]);
        swap(cube[5][2], cube[3][6]);
        swap(cube[5][3], cube[3][5]);
        swap(cube[5][4], cube[3][4]);
        swap(cube[5][5], cube[3][3]);

        swap(cube[3][8], cube[4][0]); //�̻���
        swap(cube[3][7], cube[4][1]);
        swap(cube[3][6], cube[4][2]);
        swap(cube[3][5], cube[4][3]);
        swap(cube[3][4], cube[4][4]);
        swap(cube[3][3], cube[4][5]);

        CWRotate(0); //����

        cout << "u ";
    }

    void u_() {
        swap(cube[2][0], cube[4][0]); //������
        swap(cube[2][1], cube[4][1]);
        swap(cube[2][2], cube[4][2]);
        swap(cube[2][3], cube[4][3]);
        swap(cube[2][4], cube[4][4]);
        swap(cube[2][5], cube[4][5]);

        swap(cube[4][0], cube[3][8]); //�Ȼ���
        swap(cube[4][1], cube[3][7]);
        swap(cube[4][2], cube[3][6]);
        swap(cube[4][3], cube[3][5]);
        swap(cube[4][4], cube[3][4]);
        swap(cube[4][5], cube[3][3]);

        swap(cube[3][8], cube[5][0]); //�̻���
        swap(cube[3][7], cube[5][1]);
        swap(cube[3][6], cube[5][2]);
        swap(cube[3][5], cube[5][3]);
        swap(cube[3][4], cube[5][4]);
        swap(cube[3][3], cube[5][5]);

        CCWRotate(0); //����

        cout << "u' ";
    }

    void D() {
        swap(cube[2][6], cube[4][6]); //������
        swap(cube[2][7], cube[4][7]);
        swap(cube[2][8], cube[4][8]);

        swap(cube[4][6], cube[3][2]); //�Ȼ���
        swap(cube[4][7], cube[3][1]);
        swap(cube[4][8], cube[3][0]);

        swap(cube[3][2], cube[5][6]); //�̻���
        swap(cube[3][1], cube[5][7]);
        swap(cube[3][0], cube[5][8]);

        CWRotate(1); //����

        cout << "D ";
    }

    void d() {
        swap(cube[2][3], cube[4][3]); //������
        swap(cube[2][4], cube[4][4]);
        swap(cube[2][5], cube[4][5]);
        swap(cube[2][6], cube[4][6]);
        swap(cube[2][7], cube[4][7]);
        swap(cube[2][8], cube[4][8]);

        swap(cube[4][8], cube[3][0]); //�Ȼ���
        swap(cube[4][7], cube[3][1]);
        swap(cube[4][6], cube[3][2]);
        swap(cube[4][5], cube[3][3]);
        swap(cube[4][4], cube[3][4]);
        swap(cube[4][3], cube[3][5]);

        swap(cube[3][0], cube[5][8]); //�̻���
        swap(cube[3][1], cube[5][7]);
        swap(cube[3][2], cube[5][6]);
        swap(cube[3][3], cube[5][5]);
        swap(cube[3][4], cube[5][4]);
        swap(cube[3][5], cube[5][3]);


        CWRotate(1); //����

        cout << "d ";
    }

    void d_() {
        swap(cube[2][8], cube[5][8]); //������
        swap(cube[2][7], cube[5][7]);
        swap(cube[2][6], cube[5][6]);
        swap(cube[2][5], cube[5][5]);
        swap(cube[2][4], cube[5][4]);
        swap(cube[2][3], cube[5][3]);

        swap(cube[5][8], cube[3][0]); //�컻��
        swap(cube[5][7], cube[3][1]);
        swap(cube[5][6], cube[3][2]);
        swap(cube[5][5], cube[3][3]);
        swap(cube[5][4], cube[3][4]);
        swap(cube[5][3], cube[3][5]);

        swap(cube[3][0], cube[4][8]); //�̻���
        swap(cube[3][1], cube[4][7]);
        swap(cube[3][2], cube[4][6]);
        swap(cube[3][3], cube[4][5]);
        swap(cube[3][4], cube[4][4]);
        swap(cube[3][5], cube[4][3]);

        CCWRotate(1); //����

        cout << "d' ";
    }

    void F() {
        swap(cube[0][8], cube[4][2]); //�ƻ���
        swap(cube[0][7], cube[4][5]);
        swap(cube[0][6], cube[4][8]);

        swap(cube[4][2], cube[1][0]); //�Ȼ���
        swap(cube[4][5], cube[1][1]);
        swap(cube[4][8], cube[1][2]);

        swap(cube[1][0], cube[5][6]); //�׻���
        swap(cube[1][1], cube[5][3]);
        swap(cube[1][2], cube[5][0]);

        CWRotate(2); //ǰ��

        cout << "F ";
    }

    void F_() {
        swap(cube[0][6], cube[5][0]); //�ƻ���
        swap(cube[0][7], cube[5][3]);
        swap(cube[0][8], cube[5][6]);

        swap(cube[5][0], cube[1][2]); //�컻��
        swap(cube[5][3], cube[1][1]);
        swap(cube[5][6], cube[1][0]);

        swap(cube[1][0], cube[4][2]); //�׻���
        swap(cube[1][1], cube[4][5]);
        swap(cube[1][2], cube[4][8]);

        CCWRotate(2); //ǰ��

        cout << "F' ";
    }

    void f() {
        swap(cube[0][3], cube[4][7]); //�ƻ���
        swap(cube[0][4], cube[4][4]);
        swap(cube[0][5], cube[4][1]);
        swap(cube[0][6], cube[4][8]);
        swap(cube[0][7], cube[4][5]);
        swap(cube[0][8], cube[4][2]);

        swap(cube[4][2], cube[1][0]); //�Ȼ���
        swap(cube[4][5], cube[1][1]);
        swap(cube[4][8], cube[1][2]);
        swap(cube[4][1], cube[1][3]);
        swap(cube[4][4], cube[1][4]);
        swap(cube[4][7], cube[1][5]);

        swap(cube[1][0], cube[5][6]); //�׻���
        swap(cube[1][1], cube[5][3]);
        swap(cube[1][2], cube[5][0]);
        swap(cube[1][3], cube[5][7]);
        swap(cube[1][4], cube[5][4]);
        swap(cube[1][5], cube[5][1]);

        CWRotate(2); //ǰ��

        cout << "f ";
    }

    void f_() {
        swap(cube[0][3], cube[5][1]); //�ƻ���
        swap(cube[0][4], cube[5][4]);
        swap(cube[0][5], cube[5][7]);
        swap(cube[0][6], cube[5][0]);
        swap(cube[0][7], cube[5][3]);
        swap(cube[0][8], cube[5][6]);

        swap(cube[5][0], cube[1][2]); //�컻��
        swap(cube[5][3], cube[1][1]);
        swap(cube[5][6], cube[1][0]);
        swap(cube[5][1], cube[1][5]);
        swap(cube[5][4], cube[1][4]);
        swap(cube[5][7], cube[1][3]);

        swap(cube[1][0], cube[4][2]); //�׻���
        swap(cube[1][1], cube[4][5]);
        swap(cube[1][2], cube[4][8]);
        swap(cube[1][3], cube[4][1]);
        swap(cube[1][4], cube[4][4]);
        swap(cube[1][5], cube[4][7]);

        CCWRotate(2); //ǰ��

        cout << "f' ";
    }

    void B() {
        swap(cube[0][0], cube[5][2]); //�ƻ���
        swap(cube[0][1], cube[5][5]);
        swap(cube[0][2], cube[5][8]);

        swap(cube[5][2], cube[1][8]); //�컻��
        swap(cube[5][5], cube[1][7]);
        swap(cube[5][8], cube[1][6]);

        swap(cube[1][8], cube[4][6]); //�׻���
        swap(cube[1][7], cube[4][3]);
        swap(cube[1][6], cube[4][0]);

        CWRotate(3); //����

        cout << "B ";
    }

    void b() {
        swap(cube[0][0], cube[5][2]); //�ƻ���
        swap(cube[0][1], cube[5][5]);
        swap(cube[0][2], cube[5][8]);
        swap(cube[0][3], cube[5][1]);
        swap(cube[0][4], cube[5][4]);
        swap(cube[0][5], cube[5][7]);

        swap(cube[5][2], cube[1][8]); //�컻��
        swap(cube[5][5], cube[1][7]);
        swap(cube[5][8], cube[1][6]);
        swap(cube[5][1], cube[1][5]);
        swap(cube[5][4], cube[1][4]);
        swap(cube[5][7], cube[1][3]);

        swap(cube[1][8], cube[4][6]); //�׻���
        swap(cube[1][7], cube[4][3]);
        swap(cube[1][6], cube[4][0]);
        swap(cube[1][5], cube[4][7]);
        swap(cube[1][4], cube[4][4]);
        swap(cube[1][3], cube[4][1]);

        CWRotate(3); //����

        cout << "b ";
    }

    void b_() {
        swap(cube[0][0], cube[4][6]); //�ƻ���
        swap(cube[0][1], cube[4][3]);
        swap(cube[0][2], cube[4][0]);
        swap(cube[0][3], cube[4][7]);
        swap(cube[0][4], cube[4][4]);
        swap(cube[0][5], cube[4][1]);

        swap(cube[4][6], cube[1][8]); //�Ȼ���
        swap(cube[4][3], cube[1][7]);
        swap(cube[4][0], cube[1][6]);
        swap(cube[4][7], cube[1][5]);
        swap(cube[4][4], cube[1][4]);
        swap(cube[4][1], cube[1][3]);

        swap(cube[1][8], cube[5][2]); //�׻���
        swap(cube[1][7], cube[5][5]);
        swap(cube[1][6], cube[5][8]);
        swap(cube[1][5], cube[5][1]);
        swap(cube[1][4], cube[5][4]);
        swap(cube[1][3], cube[5][7]);

        CCWRotate(3); //ǰ��

        cout << "b' ";
    }

    void M() {
        swap(cube[0][1], cube[3][1]); //�ƻ���
        swap(cube[0][4], cube[3][4]);
        swap(cube[0][7], cube[3][7]);

        swap(cube[3][1], cube[1][1]); //�̻���
        swap(cube[3][4], cube[1][4]);
        swap(cube[3][7], cube[1][7]);

        swap(cube[1][1], cube[2][1]); //�׻���
        swap(cube[1][4], cube[2][4]);
        swap(cube[1][7], cube[2][7]);

        cout << "M ";
    }

    void M_() {
        swap(cube[0][1], cube[2][1]); //�ƻ���
        swap(cube[0][4], cube[2][4]);
        swap(cube[0][7], cube[2][7]);

        swap(cube[2][1], cube[1][1]); //������
        swap(cube[2][4], cube[1][4]);
        swap(cube[2][7], cube[1][7]);

        swap(cube[1][1], cube[3][1]); //�׻���
        swap(cube[1][4], cube[3][4]);
        swap(cube[1][7], cube[3][7]);

        cout << "M' ";
    }

    void M_2() {
        swap(cube[0][1], cube[1][1]); //�ƻ���
        swap(cube[0][4], cube[1][4]);
        swap(cube[0][7], cube[1][7]);

        swap(cube[2][1], cube[3][1]); //������
        swap(cube[2][4], cube[3][4]);
        swap(cube[2][7], cube[3][7]);

        cout << "M'2 ";
    }

    void x() {
        for (int i = 0; i < 9; i++) {
            swap(cube[0][i], cube[2][i]); //�ƻ���
            swap(cube[2][i], cube[1][i]); //������
            swap(cube[1][i], cube[3][i]); //�׻���
        }

        CCWRotate(4); //����
        CWRotate(5); //����

        cout << "x ";
    }

    void x_() {
        for (int i = 0; i < 9; i++) {
            swap(cube[0][i], cube[3][i]); //�ƻ���
            swap(cube[3][i], cube[1][i]); //�̻���
            swap(cube[1][i], cube[2][i]); //�׻���
        }

        CWRotate(4); //����
        CCWRotate(5); //����

        cout << "x' ";
    }

    void y() {
        for (int i = 0; i < 9; i++) {
            swap(cube[2][i], cube[5][i]); //������
            swap(cube[5][i], cube[3][8 - i]); //�컻��
            swap(cube[3][8 - i], cube[4][i]); //�̻���
        }

        CWRotate(0); //����
        CCWRotate(1);//����

        cout << "y ";
    }

    void y_() {
        for (int i = 0; i < 9; i++) {
            swap(cube[2][i], cube[4][i]); //������
            swap(cube[4][i], cube[3][8 - i]); //�Ȼ���
            swap(cube[3][8 - i], cube[5][i]); //�̻���
        }

        CCWRotate(0); //����
        CWRotate(1);//����

        cout << "y' ";
    }

    void z() {
        for (int i = 0; i < 9; i++) {
            swap(cube[0][i], cube[4][a[i]]); //�ƻ���
            swap(cube[4][a[i]], cube[1][8 - i]); //�Ȼ���
            swap(cube[1][8 - i], cube[5][a[8 - i]]); //�׻���
        }

        CWRotate(2); //ǰ��
        CCWRotate(3);//����

        cout << "z ";
    }

    void z_() {
        for (int i = 0; i < 9; i++) {
            swap(cube[0][i], cube[5][a[8 - i]]); //�ƻ���
            swap(cube[5][a[8 - i]], cube[1][8 - i]); //�컻��
            swap(cube[1][8 - i], cube[4][a[i]]); //�׻���
        }

        CCWRotate(2); //ǰ��
        CWRotate(3);//����

        cout << "z' ";
    }

public:
    RubikCube() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                cube[i][j] = color(i);
            }
        }
    }

    void Debug() {
        cout << endl;
        for (auto& i : cube) {
            for (auto& j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void F2L_1() {
        R();
        U_();
        R_();
        U();

        y_();

        R_();
        U2();
        R();
        U_();
        U_();

        R_();
        U();
        R();
    }

    void F2L_2() {
        U();
        R();
        U_();
        R_();
        U_();

        y_();

        R_();
        U();
        R();
    }

    void F2L_3() {
        R_();
        F_();
        R();
        U();

        R();
        U_();
        R_();
        F();
    }

    void F2L_4() {
        R();
        U();
        R_();
        U_();

        R();
        U2();
        R_();
        U_();

        R();
        U();
        R_();
    }

    void F2L_5() {
        R();
        F();

        U();

        R();
        U_();
        R_();
        F_();

        U_();
        R_();
    }

    void F2L_6() {
        y_();

        R_();
        U_();
        R();
        U();

        R_();
        U_();
        R();
    }

    void F2L_7() {
        R();
        U_();
        R_();
        U();

        R();
        U_();
        R_();
    }

    void F2L_8() {
        R();
        U_();
        R_();
        U();

        R();
        U_();
        U_();
        R_();
        U();

        R();
        U_();
        R_();
    }

    void F2L_9() {
        R();
        U();

        F();

        R();
        U();
        R_();
        U_();

        F_();
        R_();
    }

    void F2L_10() {
        y_();

        R_();
        U();
        R();
        U_();

        R_();
        U();
        R();
    }

    void F2L_11() {
        R();
        U();
        R_();
        U_();

        R();
        U();
        R_();
    }

    void F2L_12() {
        for (int i = 0; i < 2; ++i) {
            R();
            U();
            R_();
            U_();
        }
        R();
        U();
        R_();
    }

    void F2L_13() {
        R();
        U_();
        R_();
        U();

        y_();

        R_();
        U();
        R();
    }

    void F2L_14() {
        y_();

        R_();
        U2();

        R();
        U();
        R_();
        U_();
        R();
    }

    void F2L_15() {
        y_();
        U_();

        R_();
        U2();

        R();
        U_();
        R_();
        U();
        R();
    }

    void F2L_16() {
        y_();

        R_();
        U();
        R();
        U_();
        U_();

        R_();
        U_();
        R();
    }

    void F2L_17() {
        F();
        U();

        R();
        U_();
        R_();
        F_();

        R();
        U_();
        R_();
    }

    void F2L_18() {
        U();

        R();
        U_();
        R_();
        U_();

        R();
        U_();
        R_();
        U();

        R();
        U_();
        R_();
    }

    void F2L_19() {
        R();
        U_();
        R_();
        U2();

        R();
        U();
        R_();
    }

    void F2L_20() {
        U();

        R();
        U_();
        U_();

        R_();
        U();
        R();
        U_();
        R_();
    }

    void F2L_21() {
        R();
        U_();
        U_();

        R_();
        U_();
        R();
        U();
        R_();
    }

    void F2L_22() {
        U_();

        R();
        U_();
        R_();
        U2();

        R();
        U_();
        R_();
    }

    void F2L_23() {
        U_();

        R();
        U();
        R_();

        y_();

        U();
        R_();
        U_();
        R();
    }

    void F2L_24() {
        y_();
        U();

        R_();
        U();
        R();
        U_();

        R_();
        U_();
        R();
    }

    void F2L_25() {
        y_();

        R_();
        U();
        R();
    }
};

int main() {
    RubikCube c;
    return 0;
}
