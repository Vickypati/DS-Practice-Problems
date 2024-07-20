// Include necessary header files
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert nodes into the binary tree
Node* insert(Node* root, int data) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    // Use a queue to traverse the tree and find the position to insert the node
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
        Node* temp = queue[front++];
        // Insert node as the left child of the parent node
        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        }
        // If the left child is not null, push it to the queue
        else {
            queue[rear++] = temp->left;
        }

        // Insert node as the right child of parent node
        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        }
        // If the right child is not null, push it to the queue
        else {
            queue[rear++] = temp->right;
        }
    }

    return root;
}

// Function to delete the deepest node in the binary tree
void deletDeepest(Node* root, Node* d_node) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    // Do level order traversal until last node
    Node* temp;
    while (front != rear) {
        temp = queue[front++];
        if (temp == d_node) {
            temp = NULL;
            free(d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                free(d_node);
                return;
            }
            else {
                queue[rear++] = temp->right;
            }
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                free(d_node);
                return;
            }
            else {
                queue[rear++] = temp->left;
            }
        }
    }
}

// Function to delete an element from the binary tree
Node* deletion(Node* root, int key) {
    if (!root) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            return NULL;
        }
        else {
            return root;
        }
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    Node* temp;
    Node* key_node = NULL;

    // Do level order traversal to find deepest node (temp) and node to be deleted (key_node)
    while (front != rear) {
        temp = queue[front++];
        if (temp->data == key) {
            key_node = temp;
        }
        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }

    if (key_node != NULL) {
        int x = temp->data;
        key_node->data = x;
        deletDeepest(root, temp);
    }

    return root;
}

// Function for inorder tree traversal (Left - Root - Right)
void inorderTraversal(Node* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function for preorder tree traversal (Root - Left - Right)
void preorderTraversal(Node* root) {
    if (!root) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for postorder tree traversal (Left - Right - Root)
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Function for Level order tree traversal
void levelorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    // Use a queue to do level order traversal
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
}

// Main function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Create a binary tree
    Node* root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);

    // Print the binary tree using different traversal methods
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level order traversal: ");
    levelorderTraversal(root);
    printf("\n");

    // Delete an element from the binary tree
    root = deletion(root, 3);

    // Print the binary tree after deletion
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}