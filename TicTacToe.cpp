//
//  main.cpp
//  TicTacToe
//
//  Created by Allie Tennyson on 11/11/18.
//  Copyright © 2018 Allie Tennyson. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void buildBoard();
string move(string position_x, int position_y);
void updateBoard(string position, int &player_value);

int main() {
  
  int player = 0;
  
  string position_x;
  int position_y;
  string position;
  
  buildBoard();
  
  while(true)
  {
    cout << "Enter an X or Q to quit: ";
    cin >> position_x;
    
    if (position_x == "q")
      break;
    
    cout << "Enter a Y: ";
    cin >> position_y;
    
    position = move(position_x, position_y);
    
    updateBoard(position, player);
    
    //Change Player
    if (player == 1)
      player = 0;
    else if (player == 0)
      player = 1;
  }
  
  return 0;
}

void buildBoard(string &position)
{
  cout << "    a" << "   b " << "  c" << "\n \n";
  cout << "1   " << position << " | " << " " << " | " << " " << "\n";
  cout << "   ----------- \n";
  cout << "2   " << " " << " | " << " " << " | " << " " << "\n";
  cout << "   ----------- \n";
  cout << "3   " << " " << " | " << " " << " | " << " " << "\n \n";
}

void updateBoard(string position, int &player_value)
{
  //0 = X
  //1 = O
  
  //position = a1, a2, a3, b1, b2, b3, c1, c2, c3
  
  string player = " ";
  
  if (player_value == 0)
    player = "X";
  else if (player_value == 1)
    player = "O";
  
  switch (player_value) {
    case 0:
      if (position == "a1")
        position_a1 = player;
      else if (position == "a2")
        position_a2 = player;
      else if (position == "a3")
        position_a3 = player;
      else if (position == "b1")
        position_b1 = player;
      else if (position == "b2")
        position_b2 = player;
      else if (position == "b3")
        position_b3 = player;
      else if (position == "c1")
        position_c1 = player;
      else if (position == "c2")
        position_c2 = player;
      else if (position == "c3")
        position_c3 = player;
      break;
    case 1:
      if (position == "a1")
        position_a1 = player;
      else if (position == "a2")
        position_a2 = player;
      else if (position == "a3")
        position_a3 = player;
      else if (position == "b1")
        position_b1 = player;
      else if (position == "b2")
        position_b2 = player;
      else if (position == "b3")
        position_b3 = player;
      else if (position == "c1")
        position_c1 = player;
      else if (position == "c2")
        position_c2 = player;
      else if (position == "c3")
        position_c3 = player;
      break;
    default:
      break;
  }
  
  cout << "    a" << "   b " << "  c" << "\n \n";
  cout << "1   " << position_a1 << " | " << position_b1 << " | " << position_c1 << "\n";
  cout << "   ----------- \n";
  cout << "2   " << position_a2 << " | " << position_b2 << " | " << position_c2 << "\n";
  cout << "   ----------- \n";
  cout << "3   " << position_a3 << " | " << position_b3 << " | " << position_c3 << "\n \n";
}

string move(string position_x, int position_y)
{
  //position_x = a, b, c
  //position_y = 1, 2, 3
  
  string position = " ";
  switch (position_y) {
    case 1:
      if (position_x == "a")
        position = "a1";
      else if (position_x == "b")
        position =  "b1";
      else if (position_x == "c")
        position =  "c1";
      break;
    case 2:
      if (position_x == "a")
        position =  "a2";
      else if (position_x == "b")
        position =  "b2";
      else if (position_x == "c")
        position =  "c2";
      break;
    case 3:
      if (position_x == "a")
        position =  "a3";
      else if (position_x == "b")
        position =  "b3";
      else if (position_x == "c")
        position =  "c3";
      break;
    default:
      break;
  }
  return position;
}
