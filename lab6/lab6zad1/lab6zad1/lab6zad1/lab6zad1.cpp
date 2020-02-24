#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

const unsigned int NAME_SIZE = 30;
const unsigned int STREET_SIZE = 40;
const unsigned int CITY_SIZE = 20;
struct Address
{
	char name[NAME_SIZE];
	char street[STREET_SIZE];
	char city[CITY_SIZE];
	Address *next;
	Address *prev;

};
//-----------------------------------------------------------

int menu(void)
{
	cin.ignore(cin.rdbuf()->in_avail());
	cin.sync();
	char s[80];
	int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Сохранить в файл" << endl;
	cout << "6. Загрузить из файла" << endl;
	cout << "7. Delete all" << endl;
	cout << "8.  CountList" << endl;
	cout << "9.  FindMin по полю города" << endl;
	cout << "10.  FindMax по полю города" << endl;
	cout << "11.  DeleteKFirst" << endl;
	cout << "12.  DeleteKLast" << endl;
	cout << "13.  DeleteDouble" << endl;
	cout << "14.  DeleteEveryM" << endl;
	cout << "14. Выход" << endl; cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 15);
	return c;

}
//-----------------------------------------------------------
void create(Address *i, Address **phead, Address **plast)
{
	Address *old = NULL, *p = *phead;
	if (*plast == NULL)
	{
		i->next = NULL;
		i->prev = NULL;
		*phead = i;
		*plast = i;
		return;
	}
	while (p)
	{
		if (strcmp(p->name, i->name) < 0)
		{
			old = p;
			p = p->next;
		}
		else
		{
			if (p->prev)
			{
				p->prev->next = i;
				i->next = p;
				i->prev = p->prev;
				p->prev = i;
				return;
			}
			i->next = p;
			i->prev = NULL;
			p->prev = i;
			*phead = i;
			return;
		}
	}
	old->next = i;
	i->next = NULL;
	i->prev = old;
	*plast = i;
}

//-----------------------------------------------------------
Address* setElement()      // Ввод структуры
{
	Address* temp = new  Address();

	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}

	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите улицу: ";
	cin.getline(temp->street, STREET_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();

	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}
//-----------------------------------------------------------
void outputList(Address **phead, Address **plast)      //Вывод списка на экран
{
	Address *t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->street
			<< ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address **phead)    // Поиск имени в списке
{

	Address *t = *phead;

	while (t)
	{
		if (!strcmp(name, t->name))
			break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->street << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address **phead, Address **plast)  // Удаление име-ни из списка
{
	struct Address *t = *phead;

	while (t)
	{
		if (!strcmp(name, t->name))
			break;
		t = t->next;
	}
	if (t)
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		} delete t;
	}
}
//-----------------------------------------------------------
void writeToFile(Address **phead)//Запись в файл
{
	struct Address *t = *phead;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;

	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
void FindMin(Address **phead, Address **plast) //Поиск минимального
{
	if (*phead)
	{
		struct Address *t = *phead;
		struct Address *min = *phead;
		t = t->next;
		while (t)
		{
			if (strcmp(min->city, t->city) > 0)
			{
				min = t;
			}
			t = t->next;
		}
		cout << min->name << " " << min->street << " " << min->city << endl;
	}
}
void FindMax(Address **phead, Address **plast)//Поиск максимального
{
	if (*phead)
	{
		struct Address *t = *phead;
		struct Address *max = *phead;
		t = t->next;
		while (t)
		{
			if (strcmp(max->city, t->city) < 0)
			{
				max = t;
			}
			t = t->next;
		}
		cout << max->name << " " << max->street << " " << max->city << endl;
	}
}
void delete_all(Address **phead, Address **plast)//Удаление всего списка 
{
	Address *p = new Address;
	p = *phead;
	while (*phead)
	{
		p = *phead;
		*phead = p->next;
		delete p;
	}
	*phead = NULL;
	*plast = NULL;
}
void CountList(Address **phead, Address **plast) //Подсчет кол-ва элементов
{
	Address *p = new Address;
	p = *phead;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	cout << count << endl;
}
void DeleteKFirst(Address **phead, Address **plast, int k) // Удаление k первых 
{
	int count = 0;
	if (!*phead)
	{
		return;
	}
	Address *p = new Address;
	Address *temp = new Address;
	p = *phead;
	while (p) // перебор списка и удаление элементов 
	{
		if (count < k)
		{
			temp = p;
			p = p->next;
			if (!p)
			{
				*phead = NULL;
				*plast = NULL;
				break;
			}
			p->prev = NULL;
			delete temp;
		}
		else {
			*phead = p;
			break;
		}
		count++;
	}
}
void DeleteKLast(Address **phead, Address **plast, int k) // Удаление k последних 

{
	int count = 0;
	if (!*plast)
	{
		return;
	}
	Address *p = new Address;
	Address *temp = new Address;
	p = *plast;
	while (p) // перебор списка и удаление элементов 
	{
		if (count < k)
		{
			temp = p;
			p = p->prev;
			if (!p)
			{
				*phead = NULL;
				*plast = NULL;
				break;
			}
			p->next = NULL;
			delete temp;
		}
		else {
			*plast = p;
			break;
		}
		count++;
	}
}
void DeleteEveryМ(Address **phead, Address **plast, int m) //Удаление M элемента начиная с первого
{
	int count = m;
	if (!*phead)
	{
		return;
	}
	Address *p = new Address;
	Address *temp = new Address;
	p = *phead;
	while (p)
	{
		if (count == m)
		{
			temp = p;
			if (p == *plast)
			{
				*plast = p->prev;
				p->prev->next = NULL;
				delete temp;
				break;
			}
			if (p == *phead)
			{
				*phead = p->next;
				p->next->prev = NULL;
				p = p->next;
				delete temp;
				count = 1;
				continue;
			}
			if (!p)
			{
				delete temp;
				break;
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p = p->next;
			delete temp;
			count = 1;
		}
		else {
			p=p->next;
			count++;
		}
	}
}
void DeleteDouble(Address **phead, Address **plast) // Удаление одинаковых записей
{
	struct Address *t = *phead;
	t = t->next;
	struct Address *tmp = *phead;
	while (tmp)
	{
		while (t) {
			if (!strcmp(tmp->name, t->name) || !strcmp(tmp->street, t->street) || !strcmp(tmp->city, t->city)) { //проверяю все свойства
				if (*phead == t) {
					*phead = t->next;
					if (*phead)
						(*phead)->prev = NULL;
					else
						*plast = NULL;
				}
				else {
					t->prev->next = t->next;
					if (t != *plast)
						t->next->prev = t->prev;
					else
						*plast = t->prev;
				}
			}
			t = t->next;
		}
		tmp = tmp->next;
		if (tmp != NULL)
			t = tmp->next;
		else
			break;
	}
}
//-----------------------------------------------------------
void readFromFile(Address **phead, Address **plast)          //Считывание из файла
{
	struct Address *t;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist.txt", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete *phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp))
			break;
		create(t, phead, plast);
	}
	fclose(fp);
}
//-----------------------------------------------------------
int main(void)
{

	Address *head = NULL;
	Address *last = NULL;

	setlocale(LC_CTYPE, "Rus");

	while (true)
	{
		switch (menu())
		{
		case 1:
		{

			create(setElement(), &head, &last);
		}
		break;
		case 2:
		{
			char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
		break;
		case 3:
			outputList(&head, &last);
			break;
		case 4:
		{
			char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
		break;
		case 5:
			writeToFile(&head);
			break;
		case 6:
			readFromFile(&head, &last);
			break;
		case 7:
			delete_all(&head, &last);
			break;
		case 8:
			CountList(&head, &last);
			break;
		case 9:
			FindMin(&head, &last);
			break;
		case 10:
			FindMax(&head, &last);
			break;
		case 11:
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			int k;
			cout << "Enter k " << endl;
			cin >> k;
			DeleteKFirst(&head, &last, k);

			break;
		case 12:
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			int kar;
			cout << "Enter k " << endl;
			cin >> kar;
			DeleteKLast(&head, &last, kar);
			break;
		case 13:
			DeleteDouble(&head, &last);
			break;
		case 14:
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			int M;
			cout << "Enter m " << endl;
			cin >> M;
			DeleteEveryМ(&head, &last, M);
			break;
		case 15:
			exit(0);
		default:
			exit(1);
		}
	}
	return 0;
}

