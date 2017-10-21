
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using namespace std;
using FText = std::string;

constexpr int32 WORD_LENGTH = 5;
constexpr int32 NUM_OF_TURNS = 5;

void printIntro();
void playGame();
FText getValidGuess();
bool askToPlayAgain();
void printGameSummary();

FBullCowGame BCGame;

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

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText guess = getValidGuess();
		FBullCowCount bullCowCount = BCGame.SubmitGuess(guess);
		cout << "Bulls: " << bullCowCount.Bulls;
		cout << " Cows: " << bullCowCount.Cows << "\n\n";
	}
	printGameSummary();
}

void printGameSummary() {
	if (BCGame.IsGameWon()) {
		cout << "You WON!!!\n";
	}
	else {
		cout << "You LOST..\n";

	}
}

void printIntro() {
	cout << "\nWelcome to Bulls and Cows! a fun word game\n";
	cout << "can you guess the " << BCGame.GetHiddenWordLength();
	cout << " letter isogram I'm thinking of?\n";
}

FText getValidGuess() {
	EWordStatus Status = EWordStatus::Invalid;
	FText Guess;
	while(Status != EWordStatus::OK){
		int32 currTry = BCGame.GetCurrentTry();
		cout << "Try: " << currTry << endl;
		cout << "Enter your guess: \n";
		Guess = "";
		getline(cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EWordStatus::Wrong_Length:
			cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EWordStatus::Not_Isogram:
			cout << "Please enter a word without repeating letters\n";
			break;
		case EWordStatus::Not_Lowercase:
			cout << "Please enter an all lowercase word.\n";
			break;
		default:
			break;
		}
	}
	return Guess;
}

bool askToPlayAgain(){
	cout << "Do you want to play again?"; 
	FText response = "";
	getline(cin, response);
	return (response[0] == 'Y') || (response[0] == 'y');
	}
