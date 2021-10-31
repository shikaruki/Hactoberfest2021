/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Node{
    int key;
    Node left, right;
    Node(int key){
        this.key = key;
        left = right = null;
    }
}

class BinarySearchTree{
    Node root;
    
    public void insert(int key){
        root = insertImpl(root, key);
    }
    
    private Node insertImpl(Node node, int key){
        if(node == null){
            node = new Node(key);
            System.out.println("here");
            return node;
        }
            
        if(key < node.key)
            node.left = insertImpl(node.left, key);
        else if(key > node.key)
            node.right = insertImpl(node.right, key);
        return node;
    }
    
    public void inOrder(){
        inOrderImpl(root);
    }
    
    private void inOrderImpl(Node root){
        if(root != null){
            inOrderImpl(root.left);
            System.out.println(root.key);
            inOrderImpl(root.right);
        }
    }
    
    public void count(){
        System.out.println(countImpl(root));
    }
    
    private int countImpl(Node root){
        if(root == null)
            return 0;
            return 1 + countImpl(root.left) + countImpl(root.right);
    }
    
    
    
    public void smallest(){
        System.out.println(smallestImpl(root));
    }
    
    private int smallestImpl(Node root){
        int val=0;
        while(root!=null){
            val = root.key;
            root =  root.left;
        }
        return val;
    }
    
    public void largest(){
        System.out.println(largestImpl(root));
    }
    
    private int largestImpl(Node root){
        int val=0;
        while(root!=null){
            val = root.key;
            root =  root.right;
        }
        return val;
    }
}
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BinarySearchTree bst = new BinarySearchTree();
		bst.insert(1);
		System.out.println(bst.root.key);
		bst.insert(2);
		System.out.println(bst.root.key);
		bst.insert(3);
		bst.inOrder();
		System.out.println("smallest:");
		bst.smallest();
		bst.largest();
		bst.count();
	}
}
