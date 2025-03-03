# System Structures 

## Objectives
- Describe the services an operating system provides to users, processes, and other systems.
- Discuss the various ways of structuring an operating system.
- Explain how operating systems are installed, customized, and booted.

## Operating System Services
Operating systems provide a set of essential services (environment) for users and programs :

- **User Interface (UI)**: Can be Command-Line (CLI), Graphical User Interface (GUI), or Batch.
- **Program Execution**: Loads programs into memory, runs them, and handles termination and errors.
- **I/O Operations**: Manages input/output devices and file operations.
- **File-System Manipulation**: Handles file (create, delete, read, write, search), permission management, and storage.
- **Communications**: Enables process communication via shared memory (within) or message passing (among).
    - Shared memory : ไว ，รองรับข้อมูลขนาดใหญ่ แต่เนื่องจากเข้าถึง memory เดียวกันทำให้ต้อง deal เรื่อง synchronization -> race condition
    - Message passing : ช้ากว่า, ข้ามเครื่องได้ ปลอดภัยและเสถียรมากกว่า
- **Error Detection**: Identifies and corrects system errors.
- **Resource Allocation**: Distributes CPU, memory, and I/O resources among processes.
- **Accounting**: Tracks resource usage for each users.
- **Protection & Security**: chain is only as strong as its weakest link (human).
    - **Protection** : all access to system resources must be controlled
    - **Security** : outsider requires user authentication, defending external devices from invalid access attempts.
## User Operating System Interfaces
### Command-Line Interface (CLI) 
- Allows direct user interaction via commands.
- Implemented within the kernel or as a system program (Shell).
- Sometimes command built-in, sometimes just names of programs.

## System Calls
### Definition
- System calls provide an interface between programs and the OS.
- Allows user-level programs to request services from the OS kernel.
- Mostly accessed via high-level **Application Programming Interfaces (APIs)** rather than direct system calls 
  - **Win32 API** (Windows)
  - **POSIX API** (UNIX/Linux/MacOS)
  - **Java API** (JVM-based applications)

### Why use system calls instead of direct kernel access ?
- user's application run in user mode, they can't directly access hardware or perform privileged operations, so they make system calls to request services from the OS kernel.

### Why use APIs rather than system calls?
- APIs provide a higher level interface, making it easier for developers to use OS services.
- **Simplicity** : API provide user-friendly function that abstract complex system calls.
- **Portability** : APIs allow software to be cross-platform without modification, different OS have different system calls.

System Call: ใช้เมื่อ ต้องการควบคุม OS โดยตรง, เช่น เขียน OS, ทำงานกับ Kernel, หรือเขียนโปรแกรมที่ต้องเข้าถึงทรัพยากรระดับต่ำ

Library API: ใช้เมื่อ ต้องการให้โค้ดอ่านง่าย, ดูแลรักษาง่าย, และรองรับหลาย OS

### System Call Parameter Passing
- Parameters passed using: both **Registers** and **Stack-based methods** do not limit the number or length of parameters.
  - **Registers** params stored in a block, or table in memory pass address as param.
  - **Stack-based methods** params pushed on stack, and popped off stack.

## Operating System Design & Implementatio

### Design Considerations
- **Affected by choice of hardware, type of system**
- **User Goals**: Convenient to use, easy to learn, reliable, safe and fast.
- **System Goals**: Easy to design, implement and maintain, also flexible, reliable, error-free and efficient.

### Policy vs. Mechanism
- **Policy (นโยบาย)**: **What** should be done.
- **Mechanism (ทำอย่างไร)**: **How** it should be implemented.
- **Separation of policy from mechanism** allows maximum flexibility, isolate we can change either one. เช่น แก้ scheduling policy โดยไม่แก้ context switching mechanism
- **Portability and Adapability** ปรับแต่งได้ง่ายและรองรับการใช้งานกับระบบอื่นได้ง่ายขึ้น เช่นใช้ Energy-Aware Scheduling Policy ในโทรศัพท์

### Implementation
- Early OSes: Written in **assembly language**.
- Modern OSes: Mostly written in **C, C++, rust, golang** with some scripting support.
- Nowadays usually a mix of languages
  - **Lowest-level** : **assembly** for assigning HW.
  - **Main body** : **C** connecting assembly to other.
  - **System programs** : **C,C+,sripting languages like PEARL, Python, Shell Script**
- High-level languages improve portability and readability but may reduce performance
  
(Assembly ยึดติดกับ HW มากเกินไปหากมีการเปลี่ยน HW อาจจะต้องเขียนโค้ดใหม่หมด ขณะที่ Higher level มี compiler สามารถแปลงไป cross platform ได้ง่ายมากกว่า)

(Higher level อ่านง่ายกว่าทำให้ dev and maintain ง่ายด้วยรวมทั้งยังมีเครื่องมือช่วยเยอะ)
- **Emulation** can allow an OS to run on non-native hardware.

## Operating System Structures
### Types of OS Structures
- **Simple Structure (MS-DOS)**: Minimal structure, not divided into module, monoric.
  - written to provide the most functionality in least space, virus->broke.
- **UNIX**: Limited structuring, two separable parts.
  - **Systems programs**
  - **The kernel** : consists of everything below system-call and above the physical hardware.
- **Layered Approach**: OS divided into layers each build on top of lower layer (level 0 = HW, level 1 = kernel, level n = UI).
- **Microkernel (macOS Darwin)**: Moves as much to user module from kernel, improve security but reduce performance.
- **Modular Kernel (Linux, Solaris)**: Loadable modules provide flexibility and scalability.
- **Key different between Modular and Microkernel**
  - microkernel communicate via message passing, while modular load modules into kernel

## System Boot Process
- **Bootstrapping (Boot Process)**:
  - System starts execution at a fixed memory location (Firmware ROM used to hold initial boot code).
  - **Bootstrap Loader** (stored in ROM/EEPROM) locates the kernel load into memory and starts execution.
    - sometimes two-step, `boot block` at fixed location loaded by ROM, loads `bootstrap loader` from disk.
  - **Boot Managers** (e.g., GRUB) allows selection of kernel from multiple disks, version and kernel options, then running.

## Debugging & Performance Tuning
- **Debugging**: finding and fixing errors (bugs)
  - OS generate `log files` containing error infomation
    - **core dump**: crash on runtime (mostly about memory)
    - **crash dump**: OS source code crash (bug from OS)

- **Performance Tuning**:
  - Uses `trace listing` and `profiling` for analysis.
  - trace listing : log file, save เหตุผลการณ์ว่าเกิดอะไรขึ้นเพื่อติดตามปัญหาในโปรแกรม
  - profiling : แยกโปรแกรมเป็น section, track ว่าส่วนไหนใช้เวลามากสุดเพื่อ identify bottleneck
  - Identifies bottlenecks and remove it to improve performance.
  - Uses system monitors (e.g., Task Manager, `top` command) for optimization.


