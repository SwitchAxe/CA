#ifndef CA_H
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
	#define SW cellmap[x-1][y+1] //South-West direction
	#define SE cellmap[x+1][y+1] //South-East direction

	//defining the macro functions for easier and more readable loops
	#define loopX(size) for (int x = 0; x < (size); x++)
	#define loopY(size) for (int y = 0; y < (size); y++)


	//oS is the old state of the cell, nS is the new state.
	typedef struct
	{
		bool oS;
		bool nS;
	} cell;


	void fillCharmap(int size, char** charmap, FILE* file)
	{
		for (int i = 0; i < size; i++)
		{
			fscanf(file, "%s", charmap[i]);
		}
	}
	
	void cellmapFromCharmap(int size, char** charmap, cell** cellmap)
	{
		loopX(size)
		{
			loopY(size)
			{
				C.oS = (charmap[x][y] == '1') ? true : false; 
			}
		}
	}
	
	void updateOldStates(int size, cell** cellmap)
	{
		loopX(size)
		{
			loopY(size)
			{
				C.oS = C.nS;
			}
		}
	}
	
	void printCellmap(int size, cell** cellmap)
	{
		printf("\033[0;0H\033[0;0f");
		loopX(size)
		{
			loopY(size)
			{
				printf("%c", (C.nS == true) ? 'x' : ' ');
			}
			printf("\n");
		}
	}

	void printCharmap(int size, char** charmap)
	{
		for (int i = 0; i < size; i++)
		{
			for (int e = 0; e < size; e++)
			{
				printf("%c", charmap[i][e]);
			}
			printf("\n");
		}
	}

#endif