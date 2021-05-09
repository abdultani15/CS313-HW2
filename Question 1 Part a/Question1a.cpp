//Header File: linkedStack.h 

#ifndef H_StackType 
#define H_StackType

#include <iostream>
#include <cassert> 

#include "stackADT.h"

using namespace std;

//Define the node
template <class Type>   //This declares a template for the node class everytime it is used
struct nodeType
{
    //Information is stored in info 
    Type info;
    //This pointer is used to point to the next node
    nodeType<Type>* link;
};

template <class Type>  //Declaring a template for the linked linked stack
class linkedStackType : public stackADT<Type>
{
public:
    //Here we are using assignment operator overload
    const linkedStackType<Type>& operator=
        (const linkedStackType<Type>&);

    //This function returns true if stack is empty
    bool isEmptyStack() const;

    //This function returns true if stack is full
    bool isFullStack() const;

    //This function initializes the stack to an empty stack and top is nullptr
    void initializeStack();

    //Function that pushes or adds a newItem to the top of the stack
    //The stack needs to exist and not be full
    void push(const Type& newItem);

    //Function returns the top element of the stack
    //The stack needs to exist and not be full
    Type top() const;

    //Function the pops or removes top element from the stack
    //The stack needs to exist and not be full
    void pop();

    //Default constructor
    //Makes the top of the stack nullptr
    linkedStackType();

    //Copy Constructor
    linkedStackType(const linkedStackType<Type>& otherStack);

    //Destructor
    //This removes all the elements from the stack
    ~linkedStackType();

private:
    nodeType<Type>* stackTop; //pointer to the stack
    //Function used to copy otherstack 
    void copyStack(const linkedStackType<Type>& otherStack);

};


//Default constructor
template <class Type>
linkedStackType<Type>::linkedStackType()
{
    //Creates pointer to nullptr
    stackTop = nullptr;
}

template <class Type>
//Function isEmptyStack
//Scope resolution operator to inherit IsEmptyStack member function
bool linkedStackType<Type>::isEmptyStack() const
{
    //If stackTop is nullptr then stack is empty otherwise it is not empty
    return(stackTop == nullptr);
}

template <class Type>
//Function isFullStack
//Scope resolution operator to inherit IsFullStack member function
bool linkedStackType<Type>::isFullStack() const
{
    return false; //Stack is not full and return false  
}

template <class Type>
//Scope resolution operator to inherit initializeStack member function
void linkedStackType<Type>::initializeStack()
{
    //pointer to delete the node
    nodeType<Type>* temp;
    //while function 
    while (stackTop != nullptr) //While stackTop is not nullptr meaning Stack is not empty
    {
        temp = stackTop; //Set temp to point to current node

        stackTop = stackTop->link; //Move stackTop to the next node in the list

        delete temp; //Delete temp to prevent memory leak
    }
}//end of initializeStack function

template <class Type>
//push function
//Scope resolution operator to inherit push member function
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type>* newNode; //pointer to create a new node

    newNode = new nodeType<Type>; //create a node

    newNode->info = newElement; //store newElement in newNode->info
    newNode->link = stackTop; //places newNode before stackTop  
    stackTop = newNode; //sets stackTop to newNode to make it the new top

} //end push


template <class Type>
//top function
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr); //if stack is empty, exit program

    return stackTop->info; //return the data in stackTop->info
}//end top

template <class Type>
//pop function
void linkedStackType<Type>::pop()
{
    nodeType<Type>* temp; // temp pointer that will be used to deallocate memory

    if (stackTop != nullptr) //if statement to check if stack is not empty
    {
        temp = stackTop; // set temp equal to stackTop

        stackTop = stackTop->link; //moves the stacktop to the next node in the list

        delete temp; //deletes the temp node which would delete old top node
    }
    else // if the stack is empty, print message
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type>
void linkedStackType<Type>::copyStack
(const linkedStackType<Type>& otherStack)
{
    nodeType<Type>* newNode, * current, * last; //creates multiple pointers for the function

    if (stackTop != nullptr) //if stack is not empty
        initializeStack();   //initialize it so it becomes empty

    if (otherStack.stackTop == nullptr) //if the otherStack is empty
        stackTop = nullptr;             //stackTop points to nullptr
    else //else copy the stack
    {
        current = otherStack.stackTop; //set current to top of otherStack
                                       //this copies the stackTop element of the stack    

        stackTop = new nodeType<Type>; //creates new node

        stackTop->info = current->info; //copy the info stored in otherStack into the newTop 
        stackTop->link = nullptr;       //sets stackTop link to nullptr

        last = stackTop; //sets last to point to the node
        current = current->link; //moves current node to the next node


        while (current != nullptr) //while function to copy the rest of the stack
                                   //while current does not point to nullptr
        {
            newNode = new nodeType<Type>; //Create a new node

            newNode->info = current->info; //copies the info in current to newNode
            newNode->link = nullptr; //sets the newNode link to nullptr
            last->link = newNode; //sets last link to newNode 
            last = newNode; //sets last node to newNode
            current = current->link; //moves current to the next node in the list
        }
    }
} //end of copyStack function

//copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(
    const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;  //points stackTop to nullptr to create a new stack
    copyStack(otherStack); //Makes a copy of otherStack
}//end of copy contructor

//destructor
template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack(); // uses the initializeStack function to empty the list
}//end of destructor

template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator= //This line is overloading the assignment operator
(const linkedStackType<Type>& otherStack)
{
    if (this != &otherStack) //if this does not equal &otherstack so it does not copy itself
        copyStack(otherStack);//copies otherstack

    return *this;
}//end of operator function

#endif