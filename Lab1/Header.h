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
	void push_back(int Newelement); // ���������� � ����� ������
	void push_front(int Newelement); // ���������� � ������ ������
	void pop_back(); // �������� ���������� ��������
	void pop_front(); // �������� ������� ��������
	void insert(int Newelement, size_t); // ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������)
	int at(size_t); // ��������� �������� �� �������. ����� ������� ���� size_t
	void remove(size_t); // �������� �������� �� �������
	size_t get_size(); // ��������� ������� ������
	void print_to_console(); // ����� ��������� ������ � ������� ����� �����������, �� ������������ at
	void clear(); // �������� ���� ��������� ������
	void set(size_t, int); // ������ �������� �� ������� �� ������������ �������
	bool isEmpty(); // �������� �� ������� ������
	void push_back(List&);
};