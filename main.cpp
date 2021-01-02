#include <iostream>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void printArraySelection(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArrayHeap(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr1[] = { 12, 11, 13, 5, 6, 7, 8, 1, 87, 93};
	int arr[] = { 15, 4, 9 ,3 ,2, 12, 11, 14, 21, 24, 1, 10, 16, 5, 8 ,99 ,101, 83, 19, 41, 22, 54, 31, 100, 35, 74, 89 ,
	              23 ,72, 122, 121, 142, 18, 27, 61, 90, 10, 33, 39 ,30 ,28, 102, 112, 84, 92, 48, 107, 105,
                  115, 49, 96 ,13 ,62, 152, 111, 114, 241, 242, 0, 150, 159, 49, 99 ,39 ,29, 129, 119, 149, 219, 249, 19, 109,
                  158, 48, 98 ,38 ,28, 128, 118, 148, 218, 248, 18, 108, 15, 4, 97 ,37 ,27, 127, 117, 147, 217, 247, 17, 107, 119, 125, 303, 999};
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	heapSort(arr, n);
	cout << "Sorted array is " << endl;
	printArraySelection(arr, n);
	printArrayHeap(arr, n);
}
