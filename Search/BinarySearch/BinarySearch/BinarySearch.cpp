#include<iostream>
using namespace std;

// NOTE - Binary search works only on sorted array

int binarySearch(int arr[], int left, int right, int key) {

	while (left <= right)
	{
		int mid = left + (right - left) / 2; // (left + right)/2 would do the same

		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] < key) { // right half
			left = mid + 1;
		}
		else { // left half
			right = mid - 1;
		}
	}

	return -1; // if not found
}

int main()
{
	int myArray[10] = { 1,3,12,14,23,34,55,65,75,78 };
	int output,num;

	cout << "Array is: " << endl;

	for (int i = 0; i <10; i++) {
		cout << myArray[i]<<" ";
	}
	cout << endl << endl;

	cout << "Enter element to search: ";
	cin >> num;

	output = binarySearch(myArray, 0, 9, num);

	if (output == -1)
	{
		cout << "Element not found" << endl;
	}
	else {
		cout << "Element found at position " << output + 1 << endl;
	}
}