#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cell{
    int x, y;
    char type;
    vector<cell*> neighbors;

    cell(int x, int y, char t): x(x),y(y),type(t){}

    void get_Neighbors(vector<cell*> const grid){
        for (auto const g: grid){
            if (g!= this){
                if(g->type != '#'){
                    if(g->x == this->x + 1 && g->y == this->y) this->neighbors.push_back(g);
                    else if(g->x == this->x - 1 && g->y == this->y) this->neighbors.push_back(g);
                    else if(g->x == this->x && g->y == this->y+1) this->neighbors.push_back(g);
                    else if(g->x == this->x && g->y == this->y-1) this->neighbors.push_back(g);
                }
            }
        }
    }
};

int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();

    vector<cell*> grid;
    for (int rows = 0; rows < height; rows++) {
        string line;
        cin >> line; cin.ignore();
        for (int cols = 0; cols < line.size(); cols++){
            grid.push_back(new cell(cols,rows,line[cols]));
        }
    }
    for (int rows = 0; rows < height; rows++){
        for (int cols = 0; cols < width; cols++){
            grid[rows*width+cols]->get_Neighbors(grid);
            if(grid[rows*width+cols]->type != '#') cout << grid[rows*width+cols]->neighbors.size();
            else cout << '#';
        }
        cout << endl;
    }
}