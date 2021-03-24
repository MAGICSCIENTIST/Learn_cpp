#include "sort.h"
#include <vector>
#include <unordered_map>
using namespace std;


Sort::Sort() {

}

vector<int> Sort::CountSort(vector<int> source, vector<int> filter) {
	vector<int> list = source;
	vector<int> last;
	unordered_map<int, int> hashMap;
	for (int i : filter)
	{
		hashMap[i] = 0;
	}
	int offset = 0;
	for (int i = list.size() - 1; i >= 0; i--) {
		int cur = list[i];
		if (hashMap.count(cur) != 0) {
			hashMap[cur]++;
			offset++;
		}
		else {
			last.push_back(list[i]);
			list[i + offset] = list[i];
		}
	}
	int index = 0;
	for (auto item : filter) {
		for (int j = 0; j < hashMap[item]; j++) {
			list[index] = item;
			index++;
		}
	}
	//vector<int> sortedLast = InsertSort(last);
	/*vector<int> sortedLast = BInsertSort(last);*/
	vector<int> sortedLast = ShellSort(last);
	for (int a : sortedLast) {
		list[index] = a;
		index++;
	}


	if (1) {

	}
	else

		return list;


}

vector<int> Sort::InsertSort(vector<int> list) {
	vector<int> res = list;
	for (int i = 1; i < res.size(); i++) {
		if (res[i] < res[i - 1]) {
			int r = res[i];
			res[i] = res[i - 1];
			int j = i - 1;
			for (; j >= 0 && res[j] > r; --j) {
				res[j + 1] = res[j];
			}
			res[j + 1] = r;
		}
	}
	return res;
};

vector<int> Sort::BInsertSort(vector<int> list) {
	vector<int> res = list;
	for (int i = 1; i < res.size(); i++) {
		if (res[i] < res[i - 1]) {
			int cur = res[i];
			res[i] = res[i - 1];
			int low = 0;
			int high = i - 1;
			int mid = (low + high) / 2;
			while (low <= high) {
				if (res[mid] < cur) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}

				mid = (low + high) / 2;
			}
			for (int j = i - 1; j > high; j--) {
				res[j + 1] = res[j];
			}
			res[high + 1] = cur;
		}
	}
	return res;
}

vector<int> Sort::ShellSort(vector<int> list) {
	int t = 0;
	while (t < list.size()) {
		t = 3 * t + 1;
	}
	vector<int> res = list;
	while (t > 0) {
		for (int i = t; i < res.size(); i++) {
			int cur = res[i];
			if (cur < res[i - t]) {
				res[i] = res[i - t];
				int j = i - t;
				for (; j >= 0 && res[j] > cur; j -= t) {
					res[j + t] = res[j];
				}
				res[j + t] = cur;
			}
		}
		t = t / 3;
	}
	return res;

}

vector<int> Sort::BubbleSort(vector<int> list) {

	int flag = 1;
	int m = list.size()-1;
	vector<int> res = list;
	while (m > 0 && flag == 1)
	{
		flag = 0;
		for (int i = 0; i < m; i++)
		{
			if (res[i] > res[i + 1]) {
				int p = res[i]; res[i] = res[i + 1]; res[i + 1] = p;
				flag = 1;
			}
		}
		m--;
	}
	return res;

}

vector<int> Sort::QuickSort(vector<int> list ) {
	vector<int> res = list;
	Sort s = Sort();
	 s.QuickSort_main(res,0,list.size()-1);
	 return res;
}
void Sort::QuickSort_main(vector<int> &list, int low, int high) {
	vector<int>res = list;
	if (low >= high) {
		return;
	}
	int mid = QuickSort_Split(list, low, high);
	QuickSort_main(list, low, mid - 1);
	QuickSort_main(list, mid + 1, high);
}
int Sort::QuickSort_Split(vector<int> &list,int low,int high) {	
	int midValue = list[low];

	while (low<high)
	{

		while (low<high&&list[high]>= midValue)
		{
			high--;
		}
		list[low] = list[high];

		while (low < high && list[low] <= midValue)
		{
			low++;
		}
		list[high] = list[low];

	}
	list[low] = midValue;
	return low;
}


vector<int> Sort::SelectSort(std::vector<int> list) {
	vector<int> res= list;
	for (int i = 0; i < res.size(); i++)
	{
		int minIndex = i;
		for (int j = i; j < res.size(); j++)
		{
			if (res[j]< res[minIndex]) {
				minIndex = j;
			}
		}
		int p = res[i]; res[i] = res[minIndex]; res[minIndex] = p;
	}


	return res;
 }


