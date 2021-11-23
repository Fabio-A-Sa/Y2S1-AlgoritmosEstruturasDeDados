// Created on November, 2021
// @author: Fábio Araújo de Sá

# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {

	stack<T> values;
	stack<T> minimums;

    public:
        StackExt() {};
        bool empty() const;
        T& top();
        void pop();
        void push(const T& val);
        T& findMin();
};

template <class T> 
bool StackExt<T>::empty() const {
	return this->values.empty();
}

template <class T> 
T& StackExt<T>::top() {
    T& result = this->values.top();
    return result;
}

template <class T> 
void StackExt<T>::pop() {
    if (this->minimums.top() == this->values.top()) {
        this->minimums.pop();
    }
    this->values.pop();
}

template <class T> 
void StackExt<T>::push(const T& val) {
    if (this->minimums.empty()) this->minimums.push(val);
    this->values.push(val);
    if (val < this->minimums.top()) this->minimums.push(val);
}

template <class T> 
T& StackExt<T>::findMin() {
    T& result = this->minimums.top();
    return result;
}