# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        #left, right, root
        postStack = []
        #left, root, right
        inStack = []
        
        def postOrder(node):
            if not node:
                return
            postOrder(node.left)
            postOrder(node.right)
            postStack.append(node.val)
            return

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            inStack.append(node.val)
            inorder(node.right)
            return
        postOrder(root)
        inorder(root)

        postString = ",".join(str(num) for num in postStack)
        inString = ",".join(str(elem) for elem in inStack)

        result = postString+","+inString

        print(result)
        return result



    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if data == ",":
            return None
        print(data)
        middle = len(data)//2
        postOrder = [int(x) for x in data[:middle].split(",")]
        inOrder = [int(x) for x in data[middle+1:].split(",")]
        print(postOrder)
        print(inOrder)

        def constructBinaryTree(inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
            if not inorder or not postorder:
                return None

            root_val = postorder[-1]
            root = TreeNode(root_val)
            mid_idx = inorder.index(root_val)

            root.left = constructBinaryTree(inorder[:mid_idx], postorder[:mid_idx])
            root.right = constructBinaryTree(inorder[mid_idx+1:], postorder[mid_idx:-1])
            
            return root


        result = constructBinaryTree(inOrder, postOrder)

        return result





# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans