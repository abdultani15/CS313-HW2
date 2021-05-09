#include<iostream>
#include "arrayStack.h"
#include<stack>
using namespace std;
int main() {
	int size = 100; //sets size equal to 100
	arrStack<double> stack; 
	stack.initializeStack(size); //initials stack to hold 100 elements
	stack.push(17); //push functions
	stack.push(52);
	stack.push(4);
	stack.push(78);
	stack.push(33);
	stack.pop();
	stack.changeDatainLocation(1,10); 
	stack.printStack();

}