#pragma once
#pragma once
#include<vector>
#include"Comparator.h"

template <class T>
std::vector<T>& sort(std::vector<T>& elems, Comparator<T>& c) {
	std::vector<T>& elems2 = elems;
	int size = elems2.size();
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (c.compare(elems2[i], elems2[j]))
				std::swap(elems2[i], elems2[j]);
	return elems2;
}