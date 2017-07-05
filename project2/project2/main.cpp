#include "Sequence.h"
#include <string>
#include <iostream>
#include <cassert>
#include <type_traits>
using namespace std;

#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }

static_assert(std::is_default_constructible<Sequence>::value,
              "Sequence must be default-constructible.");
static_assert(std::is_copy_constructible<Sequence>::value,
              "Sequence must be copy-constructible.");

void thisFunctionWillNeverBeCalled()
{
    CHECKTYPE(&Sequence::operator=,  Sequence& (Sequence::*)(const ItemType&));
    CHECKTYPE(&Sequence::empty,      bool (Sequence::*)() const);
    CHECKTYPE(&Sequence::size,       int  (Sequence::*)() const);
    CHECKTYPE(&Sequence::insert,     bool (Sequence::*)(int, const ItemType&));
    CHECKTYPE(&Sequence::insert,     int (Sequence::*)(const ItemType&));
    CHECKTYPE(&Sequence::erase,      bool (Sequence::*)(int));
    CHECKTYPE(&Sequence::remove,     int  (Sequence::*)(const ItemType&));
    CHECKTYPE(&Sequence::get,	 bool (Sequence::*)(int, ItemType&) const);
    CHECKTYPE(&Sequence::set,	 bool (Sequence::*)(int, const ItemType&));
    CHECKTYPE(&Sequence::find,       int  (Sequence::*)(const ItemType&) const);
    CHECKTYPE(&Sequence::swap,       void (Sequence::*)(Sequence&));
    CHECKTYPE(subsequence, int  (*)(const Sequence&, const Sequence&));
    CHECKTYPE(interleave,  void (*)(const Sequence&, const Sequence&, Sequence&));
}

void test()
{
    // default constructor
    Sequence ok;
    // For an empty sequence:
    assert(ok.size() == 0);             // test size
    assert(ok.empty());                 // test empty
    assert(ok.remove("paratha") == 0);  // nothing to remove

    
    //INSERT
    Sequence s; // created a sequence object
    assert(s.insert(0, "lavash")); //insert value(string) at position 0
    assert(s.insert(0, "tortilla"));//insert another value(string) at position zero
    
    //SIZE
    assert(s.size() == 2); // makin sure size is two
    
    // GET
    //the value at position one went up by one
    ItemType x = "injera"; //define ItemType
    assert(s.get(0, x)  &&  x == "tortilla"); //after inserted making sure tortilla is at position 0
    assert(s.get(1, x)  &&  x == "lavash");// making sure lavash is at position 1
    
    Sequence k; // created another a sequence object
    assert(k.insert(0, "one")); //insert value(string) at position 0
    assert(k.insert(0, "two"));//insert another value(string) at position zero
    
    //SIZE
    assert(k.size() == 2); // makin sure size is two
    //GET
    ItemType  y = "sdfdsf"; //define ItemType
    assert(k.get(0, y)  &&  y == "two"); //after inserted making sure two is at position 0
    assert(k.get(1, y)  &&  y == "one");// making sure one is at position 1
    
    //FIND
    assert(k.find("one") == 1); //one is at position 1
    assert(k.find("two") == 0); // two is at position 0
    
    //SWAP
    k.swap(s); // swaping two function
    ItemType m = "injera"; //define ItemType
    assert(s.get(0, m)  &&  m == "two"); //after swaping s get k value at the position 0
    assert(s.get(1, m)  &&  m == "one");// after swaping s get k value at position 1
    
    //EMPTY
    assert(k.empty() == false); // checking if emtpy
    assert(s.empty() == false); // checking if empty
    
    //SET
    k.set(0, "three");
    assert(k.get(0, m)  &&  m == "three"); //after setting the value at position 0, changed value to three from two
    
    //REMOVE
    assert(k.remove("three") == 1); // removing the value
    
    //ERASE
    assert(k.erase(2) == false); // since k doesn't have position 2, returns false
    assert(s.erase(1) == true); // since s objects has items at postion 1, removed the item

    //INSERT
    assert(s.insert("zeo") == 1); // value is greater than item in sequence so it return 1
    
    
    //SUBSEQUENCE
    //making another sequence
    Sequence a;
    assert(a.insert(0, "a")); //insert value(string) at position 0
    assert(a.insert(1, "b"));//insert another value(string) at position 1
    assert(a.insert(2, "c")); //insert value(string) at position 2
    assert(a.insert(3, "d"));//insert another value(string) at position 3

    Sequence b;
    assert(b.insert(0, "c")); //insert value(string) at position 0
    assert(b.insert(1, "d"));//insert another value(string) at position 1
    
    assert(subsequence(a, b) == 2); // subsequence starts at position 2
    
    //INTERLEAVE
    Sequence result;
    interleave(a, b, result);
    
    ItemType z = "ninja";
    assert(result.get(0, z) && z == "a");//a from first sequence
    assert(result.get(1, z) && z == "c");//c from second sequence
    assert(result.get(2, z) && z == "b");// b from first sequence
    assert(result.get(3, z) && z == "d");//d from second sequence
    assert(result.get(4, z) && z == "c");//c from first sequence
    assert(result.get(5, z) && z == "d");//d from second sequence
}

int main()
{
    thisFunctionWillNeverBeCalled();
    test();
    
    cout << "Passed all tests" << endl;
}
