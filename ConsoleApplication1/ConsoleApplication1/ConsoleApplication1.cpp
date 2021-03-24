// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "sort.h";
#include "tree.h";

using namespace std;


class LinkNode {

public:
	LinkNode(int data) {
		this->data = data;
	}
public:
	int data;
	LinkNode* Next;
};

class LinkList
{
public:
	LinkNode* head;


public:
	LinkNode* Init(vector<int> data) {
		this->head = new LinkNode(NULL);

		LinkNode* pNode = this->head;
		for (int item : data)
		{
			LinkNode* p = new LinkNode(item);
			pNode->Next = p;
			pNode = p;

		}
		return this->head;
	}

	void Add(LinkNode* node) {

	}
	void Insert(string data, LinkNode* node) {

	}

	LinkNode* Find(int data) {

	}

	void Delete(string data) {

	}
	void Delete(int mink, int maxk) {

		LinkNode* curNode = this->head;

		while (curNode->Next)
		{
			if (mink <= curNode->Next->data && curNode->Next->data <= maxk) {
				curNode->Next = curNode->Next->Next;
			}
			else {
				curNode = curNode->Next;
			}

		}
	}

	bool IsEmpty() {
		return !this->head || !this->head->Next;
	}

	vector<int> Print() {

		vector<int> res;
		LinkNode* cNode = this->head->Next;
		while (cNode)
		{
			res.push_back(cNode->data);
			cNode = cNode->Next;
		}
		return res;
	}

private:
	LinkNode* find(string data) {
	}
};


class Solution {
public:
	std::string longestCommonPrefix(vector<std::string>& strs) {
		int length = strs.size();
		std::string res = "";

		int j = 0;
		while (true) {
			char cur = '0';
			for (int i = 0; i < length; i++) {
				if (j > strs[i].length()) {
					return res;
				}
				char p = strs[i][j];
				if (cur != '0' & cur != p) {
					return res;
				}
				cur = p;
			}
			res += to_string(cur);
			j++;
		}

		return res;

	};

public:
	int bf(string haystack, string needle) {
		int i = 0;
		int j = 0;
		while (i < haystack.length() && j < needle.length()) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}


		if (j >= needle.length()) {
			return i - needle.length();
		}
		else {
			return -1;
		}
	}

public:
	int search_bin(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = left + ((right - left) / 2);
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				return mid;
			}
		}
		return right + 1;


		/*int n = nums.size();
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int middle = left + ((right - left) / 2);
			if (nums[middle] > target) {
				right = middle - 1;
			}
			else if (nums[middle] < target) {
				left = middle + 1;
			}
			else {
				return middle;
			}
		}
		return right + 1;*/
	}


	static bool isNString(string data) {
		unordered_map<char, int> cmap;
		char first = data[0];
		for (char c : data) {
			cmap[c] ++;
		}

		int i = 0;
		for (auto item : cmap) {
			i++;
			if (item.second != cmap[first]) {
				return false;
			}
		}
		return i == 3;
	}

};

void Print(vector<int>data) {
	for (int item : data)
	{
		cout << item << endl;
	}
}
void Print(vector<char>data) {
	for (char item : data)
	{
		cout << item << endl;
	}

}

bool SortTest(vector<int> data, vector<int> expect, string type = "BubbleSort") {
	vector<int> res;
	if (type == "BubbleSort") {
		res = Sort::BubbleSort(data);
	}
	else if (type == "QuickSort") {
		res = Sort::QuickSort(data);
	}
	else if (type == "SelectSort") {
		res = Sort::SelectSort(data);
	}

	if (res.size() != expect.size()) {
		return false;
	}
	for (int i = 0; i < expect.size(); i++)
	{
		if (expect[i] != res[i]) {
			return false;
		}

	}


	return true;
}




void main_sort()
{
	std::cout << "Hello World!\n";
	//Solution a;

	/*std::vector<std::string> data = { "asd","asdea" };
	string b = a.longestCommonPrefix(data);*/
	//int res = a.bf("Hello", "ll");

	vector<int> data = { 2,3,1,5 };
	vector<int> expect = { 1,2,3,5 };
	bool isPass = false;
	//int res = 0;
	/*res = a.search_bin(data,0);
	cout << to_string(res);*/

	/*data = { 1,3,5,7 };
	res = a.search_bin(data, 6);
	cout << to_string(res);*/
	//vector<int>res = a.InsertSort(data);
	vector<int> filter = { };
	vector<int>res = Sort::CountSort(data, filter);

	/*string testFunc = "BubbleSort";*/
	/*string testFunc = "QuickSort";*/
	string testFunc = "SelectSort";

	isPass = SortTest(data, expect, testFunc);
	cout << isPass;

	data = { 1 };
	expect = { 1 };
	isPass = SortTest(data, expect, testFunc);
	cout << isPass <<endl;

	data = {  };
	expect = {  };
	isPass = SortTest(data, expect, testFunc);
	cout << isPass << endl;

	data = { 1,1,1,1,1 };
	expect = { 1,1,1,1,1 };
	isPass = SortTest(data, expect, testFunc);
	cout << isPass << endl;

	data = { 1,3,3,3,1 };
	expect = { 1,1,3,3,3 };
	isPass = SortTest(data, expect, testFunc);
	cout << isPass << endl;

	data = { 9,8,7,6,5,1 };
	expect = { 1,5,6,7,8,9 };
	isPass = SortTest(data, expect, testFunc);
	cout << isPass << endl;

}

void main_tree() {
	vector<char> data_first{ 1,'#',2,3 };
	string data_first2 = "ABC##D#E##F##";
	data_first.clear();
	for (char item : data_first2)
	{
		data_first.push_back(item);
	}

	vector<char> data_bin{ 3,9,20,'#','#',15,7 };
	Tree solution = Tree();



	TreeNode* root = TreeNode::Create(data_first, 0);
	vector<char>* scan = new vector<char>();
	solution.Scan_Mid(root, scan);
	Print(*scan);
	int d = solution.MinDepth(root);
	d = solution.MaxDepth(root);

	char sameParent = solution.GetSameParent(root, 'B', 'E');


	//check same path

}

int main() {
	/*string data;
	cin >> data;

	bool isOk = Solution::isNString(data);*/
	main_sort();

	/*LinkList* list = new LinkList();
	vector<int> d = { 9,1,2,10,2,1,5,8 };
	LinkNode* head = list->Init(d);
	Print(list->Print());
	list->Delete(1, 3);
	Print(list->Print());

	main_tree();*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


