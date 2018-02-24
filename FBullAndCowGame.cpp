//
//  FBullAndCowGame.cpp
//  BullsandCows
//
//  Created by Oliver Clutterbuck on 21/02/2018.
//  Copyright © 2018 Oliver Clutterbuck. All rights reserved.
//

#include "FBullAndCowGame.hpp"




FBullAndCowGame::FBullAndCowGame(){
    
    ResetGame();
    
}

int32 FBullAndCowGame::GetMaxTries() const {
    
    return maxTries;
    
}

int32 FBullAndCowGame::GetCurrentTry() const {
    
    return numberOfTries;
    
}

bool FBullAndCowGame::IsGameWon() const {
    
    return bIsGameWon;
    
}

int32 FBullAndCowGame::GetHiddenWordLength() const {
    
    return hiddenWord.length();
    
}

void FBullAndCowGame::ResetGame() {
    
    constexpr int32 MAX_TRIES = 10;
    maxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    hiddenWord = HIDDEN_WORD;
    
    numberOfTries = 1;
    bIsGameWon = false;
    return;
    
}

EGuessStatus FBullAndCowGame::CheckGuessValidity(FString guess) {
    
    if(!IsIsogram(guess)){
        
        return EGuessStatus::ERR_NOT_ISOGRAM;
        
    } else if(false) {
        
        return EGuessStatus::ERR_NOT_LOWERCASE;
        
    } else if(guess.length() != hiddenWord.length()){ 
        
        return EGuessStatus::ERR_WORD_LENGTH;
        
    } else {
        
        return EGuessStatus::OK;
        
    }
    
}

FBullCount FBullAndCowGame::SubmitGuess(FString guess){
    
    
    numberOfTries++;
    
    FBullCount count;
    
    int32 guessLetterCount = guess.length();
    int32 hiddenWordLetterCount = hiddenWord.length();
    
    for(int32 i = 0; i < guessLetterCount; i++){
        
        for(int32 j = 0; j < hiddenWordLetterCount; j++){
            
            if (guess[i] == hiddenWord[j]){
                
                if(i == j){
                    
                    count.bulls++;
                    
                } else {
                    
                    count.cows++;
                    
                }
                
            } else{
                
                // Letter does not match
                
            }
            
        }
        
    }
    
    if(count.bulls == 6) { bIsGameWon = true; }
    
    
    return count;
    
}

bool FBullAndCowGame::IsIsogram(FString) const{
    
    return true;
    
}
