// Created on November, 2021
// @author: Fábio Araújo de Sá
// Theorical Lecture 5, 04/11/2021, Iterators

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {

    string name;
    unsigned int up;
    int age;

    public:
        Person();
        Person(string name, unsigned int up, int age);
        void setName(string name);
        void setAge(int age);
        void setUp(unsigned int up);
        string getName() const;
        unsigned int getUp() const;
        int getAge() const;
        void presentation();
        bool operator == (const Person &p) const;
        bool operator < (const Person &p) const;
};

Person::Person() {}
Person::Person(string name, unsigned int up, int age) : name(name), up(up), age(age) {}

void Person::setName (string name) { this->name = name; }
void Person::setAge (int age) { this-> age = age; }
void Person::setUp (unsigned int up) { this->up = up; }

string Person::getName() const { return name; }
unsigned int Person::getUp() const { return up; }
int Person::getAge() const { return age; }

ostream & operator << (ostream & os, const Person &p) {
    os << p.getName() << " have up " << p.getUp() << " and " << p.getAge() << " years old" << endl;
    return os;
}

bool Person::operator == (const Person &p) const {
    return (age == p.getAge() && up == p.getUp() && name == p.getName());
}

bool Person::operator < (const Person &p) const {
    return age < p.getAge();
}

bool isTeenager (const Person &p) { return p.getAge() < 20 ; }

bool younger (const Person &p1, const Person &p2) {
    return p1.getAge() < p2.getAge();
}

void writeVector (vector<Person> p) {
    for (auto person : p) {
        cout << p << endl;
    }
}

void sequentialSearch() {

    cout << "\nTest sequentialSearch() STL algorithm:" << endl;
    vector<int> numbers = {23, 3, 123, 3, 1, 3, 5, 65, 32, 654, 246, 776, 3, 76, 457, 5, 975, 3224, 8, 2, 5, 42, 644, 75, 2, 44, 64};
    vector<int> keys = {1, 2, 3, 4, 5, 6, 7, 8};
    for (auto key : keys) {
        vector<int>::iterator it = find(numbers.begin(), numbers.end(), key);
        string result = it == numbers.end() ? "not found" : "found";
        cout << key << "? " << result << endl;
    }
}

bool lambda (int x, int y) { return x < y; }

void binarySearch() {

    cout << "\nTest binarySearch() STL algorithm:" << endl;
    vector<int> sortedNumbers = {0, 4, 6, 7, 12, 45, 67, 89, 133, 245, 246, 467, 6789, 23455};
    vector<int> keys = {3, 7, 12, 245, 246, 247, 890, 23455};
    for (auto key : keys) {
        string result = binary_search(sortedNumbers.begin(), sortedNumbers.end(), key, lambda) ? "found" : "not found";
        cout << key << "? " << result << endl;
    }
    cout << endl;
}

void testPerson() {

    vector<Person> vp;
    vp.push_back(Person("6666666","Rui Silva",34));
    vp.push_back(Person("7777777","Antonio Matos",24));
    vp.push_back(Person("1234567","Maria Barros",20));
    vp.push_back(Person ("7654321","Carlos Sousa",18));
    vp.push_back(Person("3333333","Fernando Cardoso",33));
    cout << "initial vector:" << endl;
    writeVector(vp);
}

int main () {

    sequentialSearch();
    binarySearch();
    testPerson();
    return 0;
}