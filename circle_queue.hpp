#ifndef B0A53088_BD04_460C_980E_9E63DC96C793
#define B0A53088_BD04_460C_980E_9E63DC96C793

#include <iostream>

class circle_queue{
private:
    struct ring_buffer{
        std::string* start_;
        std::string* end_;
        std::string* del_;  // позиция для удаления
        std::string* add_;  // позиция для вставки
    };

    ring_buffer* rb_;

    size_t MAX_SIZE_;
    size_t TOTAL_SIZE_;
    size_t COUNT_BROKEN_STRING_;
public:
    circle_queue();
    circle_queue(const size_t capacity);
    ~circle_queue();
    void push(const std::string str);
    void pop();
    size_t size() const;
    size_t max_size() const;
    size_t count_broken_string() const;
    size_t size_first_string() const;
    void front(std::string* pstr) const;
    void output();
    void clear();
};

#endif /* B0A53088_BD04_460C_980E_9E63DC96C793 */
