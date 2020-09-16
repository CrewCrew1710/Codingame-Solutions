#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define FOR(i,size) for(int i = 0; i < size; i++)
#define TWOD(x,y,w) y*w+x

struct Cell {
    int x, y;
    char type;
    Cell(int x, int y, char t) :x(x), y(y), type(t) {};
};

int main()
{
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    vector<Cell*> grid(H * W);
    for (int rows = 0; rows < H; rows++) {
        string line;
        getline(cin, line);
        for (int cols = 0; cols < (int)line.size(); cols++) {
            grid[rows * W + cols] = (new Cell(cols, rows, line[cols]));
        }
    }

    vector<Cell*> starts;
    unordered_map<char, int> ends;
    FOR(rows, H) {
        FOR(cols, W) {
            if (rows == 0 && cols % 3 == 0) starts.push_back(grid[TWOD(cols, rows, W)]);
            if (rows == H - 1 && cols % 3 == 0) ends[grid[TWOD(cols, rows, W)]->type]++;
            // cerr << grid[TWOD(cols,rows,W)]->type;
        }
        //cerr << endl;
    }

    for (auto const k : ends){
        cerr << k.first << endl;
    }

    vector<pair<char, char>> answers;
    while (starts.size() > 0) {
        cerr << starts.size() << endl;
        Cell* current = starts[starts.size() - 1];
        cerr << '(' << current->x << ',' << current->y << ',' << current->type << ')' << endl;
        for (int i = 0; i < grid.size(); i++) {
            if (count(starts.begin(), starts.end(), current) == 1 || current->type == '|') {
                if (grid[i]->type == '-') {
                    if (grid[i]->x == current->x - 1 && grid[i]->y == current->y) {
                        current = grid[(current->y + 1) * W + (current->x - 3)];
                        if(ends.count(current->type) == 1){ answers.push_back(make_pair(starts[starts.size() - 1]->type, current->type)); starts.pop_back(); break; }
                        i = current->y * W + current->x - 2;

                        cerr << '(' << current->x << ',' << current->y << ',' << current->type << ')' << endl;
                    }
                    if (grid[i]->x == current->x + 1 && grid[i]->y == current->y) {
                        current = grid[(current->y + 1) * W + (current->x + 3)];
                        if (ends.count(current->type) == 1) { answers.push_back(make_pair(starts[starts.size() - 1]->type, current->type)); starts.pop_back(); break; }
                        i = current->y * W + current->x - 2;
                        cerr << '(' << current->x << ',' << current->y << ',' << current->type << ')' << endl;
                    }
                }
                if (ends.count(grid[i]->type) == 1) {
                    if (grid[i]->x == current->x && grid[i]->y == current->y + 1) {
                        current = grid[i];
                        cerr << "this" << '(' << current->x << ',' << current->y << ',' << current->type << ')' << endl;
                        answers.push_back(make_pair(starts[starts.size() - 1]->type, current->type)); starts.pop_back(); break;
                    }
                }
                else if (grid[i]->type == '|') {
                    if (grid[i]->x == current->x && grid[i]->y == current->y + 1) {
                        current = grid[i];
                        i = current->y * W + current->x - 2;
                        cerr << '(' << current->x << ',' << current->y << ',' << current->type << ')' << endl;
                    }
                }

            }
        }
        cin.get();
    }

    //cerr << answers.size();
    for (int i = answers.size() - 1; i >= 0; i--) {
        cout << answers[i].first << answers[i].second << endl;
    }
}