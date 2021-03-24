#pragma once
#include <vector>
class Sort
{
public:
	Sort();
	static std::vector<int> CountSort(std::vector<int> list, std::vector<int> filter);
	static std::vector<int> InsertSort(std::vector<int> list);
	static std::vector<int> BInsertSort(std::vector<int> list);
	static std::vector<int> ShellSort(std::vector<int> list);
	static std::vector<int> BubbleSort(std::vector<int> list);
	static std::vector<int> QuickSort(std::vector<int> list);
	static std::vector<int> SelectSort(std::vector<int> list);

private:
	void QuickSort_main(std::vector<int>& list, int low, int high);
	int QuickSort_Split(std::vector<int>& list, int low, int high);
};

