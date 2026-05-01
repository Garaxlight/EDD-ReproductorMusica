#pragma once
#include "Node.hpp"
template <typename T>
class Stack{
    private:
        Node<T>* top;

    public:
        Stack(){
            top = nullptr;
        }

        void push(T value){
            Node<T>* nuevo = new Node<T>(value);
            nuevo->next = top;
            top = nuevo;
        }

        void pop(){
            if (top==nullptr){return;}

            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }

        T top(){
            if (top == nullptr){
                throw std::runtime_error("Stack vacio");

            }
            return top->data;
        }

        bool isEmpty(){
            return top == nullptr;
        }
};