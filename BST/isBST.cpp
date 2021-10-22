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

bool isSorted(Node* root,Node* min = NULL,Node* max=NULL){
	if(root==NULL)return true;
	if(min!=NULL&& root->data<= min->data)return false;
	if(max!=NULL && root->data>=max->data)return false;

	bool leftValid = isSorted(root->left,min,root);
	bool rightValid = isSorted(root->right,root,max);
	return leftValid&&rightValid;
}


void preorder(Node* root){
	if(root==NULL)return ;
	cout<<root->data<<" ";
	preorder(root->left);

	preorder(root->right);
}

int main(){
	Node *root = new Node(2);
	root->left = new Node(1);
	root->right =new Node(3);
	preorder(root);
	cout<<isSorted(root);
	return 0;

}