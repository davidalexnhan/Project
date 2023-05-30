#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Function to set the console window size
void SetConsoleWindowSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = {0, 0, width - 1, height - 1};
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    COORD coord = {width, height};
    SetConsoleScreenBufferSize(hConsole, coord);
}

// Function to set the cursor position in the console
void SetCursorPosition(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(hConsole, coord);
}

int main()
{
    const int width = 40;    // Width of the game window
    const int height = 20;   // Height of the game window
    int paddleWidth = 4;     // Width of the paddles
    int paddleHeight = 1;    // Height of the paddles
    int ballPositionX = width / 2;
    int ballPositionY = height / 2;
    int ballDirectionX = -1;
    int ballDirectionY = -1;
    int player1PositionY = height / 2 - paddleHeight / 2;
    int player2PositionY = height / 2 - paddleHeight / 2;
    int player1Score = 0;
    int player2Score = 0;

    // Set console window size
    SetConsoleWindowSize(width, height + 2);

    // Hide cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    // Game loop
    while (true)
    {
        // Clear screen
        system("cls");

        // Draw paddles
        for (int y = player1PositionY; y < player1PositionY + paddleHeight; ++y)
        {
            SetCursorPosition(0, y);
            cout << "|";
        }
        for (int y = player2PositionY; y < player2PositionY + paddleHeight; ++y)
        {
            SetCursorPosition(width - 1, y);
            cout << "|";
        }

        // Draw ball
        SetCursorPosition(ballPositionX, ballPositionY);
        cout << "O";

        // Draw score
        SetCursorPosition(width / 2 - 1, 0);
        cout << player1Score << " - " << player2Score;

        // Move ball
        ballPositionX += ballDirectionX;
        ballPositionY += ballDirectionY;

        // Ball collision with paddles
        if (ballPositionX == 1 && ballPositionY >= player1PositionY && ballPositionY < player1PositionY + paddleHeight)
        {
            ballDirectionX = 1;
        }
        else if (ballPositionX == width - 2 && ballPositionY >= player2PositionY && ballPositionY < player2PositionY + paddleHeight)
        {
            ballDirectionX = -1;
        }

        // Ball collision with walls
        if (ballPositionX == 0 || ballPositionX == width - 1)
        {
            // Check if the ball is at the top or bottom wall
            if (ballPositionY == 0 || ballPosition

