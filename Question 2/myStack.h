#pragma once
#include<iostream>
using namespace std;

template <class T>
class arrStack {
private:
	int maxStackSize; //maxStackSize Variable 
	int stackTop;     //stackTop variable 
	T* arr;           //arr to hold the stack

public:
	void initializeStack(int size) { //function to initialize stack
		arr = new T[size];  //makes an array of size
		maxStackSize = size; //make maxstackSize equal to Size
		stackTop = 0;        //Sets stackTop to 0
	}
	bool isStackEmpty() {      //Boolean function to check if function is empty
		return stackTop == 0; //it returns true if it is empty
	}
	bool isStackFull() { //Boolean function to check if function is full
		return stackTop == maxStackSize; //it returns true it if is full
	}
	void push(T data) {  //Function to add or push data into stack
		if (!isStackFull()) {  //if statement to check if stack is not full
			arr[stackTop] = data; //top of stack is set to data
			stackTop++; //goes to the next element in the stack
		}
		else { //else if stack is full
			cout << "Stack is Full" << endl; //prints msg
		}
	}
	void pop() { //function to remove or pop element from stack
		if (!isStackEmpty()) { //if statement to check if stack is not empty
			stackTop--; //stackTop decremented
		}
		else { //else if stack is empty
			cout << "Empty Stack" << endl; //prints msg
		}
	}

	~arrStack() { //Destructor
		delete[] arr; //deallocates memory
	}

	void printStack() { //function to print stack
		cout << "Stack: " << endl; //print msg
		while (!isStackEmpty()) { //while loop when stack is not empty
			cout << arr[--stackTop] << endl; //prints arr spot and decremented 
		}
	}

	T getTop() { //function to get top element
		return arr[stackTop-1]; //returns top element
	}

	void changeDatainLocation(int arrLocation, T data) { //function to change data in a specific place in array
		if (arrLocation > stackTop) { //if location is bigger than stackTop, then it is invalid
			cout << "Invalid Location of array." << endl; //prints msg
		}
		int iterator = stackTop; //iterator starts at top of stack
		if (iterator = !arrLocation) { //if iterator is not specified location
			iterator--;                //it decrements until it is
		}
		else { //else if it is a specified location
			arr[iterator + 1] = data; //then the data in the location is changed to specified data
		}
	}



};
