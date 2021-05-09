#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	Node<T>* next;
	T data;
};
template<class T>
class LLStack{
private: Node<T>* top = nullptr;

public:
	bool isStackEmpty() {
		return top == nullptr;
}
void push(int data) {
	Node<T>* newNode;			//Creates a new node
	newNode = new Node<T>();
	newNode->data = data;	//Set the value of the new node to data
	newNode->next = top;  //Connect new node to the head node
	top = newNode;		//The new node now becomes the head
}
void pop() {
	if (isStackEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		Node<T>* newNode;			//Creates a new node
		newNode = top;
		top = top->next;
		delete(newNode);
	}
}
void LL_print() {
	while (top != NULL) {         //Do the while loop until node is NULL
		cout << top->data << " "; //Print out the current value of the node
		top = top->next;	  //Set current to the next spot of the node
	}
}


};
