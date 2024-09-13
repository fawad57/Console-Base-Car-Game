/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/


#pragma once
#include <iostream>
#include<Windows.h>
using namespace std;
class Node {
public:
	char ch;
	Node* next;
	Node() {
		next = NULL;
	}
};
class linked_list {
public:
	Node* head;
	linked_list() {
		head = NULL;
	}

	//This linked list store the mystery boxes, trophies and a keys when player collected them during playing game.

	void createNode(char c) {
		Node* temp = new Node;
		temp->ch = c;
		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}


	//This delete the keys from the list when the player use it.

	void delete_Node(char ch) {
		Node* temp = head;
		Node* prev = NULL;
		while (temp != NULL && temp->ch != ch)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp) {
			if (prev) {
				prev->next = temp->next;
				delete temp;
			}
			else {
				head = temp->next;
				delete temp;
			}
		}
	}
};