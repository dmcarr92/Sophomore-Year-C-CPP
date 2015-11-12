#ifndef BSTREE_H_
#define BSTREE_H_

#include "dataType.h"
#include "stack.h"
#include "queue.h"

typedef struct leafPtr{

	struct leafPtr* left;
	struct leafPtr* right;
	data* data;
}leaf;

typedef struct{

	leaf* root;
}tree;

tree* createTree();
leaf* createLeaf(data* d);

void addToTree_r(leaf* l, data* d);
void addToTree(tree* trizzle, data* d);

tree* getTreeFromFile(char* fname);

float getEvenSum_r(leaf* l);
float getEvenSum(tree* trizzle);

leaf* getSmallest_r(leaf* l);
leaf* getSmallest(tree* trizzle);

leaf* getLargest_r(leaf* l);
leaf* getLargest(tree* trizzle);

int getTreeHeight_r(leaf* l);
int getTreeHeight(tree* trizzle);

void printKdist_r(leaf* l, int K);
void printKdist(tree* trizzle, int K);

int getTreeSize_r(leaf* l);
int getTreeSize(tree* trizzle);

void printPathSumN_r(leaf* l, float sum, float N);
void printPathSumN(tree* trizzle, float N);

void printRange_r(leaf* l, float min, float max);
void printRange(tree* trizzle, float min, float max);

int isBalanced(tree* trizzle);

#endif
