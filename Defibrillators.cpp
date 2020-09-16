#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Data {
    string Name, Address, Phone;
    float Lon, Lat;

    Data(string N, string A, string P, string LON, string LAT) :Name(N), Address(A), Phone(P) {
        Lon = stof(LON, 0); Lat = stof(LAT, 0);
    }
};

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    for (auto& c : LON) {
        if (c == ',') c = '.';
    }
    for (auto& c : LAT) {
        if (c == ',') c = '.';
    }
    float lonn = stof(LON);
    float latt = stof(LAT);

    vector<Data*> defibs;
    for (int i = 0; i < N; i++) {
        string name, address, phone, lon, lat;
        string DEFIB;
        getline(cin, DEFIB);
        for (auto& c : DEFIB) {
            if (c == ',') c = '.';
        }
        name = DEFIB.substr(DEFIB.find(';') + 1);
        address = name.substr(name.find(';') + 1);
        phone = address.substr(address.find(';') + 1);
        lon = phone.substr(phone.find(';') + 1);
        lat = lon.substr(lon.find(';') + 1);
        name = name.substr(0, name.find(';'));
        address = address.substr(0, address.find(';'));
        phone = phone.substr(0, phone.find(';'));
        lon = lon.substr(0, lon.find(';'));
        defibs.push_back(new Data(name, address, phone, lon, lat));
    }

    Data* closest = defibs[0];
    float distance = 1000000000.0f;
    for (auto const d : defibs) {
        float x = (d->Lon - lonn) * cos((d->Lat + latt) / 2);
        float y = d->Lat - latt;
        float dis = sqrt(pow(x, 2) + pow(y, 2)) * 6371.0f;
        if (dis < distance) {
            distance = dis;
            closest = d;
        }
    }

    cout << closest->Name;

    defibs.clear();

    return 0;
}