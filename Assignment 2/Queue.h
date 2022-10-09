#pragma once
#include<iostream>

//template class Queue
template <class T>
class Queue {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* front;
	Node* rear;
	int size;
public:
	//Default Constructor
	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}
	//Destructor
	~Queue() {
		Node* temp = front;
		while (temp != NULL) {
			front = front->next;
			delete temp;
			temp = front;
		}
	}
	//push function takes in a T object and adds it to the queue
	void push(T data) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = NULL;
		if (front == NULL) {
			front = temp;
			rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
		size++;
	}
	//pop function removes the first element in the queue and returns it
	T pop() {
		Node* temp = front;
		T data = temp->data;
		front = front->next;
		delete temp;
		size--;
		return data;
	}
	//front function
	T Front() {
		return front->data;
	}
	//isEmpty function returns true if the queue is empty
	bool isEmpty() {
		if (size == 0) {
			return true;
		}
		return false;
	}
	//getSize function returns the size of the queue
	int getSize() {
		return size;
	}
	//printQueue function prints the queue
	void printQueue() {
		Node* temp = front;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};