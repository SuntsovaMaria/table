#include <iostream>
#include "poly.h"
#include "hash.h"
#include "avl.h"
#include "unorderedlist.h"
#include "unorderedvect.h"
#include "ordered.h"

using namespace std;

int main() {
    poly p1("xyz+1"), p2("x2+y"), p3("z5+xy3+2");

   
    HashTable<string, poly, funct1> hashTable;
    hashTable.insertp("poly1", p1);
    hashTable.insertp("poly2", p2);
    hashTable.insertp("poly3", p3);

    cout << "HashTable before deletion:" << endl;
    hashTable.print();
    hashTable.deletep("poly2");
    cout << "HashTable after deletion:" << endl;
    hashTable.print();

    UnorderedTablesList<string, poly> unorderedList;
    unorderedList.insert("poly1", p1);
    unorderedList.insert("poly2", p2);
    unorderedList.insert("poly3", p3);

    cout << "\nUnordered List before deletion:" << endl;
    unorderedList.print();
    unorderedList.remove("poly2");
    cout << "Unordered List after deletion:" << endl;
    unorderedList.print();

   
    UnorderedTables<string, poly> unorderedVector;
    unorderedVector.insert("poly1", p1);
    unorderedVector.insert("poly2", p2);
    unorderedVector.insert("poly3", p3);

    cout << "\nUnordered Vector before deletion:" << endl;
    unorderedVector.print();
    unorderedVector.remove("poly2");
    cout << "Unordered Vector after deletion:" << endl;
   unorderedVector.print();

    
    OrderedTables<string, poly> orderedList;
    orderedList.insert("poly1", p1);
    orderedList.insert("poly2", p2);
    orderedList.insert("poly3", p3);

    cout << "\nOrdered List before deletion:" << endl;
    orderedList.print();
    orderedList.remove("poly2");
    cout << "Ordered List after deletion:" << endl;
    orderedList.print();

    return 0;
}
