#include <iostream>
#include <vector>
using namespace std;

void test1() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2(v1);
    for (auto& v : v2) {
        cout << v;
    }
}

int main() {
    test1();
}