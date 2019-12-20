//SSBU Tournament Project
//By Jordan Cole

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

//Function prototypes
void shuffle_players(vector<string>names);
int show_menu(vector<string>names, vector<int>wins, vector<int>kills, int total);
void display_scores(vector<string>names, vector<int>wins, vector<int>kills, int total);
void enter_wins(vector<string>names, vector<int>wins, int total);
void enter_kills(vector<string>names, vector<int>kills, int total);

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
	vector<string>player_names(total_players);
	vector<int>player_wins(total_players);
	vector<int>player_kills(total_players);

	//Loop to enter player names
	for (int i = 0; i < total_players; i++)
	{
		cout << "Player " << (i + 1) << ", please enter your name: ";
		cin >> player_names[i];
	}
	cout << endl;
    
    //Show menu options until Exit
    int show_menu_choice;
    do
    {
        show_menu_choice = show_menu(player_names, player_wins, player_kills, total_players);
        display_scores(player_names, player_wins, player_kills, total_players);
    } while (show_menu_choice != 4);
    
    return 0;
}

//Function: Display menu options
int show_menu(vector<string>names, vector<int>wins, vector<int>kills, int total)
{
    int menu_choice;
    cout << "Please choose from the following options:" << endl;
    cout << "1. Randomize Player Order" << endl;
    cout << "2. Enter Wins" << endl;
    cout << "3. Enter Kills" << endl;
    cout << "4. Exit" << endl;
    cout << "Select and Press Enter: ";
    cin >> menu_choice;
    cout << endl;
    
    if (menu_choice == 1)
    {
        shuffle_players(names);
    }
    else if (menu_choice == 2)
    {
        enter_wins(names, wins, total);
    }
    else if (menu_choice == 3)
    {
        enter_kills(names, kills, total);
    }
    else if (menu_choice == 4)
    {
        cout << "Exit" << endl;
    }
    else
    {
        cout << "Invalid selection, please try again." << endl;
        cout << endl;
    }
    
    return menu_choice;
}

//Function: Display current standings
void display_scores(vector<string>names, vector<int>wins, vector<int>kills, int total)
{
    cout << "Current Standings:" << endl;
    for (int i = 0; i < total; i++)
	{
		cout << (i + 1) << ". " << names[i] << endl;
		cout << "[Wins - " << wins[i] << ", Kills - " << kills[i] << "]" << endl;
	}
    cout << endl;
}

//Function: Shuffle player order and display
void shuffle_players(vector<string>names)
{
	int n = names.size();
	srand(time(0));
	cout << "The player order this round will be:" << endl;
	for (int i = 0; i < n; i++)
	{
		int j = i + rand() % (n - i);
		swap(names[i], names[j]);
		cout << (i + 1) << ". " << names[i] << endl;
	}
	cout << endl;
}

//Function: Enter win data
void enter_wins(vector<string>names, vector<int>wins, int total)
{
    int menu_choice;
    cout << "Please select a player to add 1 win:" << endl;
    for (int i = 0; i < total; i++)
	{
		cout << (i + 1) << ". " << names[i] << endl;
	}
	cout << "Select and Press Enter: ";
	cin >> menu_choice;
    cout << endl;
}

//Function: Enter kill data
void enter_kills(vector<string>names, vector<int>kills, int total)
{
    int menu_choice;
    cout << "Please select a player to add 1 kill:" << endl;
    for (int i = 0; i < total; i++)
	{
		cout << (i + 1) << ". " << names[i] << endl;
	}
	cout << "Select and Press Enter: ";
	cin >> menu_choice;
    cout << endl;
}
