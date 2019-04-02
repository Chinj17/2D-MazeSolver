#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool PATH(int x, int y);
void Print_Map(vector<vector<char>>);
void Clear_Screen();
bool check(int a, int b);


vector<vector<char>> map{{'.','#','#','#','#','#'},
			 {'.','.','.','.','.','#'},
			 {'#','.','#','#','#','#'},
			 {'#','.','#','#','#','#'},
			 {'.','.','.','#','.','G'},
			 {'#','#','.','.','.','#'}};

int main()
{
	string border = "===========================";
	cout << "The maze is: " << endl;
	cout << border << endl;
	Print_Map(map);

	unsigned int startx, starty;
	cout << "Enter the starting Position (x y): ";
	cin >> startx >> starty;
	while (startx > 5)
	{
		cout << "Out of bounds. Enter new starting Position (x,y): ";
		cin >> startx >> starty;
		if (starty > 5 )
		{
			cout << "Out of bounds. Enter new starting Position (x,y): ";
			cin >> startx >> starty;
		}
	}
	while (starty > 5)
	{
		cout << "Out of bounds. Enter new starting Position (x,y): ";
		cin >> startx >> starty;
		if (startx > 5 )
		{
			cout << "Out of bounds. Enter new starting Position (x,y): ";
			cin >> startx >> starty;
		}
	}
	while (map[startx][starty] == '#')
	{
		cout << "An Obstacle is present at that position. Enter new starting Position (x,y): ";
		cin >> startx >> starty;
	}


	map[startx][starty] = 'S';
	Clear_Screen();
	cout << "Printing the new maze: " << endl;
	cout << border << endl;
	Print_Map(map);
	PATH(startx,starty);
	map[startx][starty] = 'S';

	cout << "\n Solved maze is: " << endl;
	cout << border << endl;
	Print_Map(map);
	return 0;
}

// Function to find the Path
bool PATH(int x, int y)
{
	if(check(x,y) == false)
  	{
		return false;
	}

	if(map[x][y] == 'G')
  	{
		return true;
	}

	if(map[x][y] == '#' || map[x][y]=='X' || map[x][y]=='x' || map[x][y] == '+')
  	{
		return false;
	}

	map[x][y] = '+';

	//Check movement North
	if (PATH(x,y-1) == true)
  	{
		return true;
	}

	//Check movement East
	if (PATH(x+1,y) == true)
  	{
		return true;
	}

	//Check movement South
	if (PATH(x,y+1) == true)
  	{
		return true;
	}

	//Check movement West
	if (PATH(x-1,y) == true)
  	{
		return true;
	}

	map[x][y] = 'X';

	return false;
}

// Function to print the Map
void Print_Map(vector<vector<char>> map)
{
	for (unsigned int i = 0; i < map.size(); i++)
	{
		cout << "\t";
		for (unsigned int j = 0; j < map[i].size(); j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

// Function to clear the screen
void Clear_Screen()
{
	cout << "\x1b[2J\x1b[1;1H" << flush;
}

// Function to check if the Path goes out of bounds 
bool check(int a, int b)
{
	if ( a > 5 || b > 5 || a < 0 || b < 0 || map[a][b] == '#' )
	{
		return false;
	}
	else
		return true;
}
