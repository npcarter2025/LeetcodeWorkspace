# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """

        stack = []
        def preOrder(node):
            if not node:
                stack.append("null")
                return
            stack.append(str(node.val))
            preOrder(node.left)
            preOrder(node.right)
        preOrder(root)
        print(stack)
        result = ','.join(stack)
        return result
        # #left, right, root
        # postStack = []
        # #left, root, right
        # inStack = []
        
        # def postOrder(node):
        #     if not node:
        #         return
        #     postOrder(node.left)
        #     postOrder(node.right)
        #     postStack.append(node.val)
        #     return

        # def inorder(node):
        #     if not node:
        #         return
        #     inorder(node.left)
        #     inStack.append(node.val)
        #     inorder(node.right)
        #     return
        # postOrder(root)
        # inorder(root)

        # postString = ",".join(str(num) for num in postStack)
        # inString = ",".join(str(elem) for elem in inStack)

        # result = postString+","+inString

        # print(result)

        # return result


        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """

        values = iter(data.split(','))

        def constructTree():
            val = next(values)
            if val == "null":
                return None
            node = TreeNode(int(val))
            node.left = constructTree()
            node.right = constructTree()
            return node
        return constructTree()









        # if data == "bruh":
        #     return [3,2,4,3]
        # if data == ",":
        #     return None
        # print(data)
        # middle = len(data)//2
        # postOrder = [int(x) for x in data[:middle].split(",")]
        # inOrder = [int(x) for x in data[middle+1:].split(",")]
        # print(postOrder)
        # print(inOrder)

        # def constructBinaryTree(inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        #     if not inorder or not postorder:
        #         return None

        #     root_val = postorder[-1]
        #     root = TreeNode(root_val)
        #     mid_idx = inorder.index(root_val)

        #     root.left = constructBinaryTree(inorder[:mid_idx], postorder[:mid_idx])
        #     root.right = constructBinaryTree(inorder[mid_idx+1:], postorder[mid_idx:-1])
            
        #     return root
        
        # def buildTree(preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        #     if not inorder or not preorder:
        #         return None
        #     root = TreeNode(preorder[0])

        #     middle = inorder.index(preorder[0])

        #     root.left = self.buildTree(preorder[1:1+middle], inorder[:middle])
        #     root.right = self.buildTree(preorder[1+middle:], inorder[middle+1:])

        #     return root

        # #result = constructBinaryTree(preOrder, inOrder)
        # result = constructBinaryTree(inOrder, postOrder)

        # return result



        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))