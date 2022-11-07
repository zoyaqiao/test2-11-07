#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv; // condition variable
mutex myMutex; 
int flag = 0;

void printA() {
    unique_lock<mutex> lk(myMutex);
    for (int i = 0; i < 10; ++i) {
        if (flag != 0) {
            cv.wait(lk);
        }
        flag = 1;
        cout << "thread 1 print" << endl;
        cout << i << endl;
        cv.notify_all();
    }
    cout << "thread 1 is finished" << endl;
}

void printB() {
    unique_lock<mutex> lk(myMutex);
    for (int i = 0; i< 10; ++i) {
        if (flag != 1) {
            cv.wait(lk);
        }
        flag = 2;
        cout << "thread 2 print" << endl;
        cout << i << endl;
        cv.notify_all();
    }
    cout << "thread 2 is finished" << endl;
}

void printC() {
    unique_lock<mutex> lk(myMutex);
    for (int i = 0; i < 10; ++i) {
        if (flag != 2) {
            cv.wait(lk);
        }
        flag = 0;
        cout << "thread 3 print" << endl;
        cout << i << endl;
        cv.notify_all();
    }
    cout << "thread 3 is finished" << endl;
}

int main() {
    thread th1(printA);
    thread th2(printB);
    thread th3(printC);

    th1.join();
    th2.join();
    th3.join();

    cout << "main thread" << endl;
    return 0;
}























