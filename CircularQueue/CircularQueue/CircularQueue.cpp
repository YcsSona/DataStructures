#include<iostream>
using namespace std;

class CircularQueue {
private:
	int front;
	int rear;
	int myArray[5];

public:
	CircularQueue()
	{
		front = -1;
		rear = -1;
		for (int i = 0; i < 5; i++)
		{
			myArray[i] = 0;
		}
	}

	/// <summary>
	/// Function to check queue is empty or not 
	/// </summary>

	bool isEmpty()
	{
		if (rear == -1 && front == -1)
			return true;
		else
			return false;
	}

	/// <summary>
	/// Function to check queue is full or not
	/// </summary>

	bool isFull()
	{
		if ((rear + 1)%5 == front) // here 5 is size(N) of the array
			return true;
		else
			return false;
	}

	/// <summary>
	/// Function to add an element in the queue
	/// </summary>
	/// <param name="element"></param>

	void enqueue(int element)
	{
		if (isFull())
		{
			cout << "Queue is full." << endl;
			return;
		}
		else if (isEmpty())
		{
			rear = 0;
			front = 0;
			myArray[rear] = element;
		}
		else
		{
			rear = (rear + 1) % 5; // Similar to rear++ 
			myArray[rear] = element;
		}
	}

	/// <summary>
	/// Function to remove an element from queue 
	/// </summary>

	int dequeue()
	{
		int temp;

		if (isEmpty())
		{
			cout << "Queue is empty." << endl;
			return 0;
		}
		else if (front == rear)
		{
			temp = myArray[front];
			myArray[front] = 0;
			rear = -1;
			front = -1;
			return temp;
		}
		else
		{
			temp = myArray[front];
			myArray[front] = 0;
			front = (front + 1) % 5; // similar to front++
			return temp;
		}
	}

	/// <summary>
	/// Function to displat total elements in the queue 
	/// </summary>

	int count()
	{
		if (rear == -1 && front == -1)
		{
			return 0;
		}
		else
		{
			return (rear - front + 1);
		}
	}

	/// <summary>
	/// Function to display all the elements of the queue
	/// </summary>

	void display()
	{
		cout << "Elements of the queue are: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << myArray[i] << "  ";
		}
	}
};

int main()
{
	CircularQueue cq1;
	int option, element;

	do
	{
		cout << "\n\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
		cout << "0. Exit" << endl;
		cout << "1. Enqueue()" << endl;
		cout << "2. Dequeue()" << endl;
		cout << "3. IsEmpty()" << endl;
		cout << "4. IsFull()" << endl;
		cout << "5. count()" << endl;
		cout << "6. display()" << endl;
		cout << "7. Clear screen" << endl;

		cin >> option;

		switch (option)
		{
		case 0:
			break;

		case 1:
			cout << "ENQUEUE" << endl;
			cout << "Enter an element to add in the queue" << endl;
			cin >> element;

			cq1.enqueue(element);
			break;

		case 2:
			cout << "DEQUEUE" << endl;
			cout << "Dequeued value " << cq1.dequeue() << endl;
			break;

		case 3:
			if (cq1.isEmpty())
				cout << "\nQueue is empty." << endl;
			else
				cout << "\nQueue is not empty." << endl;

			break;

		case 4:
			if (cq1.isFull())
				cout << "\nQueue is full." << endl;
			else
				cout << "\nQueue is not full." << endl;

			break;

		case 5:
			cout << "Total elements in the queue are: " << cq1.count() << endl;
			break;

		case 6:
			cout << endl;
			cq1.display();
			break;

		case 7:
			system("cls");
			break;

		default:
			cout << "You have entered wrong option." << endl;
			break;
		}
	} while (option != 0);
}