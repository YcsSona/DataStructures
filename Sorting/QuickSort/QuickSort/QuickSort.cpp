#include<iostream>
using namespace std;

int partition(int arr[], int startIndex, int endIndex)
{
	// Pivot = Last element of the Array
	int pivotElement = arr[endIndex];

	// To keep track of index position
	int pIndex = startIndex;

	for (int i = startIndex; i < endIndex; i++)
	{
		if (arr[i] <= pivotElement)
		{
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;

			pIndex++;
		}
	}

	int temp = arr[endIndex];
	arr[endIndex] = arr[pIndex];
	arr[pIndex] = temp;

	return pIndex;
}

void quickSort(int arr[], int startIndex, int endIndex)
{
	// startIndex will be greater for the left sub-array
	// startIndex will be smaller for the right sub-array
	// startIndex will be equal to the endIndex when there is only one element in the array

	if (startIndex < endIndex)
	{
		int p = partition(arr, startIndex, endIndex);

		// Recursive call for the left partition
		quickSort(arr, startIndex, (p - 1));
		
		// Recursive call for the right partition
		quickSort(arr, (p + 1), endIndex);
	}
}

int main()
{
	const int size = 5;
	int myArray[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the " << i + 1 << " element" << endl;
		cin >> myArray[i];
	}

	cout << "UNSORTED array is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << myArray[i] << " ";
	}

	quickSort(myArray, 0, (size - 1));

	cout << endl << "SORTED array is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << myArray[i] << " ";
	}

	return 0;
}