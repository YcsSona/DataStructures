#include<iostream>
using namespace std;

// Selection sort is in-place comparison sort

void selectionSort(int arr[])
{
	for (int i = 0; i < 9; i++) // i = 9 because we do not need to sort the last element(it will be already sorted
	{
		int min = i; 

		/// <summary>
		/// Check the element to be minimum 
		/// Sorting mode = ASCENDING
		/// </summary>

		for (int j = i+1; j < 10; j++) // j = i + 1 because we need compare next element not the same
		{
			if (arr[j] < arr[min])
			{
				min = j;  // assign the index position
			}
		}

		/// <summary>
		/// Swap the minimum element and current element
		/// </summary>

		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main()
{
	int myArray[10];

	cout << "Enter 10 integer elements: "<<endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> myArray[i];
	}

	cout << endl;

	cout << "UNSORTED array is: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << "  ";
	}

	cout << endl << endl;

	selectionSort(myArray);

	cout << "SORTED array is: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << myArray[i] << "  ";
	}
}