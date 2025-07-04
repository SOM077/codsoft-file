

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // seeding random once

    cout << "\n===Welcome to the game  Guess The Number! ===\n";
    cout << "Guess a number between 1 and 100.\n";
    cout << "Choose a difficulty level to start playing.\n";

    while (true) {
        cout << "\nSelect Difficulty Level:\n";
        cout << "1. Easy (10 chances)\n";
        cout << "2. Medium (7 chances)\n";
        cout << "3. Hard (5 chances)\n";
        cout << "0. Quit the game\n";
        cout << "User choice: ";

        int difficulty;
        cin >> difficulty;

        if (difficulty == 0) {
            cout << "Game Over! Try again later.\n";
            break;
        }

        if (difficulty < 1 || difficulty > 3) {
            cout << "Oops! Invalid choice. Try again.\n";
            continue;
        }

        int totalchances;
        if (difficulty == 1)
            totalchances = 10;
        else if (difficulty == 2)
            totalchances = 7;
        else
            totalchances = 5;

        int targetNumber = 1 + rand() % 100;
        int guess;
        bool guessedRight = false;

        cout << "\nAlright! You've got " << totalchances << " chances. Let's go!\n";

        for (int attempt = 1; attempt <= totalchances; ++attempt) {
            cout << "Attempt " << attempt << "/" << totalchances << " - Enter your guess: ";
            cin >> guess;

            if (guess == targetNumber) {
                cout << " Nice! You nailed it! The number was " << targetNumber << ".\n";
                guessedRight = true;
                break;
            } else {
                cout << "Nope! ";

                if (guess > targetNumber)
                    cout << "Try a smaller number.\n";
                else
                    cout << "Try a bigger number.\n";

                if (attempt < totalchances)
                    cout << "Attempts left: " << totalchances - attempt << "\n";
            }
        }

        if (!guessedRight) {
            cout << " Out of attempts! The number was " << targetNumber << ". Better luck next time!\n";
        }

        cout << "--------------------THANK YOU----------------------------\n";
    }

    return 0;
}


