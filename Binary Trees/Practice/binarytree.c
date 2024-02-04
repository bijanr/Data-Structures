#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int value;
    struct treenode* left;
    struct treenode* right;
}treeNode;

treeNode* createNode(int value){
    treeNode* result = (treeNode*)malloc(sizeof(treeNode));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printTabs(int numTabs){
    for(int i = 0; i< numTabs; i++)
        printf("\t");

}
void printTree_rec(treeNode* root, int level){
    if(root == NULL){
        printTabs(level);
        printf("---< empty >---\n");
        return;
    }
    printTabs(level);
    printf("Value = %d\n", root->value);
    printTabs(level);
    printf("Left : \n");
    printTree_rec(root->left,level+1 );
    printTabs(level);
    printf("Right : \n");
    printTree_rec(root->right,level+1);
    printTabs(level);
    printf("Done\n");
}



int main()
{
    treeNode* n1 = createNode(20);
    treeNode* n2 = createNode(12);
    treeNode* n3 = createNode(15);
    treeNode* n4 = createNode(7);
    treeNode* n5 = createNode(18);
    
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n2->right = n5;
    
    printTree_rec(n1, 0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    return 0;
}
