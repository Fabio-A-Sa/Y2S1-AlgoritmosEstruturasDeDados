// Created on 20 November, 2021
// author: Fábio Araújo de Sá, up202007658

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Letter {

    char letter;
    int frequency, firstOccurrence;

    public:
        Letter(char letter, int frequency, int firstOccurrence);
        char getLetter() const;
        int getFrequency() const;
        int getFirstOccurrence() const;
};

Letter::Letter(char letter, int frequency, int firstOccurrence) :
        letter(letter),
        frequency(frequency),
        firstOccurrence(firstOccurrence) {}

char Letter::getLetter() const { return letter; }
int Letter::getFrequency() const { return frequency; }
int Letter::getFirstOccurrence() const { return firstOccurrence; }

class ADN {

    vector<Letter> letters;
    string sequence;
    string unique;

    public:
        ADN(string name);
        void showFrequency();
        friend bool notIn (char c, string s);
};

bool notIn (char c, string s) {
    for (auto l : s) if (c == l) return false;
    return true;
}

bool key (const Letter &a, const Letter &b) {
    if (a.getFrequency() == b.getFrequency()) {
        return a.getFirstOccurrence() < b.getFirstOccurrence();
    } else return a.getFrequency() > b.getFrequency();
}

ADN::ADN(string sequence) : sequence(sequence) {

    this->letters.clear();
    int firstOcc;
    string unique = "";

    for (auto letter : sequence) if (notIn(letter, unique)) unique += letter;

    for (auto letter : unique) {
        for (int i = 0 ; i < sequence.size() ; i++) {
            if (sequence[i] == letter) {
                firstOcc = i;
                break;
            }
        }
        Letter l = Letter(letter, count(sequence.begin(), sequence.end(), letter), firstOcc);
        letters.push_back(l);
    }
    sort(letters.begin(), letters.end(), key);
}

void ADN::showFrequency() {

    for (auto letter : letters) {
        cout << letter.getLetter() << " " << letter.getFrequency()  << endl;
    }
}

int main () {

    string sequence;
    cin >> sequence;
    ADN input = ADN(sequence);
    input.showFrequency();

    return 0;
}