//
//  FBullAndCowGame.hpp
//  BullsandCows
//
//  Created by Oliver Clutterbuck on 21/02/2018.
//  Copyright © 2018 Oliver Clutterbuck. All rights reserved.
//
#pragma once

#ifndef FBullAndCowGame_hpp
#define FBullAndCowGame_hpp

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCount {
    
    int32 bulls = 0;
    int32 cows = 0;
    
};

enum class EGuessStatus {
    OK,
    ERR_WORD_LENGTH,
    ERR_NOT_ISOGRAM,
    ERR_NOT_LOWERCASE
};

class FBullAndCowGame {

public:
    FBullAndCowGame();
    
    int32 GetCurrentTry() const;
    int32 GetMaxTries() const;
    bool IsGameWon() const;
    int32 GetHiddenWordLength() const;
    
    void ResetGame();
    EGuessStatus CheckGuessValidity(FString guess);
    FBullCount SubmitGuess(FString guess);
    

private:
    
    int32 maxTries;
    int32 numberOfTries;
    FString hiddenWord;
    bool bIsGameWon;
    
    bool IsIsogram(FString guess) const;
    
};


#endif /* FBullAndCowGame_hpp */
