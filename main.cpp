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
    std::cout << "Input 5 to printf circle queue.\n";
    std::cout << "Input 6 to get size of broken string.\n";
    std::cout << "Input 7 to clear.\n";
    std::cout << "Input -1 to exit\n";

    while(true){
        int key; std::cin >> key;
        if(key == -1) break;
        if(key == 1){
            std::cout << "Input string: ";
            std::string str; std::cin >> str;
            std::cout << std::endl;
            q.push(str);
        }
        if(key == 2) q.pop();
        if(key == 3) std::cout << q.size() << std::endl;
        if(key == 4){
            std::string str;
            q.front(&str);
            std::cout << str << std::endl; 
        }
        if(key == 5) q.output();
        if(key == 6) std::cout << q.count_broken_string() << std::endl;
        if(key == 7) q.clear();
    }
    

    return 0;
}