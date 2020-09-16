#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getBinary(char c) {
    string temp;
    for (int i = 7; i >= 0; --i) {
        temp+= ((c & (1 << i))? '1' : '0');
    }
    return temp.substr(1);
}

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    string binary;

    for (auto const c : MESSAGE){
        binary+=getBinary(c);
    }

    cerr << binary;

    for (int i = 0; i < binary.size(); i++){
        int temp = 1;
        while(binary[i] == binary[i+1]){
            temp += 1;
            i++;
        }

        if(binary[i] == '1'){ 
            cout << "0 ";
            for (int j = 0; j < temp; j++) cout << '0';
        }
        else if(binary[i] == '0'){ 
            cout << "00 ";
            for(int j = 0; j < temp; j++) cout << '0';
        }

        if(i != binary.size()-1)cout << ' ';
    }
    
}