#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}treeNode;

treeNode* head = NULL, *newNode, *temp;

treeNode* alloc();
void insertNode();
treeNode* minValueNode(treeNode* node);
treeNode* deleteNode(treeNode* root, int key);
void preOrder(treeNode* node);
void inOrder(treeNode* node);
void postOrder(treeNode* node);
int totalNodes(treeNode* node);
void deleteTree(treeNode* tree);

int main(){
    int totalNode, height, option;
    printf("\t\t**Binary Search Tree**\t\t\n");
    printf("1. Insertion\n2. Deletion\n3. Pre Order Traversal\n4. In Order Traversal\n5.Post Order Traversal\n6. Total Nodes\n7.Delete Tree\n8. Exit\n");
    do{
        printf("Operation Number: \n");
        scanf("%d", &option);
        switch(option){
            case 1: 
                insertNode();
                break;
            case 2:
                printf("Enter the value you want to delete: ");
                int key;
                scanf("%d", &key);
                treeNode* deletedKey = deleteNode(head, key);
                printf("Deleted %d.\n", deletedKey->value);
                break;
            case 3:
                preOrder(head);
                putchar('\n');
                break;
            case 4:
                inOrder(head);
                putchar('\n');
                break;
            case 5:
                postOrder(head);
                putchar('\n');
                break;
            case 8:
                printf("Terminated!\n");
                break;

        }
    }while(option != 9);
    return 0;
}

treeNode* alloc(){
    treeNode* memory = malloc(sizeof(treeNode));
    return memory;
}

void insertNode(){
    newNode = alloc();
    printf("Enter the value you want to add: ");
    scanf("%d", &newNode->value);
    newNode->left = NULL;
    newNode->right = NULL; //creating an empty tree with a value and two null leaf

    // initial check whether the tree is empty
    if(head == NULL){
        head = newNode;
        return; 
    }

    temp = head;
    while(temp != NULL){
        //for left subtree
        if(newNode->value < temp->value){
            //if left position NULL add newNode else traverse by one left position
            if(temp->left == NULL){
                temp->left = newNode;
                return;
            }
            else
                temp = temp->left;
        }

        //for right subtree
        else{
            //if right position NULL add newNode else traverse by one right position
            if(temp->right == NULL){
                temp->right = newNode;
                return;
            }
            else
                temp = temp->right;
        }
    }
}

treeNode* minValueNode(treeNode* node){
    treeNode* current = alloc();

    while(current && current->left != NULL)
        current = current->left;
    return current;
}

treeNode* deleteNode(treeNode* root, int key){
    if(root == NULL)
        return root;
    //traversing until found the position
    if(key < root->value)
        root->left = deleteNode(root->left, key);
    else if(key> root->value)
        root->right = deleteNode(root->right, key);
    // if the element is found this block is performed
    else{
        //deletion for 1 or 0 child
        if(root->left == NULL)
        {
            treeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            treeNode* temp = root->left;
            free(root);
            return temp;
        }
        //deletion for more than 2 children
        treeNode* temp = minValueNode(root->right);

        //copy the temp value into current root value
        root->value = temp->value;

        root->right = deleteNode(root->right, temp->value);
    }
}

void preOrder(treeNode* node){
    if(node == NULL)
        return;
    printf("%d ", node->value);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(treeNode* node){
    if(node == NULL)
        return;
    inOrder(node->left);
    printf("%d ", node->value);
    inOrder(node->right);
}

void postOrder(treeNode* node){
    if(node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->value);
}