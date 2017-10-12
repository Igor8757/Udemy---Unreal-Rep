#include <iostream>
#include <string>
#include "FBullCowGame.h"

using namespace std;

constexpr int WORD_LENGTH = 5;
constexpr int NUM_OF_TURNS = 5;

void printIntro();
void playGame();
string getGuess();
bool askToPlayAgain();

int main() {
	bool playAgain = false;
	do {
		printIntro();
		playGame();
		playAgain = askToPlayAgain();
		cout << "\n";
	}
	while (playAgain);
	return 0;
}

void playGame(){
	for (int i = 0; i <= NUM_OF_TURNS; i++) {
		cout << getGuess() << "\n";
	}
}

void printIntro() {
	cout << "Welcome to Bulls and Cows! a fun word game\n";
	cout << "can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
}

string getGuess() {
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

bool askToPlayAgain(){
	cout << "Do you want to play again?"; 
	string response = "";
	getline(cin, response);
	return (response[0] == 'Y') || (response[0] == 'y');
	}
