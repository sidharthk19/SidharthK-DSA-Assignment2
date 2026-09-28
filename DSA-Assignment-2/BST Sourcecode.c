#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key[20];
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char key[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->key, key);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node *root, char key[]) {
    if (root == NULL)
        return createNode(key);

    if (strcmp(key, root->key) < 0)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->key);
        inorder(root->right);
    }
}

int main() {
    char keys[][20] = {

        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };//This is the INPUT.File attached has same values
    int n = 8;
    Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("Inorder traversal:\n");
    inorder(root);

    return 0;
}
