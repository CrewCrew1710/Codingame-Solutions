#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string b;
    getline(cin, b);

    int longest = 1;

    for (int i = 0; i < b.size() - 1; i++) {
        int count = 0;
        if (b[i] == '0') count++;
        for (int j = i + 1; j < b.size(); j++) {
            if (count == 1 && b[j] == '0') { longest = max(longest, j - i); break; }
            else if (count == 0 && b[j] == '0') count++;
            else longest = max(longest, j + 1 - i);
        }
    }

    cout << longest;
}