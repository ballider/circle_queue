#include "head.hpp"
#include "AutoTest.hpp"

int main(){

    if(!AutoTest()) return 0;
    
    std::cout << "Input count of bytes: ";
    size_t size; std::cin >> size;
    circle_queue q(size);
    std::cout << std::endl;

    std::cout << "Input 1 to push.\n";
    std::cout << "Input 2 to pop.\n";
    std::cout << "Input 3 to get size.\n";
    std::cout << "Input 4 to get first string.\n";
    std::cout << "Input 5 to printf.\n";
    std::cout << "Input 6 to get size of broken string.\n";
    std::cout << "Input 7 to clear.\n";
    std::cout << "Input 8 to get size first string.\n";
    std::cout << "Input -1 to exit\n";

    while(true){
        int key; std::cin >> key;
        if(key == -1) break;
        if(key == 1){
            std::cout << "Input string: ";
            char str[INT8_MAX]; std::cin >> str;
            q.push(str);
        }
        if(key == 2) q.pop();
        if(key == 3) std::cout << q.count_string() << std::endl;
        if(key == 4){
            char* str;
            q.front(&str);
            std::cout << str << std::endl;
        }
        if(key == 5) q.output();
        if(key == 6) std::cout << q.count_broken_string() << std::endl;
        if(key == 7) q.clear();
        if(key == 8) std::cout << q.size_first_string() << std::endl;
    }
    
    return 0;
}