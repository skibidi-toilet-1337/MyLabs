/***********************
 * Автор: Бобкова Е.А. *
 ***********************/

#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

const int width = 80;
const int height = 20;
int bombTimer;
int prevTime;

//snake head coords
int x, y;

//food coords
int fruitCordX, fruitCordY;

//spike coords
int bombCordX, bombCordY;

int playerScore;

//arr to store coords of snake tail
int snakeTailX[100], snakeTailY[100];

int snakeTailLen;
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
snakesDirection sDir;
bool isGameOver;

void gameInit() {
  isGameOver = false;
  sDir = STOP;
  x = width / 2;
  y = height / 2;
  //generating random cords for fruit in game field
  fruitCordX = rand() % width;
  fruitCordY = rand() % height;

  //gen rand cords for bomb
  bombCordX = rand() % width;
  bombCordY = rand() % height;
  bombTimer = 3000;
  prevTime = GetTickCount();
  playerScore = 0;
}

void gameRender(string playerName) {
  system("cls");

  //creating top walls with symblol -
  for (int iteration = 0; iteration < width + 2; ++iteration) {
    cout << "-";
  }
  cout << endl;

  //creating game field
  for (int iterationX = 0; iterationX < height; ++iterationX) {
    for (int iterationY = 0; iterationY <= width; ++iterationY) {
      //creating side walls with symbol |
      if (iterationY == 0 || iterationY == width) {
        cout << "|";
      }

      //snake's head
      if (iterationX == y && iterationY == x) {
        cout << "@";
      }

      //fruit
      else if (iterationX == fruitCordY && iterationY == fruitCordX) {
        cout << "q";
      } 
      
      else if (iterationX == bombCordY && iterationY == bombCordX) {
        cout << "*";
      }

      else {
        bool prTail = false;
        for (int iter = 0; iter < snakeTailLen; ++iter) {
          if (snakeTailX[iter] == iterationY && snakeTailY[iter] == iterationX) {
            cout << "o";
            prTail = true;
          }
        }
        if (!prTail) {
          cout << " ";
        }
      }
    }
    cout << endl;
  }

  //creating bottom walls with symbol -
  for (int iteration = 0; iteration < width + 2; ++iteration) {
    cout << "-";
  }

  cout << endl;
  cout << playerName << "'s Score: " << playerScore << endl;

}

void bombGen() {
  
  bombCordX = rand() % width;
  bombCordY = rand() % height;
  /**for (int second = 3; second > 0; --second) {
    bombCordX = rand() % width;
    bombCordY = rand() % height;
    this_thread::sleep_for(chrono::seconds(1));

  }*/
  //Sleep(3000);

}

void updateGameLogic() {

  int currTime = GetTickCount();
  int delta = currTime - prevTime;
  prevTime = currTime;

  int prevX = snakeTailX[0];
  int prevY = snakeTailY[0];
  int prevX1, prevY1;
  snakeTailX[0] = x;
  snakeTailY[0] = y;

  for (int iteration = 1; iteration < snakeTailLen; ++iteration) {
    prevX1 = snakeTailX[iteration];
    prevY1 = snakeTailY[iteration];
    snakeTailX[iteration] = prevX;
    snakeTailY[iteration] = prevY;
    prevX = prevX1;
    prevY = prevY1;
  }

  switch (sDir) {
  case LEFT:
    x--;
    break;
  case RIGHT:
    x++;
    break;
  case UP:
    y--;
    break;
  case DOWN:
    y++;
    break;

  }

  //check collision with wall
  if (x >= width || x < 0 || y >= height || y < 0) {
    isGameOver = true;
  }

  //check collision with tail
  for (int tailSegment = 0; tailSegment < snakeTailLen; ++tailSegment) {
    if (snakeTailX[tailSegment] == x && snakeTailY[tailSegment] == y) {
      isGameOver = true;
    }
  }

  //check collision with fruits
  if (x == fruitCordX && y == fruitCordY) {
    playerScore += 10;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    ++snakeTailLen;
  } else if (x == bombCordX && y == bombCordY) {
    isGameOver = true;
  }
  
  if (bombTimer > delta) {
    bombTimer -= delta;

  } else {
    bombGen();
    bombTimer = 3000;
  }
  
}



void userInput() {
  if (_kbhit()) {
    switch (_getch()) {
    case 'a':
      sDir = LEFT;
      break;
    case 'd':
      sDir = RIGHT;
      break;
    case 'w':
      sDir = UP;
      break;
    case 's':
      sDir = DOWN;
      break;
    case 'x':
      isGameOver = true;
      break;
    }
  }
}

int main() {

  string playerName;
  cout << "Enter your name: ";
  cin >> playerName;

  gameInit();

  while (!isGameOver) {
    gameRender(playerName);
    userInput();
    updateGameLogic();
    Sleep(100);
  }

  //system("cls");
  cout << "GAME OVER";

  return 0;
}