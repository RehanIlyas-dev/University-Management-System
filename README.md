<div align="center">

# 🎓 University Management System

### A Powerful Console-Based University Management System built in C++

[![Language](https://img.shields.io/badge/Language-C++-blue.svg?style=for-the-badge&logo=cplusplus)](https://en.cppreference.com/)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-brightgreen.svg?style=for-the-badge&logo=linux)](https://github.com/RehanIlyas-dev/University-Management-System)
[![License](https://img.shields.io/badge/License-Open%20Source-orange.svg?style=for-the-badge)](LICENSE)

<br>

> 🏫 A complete university administration tool with **role-based access**, **CGPA tracking**, **attendance management**, **exam scheduling**, and much more — all from your terminal!

<br>

```
    +================================================+
    |                                                |
    |        UNIVERSITY MANAGEMENT SYSTEM            |
    |                                                |
    +================================================+
```

</div>

---

## 📋 Table of Contents

- [✨ Key Highlights](#-key-highlights)
- [🔐 Authentication System](#-authentication-system)
- [👨‍💼 Admin Features](#-admin-features)
- [🎓 Student Features](#-student-features)
- [📊 CGPA System](#-cgpa-system)
- [🗂️ Data Storage](#️-data-storage)
- [🚀 Getting Started](#-getting-started)
- [📁 Project Structure](#-project-structure)
- [🖥️ Screenshots](#️-screenshots)
- [🛠️ Tech Stack](#️-tech-stack)
- [🤝 Contributing](#-contributing)

---

## ✨ Key Highlights

<table>
<tr>
<td width="50%">

🔐 **Smart Authentication**
- First-time admin signup with password confirmation
- Role-based access (Admin / Student)
- Secure password change for all users

</td>
<td width="50%">

📊 **CGPA & Academics**
- Grade management with A-F grading scale
- Automatic CGPA calculation
- Merit list ranked by performance

</td>
</tr>
<tr>
<td width="50%">

📅 **University Operations**
- Exam schedule management
- Attendance tracking with 75% warning
- Department-wise analytics

</td>
<td width="50%">

💬 **Communication**
- Admin announcements board
- Student feedback system
- Formatted fee receipts

</td>
</tr>
</table>

---

## 🔐 Authentication System

```
┌─────────────────────────────────────────────────┐
│               FIRST TIME LAUNCH                 │
│                                                 │
│  No admin found → Admin creates own account     │
│  ✓ Custom username                              │
│  ✓ Password with confirmation                   │
│  ✓ Stored securely in Users.txt                 │
└─────────────────────────────────────────────────┘
```

| Feature | Description |
|---------|-------------|
| 🆕 **First-time Setup** | Admin creates their own account on first launch |
| 👨‍🎓 **Student Accounts** | Created by admin when enrolling new students |
| 🔑 **Password Change** | Both admin and students can update passwords |
| 🛡️ **Single Admin** | System enforces only one admin account |

---

## 👨‍💼 Admin Features

> **16 powerful tools** to manage the entire university from one dashboard

<details>
<summary><b>📋 Student Management (5 options)</b></summary>

| # | Feature | Description |
|---|---------|-------------|
| 1 | ➕ **Add New Student** | Full registration with username, password, department, fee, and hostel details |
| 2 | 👁️ **View All Students** | List all students with attendance percentages |
| 3 | 🔍 **Search Student** | Find students by roll number or name |
| 4 | ✏️ **Update Student** | Modify any student's information |
| 5 | 🗑️ **Delete Student** | Remove a student from the system |

</details>

<details>
<summary><b>📚 Academics (6 options)</b></summary>

| # | Feature | Description |
|---|---------|-------------|
| 6 | ✅ **Mark Attendance** | Record present/absent for each student |
| 7 | 📝 **Add Student Grade** | Enter subject name, credit hours, and letter grade |
| 8 | 📊 **View Student Grades** | Check any student's full grade report + CGPA |
| 9 | 🏆 **Merit List** | Auto-sorted ranking of all students by CGPA |
| 10 | 📈 **Department Count** | See how many students are in each department |
| 11 | 📅 **Exam Schedule** | Add upcoming exam dates for students to view |

</details>

<details>
<summary><b>📢 Communication & Account (5 options)</b></summary>

| # | Feature | Description |
|---|---------|-------------|
| 12 | 📢 **Post Announcement** | Broadcast notices to all students |
| 13 | 💬 **View Feedback** | Read all student-submitted feedback |
| 14 | 🧹 **Clear Feedback** | Wipe all feedback records |
| 15 | 🔑 **Change Password** | Update admin credentials |
| 16 | 🚪 **Logout** | Return to main login menu |

</details>

---

## 🎓 Student Features

> **10 essential tools** for students to track their academic life

<details>
<summary><b>👤 My Info (5 options)</b></summary>

| # | Feature | Description |
|---|---------|-------------|
| 1 | 👤 **View Profile** | See personal details (name, roll, department, class) |
| 2 | 📊 **View Attendance** | Check attendance % with ⚠️ **warning if below 75%** |
| 3 | 🧾 **Fee Receipt** | Formatted receipt with **PAID** / **UNPAID** status |
| 4 | 🏠 **Hostel Info** | View assigned hostel name and room number |
| 5 | 📈 **View CGPA** | Full grade report with calculated CGPA out of 4.0 |

</details>

<details>
<summary><b>🏫 University (3 options)</b></summary>

| # | Feature | Description |
|---|---------|-------------|
| 6 | 📅 **Exam Schedule** | View all upcoming exam dates |
| 7 | 📢 **Announcements** | Read notices posted by admin |
| 8 | 💬 **Submit Feedback** | Send feedback to admin |

</details>

<details>
<summary><b>🔑 Account (2 options)</b></summary>

| # | Feature | Description |
|---|---------|-------------|
| 9 | 🔑 **Change Password** | Update login credentials |
| 10 | 🚪 **Logout** | Return to main login menu |

</details>

---

## 📊 CGPA System

The CGPA is calculated using the **weighted average formula**:

```
                 Σ (Grade Point × Credit Hours)
    CGPA  =  ─────────────────────────────────────
                    Σ (Credit Hours)
```

### Grading Scale

| Grade | Points | Description |
|:-----:|:------:|:-----------:|
| **A** | 4.0 | Excellent |
| **B** | 3.0 | Good |
| **C** | 2.0 | Average |
| **D** | 1.0 | Below Average |
| **F** | 0.0 | Fail |

### Example

| Subject | Credits | Grade | Points |
|---------|:-------:|:-----:|:------:|
| Mathematics | 3 | A | 4.0 |
| English | 3 | B | 3.0 |
| Physics | 4 | A | 4.0 |
| **CGPA** | | | **(4×3 + 3×3 + 4×4) / (3+3+4) = 3.7** |

---

## 🗂️ Data Storage

All data persists across sessions via auto-generated text files:

```
📂 Data Files
├── 👤 Users.txt        →  username | password | role (Admin/Student)
├── 🎓 Students.txt     →  Full student records
├── 📊 Grades.txt       →  username | subject | credits | grade_point
├── 💬 Feedback.txt     →  user : feedback_message
├── 📅 Exams.txt        →  subject | date
└── 📢 Notices.txt      →  announcement text
```

---

## 🚀 Getting Started

### Prerequisites

| Platform | Requirement |
|----------|------------|
| **Linux** | GCC/G++ compiler (`sudo apt install g++`) |
| **Windows** | MinGW or MSVC |

### Quick Start

```bash
# Clone the repository
git clone https://github.com/RehanIlyas-dev/University-Management-System.git

# Navigate to project
cd University-Management-System/University\ Management\ System

# Compile
g++ main.cpp -o ums

# Run
./ums
```

### First Launch

1. 🖥️ The system detects no admin account
2. 📝 You'll be prompted to create an admin account
3. 🔑 Enter your username and password (with confirmation)
4. ✅ Admin account is created — you're ready to go!

---

## 📁 Project Structure

```
University-Management-System/
│
├── 📄 README.md                              # Documentation
│
└── University Management System/
    ├── 📄 main.cpp                            # Source code (~1380 lines)
    ├── 📄 Users.txt                           # Auto-generated
    ├── 📄 Students.txt                        # Auto-generated
    ├── 📄 Grades.txt                          # Auto-generated
    ├── 📄 Feedback.txt                        # Auto-generated
    ├── 📄 Exams.txt                           # Auto-generated
    └── 📄 Notices.txt                         # Auto-generated
```

---

## 🛠️ Tech Stack

| Component | Technology |
|-----------|-----------|
| **Language** | C++ |
| **UI** | Console with ANSI color codes |
| **Storage** | File-based persistence (`.txt`) |
| **Architecture** | Procedural (functions + parallel arrays) |
| **Compatibility** | Linux & Windows |

---

## 🤝 Contributing

Contributions are welcome! Feel free to:

1. 🍴 Fork the repository
2. 🔧 Create a feature branch (`git checkout -b feature/NewFeature`)
3. 💾 Commit your changes (`git commit -m 'Add NewFeature'`)
4. 📤 Push to the branch (`git push origin feature/NewFeature`)
5. 📬 Open a Pull Request

---

<div align="center">

### ⭐ If you found this project useful, give it a star!

**Made with ❤️ by [Rehan Ilyas](https://github.com/RehanIlyas-dev)**

</div>
