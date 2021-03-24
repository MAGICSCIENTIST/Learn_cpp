#pragma once
#include <vector>
#include "tree.h";
using namespace std;

TreeNode* TreeNode::init() {
	return new TreeNode(NULL);
}
//Ç°ÐòÉú³É
TreeNode* TreeNode::Create(vector<char> defineList, int type = 0) {
	int index = 0;
	int* i = &index;
	if (type == 0) {
		return Create_first(defineList, i);
	}
	else {
		return Create_bin(defineList);
	}

}

TreeNode* TreeNode::Create_first(vector<char> defineList, int* i) {
	if (*i >= defineList.size()) {
		return NULL;
	}
	char data = defineList[*i];
	(*i)++;

	if (data == '#') {
		return NULL;
	}
	TreeNode* node = new TreeNode(data);
	node->left = Create_first(defineList, i);
	node->right = Create_first(defineList, i);
	return node;

}

TreeNode* TreeNode::Create_bin(vector<char> defineList) {

	List queue = List();
	int i = 0;
	if (i >= defineList.size() || defineList[i] == '#') {
		return NULL;
	}


	char data = defineList[i];
	i++;
	TreeNode* root = new TreeNode(data);
	queue.push(root);


	while (!queue.isEmpty()) {
		TreeNode* node = queue.pop();
		if (i < defineList.size() && defineList[i] != '#') {
			node->left = new TreeNode(defineList[i]);
			queue.push(node->left);
		}
		i++;

		if (i < defineList.size() && defineList[i] != '#') {
			node->right = new TreeNode(defineList[i]);
			queue.push(node->right);
		}
		i++;

	}
	return root;

}


void Tree::Scan_Mid(TreeNode* root,vector<char>* data) {
	if (!root) {
		return ;
	}	
	Scan_Mid(root->left,data);
	(*data).push_back(root->Data);
	Scan_Mid(root->right,data);	
}
int Tree::MaxDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}

	int leftDepth = MaxDepth(root->left);
	int rightDepth = MaxDepth(root->right);
	if (leftDepth && rightDepth) {
		return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
	}
	else {
		return leftDepth + rightDepth + 1;
	}

	return 0;
}

bool Tree::FindPath(TreeNode* root, char data, vector<char>* path) {
	if (!root) {
		return false;
	}

	path->push_back(root->Data);
	if (root->Data == data) {
		return true;
	}

	if (FindPath(root->left, data, path)|| FindPath(root->right, data, path)) {		
		return true;
	}	
	else {
		path->pop_back();
		return false;
	}
}

char Tree :: GetSameParent(TreeNode* root, char dataA, char dataB) {
	vector<char>* scan1 = new vector<char>();
	vector<char>* scan2 = new vector<char>();
	
	if (!Tree::FindPath(root, dataA, scan1) || !Tree::FindPath(root, dataB, scan2)) {
		return NULL;
	}
	
	vector<char>* maxPath = scan1->size() > scan2->size() ? scan1 : scan2;
	vector<char>* minPath = scan1->size() > scan2->size() ? scan2 : scan1;

	for (int i = minPath->size()-1; i >= 0;i--) {
		char itemMin = (*minPath)[i];
		for (char itemMax:*maxPath)
		{
			if (itemMin == itemMax) {
				return  itemMax;
			}
		}			
	}
	return NULL;


}

int Tree::MinDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}

	int leftDepth = MinDepth(root->left);
	int rightDepth = MinDepth(root->right);
	if (leftDepth && rightDepth) {
		return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	else {
		return leftDepth + rightDepth + 1;
	}
}







