//
//  main.cpp
//  BullsandCows
//
//  Created by Oliver Clutterbuck on 20/09/2017.
//  Copyright © 2017 Oliver Clutterbuck. All rights reserved.
//

#include <iostream>
#include "FBullAndCowGame.hpp"

using FText = std::string;
using int32 = int;


void printIntro();
FText getValidGuess();
void playGame();
void endGame();
bool AskToPlayAgain();
void SummariseGame();
FBullAndCowGame BullCowGame;



int32 main(int32 argc, const char * argv[])
{
    
    printIntro();
    playGame();
    
    return 0;
}



// Print32 int32ro text
void printIntro()
{

    std::cout << "Welcome to Bulls and Cows, a fun word game!" << "\n\n";
    std::cout << "Can you guess the "  << BullCowGame.GetHiddenWordLength()  << " letter isogram I'm thinking of?\n\n";
    std::cout << std::endl;
    return;
    
}

// Play Game
void playGame()
{
    
    do {
            BullCowGame.ResetGame();
            FBullCount results;
            FText guess;
    
            while (!BullCowGame.IsGameWon() && BullCowGame.GetCurrentTry() <= BullCowGame.GetMaxTries()){
        
                guess = getValidGuess();
                results = BullCowGame.SubmitGuess(guess);
                std::cout << "Bulls = " << results.bulls << ", Cows = " << results.cows << "\n\n";
        
            }
        
            endGame();

        } while(AskToPlayAgain());
    
    
}

// Clean up game
void endGame()
{
    std::cout << "Game Over!" << "\n\n";
    SummariseGame();
}

// Get user guess
FText getValidGuess()
{
    
    FText guess;
    EGuessStatus status;

    do {
        
            std::cout << "Whats your guess?" << std::endl;
            std::cout << "Try " << BullCowGame.GetCurrentTry() << std::endl;
            getline(std::cin, guess);
            status =  BullCowGame.CheckGuessValidity(guess);
        
            switch (status){
                
                case EGuessStatus::ERR_WORD_LENGTH:
                    std::cout << "Please enter a " << BullCowGame.GetHiddenWordLength() << " length word." << std::endl;
                    break;
                case EGuessStatus::ERR_NOT_LOWERCASE:
                    std::cout << "Please enter your guess in lowercase" << std::endl;
                    break;
                case EGuessStatus::ERR_NOT_ISOGRAM:
                    std::cout << "Please enter a word with no repeating letters" << std::endl;
                    break;
                default:
                    break;
            }
        
        std::cout << std::endl;
        
        
    } while (status != EGuessStatus::OK);
    
    return guess;
}

void SummariseGame(){
    
    if(BullCowGame.IsGameWon()){
        
        std::cout << "Congratulations you won!!!!\n\n";
        
    } else {
        
        std::cout << "Bad luck!  Better luck next time...\n\n";
        
    }
}

bool AskToPlayAgain(){
    
    std::cout << "Do you want to play again?" << std::endl;
    FText response;
    getline(std::cin, response);
    return response[0] == 'Y' || response[0] == 'y';
    
}
