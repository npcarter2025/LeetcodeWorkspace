#include <string>
#include <sstream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // TODO: Implement your serialization logic here
        return "";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // TODO: Implement your deserialization logic here
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root)); 