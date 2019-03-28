#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "OAHashTable.h"

int hashCode(int key, int size)
{
	return key % size;
}

struct OAHashTable* initOAHashTable(int size)
{
	struct OAHashTable *hashTable = (struct OAHashTable*)malloc(sizeof(struct OAHashTable));
	//Calloc to init buckets to NULL
	hashTable->buckets = (struct DataItem**)calloc(size, sizeof(struct DataItem*));
	hashTable->size = size;
	hashTable->numCollisions = 0;
	hashTable->numProbes = 0;
	hashTable->numInsertions = 0;
	hashTable->numSearches = 0;
	
	return hashTable;
}

int insert(struct OAHashTable *hashTable, int key, int data)
{
	struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
	item->data = data;
	item->key = key;
	
	int hashIndex = hashCode(key, hashTable->size);
	int numTries = 0;
	int probe = 1;
	
	if (hashTable->buckets[hashIndex] != NULL)
	{
		hashTable->numCollisions++;
	}
	while (hashTable->buckets[hashIndex] != NULL && numTries < hashTable->size)
	{
		if (hashTable->buckets[hashIndex]->key == -1) break;
		numTries++;
		hashIndex += probe;
		if (probe == 1) probe++;
		else probe = probe * probe;
		hashIndex %= hashTable->size;
	}
	if (numTries == hashTable->size)
	{
		return -1;
	}
	else
	{
		hashTable->buckets[hashIndex] = item;
	}
	hashTable->numInsertions++;
	
	return 0;
}

struct DataItem* search(struct OAHashTable *hashTable, int key)
{
	hashTable->numSearches++;
	int hashIndex = hashCode(key, hashTable->size);
	int numTries = 0;
	int probe = 1;
	
	while (hashTable->buckets[hashIndex] != NULL && numTries < hashTable->size)
	{
		numTries++;
		hashTable->numProbes++;
		if (hashTable->buckets[hashIndex]->key == key)
			return hashTable->buckets[hashIndex];
		
		hashIndex += probe;
		if (probe == 1) probe++;
		else probe = probe * probe;
		hashIndex %= hashTable->size;
	}
	
	return NULL;
}

void printKeys(struct OAHashTable *hashTable)
{
	printf("[");
	for (int i = 0; i < hashTable->size - 1; i++)
	{
		if (hashTable->buckets[i] != NULL)
		{
			printf("%d, ", hashTable->buckets[i]->key);
		}
		else
		{
			printf("-, ");
		}
	}
	
	if (hashTable->buckets[hashTable->size - 1] != NULL)
	{
		printf("%d", hashTable->buckets[hashTable->size - 1]->key);
	}
	else
	{
		printf("-");
	}
	printf("]\n");
}

void destroy(struct OAHashTable *hashTable)
{
	for (int i = 0; i < hashTable->size; i++)
	{
		if (hashTable->buckets[i] != NULL)
		{
			free(hashTable->buckets[i]);
		}
	}
	free(hashTable);
}

void removeItem(struct OAHashTable *hashTable, int key)
{
	int hashIndex = hashCode(key, hashTable->size);
	int numTries = 0;
	while (hashTable->buckets[hashIndex] != NULL && numTries < hashTable->size)
	{
		numTries++;
		if (hashTable->buckets[hashIndex]->key == key)
		{
			hashTable->buckets[hashIndex]->key = -1;
			hashTable->buckets[hashIndex]->data = -1;
			break;
		}
		
		++hashIndex;
		hashIndex %= hashTable->size;
	}
}

void printPerformance(struct OAHashTable *hashTable)
{
	printf("Number of insertions: %d\n", hashTable->numInsertions);
	printf("Number of collisions: %d\n", hashTable->numCollisions);
	printf("Load factor: %.3f\n", (double)hashTable->numInsertions / hashTable->size);
	printf("%% of insertions that collided: %.1f\n", (double)hashTable->numCollisions / hashTable->numInsertions * 100);
	printf("Average number of probes per search: %f\n", (double)hashTable->numProbes / hashTable->numSearches);
}