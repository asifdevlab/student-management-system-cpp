# 🎓 Student Management System (C++)

A console-based Student Management System developed in **C++** to demonstrate both fundamental and advanced **Object-Oriented Programming (OOP)** concepts. This project allows users to manage student records efficiently through a menu-driven interface while utilizing file handling for data persistence.

---

## 📌 Project Overview

The Student Management System is designed to perform CRUD (Create, Read, Update, Delete) operations on student records. The project was initially developed as a basic record management system and later enhanced with advanced OOP concepts such as inheritance, polymorphism, virtual functions, exception handling, and static data members.

Student data is stored in a text file, allowing records to persist even after the program is closed.

---

## ✨ Features

* Add new student records
* Display all student records
* Search student by Roll Number
* Update student details
* Delete student records
* Calculate and display grades automatically
* Save records to a file
* Load records from a file
* Count total students using static data members
* Menu-driven user interface
* Input validation using exception handling

---

## 🏗️ OOP Concepts Implemented

### Encapsulation

Student data members are kept private and accessed through member functions.

### Inheritance

The `Student` class inherits from the `Person` base class.

### Constructors

Constructors are used for object initialization.

### Virtual Functions

Virtual functions are implemented in the base class.

### Function Overriding

Derived class functions override base class functions.

### Runtime Polymorphism

Base class pointers are used to access derived class objects.

### Exception Handling

Invalid marks entered by the user are handled using `try-catch` blocks.

### Static Data Members

A static variable keeps track of the total number of students added.

### File Handling

Student records are saved to and loaded from a text file.

---

## 🛠️ Technologies Used

* C++
* Object-Oriented Programming (OOP)
* File Handling
* Exception Handling
* Visual Studio Code (VS Code)

---

## 📂 Project Structure

```text
student-management-system-cpp/
│
├── main.cpp
├── students.txt
└── README.md
```

### File Description

| File           | Description                        |
| -------------- | ---------------------------------- |
| `main.cpp`     | Contains the complete source code  |
| `students.txt` | Stores student records permanently |
| `README.md`    | Project documentation              |

---

## 🚀 How to Run

### Compile

```bash
g++ main.cpp -o sms
```

### Execute

#### Windows

```bash
sms.exe
```

#### Linux/macOS

```bash
./sms
```

---

## 📋 Menu Options

```text
========== STUDENT MANAGEMENT SYSTEM ==========

1. Add Student
2. View All Students
3. Search Student
4. Update Student
5. Delete Student
6. Save Data
7. Load Data
8. Show Total Students
9. Exit
```

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

* Object-Oriented Programming in C++
* Designing and implementing class hierarchies
* Inheritance and Polymorphism
* Exception Handling
* File Handling
* Menu-Driven Application Development
* Data Management Techniques
* Problem Solving and Code Organization

---

## 👨‍💻 Author

**Asif Hussain**

Bachelor of Computer Applications (BCA)

Academic Project – Semester II

---

## 📜 License

This project is created for educational and learning purposes. Feel free to use, modify, and enhance it for academic practice.

---

If you found this project interesting, consider giving the repository a ⭐.
