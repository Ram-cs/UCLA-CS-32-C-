#include "newsequence.h"

#include <iostream>
#include <cstdlib>

Sequence::Sequence(int size) {
    while (size < 0) {
        std::cout << "size must be positive or 1: " << std::endl;
        exit(1);
    }
    
    m_size = 0; // no. of item in arry
    max_size = size; //size of arry
    m_item = new ItemType[max_size];
    
}

Sequence::Sequence(const Sequence& other) {
    m_size  = other.m_size;
    max_size = other.max_size;
    m_item = new ItemType[max_size];
    
    for (int i = 0; i < m_size; i++) {
        m_item[i] = other.m_item[i];
    }
}

Sequence& Sequence::operator=(const Sequence& r_sequence) {
        if (&r_sequence == this) // if assign itself do nothing
            return *this;
        
        delete [] m_item; // deleting existing pointer
        m_size  = r_sequence.m_size;
        max_size = r_sequence.max_size;
        m_item = new ItemType[max_size]; // create new pointer
    
    //assigning the value
        for (int i = 0; i < m_size; i++) {
            m_item[i] = r_sequence.m_item[i];
    }
    return *this;
}

//removing the objects that are dynamically created
Sequence::~Sequence() {
    delete [] m_item;
}

bool Sequence::empty() const { // arry(sequence) is empty if m_size is zero
    if (m_size <= 0)
        return true;
    return false;
}

int Sequence::size() const {
    return m_size;
}

bool Sequence::insert(int pos, const ItemType& value) {
    //if pos is between 0 and size
    if (pos >= 0 && pos <= size()) {
        
        if (size() >= max_size) //checking point for size and arry size
            return false;
        
        //value inserted at the end if pos == size()
        if (pos == size()) {
            m_item[size()] = value;
            m_size++;
        }
        
        else {
            //inserting item at position pos by moving item one up
            for (int i = size(); i > pos; i--) {
                m_item[i] = m_item[i - 1];
                if ((i -1) == pos) {
                    m_item[pos] = value;
                    m_size++;
                }
            }
        }
        return true;
    }
    return false;
}

int Sequence::insert(const ItemType& value) {
    int p = 0;  // Default position
    
    for (int i = 0; i < size(); i++) {
        if (value <= m_item[i]) {
            p = i;
            break;
        }
        else {
            p = size();
        }
    }
    
    if (size() >=p && p >= 0) {
        if (m_size < max_size) {
            
            for (int i = size(); i > p; i--)
                m_item[i] = m_item[i-1];
           
            m_item[p] = value;
            m_size++;
            return p;
        }
        else {
            return -1;
        }
    }
    
    return -1;
}

bool Sequence::erase(int pos) {
    if (pos >= 0 && pos < size()) {
        
        //find pos and remove item at position pos from sequence
        //and replace with the previous items
        for (int i = pos; i < size(); i++) {
            m_item[i] = m_item[i + 1];
            
        }
        //Since one item removed sized has to be decrease by 1
        m_size--;
        return true;
    }
    return false;
    
}

int Sequence::remove(const ItemType& value) {
    int itemRemoved = 0; //initial removed item
    
    //loop through the sequence
    for (int i = 0; i < size(); i++) {
        //check if the value is in sequence
        if (m_item[i] == value) {
            for (int j = i; j < size()-1; j++)
                m_item[j] = m_item[j+1];
            
            itemRemoved++;
            m_size--; // total size decreased by one once item removed
        }
        
    }
    return itemRemoved;// removed item
    
}

bool Sequence::get(int pos, ItemType& value) const {
    if (pos >= 0 && pos < size()) {
        value = m_item[pos]; // copy pos item into value
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos >= 0 && pos < size()) {
        m_item[pos] = value;
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const {
    int p = -1; // set p = -1 if no item found
    
    if (size() >= 1 && size() <= DEFAULT_MAX_ITEMS) {
        for (int i = 0; i < size(); i++) {
            if (m_item[i] == value) {
                p = i;
                return p;
            }
        }
    }
    
    return p;
}

void Sequence::swap(Sequence& other) {
    //pointer (address exchange)
    ItemType* temp_pointer;
    temp_pointer = m_item;
    m_item = other.m_item;
    other.m_item = temp_pointer;
    
    // max_size exchange
    int temp_size = max_size;
    max_size = other.max_size;
    other.max_size = temp_size;
    
    //m_size exchange
    temp_size = other.m_size;
    other.m_size = m_size;
    m_size = temp_size;
    
}
