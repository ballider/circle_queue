# circle_queue
Circle queue of string. On base ring buffer.

Реализует класс кольцевой очереди строк, работающей по принципу кольцевого буффера. Все строки размещаются на базе одного отрезка памяти и располгаются без промежутков. Причём при полном заполнении этого отрезка памяти новые добавляемые строки затирают строки из начала очереди.

Класс поддерживает следующие возможности:
1) создать пустую очередь на заданное количество байт (конструктор)
2) вставить элемент в конец очереди (метод push)
3) удалить строку из начала очереди (метод pop)
4) получить длину строки из начало очереди (метод size_first_string)
5) копировать строку из начала очереди по заданному указателю (метод front)
6) узнать общее кол-во строк (метод cout_string)
7) очистить очередь (метод clear)
8) получить количество потерянных строк в начале очереди (метод count_broken_string)
9) узнать максимальную длину очереди, т. е. размер кольцевого буфера (метод max_capacity)
10) вывести очередь (метод output)

Так же в классе присутствует деструктор.
