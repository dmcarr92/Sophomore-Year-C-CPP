#include "bsTree.h"

tree* createTree(){

	//the tree structure contains only a root
	//the root is a leaf structure pointer
	tree* newTrizzle = malloc(sizeof(tree));
	newTrizzle->root = NULL;
	return newTrizzle;
}

leaf* createLeaf(data* d){

	//the leaf structure contains a data pointer and two 
	//leaf-pointers to its left(lower) and right(equal or higher) 		//children
	leaf* newLeaf = malloc(sizeof(leaf));
	newLeaf->data = d;
	newLeaf->left = NULL;
	newLeaf->right = NULL;
	return newLeaf;
}

//takes a data structure and places it in a binary search tree 
void addToTree_r(leaf* l, data* d){

	float dataSum = getDataSum(d);
	float leafSum = getDataSum(l->data);

	//if data to be added is greater than or equal to the data
	//in the current leaf, it will be added to the right subtree.
	//the program will then decide whether it needs to create
	//a new leaf or recursively call addFromLeaf using the existing
	//right subtree
	if(dataSum >= leafSum){

		if(l->right == NULL){

			printf("\ncreating right subtree *");
			l->right = createLeaf(d);
		}
		else{

			printf("\nbranching right");
			addToTree_r(l->right, d);
		}
	}
	else{ //if the data to be added is lower
	      //than that in the current leaf...

		if(l->left == NULL){

			printf("\ncreating left subtree *");
			l->left = createLeaf(d);
		}
		else{

			printf("\nbranching left");
			addToTree_r(l->left, d);
		}
	}
}

void addToTree(tree* trizzle, data* d){

	if(trizzle->root == NULL){ //if tree is empty

		printf("\ntree currently empty, adding data to root *");
		leaf* newRoot = createLeaf(d);
		trizzle->root = newRoot;
	}
	else{

		addToTree_r(trizzle->root, d);
	}
}

//reads a .txt file containing data, places it in a binary search tree
tree* getTreeFromFile(char* fname){

	tree* trizzle = createTree();
	FILE* srcFile = openfileRead(fname);
	data* newData;
	int count = 0;
	while(1){

		newData = readData(srcFile);
		if(newData == NULL)break;
		addToTree(trizzle, newData);
		count++;
	}
	printf("\n\n%d data nodes added\n",count);
	return trizzle;
}

//takes and returns the sum of all even data structures in the tree
float getEvenSum_r(leaf* l){

	if(l == NULL)return 0.0;
	else{

		float dataSum = getDataSum(l->data);
		if((int)dataSum % 2 == 0){

			printf("\nto be added: %f",dataSum);
			return(dataSum + getEvenSum_r(l->left) + getEvenSum_r(l->right));
		}
		else{

			return(getEvenSum_r(l->left) + getEvenSum_r(l->right));
		}
	}
}

float getEvenSum(tree* trizzle){

	if(trizzle->root == NULL){

		printf("\ntree is empty\n");
		return 0.0;
	}
	else{

		float dataSum = getDataSum(trizzle->root->data);
		if((int)dataSum % 2 == 0){

			printf("\nto be added: %f",dataSum);
			return(dataSum + getEvenSum_r(trizzle->root->left) + getEvenSum_r(trizzle->root->right));
		}
		else{

			return(getEvenSum_r(trizzle->root->left) + getEvenSum_r(trizzle->root->right));
		}
	}
}

//searches a binary search tree and returns the leaf containing
//the data structure with the smallest sum
leaf* getSmallest_r(leaf* l){

	if(l->left == NULL){

		return l;
	}
	else{

		return getSmallest_r(l->left);
	}
}

leaf* getSmallest(tree* trizzle){

	if(trizzle->root->left == NULL){

		return trizzle->root;
	}
	else{

		return getSmallest_r(trizzle->root->left);
	}
}

//searches a binary search tree and returns the leaf containing
//the data structure with the largest sum
leaf* getLargest_r(leaf* l){

	if(l->right == NULL){

		return l;
	}
	else{

		return getLargest_r(l->right);
	}
}

leaf* getLargest(tree* trizzle){

	if(trizzle->root->right == NULL){

		return trizzle->root;
	}
	else{

		return getLargest_r(trizzle->root->right);
	}
}

//returns the height (or distance from root) of the furthest leaf
//in the tree. If only the root exists then the function returns 0.
int getTreeHeight_r(leaf* l){

	if(l == NULL){

		return -1;
	}
	else{

		int leftHeight = getTreeHeight_r(l->left);
		int rightHeight = getTreeHeight_r(l->right);
		if(leftHeight > rightHeight){

			return(1 + leftHeight);
		}
		else{

			return(1 + rightHeight);
		}
	}
}

int getTreeHeight(tree* trizzle){

	if((trizzle->root->left == NULL) && (trizzle->root->right == NULL)){

		return 0;
	}
	else{

		return(getTreeHeight_r(trizzle->root));
	}
}

void printKdist_r(leaf* l, int K){

	if(l == NULL)return;
	else if(K == 0){

		float sum = getDataSum(l->data);
		printf("\n%f",sum);
	}
	else{

		printKdist_r(l->left, (K - 1));
		printKdist_r(l->right, (K - 1));
	}
}

void printKdist(tree* trizzle, int K){

	if(trizzle->root == NULL)return;
	else{

		printf("\nsearching for data %d branches from root:\n",K);
		printKdist_r(trizzle->root, K);
	}
}

int getTreeSize_r(leaf* l){

	if(l == NULL)return 0;
	else{

		return(1 + getTreeSize_r(l->left) + getTreeSize_r(l->right));
	}
}
	
int getTreeSize(tree* trizzle){

	if(trizzle->root == NULL)return 0;
	else{

		return(1 + getTreeSize_r(trizzle->root->left) + getTreeSize_r(trizzle->root->right));
	}
}

void printPathSumN_r(leaf* l, float sum, float N){

	if(l == NULL)return;
	else if(sum > N)return;
	float leafSum = getDataSum(l->data);
	sum += leafSum;
	if(sum == N){

		printf("\n\npath sum = %f\nterminating leaf: ",N);
		printData(l->data);
	}
	else{

		printPathSumN_r(l->left, sum, N);
		printPathSumN_r(l->right, sum, N);
	}
}

void printPathSumN(tree* trizzle, float N){

	if(trizzle->root == NULL)return;

	float sum;
	sum = getDataSum(trizzle->root->data);
	if(sum == N){

		printf("\n\npath sum = %.2f\nterminating leaf: ",N);
		printData(trizzle->root->data);
	}
	else{

		printPathSumN_r(trizzle->root->left, sum, N);
		printPathSumN_r(trizzle->root->right, sum, N);
	}
}

void printRange_r(leaf* l, float min, float max){

	if(l == NULL)return;
	float dataSum = getDataSum(l->data);
	if(min <= dataSum && dataSum <= max){

		printf("%f\n",dataSum);
	}
	printRange_r(l->left, min, max);
	printRange_r(l->right, min, max);
}

void printRange(tree* trizzle, float min, float max){

	if(trizzle->root == NULL){

		printf("tree is empty\n");
		return;
	}
	float dataSum = getDataSum(trizzle->root->data);
	if(min <= dataSum && dataSum <= max){

		printf("%f\n",dataSum);
	}
	printRange_r(trizzle->root->left, min, max);
	printRange_r(trizzle->root->right, min, max);
}

int isBalanced(tree* trizzle){

	if(trizzle->root == NULL)return 0;
	int leftWeight = getTreeSize_r(trizzle->root->left);
	int rightWeight = getTreeSize_r(trizzle->root->right);
	printf("\nleftWeight = %d\nrightWeight = %d\n",leftWeight, rightWeight);
	if(leftWeight == rightWeight)return 1;
	else return -1;
}



