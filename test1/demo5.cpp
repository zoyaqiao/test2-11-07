#include <vector>
#include <string>
#include<algorithm>
#include <iostream>
#include <iterator>
using namespace std;

// read data form standard inputstream, sort these datas, finally transport the sorted data to outstream
void test1() {
    vector<string> v;
    string tmp;
    while (getline(cin, tmp)) {
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}

// look for the value c in the string
// strchr 
char* my_strchr(char* s, char c) {
    while(*s != '\0' && *s != c) {
        ++s;
    }
    return *s == c ? s : (char*) 0;
}

// test basic_string& append(const basic_string& __s,
                    //    size_type __pos, size_type __n)

void append_test1() {
    string s1 = "abc";
    string s2 = "1234";
    s1.append(s2, 1, 4); // expect abc234
    cout << "s1" << s1;
}

void append_test2() {
    string s1 = "abc";
    char* s2 = "1234";
    s1.append(s2, 2); // expect abc12
    cout << "s1" << s1;
}

// basic_string& insert(size_type __pos, const basic_string& __s)
void insert_test1() {
    string s1 = "abc";
    s1.insert(1, "12345678910111213415");
    cout << s1.capacity() << endl;
    cout << "s1.max_size()" << s1.max_size() << endl;
    cout << "s1" << s1;
}

// void basic_string<_CharT,_Traits,_Alloc>::reserve(size_type __res_arg)
void reserve_test1() {
    string s1 = "abcd";
    cout << "s1.capacity() " << s1.capacity() << endl;
    
    s1.reserve(2);
    cout << "s1.capacity() " << s1.capacity() << endl;

    cout << "s1.size() " << s1.size() << endl;
}


int main() {
    // test1();
    // char* a = "abc123";
    // if (my_strchr(a, '1') == nullptr) {
    //     cout << "fail to search" << endl;
    // }
    // cout << "res" << my_strchr(a, '1') << endl;;

    // append_test1();
    // append_test2();
    // insert_test1();
    reserve_test1();
}