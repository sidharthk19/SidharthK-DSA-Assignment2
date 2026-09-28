# DSA Assignment 2 - Question 11

## Subject
PCCST303 - Data Structures and Algorithms

## Question
A government database stores identification numbers:

A102, A25, A7, B100, B12, A120, B3, A45

## Objectives

1. Implement a Binary Search Tree.
2. Display the inorder traversal.
3. Compare BST Search with Linear Search.
4. Record the number of comparisons.
5. Analyse the effect of key length and insertion order.
6. Compare observed results with theoretical complexity.

## Files

- `source_code/` - C source code
- `input/` - Input data
- `output/` - Program output
- `analysis/` - Complexity analysis, comparison table and conclusion

## Data Structure

Binary Search Tree (BST)

## Algorithms Compared

- BST Search
- Linear Search

## Complexity

### BST Search
Average: O(log n)
Worst: O(n)

### Linear Search
Best: O(1)
Average: O(n)
Worst: O(n)

## Conclusion

The BST provides efficient searching when the tree remains reasonably
balanced. However, insertion order can cause the tree to become
skewed. For a growing database, a self-balancing BST can provide
more consistent search performance.
