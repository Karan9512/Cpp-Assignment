#include <iostream>
#include <climits>

using namespace std;

int findMin(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findSecondMax(int arr[], int n) 
{
    int max = INT_MIN, secondMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] != max) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int findSecondMin(int arr[], int n) 
{
    int min = INT_MAX, secondMin = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] < secondMin && arr[i] != min) {
            secondMin = arr[i];
        }
    }
    return secondMin;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Minimum: " << findMin(arr, n) << endl;
    cout << "Maximum: " << findMax(arr, n) << endl;
    cout << "Second Maximum: " << findSecondMax(arr, n) << endl;
    cout << "Second Minimum: " << findSecondMin(arr, n) << endl;

    return 0;
}
