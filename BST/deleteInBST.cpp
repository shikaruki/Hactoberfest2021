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

Node* inorderSucc(Node* root){
	Node* curr =root;
	while(curr&&curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}


Node* deleteInBST(Node* root,int key){

	if(root==NULL)return NULL;
	if(root->data>key){
		root->left = deleteInBST(root->left,key);
	}
	else if(root->data<key){
		root->right = deleteInBST(root->right,key);
	}
	else{
		// case 1 and 2
		if(root->left==NULL){
			Node* temp =root->left;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp =inorderSucc(root->right);
		root->data = temp->data;
		root->right = deleteInBST(root->right,temp->data);
	}
	return root;
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
	cout<<endl;
	deleteInBST(root,1);
		
	inorder(root);
	return 0;

}