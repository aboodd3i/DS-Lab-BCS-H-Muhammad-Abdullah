#include "iostream"
using namespace std;

int *allocateArray(int size)
{
    int *allocatedArray = new int[size];
    return allocatedArray;
}

void freeMemory(int *array)
{
    delete[] array;
    cout << "\nArray Memory Freed.\n";
}

int main()
{
    int size;

    cout << "Please enter the size of the array: ";
    cin >> size;

    int *array = allocateArray(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Please enter element #" << i + 1 << " of the array: ";
        cin >> array[i];
    }

    cout << "\nDisplaying Array:\n";

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }

    freeMemory(array);

    return 0;
}
