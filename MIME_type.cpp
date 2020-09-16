#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    unordered_map<string, string> Lookup;

    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        //cerr << EXT << " " << MT << endl;
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::toupper);
        Lookup.emplace(EXT, MT);
    }

    for (int i = 0; i < Q; i++) {
        string FNAME;
        getline(cin, FNAME); // One file name per line.
        string type = "UNKNOWN";
        
        int found2 = 0;
        int pos = 0;
        for (int i = FNAME.size() - 1; i >= 0; i--){
            if(FNAME[i] == '.') {found2++; pos = i; break;}
        }
        if(found2 == 1) {type = FNAME.substr(pos+1);}
        
        transform(type.begin(), type.end(), type.begin(), ::toupper);

        if(Lookup.count(type) == 1) cout << Lookup.at(type) << endl;
        else{ cout << "UNKNOWN" << endl;}
        
    }

}