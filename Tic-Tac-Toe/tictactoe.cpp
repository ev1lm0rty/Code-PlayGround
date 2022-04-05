/*
 * @author: shubham.arya
 * @date: 04-apr-2022
*/

#include <iostream>
using namespace std;

void printGrid(char table[3][3]){
  cout << "Welcome to TIC-TAC-TOE !!" << endl << endl;
  cout << "| " << table[0][0] << " | " << table[0][1] << " | " << table [0][2] << " | " << endl;
  cout << "| " << table[1][0] << " | " << table[1][1] << " | " << table [1][2] << " | " << endl;
  cout << "| " << table[2][0] << " | " << table[2][1] << " | " << table [2][2] << " | " << endl;
  cout << endl;

}


bool checkWinner(char table[3][3]){
  char winner = false;
  /* Diagonals */
  if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
    winner = table[0][0];
  else if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
    winner = table[0][2];

  /* Horizontals */
  else if (table[0][0] == table[1][0] && table[1][0] == table[2][0])
    winner = table[0][0];
  else if (table[0][1] == table[1][1] && table[1][1] == table[2][1])
    winner = table[0][1];
  else if (table[0][2] == table[1][2] && table[1][2] == table[2][2])
    winner = table[0][2];

  /* Verticals */
  else if (table[0][0] == table[0][1] && table[0][1] == table[0][2])
    winner = table[0][0];
  else if (table[1][0] == table[1][1] && table[1][1] == table[1][2])
    winner = table[1][0];
  else if (table[2][0] == table[2][1] && table[2][1] == table[2][2])
    winner = table[2][0];

  else 
    winner = 'n';

  if (winner != 'n'){
    cout << "WINNER IS PLAYER " << winner << endl;
    return true;
  }
  else
    return false;

}

int main(){
  char player[2] = {'X', 'O'};
  int chances = 9;
  int winner = 0 ; 
  int current = 0;
  int flag = 0;
  char input;
  char table[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
  };

  cout << "\033[2J\033[1;1H";

  printGrid(table);

  while ( winner != 0 || chances > 0 ){
    cout << "Player " << player[current] << " move: " ; 
    current = current ^ 1 ;
    cin >> input ;
    cout << endl;
    chances--;

    /* Replace position with current player's symbol */
    for (int i = 0 ; i < 3 ; i ++){
      for (int j = 0 ; j < 3 ; j++){
        if (input == table[i][j]){
            table[i][j] = player[current ^ 1];
            flag = 1;
            break;
        }
      }
    }

    if (flag == 0 ){
      cout << "Wrong Move !!, Try Again " << endl;
      chances++;
      current = current ^ 1;
    }

    /* Print the table */
    flag = 0;
    cout << "\033[2J\033[1;1H";
    printGrid(table);

    /* Check winner */
    if (checkWinner(table))
      break;
  }

  if (chances == 0)
    cout << "IT's a TIE" << endl;
  return 0;
}
