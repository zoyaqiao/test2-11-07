#include "myAllocator.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 0,1,2,3,4 };
	vector<int, myAllocator::allocator<int>> iv(arr, arr + 5);

	for (size_t i = 0; i < iv.size(); ++i) {
		cout << iv[i] << endl;
	}
	cout << endl;
}