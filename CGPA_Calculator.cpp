#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int numCourses;
    cout << "=== CGPA Calculator ===" << endl;
    cout << "Enter number of courses taken: ";
    cin >> numCourses;

    if (numCourses <= 0) {
        cout << "Invalid number of courses!" << endl;
        return 0;
    }

    vector<double> grades(numCourses);
    vector<int> creditHours(numCourses);
    vector<double> gradePoints(numCourses);

    double totalGradePoints = 0;
    int totalCredits = 0;

    // Input for each course
    for (int i = 0; i < numCourses; i++) {
        cout << "\n--- Course " << i + 1 << " ---" << endl;
        cout << "Enter grade (grade point e.g 4.0, 3.5, 3.0): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        gradePoints[i] = grades[i] * creditHours[i];
        totalGradePoints += gradePoints[i];
        totalCredits += creditHours[i];
    }

    // Calculate GPA / CGPA
    double gpa = 0;
    if (totalCredits > 0) {
        gpa = totalGradePoints / totalCredits;
    }

    // Display results
    cout << "\n========================================" << endl;
    cout << "Course Details:" << endl;
    cout << "----------------------------------------" << endl;
    cout << left << setw(10) << "Course"
         << setw(12) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(15) << "Grade Points" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(10) << i + 1
             << setw(12) << grades[i]
             << setw(15) << creditHours[i]
             << setw(15) << gradePoints[i] << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points (grade * credit): " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "GPA for the Semester: " << gpa << endl;
    cout << "Overall CGPA: " << gpa << endl;
    cout << "========================================" << endl;

    return 0;
}
