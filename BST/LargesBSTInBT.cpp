#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	Node* left;
	Node* right;
	int data;
	Node(int val){
		data = val;
		left =NULL;
		right = NULL;
	}
};

struct info{
	int size;
	
	int max;
	int min;
	int ans;
	bool isBST;

};

info largestBSTinBT(Node* root){
	if(root==NULL){
		return {0,INT_MIN,INT_MAX,0,true};
	}
	if(root->left==NULL&&root->right==NULL){
		return {1,root->data,root->data,1,true};
	}
	info leftside = largestBSTinBT(root->left);
	info rightside = largestBSTinBT(root->right);

	info curr;
	curr.size = (1+leftside.size+rightside.size);

	if(leftside.isBST && rightside.isBST && leftside.max<root->data && root->data<rightside.min){
			curr.min =min(leftside.min,min(rightside.min,root->data));

		curr.max =max(leftside.max,max(rightside.max,root->data));
		curr.ans = curr.size;
		curr.isBST=true;
	

		return curr;
	}
	curr.ans=max(leftside.ans,rightside.ans);
	curr.isBST=false;
	return curr;
}
int main(int argc, char const *argv[])
{
	Node* root = new Node(15);
	root->left = new Node(3);
	root->right=new Node(30);
	root->left->left=new Node(22);
	root->right->left= new Node(23);

// Zigzag(root);
cout<<largestBSTinBT(root).ans;

	return 0;
}