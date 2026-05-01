#pragma once

template <typename T> //nodo generico

class Node {
    public:
        T data;
         Node* next;

         Node(T data){
            this->data = data;
            this->next = nullptr;
         }
};