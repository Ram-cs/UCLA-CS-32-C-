
#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;


void test()
{
    Sequence s;
    assert(s.insert(0, 100));
    assert(s.insert(0, 300));
    assert(s.size() == 2);
    ItemType x = 345;
    assert(s.get(0, x) && x == 300);
    assert(s.get(1, x) && x == 100);

    
    for (int i = 0; i < 130; i++) {
        s.insert(i);
    }
}

int main()
{
    test();
    Sequence s;
    Sequence a;
    
    assert(s.empty()); // check empty
    assert(a.empty()); // check empty
    
    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        s.insert(i);        // Insert 200 items in s
    }
    
    assert(s.size() == 200);    // Check if s = 200
    s.swap(a);  // swap the value between s and a objects
    assert(a.size() == 200);    // checking again the size
    for (int k = 0; k < 20; k++)
    {
        a.remove(k);    //remove first 20 elements
    }
    assert(a.size() == 180);    //checking remaining size
    
    Sequence r;
    r.insert(r.size(), 21); // Inserts at the last position
    r.insert(r.size(), 42); // Inserts at the last position
    assert(r.find(42) == 1);
    assert(!r.insert(5, 69));
    assert(!r.erase(3));
    assert(r.erase(1));
    assert(r.size() == 1);
    
    unsigned long swag = 33;
    assert(r.get(0, swag) && swag == 21);
    unsigned long remix = 968;
    assert(r.set(0, remix) && r.find(968) == 0);
    
    //checking if initial constructor works
    Sequence n (500);
    Sequence m (400);
    
    assert(n.size() == 0); // check size of n object
    assert(m.size() == 0); // check size of m object
    for (int i = 0; i < 300; i++)
    {
        n.insert(i);        // Insert 300 items in n
    }
    assert(n.size() == 300); //chec size of n
    n.swap(m); // swap n and m objects
    assert(n.size() == 0); // check size of n
    
    assert(m.size() == 300); // check size of object m
    
    
    
    cout << "Passed all tests" << endl;
}
