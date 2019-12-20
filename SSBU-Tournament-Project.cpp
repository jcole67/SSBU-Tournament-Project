//SSBU Tournament Project
//By Jordan Cole

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

//Function prototypes
void shuffle_players(vector<string> vect);

int main()
{
	//Create var for player count
	int total_players;

	//User input for player count (must be 1-8)
	do
	{
		cout << "Please enter total number of players (1-8): ";
		cin >> total_players;
		cout << endl;
	} while (total_players < 1 || total_players > 8);

	//Create vector for player names
	vector <string> player_name(total_players);

	//Loop to enter player names
	for (int i = 0; i < total_players; i++)
	{
		cout << "Player " << (i + 1) << ", please enter your name: ";
		cin >> player_name[i];
	}
	cout << endl;

	//Randomize and display play order
	cout << "The play order this round will be:" << endl;
	shuffle_players(player_name);
	cout << endl;

	////////// WORKING //////////
	cout << "Who won that round?"

	return 0;
}

//Function: Shuffle player order and display
void shuffle_players(vector<string> vect)
{
	int n = vect.size();
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		int j = i + rand() % (n - i);
		swap(vect[i], vect[j]);
		cout << vect[i] << endl;
	}
}
