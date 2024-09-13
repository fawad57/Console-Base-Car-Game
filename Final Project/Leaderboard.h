/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/

#pragma once
#include <iostream>
#include<Windows.h>
using namespace std;
class TreeNode {
public:
	string name;
	int score;
	int coins;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		left = NULL;
		right = NULL;

	}
};

class Tree {
public:
	TreeNode* root;
	int player;
	Tree() {
		player = 1;
		root = NULL;
	}

	//Storing record in a BST from the file.


	void Insert(string name, int score, int coins) {
		TreeNode* newnode = new TreeNode();
		TreeNode* temp;
		newnode->name = name;
		newnode->coins = coins;
		newnode->score = score;

		if (root == NULL) {
			root = newnode;
		}
		else {
			temp = root;
			while (temp)
			{
				if (score < temp->score) {
					if (temp->left) {
						temp = temp->left;
					}
					else {
						temp->left = newnode;
						break;
					}
				}
				else if (score > temp->score) {
					if (temp->right) {
						temp = temp->right;
					}
					else {
						temp->right = newnode;
						break;
					}
				}
				else if (score == temp->score) {
					if (temp->right)
					{
						temp = temp->right;
					}
					else {
						temp->right = newnode;
						break;
					}
				}
			}
		}
	}

	//Display the tree from greater to lower.


	void print(TreeNode* temp) {
		if (temp != NULL) {
			print(temp->right);
			cout << "\t\t\t" << player << ". " << temp->name << "\t\t\t" << temp->score << "\t\t\t" << temp->coins << endl;
			player++;
			print(temp->left);
		}
	}
};