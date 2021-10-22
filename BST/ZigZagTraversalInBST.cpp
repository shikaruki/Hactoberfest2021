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


void Zigzag(Node* root){
	if(root==NULL){
		return ; 
	}
	stack<Node*>st1,st2;
	st1.push(root);
	Node* temp;
	while(!st1.empty()|| !st2.empty()){
		while(!st1.empty()){
			temp = st1.top();
			st1.pop();
			cout<<temp->data<<" ";

			if(temp->left){
				st2.push(temp->left);
			}
			if(temp->right){
				st2.push(temp->right);
			}
		}
		while(!st2.empty()){
			temp = st2.top();
			st2.pop();
			cout<<temp->data<<" ";
			if(temp->right)st1.push(temp->right);
			if(temp->left)st1.push(temp->left);
		}
	}

}

int main(int argc, char const *argv[])
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->left= new Node(5);

Zigzag(root);

	return 0;
}