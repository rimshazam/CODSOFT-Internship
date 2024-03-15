//CODSOFT INTERSHIP
//TASK 01 : NUMBER GUESSING GAME

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//int main()
//{
//    srand(time(0));
//    int num = (rand() % 50) + 1;
//    int numGuesses = 1;
//    int guess = -1;
//
//    cout << ">>>>> **** NUMBER GUESSING GAME **** <<<<<" << endl;
//    cout << "\nA random number has been generated between 1-50." << endl;
//    cout << "You have to guess the number.\n\nEnter your guess : ";
//    cin >> guess;
//
//    while (guess != num)
//    {
//        //IF GUESS IS OUT OF BOUNDS
//        if (guess < 1 || guess > 50)
//        {
//            cout << "Your guess is OUT OF BOUNDS specified" << endl;
//            goto here;
//        }
//        else
//        {
//            //IF GUESS IS HIGH
//            if (guess > num)
//            {
//                if (guess - num >= 20)
//                {
//                    cout << "Your guess is VERY HIGH" << endl;
//                }
//                else if (guess - num >= 5 && guess - num <20)
//                {
//                    cout << "Your guess is HIGH" << endl;
//                }
//                else if (guess - num < 5)
//                {
//                    cout << "You are close! Your guess is LITTLE HIGH" << endl;
//                }
//            }
//            // IF GUESS IS LOW
//            else if (guess < num)
//            {
//                if (num - guess >= 20)
//                {
//                    cout << "Your guess is VERY LOW" << endl;
//                }
//                else if (num - guess >= 5 && num - guess <20)
//                {
//                    cout << "Your guess is LOW" << endl;
//                }
//                else if (num - guess < 5)
//                {
//                    cout << "You are close! Your guess is LITTLE LOW" << endl;
//                }
//            }
//        }
//        here:
//        cout << "\nMake another guess : ";
//        cin >> guess;
//        numGuesses++;
//    }
//
//    cout << "\n>>> *** CONGRATULATIONS *** <<<\nYou guessed it right in " << numGuesses << " guesses!!\nThe number is " << num << endl;
//    return 0;
//}


