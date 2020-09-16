#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main()
{
    unordered_multimap<int,int> linked_nodes;
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        cerr << N1 << ' ' << N2 << endl;
        
        linked_nodes.emplace(make_pair(N1,N2));
    }

    vector<int> exit_nodes(E,0);
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        exit_nodes[i]= EI;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        for (auto m: linked_nodes){
            for (auto const e : exit_nodes){
                if (m.first == SI && m.second == e) {cout << m.first << ' ' << m.second << endl; goto end;}
                if(m.first == e && m.second == SI){cout << m.first << ' ' << m.second << endl; goto end;}
            }

        }

        for (auto const m : linked_nodes){
            if (m.first == SI){
                cout << m.first << ' ' << m.second << endl; goto end;
            }
            if(m.second == SI){
                cout << m.second << ' ' << m.first << endl; goto end;
            }
        }
                
        end: ;
    }
}