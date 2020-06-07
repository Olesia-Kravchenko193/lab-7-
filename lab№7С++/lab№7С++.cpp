#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

struct Student
{
	string lastName;
	float avergeMark = 0;
	Student* prevStud = nullptr;

	void setInf()
	{
		cout << "Введите информацию: ";
		cin >> lastName >> avergeMark;
	}

	void getInf()
	{
		cout << lastName << " " << avergeMark << endl;
	}
};

struct StackOfStudents
{
	Student* currentStud = nullptr;
	Student* prevStud = nullptr;

	void add()
	{
		prevStud = currentStud;
		currentStud = new Student();
		currentStud->prevStud = prevStud;
		currentStud->setInf();
	}

	void show()
	{
		prevStud = currentStud;
		while (currentStud)
		{
			currentStud->getInf();
			currentStud = currentStud->prevStud;
		}
		currentStud = prevStud;
		prevStud = prevStud->prevStud;
	}

	void clear()
	{
		while (currentStud)
		{
			prevStud = currentStud->prevStud;
			delete currentStud;
			currentStud = prevStud;
		}
		prevStud = nullptr; 
	}
};

struct RealValue
{
	double value = 0;
	RealValue* nextValue = nullptr;

	void getVal()
	{
		cout << value << "  ";
	}
};

struct RealValuesQueue
{
	RealValue* firstValue = nullptr;
	RealValue* currentValue = nullptr;

	void enqueue(double num)
	{
		if (!firstValue)
		{
			firstValue = new RealValue();
			firstValue->value = num;
		}
		else if (!currentValue)
		{
			currentValue = new RealValue();
			currentValue->value = num;
			firstValue->nextValue = currentValue;
		}
		else
		{
			currentValue->nextValue = new RealValue();
			currentValue->nextValue->value = num;
			currentValue = currentValue->nextValue;
		}
	}

	void dequeue(/*float value = 0*/)
	{
		if (firstValue)
		{
			RealValue* valueToDel = firstValue;
			if (!valueToDel->nextValue)
			{
				delete valueToDel;
				firstValue = nullptr;
				return;
			}
			while (valueToDel->nextValue != currentValue)
			{
				valueToDel = valueToDel->nextValue;
			}
			currentValue = valueToDel;
			delete currentValue->nextValue;
			currentValue->nextValue = nullptr;
			if (firstValue == currentValue)
				currentValue = nullptr;
		}
	}

	double show()
	{
		double sum = 0;
		if (!currentValue && firstValue)
		{
			firstValue->getVal();
			cout << endl;
			if (abs(currentValue->value) < 1)
			{
				sum += currentValue->value;
			}
		}
		else if (!firstValue)
			cout << 0 << endl;
		else
		{
			currentValue = firstValue;
			currentValue->getVal();
			if (abs(currentValue->value) < 1)
			{
				sum += currentValue->value;
			}
			while (currentValue->nextValue)
			{

				currentValue = currentValue->nextValue;
				currentValue->getVal();
				if (abs(currentValue->value) < 1)
				{
					sum += currentValue->value;
				}
			}
			cout << endl;
		}
		return sum;
	}
};

struct Node
{
	double data = 0;
	Node* next = nullptr;
};

struct Queue
{
	Node* head = nullptr, *tail = nullptr;
	size_t count = 0;

	void add(double value)
	{
		if (!head)
		{
			head = new Node();
			head->data = value;
		}
		else if (!tail)
		{
			tail = new Node();
			tail->data = value;
			head->next = tail;
		}
		else
		{
			tail->next = new Node();
			tail->next->data = value;
			tail = tail->next;
		}
		count++;
	}

	void add_node(Node* node)
	{
		if (!head)
		{
			head = node;
		}
		else if (!tail)
		{
			tail = node;
			head->next = tail;
		}
		else
		{
			tail->next = node;
			tail = tail->next;
		}
		count++;
	}

	void insert_by_num(double by_num, double value)
	{
		Node* insertance;
		for (Node* next = head; next; next = next->next)
		{
			if (next->data < by_num)
			{
				insertance = new Node();
				insertance->data = value;
				insertance->next = next->next;
				next->next = insertance;
				next = next->next;
				count++;
			}
		}
	}

	void remove_at_range(double minVal, double maxVal)
	{
		if (head)
		{
			Node* save;
			while (head && head->data >= minVal && head->data <= maxVal)
			{
				save = head->next;
				delete head;
				head = save;
				if (head == tail)
					tail = nullptr;
				count--;
			}
			for (Node* next = head; next; next = next->next)
			{
				while (next->next && next->next->data >= minVal && next->next->data <= maxVal)
				{
					save = next->next->next;
					delete next->next;
					next->next = save;
					count--;
				}
			}
		}
	}

	static void integrate(Queue& queue1, Queue& queue2) 
	{
		if (queue1.head != queue2.head)
		{
			Queue queue;
			while (queue1.head && queue2.head)
			{
				if (queue1.head->data < queue2.head->data)
				{
					queue.add_node(queue1.head);
					queue1.head = queue1.head->next;
				}
				else
				{
					queue.add_node(queue2.head);
					queue2.head = queue2.head->next;
				}
			}
			if (!queue1.head)
			{
				while (queue2.head)
				{
					queue.add_node(queue2.head);
					queue2.head = queue2.head->next;
				}
			}
			else if (!queue2.head)
			{
				while (queue1.head)
				{
					queue.add_node(queue1.head);
					queue1.head = queue1.head->next;
				}
			}
			queue1.head = queue.head;
			queue2.head = queue.head;
		}
	}

	void sort_ascendinG() 
	{
		if (tail)
			for (size_t i = 0; i < count; i++)
			{
				for (Node* next = head; next; next = next->next)
				{
					if (next->next && next->data > next->next->data)
						std::swap(next->data, next->next->data);
				}
			}
	}

	void show()
	{
		if (head)
		{
			for (Node* next = head; next; next = next->next)
			{
				std::cout << std::setw(5) << next->data << " ";
			}
			std::cout << std::endl;
		}
		else std::cout << "NULL" << std::endl;
	}
};

void Task1()
{
	StackOfStudents stack;
	stack.add();
	stack.show();
	stack.clear();
}

void Task2()
{
	RealValuesQueue queue;
	double nums[4] = { 2.2, 3.2, 2.4, -3.2 };
	for (size_t i = 0; i < 4; i++)
	{
		queue.enqueue(nums[i]);
	}
	cout << "очередь: ";
	queue.show();
	queue.dequeue();
	queue.enqueue(0.04);
	cout << "очередь: ";
	cout << "сумма " << queue.show();
}

void Task3()
{
	Queue queue1, queue2;

	queue1.add(3);
	queue1.add(-1);
	queue1.add(0);
	queue1.sort_ascendinG();
	std::cout << std::setw(18) << "очередь 1: ";
	queue1.show();

	queue2.add(22);
	queue2.add(-5);
	queue2.add(10);
	queue2.sort_ascendinG();
	std::cout << std::setw(18) << "очередь 2: ";
	queue2.show();

	Queue::integrate(queue1, queue2);
	std::cout << std::setw(18) << "интегрированная очередь: ";
	queue1.show();
	std::cout << std::setw(18) << "указатели: " << std::setw(9) << "глава - " << queue1.head << std::setw(12) << "хвост - " << queue1.tail;
}



int main()
{
	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;
	setlocale(LC_ALL, "Russian");

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