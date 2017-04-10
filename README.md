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
Adding 10 to [btree=0x7ffe837f5540] index1: 0, index2: 0
Adding 30 to [btree=0x7ffe837f5540] index1: 10, index2: 0
Adding 2 to [btree=0x7ffe837f5540] index1: 10, index2: 30
Adding 2 to [btree=0x7ffe837f5510] index1: 0, index2: 0
Adding 19 to [btree=0x7ffe837f5540] index1: 10, index2: 30
Adding 19 to [btree=0x7ffe837f5510] index1: 0, index2: 0
Adding 5 to [btree=0x7ffe837f5540] index1: 10, index2: 30
Adding 5 to [btree=0x7ffe837f5510] index1: 2, index2: 0
Adding 50 to [btree=0x7ffe837f5540] index1: 10, index2: 30
Adding 50 to [btree=0x7ffe837f5510] index1: 0, index2: 0
Adding 20 to [btree=0x7ffe837f5540] index1: 10, index2: 30
Adding 20 to [btree=0x7ffe837f5510] index1: 19, index2: 0
Adding 1 to [btree=0x7ffe837f5540] index1: 10, index2: 30
Adding 1 to [btree=0x7ffe837f5510] index1: 2, index2: 5
Adding 1 to [btree=0x7ffe837f54e0] index1: 0, index2: 0
[tree=0x7ffe837f55b0] index1: 10, index2: 30
[tree=0x7ffe837f55b0] going left
[tree=0x1e4e420] index1: 2, index2: 5
[tree=0x1e4e420] going left
[tree=0x1e4e4b0] index1: 1, index2: 0
[tree=0x7ffe837f55b0] going middle
[tree=0x1e4e450] index1: 19, index2: 20
[tree=0x7ffe837f55b0] going right
[tree=0x1e4e480] index1: 50, index2: 0
```
