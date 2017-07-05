
#include <iostream>
using namespace std;

bool somePredicate(double x);
int countFalse(const double a[], int n);
int firstFalse(const double a[], int n);
int indexOfMin(const double a[], int n);
bool includes(const double a1[], int n1, const double a2[], int n2);

bool somePredicate(double x) {
    return x < 0;
}

// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const double a[], int n)
{
    if (n == 0) //for the empty arry
        return false;
    
    if (n == 1) //when arry has one element
        return somePredicate(a[0]);
    
    bool first = somePredicate(a[0]); //first element of the arry
    bool rest = allTrue(a + 1, n - 1); //rest element of the arry
    
    if (first == false || !rest == true) //if either false
        return false;
    return true;
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const double a[], int n) {
    int falseEle = 0;
    if (n == 0) //if arry is empty
        return 0;
    
    if (somePredicate(a[0]) == false) //if false
        falseEle = 1;
    
    return countFalse(a + 1, n -1) + falseEle; //other wise

}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const double a[], int n) {
    if(n <= 0)      //true if 0 or less so -1
        return -1;
    if (!somePredicate(a[0]))   //first element at 0 index
        return 0;
    if (firstFalse(a+1, n-1) == -1) //when we don't have any false in arry
        return -1;
    return 1 + firstFalse(a + 1, n-1);  //Otherwise find first false index and add 1
}

// Return the subscript of the smallest double in the array (i.e.,
// the one whose value is <= the value of all elements).  If more
// than one element has the same smallest value, return the smallest
// subscript of such an element.  If the array has no elements to
// examine, return -1.
int indexOfMin(const double a[], int n) {
    if (n <= 0) //when arry is invalid
        return -1;
    
    if (n == 1) //when arry has just one element
        return 0;
    
    int minIndex = 1 + indexOfMin(a + 1, n -1); //get the idex of smallest element of arry beside first element
    int firstEle = a[0]; //first Element of arry
    
    if (a[minIndex] >= firstEle) //compare the first element of arry with the smallest element of arry
        return 0; //found first element is smallest element of arry, index is@ 0
    return minIndex; //otherwise index of smallest element of arry
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then the function should return true if a2 is
//    50 20 30
// or
//    50 40 40
// and it should return false if a2 is
//    50 30 20
// or
//    10 20 20
bool includes(const double a1[], int n1, const double a2[], int n2) {
    if(n1 < 0) //if n1 is Negative
        return false;
    
    if(n1 >= 0 && n2 == 0) //though n2 is Zero
        return true;
    
    if(a1[0] == a2[0]) //first element of each arry must be equal
        return includes(a1 + 1, n1 - 1, a2 + 1, n2 - 1); //for the rest of the arry comparison
    else
        return includes(a1 + 1, n1 - 1, a2, n2); //when first arry doesn't equal, decrease index by one each time a1 and make first element
}














































