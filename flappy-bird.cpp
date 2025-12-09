#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int width = 20;
const int height = 10;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw(int birdY, int obstacleX, int gapY) {
    system("cls");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1) {
                cout << "|";
            } else if (x == obstacleX && (y < gapY || y > gapY + 2)) {
                cout << "#";
            } else if (x == 5 && y == birdY) {
                cout << "O";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int birdY = height / 2;
    int obstacleX = width - 1;
    int gapY = rand() % (height - 4) + 1;
    int score = 0;
    bool gameOver = false;

    while (!gameOver) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ') {
                birdY -= 2; // jump
            }
        }

        birdY++;
        obstacleX--;

        if (obstacleX < 0) {
            obstacleX = width - 1;
            gapY = rand() % (height - 4) + 1;
            score++;
        }

        if (birdY >= height || birdY < 0 || (obstacleX == 5 && (birdY < gapY || birdY > gapY + 2))) {
            gameOver = true;
        }

        draw(birdY, obstacleX, gapY);
        cout << "Score: " << score << endl;
        Sleep(100);
    }

    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}
  
