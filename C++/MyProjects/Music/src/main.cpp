#include <iostream>
#include <windows.h>

using namespace std;

#pragma comment(lib, "winmm.lib")

enum Scale {
    A5 = 81, G5 = 79, F5 = 77, E5 = 76, D5 = 74, C5 = 72,

    B4 = 71, A4 = 69, G4 = 67, E4 = 64, D4 = 62, C4 = 60,

    B3 = 59, A3 = 57, G3 = 55, E3 = 52, D3 = 50

};

enum Voice {

    L2 = D3, L3 = E3, L5 = G3, L6 = A3, L7 = B3,

    M1 = C4, M2 = D4, M3 = E4, M5 = G4, M6 = A4, M7 = B4,

    H1 = C5, H2 = D5, H3 = E5, H4 = F5, H5 = G5, H6 = A5,

    LOW_SPEED = 500, MIDDLE_SPEED = 400, HIGH_SPEED = 300,

    _ = 0XFF

};

// �����
void Wind() {
    HMIDIOUT handle;
    midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
    midiOutShortMsg(handle, 34 << 8 | 0xC0);
    int volume = 0x7f;
    int voice = 0x0;
    int sleep = 1000;
    int wind[] =
    {
            400, 0, L7, M1, M2, M3, 300, L3, 0, M5, M3, 300, L2, L5, 2, _, 0, L7, M1, M2, M3, 300, L2, 0, M5,
            M3, M2, M3, M1, M2, L7, M1, 300, L5, 0, L7, M1, M2, M3, 300, L3, 0, M5, M3, 300, L2, L5, 2, _, 0,
            L7, M1, M2, M3, 300, L2, 0, M5, M3, M2, M3, M1, M2, L7, M1, 300, L5,

            0, L7, M1, M2, M3, 300, L3, 0, M5, M3, 300, L2, L5, 2, _, 0, L7, M1, M2, M3, 300, L2, 0, M5, M3, M2,
            M3, M1, M2, L7, M1, 300, L5, 0, L7, M1, M2, M3, 300, L3, 0, M5, M3, 300, L2, L5, 2, _,

            0, M6, M3, M2, L6, M3, L6, M2, M3, L6, _, _, _,

            M2, 700, 0, M1, 300, M2, 700, 0, M1, 300, M2, M3, M5, 0, M3, 700, 300, M2, 700, 0, M1, 300, M2, 700,
            0, M1, M2, M3, M2, M1, 300, L5, _,

            M2, 700, 0, M1, 300, M2, 700, 0, M1, 300, M2, M3, M5, 0, M3, 700, 300, M2, 700, 0, M3, 300, M2, 0,
            M1, 700, 300, M2, _, _, _,

            M2, 700, 0, M1, 300, M2, 700, 0, M1, 300, M2, M3, M5, 0, M3, 700, 300, M2, 700, 0, M3, 300, M2, 0,
            M1, 700, 300, L6, _,

            0, M3, M2, M1, M2, 300, M1, _, 0, M3, M2, M1, M2, 300, M1, 700, 0, L5, M3, M2, M1, M2, 300, M1, _,
            _, _,

            M1, M2, M3, M1, M6, 0, M5, M6, 300, _, 700, 0, M1, 300, M7, 0, M6, M7, 300, _, _, M7, 0, M6, M7,
            300, _, M3, 0, H1, H2, H1, M7, 300, M6, M5, M6, 0, M5, M6, _, M5, M6, M5, 300, M6, 0, M5, M2, 300,
            _, 0, M5, 700, 300, M3, _, _, _,

            M1, M2, M3, M1, M6, 0, M5, M6, 300, _, 700, 0, M1, 300, M7, 0, M6, M7, 300, _, _, M7, 0, M6, M7,
            300, _, M3, 0, H1, H2, H1, M7, 300, M6, M5, M6, 0, H3, H3, 300, _, M5, M6, 0, H3, H3, 300, _, 0, M5,
            700, 300, M6, _, _, _, _, _,

            H1, H2, H3, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H3, 0, H6, H5,
            300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H2, 0, H1, M6, 300, _, 0, H1, H1, 300,
            H2, 0, H1, 300, M6, 700, 0, _, 300, H1, 700, H3, _, 0, H3, H4, H3, H2, H3, 300, H2, 700,

            H1, H2, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 300, _, H3, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 700,
            300, H3, 700, H2, 0, H1, M6, 700, 300,

            H3, 700, H2, 0, H1, 300, M6, 700, H1, H1, _, _, _, _, _,

            0, M6, 300, H3, 700, H2, 0, H1, M6, 700, 300, H3, H2, 700, 300, 0, H1, M6, 300, 700, H1, H1, _, _,

            0, L7, M1, M2, M3, 300, L3, 0, M5, M3, 300, L2, L5, 2, _, 0, L7, M1, M2, M3, 300, L2, 0, M5, M3, M2,
            M3, M1, M2, L7, M1, 300, L5, 0, L7, M1, M2, M3, 300, L3, 0, M5, M3, 300, L2, L5, 2, _,

            0, M6, M3, M2, L6, M3, L6, M2, M3, L6, _, _, _,

            M2, 700, 0, M1, 300, M2, 700, 0, M1, 300, M2, M3, M5, 0, M3, 700, 300, M2, 700, 0, M1, 300, M2, 700,
            0, M1, M2, M3, M2, M1, 300, L5, _,

            M2, 700, 0, M1, 300, M2, 700, 0, M1, 300, M2, M3, M5, 0, M3, 700, 300, M2, 700, 0, M3, 300, M2, 0,
            M1, 700, 300, M2, _, _, _,

            M2, 700, 0, M1, 300, M2, 700, 0, M1, 300, M2, M3, M5, 0, M3, 700, 300, M2, 700, 0, M3, 300, M2, 0,
            M1, 700, 300, L6, _,

            0, M3, M2, M1, M2, 300, M1, _, 0, M3, M2, M1, M2, 300, M1, 700, 0, L5, M3, M2, M1, M2, 300, M1, _,
            _, _,

            M1, M2, M3, M1, M6, 0, M5, M6, 300, _, 700, 0, M1, 300, M7, 0, M6, M7, 300, _, _, M7, 0, M6, M7,
            300, _, M3, 0, H1, H2, H1, M7, 300, M6, M5, M6, 0, M5, M6, _, M5, M6, M5, 300, M6, 0, M5, M2, 300,
            _, 0, M5, 700, 300, M3, _, _, _,

            M1, M2, M3, M1, M6, 0, M5, M6, 300, _, 700, 0, M1, 300, M7, 0, M6, M7, 300, _, _, M7, 0, M6, M7,
            300, _, M3, 0, H1, H2, H1, M7, 300, M6, M5, M6, 0, H3, H3, 300, _, M5, M6, 0, H3, H3, 300, _, 0, M5,
            700, 300, M6, _, _, _, _, _,

            H1, H2, H3, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H3, 0, H6, H5,
            300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H2, 0, H1, M6, 300, _, 0, H1, H1, 300,
            H2, 0, H1, 300, M6, 700, 0, _, 300, H1, 700, H3, _, 0, H3, H4, H3, H2, H3, 300, H2, 700,

            H1, H2, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 300, _, H3, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 700,
            300, H3, 700, H2, 0, H1, M6, 700, 300,

            H3, 700, H2, 0, H1, 300, M6, 700, H1, H1, _, _, _, _, _,

            H1, H2, H3, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H3, 0, H6, H5,
            300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H2, 0, H1, M6, 300, _, 0, H1, H1, 300,
            H2, 0, H1, 300, M6, 700, 0, _, 300, H1, 700, H3, _, 0, H3, H4, H3, H2, H3, 300, H2, 700,

            H1, H2, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 300, _, H3, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 700,
            300, H3, 700, H2, 0, H1, M6, 700, 300,

            H3, 700, H2, 0, H1, 300, M6, 700, H1, H1, _, _, _, _, _,

            H1, H2, H3, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H3, 0, H6, H5,
            300, _, 0, H6, H5, 300, _, 0, H6, H5, 300, _, 0, H2, H3, 300, H2, 0, H1, M6, 300, _, 0, H1, H1, 300,
            H2, 0, H1, 300, M6, 700, 0, _, 300, H1, 700, H3, _, 0, H3, H4, H3, H2, H3, 300, H2, 700,

            H1, H2, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 300, _, H3, H3, 0, H6, H5, _, H6, H5, _, H6, H5, 700,
            300, H3, 700, H2, 0, H1, M6, 700, 300,

            H3, 700, H2, 0, H1, 300, M6, 700, H1, H1, _, _, _, _, _,

            0, M6, 300, H3, 700, H2, 0, H1, M6, 700, 300, H3, H2, 700, 300, 0, H1, M6, 300, 700, H1, H1, _, _,
            _, _, _, _, _,

    };

    for (auto i : wind) {
        if (i == LOW_SPEED || i == HIGH_SPEED || i == MIDDLE_SPEED) {
            sleep = i;//Sleep(i/2);
            continue;
        }
        if (i == 0) {
            sleep = 175;
            continue;
        }
        if (i == 700) {
            Sleep(175);
            continue;
        }
        if (i == _) {
            Sleep(500);
            continue;
        }

        voice = (volume << 16) + ((i) << 8) + 0x90;
        midiOutShortMsg(handle, voice);
        cout << voice << endl;
        Sleep(sleep);

    }

    midiOutClose(handle);

}

int main() {
    Wind();
    return 0;
}
