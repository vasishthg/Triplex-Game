#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
    
    std::cout << "\n\nYou Are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter The Correct code to enter...";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "+ There Are 3 digits in the code";
    std::cout << std::endl;
    std::cout << "+ The digits add up to: " << CodeSum;
    std::cout << std::endl;
    std::cout << "+ The digits multiply to: " << CodeProduct;
    std::cout << std::endl;

    int GuessA, GuessB, GuessC; 

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
   // std::cout << "You Have Enetered : " << GuessA << GuessB << GuessC;


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Server Accessed :)";
        return true;
    }
    else
    {
        std::cout << "Access Denied :(";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n\n\n\n***Great Work Agent, You Succesfully Got all The Files, Now get out of there!***\n" ;
    return 0;
}