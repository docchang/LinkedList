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
    int size;
    
    LinkedList() {
        Head = NULL;
        size = 0;
    }
    
    ~LinkedList() {
        for (Node *i = Head; i != NULL;) {
            Node *p = i;    //keep the 
            i = i->next;    //advance pointer
            free(p);        //free node
        }
    }
    
    Node *getTail() {
        Node *p = Head;
        while (p->next != NULL) {
            p = p->next;
        }
        return p;
    }
    
    void insertTail(Node *newNode) {
        size++;
        
        //empty list
        if (Head == NULL) {
            Head = newNode;
            return;
        }
        
        Node *tail = getTail();
        tail->next = newNode;
        tail = tail->next;      //advance tail to the new node
        tail->next = NULL;      //ensure NULL terminated
    }
    
    //insert Head
    void insertHead(Node *newNode) {
        size++;
        
        //empty list
        if (Head == NULL) {
            Head = newNode;
            return;
        }
        
        newNode->next = Head;
        Head = newNode;
    }
    
    //insert Head
    void insertHead(int value) {
        Node *newNode = new Node(value);
        insertHead(newNode);
    }
    //insert Tail
    void insertTail(int value) {
        Node *newNode = new Node(value);
        insertTail(newNode);
    }

    bool deleteNode(int value) {        
        for (Node *i = Head, *prev = NULL; i != NULL; prev = i, i = i->next) {
            
            //value found
            if (i->value == value) {

                if (i == Head) {
                    Head = i->next;
                }  else {
                    prev->next = i->next;
                }
                
                free(i);
                size--;
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
        insertTail(ptr);
        size--;
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




