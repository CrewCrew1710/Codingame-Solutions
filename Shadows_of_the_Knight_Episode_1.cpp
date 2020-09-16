#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();

    int x1 = 0;
    int x2 = W - 1;
    int y1 = 0;
    int y2 = H - 1;

    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore(); 

        for (auto c : bombDir){
            if (c == 'U') y2 = Y0 - 1;
            if (c == 'D') y1 = Y0 + 1;
            if (c == 'R') x1 = X0 + 1;
            if (c == 'L') x2 = X0 - 1;
        }

        X0 = x1 + (x2 - x1) / 2;
        Y0 = y1 + (y2 - y1) / 2;

        cout << X0 << ' ' << Y0 << endl;
    }
}