//SSBU Tournament Project
//By Jordan Cole

#include <iostream>
#include <vector>
#include <algorithm>
#include<time.h>

using namespace std;

//Function prototypes
void shuffle_players(vector<string> vect);

int main()
{
    //Create var for player count / vector for player names
    int total_players;
    vector <string> player_name(8, "CPU");
   
   //User input for player count (must be 1-8)
   do
   {
       cout << "Please enter total number of players (1-8): ";
       cin >> total_players;
       cout << endl;
   } while (total_players < 1 || total_players > 8);
   
   //Loop to enter player names
   for (int i = 0; i < total_players; i++)
   {
       cout << "Player " << (i + 1) << ", please enter your name: ";
       cin >> player_name[i];
   }
   
   //TEST REGULAR > SHUFFLED > REGULAR > SHUFFLED
   cout << player_name[0] << endl;
   cout << player_name[1] << endl;
   cout << player_name[2] << endl;
   cout << player_name[3] << endl;
   cout << player_name[4] << endl;
   cout << player_name[5] << endl;
   cout << player_name[6] << endl;
   cout << player_name[7] << endl;
   cout << endl;
   cout << endl;
   shuffle_players (player_name);
   cout << endl;
   cout << endl;
   cout << player_name[0] << endl;
   cout << player_name[1] << endl;
   cout << player_name[2] << endl;
   cout << player_name[3] << endl;
   cout << player_name[4] << endl;
   cout << player_name[5] << endl;
   cout << player_name[6] << endl;
   cout << player_name[7] << endl;
   cout << endl;
   cout << endl;
   shuffle_players (player_name);
   
   //8-works, 7-needs 1 cpu, 6-needs 2 cpu, 5-needs 3 cpu
   //4-works, 3-needs 1 cpu, 2-needs 2 cpu, 1-needs 3 cpu
   
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
