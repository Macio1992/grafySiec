#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int x){
	size = x;
	stack = new int[size];
	for(int i = 0; i < size; i++) stack[i] = -1;
	top = -1;
}

Stack::~Stack(){
	delete [] stack;
}

void Stack::push(int x){
	
	if(top > size){
		cout<<"Stack is full"<<endl;
		return;
	}
	
	stack[++top] = x;
}

void Stack::pop(){
	if(top < 0){
		cout<<"The stack is empty"<<endl;
		return;
	}
	stack[top] = 0;
	top--;
	//cout<<"The deleted element is: "<<stack[top--]<<endl;
}

void Stack::display(){
	
	if(top < 0){
		cout<<"The stack is empty"<<endl;
		return;
	}
	
	for(int i = top; i >= 0; i--)
		cout<<stack[i]<<" ";
	cout<<endl;
	
}

int Stack::getStackTop(){
	return stack[top];
}

bool Stack::checkIfStackEmpty(){
	int l = 0;
	for(int i = 0; i < size; i++)
		if(stack[i] == -1) l++;
		
	if(l == size-1) return true;
	else return false;
}

int Stack::getActualValue(){
	return stack[top];
}
