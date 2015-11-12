#include "bsTree.h"

//argc is the number of data nodes in the generated .txt file
//argv is the name of the .txt file
int main(int argc,char* argv[]){

	printf("\nPROGRAM BEGUN\n\n");

	//generating a readable .txt file
	srand(time(NULL));
	FILE* out = fopen(argv[2],"w");
	int i;
	int v1;
	int v2;
	float v3;
	for(i = 0;i < atoi(argv[1]);i++){

		v1 = rand() % 100;
		v2 = rand() % 200;
		v3 = (rand() % 10000)/100.00;
		printf("%d %d %f\n",v1,v2,v3);
		fprintf(out,"%d %d %f\n",v1,v2,v3);
	}
	fclose(out);
	tree* trizzlefizzle = getTreeFromFile(argv[2]);
	float evenSum = getEvenSum(trizzlefizzle);
	printf("\n\nevenSum = %f\n",evenSum);
	leaf* smallestlizzle = getSmallest(trizzlefizzle);
	leaf* largestlizzle = getLargest(trizzlefizzle);
	float smallestData = getDataSum(smallestlizzle->data);
	float largestData = getDataSum(largestlizzle->data);
	printf("\nsmallest data = %f\n",smallestData);
	printf("largest data = %f\n",largestData);
	int treeSize = getTreeSize(trizzlefizzle);
	int treeHeight = getTreeHeight(trizzlefizzle);
	printf("\ntree size = %d\ntree height = %d\n",treeSize, treeHeight);
	printKdist(trizzlefizzle, 1);
	printf("\n");
	printKdist(trizzlefizzle, treeHeight);
	printf("\n\nFinding data between 100.0 and 150.0:\n\n");
	printRange(trizzlefizzle, 100.0, 150.0);
	int balance = isBalanced(trizzlefizzle);
	printf("\nBalanced? %d\n",balance);


	tree* simpleTree = createTree();
	data* d1 = createData(8,0,0);
	data* d2 = createData(9,0,0);
	data* d3 = createData(2,0,0);
	data* d4 = createData(3,0,0);
	data* d5 = createData(12,0,0);
	data* d6 = createData(1,0,0);
	addToTree(simpleTree, d1);
	addToTree(simpleTree, d2);
	addToTree(simpleTree, d3);
	addToTree(simpleTree, d4);
	addToTree(simpleTree, d5);
	addToTree(simpleTree, d6);

//	 simpleTree
//
//	      8
//	     / \
//	    2   9
//	   / \   \
//	  1   3  12

	printPathSumN(simpleTree, 13);
	//printBreathFirst(simpleTree);

	printf("\nsuccess\n");
	return 0;
}


