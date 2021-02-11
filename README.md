# CA
a pretty bad header for building cellular automata

# Usage

## struct
the header contains a struct that characterizes each cell with 2 states that can either be 
dead (false) or alive (true). the struct is hence defined as follows:

	typedef struct  
	{  

		bool oS; //old state, see the functions for a clearer view on its role.  	
		bool nS; //new state.  
	};  

 



## Functions
__printCharmap(int size, char** charmap);__:  

printCharmap is just for testing purposes, and *usually* it shouldn't be needed.  

__printCellmap(int size, cell** cellmap);__:  

printCellmap is used to print the cell map to the screen and hence visualizing the automaton.
refer to the code for details.  

__fillCharmap(int size, char** charmap, FILE* file);__:  

fills _charmap_ with all the contents of _file_ via a sequence of fscanf()s in a for loop. 
refer to the code for details.  

__cellMapFromCharmap(int size, char** charmap, cell** cellmap);__  

maps each character in the _charmap_ (which we copied from the input file) to _cellmap_ using 
the following relation:  



__1__ -> __true__, __0__ -> __false__  


