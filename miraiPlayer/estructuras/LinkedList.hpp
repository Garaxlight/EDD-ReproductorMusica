#pragma once
#include "Node.hpp"

template <typename T>

class LinkedList {
    public:
        Node<T>* head;
        int size;


        LinkedList(){
            head = nullptr;
            size = 0;
        }

        //metodos para insertar, remover, obtener, etc
        void insertEnd(T data);
        void insertFront(T data);
        void removeFirst();
        void removeat(int index);
        T getAt (int index);
        bool isEmpty();
        void clear();
};