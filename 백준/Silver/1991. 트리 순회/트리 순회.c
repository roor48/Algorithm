#include <stdio.h>
#include <memory.h>

typedef struct {
    // -1 == NULL
    int value;
    int left;
    int right;
} Node;

int N;
int visited[26];
Node tree[26];

// 전위 순회
void preorder(Node *node) {
    if (visited[node->value])
        return;
    visited[node->value] = 1;

    printf("%c", 'A' + node->value);
    if (node->left != -1)
        preorder(&tree[node->left]);
    if (node->right != -1)
        preorder(&tree[node->right]);
}

// 중위 순회
void inorder(Node *node) {
    if (visited[node->value])
        return;
    visited[node->value] = 1;
    
    if (node->left != -1)
        inorder(&tree[node->left]);
    printf("%c", 'A' + node->value);
    if (node->right != -1)
        inorder(&tree[node->right]);
    
}

// 후위 순회
void postorder(Node *node) {
    if (visited[node->value])
        return;
    visited[node->value] = 1;

    if (node->left != -1)
        postorder(&tree[node->left]);
    if (node->right != -1)
        postorder(&tree[node->right]);
    printf("%c", 'A' + node->value);
    
}

int main() {
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        char a, b, c;
        scanf("%c %c %c\n", &a, &b, &c);
        
        tree[a - 'A'].value = a - 'A';
        tree[a - 'A'].left = (b == '.') ? -1 : (b - 'A');
        tree[a - 'A'].right = (c == '.') ? -1 : (c - 'A');
    }

    memset(visited, 0, sizeof(visited));
    preorder(tree); puts("");

    memset(visited, 0, sizeof(visited));
    inorder(tree);  puts("");
    
    memset(visited, 0, sizeof(visited));
    postorder(tree); puts("");

    return 0;
}
