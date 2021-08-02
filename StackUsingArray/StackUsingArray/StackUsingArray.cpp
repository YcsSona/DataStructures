#include<iostream>
using namespace std;

class Stack {
private:
	int top;
	int myArray[5];

public:

	/// <summary>
	/// Constructor to initialize top and array elements to zero.
	/// </summary>
	
	Stack()
	{
		top = -1;
		for (int i = 0; i < 5; i++)
		{
			myArray[i] = 0;
		}
	}

	/// <summary>
	/// Function to check stack is full or not
	/// </summary>
	
	bool isFull()
	{
		if (top == 4)
		{
			return true;
		}
		return false;
	}

	/// <summary>
	/// Function to check stack is empty or not
	/// </summary>

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}

		return false;
	}

	/// <summary>
	/// Function to add element into the stack
	/// </summary>
	/// <param name="element"></param>

	void push(int element)
	{
		if (isFull())
		{
			cout << "Stack overflow" << endl;
		}
		else
		{
			top++; // increment top first and then push element at top index
			myArray[top] = element;
		}
	}

	/// <summary>
	/// Function to remove element from stack
	/// </summary>

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else {
			int	popValue = myArray[top];
			myArray[top] = 0;
			top--;
			return popValue;
		}
	}

	/// <summary>
	/// Count of total elements in the stack 
	/// </summary>

	int count()
	{
		return (top + 1);
	}

	/// <summary>
	/// To get the element at particular position
	/// </summary>
	/// <param name="position"></param>

	int peek(int position)
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else 
		{
			return myArray[position];
		}
	}

	/// <summary>
	/// Changes element at given position
	/// </summary>
	/// <param name="position"></param>
	/// <param name="element"></param>

	void change(int position, int element)
	{
		myArray[position] = element;
		cout << "Value changed at location" << position << endl;
	}

	/// <summary>
	/// Function to display the stack in DESCENDING order
	/// </summary>

	void display()
	{
		cout << "All elements in the stack are: " << endl;

		for (int i = 4; i >= 0; i--)
		{
			cout << myArray[i] << endl;
		}
	}
};

int main()
{
	Stack s1;
	int option, position, element;

	do
	{
		cout << "What operation do you want to perform? Select option number. Enter 0 to exit" << endl;
		cout << "0. Exit" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. IsEmpty()" << endl;
		cout << "4. IsFull()" << endl;
		cout << "5. Peek()" << endl;
		cout << "6. count()" << endl;
		cout << "7. Change()" << endl;
		cout << "8. Display()" << endl;
		cout << "9. Clear Screen" << endl;

		cin >> option;
		cout << endl << endl;

		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Enter an element to push into the stack" << endl;
			cin >> element;

			s1.push(element);
			break;

		case 2:
			cout << "Pop function called - popped value is: " << s1.pop() << endl;
			break;

		case 3:
			if (s1.isEmpty())
				cout << "Stack is empty" << endl;
			else
				cout << "Stack is not empty" << endl;

			break;

		case 4:
			if (s1.isFull())
				cout << "Stack is full" << endl;
			else
				cout << "Stack is not full" << endl;

			break;

		case 5:
			cout << "Enter position of element you want to peek. " << endl;
			cin >> position;
			cout << "Peek function called - Value at position " << position <<" is " << s1.peek(position) << endl;
			break;

		case 6:
			cout << "Count of total elements is: " << s1.count() << endl;
			break;
		
		case 7:
			cout << "Change function called." << endl;
			cout << "Enter position of element you want to change : ";
			cin >> position;
			cout << endl;
			cout << "Enter value of element you want to change : ";
			cin >> element;

			s1.change(position, element);
			break;

		case 8:
			cout << "Display function called." << endl;
			s1.display();
			break;

		case 9:
			system("cls");
			break;

		default:
			cout << "You have entered wrong option number" << endl;
			break;
		}
	} while (option!=0);
}