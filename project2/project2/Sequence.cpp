
#include "Sequence.h"



Sequence::Sequence(): m_size(0) {
    //making circular link
    head = new Node;
    // for the empty circular link list, next points its head
    head->next = head;
    head->previous = head; // previous points its head
}

Sequence::Sequence(const Sequence& old): m_size(old.m_size) {
    //always initialize new head
    head = new Node;
    head->next = head;
    head->previous = head;

    Node* p;
    for (p = old.head->next; p != old.head; p = p->next) //if last node points head loop breaks
    {
        Node* newNode = new Node; // creat new node
        newNode-> value = p->value; // assign the value to new node from the old node
        newNode->next = head; //new node next pointing to head
        newNode->previous = head->previous; //new node previous
        head->previous->next = newNode; //head previous next points to new node
        head->previous = newNode; // head previous points to new node
    }
}

Sequence& Sequence::operator=(const Sequence& other) {
    if (&other == this) //if assign itself then return itself
        return *this;
    
    Sequence temp(other); //temp objects store "other" objects value
    swap(temp); // swaping current objects(temp) with other objects
    return *this; // returning current objects value
}

Sequence::~Sequence(){
    while (head->next != head) { // making sure head next ponter doesn't have its own address
        Node* tempPtr = head->next; //store the adjacent node address of head with tempPtr
        head->next = tempPtr->next; // change the head next address with its next adjacent node
        tempPtr->next->previous = tempPtr->previous;
        delete tempPtr; // delete adjacent node
    }
    delete head; // finally once everything deleted, deleting head
}

bool Sequence::empty() const { // size() == 0 is empty
    if (size() == 0) // if empty return 0 otherwise false
        return true;
    return false;
}

int Sequence::size() const { // returning size, so if size is n then position is always n-1
    return m_size;
}

bool Sequence::insert(int pos, const ItemType& value) {
    
    // if position is negative or more than size
    if (pos < 0 || pos > size()) {
        return false;
    }
    
    if (pos >= 0 && pos < size()) { //check if pos is greater than 0 and less than size
        Node* p = head; //assigned head to new node
        for (int i = 0; i < size(); i++) { //go through loop untill index or pos is less than size
            Node* newNode = new Node; //create new node
            p = p->next;//iteration through each node
            if (i == pos) { //if given position is equal to index i
                newNode->value = value;
                newNode->next = p; // exchange the value, next and previous bewen consacutive nodes
                newNode->previous = p->previous;
                p->previous->next = newNode;
                p->previous = newNode;
               
                m_size++; //once inserted increase size by one
                return true;
            }
            p = p->next; //poits to next node
        }
    }
    
    else if (pos == size()) { //if pos equal size
        Node* newNode = new Node; //crate new node and exchange next, previous with head node
        newNode->value = value;
        newNode->next = head;
        newNode->previous = head->previous;
        head->previous->next = newNode;
        head->previous = newNode;
        m_size++; //at he end increase size once inserted
        return true;
    }
    return true;
}

int Sequence::insert(const ItemType& value) {
    int position = -1;
    if (empty()) { // if there is no sequence, inserted node will be
        //at position 0 with size 1
        Node* newNode = new Node;//crating a new node
        newNode->value = value;
        newNode->previous = head;
        newNode->next = head;
        head->previous = newNode;
        head->next = newNode;
        insert(position, value); //inserting the value at position
        return position;
    } else {
        Node* p = head;
        for (int i = 0; i < size(); i++) {
            p = p->next; //inerate through each node
            
            if (value <= p->value) { //when given value is equal or less than nodes value
                position = i; //if item exists function return index of sequence
                break;
            } else {
                position = size(); //otherwise position is size
            }
        }
        insert(position, value); // inserting value at the end
    }
    return position; //return position
}


bool Sequence::erase(int pos) {
    if(pos >= 0 && pos < size()) { //pos must be grater than 0 and less than size
        Node* p = head;
        
        //for size n, position(pos) is n-1
        for (int i = 0; i < size(); i++) {
            p = p->next; //iterating through each loop
            if (pos == i) {
                Node* deleteNode = p; //assigned delete target node with new delete Node
                p->next->previous = p->previous;
                p->previous->next = p->next;
                delete deleteNode; //deleting the node at position
                m_size--; // decreasing size
                return true;
            }
        }
    }
    return false;
}

int Sequence::remove(const ItemType& value) {
    int removedItem = 0; // since no item removed
    Node* p;
    int flag = 1;
    
    while (p != head) { // check point
        if (flag) { //one time assigning the head to p
            p = head;
            flag = 0;
        }
        
        p = p->next; // iteration
        
        if (p->value == value) { //if value found delete node
            Node* deleteNode = p; // assigning the value with before and after the deleting node
            p->next->previous = p->previous;
            p->previous->next = p->next;
            delete deleteNode; //deleting the node at position
            removedItem++;//increase removed item by one each time
            m_size--;//decrease the size
        }
    }
    return removedItem;
}

bool Sequence::get(int pos, ItemType& value) const {
    if(pos >= 0 && pos < size()) { //pos must be greater than 0 and less than size()
        Node* p = head;
        //for size n, position(pos) is n-1
        for (int i = 0; i < size(); i++) {
            p = p->next; //iterating through nodes in the list
            if (pos == i) { //if found the positon
                value = p->value; // get the value
                return true;
            }
        }
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value) {
    if(pos >= 0 && pos < size()) {
        Node* p = head;
        
        //for size n, position(pos) is n-1
        for (int i = 0; i < size(); i++) {
            p = p->next;
            if (pos == i) {
                p->value = value;
                return true;
            }
        }
    }
    return false;
}

int Sequence::find(const ItemType& value) const{
    int p = -1;
    int i = 0;
    Node* pNode;
    
    //starting with the position 0 , each iteration point consequtive node
    //iterating by one node each time
    for (pNode = head->next; pNode != head; pNode = pNode->next) {
        //once foud value
        if (pNode->value == value) { //if current node value is value then return its position
            p = i;
            return p;
        }
        i++; //increament i
    }
    return p;
}

void Sequence::swap(Sequence& other) {
    //swapping size and head
    int swapSize = other.m_size;
    other.m_size = m_size;
    m_size = swapSize;
    
    Node* swapHead = other.head;
    other.head = head;
    head = swapHead;
}

int subsequence(const Sequence& seq1, const Sequence& seq2) {
    if (seq2.empty() || seq2.size() > seq1.size()) //false of seq2 is empty
        //or greater in size
        return -1;
    int subseq = -1; // sunsequence index 1
    int index1 = 0;
    int index2 = 0;
    int size1 = seq1.size(); // size of sequence 1
    int size2 = seq2.size();
    int flag = 1;
    ItemType val1; //ItemType valu defined
    ItemType val2;
    //as sequence run to the size once seq2 match seq1 its size decrease
    while (index1 < size1 && size2 != 0) {
        seq1.get(index1, val1);
        seq2.get(index2, val2);
        
        //if value in seq is equal to seq2
        if (val1 == val2) {
            if(flag) { //record the subsequence
              subseq = index1;
              flag = 0;
            }
            //increass index1 and index 2
            index1++;
            index2++; //increase index 2
            size2--; // decrease the size of index 2
        } else {
            flag = 1; //onece value doens't equal setting flag for upcoming value
            subseq = -1;
            index1++;
            index2 = 0;
            size2 = seq2.size();
        }
    }
    return subseq; // returning index
}
    

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    if (seq1.empty() && seq2.empty())
        return;
    
    else if (seq1.size() == 0) { //if seq1 is empty then result is just seq2
        result = seq2;
    } else if (seq2.size() == 0) {
        result = seq1; // if seq2 is empty then result is just seq1
    } else {
        if (&seq1 ==&seq2) {
            //if three sequence points to the same spot return nothing
            if (&seq1 == &result && &seq2 ==&result)
                return;
            //otherwise if seq1 and seq2 aliasing, store either seq1 or seq2 in result
            result = seq1;
            return;
        } else {
            int i = 0, j = 0, p = 0;
            ItemType val1, val2;
        
            while (i < seq1.size() || j < seq2.size()) { // iterating through seq1
                //and seq2 one by one
                if (i < seq1.size()) {
                    seq1.get(i, val1); //get value from seq1
                    result.insert(p, val1); //insert value in result
                    i++; //increment get position
                    p++;// increment result position
                }
                //after sequence1, seq2 value inserting in the result
                if (j < seq2.size()) {//break if sequence reached at the end
                    seq2.get(j, val2);
                    result.insert(p, val2); // put the value in of seq2 after seq1
                    j++;
                    p++;
                }
            }
        }
    }
    
}













