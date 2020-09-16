#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool cmp(pair<int, int>* a, pair<int, int>* b) {
    return a->first < b->first;
}

int main()
{
    int L;
    cin >> L; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    vector<pair<int, int>*> done_length;
    vector<pair<int, int>> not_done;
    for (int i = 0; i < N; i++) {
        int st;
        int ed;
        cin >> st >> ed; cin.ignore();
        done_length.push_back(new pair<int, int>(st, ed));
    }

    sort(done_length.begin(), done_length.end(), cmp);
    //for (auto const p : done_length){
     //   cerr << p->first << ' ' << p->second << endl;
    //}
    //cerr << endl;

    pair<int, int>* current = done_length[0];
    if (current->first > 0) not_done.push_back(make_pair(0, current->first));

    for (auto const section : done_length) {
        if (current != section) {
            if (current->second > section->second) { goto next; }
            if (section->first - current->second > 0) not_done.push_back(make_pair(current->second, section->first));
            current = section;
        }
    next:;
    }
    if (current->second != L) not_done.push_back(make_pair(current->second, L));


    if (not_done.size() == 0) {
        cout << "All painted" << endl;
    }
    else {
        for (auto const p : not_done) {
            cout << p.first << ' ' << p.second << endl;
        }
    }

}