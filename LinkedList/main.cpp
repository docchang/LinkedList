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
    
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << list << endl;
    
    list.deleteNode(1);
    list.deleteNode(3);
    
    cout << list << endl;
    
    list.reverse();
    
    cout << list << endl;
    
    return 0;
}
