#include "CA.h"
#include <stdlib.h>
#include <unistd.h>
#define SIZE 24

int LST(int size, cell** cellmap, int x, int y)
{
    //Local State Function 	
	int adjcnt = 0;
	if ((x-1 >= 0) && (y-1 >= 0) && NW.oS) adjcnt++;
	if ((y+1 < size) && (x-1 >= 0) && SW.oS) adjcnt++;
	return adjcnt;
}

void newGeneration(int size, cell** cellmap)
{
    loopX(size)
    {
        loopY(size)
        {
            if (C.oS) {continue;}
            if (LST(SIZE, cellmap, x, y) == 1)
            {
                C.nS = true;
            }
            else
            {
                C.nS = false;
            }
        }
    }
}

int main()
{
    cell** cellmap = (cell**) malloc(SIZE*sizeof(cell*));
    for (int i = 0; i < SIZE; i++)
    {
        cellmap[i] = (cell*) malloc(SIZE*sizeof(cell));
    }
    
    char** charmap = (char**) malloc(SIZE*sizeof(char*));
    for (int i = 0; i < SIZE; i++)
    {
        charmap[i] = (char*) malloc(SIZE*sizeof(char));
    }
    FILE* file = fopen("example_input", "r");
    
    if (file == NULL) {printf("error opening the file"); exit(1);}
    fillCharmap(SIZE, charmap, file);
    cellmapFromCharmap(SIZE, charmap, cellmap);
    
        while (true)
        {
            //printCharmap(SIZE, charmap);
            newGeneration(SIZE, cellmap);
            updateOldStates(SIZE, cellmap);
            printCellmap(SIZE, cellmap);
            usleep(1000000);
        }

    return 0;
}
