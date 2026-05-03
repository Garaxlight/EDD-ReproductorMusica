#pragma once
#include "Node.hpp"
#include <stdexcept>

template <typename T>
class Queue{
    private:
        Node<T>* front;
        Node<T>* back;

    public:
    Queue(){
        front = nullptr;
        back = nullptr;
    }

    void push(T value){
        Node<T>* nuevo = new Node<T>(value);
        if(back == nullptr){
            front = back = nuevo;
        }else{
            back->next = nuevo;
            back = nuevo;
        
        }
    }

    void dequeue(){
        if (front == nullptr) return;

        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr){
            back = nullptr;
        }
        delete temp;
    }
    void pushFront(T value){
        Node<T>* nuevo = new Node<T>(value);
        nuevo -> next = head;
        head = nuevo;
        if(back == nullptr){
            back = nuevo;
        }

    }

    T front(){
        if (front == nullptr){
            throw std::runtime_error("Queue vacia");
        }
        return front->data;
    }

    bool isEmpty(){
        return front == nullptr;
    }
};