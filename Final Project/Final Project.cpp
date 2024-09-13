/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/


#include <iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include"Game_Play.h"
#include"Leaderboard.h"
#include"Resume.h"
#include"Auto_Play.h"
using namespace std;
int main()
{


	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool check = true;
	while (check)
	{
		Sleep(30);
		system("CLS");
		SetConsoleTextAttribute(h, 6);
		cout << "\t\t/====================================================================================\\" << endl
			<< "\t\t|| ________  ________  ________  _______           ________  ________  ________     ||" << endl
			<< "\t\t|||\\   __  \\|\\   __  \\|\\   ____\\|\\  ___ \\         |\\   ____\\|\\   __  \\|\\   __  \\    ||" << endl
			<< "\t\t||\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|        \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\   ||" << endl
			<< "\t\t|| \\ \\   _  _\\ \\   __  \\ \\  \\    \\ \\  \\_|/__       \\ \\  \\    \\ \\   __  \\ \\   _  _\\  ||" << endl;
		SetConsoleTextAttribute(h, 9);
		cout << "\t\t||  \\ \\  \\\\  \\\\ \\  \\ \\  \\ \\  \\____\\ \\  \\_|\\ \\       \\ \\  \\____\\ \\  \\ \\  \\ \\  \\\\  \\| ||" << endl
			<< "\t\t||   \\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\_______\\ \\_______\\       \\ \\_______\\ \\__\\ \\__\\ \\__\\\\ _\\ ||" << endl
			<< "\t\t||    \\|__|\\|__|\\|__|\\|__|\\|_______|\\|_______|        \\|_______|\\|__|\\|__|\\|__|\\|__|||" << endl
			<< "\t\t\\====================================================================================/" << endl << endl << endl;
		SetConsoleTextAttribute(h, 6);

		// Main menu


		cout << "\t\t\t\t\t/================================\\" << endl;
		cout << "\t\t\t\t\t||\t\t\t\t||" << endl;
		cout << "\t\t\t\t\t||\t1. Start the Game\t||" << endl;
		cout << "\t\t\t\t\t||\t2. ScoreBoard\t\t||" << endl;
		cout << "\t\t\t\t\t||\t3. AutoPlay\t\t||" << endl;
		cout << "\t\t\t\t\t||\t4. Quit\t\t\t||" << endl;
		cout << "\t\t\t\t\t||\t\t\t\t||" << endl;
		cout << "\t\t\t\t\t\\================================/" << endl << endl << endl;
		char ch = _getch();
		switch (ch)
		{
		case '1': {

			//on this point i display the objects and game control.

			SetConsoleTextAttribute(h, 5);
			cout << "Start:";
			SetConsoleTextAttribute(h, 4);
			cout << " S" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Wall: ";
			SetConsoleTextAttribute(h, 4);
			cout << " | , -" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Obstacles:";
			SetConsoleTextAttribute(h, 4);
			cout << " #" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Mystery Box:";
			SetConsoleTextAttribute(h, 4);
			cout << " B" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Trophy:";
			SetConsoleTextAttribute(h, 4);
			cout << " T" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Car:";
			SetConsoleTextAttribute(h, 4);
			cout << " C" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Routes:";
			SetConsoleTextAttribute(h, 4);
			cout << " ." << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Key/Live:";
			SetConsoleTextAttribute(h, 4);
			cout << " K" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Power-Ups:";
			SetConsoleTextAttribute(h, 4);
			cout << " +" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Fuel Tank:";
			SetConsoleTextAttribute(h, 4);
			cout << " f" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Coins:";
			SetConsoleTextAttribute(h, 4);
			cout << " &" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "End:";
			SetConsoleTextAttribute(h, 4);
			cout << " E" << endl << endl;

			SetConsoleTextAttribute(h, 1);
			cout << "Game Controling keys : " << endl << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Going Up:";
			SetConsoleTextAttribute(h, 4);
			cout << " W" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Going Right:";
			SetConsoleTextAttribute(h, 4);
			cout << " D" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Going Down:";
			SetConsoleTextAttribute(h, 4);
			cout << " S" << endl;
			SetConsoleTextAttribute(h, 5);
			cout << "Going Left";
			SetConsoleTextAttribute(h, 4);
			cout << " A" << endl << endl;

			string name;
			Game_Play game;
			int s, c, ps;
			bool check1;
			char ch1;
			int level;
			cout << "Enter your Name: ";
			SetConsoleTextAttribute(h, 1);
			getline(cin, name);
			ifstream in;
			in.open("Scoreboard.txt");
			string str, s1;
			int i, i2;
			while (getline(in, str))
			{
				i = str.find(':');
				i2 = str.find("Score");
				//cout << i2 << endl;
				s1 = str.substr(i + 1, i2 - 6);
				if (s1 == name) {
					str = str.substr(i + 1);
					//cout << str << endl;
					i = str.find(':');
					i2 = str.find("Coins");
					s1 = str.substr(i + 1, i2);
					//cout << s << endl;
					ps = stoi(s1);
					SetConsoleTextAttribute(h, 4);
					cout << "Your Previous Games Score is : ";
					SetConsoleTextAttribute(h, 1);
					cout << ps << endl;
				}
			}

			ifstream iff;
			iff.open("Resume.txt");
			getline(iff, str);
			i = str.find(':');
			if (i > 0) {
				str = str.substr(i + 1);
			}

			if (i > 0 && str == name) {
				//	game.game_control(0, name);
				cout << "You want to resume or not?(Y/N)" << endl;
				ch1 = _getch();

				if (ch1 == 'Y' || ch1 == 'y') {
					Resume r;
					level = r.getLevel();
					check1 = game.game_control(0, name);
					level++;
					while (check1 == true && level <= 3)
					{
						check1 = game.game_control(level, name);
						level++;
					}
					ofstream out;
					out.open("Resume.txt");
					out << endl;
				}
				else if (ch1 == 'N' || ch1 == 'n') {
					ofstream out;
					out.open("Resume.txt");
					out << endl;
					cout << endl << "Press any key to start the game" << endl;
					_getch();


					check1 = game.game_control(1, name);
					if (check1 == true) {
						check1 = game.game_control(2, name);
						if (check1 == true) {
							game.game_control(3, name);
						}
					}
				}

			}
			else {
				cout << endl << "Press any key to start the game" << endl;
				_getch();


				check1 = game.game_control(1, name);
				if (check1 == true) {
					check1 = game.game_control(2, name);
					if (check1 == true) {
						game.game_control(3, name);
					}
				}
			}
			break;
		}
		case '2': {

			//Read data from file and store in a tree and then display.

			Tree tree;
			SetConsoleTextAttribute(h, 9);
			cout << "\t\t\tName\t\t\t\tScore\t\t\tCoins" << endl;
			int player = 1;
			ifstream in;
			in.open("Scoreboard.txt");
			string str;
			int counter = 0;
			string s, name;
			int index, i2, score, coins;
			SetConsoleTextAttribute(h, 7);
			while (in.is_open()) {
				if (in.eof()) {
					break;
				}
				while (getline(in, str))
				{
					index = str.find(':');
					i2 = str.find("Score");
					//cout << i2 << endl;
					s = str.substr(index + 1, i2 - 5);
					//cout << s << endl;
					name = s;
					str = str.substr(index + 1);
					//cout << str << endl;
					index = str.find(':');
					i2 = str.find("Coins");
					s = str.substr(index + 1, i2);
					//cout << s << endl;
					score = stoi(s);
					str = str.substr(index + 1);
					//cout << str << endl;
					index = str.find(':');
					s = str.substr(index + 1);
					//cout << s << endl;
					coins = stoi(s);
					tree.Insert(name, score, coins);
				}
			}

			tree.print(tree.root);
			_getch();
			break;
		}
		case '3': {

			//Auto play case.
			Auto_play play;
			play.dijkstraShortestPath(1);
			play.dijkstraShortestPath(2);
			play.dijkstraShortestPath(3);
			_getch();
			break;
		}
		case '4': {

			//Exit case.
			check = false;
		}
		default:
			break;
		}
	}

}
