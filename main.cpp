#include <iostream>
#include <fstream>
using namespace std;

//BASE CLASS

class Person
{
protected:
    string name;

public:
    virtual void input()
    {
        cout << "Enter Name : ";
        getline(cin, name);
    }

    virtual void display()
    {
        cout << "\nName : " << name;
    }

    virtual ~Person() {}
};

//DERIVED CLASS 

class Student : public Person
{
private:
    int rollNo;
    float marks;

    static int studentCount;

public:

    // Constructor
    Student()
    {
        rollNo = 0;
        marks = 0;
    }

    // Override Input Function
    void input() override
    {
        cout << "\nEnter Roll Number : ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name : ";
        getline(cin, name);

        try
        {
            cout << "Enter Marks : ";
            cin >> marks;

            if(marks < 0 || marks > 100)
            {
                throw marks;
            }
        }
        catch(float)
        {
            cout << "Invalid Marks!\n";
            cout << "Marks set to 0.\n";
            marks = 0;
        }

        studentCount++;
    }

    // Override Display Function
    void display() override
    {
        cout << "\n--------------------------------";
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nMarks       : " << marks;
        cout << "\nGrade       : " << calculateGrade();
        cout << "\n--------------------------------";
    }

    // Grade Calculation
    char calculateGrade()
    {
        if(marks >= 90)
            return 'A';
        else if(marks >= 75)
            return 'B';
        else if(marks >= 50)
            return 'C';
        else
            return 'F';
    }

    // Getter
    int getRollNo()
    {
        return rollNo;
    }

    float getMarks()
    {
        return marks;
    }

    // Update Student
    void updateStudent()
    {
        cin.ignore();

        cout << "\nEnter New Name : ";
        getline(cin, name);

        try
        {
            cout << "Enter New Marks : ";
            cin >> marks;

            if(marks < 0 || marks > 100)
                throw marks;
        }
        catch(float)
        {
            cout << "Invalid Marks!\n";
            marks = 0;
        }
    }

    // File Writing
    void writeToFile(ofstream &file)
    {
        file << rollNo << endl;
        file << name << endl;
        file << marks << endl;
    }

    // File Reading
    void readFromFile(ifstream &file)
    {
        file >> rollNo;
        file.ignore();

        getline(file, name);

        file >> marks;
        file.ignore();
    }

    // Static Function
    static void showStudentCount()
    {
        cout << "\nTotal Students Added : "
             << studentCount << endl;
    }
};

// Static Variable Definition
int Student::studentCount = 0;

//Main

int main()
{
    Student students[100];

    int totalStudents = 0;

    int choice;

    do
    {
        cout << "\n\n========== STUDENT MANAGEMENT SYSTEM ==========";
        cout << "\n1. Add Student";
        cout << "\n2. View All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Save Data";
        cout << "\n7. Load Data";
        cout << "\n8. Show Total Students";
        cout << "\n9. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            if(totalStudents < 100)
            {
                students[totalStudents].input();
                totalStudents++;

                cout << "\nStudent Added Successfully!";
            }
            else
            {
                cout << "\nStorage Full!";
            }

            break;
        }

        case 2:
        {
            if(totalStudents == 0)
            {
                cout << "\nNo Records Found!";
            }
            else
            {
                // Runtime Polymorphism
                Person *ptr;

                for(int i = 0; i < totalStudents; i++)
                {
                    ptr = &students[i];
                    ptr->display();
                }
            }

            break;
        }

        case 3:
        {
            int roll;
            bool found = false;

            cout << "\nEnter Roll Number : ";
            cin >> roll;

            for(int i = 0; i < totalStudents; i++)
            {
                if(students[i].getRollNo() == roll)
                {
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nStudent Not Found!";
            }

            break;
        }

        case 4:
        {
            int roll;
            bool found = false;

            cout << "\nEnter Roll Number to Update : ";
            cin >> roll;

            for(int i = 0; i < totalStudents; i++)
            {
                if(students[i].getRollNo() == roll)
                {
                    students[i].updateStudent();

                    cout << "\nRecord Updated Successfully!";
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nStudent Not Found!";
            }

            break;
        }

        case 5:
        {
            int roll;
            bool found = false;

            cout << "\nEnter Roll Number to Delete : ";
            cin >> roll;

            for(int i = 0; i < totalStudents; i++)
            {
                if(students[i].getRollNo() == roll)
                {
                    for(int j = i; j < totalStudents - 1; j++)
                    {
                        students[j] = students[j + 1];
                    }

                    totalStudents--;

                    cout << "\nRecord Deleted Successfully!";
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                cout << "\nStudent Not Found!";
            }

            break;
        }

        case 6:
        {
            ofstream file("students.txt");

            for(int i = 0; i < totalStudents; i++)
            {
                students[i].writeToFile(file);
            }

            file.close();

            cout << "\nData Saved Successfully!";
            break;
        }

        case 7:
        {
            ifstream file("students.txt");

            if(!file)
            {
                cout << "\nFile Not Found!";
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

            cout << "\nData Loaded Successfully!";
            cout << "\nTotal Students Loaded : "
                 << totalStudents;

            break;
        }

        case 8:
        {
            Student::showStudentCount();
            break;
        }

        case 9:
        {
            cout << "\nThank You!";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice!";
        }
        }

    } while(choice != 9);

    return 0;
}