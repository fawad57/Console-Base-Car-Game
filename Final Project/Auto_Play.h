/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/


#pragma once
#include <iostream>
#include<Windows.h>
#include"Gird_list.h"
#include<queue>
#include"Game_Play.h"
using namespace std;
class Auto_play{
	Level_One one;
	Level_Two two;
	Level_Three three;
	Grid_Node** arr1;
public:
	void dijkstraShortestPath(int x) {
		int rows, cols, INF;
		if(x == 1) {
			Grid_Node** arr1 = one.level_One_Grid();
			rows = 16;
			cols = 16;
			INF = INT_MAX;
		}
		else if (x == 2) {
			Grid_Node** arr1 = two.level_Two_Grid();
			rows = 32;
			cols = 32;
			INF = INT_MAX;
		}
		else {
			Grid_Node** arr1 = three.level_Three_Grid();
			rows = 50;
			cols = 50;
			INF = INT_MAX;
		}

		// Define a priority queue for Dijkstra's algorithm

		priority_queue<std::pair<int, Grid_Node*>, vector<std::pair<int, Grid_Node*>>, greater<std::pair<int, Grid_Node*>>> pq;

		// Set initial distances to infinity for all nodes except the starting point


		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				arr1[i][j].distance = INF;
				arr1[i][j].visited = false;
			}
		}

		int start_x = -1, start_y = -1;
		int end_x = -1, end_y = -1;

		// Find the starting and ending points


		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (arr1[i][j].ch == 'S') {
					start_x = i;
					start_y = j;
				}
				else if (arr1[i][j].ch == 'E') {
					end_x = i;
					end_y = j;
				}
			}
		}

		// Enqueue the starting node with distance 0

		pq.push({ 0, &arr1[start_x][start_y] });
		arr1[start_x][start_y].distance = 0;

		// Dijkstra's algorithm

		while (!pq.empty()) {
			Grid_Node* current = pq.top().second;
			pq.pop();

			current->visited = true;

			// Check adjacent nodes

			if (current->right != nullptr)
				current->updateDistances(current->right, 1);
			if (current->left != nullptr)
				current->updateDistances(current->left, 1);
			if (current->up != nullptr)
				current->updateDistances(current->up, 1);
			if (current->down != nullptr)
				current->updateDistances(current->down, 1);

			// Push adjacent nodes into the priority queue


			if (current->right != nullptr && !current->right->visited)
				pq.push({ current->right->distance, current->right });
			if (current->left != nullptr && !current->left->visited)
				pq.push({ current->left->distance, current->left });
			if (current->up != nullptr && !current->up->visited)
				pq.push({ current->up->distance, current->up });
			if (current->down != nullptr && !current->down->visited)
				pq.push({ current->down->distance, current->down });
		}

		// Backtrack to mark the shortest path with '*'


		Grid_Node* current = &arr1[end_x][end_y];
		while (current->ch != 'S') {
			if (current->up != nullptr && current->up->distance == current->distance - 1) {
				current = current->up;
				current->ch = '*';
			}
			else if (current->down != nullptr && current->down->distance == current->distance - 1) {
				current = current->down;
				current->ch = '*';
			}
			else if (current->left != nullptr && current->left->distance == current->distance - 1) {
				current = current->left;
				current->ch = '*';
			}
			else if (current->right != nullptr && current->right->distance == current->distance - 1) {
				current = current->right;
				current->ch = '*';
			}
		}
	}
};
