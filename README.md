# btree

Usage
-----
Compile with: ```gcc btree.c -o btree```

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
