#include "AutoTest.hpp"

bool AutoTest1(){
    circle_queue q(100);
    q.push("123");
    q.push("223");
    q.push("323");
    q.pop();
    std::string str; q.front(&str);
    if(str == "223") return 1;
    else return 0;
}

bool AutoTest2(){
    circle_queue q(100);
    q.push("123");
    q.push("223");
    q.push("323");
    q.pop();
    q.push("456");
    if(q.size() == 3) return 1;
    else return 0;
}

bool AutoTest3(){
    circle_queue q(100);
    q.push("123");
    q.push("223");
    q.push("323");
    q.push("423");
    q.push("523");
    q.push("623");
    if(q.count_broken_string() == 6-q.max_size()) return 1;
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