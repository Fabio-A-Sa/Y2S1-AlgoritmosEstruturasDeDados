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
    bool runway;

    public:
        Plane (string name, int minute, char AorL) : name(name), minute(minute), delay(0), AorL(AorL), runway(false) {}
        void setDelay(int delay) { this->delay = delay; }
        int getDelay() { return delay; }
        int getMinute() { return minute; }
        string getName() { return name; }
        char getAorL() { return AorL; }
        void incrementDelay(int increment) { this->delay+=increment; }
        void finished () { this->runway = true; }
        bool getRunway() { return runway; }
        bool operator < (const Plane &p);
};

ostream & operator << (ostream & os,  Plane p) {
    os << p.getName() << " " << p.getDelay() << endl;
    return os;
}

bool Plane::operator < (const Plane &p) {
    if (this->getMinute() == p.getMinute()) {
        return this->getAorL() < p.getAorL();
    } else return this->getMinute() < p.getMinute();
}

vector<Plane> findPlanes (vector<Plane> planes, int clock) {
    vector<Plane> result = {};
    for (Plane plane : planes) {
        if (clock == plane.getDelay()) result.push_back(plane);
    }
    return result;
}

void solve (vector<Plane> planes, vector<int> times) {

    int lastTime = 0;
    for (int time : times) {

        vector<Plane> availablePlanes = findPlanes(planes, time);
        sort(availablePlanes.begin(), availablePlanes.end());

        if (!availablePlanes.empty()) {
            for (auto &plane : availablePlanes) {
                plane.finished();
                for (auto &plane : planes) if (!plane.getRunway()) plane.incrementDelay(1);
                lastTime++;
            }
        }

        int increment = time - lastTime;
        for (Plane &plane : planes) {
            if (!plane.getRunway()) plane.incrementDelay(increment);:
        }

        lastTime = time;
    }

    for (Plane plane : planes) {
        cout << plane;
    }
}

bool notIn(vector<int> times, int time) {
    for (int i : times) if (i == time) return false;
    return true;
}

int main () {

    int cases, nLevantar, nAterrar, time;
    vector<Plane> planes = {};
    vector<int> times = {};
    string currentName;

    cin >> cases;
    for (int i = 0 ; i < cases ; i++) {

        cin >> nLevantar >> nAterrar;
        for (int j = 0 ; j < nLevantar ; j++) {
            cin >> currentName >> time;
            Plane p = Plane(currentName, time, 'L');
            if (notIn(times, time)) times.push_back(time);
            planes.push_back(p);
        }

        for (int k = 0 ; k < nAterrar ; k++) {
            cin >> currentName >> time;
            Plane p = Plane(currentName, time, 'A');
            if (notIn(times, time)) times.push_back(time);
            planes.push_back(p);
        }

        cout << nLevantar << nAterrar;
        solve(planes, sort(times.begin(), times.end()));
        planes.clear();
    }

    return 0;
}