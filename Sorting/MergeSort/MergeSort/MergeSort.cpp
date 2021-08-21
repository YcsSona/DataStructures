#include<iostream>
using namespace std;

/// <summary>
/// Merge function 
/// </summary>
/// <param name="arr"></param>
/// <param name="l"></param>
/// <param name="m"></param>
/// <param name="r"></param>
void merge(int arr[], int l, int m, int r)
{
	// i -> Index for the left sub-array
	// j -> Index for the right sub-array
	// k -> Index for the temp array

	int i = l, j = m + 1, k = l;

	int temp[5];

	// i <= m ---> Iterate over left sub-array
	// j <= r ---> Iterate over right sub-array
	while (i <= m && j <= r)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	/// <summary>
	/// Copying all elements from left sub-array to temp as it is
	/// </summary>
	while (i <= m)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	/// <summary>
	/// Copying all elements from right sub-array to temp as it is
	/// </summary>
	while (j <= r)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	for (int p = l; p <= r; p++)
	{
		arr[p] = temp[p];
	}
}

/// <summary>
/// Mergesort funtion
/// </summary>
/// <param name="arr"></param>
/// <param name="l"></param>
/// <param name="r"></param>
void mergeSort(int arr[], int l, int r) {

	if (l < r)
	{
		int mid = (l + r) / 2;

		mergeSort(arr, l, mid); // for the left half
		mergeSort(arr, mid + 1, r); // for the right half

		merge(arr,l,mid,r);
	}
}

int main()
{
	int myArray[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the " << i + 1 << " element" << endl;
		cin >> myArray[i];
	}

	cout << "UNSORTED array is: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << myArray[i] << " ";
	}

	mergeSort(myArray, 0, 4);

	cout << endl << "SORTED array is: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << myArray[i] << " ";
	}
}