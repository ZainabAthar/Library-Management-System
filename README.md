# Library Management System - C++ OOP Project

## Overview
Welcome to the Library Management System (LMS) implemented in C++ using Object-Oriented Programming (OOP) concepts. This system allows efficient management of library resources, including issuing and returning books, managing students, and book information.

## Features
- **Modularity**: The system is organized into classes, each representing a distinct entity (IssueBook, ReturnBook, Student, Book) to ensure a modular and scalable structure.
- **Encapsulation**: Data members and methods are encapsulated within classes, providing a clear separation of concerns and enhancing code maintainability.
- **File Handling**: Data is stored in text files (e.g., .txt) to ensure persistent storage of information.

## Classes
### 1. **Issue Book**
   - **IssueBook.h**: Header file for the IssueBook class.
   - **IssueBook.cpp**: Implementation file for the IssueBook class.
   - Manages the issuance of books, tracking details such as issue date, due date, and associated book and student information.

### 2. **ReturnBook**
   - **ReturnBook.h**: Header file for the ReturnBook class.
   - **ReturnBook.cpp**: Implementation file for the ReturnBook class.
   - Handles the return of books, updating book availability and recording return dates.

### 3. **Student**
   - **Student.h**: Header file for the Student class.
   - **Student.cpp**: Implementation file for the Student class.
   - Represents library patrons (students), storing details such as name, ID, and borrowed books.

### 4. **Book**
   - **Book.h**: Header file for the Book class.
   - **Book.cpp**: Implementation file for the Book class.
   - Manages information related to books, such as title, author, and availability.
   
### 5. **Data Files**
   - **issuebook_data.txt**: Text file storing data related to issued books.
   - **returnbook_data.txt**: Text file storing data related to returned books.
   - **student_data.txt**: Text file storing data related to students.
   - **book_data.txt**: Text file storing data related to books.

## Usage
1. Clone the repository: `git clone https://github.com/ZainabAthar/Library-Management-System.git`
2. Compile the source code: `g++ main.cpp issuebook.cpp returnbook.cpp student.cpp book.cpp -o library_system`
3. Run the executable: `./library_system`

## How to Contribute
If you find any bugs or have suggestions for improvements, feel free to open an issue or submit a pull request. Contributions are always welcome!

