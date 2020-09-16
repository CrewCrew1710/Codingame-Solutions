#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w;
    int h;
    int countX;
    int countY;
    cin >> w >> h >> countX >> countY; cin.ignore();
    vector<int> xValue(countX+2), yValue(countY+2);
    xValue.at(0) = 0;
    xValue.at(countX+1) = w;
    yValue.at(0) = 0;
    yValue.at(countY+1) = h;
    for (int i = 0; i < countX; i++) {
        int x;
        cin >> x; cin.ignore();
        xValue.at(i+1) = x;
    }
    for (int i = 0; i < countY; i++) {
        int y;
        cin >> y; cin.ignore();
        yValue.at(i+1) = y;
    }
    int total = 0;


    map<int,int> xs, ys;
    for (int x = 0; x < xValue.size(); x++){
        for (int x2 = x+1; x2 < xValue.size(); x2++){
            xs[xValue[x2]-xValue[x]]++;
        }
    }
    for (int y = 0; y < yValue.size(); y++){
        for (int y2 = y+1; y2 < yValue.size(); y2++){
            ys[yValue[y2]-yValue[y]]++;
        }
    }
    for (auto const x:xs){
        if(ys.count(x.first)){
            total += x.second * ys.at(x.first);
        }
    }

    cout << total << endl;
}