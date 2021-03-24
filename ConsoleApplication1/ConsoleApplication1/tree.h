#pragma once
#include <vector>




class TreeNode
{
public:
	char Data;
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode* init();
	static  TreeNode* Create(std::vector<char> defineList, int type);


public:
	explicit TreeNode(char data) {
		this->Data = data;
	}
private:
	static	TreeNode* Create_first(std::vector<char> defineList, int* i);
	static	TreeNode* Create_bin(std::vector<char> defineList);

};

class ListItem {
public:
	TreeNode* data;
	ListItem* next;
};

class List
{
private:
	ListItem* end= NULL;
	ListItem* start = new ListItem();

public:
	void push(TreeNode* data) {
		if (this->end == NULL) {
			this->end = new ListItem();
			this->start->next = this->end;
		}
		else {
			this->end->next = new ListItem();
			this->end = this->end->next;
		}
		this->end->data = data;
	}
	TreeNode* pop() {
		if (!this->start||!this->start->next) {
			return NULL;
		}
		TreeNode* data = this->start->next->data;
		this->start = this->start->next;
		return data;

	}
	bool isEmpty() {
		return this->start == this->end || this->start->next== NULL;
	}
};


class Tree
{
public:
	static int MinDepth(TreeNode* node);
	static int MaxDepth(TreeNode* node);
	void Scan_Mid(TreeNode* root, std::vector<char>* data);
	bool FindPath(TreeNode* root, char data, std::vector<char>* path);
	char GetSameParent(TreeNode* root, char dataA, char dataB);
};