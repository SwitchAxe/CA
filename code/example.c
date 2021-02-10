#include "CA.h"
#include <stdlib.h>
#include <unistd.h>
#define SIZE 24

int LST(int size, cell cellmap[size][size], int x, int y)
{
    //Local State Function 	
	int adjcnt = 0;
	if ((x-1 >= 0) && (y-1 >= 0) && NW.oS) adjcnt++;
	if ((y+1 < SIZE) && (x-1 >= 0) && SW.oS) adjcnt++;
	return adjcnt;
}

void updateStates(int size, cell (*cellmap)[size][size])
{
    cycleX(size)
    {
        cycleY(size)
        {
            if (C->oS) {continue;}
            if (LST(SIZE, *cellmap, x, y) == 1)
            {
                C->nS = true;
            }
            else
            {
                C->nS = false;
            }
        }
    }
}

int main()
{
    cell cellmap[SIZE][SIZE] = {0};
    
    char charmap[SIZE][SIZE] = {0};
    FILE* file = fopen("example_input", "r");
    
    if (file == NULL) {printf("error opening the file"); exit(1);}
    fillCharmap(SIZE, &charmap, file);
    printf("got here!\n");
    CellmapFromCharmap(SIZE, &cellmap, &charmap);
    while (true)
    {
        clearScreen();
        
        updateCellmap(SIZE, &cellmap);
        updateStates(SIZE, &cellmap);
        printCellmap(SIZE, cellmap);
        usleep(100000);
    }

    return 0;
}
