#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *createNode(int data){
    treeNode *newNode = calloc(1, sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printTree(treeNode *tree){
}

int main(){
    treeNode *root = calloc(1, sizeof(treeNode));
    root = createNode(5);
    root->left = createNode(10);
    root->right = createNode(15);
    root->left->left = createNode(20);
    root->right->right = createNode(25);
    printTree(root);
    printTree(root->left);
    printTree(root->right);
    



    
    return 0;
}