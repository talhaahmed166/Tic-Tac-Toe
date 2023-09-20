#include <iostream>
#include <locale> // Required for setting the locale

using namespace std;

// Function to clear the console screen (for a cleaner appearance)
void clearScreen()
{
    cout << "\x1b[2J\x1b[H";
}

// Function to print the Tic-Tac-Toe board with colors and formatting
void print(int arr[][3], int size)
{
    clearScreen();
    // cout << "\x1b[36m"; // Cyan background color for the entire board

    for (int i = 0; i < size; i++)
    {
        cout << "\x1b[34m  |  \x1b[0m";
        for (int j = 0; j < size; j++)
        {
            int value = arr[i][j];
            if (value == 0)
            {
                cout << "\x1b[43m\x1b[30m   \x1b[0m"; // Yellow background for 0
            }
            else if (value == 1)
            {
                cout << "\x1b[41m\x1b[30m X \x1b[0m"; // Red background for 1
            }
            else if (value == 2)
            {
                cout << "\x1b[42m\x1b[30m ○ \x1b[0m"; // Green background for 2
            }
            if (j < size - 1)
            {
                cout << "\x1b[34m  |  \x1b[0m";
            }
        }
        cout << endl;
        if (i < size - 1)
        {
            cout << "\x1b[34m---------------------------\x1b[0m" << endl;
        }
    }
    cout << "\x1b[0m"; // Reset colors
}

int main()
{
    const int size = 3;
    int row, column;
    bool player1 = true;
    bool player2 = false;
    int arr[size][size] = {0};

    // Ensure that the console supports Unicode output
    setlocale(LC_ALL, "");

    cout << "\x1b[34m"; // Blue background color for the game title
    cout << "TIC-TAC-TOE" << endl;
    cout << "\x1b[0m"; // Reset colors

    print(arr, size);

    for (int i = 0; i < size * size; i++)
    {
        while (player1 == true)
        {
            cout << "\x1b[31mPlayer 1\x1b[0m:  ";
            cin >> row;
            cin >> column;
            if (arr[row][column] == 0 && row < size && column < size)
            {
                arr[row][column] = 1;
                player1 = false;
                player2 = true;
                print(arr, size);
                if (arr[0][0] == 1 && arr[0][1] == 1 && arr[0][2] == 1 || arr[0][0] == 1 && arr[1][0] == 1 && arr[2][0] == 1 || arr[0][1] == 1 && arr[1][1] == 1 && arr[2][1] == 1 || arr[0][2] == 1 && arr[1][2] == 1 && arr[2][2] == 1 || arr[1][0] == 1 && arr[1][1] == 1 && arr[1][2] == 1 || arr[2][0] == 1 && arr[2][1] == 1 && arr[2][2] == 1 || arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1 || arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1)
                {
                    cout<<endl;
                    cout << "\x1b[42m\x1b[30m Congratulations... Player 1 WON!!! \x1b[0m";
                    player1 = false;
                    player2 = false;
                }
            }
            else
            {
                cout << "Invalid input. Please enter again." << endl;
                player1 = true;
                player2 = false;
            }
        }
        while (player2 == true)
        {
            cout << "\x1b[32mPlayer 2\x1b[0m: ";
            cin >> row;
            cin >> column;
            if (arr[row][column] == 0 && row < size && column < size)
            {
                arr[row][column] = 2;
                player1 = true;
                player2 = false;
                print(arr, size);
                if (arr[0][0] == 2 && arr[0][1] == 2 && arr[0][2] == 2 || arr[0][0] == 2 && arr[1][0] == 2 && arr[2][0] == 2 || arr[0][1] == 2 && arr[1][1] == 2 && arr[2][1] == 2 || arr[0][2] == 2 && arr[1][2] == 2 && arr[2][2] == 2 || arr[1][0] == 2 && arr[1][1] == 2 && arr[1][2] == 2 || arr[2][0] == 2 && arr[2][1] == 2 && arr[2][2] == 2 || arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2 || arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 2)
                {
                    cout<<endl;
                    cout << "\x1b[42m\x1b[30m Congratulations... Player 2 WON!!! \x1b[0m";
                    player1 = false;
                    player2 = false;
                }
            }
            else
            {
                cout << "Invalid input. Please enter again." << endl;
                player1 = false;
                player2 = true;
            }
        }
    }
    cout << endl;

    return 0;
}