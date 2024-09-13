/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/

#pragma once
#include <iostream>
#include"Queue_Node.h"
#include"Level_One.h"
#include"Level_Two.h"
#include"Level_Three.h"
#include"Linked_List.h"
#include<Windows.h>
#include<conio.h>
#include"Gird_list.h"
#include"Resume.h"
using namespace std;


class Game_Play {

	Level_One one;
	Level_Two two;
	Level_Three three;
	linked_list list;
	Grid_Node** arr;
	int score;
	int coins;
	int steps;

public:

	Game_Play() {
		score = 0;
		coins = 0;
		steps = 0;
	}

	bool game_control(int level,string name) {
		int size = 0;
		int x = 1;
		int y = 1;
		bool check = false;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		//these condition check the level and a resume.

		if (level == 1) {
			size = 16;
			arr = one.level_One_Grid();
			steps += 40;
		}
		else if (level == 2) {
			size = 32;
			arr = two.level_Two_Grid();
			steps += 40;
		}
		else if (level == 3) {
			size = 50;
			arr = three.level_Three_Grid();
			steps += 80;
		}
		else if (level == 0) {
			Resume r;
			size = r.getSize();
			level = r.getLevel();
			arr = r.Resume_grid();
			score = r.getScore();
			coins = r.getCoins();
			x = r.getX_axis();
			y = r.getY_axis();
			steps = r.getSteps();
		}

		//here the score coins and level will be displayed.

		SetConsoleTextAttribute(h, 7);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Score: " << score << "\t\t\t" << "Coins: " << coins << "\t\t\t" << "Remaining steps: " << steps << "\t\t\tLevel: " << level << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;

		//these loops display the gird.

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) {
				if (arr[i][j].ch == '|' || arr[i][j].ch == '-' || arr[i][j].ch == '_' || arr[i][j].ch == '#') {
					SetConsoleTextAttribute(h, 4);
					cout << arr[i][j].ch << " ";
				}
				else if (arr[i][j].ch == 'K' || arr[i][j].ch == '$') {
					SetConsoleTextAttribute(h, 6);
					cout << arr[i][j].ch << " ";
				}
				else if (arr[i][j].ch == '+') {
					SetConsoleTextAttribute(h, 2);
					cout << arr[i][j].ch << " ";
				}
				else if (arr[i][j].ch == 'T' || arr[i][j].ch == 'B') {
					SetConsoleTextAttribute(h, 9);
					cout << arr[i][j].ch << " ";
				}
				else if (arr[i][j].ch == 'f') {
					SetConsoleTextAttribute(h, 13);
					cout << arr[i][j].ch << " ";
				}
				else {
					SetConsoleTextAttribute(h, 7);
					cout << arr[i][j].ch << " ";
				}
			}
			cout << endl;
		}
		arr[x][y].ch = '.';


		//this while control the game. maens When the score or a coin boost and fuel as well and check that when the game will terminated. 


		while (score >= 0 && steps > 0)
		{
			SetConsoleTextAttribute(h, 7);
			char move=_getch();
		//	cin >> move;
			Sleep(1);
			system("CLS");


			//the below if control when the player stop the game in between so this condition will store his record in file. 

			if (move == 27) {

				Node* temp = list.head;
				while (temp != NULL)
				{
					if (temp->ch == 'T') {
						int a = rand() % 25;
						score += a;
					}
					else if (temp->ch == 'B') {
						int a = rand() % 50;
						coins += a;
					}
					temp = temp->next;
				}


				ofstream out;
				out.open("Resume.txt");
				out << "Name:" << name << endl;
				out << "Size:" << size << endl;
				out << "Score:" << score << endl;
				out << "coins:" << coins << endl;
				out << "Level:" << level << endl;
				out << "x_axis:" << x << endl;
				out << "y_axis:" << y << endl;
				out << "steps:" << steps << endl;
				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++) {
						out << arr[i][j].ch << endl;
					}

				}
				return false;
			}




			//this else if control the right movements.


			else if (move == 'D' || move == 'd') { // 77 

				arr[x][y].ch = '.';
				steps--;

				if (arr[x][y + 1].ch == '.') {
					arr[x][y + 1].ch = 'C';
					//arr1[x][y + 1].ch = 'C';
					y++;
				}

				//this if boost the coins by 1.

				else if (arr[x][y + 1].ch == '$') {
					arr[x][y + 1].ch = 'C';
					//arr1[x][y + 1].ch = 'C';
					y++;
					coins++;
				}
				//this condition check if a car hit the obstacles this condition deduct score by 5.

				else if (arr[x][y + 1].ch == '#') {
					Beep(500, 1000);
					arr[x][y + 1].ch = 'C';
					//arr1[x][y + 1].ch = 'C';
					y++;
					score -= 5;
				}

				//this condition boost the score by 1.

				else if (arr[x][y + 1].ch == '+') {
					arr[x][y + 1].ch = 'C';
					//arr1[x][y + 1].ch = 'C';
					y++;
					score++;
				}


				//this condition refuel the tank.


				else if (arr[x][y + 1].ch == 'f') {
					arr[x][y + 1].ch = 'C';
					//arr1[x][y + 1].ch = 'C';
					y++;
					steps += 20;
				}


				//this condition check that the player reaches the the end point or not.


				else if (arr[x][y + 1].ch == 'E') {
					check = true;
					break;
				}

				//this condition store the mystery box, trophies and keys in a linked list.

				else if (arr[x][y + 1].ch == 'B' || arr[x][y + 1].ch == 'T' || arr[x][y + 1].ch == 'K') {
					list.createNode(arr[x][y + 1].ch);
					arr[x][y + 1].ch = 'C';
					//arr1[x][y + 1].ch = 'C';
					y++;
				}

				//else check that the player hit the wall or not it he hit score will be minus by 1.

				else {
					arr[x][y + 1].ch = 'X';
					Beep(500, 1000);
					//arr1[x][y + 1].ch = 'X';
					score--;

					arr[x][y].ch = 'C';
					//arr1[x][y].ch = 'C';
				}

				//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.                                                 

				if (arr[x - 1][y - 1].ch == '#') {
					score += 5;
					arr[x - 1][y - 1].ch = '.';
				}
				if (arr[x + 1][y - 1].ch == '#') {
					score += 5;
					arr[x + 1][y - 1].ch = '.';
				}

			}



			//this else if control the down movements.

			else if (move == 's' || move == 'S') { // 80

				arr[x][y].ch = '.';
				steps--;

				if (arr[x + 1][y].ch == '.') {
					arr[x + 1][y].ch = 'C';
					//arr1[x + 1][y].ch = 'C';
					x++;
				}

				//this if boost the coins by 1.


				else if (arr[x + 1][y].ch == '$') {
					arr[x + 1][y].ch = 'C';
					//arr1[x + 1][y].ch = 'C';
					x++;
					coins++;
				}

				//this condition check if a car hit the obstacles this condition deduct score by 5.

				else if (arr[x + 1][y].ch == '#') {
					Beep(500, 1000);
					arr[x + 1][y].ch = 'C';
					//arr1[x + 1][y].ch = 'C';
					x++;
					score -= 5;
				}

				//this condition boost the score by 1.

				else if (arr[x + 1][y].ch == '+') {
					arr[x + 1][y].ch = 'C';
					//arr1[x + 1][y].ch = 'C';
					x++;
					score++;
				}

				//this condition refuel the tank.


				else if (arr[x + 1][y].ch == 'f') {
					arr[x + 1][y].ch = 'C';
					//arr1[x + 1][y].ch = 'C';
					x++;
					steps += 20;
				}

				//this condition check that the player reaches the the end point or not.


				else if (arr[x + 1][y].ch == 'E') {
					check = true;
					break;
				}

				//this condition store the mystery box, trophies and keys in a linked list.


				else if (arr[x + 1][y].ch == 'B' || arr[x + 1][y].ch == 'T' || arr[x + 1][y].ch == 'K') {
					list.createNode(arr[x + 1][y].ch);
					arr[x + 1][y].ch = 'C';
					arr[x + 1][y].ch = 'C';
					x++;
				}

				//else check that the player hit the wall or not it he hit score will be minus by 1.

				else {
					arr[x + 1][y].ch = 'X';
					Beep(500, 1000);
					//arr1[x + 1][y].ch = 'X';
					score--;

					arr[x][y].ch = 'C';
					//arr1[x][y].ch = 'C';
				}

				//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.

				if (arr[x - 1][y - 1].ch == '#') {
					score += 5;
					arr[x - 1][y - 1].ch = '.';
				}
				if (arr[x - 1][y + 1].ch == '#') {
					score += 5;
					arr[x - 1][y + 1].ch = '.';
				}

			}



			//this else if control the up movements.

			else if (move == 'w' || move == 'W') { // 72

				arr[x][y].ch = '.';
				steps--;

				if (arr[x - 1][y].ch == '.') {
					arr[x - 1][y].ch = 'C';
					//arr1[x - 1][y].ch = 'C';
					x--;
				}

				//this if boost the coins by 1.

				else if (arr[x - 1][y].ch == '$') {
					arr[x - 1][y].ch = 'C';
					//arr1[x - 1][y].ch = 'C';
					x--;
					coins++;
				}

				//this condition check if a car hit the obstacles this condition deduct score by 5.

				else if (arr[x - 1][y].ch == '#') {
					Beep(500, 1000);
					arr[x - 1][y].ch = 'C';
					//arr1[x - 1][y].ch = 'C';
					x--;
					score -= 5;
				}

				//this condition boost the score by 1.


				else if (arr[x - 1][y].ch == '+') {
					arr[x - 1][y].ch = 'C';
					//arr1[x - 1][y].ch = 'C';
					x--;
					score++;
				}

				//this condition refuel the tank.


				else if (arr[x - 1][y].ch == 'f') {
					arr[x - 1][y].ch = 'C';
					//arr1[x - 1][y].ch = 'C';
					x--;
					steps += 20;
				}


				//this condition check that the player reaches the the end point or not.

				else if (arr[x - 1][y].ch == 'E') {
					check = true;
					break;
				}


				//this condition store the mystery box, trophies and keys in a linked list.


				else if (arr[x - 1][y].ch == 'B' || arr[x - 1][y].ch == 'T' || arr[x - 1][y].ch == 'K') {
					list.createNode(arr[x - 1][y].ch);
					arr[x - 1][y].ch = 'C';
				//	arr[x - 1][y].ch = 'C';
					x--;
				}

				//else check that the player hit the wall or not it he hit score will be minus by 1.

				else {
					arr[x - 1][y].ch = 'X';
					Beep(500, 1000);
					//arr1[x - 1][y].ch = 'X';
					score--;

					arr[x][y].ch = 'C';
					//arr1[x][y].ch = 'C';
				}

				//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.

				if (arr[x + 1][y - 1].ch == '#') {
					score += 5;
					arr[x + 1][y - 1].ch = '.';
				}
				if (arr[x + 1][y + 1].ch == '#') {
					score += 5;
					arr[x + 1][y + 1].ch = '.';
				}

			}


			//this else if control the left movements.

			else if (move == 'a' || move == 'A') { // 75

				arr[x][y].ch = '.';
				steps--;

				if (arr[x][y - 1].ch == '.') {
					arr[x][y - 1].ch = 'C';
					//arr1[x][y - 1].ch = 'C';
					y--;
				}

				//this if boost the coins by 1.

				else if (arr[x][y - 1].ch == '$') {
					arr[x][y - 1].ch = 'C';
					//arr1[x][y - 1].ch = 'C';
					y--;
					coins++;
				}

				//this condition check if a car hit the obstacles this condition deduct score by 5.


				else if (arr[x][y - 1].ch == '#') {
					Beep(500, 1000);
					arr[x][y - 1].ch = 'C';
					//arr1[x][y - 1].ch = 'C';
					y--;
					score -= 5;
				}

				//this condition boost the score by 1.

				else if (arr[x][y - 1].ch == '+') {
					arr[x][y - 1].ch = 'C';
					//arr1[x][y - 1].ch = 'C';
					y--;
					score ++;
				}

				//this condition refuel the tank.


				else if (arr[x][y - 1].ch == 'f') {
					arr[x][y - 1].ch = 'C';
					//arr1[x][y - 1].ch = 'C';
					y--;
					steps+=20;
				}


				//this condition check that the player reaches the the end point or not.


				else if (arr[x][y - 1].ch == 'E') {
					check = true;
					break;
				}


				//this condition store the mystery box, trophies and keys in a linked list.


				else if (arr[x][y - 1].ch == 'B' || arr[x][y - 1].ch == 'T' || arr[x][y - 1].ch == 'K') {
					list.createNode(arr[x][y - 1].ch);
					arr[x][y - 1].ch = 'C';
					//arr1[x][y - 1].ch = 'C';
					y--;
				}

				//else check that the player hit the wall or not it he hit score will be minus by 1.

				else {
					arr[x][y - 1].ch = 'X';
					Beep(500, 1000);
					//arr1[x][y - 1].ch = 'X';
					score--;
					arr[x][y].ch = 'C';
					//arr1[x][y].ch = 'C';

				}


				//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.

				if (arr[x + 1][y + 1].ch == '#') {
					score += 5;
					arr[x + 1][y + 1].ch = '.';
				}
				if (arr[x - 1][y + 1].ch == '#') {
					score += 5;
					arr[x - 1][y + 1].ch = '.';
				}

			}


			// display the grid after every movement

			SetConsoleTextAttribute(h, 7);
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Score: " << score << "\t\t\t" << "Coins: " << coins << "\t\t\t" << "Remaining steps: " << steps << "\t\t\tLevel: " << level << endl;
			cout << "------------------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++) {
					if (arr[i][j].ch == '|' || arr[i][j].ch == '-' || arr[i][j].ch == '_' || arr[i][j].ch == '#') {
						SetConsoleTextAttribute(h, 4);
						cout << arr[i][j].ch << " ";
					}
					else if (arr[i][j].ch == 'K' || arr[i][j].ch == '$') {
						SetConsoleTextAttribute(h, 6);
						cout << arr[i][j].ch << " ";
					}
					else if (arr[i][j].ch == '+') {
						SetConsoleTextAttribute(h, 2);
						cout << arr[i][j].ch << " ";
					}
					else if (arr[i][j].ch == 'T' || arr[i][j].ch == 'B') {
						SetConsoleTextAttribute(h, 9);
							cout << arr[i][j].ch << " ";
					}
					else if (arr[i][j].ch == 'f') {
						SetConsoleTextAttribute(h, 13);
						cout << arr[i][j].ch << " ";
					}
					else {
						SetConsoleTextAttribute(h, 7);
						cout << arr[i][j].ch << " ";
					}
				}
				cout << endl;
			}

			//tihs condition check if the player terminate this condition check that he has a live or not.
			//if have a key he has an option to use the key or not.
			//If he use the key game will start to their where he left.
			//if not the key will be store for the next game in the file.

			if (score < 0 || steps <= 0) {
				Node* temp1 = list.head;
				bool c1 = false;
				int keys = 0;
				while (temp1 != NULL)
				{
					if (temp1->ch == 'K') {
						c1 = true;
						keys++;
					}
					temp1 = temp1->next;

				}
				if (c1 == true) {
					Sleep(300);
					cout << endl << "You want to use key or not? Y/N" << endl;
					char character = _getch();
					if (character == 'Y' || character == 'y') {
						list.delete_Node('K');
						steps += 60;
						if (score < 0) {
							score = 0;
						}
					}
					else {
						ofstream out1;
						out1.open("Keys.txt");
						out1 << "Name:" << name << endl;
						out1 << "Keys:" << score << endl;
						out1 << endl;
					}
				}
				else if (c1 == false) {
					ifstream in;
					ofstream of;
					cout << "sdsdsd" << endl;
					in.open("Keys.txt");
					string str1;
					int ind;
					getline(in, str1);
					ind = str1.find(':');
					if (ind > 0) {
						str1 = str1.substr(ind + 1);
					}
					if (ind > 0 && str1 == name) {
						getline(in, str1);
						ind = str1.find(':');
						str1 = str1.substr(ind + 1);
						ind = stoi(str1);
						if (ind > 0) {
							cout << endl << "You want to use your previous key or not? Y/N" << endl;
							char character = _getch();
							if (character == 'Y' || character == 'y') {
								of.open("Keys.txt");
								of << endl;
								steps += 60;
								if (score < 0) {
									score = 0;
								}
								c1 = true;
							}
						}
					}
		
				}

				if (c1 == false) {
					break;
				}
			}

			//arr[x][y].ch = '.';
			//arr1[x][y].ch = '.';

		}

		//this condition dequeue the trophies mystery boxes from the list and boost the score and coins.

		if (check == false || level == 3) {
			Node* temp = list.head;
			while (temp != NULL)
			{
				if (temp->ch == 'T') {
					int a = rand() % 25;
					score += a;
				}
				else if (temp->ch == 'B') {
					int a = rand() % 50;
					coins += a;
				}
				temp = temp->next;
			}

			ofstream out;
			out.open("Scoreboard.txt", ios::app);
			out << "Name:" << name <<" "<< "Score:" << score << " "<< "Coins:" << coins << endl;


		}

		SetConsoleTextAttribute(h, 7);
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Score: " << score << "\t\t\t" << "Coins: " << coins << "\t\t\t" << "Remaining steps: " << steps << "\t\t\tLevel: " << level << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;

		if (check == false) {
			cout << "Oops! better luck next point" << endl;
			_getch();
			return false;
		}
		else {
			cout << "Congratulation you win the game" << endl;
			_getch();
			return true;
		}

	}



	int getScore() {
		return score;
	}

	int getCoins() {
		return coins;/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/

#pragma once
#include <iostream>
#include"Queue_Node.h"
#include"Level_One.h"
#include"Level_Two.h"
#include"Level_Three.h"
#include"Linked_List.h"
#include<Windows.h>
#include<conio.h>
#include"Gird_list.h"
#include"Resume.h"
		using namespace std;


		class Game_Play {

			Level_One one;
			Level_Two two;
			Level_Three three;
			linked_list list;
			Grid_Node** arr;
			int score;
			int coins;
			int steps;

		public:

			Game_Play() {
				score = 0;
				coins = 0;
				steps = 0;
			}

			bool game_control(int level, string name) {
				int size = 0;
				int x = 1;
				int y = 1;
				bool check = false;
				HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

				//these condition check the level and a resume.

				if (level == 1) {
					size = 16;
					arr = one.level_One_Grid();
					steps += 40;
				}
				else if (level == 2) {
					size = 32;
					arr = two.level_Two_Grid();
					steps += 40;
				}
				else if (level == 3) {
					size = 50;
					arr = three.level_Three_Grid();
					steps += 80;
				}
				else if (level == 0) {
					Resume r;
					size = r.getSize();
					level = r.getLevel();
					arr = r.Resume_grid();
					score = r.getScore();
					coins = r.getCoins();
					x = r.getX_axis();
					y = r.getY_axis();
					steps = r.getSteps();
				}

				//here the score coins and level will be displayed.

				SetConsoleTextAttribute(h, 7);
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Score: " << score << "\t\t\t" << "Coins: " << coins << "\t\t\t" << "Remaining steps: " << steps << "\t\t\tLevel: " << level << endl;
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;

				//these loops display the gird.

				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++) {
						if (arr[i][j].ch == '|' || arr[i][j].ch == '-' || arr[i][j].ch == '_' || arr[i][j].ch == '#') {
							SetConsoleTextAttribute(h, 4);
							cout << arr[i][j].ch << " ";
						}
						else if (arr[i][j].ch == 'K' || arr[i][j].ch == '$') {
							SetConsoleTextAttribute(h, 6);
							cout << arr[i][j].ch << " ";
						}
						else if (arr[i][j].ch == '+') {
							SetConsoleTextAttribute(h, 2);
							cout << arr[i][j].ch << " ";
						}
						else if (arr[i][j].ch == 'T' || arr[i][j].ch == 'B') {
							SetConsoleTextAttribute(h, 9);
							cout << arr[i][j].ch << " ";
						}
						else if (arr[i][j].ch == 'f') {
							SetConsoleTextAttribute(h, 13);
							cout << arr[i][j].ch << " ";
						}
						else {
							SetConsoleTextAttribute(h, 7);
							cout << arr[i][j].ch << " ";
						}
					}
					cout << endl;
				}
				arr[x][y].ch = '.';


				//this while control the game. maens When the score or a coin boost and fuel as well and check that when the game will terminated. 


				while (score >= 0 && steps > 0)
				{
					SetConsoleTextAttribute(h, 7);
					char move = _getch();
					//	cin >> move;
					Sleep(1);
					system("CLS");


					//the below if control when the player stop the game in between so this condition will store his record in file. 

					if (move == 27) {

						Node* temp = list.head;
						while (temp != NULL)
						{
							if (temp->ch == 'T') {
								int a = rand() % 25;
								score += a;
							}
							else if (temp->ch == 'B') {
								int a = rand() % 50;
								coins += a;
							}
							temp = temp->next;
						}


						ofstream out;
						out.open("Resume.txt");
						out << "Name:" << name << endl;
						out << "Size:" << size << endl;
						out << "Score:" << score << endl;
						out << "coins:" << coins << endl;
						out << "Level:" << level << endl;
						out << "x_axis:" << x << endl;
						out << "y_axis:" << y << endl;
						out << "steps:" << steps << endl;
						for (int i = 0; i < size; i++)
						{
							for (int j = 0; j < size; j++) {
								out << arr[i][j].ch << endl;
							}

						}
						return false;
					}




					//this else if control the right movements.


					else if (move == 'D' || move == 'd') {

						arr[x][y].ch = '.';
						steps--;

						if (arr[x][y + 1].ch == '.') {
							arr[x][y + 1].ch = 'C';
							//arr1[x][y + 1].ch = 'C';
							y++;
						}

						//this if boost the coins by 1.

						else if (arr[x][y + 1].ch == '$') {
							arr[x][y + 1].ch = 'C';
							//arr1[x][y + 1].ch = 'C';
							y++;
							coins++;
						}
						//this condition check if a car hit the obstacles this condition deduct score by 5.

						else if (arr[x][y + 1].ch == '#') {
							Beep(500, 1000);
							arr[x][y + 1].ch = 'C';
							//arr1[x][y + 1].ch = 'C';
							y++;
							score -= 5;
						}

						//this condition boost the score by 1.

						else if (arr[x][y + 1].ch == '+') {
							arr[x][y + 1].ch = 'C';
							//arr1[x][y + 1].ch = 'C';
							y++;
							score++;
						}


						//this condition refuel the tank.


						else if (arr[x][y + 1].ch == 'f') {
							arr[x][y + 1].ch = 'C';
							//arr1[x][y + 1].ch = 'C';
							y++;
							steps += 20;
						}


						//this condition check that the player reaches the the end point or not.


						else if (arr[x][y + 1].ch == 'E') {
							check = true;
							break;
						}

						//this condition store the mystery box, trophies and keys in a linked list.

						else if (arr[x][y + 1].ch == 'B' || arr[x][y + 1].ch == 'T' || arr[x][y + 1].ch == 'K') {
							list.createNode(arr[x][y + 1].ch);
							arr[x][y + 1].ch = 'C';
							//arr1[x][y + 1].ch = 'C';
							y++;
						}

						//else check that the player hit the wall or not it he hit score will be minus by 1.

						else {
							arr[x][y + 1].ch = 'X';
							Beep(500, 1000);
							//arr1[x][y + 1].ch = 'X';
							score--;

							arr[x][y].ch = 'C';
							//arr1[x][y].ch = 'C';
						}

						//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.                                                 

						if (arr[x - 1][y - 1].ch == '#') {
							score += 5;
							arr[x - 1][y - 1].ch = '.';
						}
						if (arr[x + 1][y - 1].ch == '#') {
							score += 5;
							arr[x + 1][y - 1].ch = '.';
						}

					}



					//this else if control the down movements.

					else if (move == 's' || move == 'S') {

						arr[x][y].ch = '.';
						steps--;

						if (arr[x + 1][y].ch == '.') {
							arr[x + 1][y].ch = 'C';
							//arr1[x + 1][y].ch = 'C';
							x++;
						}

						//this if boost the coins by 1.


						else if (arr[x + 1][y].ch == '$') {
							arr[x + 1][y].ch = 'C';
							//arr1[x + 1][y].ch = 'C';
							x++;
							coins++;
						}

						//this condition check if a car hit the obstacles this condition deduct score by 5.

						else if (arr[x + 1][y].ch == '#') {
							Beep(500, 1000);
							arr[x + 1][y].ch = 'C';
							//arr1[x + 1][y].ch = 'C';
							x++;
							score -= 5;
						}

						//this condition boost the score by 1.

						else if (arr[x + 1][y].ch == '+') {
							arr[x + 1][y].ch = 'C';
							//arr1[x + 1][y].ch = 'C';
							x++;
							score++;
						}

						//this condition refuel the tank.


						else if (arr[x + 1][y].ch == 'f') {
							arr[x + 1][y].ch = 'C';
							//arr1[x + 1][y].ch = 'C';
							x++;
							steps += 20;
						}

						//this condition check that the player reaches the the end point or not.


						else if (arr[x + 1][y].ch == 'E') {
							check = true;
							break;
						}

						//this condition store the mystery box, trophies and keys in a linked list.


						else if (arr[x + 1][y].ch == 'B' || arr[x + 1][y].ch == 'T' || arr[x + 1][y].ch == 'K') {
							list.createNode(arr[x + 1][y].ch);
							arr[x + 1][y].ch = 'C';
							arr[x + 1][y].ch = 'C';
							x++;
						}

						//else check that the player hit the wall or not it he hit score will be minus by 1.

						else {
							arr[x + 1][y].ch = 'X';
							Beep(500, 1000);
							//arr1[x + 1][y].ch = 'X';
							score--;

							arr[x][y].ch = 'C';
							//arr1[x][y].ch = 'C';
						}

						//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.

						if (arr[x - 1][y - 1].ch == '#') {
							score += 5;
							arr[x - 1][y - 1].ch = '.';
						}
						if (arr[x - 1][y + 1].ch == '#') {
							score += 5;
							arr[x - 1][y + 1].ch = '.';
						}

					}



					//this else if control the up movements.

					else if (move == 'w' || move == 'W') {

						arr[x][y].ch = '.';
						steps--;

						if (arr[x - 1][y].ch == '.') {
							arr[x - 1][y].ch = 'C';
							//arr1[x - 1][y].ch = 'C';
							x--;
						}

						//this if boost the coins by 1.

						else if (arr[x - 1][y].ch == '$') {
							arr[x - 1][y].ch = 'C';
							//arr1[x - 1][y].ch = 'C';
							x--;
							coins++;
						}

						//this condition check if a car hit the obstacles this condition deduct score by 5.

						else if (arr[x - 1][y].ch == '#') {
							Beep(500, 1000);
							arr[x - 1][y].ch = 'C';
							//arr1[x - 1][y].ch = 'C';
							x--;
							score -= 5;
						}

						//this condition boost the score by 1.


						else if (arr[x - 1][y].ch == '+') {
							arr[x - 1][y].ch = 'C';
							//arr1[x - 1][y].ch = 'C';
							x--;
							score++;
						}

						//this condition refuel the tank.


						else if (arr[x - 1][y].ch == 'f') {
							arr[x - 1][y].ch = 'C';
							//arr1[x - 1][y].ch = 'C';
							x--;
							steps += 20;
						}


						//this condition check that the player reaches the the end point or not.

						else if (arr[x - 1][y].ch == 'E') {
							check = true;
							break;
						}


						//this condition store the mystery box, trophies and keys in a linked list.


						else if (arr[x - 1][y].ch == 'B' || arr[x - 1][y].ch == 'T' || arr[x - 1][y].ch == 'K') {
							list.createNode(arr[x - 1][y].ch);
							arr[x - 1][y].ch = 'C';
							//	arr[x - 1][y].ch = 'C';
							x--;
						}

						//else check that the player hit the wall or not it he hit score will be minus by 1.

						else {
							arr[x - 1][y].ch = 'X';
							Beep(500, 1000);
							//arr1[x - 1][y].ch = 'X';
							score--;

							arr[x][y].ch = 'C';
							//arr1[x][y].ch = 'C';
						}

						//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.

						if (arr[x + 1][y - 1].ch == '#') {
							score += 5;
							arr[x + 1][y - 1].ch = '.';
						}
						if (arr[x + 1][y + 1].ch == '#') {
							score += 5;
							arr[x + 1][y + 1].ch = '.';
						}

					}


					//this else if control the left movements.

					else if (move == 'a' || move == 'A') {

						arr[x][y].ch = '.';
						steps--;

						if (arr[x][y - 1].ch == '.') {
							arr[x][y - 1].ch = 'C';
							//arr1[x][y - 1].ch = 'C';
							y--;
						}

						//this if boost the coins by 1.

						else if (arr[x][y - 1].ch == '$') {
							arr[x][y - 1].ch = 'C';
							//arr1[x][y - 1].ch = 'C';
							y--;
							coins++;
						}

						//this condition check if a car hit the obstacles this condition deduct score by 5.


						else if (arr[x][y - 1].ch == '#') {
							Beep(500, 1000);
							arr[x][y - 1].ch = 'C';
							//arr1[x][y - 1].ch = 'C';
							y--;
							score -= 5;
						}

						//this condition boost the score by 1.

						else if (arr[x][y - 1].ch == '+') {
							arr[x][y - 1].ch = 'C';
							//arr1[x][y - 1].ch = 'C';
							y--;
							score++;
						}

						//this condition refuel the tank.


						else if (arr[x][y - 1].ch == 'f') {
							arr[x][y - 1].ch = 'C';
							//arr1[x][y - 1].ch = 'C';
							y--;
							steps += 20;
						}


						//this condition check that the player reaches the the end point or not.


						else if (arr[x][y - 1].ch == 'E') {
							check = true;
							break;
						}


						//this condition store the mystery box, trophies and keys in a linked list.


						else if (arr[x][y - 1].ch == 'B' || arr[x][y - 1].ch == 'T' || arr[x][y - 1].ch == 'K') {
							list.createNode(arr[x][y - 1].ch);
							arr[x][y - 1].ch = 'C';
							//arr1[x][y - 1].ch = 'C';
							y--;
						}

						//else check that the player hit the wall or not it he hit score will be minus by 1.

						else {
							arr[x][y - 1].ch = 'X';
							Beep(500, 1000);
							//arr1[x][y - 1].ch = 'X';
							score--;
							arr[x][y].ch = 'C';
							//arr1[x][y].ch = 'C';

						}


						//the below conditions check that the player cross the obstacles or not if yes the score increase by 5.

						if (arr[x + 1][y + 1].ch == '#') {
							score += 5;
							arr[x + 1][y + 1].ch = '.';
						}
						if (arr[x - 1][y + 1].ch == '#') {
							score += 5;
							arr[x - 1][y + 1].ch = '.';
						}

					}


					// display the grid after every movement

					SetConsoleTextAttribute(h, 7);
					cout << "------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Score: " << score << "\t\t\t" << "Coins: " << coins << "\t\t\t" << "Remaining steps: " << steps << "\t\t\tLevel: " << level << endl;
					cout << "------------------------------------------------------------------------------------------------------------------" << endl;
					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < size; j++) {
							if (arr[i][j].ch == '|' || arr[i][j].ch == '-' || arr[i][j].ch == '_' || arr[i][j].ch == '#') {
								SetConsoleTextAttribute(h, 4);
								cout << arr[i][j].ch << " ";
							}
							else if (arr[i][j].ch == 'K' || arr[i][j].ch == '$') {
								SetConsoleTextAttribute(h, 6);
								cout << arr[i][j].ch << " ";
							}
							else if (arr[i][j].ch == '+') {
								SetConsoleTextAttribute(h, 2);
								cout << arr[i][j].ch << " ";
							}
							else if (arr[i][j].ch == 'T' || arr[i][j].ch == 'B') {
								SetConsoleTextAttribute(h, 9);
								cout << arr[i][j].ch << " ";
							}
							else if (arr[i][j].ch == 'f') {
								SetConsoleTextAttribute(h, 13);
								cout << arr[i][j].ch << " ";
							}
							else {
								SetConsoleTextAttribute(h, 7);
								cout << arr[i][j].ch << " ";
							}
						}
						cout << endl;
					}

					//tihs condition check if the player terminate this condition check that he has a live or not.
					//if have a key he has an option to use the key or not.
					//If he use the key game will start to their where he left.
					//if not the key will be store for the next game in the file.

					if (score < 0 || steps <= 0) {
						Node* temp1 = list.head;
						bool c1 = false;
						int keys = 0;
						while (temp1 != NULL)
						{
							if (temp1->ch == 'K') {
								c1 = true;
								keys++;
							}
							temp1 = temp1->next;

						}
						if (c1 == true) {
							Sleep(300);
							cout << endl << "You want to use key or not? Y/N" << endl;
							char character = _getch();
							if (character == 'Y' || character == 'y') {
								list.delete_Node('K');
								steps += 60;
								if (score < 0) {
									score = 0;
								}
							}
							else {
								ofstream out1;
								out1.open("Keys.txt");
								out1 << "Name:" << name << endl;
								out1 << "Keys:" << score << endl;
								out1 << endl;
							}
						}
						else if (c1 == false) {
							ifstream in;
							ofstream of;
							cout << "sdsdsd" << endl;
							in.open("Keys.txt");
							string str1;
							int ind;
							getline(in, str1);
							ind = str1.find(':');
							if (ind > 0) {
								str1 = str1.substr(ind + 1);
							}
							if (ind > 0 && str1 == name) {
								getline(in, str1);
								ind = str1.find(':');
								str1 = str1.substr(ind + 1);
								ind = stoi(str1);
								if (ind > 0) {
									cout << endl << "You want to use your previous key or not? Y/N" << endl;
									char character = _getch();
									if (character == 'Y' || character == 'y') {
										of.open("Keys.txt");
										of << endl;
										steps += 60;
										if (score < 0) {
											score = 0;
										}
										c1 = true;
									}
								}
							}

						}

						if (c1 == false) {
							break;
						}
					}

					//arr[x][y].ch = '.';
					//arr1[x][y].ch = '.';

				}

				//this condition dequeue the trophies mystery boxes from the list and boost the score and coins.

				if (check == false || level == 3) {
					Node* temp = list.head;
					while (temp != NULL)
					{
						if (temp->ch == 'T') {
							int a = rand() % 25;
							score += a;
						}
						else if (temp->ch == 'B') {
							int a = rand() % 50;
							coins += a;
						}
						temp = temp->next;
					}

					ofstream out;
					out.open("Scoreboard.txt", ios::app);
					out << "Name:" << name << " " << "Score:" << score << " " << "Coins:" << coins << endl;


				}

				SetConsoleTextAttribute(h, 7);
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "Score: " << score << "\t\t\t" << "Coins: " << coins << "\t\t\t" << "Remaining steps: " << steps << "\t\t\tLevel: " << level << endl;
				cout << "------------------------------------------------------------------------------------------------------------------" << endl;

				if (check == false) {
					cout << "Oops! better luck next point" << endl;
					_getch();
					return false;
				}
				else {
					cout << "Congratulation you win the game" << endl;
					_getch();
					return true;
				}

			}



			int getScore() {
				return score;
			}

			int getCoins() {
				return coins;
			}


		};





	}


};





