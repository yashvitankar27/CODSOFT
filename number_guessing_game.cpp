#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    int randomNumber = std::rand() % 100 + 1;

    int guess;
    bool guessedCorrectly = false;

    std::cout << "Guess the number (between 1 and 100): ";

    while (!guessedCorrectly) {
        std::cin >> guess;

        if (guess < randomNumber) {
            std::cout << "Too low. Guess again: ";
        } else if (guess > randomNumber) {
            std::cout << "Too high. Guess again: ";
        } else {
            std::cout << "Congratulations! You guessed the number correctly!" << std::endl;
            guessedCorrectly = true;
        }
    }

    return 0;
}

