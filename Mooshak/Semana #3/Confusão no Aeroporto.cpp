// Created on 24 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Plane {

    private string name;
    private int minute;
    private int delay;

    public:
        Plane (string name, int minute) : name(name), minute(minute), delay(0) {}
        void setDelay(int delay) { this->delay = delay; }
        int getDelay() { return delay; }
        int getMinute() { return minute; }
        string getName() { return name; }
        ostream & operator << (ostream & os, const Plane &p);
};

ostream & Plane::operator << (ostream & os, const Plane &p) {
    os << p.getName() << " " << p.getDelay() << endl;
    return os;
}

int main () {


    return 0;
}