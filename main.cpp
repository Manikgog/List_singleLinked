#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "queue.h"

void loop() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	
	Queue myq;
	int choice;
	int data = 0;
	while (true)
	{
		system("cls");
		std::cout << R"(Choose:
1 - add element;
2 - remove element;
3 - show size;
4 - show element in index;
5 - insert element;
6 - exit.)" << std::endl;
		do {
			std::cin >> choice;

		} while (choice < 1 || choice > 6);
		static int tmp;
		switch (choice)
		{
		case 1:
			std::cout << "Enter number to adding to queue -> ";
			std::cin >> tmp;
			
			push(myq, tmp);
			break;

		case 2:
			tmp = pull(myq);
			std::cout << "Removed element with data: " << tmp << std::endl;
			break;
		case 3:
			std::cout << "Size of queue -> " << Size(myq) << std::endl;
			break;
		case 4:
			std::cout << "Enter an index -> ";
			std::cin >> tmp;
			std::cout << LookAt(myq, tmp) << std::endl;
			break;
		case 5:
			std::cout << "Enter an index to insert before -> ";
			std::cin >> tmp;
			std::cout << "Enter number to insert -> ";
			std::cin >> data;
			Insert(myq, data, tmp);
			break;
		case 6:
			Clear(myq);
			return;
		}
		print(myq);
		system("pause");
	}
	
}

int main()
{
	loop();
	system("pause");
	return 0;
}
