#include<iostream>
#include<time.h>
#include"linkListStack.h"
#include"myStack.h"
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using namespace std;

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}

using namespace std;



void arrStackTest() {         //Function that does 5 million operations
	srand(time(nullptr));     //These operations are push and pop
	int size = 5000000;
	arrStack<int> arrStack;
	for (int i = 0; i < size; i++)
	{
		arrStack.push(rand() % size + 1);
		arrStack.pop();
	}
}
void LLStackTest() {        //Function that does 5 million operations
	srand(time(nullptr));   //These operations are push and pop
	int size = 5000000;
	LLStack<int> llStack;
	for (int i = 0; i < size; i++)
	{
		llStack.push(rand() % size + 1);
		llStack.pop();
	}
	
}

int main() {
	arrStack<int> arrStack;
	LLStack<int> llStack;
	auto arrStackTime = TimeFunc([&]() {arrStackTest();; }); //Used to time test
	auto LLStackTime = TimeFunc([&]() {LLStackTest();; });   //Used to time test
	
	cout << "Time to complete Array Stack Test " << arrStackTime << " milliseconds" << endl;
	cout << "Time to complete Linked List Stack Test " << LLStackTime << " milliseconds" << endl;
}