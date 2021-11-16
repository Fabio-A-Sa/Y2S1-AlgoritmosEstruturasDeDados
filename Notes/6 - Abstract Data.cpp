// Created on November, 2021
// @author: Fábio Araújo de Sá

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void AbstractData() {

    cout << "Arrays:" << endl;
    char[] name = {'F', 'E', 'U', };

    cout << "Lists:" << endl;
    list<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto number : numbers) cout << number << " ";
    cout << endl;

}

int main () {

    AbstractData();
    return 0;
}