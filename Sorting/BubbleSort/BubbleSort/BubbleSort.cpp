#include<iostream>
using namespace std;

// Repeatedly swaps the adjacent elements
// It is known as bubble sort because with every iteration the largest element bubbles up towards the last place

void BubbleSort(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10-i-1; j++) // n-i-1 as we do not have to check sorted element again
		{
			/// <summary>
			/// Swapping
			/// Mode = ASCENDING
			/// </summary>

			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int myArray[10];

	cout << "Enter 10 integer elements: " << endl;

	for (int i = 0; i < 10; i++)
	{
		cin >> myArray[i];
	}

	cout << endl;

	cout << "UNSORTED ARRAY" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << " ";
	}

	cout << endl << endl;

	BubbleSort(myArray);

	cout << "SORTED ARRAY" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << " ";
	}

}