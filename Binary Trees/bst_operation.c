#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//todo structure declaration
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head = NULL, *newnode, *parentptr, *temp;

//todo Insert Element--1
void insertElement()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter The Value you want to Add : ");
    scanf("%d", &newnode->data);
    int val = newnode->data;
    newnode->left = NULL;
    newnode->right = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            parentptr = temp;
            if (val < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (val < parentptr->data)
            parentptr->left = newnode;
        else
            parentptr->right = newnode;
    }
}
//min value node
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

//todo Delete an Element-3
struct node *deleteNode(struct node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//todo Height of a Tree (recursion)-4
int Height(struct node *tree)
{
    int leftheight, rightheight;
    if (tree == NULL)
        return -1;

    leftheight = Height(tree->left);
    rightheight = Height(tree->right);

    if (leftheight > rightheight)
        return (leftheight + 1);
    else
        return (rightheight + 1);
}
//todo delete the tree (recursion)--12
void deleteTree(struct node *tree)
{
    head = NULL;
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    else
        return;
}
// main function
int main()
{
    int tn, TEN, TIN, height;
    int option = 0;
    printf("\n**********--Tree Data Structure Operations--**********");
    printf("\n***************************************************");
    printf("\n***--------Main Menu--------***");
    printf("\nPress the following keys for following functions");
    printf("\n1)  Insert Element\n2)  Delete an Element\n3) Height of Tree\n4) Delete the Tree\n5) Exit\n");
    do
    {
        printf("\nYou want to Perform Function No : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertElement();
            break;
        case 2:
            printf("\nEnter the value You want to delete : ");
            int key;
            scanf("%d", &key);
            deleteNode(head, key);
            break;
        case 3:
            height = Height(head);
            printf("\nThe Height of the Tree is %d", height);
            break;
        case 4:
            deleteTree(head);
            break;
        case 5:
            //! writing so that it does not come in default when we select option 4
            break;
        default:
            printf("\nInvalid Option key is pressed\n");
            break;
        }
    } while (option != 5);
    return 0;
}