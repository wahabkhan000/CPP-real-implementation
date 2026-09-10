# CPP Real Implementation

A comprehensive collection of **C++ implementations** demonstrating fundamental data structures, algorithms, and system-level concepts. This project is designed for learning, reference, and portfolio demonstration of core computer science principles.

## Overview

This repository contains 30+ standalone C++ programs organized into three main categories:

- **Core Data Structures** – Linked lists (singly, doubly, circular) with operations like insertion, deletion, traversal, and reversal
- **Advanced Algorithms** – Hash table implementation with collision handling, complex data structure manipulation
- **Real-World Applications** – Browser history, music playlists, text editor, university management, OS simulation

All programs are interactive console applications with user-friendly menu systems and input validation.

---

## Project Components

### 1. Linked List Implementations

**Fundamental Operations:**
- `Linked_List_value_add_from_Head.cpp` – Insert nodes at the head
- `Linked_Lists_Value_adding_from_Tail.cpp` – Insert nodes at the tail
- `Adding value in doubly linked list.cpp` – Insert at arbitrary positions in doubly linked lists
- `Deleting value from Linked List.cpp` – Remove nodes from various positions
- `delete-first-value-in-linked-list.cpp` – Head deletion
- `remove-tail-in-linked-list.cpp` – Tail deletion

**Advanced Operations:**
- `Reverse-Linked-List.cpp` – Reverse list using data swapping
- `Revers-Linked-List-By-Reversing-address.cpp` – Reverse list by pointer manipulation
- `Rotate-Linked-List-based-on-input.cpp` – Rotate by k positions
- `Remove_Nth_Node_From_End_of_List.cpp` – Efficient removal using two pointers
- `Removing_duplicate_from_Linked_List.cpp` – Filter duplicate values
- `Address-of-middle-element.cpp` – Find middle node using slow/fast pointers
- `Finding-address-of-middle-element.cpp` – Middle element location

**Specialized Structures:**
- `Interactive_Circular_Doubly_Linked_List_Traversal.cpp` – Circular list navigation with forward/backward traversal
- `User_Controlled_Circular_Doubly_Linked_List.cpp` – User-driven circular list operations

---

### 2. Hash Table Implementation

**Collision Handling via Separate Chaining:**
- `Hash_Table_Using_Separate_Chaining.cpp` (v1.0, v1.1, v2.0) – Three iterations with increasing features

**Key Features:**
- Polynomial rolling hash function for key distribution
- Separate chaining using linked lists to resolve collisions
- Operations: Insert, search, update, delete, clear
- Statistics tracking: collision count, load factor, chain lengths
- Duplicate key prevention with validation
- Full menu-driven interface

---

### 3. Real-World Applications

#### Browser History Management
`Browser_History_Management_System_using_Doubly_Linked_List.cpp`
- Back/forward navigation
- Current page tracking
- Automatic forward history clearing on new visits
- Page details: title, URL, visit time

#### Music Playlist System
`Music_Playlist_using_a_Circular_Doubly_Linked_List.cpp`
- Add/delete songs with circular traversal
- Play, skip to next/previous track
- Song search (case-insensitive)
- Jump to specific song
- Rename songs
- Full playlist display

#### Text Editor
`Text_Editor_using_Doubly_Linked_List.cpp`
- Insert/delete characters with cursor positioning
- Cursor left/right movement
- Display text with cursor indicator
- Clear entire document

#### University Management System
`University_System_modefied.cpp` & `University_system_by_structs.cpp`
- Nested struct hierarchy: University → Departments → Courses → Instructors & Students
- Student data: ID, name, CGPA (0-4.0), age, address
- Instructor data: Employee ID, salary, address
- Address structure: country, state, city, block
- Input validation for CGPA and age ranges
- Hierarchical data storage and display

---

### 4. System Simulation

#### Operating System Simulator
`OS.cpp`
- **Process Management:** PID generation, arrival time, burst time, memory requirements
- **Memory Management:** 
  - Physical memory allocation with paging
  - Page table generation with frame mapping
  - Page table entries: valid bits, dirty bits, accessed bits, protection bits
- **Scheduling:** FCFS (First-Come-First-Served)
  - Process arrival time sorting
  - Completion time, waiting time, turnaround time, response time calculations
- **CPU Management:** 
  - Ready queue simulation
  - CPU core status tracking (IDLE/BUSY)
  - Detailed process state transitions (NEW → RUNNING → Terminated)
- **Frame Management:**
  - Frame allocation tracking
  - Free/occupied frame statistics
  - Memory utilization display

#### Utility Programs
- `Trafic_fine_calculate.cpp` – Traffic violation fine calculator
- `Voice_generation_from_text.cpp` – Text-to-voice conversion
- `File_input_output.cpp` – Basic file I/O operations

---

## Key Algorithms & Techniques

| Concept | Implementation | Complexity |
|---------|---|---|
| **Linked List Traversal** | Two-pointer technique for middle element | O(n) |
| **List Reversal** | Pointer swapping | O(n) |
| **List Rotation** | Find kth node, reconnect pointers | O(n) |
| **Hash Function** | Polynomial rolling hash with modulo | O(k) per key |
| **Collision Resolution** | Separate chaining with linked lists | O(1 + α) avg |
| **Duplicate Removal** | Linear scan with comparison | O(n) |
| **Process Scheduling** | Arrival time sorting, completion time calculation | O(n log n) |
| **Memory Paging** | Random frame allocation with collision avoidance | O(p) pages |

---

## Architecture & Data Structures

### Node-Based Structures
```
Singly Linked Node:    data → next
Doubly Linked Node:    prev ← data → next
Circular List Node:    last → first (circular)
```

### Hash Table Architecture
```
Hash Function: key → index (0-9)
Bucket: Array of 10 linked list heads
Collision: Chain multiple entries in same bucket
```

### Process Control Block (OS Sim)
```
Static Info:     PID, Arrival Time, Burst Time, Memory
PCB:            State, Completion Time, Waiting Time, Turnaround Time
Page Table:     Page entries → Frame mapping with bits
```

---

## Building & Running

### Prerequisites
- C++17 or later compiler (g++, clang, MSVC)
- Standard library support

### Compilation
```bash
# Single file compilation
g++ -std=c++17 filename.cpp -o executable

# Example: Hash Table
g++ -std=c++17 Hash_Table_Using_Separate_Chaining.cpp -o hashtable
./hashtable
```

### Running Different Programs

**Linked List Example:**
```bash
g++ -std=c++17 "Adding value in doubly linked list.cpp" -o dll
./dll
# Enter list length, position, and value to insert
```

**Music Playlist Example:**
```bash
g++ -std=c++17 Music_Playlist_using_a_Circular_Doubly_Linked_List.cpp -o playlist
./playlist
# Enter number of songs, then use menu (1-9) to manage playlist
```

**OS Simulator Example:**
```bash
g++ -std=c++17 OS.cpp -o os_simulator
./os_simulator
# Select option 1 to create simulation, enter RAM size and frame size
```

---

## Usage Examples

### Hash Table Operations
```
Menu:
1. Insert Key-Value Pair
2. Search Key
3. Update Value
4. Delete Key
5. Display Hash Table
6. Display Statistics

Output:
=========================================
Bucket 0 : (name,John)->(city,NYC)
Bucket 1 : (age,25)
Bucket 2 : Empty
...
Load Factor: 0.3 | Collisions: 2
```

### Music Playlist Operations
```
Select operation from menu (0-9):
1. Add Song
2. Delete Current Song
3. Play Current Song
4. Next Song
5. Previous Song
6. Show Playlist
7. Search Song

Now Playing:
    Song    : Bohemian Rhapsody
    Artist  : Queen
    Duration: 5:55
```

### Process Scheduling Output
```
SIMULATION CONFIGURATION
CPU Cores        : 1
Scheduler        : FCFS
RAM Size         : 128 KB
Page Size        : 32 KB
Number of Frames : 4

PROCESS TABLE
PID    AT    BT    Process Size    State
1042   0     5     20 KB           NEW
2156   1     3     30 KB           NEW
...
```

---

## Learning Outcomes

This project demonstrates proficiency with:

✓ **Pointer & Memory Management** – Dynamic allocation, pointer arithmetic, dereferencing  
✓ **Data Structure Design** – Custom node implementations, collision handling  
✓ **Algorithm Implementation** – Sorting, searching, scheduling algorithms  
✓ **System Concepts** – Process scheduling, memory paging, frame allocation  
✓ **Software Design** – Menu systems, input validation, error handling  
✓ **Problem Solving** – Real-world application modeling (browser, playlists, OS)  

---

## Technical Notes

- **Memory Management:** Manual `new`/`delete` for educational transparency (not production-grade)
- **Input Validation:** Comprehensive checks to prevent crashes from invalid input
- **Platform Specific:** Some files use Windows headers (e.g., `windows.h` for delays)
- **Educational Focus:** Prioritizes clarity and learning over optimization

---

## Planned Enhancements

As noted in the code:
- Round-Robin scheduling (OS simulator v2.0)
- Banker's Algorithm for deadlock prevention (v2.1)
- Priority and preemptive scheduling (v3.0)
- Additional hash table collision strategies

---

## Repository Contents Summary

- **28+ Linked List Programs** – From basic insertion to complex circular traversals
- **3 Hash Table Versions** – Progressive improvements and optimizations
- **4 Real-World Applications** – Browser, playlist, editor, university system
- **1 OS Simulator** – Process and memory management with detailed analytics
- **30+ Total Programs** – Each ~500-10,000 LOC

---

## Getting Started

1. Clone the repository
2. Choose a program that interests you
3. Compile with `g++ -std=c++17 filename.cpp -o output`
4. Run the executable and follow the menu prompts
5. Review the source code to understand implementation details

---

## License

Educational project. Free to use for learning and portfolio purposes.

---

**Last Updated:** September 10, 2026  
**Language:** C++ (100%)  
**Files:** 31  
**Total LOC:** ~5,000+
