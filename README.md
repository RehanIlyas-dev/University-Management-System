# 🎓 University Management System (C++)

A console-based University Management System built using C++ with file handling.  
It supports Admin and Student roles for managing student records, attendance, fees, hostel allocation, and feedback.

---

## 🚀 Features

### 👨‍💼 Admin
- Add, View, Update, Delete Students
- Mark Attendance
- View Feedback
- Single Admin Restriction

### 👨‍🎓 Student
- View Profile
- Check Attendance
- Check Fee Status
- View Hostel Info
- Submit Feedback

---

## 🔐 Authentication

- Only one Admin allowed.
- Default Admin (auto-created if none exists):
  
  Username: admin  
  Password: admin123  

- Credentials stored in `Users.txt`.

---

## 📂 Data Files

- `Users.txt` → Login data  
- `Students.txt` → Student records  
- `Feedback.txt` → Feedback messages  

---

## 🛠️ Tech Used

- C++
- fstream (File Handling)
- windows.h (Console Colors)
- conio.h

---

## ▶️ How to Run

1. Open in any C++ IDE (CodeBlocks / Dev-C++ / Visual Studio).
2. Compile and Run.
3. Login as Admin or Student.

---

## ⚠️ Limitations

- Max 100 users/students (fixed arrays)
- No password encryption
- Windows only
- Console-based (no GUI)

---

## 📘 Purpose

Built to practice C++ fundamentals, file handling, authentication, and CRUD operations.
