#include<iostream>
#include"myStack.h"
#include<string>
using namespace std;

double prefixCalculator(string x) {
	arrStack<double> myStack; //initialize array stack
	int size = 100; //Sets size to 100
	myStack.initializeStack(size); //Function to initialize stack
	double num; //num variable
	for (int i = x.length()-1; i >= 0; i--) //starts from the top of the stack and decrements
	{
		if (isdigit(x[i])) { //checks if char is a number
			num = x[i] - '0'; //changes the char to the number
			myStack.push(num); //pushes the num to the stack

		}
		else { //else if it is not a number
			double op1 = myStack.getTop(); //gets top from stack and sets it to op1
			myStack.pop(); //pops the number out of the number
			double op2 = myStack.getTop();//gets top from stack and sets it to op2
			myStack.pop(); //pops the number out of the number

			switch (x[i]) { //switch case statement
			case '+': //If it is addition
				myStack.push(op1 + op2); //pushes the value of op1 + op2 to the top of the stack
				break; //break to exit switch case loop
			case '-': //if it is subtraction
				myStack.push(op1 - op2);//pushes the value of op1 - op2 to the top of the stack
				break; //break to exit switch case loop
			case '*'://if it is multiplication
				myStack.push(op1 * op2);//pushes the value of op1*op2 to the top of the stack
				break;//break to exit switch case loop
			case '/'://if it is division
				if (op2 != 0) {//checks to make sure op2 does not equal 0 
					myStack.push(op1 / op2);//pushes op1 / op2 to the top of the stack
				}
				else {//else if op2 is 0
					cout << "Division by 0 error" << endl;//prints msg
				
				}
				break; //break to exit switch case loop
			}
		}
	}
		return myStack.getTop(); //returns the top of the stack
	}


int main() {

	string expression = "+5*7+25";  //sets expression
	cout << "Expression is: "<<expression << endl;
	cout << "Answer: "<<prefixCalculator(expression) << endl; // prints the correct result of 54
}
