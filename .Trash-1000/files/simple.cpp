#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // For rand()
using namespace std;

int x = 5, y = 5;       // Player
int targetX = 3, targetY = 7; // Target
bool gameOver = false;

void Draw() {
    system("cls");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == y && j == x) cout << "@";
            else if (i == targetY && j == targetX) cout << "*";
            else cout << ".";
        }
        cout << endl;
    }
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': x--; break;
            case 'd': x++; break;
            case 'w': y--; break;
            case 's': y++; break;
            case 'x': gameOver = true; break;
        }
    }
}

void Logic() {
    x = max(0, min(x, 9));
    y = max(0, min(y, 9));

    if (x == targetX && y == targetY) {
        targetX = rand() % 10;
        targetY = rand() % 10;
    }
}

int main() {
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    return 0;
}