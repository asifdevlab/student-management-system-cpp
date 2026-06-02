#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    // Function to add student details
    void addStudent()
    {
        cout << "\nEnter Roll Number : ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name : ";
        getline(cin, name);

        cout << "Enter Marks : ";
        cin >> marks;
    }

    // Function to display student details
    void displayStudent()
    {
        cout << "\n--------------------------------";
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nMarks       : " << marks;

        // Grade Calculation
        if (marks >= 90)
            cout << "\nGrade       : A";
        else if (marks >= 75)
            cout << "\nGrade       : B";
        else if (marks >= 50)
            cout << "\nGrade       : C";
        else
            cout << "\nGrade       : Fail";

        cout << "\n--------------------------------\n";
    }

    // Getter function
    int getRollNo()
    {
        return rollNo;
    }

    
    // Save data to file
    void writeToFile(ofstream &file)
    {
        file << rollNo << endl;
        file << name << endl;
        file << marks << endl;
    }

    // Read data from file
    void readFromFile(ifstream &file)
    {
        file >> rollNo;
        file.ignore();

        getline(file, name);

        file >> marks;
        file.ignore();
    }
};

int main()
{
    Student students[100];

    int totalStudents = 0;

    int choice;

    do
    {
        cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========";
        cout << "\n1. Add Student";
        cout << "\n2. View All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Save Data to File";
        cout << "\n5. Load Data from File";
        cout << "\n6. Exit";

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                if(totalStudents < 100)
                {
                    students[totalStudents].addStudent();
                    totalStudents++;

                    cout << "\nStudent Added Successfully!\n";
                }
                else
                {
                    cout << "\nStorage Full!\n";
                }

                break;
            }

            case 2:
            {
                if(totalStudents == 0)
                {
                    cout << "\nNo Student Records Found!\n";
                }
                else
                {
                    for(int i = 0; i < totalStudents; i++)
                    {
                        students[i].displayStudent();
                    }
                }

                break;
            }

            case 3:
            {
                int roll;
                bool found = false;

                cout << "\nEnter Roll Number to Search : ";
                cin >> roll;

                for(int i = 0; i < totalStudents; i++)
                {
                    if(students[i].getRollNo() == roll)
                    {
                        students[i].displayStudent();
                        found = true;
                        break;
                    }
                }

                if(found == false)
                {
                    cout << "\nStudent Not Found!\n";
                }

                break;
            }

            case 4:
            {
                ofstream file("students.txt");

                for(int i = 0; i < totalStudents; i++)
                {
                    students[i].writeToFile(file);
                }

                file.close();

                cout << "\nData Saved Successfully!\n";

                break;
            }

            case 5:
            {
                ifstream file("students.txt");

                if(!file)
                {
                    cout << "\nFile Not Found!\n";
                    break;
                }

                totalStudents = 0;

                while(file && totalStudents < 100)
                {
                    students[totalStudents].readFromFile(file);

                    if(file)
                    {
                        totalStudents++;
                    }
                }

                file.close();

                cout << "\nData Loaded Successfully!\n";
                cout << "\nTotal Students Loaded : "
                    << totalStudents << endl;

                cout << "\n===== STUDENT RECORDS =====\n";

                if(totalStudents == 0)
                {
                    cout << "\nNo Records Found!\n";
                }
                else
                {
                    for(int i = 0; i < totalStudents; i++)
                    {
                        students[i].displayStudent();
                    }
                }

                break;
            }

            case 6:
            {
                cout << "\nThank You!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }

    } while(choice != 6);

    return 0;
}