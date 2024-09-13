/*
Fawad Humayun (22i-2548)
Areeba Nisar(22i-8770)
SE-E
*/


#include <iostream>
#include<Windows.h>
#include <queue>
#include"Gird_list.h"
using namespace std;
class Level_One {
	Grid_Node** arr;
public:
	Level_One() {
		arr = new Grid_Node*[16];
		for (int i = 0; i < 16; i++)
		{
			arr[i] = new Grid_Node[16];
			for (int j = 0; j < 16; j++)
			{
				arr[i][j] = Grid_Node();
			}
		}

	}
	Grid_Node** level_One_Grid() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++) {
				if (i == 0) {
					arr[i][j].ch = '_';
				}
				else if (i == 15) {
					arr[i][j].ch = '-';
				}
				else if (j == 0 || j % 3 == 0) {
					arr[i][j].ch = '|';
				}
				else {
					arr[i][j].ch = '.';
				}
			}
		}

		arr[1][1].ch = 'S';

		arr[3][3].ch = '-';
		arr[3][4].ch = '-';
		arr[3][5].ch = '-';
		arr[3][6].ch = '-';
		arr[3][7].ch = '-';
		arr[3][8].ch = '-';
		arr[3][9].ch = '-';

		arr[6][1].ch = '-';
		arr[6][2].ch = '-';
		arr[6][3].ch = '-';
		arr[6][4].ch = '-';
		arr[6][5].ch = '-';
		arr[6][6].ch = '-';
		arr[6][7].ch = '-';
		arr[6][8].ch = '-';
		arr[6][9].ch = '-';
		arr[6][10].ch = '-';
		arr[6][11].ch = '-';

		arr[1][12].ch = '.';
		arr[2][12].ch = '.';
		arr[1][9].ch = '.';
		arr[2][9].ch = '.';
		arr[1][6].ch = '.';
		arr[2][6].ch = '.';


		arr[4][9].ch = '.';
		arr[5][9].ch = '.';
		arr[4][6].ch = '.';
		arr[5][6].ch = '.';
		arr[4][3].ch = '.';
		arr[5][3].ch = '.';


		arr[7][12].ch = '.';
		arr[8][12].ch = '.';
		arr[8][6].ch = '.';
		arr[7][6].ch = '.';

		arr[9][12].ch = '-';
		arr[9][13].ch = '-';
		arr[9][14].ch = '-';

		arr[13][12].ch = '.';
		arr[14][12].ch = '.';
		arr[13][9].ch = '.';
		arr[14][9].ch = '.';

		arr[9][6].ch = '-';
		arr[9][5].ch = '-';
		arr[9][4].ch = '-';
		arr[9][3].ch = '-';

		arr[7][3].ch = '.';
		arr[8][3].ch = '.';

		arr[12][3].ch = '-';
		arr[12][2].ch = '-';
		arr[12][1].ch = '-';

		arr[10][3].ch = '.';
		arr[11][3].ch = '.';
		arr[13][3].ch = '.';
		arr[14][3].ch = '.';

		arr[14][1].ch = 'E';
		srand(time(0));
		int x = 0;
		int x1, y1;


		//this loop randomly generate the fuel tanker in a gird which help the player to refill their fuel tank. 


		while (x != 3)
		{
			x1 = rand() % 16;
			y1 = rand() % 16;
			if (arr[x1][y1].ch == '.') {
				arr[x1][y1].ch = 'f';
				x++;
			}
		}



		int counter = 0;
		int x_axis, y_axis;


		srand(time(0));

		//this loop randomly generate the coins in a gird.

		while (counter != 11)
		{
			x_axis = rand() % 16;
			y_axis = rand() % 16;
			if (arr[x_axis][y_axis].ch == '.') {
				arr[x_axis][y_axis].ch = '$';
				counter++;
			}
		}
		QueueNode queue;


		counter = 0;

		//this loop randomly generate the obstacles and store those obstacles in queue.

		while (counter != 5)
		{
			x_axis = rand() % 16;
			y_axis = rand() % 16;
			if (arr[x_axis][y_axis].ch == '.') {
				queue.enqueue(x_axis, y_axis);
				counter++;
			}
		}


		counter = 0;


		//this loop randomly generate the Trophies in a gird which will boost the scores in the end.

		while (counter != 2)
		{
			x_axis = rand() % 16;
			y_axis = rand() % 16;
			if (arr[x_axis][y_axis].ch == '.') {
				arr[x_axis][y_axis].ch = 'T';
				counter++;
			}
		}


		counter = 0;

		//this loop randomly generate the Mystery boxes in a gird which will boost the coins in the end.

		while (counter != 2)
		{
			x_axis = rand() % 16;
			y_axis = rand() % 16;
			if (arr[x_axis][y_axis].ch == '.') {
				arr[x_axis][y_axis].ch = 'B';
				counter++;
			}
		}


		counter = 0;


		//this loop randomly generate the + in a gird which boost the score by 1.

		while (counter != 9)
		{
			x_axis = rand() % 16;
			y_axis = rand() % 16;
			if (arr[x_axis][y_axis].ch == '.') {
				arr[x_axis][y_axis].ch = '+';
				counter++;
			}
		}

		//this loop dequeue obstacles from the list and placed them in a gird. 

		Queue* q;
		do
		{
			q = queue.dequeue();
			if (q != NULL) {
				arr[q->x_axis][q->y_axis].ch = q->ch;
			}
		} while (q != NULL);



		//here we connected the up down left right nodes with each other.


		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 15; j++) {
				arr[i][j].right = &arr[i][j + 1];
				arr[i][j + 1].left = &arr[i][j];
			}
			if (i > 0) {
				for (int j = 0; j < 16; j++)
				{
					arr[i][j].up = &arr[i - 1][j];
					arr[i - 1][j].down = &arr[i][j];
				}
			}
		}
		//for (int i = 0; i < 16; i++) {
		//	for (int j = 0; j < 16; j++) {
		//		std::cout << arr[i][j].ch << " ";
		//	}
		//	std::cout << std::endl;
		//}

		return arr;

	}

};
