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

Node* sortedArrToBST(int arr[],int st,int end){
	if(st>end){
		return NULL;
	}

	int mid=(st+end)/2;
	Node* root = new Node(arr[mid]);

	
		root->left = sortedArrToBST(arr,st,mid-1);



		root->right = sortedArrToBST(arr,mid+1,end);

	return root;

}
void preorder(Node* root){
	if(root==NULL)return ;
	cout<<root->data<<" ";
	preorder(root->left);

	preorder(root->right);
}

int main(){
	int arr[]={10,20,30,40,50};
	Node* root = sortedArrToBST(arr,0,4);
	preorder(root);

	return 0;

}