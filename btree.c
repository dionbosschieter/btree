#include <stdio.h>
#include <stdlib.h>

typedef struct btree btree;

struct btree {
    int index1;
    int index2;

    btree *parent;
    btree *node_left;
    btree *node_middle;
    btree *node_right;
};

struct btreecontainer {
    btree *firstnode;
} typedef btreecontainer;

btree *get_btree(int number) {
    btree *tree = malloc(sizeof(btree));
    tree->index1 = number;

    return tree;
}

void print_tree(btree *tree) {
    printf("[tree=%p] [parent=%p] index1: %d, index2: %d\n", tree, tree->parent, tree->index1, tree->index2);

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

btree *get_last_leaf(int number, btree *tree) {
    if (tree->index1 == 0) {
        return tree;
    } else if (number < tree->index1 && tree->node_left != NULL) {
        return get_last_leaf(number, tree->node_left);
    } else if (number > tree->index1 && number < tree->index2 && tree->node_middle != NULL) {
        return get_last_leaf(number, tree->node_middle);
    } else if (number > tree->index2 && tree->node_right != NULL) {
        return get_last_leaf(number, tree->node_right);
    }

    return tree;
}

btree *insert_number_to_node(int number, btree *tree, btreecontainer *container) {
    if (tree->index1 == 0) {
        tree->index1 = number;
        printf("Adding %d to index1 of [btree=%p] index1: %d, index2: %d\n", number, &tree, tree->index1, tree->index2);
    } else if (tree->index2 == 0 && number > tree->index1) {
        printf("Adding %d to index2 of [btree=%p] index1: %d, index2: %d\n", number, &tree, tree->index1, tree->index2);
        tree->index2 = number;
    } else if (number < tree->index1 && tree->index2 == 0) {
        tree->index2 = tree->index1;
        tree->index1 = number;
        printf("Adding %d to index1 (moving current index1 to index2) of [btree=%p] index1: %d, index2: %d\n", number, &tree, tree->index1, tree->index2);
    } else if (tree->index1 != 0 && tree->index2 != 0) {
        // break this node
        // calculate middle number
        // split node into 2 nodes
        // move middle number
        int numtomoveup = 0;
        printf("We need to split [btree=%p] (%d,%d)\n", tree, tree->index1, tree->index2);
        if (number < tree->index1) {
            numtomoveup = tree->index1;
            tree->index1 = number;
        } else if (number > tree->index2) {
            numtomoveup = tree->index2;
            tree->index2 = number;
        } else {
            numtomoveup = number;
        }

        printf("We need to move %d up to the tree and split %d and %d\n", numtomoveup, tree->index1, tree->index2);
        btree *newnode = get_btree(tree->index2);
        tree->index2 = 0;

        if (tree->parent != NULL) {
            btree *parent = tree->parent;
            newnode->parent = parent;
            if (parent->node_right == NULL) {
                parent->node_right = newnode;
                insert_number_to_node(numtomoveup, parent, container);
            } else if (parent->node_middle == NULL) {
                parent->node_middle = newnode;
                insert_number_to_node(numtomoveup, parent, container);
            } else { // if left middle right are set

                // solution: move num up and save new split parent to temp variable
                btree *newparent = insert_number_to_node(numtomoveup, parent, container);
                if (newparent == NULL) {
                    printf("Got no new parent exiting\n");
                    exit(2);
                }
                newparent->parent = parent->parent;

                // so now we have parent and newparent
                //  assign left,middle,right,newnode to parent and newparent
                if (newnode->index1 < parent->node_left->index1) {
                    printf("Newnode will be node_left of parent\n");
                    newparent->node_right = parent->node_right;
                    newparent->node_left = parent->node_middle;
                    parent->node_right = parent->node_left;
                    parent->node_left = newnode;
                    parent->node_middle = NULL;
                } else if (newnode->index1 < parent->node_middle->index1) {
                    printf("Newnode will be node_right of parent\n");
                    newparent->node_right = parent->node_right;
                    newparent->node_left = parent->node_middle;
                    parent->node_right = newnode;
                    parent->node_middle = NULL;
                } else if (newnode->index1 < parent->node_right->index1) {
                    printf("Newnode [num=%d] will be node_left of newparent [parent->node_right->index1=%d]\n", newnode->index1, parent->node_right->index1);
                    newparent->node_right = parent->node_right;
                    newparent->node_left = newnode;
                    parent->node_right = parent->node_middle;
                    parent->node_middle = NULL;
                } else if (newnode->index1 > parent->node_right->index1) {
                    printf("Newnode will be node_right of newparent\n");
                    newparent->node_right = newnode;
                    newparent->node_left = parent->node_right;
                    parent->node_right = parent->node_middle;
                    parent->node_middle = NULL;
                } else {
                    printf("Error: unexpected codepath\n");
                    exit(3);
                }
            }

            return newnode;
        } else { // this is THE top of the three, also change the btree_container
            btree *parent = get_btree(numtomoveup);
            container->firstnode = parent;
            parent->node_right = newnode;
            parent->node_left = tree;

            tree->parent = parent;
            newnode->parent = parent;

            return newnode;
        }

        printf("\n------------\n");
        print_tree(container->firstnode);
        printf("------------\n");

    }

    return NULL;
}

void add_to_btree(int number, btreecontainer *container) {
    // walk three and insert in node, 
    // if index1 and index2 is used split and move number up, insert in node
    // if index1 and index2 is used split and move number up, insert in node
    // ...
    btree *last_leaf = get_last_leaf(number, container->firstnode);

    // insert or split and move back up the tree
    insert_number_to_node(number, last_leaf, container);
}

void create_btree(int *list, size_t length, btreecontainer *container) {
    container->firstnode = get_btree(0);

    for (int i; i < length; i++) {
        add_to_btree(list[i], container);
    }
}

int main() {
    printf("Btree implementation in C, by <dionbosschieter@gmail.com>\n");

    int list[] = {1,50,20,30,2,5,10,19};
    // int list[] = {1,50,20,30,2,5,10,19};
    // int list[] = {10,30,2,19,5,50,20,1};
    size_t listsize = sizeof(list) / sizeof(int);

    btreecontainer container;
    create_btree(list, listsize, &container);
    printf("\n------end------\n");
    print_tree(container.firstnode);
    printf("------------\n");
}