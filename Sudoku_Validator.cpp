#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{

    vector<int> grid(9*9, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n; cin.ignore();\
            grid[i*9+j] = n;
        }
    }

	//finding each row validation
    for (int rows = 0; rows < 9; rows++){
        unordered_map<int,int> row;
        for (int cols = 0; cols < 9; cols++){
            row[grid[rows*9+cols]]++;
        }
        for (int i = 0; i < row.size(); i++){
            if(row[i] > 1){cout << "false" << endl; goto end;}
        }
    }

	//finding each column validation
    for (int cols = 0; cols < 9; cols++){
        unordered_map<int,int> col;
        for (int rows = 0; rows < 9; rows++){    
            col[grid[rows*9+cols]]++;    
        }
        for (int i = 0; i < col.size(); i++){
            if(col[i] > 1){ cout << "false" << endl; goto end;}
        }
    }

	//finding each 3x3 validation
    for (int i = 0; i < 3; i++){
        unordered_map<int,int> subgrid;
        for (int rows = 3 * i; rows < (3*i+3); rows++){
            for (int cols = 3*i; cols < (3*i +3); cols++){
                subgrid[grid[rows*9+cols]]++;
            }
        }
        for (int i = 0; i < subgrid.size(); i++){
            if(subgrid[i] > 1){ cout << "false" << endl; goto end;}
        }
    }
    cout << "true" << endl;
    end: ;

}