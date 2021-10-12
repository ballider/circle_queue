#include "AutoTest.hpp"

bool AutoTest1(){
    circle_queue q(10);
    char str1[] = "qwer";
    char str2[] = "asdf";
    char str3[] = "zxc";
    q.push(str1);
    q.push(str2);
    q.push(str3);
    if(q.count_broken_string() == 1) return 1;
    else return 0;
}

bool AutoTest2(){
    circle_queue q(10);
    char str1[] = "qwer";
    char str2[] = "asdf";
    char str3[] = "zxc";
    q.push(str1);
    q.push(str2);
    q.push(str3);
    q.pop();
    if(q.count_string() == 2) return 1;
    else return 0;
}

bool AutoTest3(){
    circle_queue q(10);
    char str1[] = "qwer";
    char str2[] = "asdf";
    char str3[] = "zxc";
    q.push(str1);
    q.push(str2);
    q.push(str3);
    q.pop();
    q.pop();
    if(q.size_first_string() == 3) return 1;
    else return 0;
}

bool AutoTest(){
    bool all = 1;
    if(!AutoTest1()){
        std::cout << "AutoTest1 is failed.\n";
        all = 0;
    }
    if(!AutoTest2()){
        std::cout << "AutoTest2 is failed.\n";
        all = 0;
    }
    if(!AutoTest3()){
        std::cout << "AutoTest3 is failed.\n";
        all = 0;
    }

    return all;
}