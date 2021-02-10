#include <stdbool.h>
#include <stdio.h>
//defining the neighborhood
#define C cellmap[x][y] //center of the neighborhood
#define N cellmap[x][y-1] //North direction   
#define NW cellmap[x-1][y-1] //North-West direction
#define NE cellmap[x+1][y-1] //North-east direction 
#define E  cellmap[x-1][y] //East direction
#define W  cellmap[x+1][y] //West direction
#define S  cellmap[x][y+1] //South direction 
#define SW cellmap[x-1][y-1] //South-West direction
#define SE cellmap[x+1][y+1] //South-East direction

//defining the macro functions for easier and more readable loops
#define cycleX(size) for (int x = 0; x < (size); x++)
#define cycleY(size) for (int y = 0; y < (size); y++)

//oS is the old state of the cell, nS is the new state.
typedef struct
{
	bool oS;
	bool nS;
} cell;

void clearScreen()
{
	printf("\033[0;0H\033[0;0f");
}

void printCellmap(int size, cell cellmap[size][size])
{
	
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			printf("%c", (C.oS == true) ? 'x' : ' ');
		}
		printf("\n");
	}
}
void updateCellmap(int size, cell cellmap[size][size])
{
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			C.oS = C.nS;
		}
	}
}

void fillCharMap(int size, char charmap[size][size], FILE* file)
{
	for (int i = 0; i < size; i++)
	{
		fscanf(file, "%s", charmap[i]);
	}
}

void CellmapFromCharmap(int size, 
						cell cellmap[size][size],
						 char charmap[size][size])
{
	cycleX(size)
	{
		cycleY(size)
		{
			C.oS = (charmap[x][y] == '1') ? true : false;
		}
	}
}
