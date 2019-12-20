//SSBU Tournament Project
//By Jordan Cole

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

//Function prototypes
void shuffle_players(vector<string> vect);
void show_menu();
void display_scores();
void enter_wins();
void enter_kills;

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

	//Create vector for player names, wins, kills
	vector <string> player_names(total_players);
	vector <int> player_wins(total_players);
	vector <int> player_kills(total_players);

	//Loop to enter player names
	for (int i = 0; i < total_players; i++)
	{
		cout << "Player " << (i + 1) << ", please enter your name: ";
		cin >> player_names[i];
	}
	cout << endl;
    
    //Show menu options
    show_menu();
    
	return 0;
}

//Function: Display menu options
void show_menu()
{
    int menu_choice;
    
    cout << "Please choose from the following options:" << endl;
    cout << "1. Randomize Player Order" << endl;
    cout << "2. Enter Wins" << endl;
    cout << "3. Enter Kills" << endl;
    cout << "4. Exit" << endl;
    cin >> menu_choice;
    cout << endl;
    
    if (menu_choice == 1)
    {
        shuffle_players(player_names);
    }
    else if (menu_choice == 2)
    {
        enter_wins();
    }
    else if (menu_choice == 3)
    {
        enter_kills();
    }
    else if (menu_choice == 4)
    {
        
    }
    else
    {
        cout << "Invalid selection, please try again."
    }
}

//Function: Display current standings
void display_scores()
{
    cout << "Current Standings:" << endl;
}

//Function: Shuffle player order and display
void shuffle_players(vector<string> vect)
{
	int n = vect.size();
	srand(time(0));
	cout << "The player order this round will be:" << endl;
	for (int i = 0; i < n; i++)
	{
		int j = i + rand() % (n - i);
		swap(vect[i], vect[j]);
		cout << (i + 1) << ". " << vect[i] << endl;
	}
	cout << endl;
}

//Function: Enter win data
void enter_wins(vector<int> vect)
{
    
}

//Function: Display kill data
void enter_kills(vector<int> vect)
{
    
}
