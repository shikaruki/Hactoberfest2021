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

bool Search(Node* root,int key){
	if(root==NULL)return 0;
	bool ans=0;
	if(root->data==key)return true;

	if(root->data>key){
		 ans=	Search(root->left,key);
	}else{
		ans =Search(root->right,key);
	}
	return ans;

}


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
	cout<<endl<<Search(root,1);
	return 0;

}