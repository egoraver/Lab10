#include <iostream>
using namespace std;

class Node
{
public:
	int hour, minutes;
	Node* next;
	Node* prev;
	Node()
	{
		hour = 0;
		minutes = 0;
		next = nullptr;
		prev = nullptr;
	};
};

Node* create(int hour, int minutes);
void add(Node** end, int hour, int minutes);
Node* find(Node* const first, int i);
//bool remove(Node** first, Node** end, int keyValue);
Node* insert(Node* const first, Node** end, int keyValue, int hour, int minutes);


Node* create(int hour, int minutes)
{
	Node* tmp = new Node();
	tmp->hour = hour;
	tmp->minutes = minutes;
	tmp->next = nullptr;
	tmp->prev = nullptr;
	return tmp;
}
//-----------------------------------------------
//Добавление в конец списка
void add(Node** end, int hour, int minutes)
{
	Node* tmp = new Node();
	tmp->hour = hour; tmp->minutes = minutes; tmp->next = 0; tmp->prev = *end;
	(*end)->next = tmp;
	*end = tmp;
}

Node* find(Node* const first, int hour) {
	Node* tmp = first;
	while (tmp) {
		if (tmp->hour == hour) break;
		tmp = tmp->next;
	}
	return tmp;
}


//bool remove(Node** first, Node** end, int keyValue)
//{
//    if (Node* keyPointer = find(*first, keyValue))
//    {
//        if (keyPointer == *first)
//        {
//            *first = (*first)->next;
//            (*first)->prev = 0;
//        }
//        else if (keyPointer == *end)
//        {
//            *end = (*end)->prev;
//            (*end)->next = 0;
//        }
//        else
//        {
//            (keyPointer->prev)->next = keyPointer->next; // 1
//            (keyPointer->next)->prev = keyPointer->prev; // 2
//        }
//        delete keyPointer; // 3
//        return true;
//    }
//    return false;
//}

Node* insert(Node* const first, Node** end, int keyValue, int hour, int minutes)
{
	Node* keyPointer = find(first, keyValue);
	if (keyPointer)
	{
		Node* tmp = new Node();
		tmp->hour = hour;
		tmp->minutes = minutes;
		// 1 – установление связи нового узла с последующим:
		tmp->next = keyPointer->next;
		// 2 – установление вязи нового узла с предыдущим:       
		tmp->prev = keyPointer;
		// 3 – установление связи предыдущего узла с новым:
		keyPointer->next = tmp;
		// 4 – установление связи последующего узла с новым:
		if (keyPointer != *end) (tmp->next)->prev = tmp;
		//Обновление указателя на конец списка,
		//если узел вставляется в конец:
		else *end = tmp;
		return tmp;
	}
	return 0;
}



int main()
{
	/*int t = 0;
	cin >> t;*/
	Node* first = create(15, 14); //Формирование первого элемента списка
    Node* end = first;
	//Добавление в конец списка четырех элементов 2, 3, 4 и 5:
	for (int i = 2; i < 24; i++)
	{
		   add(&end, i, 59);
	}

	//cin >> t;
	//Вставка элемента 200 после элемента 2:
    insert(first, &end, 2, 15, 36);

   // remove(&first, &end, 2);

	//Вывод списка на экран
	Node* tmp = first;
	int number = 1;
	while (tmp)
	{
		cout << "Number: " << number << endl << "Time Out: " << tmp->hour << ':' << tmp->minutes << endl << "=====================" << endl;
		tmp = tmp->next;
		number++;
	}
	return 0;

}
