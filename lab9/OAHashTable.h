#pragma once

struct DataItem
{
	int data;
	int key;
};

struct OAHashTable
{
	struct DataItem** buckets;
	int size;
	int numInsertions;
	int numSearches;
	int numProbes;
	int numCollisions;
};

struct OAHashTable* initOAHashTable(int);
void printKeys(struct OAHashTable*);
int insert(struct OAHashTable*, int, int);
void destroy(struct OAHashTable*);
void printPerformance(struct OAHashTable*);
struct DataItem* search(struct OAHashTable*, int);
void removeItem(struct OAHashTable*, int);