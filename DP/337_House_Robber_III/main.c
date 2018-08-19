#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int index;
} TreeNode;


static int max(int a, int b) {
    return a > b ? a : b;
}


int rob(struct TreeNode *node) {

    if (!node)
        return 0;

    int val = node->val;

    if (node->left) {
        val += (rob(node->left->left) + rob(node->left->right));
    }
    if (node->right) {
        val += (rob(node->right->left) + rob(node->right->right));
    }

    return max(val, rob(node->left) + rob(node->right));
}



TreeNode *case1(void) {
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->index = 0;
    root->val = 4;

    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->index = 1;
    root->left->val = 1;
    root->right = NULL;

    root->left->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->left->index = 3;
    root->left->left->val = 2;

    root->left->right = NULL;

    root->left->left->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->left->left->index = 7;
    root->left->left->left->val = 3;

    root->left->left->right = NULL;

    root->left->left->left->left = NULL;
    root->left->left->left->right = NULL;

    return root;
}

TreeNode *case2(void) {
    /*int vals[] = {3,2,3,-1,3,-1,1};*/
    /*int size = sizeof(vals) / sizeof(*vals);*/
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->index = 0;

    root->val = 3;
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->index = 1;
    root->left->val = 2;
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->index = 2;
    root->right->val = 3;

    root->left->left = NULL;
    root->left->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->right->index = 4;
    root->left->right->val = 3;
    root->left->right->left = NULL;
    root->left->right->right = NULL;


    root->right->left = NULL;
    root->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->index = 6;
    root->right->right->val = 1;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    return root;
}

int main(int argc, const char *argv[])
{

    assert(rob(case1()) == 7);
    assert(rob(case2()) == 7);

    return 0;
}
