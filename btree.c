#include <stdio.h>
#include <stdlib.h>

typedef struct btree btree;

struct btree {
    int index1;
    int index2;
    btree *node_left;
    btree *node_middle;
    btree *node_right;
};

btree *get_btree() {
    btree *tree = malloc(sizeof(btree));

    tree->index1 = 0;
    tree->index2 = 0;
    tree->node_left = 0;
    tree->node_middle = 0;
    tree->node_right = 0;

    return tree;
}

void add_to_btree(int number, btree *tree) {
    printf("Adding %d to [btree=%p] index1: %d, index2: %d\n", number, &tree, tree->index1, tree->index2);

    if (tree->index1 == 0) {
        tree->index1 = number;
    } else if (number > tree->index1 && tree->index2 == 0) {
        tree->index2 = number;
    } else if (number < tree->index1) {
        if (tree->node_left == NULL) {
            tree->node_left = get_btree();
        }
        add_to_btree(number, tree->node_left);
    } else if (number > tree->index2) {
        if (tree->node_right == NULL) {
            tree->node_right = get_btree();
        }
        add_to_btree(number, tree->node_right);
    } else if (number > tree->index1 && number < tree->index2) {
        if (tree->node_middle == NULL) {
            tree->node_middle = get_btree();
        }
        add_to_btree(number, tree->node_middle);
    }
}

void create_btree(int *list, size_t length, btree *tree) {
    tree->index1=0;
    tree->index2=0;
    tree->node_left=NULL;
    tree->node_middle=NULL;
    tree->node_right=NULL;
    
    for (int i; i < length; i++) {
        add_to_btree(list[i], tree);
    }
}

void print_tree(btree *tree) {
    printf("[tree=%p] index1: %d, index2: %d\n", tree, tree->index1, tree->index2);

    if (tree->node_left != NULL) {
        printf("[tree=%p] going left\n", tree);
        print_tree(tree->node_left);
    }
    if (tree->node_middle != NULL) {
        printf("[tree=%p] going middle\n", tree);
        print_tree(tree->node_middle);
    }
    if (tree->node_right != NULL) {
        printf("[tree=%p] going right\n", tree);
        print_tree(tree->node_right);
    }
}

int main() {
    printf("Btree implementation in C, by <dionbosschieter@gmail.com>\n");

    //int list[] = {1,50,20,30,2,5,10,19};
    int list[] = {10,30,2,19,5,50,20,1};
    size_t listsize = sizeof(list) / sizeof(int);

    btree tree;
    create_btree(list, listsize, &tree);
    print_tree(&tree);
}