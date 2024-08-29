#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int x, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void display_PreOrder(int inOrder[], int postOrder[], int n) {
    int root_index = search(inOrder, postOrder[n - 1], n);

    printf("%d ", postOrder[n - 1]);

    if (root_index != 0) {
        display_PreOrder(inOrder, postOrder, root_index);
    }

    if (root_index != n - 1) {
        display_PreOrder(inOrder + root_index + 1, postOrder + root_index, n - root_index - 1);
    }
}

int main() {
    int n;
    printf("Enter the total number of nodes in the tree: ");
    scanf("%d", &n);

    int inOrder[n], postOrder[n];

    printf("Enter inorder traversal of the tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inOrder[i]);
    }

    printf("Enter postOrder traversal of the tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postOrder[i]);
    }

    printf("Preorder traversal of the tree is: ");
    display_PreOrder(inOrder, postOrder, n);

    return 0;
}