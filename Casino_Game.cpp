
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawLine(int n, char symbol);
void displayRules();

int main() {
    string playerName;
    int amount, bettingAmount, guess, dice;
    char choice;

    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60, '_');

    cout << "\n\nEnter your name: ";
    getline(cin, playerName);

    cout << "\n\nEnter money to play the game: $";
    cin >> amount;

    do {
        system("cls"); // Clear screen
        displayRules();
        cout << "\n\nYour current balance is $" << amount << "\n";

        // Getting player's betting amount
        do {
            cout << playerName << ", enter money to bet: $";
            cin >> bettingAmount;
            if (bettingAmount > amount) {
                cout << "Your betting amount is more than your current balance\n"
                     << "Re-enter data\n";
            }
        } while (bettingAmount > amount);

        // Getting player's guess
        do {
            cout << "Guess a number between 1 to 10: ";
            cin >> guess;
            if (guess < 1 || guess > 10) {
                cout << "Please check the number! It should be between 1 and 10\n"
                     << "Re-enter data\n";
            }
        } while (guess < 1 || guess > 10);

        // Generate random number between 1 and 10
        dice = rand() % 10 + 1;
        if (dice == guess) {
            cout << "\n\nGood luck! You won $" << bettingAmount * 10 << "\n";
            amount += bettingAmount * 10; // Update balance
        } else {
            cout << "Bad luck! You lost $" << bettingAmount << "\n";
            amount -= bettingAmount; // Update balance
        }

        cout << "The winning number was: " << dice << "\n";
        cout << playerName << ", you have $ " << amount << "\n";

        if (amount <= 0) {
            cout << "You have no money to play. Game over.\n";
            break;
        }

        cout << "\n\nDo you want to play again (y/n)? ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing! Your current balance is $" << amount << "\n\n";

    return 0;
}

void drawLine(int n, char symbol) {
    cout << string(n, symbol) << "\n"; // Use string constructor for simplicity
}

void displayRules() {
    system("cls"); // Clear screen
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80, '-');
    cout << "\t1. Choose any number between 1 and 10\n";
    cout << "\t2. If you win, you will get 10 times your bet amount\n";
    cout << "\t3. If you bet on the wrong number, you will lose your betting amount\n\n";
    drawLine(80, '-');
}
