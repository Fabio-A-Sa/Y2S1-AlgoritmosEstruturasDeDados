// Created on 24 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Plane {

    public:

        char AorL;
        string name;
        int minute;
        int delay;
        bool runway;

        Plane (string name, int minute, char AorL) : name(name), minute(minute), delay(0), AorL(AorL), runway(false) {}

        bool operator < (Plane p);
        bool operator == (Plane p);
};

ostream & operator << (ostream & os,  Plane p) {
    os << p.name << " " << p.delay << endl;
    return os;
}

bool Plane::operator < (Plane p) {
    if (minute == p.minute) {
        return AorL < p.AorL;
    } else return minute < p.minute;
}

bool Plane::operator == (Plane p) {
    return runway == p.runway && AorL == p.AorL && minute == p.minute && name == p.name;
}

vector<Plane> findPlanes (vector<Plane> planes, int clock) {
    vector<Plane> result = {};
    for (Plane plane : planes) {
        if (clock == plane.minute && !plane.runway) result.push_back(plane);
    }
    return result;
}

void solve (vector<Plane> planes, vector<int> times) {

    int currentTime = 0;
    for (int time : times) {

        vector<Plane> availablePlanes = findPlanes(planes, time);
        sort(availablePlanes.begin(), availablePlanes.end());

        if (!availablePlanes.empty()) {
            for (int i = 0 ; i < availablePlanes.size() ; i++) {
                availablePlanes[i].finished();
                for (int j = i + 1 ; j < availablePlanes.size() ; j++) {
                    availablePlanes[j].incrementDelay(1);
                }
            }
        }

        for (Plane &plane : planes) {
            if (!plane.getRunway()) plane.incrementDelay(0);
        }

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

        cout << nLevantar <<  " " << nAterrar << endl;
        sort(times.begin(), times.end());
        solve(planes, times);
        planes.clear();
    }

    return 0;
}