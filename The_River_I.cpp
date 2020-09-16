#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    long long r1;
    cin >> r1; cin.ignore();
    long long r2;
    cin >> r2; cin.ignore();

    bool solving = true;
    while(solving){
        if(r1 == r2) {cout << r1 << endl; solving = false; break;}

        while(r1 < r2){
            int add_digit1 = 0;
            for (char const c : to_string(r1)){
                add_digit1 += (int)(c) - 48;
            }
            r1 += add_digit1;
        }
        while(r2 < r1){
            int add_digit1 = 0;
            for (char const c : to_string(r2)){
                add_digit1 += (int)(c) - 48;
            }
            r2 += add_digit1;
        }
    }  
}