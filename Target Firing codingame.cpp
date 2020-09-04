#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Enemy {
    int attackstokill;
    float perc;
    string type;
    int hp, armor, damage;

    Enemy(string T, int hp, int armor, int damage) :type(T), hp(hp), armor(armor), damage(damage) {
        getKill();
    };

    void getKill() {
        if (this->type == "FIGHTER") {
            int temp = 0;
            if (this->armor >= 20) temp = this->hp;
            else if (this->hp % (20 - this->armor) == 0) temp = this->hp / (20 - this->armor);
            else temp = this->hp / (20 - this->armor) + 1;
            this->attackstokill = temp;
        }
        else {
            int temp = 0;
            if (this->armor >= 10) temp = this->hp;
            else if (this->hp % (10 - this->armor) == 0) temp = this->hp / (10 - this->armor);
            else temp = this->hp / (10 - this->armor) + 1;
            this->attackstokill = temp;
        }
    }

    void getPerc() {
        this->perc = (float)this->attackstokill / this->damage;
    }

    void print() {
        //cerr << this->type << " " << this->hp << " " << this->armor << " " << this->damage << " " << this->attackstokill << " " << this->mincost << " " << this->maxcost << " " << this->maxcost - this->mincost << endl;
        cerr << this->perc << endl;
    }
};



int main()
{
    int N;
    cin >> N; cin.ignore();

    int shield = 5000;
    vector<Enemy*> aliens;
    for (int i = 0; i < N; i++) {
        string TYPE;
        int HP;
        int ARMOR;
        int DAMAGE;
        cin >> TYPE >> HP >> ARMOR >> DAMAGE; cin.ignore();
        aliens.push_back(new Enemy(TYPE, HP, ARMOR, DAMAGE));
    }
    for (auto& e : aliens) {
        e->getPerc();

        e->print();
    }

    while ((int)aliens.size() > 0 && shield >= 0) {


        Enemy* attack = aliens[0];

        int pos = 0;
        for (int i = 1; i < (int)aliens.size(); i++) {
            if (aliens[i]->perc < attack->perc) {
                pos = i;
                attack = aliens[i];
            }
        }

        while (attack->attackstokill > 0) {
            for (auto e : aliens) {
                shield -= e->damage;
            }
            attack->attackstokill--;
        }
        if (attack->attackstokill == 0) aliens.erase(aliens.begin() + pos);
    }

    if (shield < 0) { cout << "FLEE"; }
    else cout << shield;

}