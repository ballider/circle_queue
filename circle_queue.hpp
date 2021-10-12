#ifndef B0A53088_BD04_460C_980E_9E63DC96C793
#define B0A53088_BD04_460C_980E_9E63DC96C793

#include <iostream>
#include <list>

class circle_queue{
private:
    struct ring_buffer{
        char* start;
        char* end;
        char* del;  // позиция для удаления
        char* add;  // позиция для вставки
    };

    ring_buffer* rb_;

    std::list<std::pair<char* , size_t>> l;  // список, хранящий указатель на строку в буффере и её длину

    size_t MAX_CAPACITY_;
    size_t TOTAL_CAPACITY_;
    size_t COUNT_BROKEN_STRING_;

    void push_char(const char c);
    void pop_char();
public:
    circle_queue();
    circle_queue(const size_t capacity);
    ~circle_queue();
    void push(const char* str);
    void pop();
    size_t total_capacity() const;
    size_t max_capacity() const;
    size_t count_broken_string() const;
    size_t size_first_string() const;
    size_t count_string() const;
    void front(char** str) const;
    void output();
    void clear();
};

#endif /* B0A53088_BD04_460C_980E_9E63DC96C793 */
