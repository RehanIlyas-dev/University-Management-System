# University Management System

A feature-rich console-based University Management System built in **C++**. It provides separate dashboards for **Admin** and **Students** with role-based authentication, file-based persistence, and a clean colored terminal UI.

---

## Features

### Admin Panel (16 Options)

| # | Feature | Description |
|---|---------|-------------|
| 1 | Add New Student | Register a student with name, roll, department, class, fee & hostel info |
| 2 | View All Students | List all students with attendance percentage |
| 3 | Search Student | Search by roll number or name |
| 4 | Update Student | Modify student details by roll number |
| 5 | Delete Student | Remove a student record |
| 6 | Mark Attendance | Mark present/absent for a student |
| 7 | Add Student Grade | Add subject grades (A/B/C/D/F) with credit hours |
| 8 | View Student Grades | View any student's grade report and CGPA |
| 9 | Merit List | View all students ranked by CGPA (highest first) |
| 10 | Department-wise Count | View student count per department |
| 11 | Add Exam Schedule | Add upcoming exam dates |
| 12 | Post Announcement | Post notices visible to all students |
| 13 | View Feedback | Read feedback submitted by students |
| 14 | Clear All Feedback | Delete all feedback records |
| 15 | Change Password | Update admin password |
| 16 | Logout | Return to login menu |

### Student Dashboard (10 Options)

| # | Feature | Description |
|---|---------|-------------|
| 1 | View Profile | See name, roll, department, class |
| 2 | View Attendance | See attendance % with warning if below 75% |
| 3 | Fee Receipt | Formatted receipt showing PAID/UNPAID status |
| 4 | Hostel Information | View assigned hostel and room number |
| 5 | View CGPA | See grade report with calculated CGPA |
| 6 | View Exam Schedule | See upcoming exam dates |
| 7 | View Announcements | Read admin-posted notices |
| 8 | Submit Feedback | Send feedback to admin |
| 9 | Change Password | Update student password |
| 10 | Logout | Return to login menu |

### Authentication
- **First-time setup**: On first launch, admin creates their own account (username + password with confirmation)
- **Student accounts**: Created by admin when adding a new student
- **Password change**: Both admin and students can change their passwords

---

## Data Files

All data is stored in plain text files (auto-created):

| File | Purpose |
|------|---------|
| `Users.txt` | Usernames, passwords, and roles |
| `Students.txt` | Student records (name, roll, dept, class, fee, hostel) |
| `Grades.txt` | Subject grades with credit hours |
| `Feedback.txt` | Student feedback messages |
| `Exams.txt` | Exam schedule (subject + date) |
| `Notices.txt` | Admin announcements |

---

## How to Run

### Prerequisites
- **Linux**: GCC/G++ compiler
- **Windows**: MinGW or any C++ compiler

### Compile & Run (Linux)
```bash
g++ main.cpp -o ums
./ums
```

### Compile & Run (Windows)
```bash
g++ main.cpp -o ums.exe
ums.exe
```

> **Note**: The current version uses Linux-compatible functions (`system("clear")`, ANSI colors). For Windows, replace `system("clear")` with `system("cls")` and use `<windows.h>` for colors.

---

## Project Structure

```
University Management System/
├── main.cpp          # Main source code (~1380 lines)
├── Users.txt         # User credentials (auto-generated)
├── Students.txt      # Student records (auto-generated)
├── Grades.txt        # Grade records (auto-generated)
├── Feedback.txt      # Feedback data (auto-generated)
├── Exams.txt         # Exam schedule (auto-generated)
├── Notices.txt       # Announcements (auto-generated)
└── README.md         # This file
```

---

## CGPA Calculation

CGPA is calculated using the standard formula:

```
CGPA = Sum(Grade Point x Credit Hours) / Sum(Credit Hours)
```

| Grade | Grade Point |
|-------|-------------|
| A | 4.0 |
| B | 3.0 |
| C | 2.0 |
| D | 1.0 |
| F | 0.0 |

---

## Screenshots

### Login Menu
```
    +================================================+
    |        UNIVERSITY MANAGEMENT SYSTEM            |
    +================================================+

    +================================================+
    |                 LOGIN MENU                     |
    +================================================+
    |    1.  Sign In as Admin                         |
    |    2.  Sign In as Student                       |
    |    3.  Exit                                     |
    +================================================+
```

---

## Technologies Used

- **Language**: C++
- **Storage**: File-based (plain text)
- **UI**: Console with ANSI color codes
- **Architecture**: Procedural (functions + parallel arrays)

---

## License

This project is open source and available for educational purposes.
