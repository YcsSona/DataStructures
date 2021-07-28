#include<iostream>
using namespace std;

void linearSearch(int arr[], int key) {
	int flag = 0;

	for (int  i = 0; i < 5; i++)
	{
		if (arr[i] == key) {
			flag = 1;
			cout << "Element found at position " << i + 1 << endl;
			break;
		}
	}

	if (flag == 0) {
		cout << "Element not found" << endl;
	}
}

int main()
{
	int arr[5];
	int num;

	cout << "Enter array elements: ";

	for (int i = 0;i < 5;i++) {
		cin >> arr[i];
	}

	cout << endl;

	cout << "Array is: ";

	for (int i = 0;i < 5;i++) {
		cout << arr[i] << " ";
	}

	cout << endl << endl;

	cout << "Enter element to search: " << endl;
	cin >> num;

	linearSearch(arr, num);
}