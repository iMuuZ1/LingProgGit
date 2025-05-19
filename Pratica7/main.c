#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the BST
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} tNode;

// Function to create a new node
tNode *create_node(int key) {
    tNode *new_node = (tNode *) malloc(sizeof(tNode)); // Usando o typedef
    if (new_node == NULL) {
        fprintf(stderr, "Error: Impossible to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the BST
tNode *insert_node(tNode *root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else {  // Allow duplicates to be inserted in the right subtree
        root->right = insert_node(root->right, key);
    }

    return root;
}

// Function to find the minimum value node in a subtree
tNode *min_value_node(tNode *node) {
    tNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to remove a node from the BST
tNode *remove_node(tNode *root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Error: The key is not in the tree.\n");
        return root;
    }

    if (key < root->key) {
        root->left = remove_node(root->left, key);
    } else if (key > root->key) {
        root->right = remove_node(root->right, key);
    } else {
        if (root->left == NULL) {
            tNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tNode *temp = root->left;
            free(root);
            return temp;
        }

        tNode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = remove_node(root->right, temp->key);
    }

    return root;
}

// Function to delete the BST and free memory
void delete_tree(tNode *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

// Function to print the BST in inorder traversal
void inorder_traversal(tNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

tNode *search_node(tNode *root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search_node(root->left, key);
    else
        return search_node(root->right, key);
}



int main() {
    tNode *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    insert_node(root, 50); // Inserting duplicate key

    printf("BST in inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    root = remove_node(root, 20);
    printf("BST after removing 20: ");
    inorder_traversal(root);
    printf("\n");

    int key;
    for (int i = 0; i < 3; i++) {
        printf("Digite a chave a ser buscada (%d/3): ", i + 1);
        scanf("%d", &key);

        tNode *result = search_node(root, key);
        if (result != NULL)
            printf("Chave %d encontrada na árvore.\n", key);
        else
            printf("Chave %d NÃO encontrada na árvore.\n", key);
    }


    delete_tree(root); // Free memory

    return 0;
}