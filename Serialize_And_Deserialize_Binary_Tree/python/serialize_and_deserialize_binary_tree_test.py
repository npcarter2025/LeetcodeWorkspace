import unittest
from serialize_and_deserialize_binary_tree import Codec

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
    def __eq__(self, other):
        """Helper method to compare trees for testing"""
        if not self and not other:
            return True
        if not self or not other:
            return False
        return (self.val == other.val and 
                self.left == other.left and 
                self.right == other.right)


class TestSerializeDeserializeBinaryTree(unittest.TestCase):
    
    def setUp(self):
        """Set up test fixtures before each test method."""
        self.codec = Codec()
    
    def create_tree_from_list(self, values):
        """Helper method to create a binary tree from a list representation"""
        if not values:
            return None
        
        root = TreeNode(values[0])
        queue = [root]
        i = 1
        
        while queue and i < len(values):
            node = queue.pop(0)
            
            # Left child
            if i < len(values) and values[i] is not None:
                node.left = TreeNode(values[i])
                queue.append(node.left)
            i += 1
            
            # Right child
            if i < len(values) and values[i] is not None:
                node.right = TreeNode(values[i])
                queue.append(node.right)
            i += 1
            
        return root
    
    def trees_equal(self, tree1, tree2):
        """Helper method to check if two trees are equal"""
        if not tree1 and not tree2:
            return True
        if not tree1 or not tree2:
            return False
        return (tree1.val == tree2.val and 
                self.trees_equal(tree1.left, tree2.left) and 
                self.trees_equal(tree1.right, tree2.right))
    
    def test_example_1(self):
        """Test Example 1: [1,2,3,null,null,4,5]"""
        # Create tree: [1,2,3,null,null,4,5]
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        root.right.left = TreeNode(4)
        root.right.right = TreeNode(5)
        
        # Serialize and deserialize
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        # Check if trees are equal
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_empty_tree(self):
        """Test Example 2: Empty tree []"""
        root = None
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertIsNone(deserialized)
    
    def test_single_node(self):
        """Test Example 3: Single node [1]"""
        root = TreeNode(1)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_two_nodes(self):
        """Test Example 4: Two nodes [1,2]"""
        root = TreeNode(1)
        root.left = TreeNode(2)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_complete_binary_tree(self):
        """Test complete binary tree [1,2,3,4,5,6,7]"""
        root = self.create_tree_from_list([1, 2, 3, 4, 5, 6, 7])
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_left_skewed_tree(self):
        """Test left-skewed tree"""
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.left.left = TreeNode(3)
        root.left.left.left = TreeNode(4)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_right_skewed_tree(self):
        """Test right-skewed tree"""
        root = TreeNode(1)
        root.right = TreeNode(2)
        root.right.right = TreeNode(3)
        root.right.right.right = TreeNode(4)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_negative_values(self):
        """Test tree with negative values"""
        root = TreeNode(-1)
        root.left = TreeNode(-2)
        root.right = TreeNode(-3)
        root.left.left = TreeNode(-4)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_mixed_positive_negative(self):
        """Test tree with mixed positive and negative values"""
        root = TreeNode(0)
        root.left = TreeNode(-1)
        root.right = TreeNode(1)
        root.left.left = TreeNode(-2)
        root.right.right = TreeNode(2)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_large_values(self):
        """Test tree with large values (within constraints)"""
        root = TreeNode(1000)
        root.left = TreeNode(-1000)
        root.right = TreeNode(999)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_unbalanced_tree(self):
        """Test unbalanced tree"""
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        root.left.left = TreeNode(4)
        root.left.right = TreeNode(5)
        root.right.right = TreeNode(6)
        root.left.left.left = TreeNode(7)
        
        serialized = self.codec.serialize(root)
        deserialized = self.codec.deserialize(serialized)
        
        self.assertTrue(self.trees_equal(root, deserialized))
    
    def test_serialization_format(self):
        """Test that serialization produces a string"""
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        
        serialized = self.codec.serialize(root)
        
        self.assertIsInstance(serialized, str)
        self.assertGreater(len(serialized), 0)
    
    def test_round_trip_consistency(self):
        """Test that multiple serialize-deserialize cycles are consistent"""
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        root.left.left = TreeNode(4)
        
        # First round trip
        serialized1 = self.codec.serialize(root)
        deserialized1 = self.codec.deserialize(serialized1)
        
        # Second round trip
        serialized2 = self.codec.serialize(deserialized1)
        deserialized2 = self.codec.deserialize(serialized2)
        
        # All should be equal
        self.assertTrue(self.trees_equal(root, deserialized1))
        self.assertTrue(self.trees_equal(root, deserialized2))
        self.assertTrue(self.trees_equal(deserialized1, deserialized2))


if __name__ == '__main__':
    unittest.main(verbosity=2) 