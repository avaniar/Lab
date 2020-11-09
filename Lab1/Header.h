#pragma once
class List
{
private:
	class Node
	{
	public:
		Node(int data, Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		};
		~Node() {};

		int data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
	size_t size;

public:
	List();
	~List();
	void reset_list();
	void push_back(int Newelement); // добавление в конец списка
	void push_front(int Newelement); // добавление в начало списка
	void pop_back(); // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	void insert(int Newelement, size_t); // добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)
	int at(size_t); // получение элемента по индексу. ћожно сделать типа size_t
	void remove(size_t); // удаление элемента по индексу
	size_t get_size(); // получение размера списка
	void print_to_console(); // вывод элементов списка в консоль через разделитель, не использовать at
	void clear(); // удаление всех элементов списка
	void set(size_t, int); // замена элемента по индексу на передаваемый элемент
	bool isEmpty(); // проверка на пустоту списка
	void push_back(List&);
};