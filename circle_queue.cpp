#include "circle_queue.hpp"

circle_queue::circle_queue(){
    rb_ = nullptr;
    MAX_SIZE_ = 0;
    TOTAL_SIZE_ = 0;
    COUNT_BROKEN_STRING_ = 0;
}

circle_queue::circle_queue(const size_t capacity){
    MAX_SIZE_ = capacity/sizeof(std::string);
    std::string* mem = new std::string[MAX_SIZE_];
    rb_ = new ring_buffer;
    
    rb_->start_ = mem;
    rb_->end_ = mem + MAX_SIZE_;
    rb_->del_ = mem;
    rb_->add_ = mem;

    TOTAL_SIZE_ = 0;
    COUNT_BROKEN_STRING_ = 0;
}

circle_queue::~circle_queue(){
    if(rb_ == nullptr) return;

    delete[] rb_->start_;
    delete rb_;
}

void circle_queue::push(const std::string str){
    if(rb_ == nullptr) return;
    if(TOTAL_SIZE_ == MAX_SIZE_){
        pop();
        COUNT_BROKEN_STRING_++;
    }

    *(rb_->add_) = str;

    std::string* tmp = rb_->add_ + 1;
    if(tmp >= rb_->end_) tmp = rb_->start_;
    rb_->add_ = tmp;

    TOTAL_SIZE_++;
}

void circle_queue::pop(){
    if(rb_ == NULL) return;
	if(TOTAL_SIZE_ == 0) return;

    // *(rb_->del_) - удаляем этот элемент
	
	std::string* tmp = rb_->del_ + 1;
	if(tmp >= rb_->end_) tmp = rb_->start_;
	rb_->del_ = tmp;

    TOTAL_SIZE_--;
}

size_t circle_queue::size() const{
    return TOTAL_SIZE_;
}

size_t circle_queue::max_size() const{
    return MAX_SIZE_;
}

size_t circle_queue::count_broken_string() const{
    return COUNT_BROKEN_STRING_;
}

void circle_queue::output(){
    if(rb_ == nullptr) return;
    size_t i = 0;
    size_t size = TOTAL_SIZE_;
    bool choise = 1;
    while(size){
        if(choise){ 
            std::cout << *(rb_->del_+i) << " ";
            i++;
            if(rb_->del_ + i >= rb_->end_){ 
                choise = 0;
                i = 0;
            }
        }
        else{
            std::cout << *(rb_->start_+i) << " ";
            i++;
        }
        size--;
    }
    /*
    for(size_t i = 0; i < MAX_SIZE_; i++){
        std::cout << i << " " << *(rb_->start_+i) << std::endl;
    }
    */
    std::cout << std::endl;
}

void circle_queue::clear(){
    while(TOTAL_SIZE_){
        pop();
    }
}

size_t circle_queue::size_first_string() const{
    if(TOTAL_SIZE_ == 0) exit(-3);
    return (*(rb_->del_)).size();
}

void circle_queue::front(std::string* pstr) const{
    if(rb_ == nullptr) return;
    std::string ans = *(rb_->del_);
    *pstr = ans;
}