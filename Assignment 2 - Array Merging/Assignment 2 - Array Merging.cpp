// Program to merge two arrays

#include <iostream>
using namespace std;

// Function to accept the elements of the array from the user
void acceptingElements(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
}

// Function to display the elements of the array
void displayingElements(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << a[i];
	}
}

// Function to sort in ascending order the elements of the array
void sortingElements(int a[], int size)
{
	int temp; // temp is a temporary variable
	for (int i = 0; i < size - 1; i++) // To keep track of the number of iterations
	{
		for (int j = 0; j < size - i - 1; j++) // To compare the elements in that particular iteration
		{
			if (a[j] > a[j + 1]) // To sort in ascending order, comparing one element with the next one
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp; // To swap the elements
			}
		}
	}
}

// Function to merge two sorted arrays into a third array in ascending order
void mergingArrays(int a1[], int a2[], int a3[], int size1, int size2)
{
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) // To compare the elements of the two arrays and copy the greatest element to the third array
	{
		if (a1[i] < a2[j])
		{
			a3[k] = a1[i];
			i++;
		}
		else
		{
			a3[k] = a2[j];
			j++;
		}
		k++;
	}
	while (i < size1) // To copy the rest of the elements from the first array if its size is greater than the size of the second array
	{
		a3[k] = a1[i];
		k++;
		i++;
	}
	while (j < size2) // To copy the rest of the elements from the second array if its size is greater than the size of the first array
	{
		a3[k] = a2[j];
		k++;
		j++;
	}
}

int main()
{
	int a1[10], a2[10], a3[20], size1, size2, size3;
	cout << "Mergin two arrays!\n";

	// Accepting the elements of the first array from the user
	cout << "Enter the size of the first array (no greater than 10): ";
	cin >> size1;
	cout << "Enter the elements of the first array:\n";
	acceptingElements(a1, size1);

	// Accepting the elements of the second array from the user
	cout << "Enter the size of the second arrays (no greater than 10): ";
	cin >> size2;
	cout << "Enter the elements of the second array:\n";
	acceptingElements(a2, size2);

	// Sorting the two arrays
	sortingElements(a1, size1);
	sortingElements(a2, size2);

	// Displayin the two sorted arrays 
	cout << "First array sorted:";
	displayingElements(a1, size1);
	cout << "\nSecond array sorted:";
	displayingElements(a2, size2);

	size3 = size1 + size2;

	// Merging the two sorted arrays
	cout << "\nMerged array sorted:";
	mergingArrays(a1, a2, a3, size1, size2);
	displayingElements(a3, size3);
}