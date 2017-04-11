# btree

Description
-----------
```bash
# insert number to btree
get first node

    on number=3 split

    struct btree {
        node *topnode
        size_t nodecount;
    }

    struct node {
        int index1
        int index2
        node *parent
        node *left
        node *right
        node *middle
    }

    loop:>
        if is between left and right persuit middle
        if is smaller than left persuit left
        if is smaller than right persuit right
    till we find a node without (leafs/subnodes/relationships)

    add to index1 or index2 if both set split to 2 seperate nodes and move 1 up the three and add to either index1 or index2
            -> if that one ALSO has index1 and index2 split that one in 2 seperate nodes and move 1 up the three

```

Usage
-----
Compile with: ```gcc -Wall btree.c -o btree```

Run with: ```./btree```

```bash
Btree implementation in C, by <dionbosschieter@gmail.com>
Adding 1 to index1 of [btree=0x7fffffffe4a0] index1: 1, index2: 0
Adding 50 to index2 of [btree=0x7fffffffe4a0] index1: 1, index2: 0
We need to split [btree=0x603420] (1,50)
We need to move 20 up to the tree and split 1 and 50
Adding 30 to index1 (moving current index1 to index2) of [btree=0x7fffffffe4a0] index1: 30, index2: 50
Adding 2 to index2 of [btree=0x7fffffffe4a0] index1: 1, index2: 0
We need to split [btree=0x603420] (1,2)
We need to move 2 up to the tree and split 1 and 5
Adding 2 to index1 (moving current index1 to index2) of [btree=0x7fffffffe440] index1: 2, index2: 20
Adding 10 to index2 of [btree=0x7fffffffe4a0] index1: 5, index2: 0
We need to split [btree=0x6034b0] (5,10)
We need to move 10 up to the tree and split 5 and 19
We need to split [btree=0x603480] (2,20)
We need to move 10 up to the tree and split 2 and 20
Newnode [num=19] will be node_left of newparent [parent->node_right->index1=30]

------end------
[tree=0x603540] [parent=(nil)] index1: 10, index2: 0
[tree=0x603540] going left
[tree=0x603480] [parent=0x603540] index1: 2, index2: 0
[tree=0x603480] going left
[tree=0x603420] [parent=0x603480] index1: 1, index2: 0
[tree=0x603480] going right
[tree=0x6034b0] [parent=0x603480] index1: 5, index2: 0
[tree=0x603540] going right
[tree=0x603510] [parent=0x603540] index1: 20, index2: 0
[tree=0x603510] going left
[tree=0x6034e0] [parent=0x603480] index1: 19, index2: 0
[tree=0x603510] going right
[tree=0x603450] [parent=0x603480] index1: 30, index2: 50
------------
```
