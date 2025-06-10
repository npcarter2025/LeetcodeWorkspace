#include <iostream>
#include <cassert>
#include "serialize_and_deserialize_binary_tree.cpp"

using namespace std;

// Helper function to check if two trees are equal
bool treesEqual(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return t1->val == t2->val && 
           treesEqual(t1->left, t2->left) && 
           treesEqual(t1->right, t2->right);
}

// Helper function to delete tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// NOTE: These tests are currently disabled because the implementation is not complete.
// Uncomment and use these tests once you implement the serialize/deserialize methods.

/*
void testExample1() {
    cout << "Testing Example 1: [1,2,3,null,null,4,5]..." << endl;
    
    // Create tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    Codec codec;
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    assert(treesEqual(root, deserialized));
    cout << "✓ PASS" << endl;
    
    deleteTree(root);
    deleteTree(deserialized);
}

void testEmptyTree() {
    cout << "Testing empty tree..." << endl;
    
    TreeNode* root = nullptr;
    
    Codec codec;
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    assert(deserialized == nullptr);
    cout << "✓ PASS" << endl;
}

void testSingleNode() {
    cout << "Testing single node [1]..." << endl;
    
    TreeNode* root = new TreeNode(1);
    
    Codec codec;
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    assert(treesEqual(root, deserialized));
    cout << "✓ PASS" << endl;
    
    deleteTree(root);
    deleteTree(deserialized);
}

void testLeftSkewedTree() {
    cout << "Testing left-skewed tree..." << endl;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    Codec codec;
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    assert(treesEqual(root, deserialized));
    cout << "✓ PASS" << endl;
    
    deleteTree(root);
    deleteTree(deserialized);
}

void testRightSkewedTree() {
    cout << "Testing right-skewed tree..." << endl;
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    
    Codec codec;
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    assert(treesEqual(root, deserialized));
    cout << "✓ PASS" << endl;
    
    deleteTree(root);
    deleteTree(deserialized);
}

void testNegativeValues() {
    cout << "Testing negative values..." << endl;
    
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(3);
    
    Codec codec;
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize(serialized);
    
    assert(treesEqual(root, deserialized));
    cout << "✓ PASS" << endl;
    
    deleteTree(root);
    deleteTree(deserialized);
}
*/

void testBasicStructure() {
    cout << "Testing basic structure (no implementation yet)..." << endl;
    
    // Just test that we can create the codec object
    Codec codec;
    TreeNode* root = new TreeNode(1);
    
    // Test that methods exist (they return empty/null for now)
    string serialized = codec.serialize(root);
    TreeNode* deserialized = codec.deserialize("test");
    
    cout << "✓ Basic structure is set up correctly" << endl;
    cout << "  - serialize() returns: \"" << serialized << "\"" << endl;
    cout << "  - deserialize() returns: " << (deserialized ? "TreeNode*" : "nullptr") << endl;
    
    deleteTree(root);
    if (deserialized) deleteTree(deserialized);
}

int main() {
    cout << "Serialize and Deserialize Binary Tree - C++ Setup Test" << endl;
    cout << "====================================================" << endl;
    cout << "NOTE: Implementation is not complete yet." << endl;
    cout << "Uncomment tests in this file once you implement the solution." << endl;
    cout << "====================================================" << endl;
    
    testBasicStructure();
    
    cout << "====================================================" << endl;
    cout << "Setup complete! Ready for implementation. ✓" << endl;
    
    return 0;
} 