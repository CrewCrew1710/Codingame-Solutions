#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

 struct Cell{
     bool node;
     int x,y;
     Cell(int x, int y, char type) :x(x), y(y){
         if (type == '0') node = true;
         else node = false;
     }

     vector<Cell*> getN(vector<Cell*> const &Field){
         vector<Cell*> Neighbors;
         Neighbors.push_back(nullptr);
         Neighbors.push_back(nullptr);
         for (auto const c : Field){
            if(c->node == true && c->x >= this->x + 1 && c->y == this->y){
                if(Neighbors[0] == nullptr) Neighbors[0] = c;
                else Neighbors[0] = Neighbors[0];
            }
            else if(c->node == true && c->x == this->x && c->y >= this->y + 1){
                if(Neighbors[1] == nullptr) Neighbors[1] = c;
                else Neighbors[1] = Neighbors[1];
            }
         }
         return Neighbors;
     }
 };

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    vector<Cell*> Field;
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .

        int count = 0;
        for (auto const c : line){
            Field.push_back(new Cell(count, i, c));
            count++;
        }
    }

    for (auto const c : Field){
        vector<Cell*> Neighbors;
        if(c->node){
            Neighbors = c->getN(Field);
            cout << c->x << " " << c->y << " ";
            for(auto const n : Neighbors){
                if(n == nullptr) cout << "-1 -1 ";
                else cout << n->x << " " << n->y << " ";
            }
            cout << endl;
        }

    }
}