/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/

#pragma once
class Grid_Node {
public:
	char ch;
	Grid_Node* up;
	Grid_Node* down;
	Grid_Node* right;
	Grid_Node* left;
	int distance;
	bool visited;

	Grid_Node() {
		up = NULL;
		down = NULL;
		right = NULL;
		left = NULL;
	}

	void updateDistances(Grid_Node* current, int weight) {
		if (current != NULL) {
			if (!current->visited && weight + distance < current->distance) {
				current->distance = weight + distance;
			}
		}
	}
};