#include "iostream"
using namespace std;

void occupySeat(int **array, int row, int col)
{
    array[row][col] = 1;
}

void displayClassroom(int **array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void freeMemory(int **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{
    int rows, cols, choice, rowChoice, colChoice;
    bool flag = true;

    cout << "\nEnter number of rows in the classroom: ";
    cin >> rows;
    cout << "\nEnter number of cols in the classrooms: ";
    cin >> cols;

    cout << "\nGenerating Classroom...\n";

    int **classroom = new int *[rows]; // allocating memory
    for (int i = 0; i < rows; i++)
    {
        classroom[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    { // initialising empty classroom
        for (int j = 0; j < cols; j++)
        {
            classroom[i][j] = 0;
        }
    }

    cout << "Classroom Generated! It has " << rows << " rows and " << cols << " columns, and a total of " << rows * cols << " seats.\n";

    cout << "\nYou can pick one of the following options:\n\t1- Book a seat\n\t2- Show seating arrangment\n\t3- Exit program\n";

    while (flag)
    {
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter the row you want to book: ";
            cin >> rowChoice;
            cout << "Enter the column you want to book: ";
            cin >> colChoice;
            if (classroom[rowChoice][colChoice] == 0)
            {
                occupySeat(classroom, rowChoice, colChoice);
            }
            else
            {
                cout << "\nThis seat is already taken!\n";
            }
            break;

        case 2:
            displayClassroom(classroom, rows, cols);
            break;

        case 3:
            freeMemory(classroom, rows);
            flag = false;
            break;

        default:
            cout << "Please Try Again";
            break;
        }
    }

    return 0;
}
