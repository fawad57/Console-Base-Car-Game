/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/

#pragma once
#include <iostream>
#include<Windows.h>
#include"Gird_list.h"
#include<fstream>
#include<string>
using namespace std;
class Resume {
	Grid_Node** arr;
	string name;
	int size;
	int score;
	int coins;
	int level;
	int x_axis;
	int y_axis;
	int steps;
public:

	// this function collect the data from the resume file to continue the previous game.


	Resume() {

		ifstream in;
		in.open("Resume.txt");
		string str, s;
		int counter = 0;
		int index;
		int x = 0;
		int y = 0;
		while (getline(in, str))
		{
			if (counter == 0) {
				index = str.find(':');
				s = str.substr(index + 1);
				name = s;
				counter++;
				//	cout << "name:" << name << endl;
			}
			else if (counter == 1) {
				index = str.find(':');
				s = str.substr(index + 1);
				size = stoi(s);
				counter++;
				arr = new Grid_Node * [size];
				for (int i = 0; i < size; i++)
				{
					arr[i] = new Grid_Node[size];
					for (int j = 0; j < size; j++)
					{
						arr[i][j] = Grid_Node();
					}
				}
				//	cout << "size:" << size << endl;
			}
			else if (counter == 2) {
				index = str.find(':');
				s = str.substr(index + 1);
				score = stoi(s);
				counter++;
				//	cout << "score:" << score << endl;
			}
			else if (counter == 3) {
				index = str.find(':');
				s = str.substr(index + 1);
				coins = stoi(s);
				counter++;
				//	cout << "coins:" << coins << endl;
			}
			else if (counter == 4) {
				index = str.find(':');
				s = str.substr(index + 1);
				level = stoi(s);
				counter++;
				//	cout << "level:" << level << endl;
			}
			else if (counter == 5) {
				index = str.find(':');
				s = str.substr(index + 1);
				x_axis = stoi(s);
				counter++;
				//	cout << "x-axis:" << x_axis << endl;
			}
			else if (counter == 6) {
				index = str.find(':');
				s = str.substr(index + 1);
				//	cout << "s:" << s<<endl;
				y_axis = stoi(s);
				counter++;
				//	cout << "y-axis:" << y_axis << endl;
			}
			else if (counter == 7) {
				index = str.find(':');
				s = str.substr(index + 1);
				//	cout << "s:" << s<<endl;
				steps = stoi(s);
				steps++;
				counter++;
				//	cout << "y-axis:" << y_axis << endl;
			}
			else {
				//cout << str[0] << endl;
				arr[x][y].ch = str[0];
				y++;
				if (y >= size) {
					y = 0;
					x++;
				}
			}
		}
		arr[x_axis][y_axis].ch = 'C';

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++) {
				arr[i][j].right = &arr[i][j + 1];
				arr[i][j + 1].left = &arr[i][j];
			}
			if (i > 0) {
				for (int j = 0; j < size; j++)
				{
					arr[i][j].up = &arr[i - 1][j];
					arr[i - 1][j].down = &arr[i][j];
				}
			}
		}

	}

	void print() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) {
				cout << arr[i][j].ch << " ";
			}
			cout << endl;
		}
	}

	Grid_Node** Resume_grid() {
		return arr;
	}

	int getSize() {
		return size;
	}

	int getScore() {
		return score;
	}

	int getCoins() {
		return coins;
	}

	int getLevel() {
		return level;
	}
	int getX_axis() {
		return x_axis;
	}
	int getY_axis() {
		return y_axis;
	}
	int getSteps() {
		return steps;
	}


};