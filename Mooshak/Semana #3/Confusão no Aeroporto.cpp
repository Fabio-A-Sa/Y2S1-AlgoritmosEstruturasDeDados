// Created on 24 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Plane {

    char AorL;
    string name;
    int minute;
    int delay;

    public:
        Plane (string name, int minute, char AorL) : name(name), minute(minute), delay(0), AorL(AorL) {}
        void setDelay(int delay) { this->delay = delay; }
        int getDelay() { return delay; }
        int getMinute() { return minute; }
        string getName() { return name; }
        char getAorL() { return AorL; }
        void incrementDelay() { this->delay++; }
};

ostream & operator << (ostream & os,  Plane p) {
    os << p.getName() << " " << p.getDelay() << endl;
    return os;
}

void solve (vector<Plane> planes) {

    for (Plane plane : planes) {
        cout << plane;
    }
}

int main () {

    int cases, nLevantar, nAterrar, time;
    vector<Plane> planes = {};
    string currentName;

    cin >> cases;
    for (int i = 0 ; i < cases ; i++) {

        cin >> nLevantar >> nAterrar;
        for (int j = 0 ; j < nLevantar ; j++) {
            cin >> currentName >> time;
            Plane p = Plane(currentName, time, 'L');
            planes.push_back(p);
        }

        for (int k = 0 ; k < nAterrar ; k++) {
            cin >> currentName >> time;
            Plane p = Plane(currentName, time, 'A');
            planes.push_back(p);
        }

        cout << nLevantar << nAterrar;
        solve(planes);
        planes.clear();
    }

    return 0;
}