#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int count = 0;
        string line;
        getline(cin, line);
        for (int i = 0; i < line.size(); i++){
            if(line[i] == 'f'){
                if(line[i+1] == 'f'){
                    line[i+2] = '.';i = i+2; count++;
                } 
                else if(line[i+2] == 'f'){
                    count++; i = i+2;
                }
                else count++;
            }
        }
        cout << count << endl;
    }
}