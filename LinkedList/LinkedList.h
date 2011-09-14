//
//  LinkedList.h
//  LinkedList
//
//  Created by Dominic Chang on 9/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using std::ostream;
using namespace std;

class Node {
public:
    int value;
    Node *next;
    
    Node(int val = 0) {
        value = val;
        next = NULL;
    }
    ~Node() {}
};

class LinkedList {
public:
    Node *Head;
    Node *Tail;
    int size;
    
    LinkedList() {
        Head = NULL;
        Tail = Head;
    }
    
    ~LinkedList() {
        for (Node *i = Head; i != NULL;) {
            Node *p = i;    //keep the 
            i = i->next;    //advance pointer
            free(p);        //free node
        }
    }
    
    void insert(Node *newNode) {
        //empty list
        if (Tail == NULL) {
            Tail = newNode;
            Head = Tail;
            return;
        }
        
        Tail->next = newNode;
        Tail = newNode;
        Tail->next = NULL;
    }
    
    void insert(int value) {
        Node *newNode = new Node(value);
        insert(newNode);
    }

    bool deleteNode(int value) {        
        for (Node *i = Head, *prev = NULL; i != NULL; prev = i, i = i->next) {
            
            //value found
            if (i->value == value) {
                if (i == Head) {
                    Head = i->next;
                } else if (i == Tail) {
                    Tail = prev;
                    Tail->next = NULL;
                } else {
                    prev->next = i->next;
                }
                
                free(i);
                return true;
            }
        }
        
        return false;
    }
    
    void reverse() {
        //base case
        if (Head == NULL || Head->next == NULL) {
            return;
        }
        
        //inductive step
        Node *ptr = Head;
        Head = Head->next;
        reverse();
        insert(ptr);
    }
    
    //overload << operator
    friend ostream& operator<< (ostream& out, const LinkedList& L) {
        for (Node *i = L.Head; i != NULL; i = i->next) {
            out << i->value << ", ";
        }
        
        return out;
    }
    
};

#endif




