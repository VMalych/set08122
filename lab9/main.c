#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "OAHashTable.h"

#define SIZE 10000

int main(int argc, char** argv)
{
	struct OAHashTable* hashTable = initOAHashTable(SIZE);
	
	srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
	{
		insert(hashTable, rand(), rand());
	}
	
	printKeys(hashTable);
	
	search(hashTable, 6);
	search(hashTable, 39);
	search(hashTable, 100);
	
	removeItem(hashTable, 13);
	
	printKeys(hashTable);
	
	printPerformance(hashTable);
	
	destroy(hashTable);
	
	return 0;
}