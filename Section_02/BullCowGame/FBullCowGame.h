#include <string>
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus {
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public:
	FBullCowGame(); // ctor

	void Reset(); // TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EWordStatus CheckGuessValidity(FString) const;
	// counts bulls and cows, and increases try number.
	FBullCowCount SubmitGuess(FString);
private:
	int32 myCurrentTry;
	int32 myMaxTries;
	bool bGameWon;
	FString MyHiddenWord;
	bool isIsogram(FString) const;
	bool isLowercase(FString) const;
};