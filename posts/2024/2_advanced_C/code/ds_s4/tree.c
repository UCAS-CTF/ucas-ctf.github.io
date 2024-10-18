#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
struct node {
    int id;                     // 这个结点的id，这个数据不是必须的，此处加上id是为了方便理解
    ElemType data;              // 这个元素所保存的数据
    struct node *lc, *rc;       // 左右儿子指针，分别指向这个节点的左右儿子
};

struct node *root;              // 根结点指针

#define NewSpace (struct node *)malloc(sizeof(struct node))

#define N 1000
int n;
int lchild[N], rchild[N];

struct node *build(int id);
void preorder(struct node *now);
void inorder(struct node *now);
void postorder(struct node *now);

int main() {
	int i; 
    scanf("%d", &n);                                // 约定的输入格式：第一行一个整数n，代表树中结点个数
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &lchild[i], &rchild[i]);      // 约定的输入格式：接下来n行，每行两个整数，代表第i个结点的左右子结点id，
    }
    root = build(1);                                // 从根结点开始递归构建整棵树
    printf("Preorder Traversal:\n");
	preorder(root);
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\nPostorder Traversal:\n");
    postorder(root);
    printf("\n");
}

struct node *build(int id) {
    if (!id) {                      // 按照约定，id为0时代表空结点
        return NULL;
    }
    struct node *now = NewSpace;    // 构建当前结点
    now->id = id;
    now->lc = build(lchild[id]);    // 递归构建左子树
    now->rc = build(rchild[id]);    // 递归构建右子树
}

void preorder(struct node *now) {   
    if (now == NULL) {              // 走到空结点，直接返回
        return;
    }
    printf("%d ", now->id);         // 访问当前结点
    preorder(now->lc);              // 递归访问左子树
    preorder(now->rc);              // 递归访问右子树
}

void inorder(struct node *now) {
    if (now == NULL) {              // 走到空结点，直接返回
        return;
    }
    inorder(now->lc);              // 递归访问左子树         
    printf("%d ", now->id);        // 访问当前结点
    inorder(now->rc);              // 递归访问右子树
}

void postorder(struct node *now) {
    if (now == NULL) {              // 走到空结点，直接返回
        return;
    }
    postorder(now->lc);             // 递归访问左子树
    postorder(now->rc);             // 递归访问右子树
    printf("%d ", now->id);         // 访问当前结点
}
