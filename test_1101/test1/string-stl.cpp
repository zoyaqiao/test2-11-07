#include <string>
#include <iostream>

using namespace std;

class string {
public:
std::string& append(const std::string& _s) {
    return append(_s.begin(), _s.end());
};

string& operator+=(const std::string& _s) {
    return append(_s);
};

std::string source;
};
