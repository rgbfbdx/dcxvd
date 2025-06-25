// DoublyLinkedList.h
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    void insert(int position, int value);
    void erase(int position);
    int find(int value);
    void clear();
    int size() const;
    bool empty() const;
    void print_forward() const;
    void print_backward() const;
};

#endif

// DoublyLinkedList.cpp
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

void DoublyLinkedList::pop_front() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    count--;
}

void DoublyLinkedList::pop_back() {
    if (!tail) return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    count--;
}

void DoublyLinkedList::insert(int position, int value) {
    if (position <= 0) {
        push_front(value);
    } else if (position >= count) {
        push_back(value);
    } else {
        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        Node* newNode = new Node(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        count++;
    }
}

void DoublyLinkedList::erase(int position) {
    if (position < 0 || position >= count) return;
    if (position == 0) {
        pop_front();
    } else if (position == count - 1) {
        pop_back();
    } else {
        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        count--;
    }
}

int DoublyLinkedList::find(int value) {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->value == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void DoublyLinkedList::clear() {
    while (head) pop_front();
}

int DoublyLinkedList::size() const {
    return count;
}

bool DoublyLinkedList::empty() const {
    return count == 0;
}

void DoublyLinkedList::print_forward() const {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::print_backward() const {
    Node* current = tail;
    while (current) {
        cout << current->value << " ";
        current = current->prev;
    }
    cout << endl;
}