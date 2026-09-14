#include <iostream>
#include <random>
#include <string>


int main() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> computerChoice(1, 4); // 1: rock, 2: paper, 3: scissors, 4: gun
    
    std::cout << "Rock, Paper, Scissors\n";
    std::cout << "Enter rock, paper, scissors, or quit.\n";

    int playerscore = 0;
    int computerscore = 0;

    while (true) {
        string player;
        std::cout << "\nYour choice: ";
        std::cin >> player;

        if (player == "quit") {
            break;
        }

        int playerChoice;
        if (player == "rock") {
            playerChoice = 1;
        } else if (player == "paper") {
            playerChoice = 2;
        } else if (player == "scissors") {
            playerChoice = 3;
        } 
            else if (player == "gun") { 
            playerChoice = 4;
        }
        else {
            std::cout << "Invalid choice.\n";
            continue;
        }

        int computer = computerChoice(generator);
        const std::string names[] = {"", "rock", "paper", "scissors", "gun"};
        std::cout << "Computer chose " << names[computer] << ".\n";

        if (playerChoice == computer) {
            std::cout << "It's a tie!\n";
        } else if ((playerChoice == 1 && computer == 3) ||
                   (playerChoice == 2 && computer == 1) ||
                   (playerChoice == 3 && computer == 2) ||
                   (playerChoice == 4 && computer != 4)) {
            std::cout << "You win!\n";
            playerscore++;
        } else {
            std::cout << "You lose!\n";
            computerscore++;
        }
        
    }

    std::cout << "Final Score - You: " << playerscore << ", Computer: " << computerscore << "\n";
    std::cout << "Thanks for playing!\n";
    return 0;
}