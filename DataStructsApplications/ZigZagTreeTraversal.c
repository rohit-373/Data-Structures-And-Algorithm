#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
int arr[MAX_SIZE];

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* n = (Node*)malloc(sizeof(Node*));;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* createTree(Node* root, int n, int i) {
    if (i < n) {
        root = createNode(arr[i]);
        root->left = createTree(root->left, n, 2*i+1);
        root->right = createTree(root->right, n, 2*i+2);
    }
    return root;
}

void levelOrder(Node* root, int n) {
    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int flag = 1;
    while (front < rear) {
        int size = rear-front;
        int row[size];
        for (int i = 0; i < size; i++) {
            Node* curr = queue[front++];
            int index = flag ? i : (size-1-i);
            row[index] = curr->data;
            if (curr->left != NULL)
                queue[rear++] = curr->left;
            if (curr->right != NULL)
                queue[rear++] = curr->right;
            
        }
        for (int i = 0; i < size; i++) 
            printf("%d ", row[i]);
        printf("\n");
        flag = !flag;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* root = NULL;
    root = createTree(root, n, 0);
    levelOrder(root, n);
    return 0;
}
