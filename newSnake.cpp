#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

//w & h of a game field
const int width = 80;
const int height = 20;
//snake head coords
int x, y;
//food coords
int fruitCordX, fruitCordY;
//
int playerScore;
//arr to store coords of snake tail
int snakeTailX[100], snakeTailY[100];
//
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
  playerScore = 0;
}

void gameRender(string playerName) {
  system("cls");

  //creating top walls with symblol -
  for (int iteration = 0; iteration < width + 2; ++iteration) {
    cout << "-";
  }

  cout << endl;

  //hardcore part

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

void updateGameLogic() {
  int prevX = snakeTailX[0];
  int prevY = snakeTailY[0];
  int prevX1, prevY1;
  snakeTailX[0] = x;
  snakeTailY[0] = y;

  for (int iteration = 1; iteration < snakeTailLen; ++iteration) {
    prevX1 = snakeTailX[iteration];
    prevY1 = snakeTailY[iteration];
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
    snakeTailLen++;
  }
}

int setDifficulty() {
  int difficulty, choice;
  cout << "\nSet difficulty (snake speed)\n1: Easy (slow)\n2: Medium (normal)\n3: Hard (fast) "
          "\nIf not set, it will be medium (normal) "
          "\nChoose difficulty lvl: ";
  cin >> choice;

  switch (choice) {
    case '1':
      difficulty = 50;
      break;

    case '2':
      difficulty = 100;
      break;

    case '3':
      difficulty = 150;
      break;

    default:
      difficulty = 100;
      break;
  }
  return difficulty;
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
  int difficulty = setDifficulty();

  gameInit();
  while (!isGameOver) {
    gameRender(playerName);
    userInput();
    updateGameLogic();
    Sleep(difficulty);

  }

  return 0;
}

