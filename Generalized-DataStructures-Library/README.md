# 🗂️ Generalized Data Structure Library (GDSL)
> This project is a C++ library of generic data structures that provides object-oriented implementations of both linear and non-linear
data structures. 
It offers ready-to-use functionalities for fundamental as well as advanced operations, designed in a generic way using templates so that
they can be reused with any data type. 
The library is designed to support clean OOP principles, modularity, and extensibility making it suitable for both academic learning and
real-world application development.

---

## 📖 Project Overview
GDSL implements a wide range of data structures and algorithms with generic templates :

- Linear Data Structures : Stack, Queue, Singly & Doubly Linked Lists (Linear & Circular)
- Non-Linear Data Structures : Binary Search Tree (BST) with insertion, traversal, search, and counting operations
- Algorithms : Sorting (Bubble, Selection, Insertion), Searching (Linear, Binary)
- Supports multiple data types: `int`, `float`, `double`, `char`

The library allows students and developers to learn, experiment, and integrate these data structures in real-world projects.

---

## 📁 Folder Structure
```
Generalized Data Structure Library/
│
├─ GDSL.cpp
└─ README.md
```

---

## 🧩 Features
- Linear Data Structures
  • Singly Linear Linked List 
  • Singly Circular Linked List 
  • Doubly Linear Linked List 
  • Doubly Circular Linked List 
  • Stack (LIFO) 
  • Queue (FIFO) 

- Non-Linear Data Structures
  • Binary Search Tree (BST) with insert, delete, traversal operations 

- Algorithms
  • Searching (Linear Search, Binary Search etc) 
  • Sorting (Bubble Sort, Selection Sort, Insertion Sort etc) 

- Generic Implementation
  • Uses C++ templates for data type independence. 
  • Same implementation works for integers, floats, strings, and custom objects. 

- Library Format
  • Designed as a reusable C++ library that can be linked with client applications.
    
---

## 🧠 Learning Objectives 
- Mastery of C++ Object-Oriented Programming (OOP) principles. 
- Strong foundation in linear and non-linear data structures. 
- Implementation of generic programming with templates. 
- Practical knowledge of searching and sorting algorithms. 
- Experience in designing reusable libraries for software development.

---

## ⚙️ How to Run

### Compilation
```bash
g++ GDSL.cpp -o GDSL
```

### Execution
```bash
./GDSL     # Linux/Mac
GDSL.exe   # Windows
```

---

## 🧪 Example Usage
Below is a sample demonstration of using the Stack data structure from GDSL :

- Using Stack from GDSL :
```
#include <iostream>
#include "GDSL.cpp"     // Include your library

int main() {
    Stack<int> s;      // Create a stack of integers

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.top() << std::endl;

    // Pop an element
    s.pop();

    std::cout << "Top after pop: " << s.top() << std::endl;

    std::cout << "Stack contents: ";
    while(!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

- Output :
```
Top element: 30
Top after pop: 20
Stack contents: 20 10
```

---

## 🧾 Project Header Format
This project follows a documentation structure:

```
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Project     :  Generalized Data Structure Library (GDSL).
// File        :  GDSL.cpp
// Description :  This project is a C++ library of generic data structures that provides object
//                oriented implementations of both linear & non-linear data structures.
// Author      :  Ishwari Pravin Jadhav
// Date        :  14/09/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////
```

---

## 🧑‍💻 Author
```
Ishwari Pravin Jadhav
Generalized Data Structure Library (GDSL) — C++ Project
2025
```

---

## 🔖 Tags
C++, Templates, OOP, DataStructures, LinkedList, Stack, Queue, BST, Searching, Sorting, Algorithms, GenericProgramming, Library.

---

> 💡 *Generalized Data Structure Library (GDSL) :  A versatile C++ project demonstrating reusable linear & non-linear data structures
with generic programming.*