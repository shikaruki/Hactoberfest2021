#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
	Node(int val){
		data = val;
		right =NULL;
		left = NULL;
	}
};

Node* insertion(Node* root,int val){
	if(root==NULL){
		return new Node(val);
	}
	if(root->data>val){
		root->left = insertion(root->left,val);
	}else{
		root->right = insertion(root->right,val);
	}
	return root;
}
void inorder(Node* root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	Node* root = new Node(9);;
	insertion(root,3);
	insertion(root,8);
	insertion(root,1);
	insertion(root,2);
	insertion(root,84);
	insertion(root,7);
	insertion(root,9);
	inorder(root);
	return 0;

}