#include "includes.h"

// Function Declarations
void FillPlayArea(short cells, short heroRow, short heroCol, short princessRow, short princessCol);
void PrintPlayArea(short cells);
void CompleteDirections(short yAxis, short xAxis);

// Public Variables
char grid[50][50];
std::string directionArray[100];

int main()
{
    short boardSpots;
    short heroRow, heroCol;
    short princessRow, princessCol;
    short heroToPrincessY, heroToPrincessX;
    
    srand(time(NULL));
    // Initialize rand seed.

    PickRandSpots: boardSpots = rand() % 49 + 1;
    // The height and width of the board. Will pick between 1 and 49.
        
    if (boardSpots < 3 || boardSpots % 2 == 0) goto PickRandSpots;
    
    heroRow = boardSpots / 2 + 1;
    heroCol = boardSpots / 2 + 1;
    PrincessRandomCoords: princessRow = rand() % boardSpots + 1;
    princessCol = rand() % boardSpots + 1;
    if (princessRow == heroRow && princessCol == heroCol) goto PrincessRandomCoords;    

    boardSpots--;
    heroRow--;
    heroCol--;
    princessRow--;
    princessCol--;    

    heroToPrincessY = princessRow - heroRow;
    heroToPrincessX = princessCol - heroCol;

    printf("%d = heroToPrincessY\n%d = heroToPrincessX\n", heroToPrincessY, heroToPrincessX);
    // This was a debugging vice, but I found it extremely useful to be in the game.

    FillPlayArea(boardSpots, heroRow, heroCol, princessRow, princessCol);
    CompleteDirections(heroToPrincessY, heroToPrincessX);
    PrintPlayArea(boardSpots);
}


