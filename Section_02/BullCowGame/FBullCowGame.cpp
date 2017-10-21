#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	myCurrentTry = 1;
	myMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;
	bGameWon = false;
}

int32 FBullCowGame::GetMaxTries() const {	return myMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {	return myCurrentTry;}

int32 FBullCowGame::GetHiddenWordLength() const{	return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const
{
	return bGameWon;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!isIsogram(guess)) {
		return EWordStatus::Not_Isogram;
	}
	else if (!isLowercase(guess)) {
		return EWordStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLength()) {
		return EWordStatus::Wrong_Length;
	}
	else {
		return EWordStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	FBullCowCount bullCowCount;
	int32 hwlen = MyHiddenWord.length();
	int32 glen = guess.length();
	myCurrentTry++;
	for (int32 i = 0; i < hwlen; i++) {
		for (int32 j = 0; j <hwlen; j++) {
			if (guess[i] == MyHiddenWord[j]) {
				if (i == j) bullCowCount.Bulls++;
				else bullCowCount.Cows++;
			}	
		}
	}
	if (bullCowCount.Bulls == hwlen) bGameWon = true;
	else bGameWon = false;
	return bullCowCount;
}

bool FBullCowGame::isIsogram(FString guess) const
{
	if (guess.length() <= 1) return true;
	TMap<char, bool> LetterSeen;
	for (auto letter : guess) {
		letter = tolower(letter);
		if (LetterSeen[letter]) {
			return false;
		}
		else {
			LetterSeen[letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::isLowercase(FString guess) const
{
	for (auto letter : guess) {
		if (letter >= 'A' && letter <= 'Z') return false;
	}
	return true;
}
