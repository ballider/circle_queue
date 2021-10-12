#include "circle_queue.hpp"
#include <cstring>

circle_queue::circle_queue(){
    rb_ = nullptr;
    MAX_CAPACITY_ = 0;
    TOTAL_CAPACITY_ = 0;
    COUNT_BROKEN_STRING_ = 0;
    l.clear();
}

circle_queue::circle_queue(const size_t capacity){
    MAX_CAPACITY_ = capacity;
    char* mem = new char[MAX_CAPACITY_];
    rb_ = new ring_buffer;
    
    rb_->start = mem;
    rb_->end = mem + MAX_CAPACITY_;
    rb_->del = mem;
    rb_->add = mem;

    TOTAL_CAPACITY_ = 0;
    COUNT_BROKEN_STRING_ = 0;
    l.clear();
}

circle_queue::~circle_queue(){
    if(rb_ == nullptr) return;

    delete[] rb_->start;
    delete rb_;
    l.clear();
}

void circle_queue::push_char(const char c){
    if(rb_ == nullptr) return;

    *(rb_->add) = c;

    char* tmp = rb_->add + 1;
    if(tmp >= rb_->end) tmp = rb_->start;
    rb_->add = tmp;

    TOTAL_CAPACITY_++;
}

void circle_queue::push(const char* str){
    if(rb_ == nullptr) return;

    size_t size_str = strlen(str);
    
    if(size_str > MAX_CAPACITY_){
        std::cout << "Error! Size of string is bigger than size of buffer!\n";
        return;
    }

    if(TOTAL_CAPACITY_ + size_str > MAX_CAPACITY_){
        l.push_back({rb_->add, size_str});

        size_t i = 0;
        while(TOTAL_CAPACITY_ != MAX_CAPACITY_){
            push_char(str[i]);
            i++;
        }
        
        size_t tmp = size_str - i;
        while(true){
            if(l.front().second < tmp){
                tmp -= l.front().second;
                pop();
                COUNT_BROKEN_STRING_++;
            } 
            else if(l.front().second == tmp){
                pop();
                COUNT_BROKEN_STRING_++;
                break;
            }
            else{
                for(size_t j = 0; j < tmp; j++){
                    pop_char();
                }
                l.front().first = rb_->del;
                l.front().second = l.front().second - tmp;
                COUNT_BROKEN_STRING_++;
                break;
            }
        }
        
        for(i; i < size_str; i++){
            push_char(str[i]);
        }

        return;
    }

    l.push_back({rb_->add, size_str});

    for(size_t i = 0; i < size_str; i++){
        push_char(str[i]);
    }
}

void circle_queue::pop_char(){
    if(rb_ == NULL) return;
	if(TOTAL_CAPACITY_ == 0) return;

    // *(rb_->del) удаляем этот элемент

    char* tmp = rb_->del + 1;
	if(tmp >= rb_->end) tmp = rb_->start;
	rb_->del = tmp;

    TOTAL_CAPACITY_--;
}

void circle_queue::pop(){
    if(rb_ == NULL) return;
	if(TOTAL_CAPACITY_ == 0) return;
	
    for(size_t i = 0; i < l.front().second; i++){
        pop_char();
    }

    l.pop_front();
}

size_t circle_queue::total_capacity() const{
    return TOTAL_CAPACITY_;
}

size_t circle_queue::max_capacity() const{
    return MAX_CAPACITY_;
}

size_t circle_queue::count_broken_string() const{
    return COUNT_BROKEN_STRING_;
}

void circle_queue::output(){
    if(rb_ == nullptr) return;

    char* tmp = rb_->del;
    for(size_t i = 0; i < TOTAL_CAPACITY_; i++){
        std::cout << *(tmp);
        tmp = tmp + 1;
		if(tmp >= rb_->end) tmp = rb_->start;
    }
    std::cout << std::endl;
}

void circle_queue::clear(){
    while(TOTAL_CAPACITY_ != 0){
        pop();
    }
}

size_t circle_queue::count_string() const{
    return l.size();
}

size_t circle_queue::size_first_string() const{
    if(TOTAL_CAPACITY_ == 0) return 0;
    return l.front().second;
}

void circle_queue::front(char** str) const{
    if(rb_ == nullptr) return;

    char* tmp = l.front().first;
    
    char* ans = new char[l.front().second];
    for(size_t i = 0; i < l.front().second; i++){
        ans[i] = *(tmp);
        tmp++;
        if(tmp >= rb_->end) tmp = rb_->start;
    }
    *str = ans;
}

