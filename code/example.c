#include "CA.h"
#include <stdlib.h>
#include <unistd.h>
#define SIZE 24


int main()
{
    cell cellmap[SIZE][SIZE];
    
    char** charmap = malloc(SIZE*sizeof(char*));
    for (int i = 0; i < SIZE;i++)
    {
        charmap[i] = malloc(SIZE*sizeof(char));
    }
    FILE* file = fopen("example_input", "r");
    fillCharMap(SIZE, charmap, file);
    CellmapFromCharmap(SIZE, cellmap, charmap);
    while (true)
    {
        updateCellmap(SIZE, cellmap);
        printCellmap(SIZE, cellmap);
        clearScreen();
        usleep(1);
    }

    return 0;
}