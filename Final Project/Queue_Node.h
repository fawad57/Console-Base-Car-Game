/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/

#pragma once
#include <iostream>
using namespace std;
class Queue {
public:

	char ch;
	int x_axis;
	int y_axis;
	Queue* next;

	Queue() {
		next = NULL;
	}
};



class QueueNode {
	Queue* front;
	Queue* rear;
public:


	//this function store the obstacles of the gird.

	QueueNode() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int i, int j) {
		Queue* newnode = new Queue;
		newnode->ch = '#';
		newnode->x_axis = i;
		newnode->y_axis = j;
		if (front == NULL) {
			front = newnode;
			rear = newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}
	}

	//this function placed the stroe obstacles in the gird.

	Queue* dequeue() {
		if (front == NULL) {
			return NULL;
		}
		else {
			Queue* temp = front;
			front = front->next;
			if (front == NULL) {
				rear = NULL;
			}
			return temp;
		}
	}
};



