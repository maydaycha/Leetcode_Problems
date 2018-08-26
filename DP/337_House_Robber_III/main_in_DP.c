#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/************************************************************
 *
 *  Fail in hash collision if number of node is too large.
 *
 ************************************************************/


#define HASH_MAP_SIZE  0x1000
#define MASK           0xfff


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int index;
} TreeNode;

typedef struct HashNode {
    unsigned long key;
    int val;
    struct HashNode *next;
} HashNode;


static int max(int a, int b) {
    return a > b ? a : b;
}

static unsigned hash(unsigned long key) {
    return key & MASK;
}

static int get_val(unsigned long key, HashNode **hash_map) {
    HashNode *entry = hash_map[hash(key)];

    while (entry != NULL && entry->key != key) {
        entry = entry->next;
    }

    return entry ? entry->val : -1;
}

static void put_val(unsigned long key, int val, HashNode **hash_map) {
    unsigned int index = hash(key);
    HashNode *prev = NULL;
    HashNode *entry = hash_map[index];

    while (entry != NULL && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }

    if (!entry) {
        entry = malloc(sizeof(HashNode));
        if (!entry)
            return;
        entry->key = key;
        entry->val = val;
        entry->next = NULL;

        if (!prev) {
            hash_map[index] = entry;
        } else {
            prev->next = entry;
        }
    } else {
        entry->val = val;
    }
}


int rob_max(struct TreeNode *node, HashNode **hash_map) {
    int m = 0, val = 0;

    if (!node)
        return 0;
    else if ((val = get_val((unsigned long)node, hash_map)) >= 0)
        return val;

    val = node->val;

    if (node->left) {
        val += (rob_max(node->left->left, hash_map) + rob_max(node->left->right, hash_map));
    }
    if (node->right) {
        val += (rob_max(node->right->left, hash_map) + rob_max(node->right->right, hash_map));
    }

    m = max(val, rob_max(node->left, hash_map) + rob_max(node->right, hash_map));
    put_val((unsigned long)node, m, hash_map);

    return m;
}


int rob(struct TreeNode *node) {
    HashNode *hash_map[HASH_MAP_SIZE];

    memset(hash_map, 0, sizeof(hash_map));

    return rob_max(node, hash_map);
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
