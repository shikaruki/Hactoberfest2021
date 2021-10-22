#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val){
		data = val;
		left=NULL;
		right = NULL;
	}
};

vector<Node*> ConstructTrees(int start,int end){
	vector<Node*>trees;
	if(start>end){
		trees.push_back(NULL);
		return trees;
	}

	for (int i = start; i <= end; ++i)
	{
		vector<Node*> leftSubtress = ConstructTrees(start,i-1);
		vector<Node*> rightSubtrees = ConstructTrees(i+1,end);
		for(int j=0;j<leftSubtress.size();j++){
			Node* left = leftSubtress[j];
			for(int k=0;k<rightSubtrees.size();k++){
				Node* right = rightSubtrees[k];
				Node* node =new Node(i);
				node->left=left;
				node->right = right;
				trees.push_back(node);
			}
		}
	}
	return trees;
}

void preorder(Node* root){
	if(root==NULL)return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	vector<Node*>trees;
	trees = ConstructTrees(0,3);
	for (int i = 0; i <trees.size() ; ++i)
	{
		cout<<i<<" : ";
		preorder(trees[i]);
		cout<<endl;

	}
	return 0;
}