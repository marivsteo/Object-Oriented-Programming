#pragma once
#pragma once
template <class T>
class Comparator {
public:
	virtual bool compare(const T& a, const T& b) = 0;
};