//
//  main.cpp
//  LinkedList
//
//  Created by Dominic Chang on 9/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using std::ostream;
using namespace std;

int main (int argc, const char * argv[])
{
    LinkedList list;
    
    list.insertHead(1);
    list.insertHead(2);
    list.insertHead(3);
    list.insertHead(4);
    list.insertHead(5);
    cout << list.size << ":" << list << endl;
    
    list.deleteNode(1);
    list.deleteNode(3);    
    cout << list.size << ":" << list << endl;
    
    list.reverse();
    cout << list.size << ":" << list << endl;
    
    list.deleteNode(1);
    list.deleteNode(3);    
    cout << list.size << ":" << list << endl;

    list.deleteNode(5);
    list.deleteNode(4);
    list.deleteNode(2);
    cout << list.size << ":" << list << endl;
    list.deleteNode(5);
    list.deleteNode(4);
    list.deleteNode(2);
    cout << list.size << ":" << list << endl;

    list.reverse();
    cout << list.size << ":" << list << endl;
    
    
    list.insertHead(1);
    list.insertHead(2);
    list.insertHead(3);
    list.insertHead(4);
    list.insertHead(5);
    cout << list.size << ":" << list << endl;

    
    return 0;
}
