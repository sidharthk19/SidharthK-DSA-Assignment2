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

int bstSearch(Node *root, char key[], int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;

        int result = strcmp(key, root->key);

        if (result == 0)
            return 1;
        else if (result < 0)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int linearSearch(char arr[][20], int n, char key[], int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (strcmp(arr[i], key) == 0)
            return 1;
    }

    return 0;
}

int main() {
    char keys[][20] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    int n = 8;
    Node *root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    char searchKeys[][20] = {"A120", "B3", "C1"};

    printf("Search Comparison Results\n\n");

    for (int i = 0; i < 3; i++) {
        int bstComp = 0;
        int linearComp = 0;

        int bstFound = bstSearch(root, searchKeys[i], &bstComp);
        int linearFound = linearSearch(
            keys, n, searchKeys[i], &linearComp
        );

        printf("Key: %s\n", searchKeys[i]);

        printf("BST Search: %s, Comparisons = %d\n",
               bstFound ? "Found" : "Not Found", bstComp);

        printf("Linear Search: %s, Comparisons = %d\n\n",
               linearFound ? "Found" : "Not Found", linearComp);
    }

    return 0;
}
