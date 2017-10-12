#include <iostream>
#include <string>

using namespace std;

constexpr int WORD_LENGTH = 5;
constexpr int NUM_OF_TURNS = 5;

void printIntro();
string getGuess();


int main() {
	printIntro();
	for (int i = 0; i <= NUM_OF_TURNS; i++) {
		cout << getGuess() << "\n";
	}
	
	return 0;
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