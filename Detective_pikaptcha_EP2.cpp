#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Cell {
    int x, y, count;
    char type;
    Cell(int x, int y, char type) : x(x), y(y), count(0), type(type) {};

    vector<Cell*> getN(vector<Cell*> const &Field, string const side) {
        vector<Cell*> Neighbors;
        Neighbors.push_back(nullptr);
        Neighbors.push_back(nullptr);
        Neighbors.push_back(nullptr);
        Neighbors.push_back(nullptr);
        if (side == "L") {

            for (auto const c : Field) {
                if (this->type == '>') {
                    if (c->type == '0') {
                        if (c->x == this->x && c->y == this->y - 1) Neighbors[0] = c;
                        else if (c->x == this->x + 1 && c->y == this->y) Neighbors[1] = c;
                        else if (c->x == this->x && c->y == this->y + 1) Neighbors[2] = c;
                        else if (c->x == this->x - 1 && c->y == this->y) Neighbors[3] = c;
                    }
                }
                else if (this->type == 'v') {
                    if (c->type == '0') {
                        if (c->x == this->x + 1 && c->y == this->y) Neighbors[0] = c;
                        else if (c->x == this->x && c->y == this->y + 1) Neighbors[1] = c;
                        else if (c->x == this->x - 1 && c->y == this->y) Neighbors[2] = c;
                        else if (c->x == this->x && c->y == this->y - 1) Neighbors[3] = c;
                    }
                }
                else if (this->type == '<') {
                    if (c->type == '0') {
                        if (c->x == this->x && c->y == this->y + 1) Neighbors[0] = c;
                        else if (c->x == this->x - 1 && c->y == this->y) Neighbors[1] = c;
                        else if (c->x == this->x && c->y == this->y - 1) Neighbors[2] = c;
                        else if (c->x == this->x + 1 && c->y == this->y) Neighbors[3] = c;
                    }
                }
                else if (this->type == '^') {
                    if (c->type == '0') {
                        if (c->x == this->x - 1 && c->y == this->y) Neighbors[0] = c;
                        else if (c->x == this->x && c->y == this->y - 1) Neighbors[1] = c;
                        else if (c->x == this->x + 1 && c->y == this->y) Neighbors[2] = c;
                        else if (c->x == this->x && c->y == this->y + 1) Neighbors[3] = c;
                    }
                }
            }

        }
        else if (side == "R") {

            for (auto const c : Field) {
                if (this->type == '>') {
                    if (c->type == '0') {
                        if (c->x == this->x && c->y == this->y + 1)Neighbors[0] = c;
                        else if (c->x == this->x + 1 && c->y == this->y)Neighbors[1] = c;
                        else if (c->x == this->x && c->y == this->y - 1) Neighbors[2] = c;
                        else if (c->x == this->x - 1 && c->y == this->y) Neighbors[3] = c;
                    }
                }
                else if (this->type == 'v') {
                    if (c->type == '0') {
                        if (c->x == this->x - 1 && c->y == this->y)Neighbors[0] = c;
                        else if (c->x == this->x && c->y == this->y + 1)Neighbors[1] = c;
                        else if (c->x == this->x + 1 && c->y == this->y) Neighbors[2] = c;
                        else if (c->x == this->x && c->y == this->y - 1) Neighbors[3] = c;
                    }
                }
                else if (this->type == '<') {
                    if (c->type == '0') {
                        if (c->x == this->x && c->y == this->y - 1)Neighbors[0] = c;
                        else if (c->x == this->x - 1 && c->y == this->y)Neighbors[1] = c;
                        else if (c->x == this->x && c->y == this->y + 1) Neighbors[2] = c;
                        else if (c->x == this->x + 1 && c->y == this->y) Neighbors[3] = c;
                    }
                }
                else if (this->type == '^') {
                    if (c->type == '0') {
                        if (c->x == this->x + 1 && c->y == this->y)Neighbors[0] = c;
                        else if (c->x == this->x && c->y == this->y - 1)Neighbors[1] = c;
                        else if (c->x == this->x - 1 && c->y == this->y) Neighbors[2] = c;
                        else if (c->x == this->x && c->y == this->y + 1) Neighbors[3] = c;
                    }
                }
            }

        }

        return Neighbors;
    }
};

void print(vector<Cell*> const grid) {
    for (auto const c : grid) {
        cerr << "pos (" << c->x << ',' << c->y << ") " << "char: " << c->type << " times stepped on: " << c->count << endl;
    }
}

void solve(vector<Cell*>const &Field, string const side, Cell*& current, int const w, int const h) {
    Cell* end = current;

    bool solving = true;
    while (solving) {


        vector<Cell*> Neighbors;

        if (end->count == 1) solving = false;

        else {
            if (side == "L") {

                Neighbors = current->getN(Field, side);
                if (Neighbors[0] == nullptr && Neighbors[1] == nullptr && Neighbors[2] == nullptr && Neighbors[3] == nullptr) {
                    solving = false;
                }
                else {
                    for (auto& n : Neighbors) {

                        if (n != nullptr) {
                            if (n == Neighbors[0]) {
                                switch (current->type) {
                                case '>': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            else if (n == Neighbors[1]) {
                                switch (current->type) {
                                case '>': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            else if (n == Neighbors[2]) {
                                switch (current->type) {
                                case '>': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            else if (n == Neighbors[3]) {
                                switch (current->type) {
                                case '>': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            break;
                        }

                    }
                }

            }
            else if (side == "R") {

                Neighbors = current->getN(Field, side);
                if (Neighbors[0] == nullptr && Neighbors[1] == nullptr && Neighbors[2] == nullptr && Neighbors[3] == nullptr) {
                    solving = false;
                }
                else {
                    for (auto& n : Neighbors) {

                        if (n != nullptr) {
                            if (n == Neighbors[0]) {
                                switch (current->type) {
                                case '>': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            else if (n == Neighbors[1]) {
                                switch (current->type) {
                                case '>': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            else if (n == Neighbors[2]) {
                                switch (current->type) {
                                case '>': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            else if (n == Neighbors[3]) {
                                switch (current->type) {
                                case '>': n->type = '<'; current->type = '0'; n->count++; current = n; break;
                                case 'v': n->type = '^'; current->type = '0'; n->count++; current = n; break;
                                case '<': n->type = '>'; current->type = '0'; n->count++; current = n; break;
                                case '^': n->type = 'v'; current->type = '0'; n->count++; current = n; break;
                                }
                            }
                            break;
                        }

                    }
                }
            }
        }
    }
}

int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();

    vector<Cell*> Field;
    Cell* Current = nullptr;

    for (int i = 0; i < height; i++) {
        string line;
        cin >> line; cin.ignore();

        int count = 0;
        for (auto const c : line) {
            if (c == '<'){ Field.push_back(new Cell(count, i, '<')); Current = Field[i*width + count];}
            else if (c == '>'){ Field.push_back(new Cell(count, i, '>')); Current = Field[i*width + count];}
            else if (c == '^'){ Field.push_back(new Cell(count, i, '^')); Current = Field[i*width + count];}
            else if (c == 'v'){ Field.push_back(new Cell(count, i, 'v')); Current = Field[i*width + count];}
            else if (c == '0') Field.push_back(new Cell(count, i, '0'));
            else if (c == '#') Field.push_back(new Cell(count, i, '#'));
            count++;
        }
    }

    string side;
    cin >> side; cin.ignore();

    solve(Field, side, Current, width, height);

    for (auto const c : Field) {
        if (c->type == '#') cout << '#';
        else if (c->type == '0' || c->type == '<' || c->type == '>' || c->type == '^' || c->type == 'v') cout << c->count;

        if (c->x == width - 1) cout << endl;
    }
}