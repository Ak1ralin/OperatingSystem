# Introduction to Operating Systems
## Objectives
- Describe the basic organization of computer systems.
- Provide a grand tour of the major components of operating systems.
- Give an overview of the various types of computing environments.

## What is an Operating System?
An **Operating System (OS)** is software that acts as an intermediary between users and computer hardware.
### Goals:
- Execute user programs efficiently, solving user problems easier.
- Make the system convenient to use.
- Manage hardware resources effectively.

## Components of a Computer System
1. **Hardware** – Physical components (CPU, memory, I/O devices) providing basic computing resources.
2. **Operating System** – Controls and coordinates use of hardware among various applications/users.
3. **Application Programs** – User programs which solve user's problem.
4. **Users** – People, machines, and other computers.

## What Operating Systems Do
Operating systems vary based on computing needs:
- **General users** prioritize convenience and usability (ease of use).
- **Server administrators** focus on resource allocation.
- **Mobile phone** optimize for efficiency and battery life.

## OS as a Resource Allocator & Control Program
- **Resource Allocator**: Manages CPU, memory, and devices efficiently.
- **Control Program**: Oversees program execution and prevents system errors and improper use.

## Operating System Definition
- **Kernel**: The one program running at all times on the computer.
- **System Program**: Everything else in the system.

## Computer System Organization & Operations
- **Bootstrap Program (Firmware)** (stored in ROM/(EPROM)) is loaded at power-up or reboot.
  - initializes all aspects of system.
  - loads OS kernel and starts execution.
## Interrupt
- **Interrupt vector**: use to control the interrupt service routine(ISR).
- **Trap/Exception**: software-generated interrupt caused either by an error or a user request.
- **Interrupt Handling** OS preserves the state of CPU by register and program counter.
  - 2 types of interrupt system : **polling** and **vectored interrupts**(more efficient)
- **Dual-Mode Operation**: allow OS to protect itself and other system components.
  - **Mode bit** - provided by hardware to OS for determining current mode of operation.
  - **User Mode** – Normal mode (will automatically switch to kernel mode after execute system call).
  - **Kernel Mode** – Able to execute privileged operations.
- **Timers** prevent infinite loops and ensure fair CPU usage.
  - Set interrupt after specific period
  - Generate an interrupt when counter zero
  
## OS Structure
- **Multiprogramming**: Organizes job to ensures CPU is always executing tasks using **job scheduling**.
- **Timesharing (Multitasking)**: Logical extension of CPU switches jobs.
- **Interactive computing**: allow user interact with each job while it is running.
  - **Process**: Program executing in memory. 
  - **CPU Scheduling**: Decides which process gets CPU time (when several jobs ready to run at same time).
  - **Virtual Memory**: Allows execution of programs not completely in memory (RAM).

## Kernel Data Structures
Common structures used in OS management:
- **Lists** (Singly, Doubly, Circular)
- **Trees** (Binary Search Trees, Balanced Trees) 
- **Hash Maps** (Efficient data lookup)
- **Bitmaps** (Tracking resources)

## Computing Environments
- **Traditional Computing** – Standalone general purpose machines connected via networks.
  - **Portals** - provide web access to internal systems.
  - **Wireless Networks** - allow mobile computers interconnected.
- **Mobile Computing** – Smartphones and tablets with mobile OS.
  - **Extra Feature** - GPS, gyroscope
- **Distributed Systems** – Multiple connected systems sharing resources. **(not exam)**
- **Client-Server Computing** – Central servers providing services to clients.
  - **Compute-server system** - provides an interface to client to request sevices (i.e. database)
  - **File-server system** - provides interface for clients to store and retrieve files.
- **Peer-to-Peer (P2P) Systems** – All nodes act as clients and servers. (another model of distributed system)
- **Virtualization** – Allowing OS to run applications within other OS.
  - **Emulation** - replicates hardware in software, allowing software built for different architectures to run.
  - **Virtualization** - allows multiple OS instances to run on the same physical hardware by using a VMM.
- **Cloud Computing** – Delivering computing resources over the internet.
- **Real-Time Embedded Systems** – Time-sensitive applications in cars, robots, medical, etc.
