# 297. Serialize and Deserialize Binary Tree

**Difficulty:** Hard  
**Topics:** Tree, Depth-First Search, Breadth-First Search, Design, String, Binary Tree  
**Companies:** Amazon, Google, Microsoft, Facebook, Bloomberg

## Problem Description

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

## Examples

### Example 1:
```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Tree structure:
      1
     / \
    2   3
       / \
      4   5
```

### Example 2:
```
Input: root = []
Output: []
```

### Example 3:
```
Input: root = [1]
Output: [1]
```

### Example 4:
```
Input: root = [1,2]
Output: [1,2]
```

## Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`
- `-1000 <= Node.val <= 1000`

## Node Definition

```python
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

## Function Signatures

```python
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
```

## Approach Ideas

### 1. Preorder Traversal (DFS)
- Serialize using preorder traversal with null markers
- Deserialize by reconstructing the tree using the preorder sequence
- Time: O(n), Space: O(n)

### 2. Level Order Traversal (BFS)
- Serialize using level-order traversal with null markers
- Deserialize by reconstructing level by level
- Time: O(n), Space: O(n)

### 3. Postorder + Inorder
- Use two traversals to uniquely identify the tree
- More complex but mathematically elegant
- Time: O(n), Space: O(n)

## Key Points

1. **Null Handling:** Must handle null nodes consistently in both serialization and deserialization
2. **Delimiter Choice:** Choose appropriate delimiters for separating values
3. **Reconstruction Logic:** Ensure the deserialization logic matches the serialization approach
4. **Edge Cases:** Handle empty trees, single nodes, and unbalanced trees

## Test Cases to Consider

- Empty tree: `[]`
- Single node: `[1]`
- Complete binary tree: `[1,2,3,4,5,6,7]`
- Left-skewed tree: `[1,2,null,3,null,null,null]`
- Right-skewed tree: `[1,null,2,null,3]`
- Tree with negative values: `[1,-2,3]`
- Large tree with maximum constraints 
- Trees with repeated values
- Invalid BST's