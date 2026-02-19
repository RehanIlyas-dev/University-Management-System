# 🎓 University Management System (C++ Console Application)

A console-based University Management System developed in C++ using file handling and modular programming concepts.  
This system provides separate Admin and Student interfaces to manage university records efficiently.

---

## 📌 Project Description

This project is designed to simulate a basic university management environment where:

- Admin can manage student records and attendance.
- Students can view their academic details and submit feedback.
- Data is stored permanently using text files.
- Role-based authentication ensures secure access.

The application runs in a Windows console environment and uses simple text-based UI formatting.

---

## 🚀 Features

### 👨‍💼 Admin Panel
- Add New Students  
- View All Students  
- Update Student Information  
- Delete Students  
- Mark Attendance  
- View Student Feedback  
- Only One Admin Account Allowed  

### 👨‍🎓 Student Dashboard
- View Personal Profile  
- Check Attendance Percentage  
- Check Fee Payment Status  
- View Hostel Allocation Details  
- Submit Feedback  

---

## 🔐 Authentication System

- Secure login for Admin and Students.
- Only one Admin account is permitted.
- If no Admin exists, a default account is created automatically:

  Username: admin  
  Password: admin123  

- All credentials are stored in `Users.txt`.

---

## 📂 Data Storage

The system uses the following files:

- `Users.txt` → Stores usernames, passwords, and roles  
- `Students.txt` → Stores student academic and hostel data  
- `Feedback.txt` → Stores feedback submitted by students  

All records are preserved even after closing the program.

---

## 🛠️ Technologies Used

- C++  
- fstream (File Handling)  
- windows.h (Console Color Formatting)  
- conio.h (Keyboard Handling)  

---

## ▶️ How to Run

1. Open the source file in any C++ IDE (CodeBlocks, Dev-C++, Visual Studio).
2. Compile the program.
3. Run the executable.
4. Login as Admin or Student.

---

## ⚠️ Limitations

- Maximum 100 users/students (fixed-size arrays)
- Passwords stored in plain text
- Windows-only (uses windows.h)
- Console-based (No GUI)

---

## 📘 Learning Objectives

This project demonstrates:

- File handling in C++
- Role-based authentication
- CRUD operations
- Attendance calculation logic
- Structured and modular programming

---

## 👨‍💻 Author

**Rehan Ilyas**  
BS Computer Science  
UET Lahore  

Developed as an academic learning project to strengthen C++ programming and system design concepts.
