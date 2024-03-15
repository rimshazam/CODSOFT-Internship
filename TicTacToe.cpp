#include<iostream>
#include<chrono> // For std::chrono::seconds
#include<thread> // For std::this_thread::sleep_for
#ifdef _WIN32
#include <windows.h> // For Windows
#endif
using namespace std;

// >> FUNCTION CLEARS SCREEN 
void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#endif
}

// >> FUNCTION ADDS DELAY IN SECONDS <<
void delay(int seconds)
{
    this_thread::sleep_for(chrono::seconds(seconds));
}

// >> FUNCTION DISPLAYS THE BOARD <<
void displayBOARD(char arr[3][3])
{
    cout << endl << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// >> FUNCTION CHECKS IF A PLAYER HAS WON <<
int check(char arr[3][3])
{
    char p1 = 'x';
    char p2 = 'o';
    bool Player1winss = false;
    bool Player2winss = false;

    int h1, v1, ld1, rd1, h2, v2, ld2, rd2;
    h1 = v1 = ld1 = rd1 = h2 = v2 = ld2 = rd2 = 0;

    // CHECKS HORIZONTALLY AND VERTICALLY
    for (int i = 0; i < 3; i++)
    {
        h1 = v1 = h2 = v2 = 0; // Reset counters for each row and column
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == p1)
            {
                h1++;
            }
            if (arr[i][j] == p2)
            {
                h2++;
            }
            if (arr[j][i] == p1)
            {
                v1++;
            }
            if (arr[j][i] == p2)
            {
                v2++;
            }
        }

        if (h1 == 3 || v1 == 3)
        {
            Player1winss = true; // if player 1 wins, return 1
            return 1;
        }

        if (h2 == 3 || v2 == 3)
        {
            Player2winss = true; // if player 2 wins, return 2
            return 2;
        }
    }

    // CHECKS LEFT DIAGONAL
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][i] == p1)
        {
            ld1++;
        }
        else if (arr[i][i] == p2)
        {
            ld2++;
        }
    }

    if (ld1 == 3)
    {
        Player1winss = true;
        return 1;
    }
    else if (ld2 == 3)
    {
        Player2winss = true;
        return 2;
    }

    // CHECKS RIGHT DIAGONAL
    rd1 = rd2 = 0; // RESETS COUNTER FOR right diagnol
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][2 - i] == p1)
        {
            rd1++;
        }
        else if (arr[i][2 - i] == p2)
        {
            rd2++;
        }
    }

    if (rd1 == 3) {
        Player1winss = true;
        return 1;
    }
    else if (rd2 == 3) {
        Player2winss = true;
        return 2;
    }

    return -1; // NO WINNER YET
}

// >> FUNCTION MOVES PLAYER <<
bool move(char arr[3][3], char p, int r, int c)
{
    if (arr[r][c] == ' ')
    {
        arr[r][c] = p;
        return true;
    }
    cout << "\nINVALID MOVE, Cell is already occupied.\n" << endl;
    delay(1.5);
    return false;
}

// >> FUNCTION CHECKS IF GAME IS DRAW <<
bool draw(char arr[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == ' ')
            {
                return false;
            }
        }
    }
    cout << "\n It's a DRAW \n\n ******* GAME OVER *******" << endl;
    return true;
}

// >> MAIN FUNCTION <<
int main()
{
    char values[3][3];
    char player = 'x';
    char playAgain;

    do {
        // ASSIGNING VALUES
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                values[i][j] = ' ';
            }
        }

        cout << ">>>>> **** TIC TAC TOE **** <<<<<" << endl;

        while (true)
        {
            //CLEARS SCREEN
            clearScreen();

            cout << ">>>>> **** TIC TAC TOE **** <<<<<" << endl;

            //DISPLAYS BOARD
            displayBOARD(values);
            cout << endl;

            //TAKING MOVE INPUTS
            int r, c;

            cout << "\nPlayer \'" << player << "\', Enter your move\n";
            cout << "Row ( 1, 2, 3) : ";
            cin >> r;
            r -= 1;

            cout << "Col ( 1, 2, 3) : ";
            cin >> c;
            c -= 1;

            //INPUT VALIDATION OFR INDEXES
            if (r > 2 || r < 0 || c>2 || c < 0)
            {
                cout << "\nINVALID MOVE ~~ Enter again" << endl;
                delay(1.5);
                continue;
            }

            //IF MOVE NOT MADE 
            if (!move(values, player, r, c))
            {
                continue;
            }

            //CHECKS GAME STATUS ( CONTINUE / WON )
            int status = check(values);

            if (status == 1 || status == 2)
            {
                displayBOARD(values);
                cout << "\nPLAYER '" << player << "' WINS!! \n*** CONGRATULATIONS ***" << endl;
                break;
            }

            //CHECKS IF GAME IS DRAW
            if (draw(values))
            {
                break;
            }

            // SWITCHES PLAYER
            player = (player == 'x') ? 'o' : 'x';
        }

        //ASKS IF YOU WANNA PLAY AGAIN
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
        player = 'x'; // Reset player for the new game
    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nTHANK YOU FOR PLAYING TIC TAC TOE!\n";
    return 0;
}
