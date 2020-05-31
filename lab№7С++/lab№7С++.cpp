#include <iostream>
#include <queue>
#include <string>
#include <Windows.h>

using namespace std;

queue<string> name; //Объявляем очередь
queue<int> mark;

void Task1()
{ 
	setlocale(0, ""); //распознает все языки
	const int default_number_of_students = 5;
	string names[5] = { "Иванов", "Сидоров", "Шевченко", "Корнеев", "Загорный" };
	int size = 0;
	char nameV[50];
	int markV;

	for (int i = 0; i < default_number_of_students; i++)
	{
		name.push(names[rand() % 5]); // push - добавление элемента в очередь
		mark.push(rand() % 5 + 1);
	}

	do
	{
		cout << "Сколько студентов вы хотите добавить?" << endl;
		cin >> size;
	} while (size <= 0);

		for (int i = 0; i < size; i++)
		{
			cout << "Введите фамилию студента : ";
			cin >> nameV;

			cout << "Введите оценку студента по 5 системе: ";
			cin >> markV;

			if (!cin || markV < 0 || markV > 5)
			{
				cout << "Неверный ввод! Попробуйте снова\n";
				cin.clear();
				while (cin.get() != '\n');
			}//проверка, является ли число
         	name.push(nameV); 
	        mark.push(markV);
		}


	while (!name.empty())//Проверряем пустая ли очередь
	{
			cout << "Имя студента : " << name.front() << " - "; //front - обращение к первому элементу
			cout << "Оценка : " << mark.front() << endl;
			name.pop(); //pop - удаление первого элемента очереди 
			mark.pop();

	}

}
 ////////////////////////////////////////////
////////////////////////////////////////////

queue<double> numbers;

double Sum() 
{
	double sum = 0;
	double buff[100]; //массив для манипуляции с элементами очереди
	int i = 0;
	while (!numbers.empty())//пока очередь не пустая
	{
		buff[i] = numbers.front();
		numbers.pop();
		if (abs(buff[i]) < 1)
			sum += buff[i]; //добавлеям число к сумме
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers.push(buff[j]); //обратно заполяем очередь
	cout << "\n";
	return sum;
}

void dequeue()
{
	numbers.pop(); //удаление
}

void enqueue() //добавление
{
	double a;
	cout << "Введите число :";
	cin >> a;
	numbers.push(a);
}

void Print()
{
	double buff[100];
	int i = 0;
	cout << "Ваша очередь: \n | ";
	while (!numbers.empty())
	{
		cout << numbers.front() << " | ";
		buff[i] = numbers.front();
		numbers.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers.push(buff[j]); //добавляем в очередь из массива
	cout << "\n";
}

void Task2()
{
	setlocale(0, "");
	/*bool start = true;*/
	while (true) 
	{
		int choice;
		cout << "Добавить элемент в очередь - 1\n Удалить элемент очереди - 2\n Выполнить поставленную задачу - 3\n Вывести на экран - 4\n -->";
		cin >> choice;
		switch (choice)
		{
		case 1:
			enqueue();
			system("cls");
			break;
		case 2:
			dequeue();
			system("cls");
			break;
		case 3:
			numbers.push(2.2);
			numbers.push(3.2);
			numbers.push(2.4);
			numbers.push(-3.2);
			Print();
			dequeue();
			numbers.push(0.04);
			Print();

			cout << "Сумма чисел по модулю меньших 1 : " << Sum() << "\n\n\n";

			break;
		case 4:
			Print();
			break;
		default: //для повторения ввода
			break;
		}
	}
}

////////////////////////////////////////////
///////////////////////////////////////////

queue<int> numbers1;

queue<int> numbers2;

int  *P1, *P2, *P3, *P4;

void Sort() 
{
	int buff[100], bf;
	int sz = 0;

	while (!numbers2.empty())
	{
		buff[sz] = numbers2.front();
		numbers2.pop();
		sz++;
	}

	sz = 0;
	while (!numbers1.empty())
	{
		buff[sz] = numbers1.front();
		numbers1.pop();
		sz++;
	}
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - i - 1; j++) {
			if (buff[j] > buff[j + 1]) {
				// меняем элементы местами
				bf = buff[j];
				buff[j] = buff[j + 1];
				buff[j + 1] = bf;
			}
		}
	}
	for (int i = 0; i < sz; i++) {
		numbers1.push(buff[i]);
	}

}

void Sort_two() {
	int buff[100], bf;
	int size = 0, sz = 0;

	//FIRST
	while (!numbers1.empty())
	{
		buff[sz] = numbers1.front();
		numbers1.pop();
		sz++;
	}
	size = sz;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (buff[j] > buff[j + 1]) {
				// меняем элементы местами
				bf = buff[j];
				buff[j] = buff[j + 1];
				buff[j + 1] = bf;
			}
		}
	}
	for (int i = 0; i < size; i++) 
	{
		numbers1.push(buff[i]);
	}
	//////////////

	//SECOND
	size = 0, sz = 0;
	while (!numbers2.empty())
	{
		buff[sz] = numbers2.front();
		numbers2.pop();
		sz++;
	}
	size = sz;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (buff[j] > buff[j + 1]) {
				// меняем элементы местами
				bf = buff[j];
				buff[j] = buff[j + 1];
				buff[j + 1] = bf;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		numbers2.push(buff[i]);
	}
	//////////////
}

void Task3()
{
	setlocale(0, "");
	int size = rand() % 10 + 3;
	for (int i = 0; i < size; i++) 
	{
		numbers1.push(rand() % 10);
		numbers2.push(rand() % 10);
	}

	P1 = &numbers1.front();
	P2 = &numbers1.back(); //back - конец очереди
	P3 = &numbers2.front();
	P4 = &numbers2.back();

	int buff[100];
	int i = 0;
	cout << "Ваша очередь 1: \n | ";
	while (!numbers1.empty())
	{
		cout << numbers1.front() << " | ";
		buff[i] = numbers1.front();
		numbers1.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers1.push(buff[j]);
	cout << "\n";

	i = 0;
	cout << "Ваша очередь 2: \n | ";
	while (!numbers2.empty())
	{
		cout << numbers2.front() << " | ";
		buff[i] = numbers2.front();
		numbers2.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers2.push(buff[j]);
	cout << "\n";

	Sort_two();

	cout << "//////////\nПрошла сортировка\n//////////\n\n";

	cout << "Ваша очередь 1: \n | ";
	while (!numbers1.empty())
	{
		cout << numbers1.front() << " | ";
		buff[i] = numbers1.front();
		numbers1.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers1.push(buff[j]);
	cout << "\n";

	i = 0;
	cout << "Ваша очередь 2: \n | ";
	while (!numbers2.empty())
	{
		cout << numbers2.front() << " | ";
		buff[i] = numbers2.front();
		numbers2.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers2.push(buff[j]);
	cout << "\n\n\n";

	Sort();
	cout << "Ваша итоговая очередь : \n | ";
	while (!numbers1.empty())
	{
		cout << numbers1.front() << " | ";
		buff[i] = numbers1.front();
		numbers1.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		numbers1.push(buff[j]);
	cout << "\n";
}
///////////////////////////////////////

int main()
{
	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	switch (numTask)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	}
}