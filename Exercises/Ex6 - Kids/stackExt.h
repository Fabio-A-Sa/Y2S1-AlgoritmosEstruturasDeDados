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

//TODO
template <class T> 
bool StackExt<T>::empty() const {
	return true;
}

//TODO
template <class T> 
T& StackExt<T>::top() {
    return *new T();
}

//TODO
template <class T> 
void StackExt<T>::pop() {
}

//TODO
template <class T> 
void StackExt<T>::push(const T& val) {
}

//TODO
template <class T> 
T& StackExt<T>::findMin() {
    return *new T();
}

