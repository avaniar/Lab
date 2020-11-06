#include "Header.h";
#include <iostream>
using namespace std;
void List::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

List::List()
{
	reset_list();
	size = 0;
}
List::~List()
{
}
void List::push_back(int newelement)
{
	if (size == 0)//We add the new element first.
	{
		head = new Node(newelement);
		tail = head;
	}
	else//We add the new element last.
	{
		Node *current=new Node(newelement);
		tail->next = current;
		current->prev = tail;
		tail = current;
	}
	size++;
}
void List::push_front(int newelement)
{
	if (size == 0)//We add the new element first.
	{
		head = new Node(newelement);
		tail = head;
	}
	else//We add the new element first.
	{
		Node*current= new Node(newelement);
		head->prev = current;
		current->next = head;
		head = current;
	}
	size++;
}

void List::pop_back()
{
	if (size == 0)return;//Exit the function.
	if (size == 1)//We remove the first element and reset the list.
	{
		delete head;
		reset_list();
	}
	else
	{
		Node* current = tail->prev;
		current->next = nullptr;
		tail->prev = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

void List::pop_front()
{
	if (size == 0) return;//Exit the function.
	if (size == 1)//We remove the first element and reset the list.
	{
		delete head;
		reset_list();
	}
	else//We remove the first element
	{
		Node *current = head->next;
		current->prev = nullptr;
		head->next = nullptr;
		delete head;
		head = current;
	}
	size--;
}

void List::insert(int Newelement, size_t index)
{
	if ((index < 0) || (index >= size))
		throw out_of_range("The index is outside the list.");
	else if (index == 0)
			push_front(Newelement);
		 else
		{
			Node *current = head;
			for (int i = 0;i < index;i++)//We reach the desired element.
				current = current->next;
			current->prev->next = new Node(Newelement);
			current->prev->next->prev = current->prev;
			current->prev = current->prev->next;
			current->prev->next = current;
			size++;
		}
}

int List::at(size_t index)
{
	if ((index < 0) || (index >= size))
		throw out_of_range("The index is outside the list.");
	else {
		Node* current = head;
		for (int i = 0;i < index;i++)//We reach the desired element.
			current = current->next;
		return current->data;
	}
}

void List::remove(size_t index)
{
	if ((index < 0) || (index >= size))
		throw out_of_range("The index is outside the list.");
	else if (index == 0)
			 pop_front();
		 else if (index == size-1)
			 pop_back();
			else
			{
				Node * current = head;
				for (int i = 0;i < index;i++)//We reach the desired element.
					current = current->next;
				current->prev->next = current->next;
				current->next->prev = current->prev;
				current->prev = nullptr;
				current->next = nullptr;
				delete current;
				size--;
			}
}

size_t List::get_size()
{
	return size_t(size);
}

void List::print_to_console()
{
	Node *current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void List::clear()
{
	while (size)
	{
		pop_front();
	}
}

void List::set(size_t index, int number)
{

	if ((index < 0) || (index >= size))
		throw out_of_range("The index is outside the list.");
	else
	{
		Node* current = head;
		for (int i = 0;i < index;i++)//We reach the desired element.
			current = current->next;
		current->data = number;
	}
}

bool List::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void List::push_back(List list2)
{
	if (list2.isEmpty()) return;
	else
	{
		Node* current = list2.head;
		while(current)
		{
			push_back(current->data);
			current = current->next;
		}
	}
}


