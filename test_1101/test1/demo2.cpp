#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <string.h>
#include <assert.h>
#include  <iostream>
using  namespace std;

class String {
public:
    String() {
        _str = new char[1];
        
        *_str = '\0';
        size = 0;
        capacity = 1;
    }
    String(char* str){
        if (nullptr == str) {
            assert(false);
            return;
        }
        int len = strlen(str); // doesn't contain '\0'
        _str = new char[len + 1];
        strcpy(_str, str);    // '\0' is also copied
        size = len;
        capacity = len + 1;
    }
    String(const char* str) {
        if (nullptr == str) {
            assert(false);
            return;
        }
        int len = strlen(str);
        _str = new char[len + 1];
        strcpy(_str, str);
        size = len;
        capacity = len + 1;
    }
    String(String& tmp) {
        // int len = 0;
        if (nullptr == tmp.str()) {
            assert(false);
            return;
        }
        if (tmp.str() != nullptr) {
            size = tmp.size;
            capacity = size + 1;
        }
        _str = new char[size + 1];
        strcpy(_str, tmp.str());   //  avoid lacking of '\0'
    }
    String(const String& tmp) {
        if (tmp.str() == nullptr) {
            assert(false);
            return;
        }
        if (tmp.str() != nullptr) {
            size = tmp.size;
        }
        _str = new char[size + 1];
        strcpy(_str, tmp._str);
    }
    String(size_t len, char ch) {
        _str = new char[len + 1];
        size = len;
        capacity = len + 1;
        for (size_t i = 0; i < len; ++i) {
            _str[i] = ch;
        }
    }
    char* str()const {
        return _str;
    }      
    
    ~String() {
        if (_str != nullptr) {
            delete []_str;
            size = 0;
            capacity = 0;
        }
    };
    const size_t Length()const {
        return size;
    }
    size_t Size()const {
        return size;
    }
    const size_t my_capacity()const {
        return capacity;
    }

    friend ostream& operator<< (ostream& os, String& s) {
        for (int i = 0; i < s.size; ++i) {
            os << s._str[i];
        }
        os << endl;
        return os;//
    };

    // swap pointers
    void swap(String& s) {
        // String tmp = s;
        // s = *this;
        // *this = tmp;
        char* tmp = s._str;
        size_t tmp_len = s.size;
        s._str = _str;

        s.size = size;
        _str = tmp;
        size = tmp_len;

        size_t tmp_cap = s.capacity;
        s.capacity = capacity;
        capacity = tmp_cap;
    }


    bool empty() {
        return size == 0 ? true : false;
    }

    //  capacity manages the memory space of string objects, when the capacity is insufficient, a new
    //  space twice as large as the original space is always applied for;
    //  set the space is 4 if the capacity is zero;
    void push_back(const char ch) {
        if (size + 1 ==  capacity) {   // 2 -> '\0' + ch
            size_t num = capacity == 0 ? 4 : 2 * capacity;
            // this is the case where the memory allocation fails to be considered in future optimization
            char* tmp = new char[num];
            for (int i = 0; i < size; ++i) {
                tmp[i] = _str[i];
            }
            tmp[size] = ch;
            tmp[size + 1] = '\0';
            // delete the original space and let the pointer point the new space
            if (!this -> empty()) {
                delete []_str;
            }
            _str = tmp;
            size = size + 1;
            capacity = num;
            tmp = nullptr;
        } else {
            _str[size] = ch;
            _str[size + 1] = '\0';
            size = size + 1;
        }
    }
    char* begin() {
        return this -> str();
    }
    char* end() {
        return (this -> str() + this -> Size());
    }
    // const char* begin() {
    //     return this -> str();
    // }
    // const char* end() {
    //     return (this -> str() + this -> Size());
    // }
    // read only is really trouble
    String& append(String& s) {
        return append(s.begin(), s.end());
    }

    // the underlying implementation of append is push back
    String& append(char* first, char* last ) {
        for (; first != last; ++first) {
            push_back(*first);
        }
        return *this;
    }

    // replace
    // using ch1 to replace ch
    String& replace(char* ch, char* ch1) {

    }

    // assign



    // insert



    // substr



    //copy



    // find


    //find_first_of


    // find_last_of


    //find_first_not_of


    // find_last_not_of


    // compare


    // getline


    


    


    String& operator=(const String& s) {
        // to prevent the original char star pointer from pointing to an illegal space
        if (nullptr != _str) {
            delete[] _str;
            size = 0;
            capacity = 0;
        }
        if (this -> _str != s._str) {
            String tmp(s);
            std::swap(tmp._str, _str);
        }
        return *this;
    };

    String& operator=(String& s) {
        if (_str != nullptr) {
            delete [] _str;
            size = 0;
            capacity = 0;
        } 

        // using swap is much more efficient??
        _str = new char[s.size + 1];
        size = s.size;
        for (size_t i = 0; i < size; ++i) {
            _str[i] = s._str[i];
        }
        _str[size] = '\0';
        return *this;
    };

private:
    char* _str;
    size_t size;
    size_t capacity;
};



void test1() {
    String s("ab");
    cout << "s " << s;
    String s1;
    s1 = s;  // this -> s1  
    cout << "s1 " << s1;
    String s2(s1);
    size_t s2_len = s2.Length();    //  const???
    // ++s2_len;
    cout << "s2 " << s2;
    cout << "s2.length " << s2.Length() << endl;

}

// test swap
void test_swap() {
    String s1("ab");
    String s2("abcdefgh");
    s1.swap(s2);
    cout << "s1" << s1;
    cout << "s2" << s2;
}

void test_push_back() {
    String s;
    s.push_back('c');
    s.push_back('1');
    cout << "s " << s;
    
}

void test_append() {
    String s;
    String t = "abc";
    s.append(t);
    cout << "s " << s << endl;

}


int main () {
    // test1();
    // test_swap();
    // test_push_back();
    test_append();

}