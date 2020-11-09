#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
	List list;
	List list2;
	list.push_back(7);
	list.push_back(10);
	list.push_back(15);
	list.print_to_console();
	list.push_front(9);
	list.print_to_console();
	list.pop_back();
	list.print_to_console();
	list2.push_back(17);
	list.remove(1);
	list.print_to_console();
	list.insert(2, 1);
	list.print_to_console();
	list.push_back(list2);
	list.print_to_console();
	return 0;
}