#include<iostream>
using namespace std;

void insertionSort(int arr[])
{
	int key, j;

	for (int i = 1; i < 10; i++) // i = 1 because we have to select next element
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j]; //copy element to next position
			j = j - 1;
		}

		arr[j + 1] = key; // copy the key element at the jth location
	}
}

int main()
{
	int myArray[10];
	
	cout << "Enter 5 interger elements: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> myArray[i];
	}

	cout <<endl << "UNSORTED ARRAY" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << " ";
	}

	cout << endl << endl;

	insertionSort(myArray);

	cout << "SORTED ARRAY" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << " ";
	}
}