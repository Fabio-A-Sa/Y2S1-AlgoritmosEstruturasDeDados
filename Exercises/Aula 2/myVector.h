#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyVector {

    vector<T> values;

    public:
        MyVector();
        ~MyVector();
        void push_back(T v1);
        vector<T> getValues() const;
        T max() const;
        bool hasDuplicates() const;
        void removeDuplicates() ;
};

class EmptyVector { };

template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

template <class T>
T MyVector<T>::max() const {

    if (!values.empty()) {
        T maxValue = values[0];
        for (int i = 0 ; i < values.size() ; i++ ) {
            if (maxValue < values[i]) maxValue = values[i];
        }
        return maxValue;

    } else {
        EmptyVector e = EmptyVector();
        throw (e);
    }

    // Complexidade espacial: O(1), pois as variáveis estáticas usadas não dependem do tamanho do vector
    // Complexidade temporal: O(n), pois percorre-se o vector de tamanho n (for loop)
}

template<class T>
bool MyVector<T>::hasDuplicates() const {

    if (values.empty()) return false;
    for (int i = 0 ; i < values.size() ; i++) {
        for (int j = i + 1 ; j < values.size() ; j++) {
            if (values[i] == values[j]) return true;
        }
    }
	return false;

    // Complexidade espacial: O(1), pois as variáveis estáticas usadas não dependem do tamanho do vector
    // Complexidade temporal: O(n^2), pois no pior cenário percorre-se o vector n(n-1) vezes
}

template<class T>
bool notIn (vector<T> vector, T number) {

    for (int i = 0 ; i < vector.size() ; i++) {
        if (number == vector[i]) return false;
    }
    return true;
}

template<class T>
void MyVector<T>::removeDuplicates() {

    if (hasDuplicates()) {
        vector<T> unique = {};
        for (auto number : values) {
            if (notIn(unique, number)) unique.push_back(number);
        }
        values = unique;
    }

    // Complexidade Temporal: O(n^2), no pior cenário, para cada n é necessário percorrer n vezes o vector unique (bool notIn)
    // Complexidade Espacial: O(1), as variáveis usadas não dependem do tamanho n do vector
}


