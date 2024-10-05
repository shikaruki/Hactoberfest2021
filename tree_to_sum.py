'''
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree  

                  10
               /      \
             -2        6
           /   \      /  \ 
         8     -4    7    5
should be changed to 

                 20(4-2+12+6)
               /      \
         4(8-4)      12(7+5)
           /   \      /  \ 
         0      0    0    0
'''

class node:
     
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
 
# Convert a given tree to a tree where
# every node contains sum of values of
# nodes in left and right subtrees
# in the original tree
def toSumTree(Node) :
     
    # Base case
    if(Node == None) :
        return 0
 
    # Store the old value
    old_val = Node.data
 
    # Recursively call for left and
    # right subtrees and store the sum as
    # new value of this node
    Node.data = toSumTree(Node.left) + \
                toSumTree(Node.right)
 
    # Return the sum of values of nodes
    # in left and right subtrees and
    # old_value of this node
    return Node.data + old_val
 
# A utility function to print
# inorder traversal of a Binary Tree
def printInorder(Node) :
    if (Node == None) :
        return
    printInorder(Node.left)
    print(Node.data, end = " ")
    printInorder(Node.right)
     
# Utility function to create a new Binary Tree node
def newNode(data) :
    temp = node(0)
    temp.data = data
    temp.left = None
    temp.right = None
     
    return temp
 
# Driver Code
if __name__ == "__main__":
    root = None
    x = 0
     
    # Constructing tree given in the above figure
    root = newNode(10)
    root.left = newNode(-2)
    root.right = newNode(6)
    root.left.left = newNode(8)
    root.left.right = newNode(-4)
    root.right.left = newNode(7)
    root.right.right = newNode(5)
     
    toSumTree(root)
     
    # Print inorder traversal of the converted
    # tree to test result of toSumTree()
    print("Inorder Traversal of the resultant tree is: ")
    printInorder(root)
