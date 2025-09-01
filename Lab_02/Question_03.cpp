#include <iostream>
using namespace std;

int main() {
    int students;
    cout << "Enter the number of students: ";
    cin >> students;

    int **marks = new int*[students];
    int *courses = new int[students]; 

    for (int i = 0; i < students; i++) {
        cout << "\nEnter number of courses for student " << i + 1 << ": ";
        cin >> courses[i];

        marks[i] = new int[courses[i]]; 

        cout << "Enter marks for " << courses[i] << " courses: ";
        for (int j = 0; j < courses[i]; j++) {
            cin >> marks[i][j];
        }
    }

    cout << "\n--- Student Averages ---\n";
    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < courses[i]; j++) {
            sum += marks[i][j];
        }
        double avg = (double)sum / courses[i];
        cout << "Student " << i + 1 << " average: " << avg << endl;
    }

    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] courses;

    return 0;
}
