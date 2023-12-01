/* shallow vs deep copy
    1. Shallow copy : when a new pointer just copies the already existing pointer 
        int *p1 = new int (5) ; this allocates the memory on the heap
        int *p2 = p1; just copies the p1 pointer --> very dangerous as both pointers points to the same address. if you delete the p1's memory, p2 will have no idea and leads to dangling pointer
    2. Deep copy : when a new pointer allocates its own memory, but copies the value from already existing poiter (not the address)
        int *p1 = new int (5) ; 
        int *p2 = new int (*p1); deep copy
    3. This happens evertime when a "copy of the bject is created". Compiler implements a default copy constructor and it does a shallow copy. 
       Therefore we need to implement a custom copy constructor.
*/

/* copy of the object is created when,
    1. When the object is passed to a function as an argument
    2. When a function returns an object
    3. When manually a copy is created
    4. when we assign a object to another (copy assignment)
*/

/* Rule of 3 : All should be defined if a user implements any one of them
    1. Destructor
    2. copy constructor
    3. copy assigment operator
*/

#include "copy_constructor.hpp"
#include <iostream>

using std::cout;
using std::endl;

Integer::Integer(){
    m_pInt = new int(0); //create a integer on the heap
}

Integer::Integer(int value){
    m_pInt = new int(value); //create a integer on the heap
}

// custom copy constructor, performs a deep copy

Integer::Integer(const Integer &obj){
    m_pInt = new int(*obj.m_pInt); 
}

void Integer::setValue(int &value){
    *m_pInt = value;
}

int Integer::getValue() const{
    return *m_pInt;
}

Integer::~Integer(){
    delete m_pInt;
}



// 1. When the object is passed to a function as an argument
void Print(Integer i){

}

// 2. When a function returns an object
Integer Add(int x, int y){
    return Integer(x+y);
}

int main(){
    Integer i(5);
    cout << i.getValue() << endl;
    // 3. When manually a copy is created
    Integer i2(i);
    // 4. copy assignment
    Integer i3 = i; 
    return 0;
}
