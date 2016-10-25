// Kyle Semelka 861220581
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
#define MAX_SIZE 20

using namespace std;

template<typename T>
class stack {
    private:
        T data[MAX_SIZE];
        unsigned size;
    public:
        stack();
        void push(T val);
        void pop();
        T top();
        bool empty() const;
};

template<typename T>
stack<T>::stack() {
    size = -1;
}

template<typename T>
void stack<T>::push(T val) {
    if (size == MAX_SIZE - 1) {
        throw overflow_error("Called push on full stack.");
    }
    else {
        size++;
        data[size] = val;
    }
}

template<typename T>
void stack<T>::pop() {
    if (empty()) {
        throw out_of_range("Called pop on empty stack.");
    }
    else {
        --size;
    }
}

template<typename T>
T stack<T>::top() {
    if (empty()) {
        throw underflow_error("Called top on empty stack.");
    }
    return data[size];
}

template<typename T>
bool stack<T>::empty() const {
    if (size == -1) {
        return true;
    }
    else {
        return false;
    }
}

#endif