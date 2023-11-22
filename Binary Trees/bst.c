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
//todo Preorder Traversal (recursion)--2
void preorderTraversal(struct node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
//todo Inorder Traversal (recursion)--3
void inorderTraversal(struct node *node)
{
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}
//todo Postorder Traversal (recursion)--4
void postorderTraversal(struct node *node)
{
    if (node == NULL)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}
//todo Smallest Element --5
struct node *findSmallestElement(struct node *tree)
{
    if ((tree == NULL) || (tree->left == NULL))
        return tree;
    else
        return findSmallestElement(tree->left);
}
//todo largest Element --6
struct node *findLargestElement(struct node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
        return tree;
    else
        return findLargestElement(tree->right);
}
//todo Delete an Element-7
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
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
//todo no of nodes  (recursion)--8
int totalNodes(struct node *tree)
{
    if (tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
//todo External Nodes (recursion)--9
int totalExternalNodes(struct node *tree)
{
    if (tree == NULL)
        return 0;
    else if ((tree->left == NULL) && (tree->right == NULL))
        return 1;
    else
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}
//todo Internal Nodes (recursion)--10
int totalInternalNodes(struct node *tree)
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
        return 0;
    else
        return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}
//todo Height of a Tree (recursion)-11
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
    printf("\n**********--Tree Data Structure Program--**********");
    printf("\n***************************************************");
    printf("\n***--------Main Menu--------***");
    printf("\nPress the following keys for following functions");
    printf("\n1)  Insert Element\n2)  Preorder Traversal\n3)  Inorder Traversal\n4)  Postorder Traversal\n5)  Smallest Element\n6)  Largest Element\n7)  Delete an Element\n8)  Count the no of Nodes\n9)  No of External Nodes\n10) No of Internal Nodes\n11) Height of Tree\n12) Delete the Tree\n13) Exit\n");
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
            preorderTraversal(head);
            break;
        case 3:
            inorderTraversal(head);
            break;
        case 4:
            postorderTraversal(head);
            break;
        case 5:
            printf("\nThe Smallest Element is : %d", findSmallestElement(head)->data);
            break;
        case 6:
            printf("\nThe Largest Element is : %d", findLargestElement(head)->data);

            break;
        case 7:
            printf("\nEnter the value You want to delete : ");
            int key;
            scanf("%d", &key);
            deleteNode(head, key);
            break;
        case 8:
            tn = totalNodes(head);
            printf("\nThe Total no of Nodes are : %d", tn);
            break;
        case 9:
            TEN = totalExternalNodes(head);
            printf("\nThe Total no of External Nodes are : %d", TEN);
            break;
        case 10:
            TIN = totalInternalNodes(head);
            printf("\nThe total no of internal nodes is : %d", TIN);
            break;
        case 11:
            height = Height(head);
            printf("\nThe Height of the Tree is %d", height);
            break;
        case 12:
            deleteTree(head);
            break;
        case 13:
            //! writing so that it does not come in default when we select option 12
            break;
        default:
            printf("\nInvalid Option key is pressed\n");
            break;
        }
    } while (option != 13);
    return 0;
}