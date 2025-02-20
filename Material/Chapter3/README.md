# Process Concept

## Objectives
- Introduce the notion of process.
- Describe the various features of processes (scheduling, creation, termination and communication).
- Explore interprocesses communication using **shared memory** and **message passing**.
- Describe communication in client-server systems.

## Process Concept
An operating system executes multiple types of programs:
- **Batch systems**: Handles jobs.
- **Time-shared systems**: Executes user programs or tasks.
- A **process** is a program in execution, progressing sequentially.
- It consists of multiple parts, including 
  - **text section**: program code, instruction (cannot edit while running)
  - **program counter and processor register**
  - **stack**: contain temporary data (Function parameters, return addresses, local variables)
  - **data section**: contain global variables (static variable)
  - **heap**: containing memory dynamically allocated during run time
- A **process** is active entity, while **program** is passive entity stored in dist (executable file).
- **Program** becomes process when executable file is loaded into memory.
- One program can be several processes (multiple user run same program).

![Process in memory](appendix\ProcessInMemory.png)

## Process State/ Process life cycle
A process can exist in different **states**:
- **New**: Being created.
- **Running**: Being executed.
- **Waiting**: Awaiting an event.
- **Ready**: Waiting for processor assignment (queueing).
- **Terminated**: Finished execution.

![Prcess Life Cycle](appendix\ProcessLifeCycle.png)

## Process Control Block (PCB)/Task control block
Each process is represented by a PCB (Information associated with each process), which contains:
- Process state
- Program counter : location of instruction to next execute
- CPU registers
- CPU scheduling information : priority, scheduling queue pointers
- Memory management information : memory allocated to the process
- Accounting information : CPU time used, clock time elapsed since start, time limits
- I/O status information : I/O devices allocated to process, list of open files

**Use information (state) to switching process (when interrupted)**

## Process Scheduling
To **maximize CPU utilization** and ensure efficient task execution, process scheduling involves:
- **Job queue**: All system processes.
- **Ready queue**: Processes in main memory, ready to execute.
- **Device queue**: Processes waiting for I/O operations.
- Processes migrate between these queues based on scheduling needs.

![Queuing Diagram](appendix\QueuingDiagram.png)

## Scheduling Types
- **Process scheduler**: Select among available processes for next execution on CPU.
- **Long-term scheduler/Job scheduler (optional)**: Select process into ready queue.
  - invoked very infrequently(seconds, minutes) => may be slow
  - controls the degree of multiprogramming
  - strives for good process mix (I/O and CPU)
- **Short-term scheduler/CPU scheduler**: Select process to execute next and allocate CPU.
  - invoked very frequently(milliseconds) => must be fast
  - Scheduler mostly refer
- **Medium-term scheduler**: Memory **swapping** (memory-disk) to control multiprogramming levels.
## Process Types
- **I/O bound process**: I/O > computations, many short CPU bursts
- **CPU bound process**: I/O < computations, few very long CPU bursts

## Context Switching
A context switch occurs when the CPU transitions from one process to another, for saving and loading the process state. Context switching is an **overhead task**, with its efficiency dependent on hardware support.
**Thread is created to handle overhead task from context switching**

## Process Creation and Termination
- **Process Identifier (PID)**: mostly int
- **Creation**: Parent processes create child processes, forming a hierarchy.
  - Children duplicate of parent process, but with different PID.
  - `fork()` : system call creates new process.
  - `exec()` : system call used after `fork()` to replace process's mem-space with new program
- **Resource sharing**: Processes can share **all, some, or none** of the parent’s resources.
- **Execution**: Parent and child execute concurrently, but parent waits until children terminate.
- **Termination**: A process ends when it completes execution or is terminated by the OS (`exit()`), then resource are deallocated by OS.
  - `wait()` : parent will wait for their child finish.
  - `abort()` : parent terminate their child.
  - `cascading termination` : in some OS , parent dead -> child dead
  - **Zombie** : process that already dead, but data still in memory (cant kill).
  - **Orphan** : parent terminate, process will be orphan.

## Interprocess Communication (IPC)
Processes can be independent or cooperating. 

  - Independent process: **Cannot** affect or be affected by execution of other processes
  - Cooperating process: **Can** affect or be affected by execution of other processes

Reason and Advantage for cooperating processes:
- Information sharing
- Computation speedup
- Modularity
- Convenience

Cooperating processes need interprocess communication (IPC), two model of IPC:
  - **Shared Memory**: Same device (message queue/ shared memory).
  - **Message Passing**: Different devices.

Buffer Size
- **Unbounded**: No practical limit on buffer size.
- **Bounded**: Fixed buffer size.

## Message Passing 
- Mechanism for processes to communicate and to synchronize their actions.
- **Message system**: communicate without resorting to shared variables.
- IPC facility provides two operations:
  - **send(message)** : size would be fixed or variable
  - **receive(message)**
- If wish to communicate, they need : 
  - **Communication link** 
    - **Physical**: shared memory, hardware bus
    - **Logical**: direct or indirect 
  - **Exchange message** via send/receive
### Type of communication
- **Direct Communication**: Processes explicitly name each other.
  - **send(receiver, message)**
  - **receive(sender, message)**
  - Properties :
    - Links are established automatically
    - Link and communication pair is one to one
- **Indirect Communication**: Uses mailboxes or ports (socket) for communication.
  - **send(mailbox, message)**
  - **receive(mailbox, message)**
  - Mailbox has a unique id 
  - Processes can communicate only if they share a mailbox
  - Properties :
    - Links are established only if processes share a mailbox
    - Link may associated with many processes
    - Each pair may share several communication Links
  - Operations :
    - create new mailbox -> send/receive through it -> destroy it
  - Issue : Two receivers 
  - Solution : one process allow to receive at a time, system select arbitrarily, sender is notified who receives it

- **Synchronization**: Message passing can be blocking (synchronous) or non-blocking (asynchronous).
  - **Blocking**: synchronous
    - **Blocking send**: sender block until the message is received
    - **Blocking receive**: receiver block until the message is available
  - **Non-blocking**: asynchronous
    - **Non-blocking send**: sender send and continue
    - **Non-blocking receive**: receiver a valid message or null
  - If both send and receive are blocking, we have a `rendezvous`
- **Buffering**: Queue of messages attached to the link
  - **Zero capacity** - Sender must wait for receiver (0 message)
  - **Bounded capacity** - Sender must wait if link full (n messages)
  - **Unbounded capacity** - Sender never waits (infinite messages)

## Communication in Client-Server Systems
- **Remote Procedure Calls (RPC)**: Abstracts procedure calls between networked processes.
  - **Binding server**: Table tell which server for calling procedure. (can use port to differentiation as well)
  - **Stub**: Dummy procedure in client and server
    - **Client Stub**: parameter marshalling (packing parameters to network representation (XDR))
    - **Server Stub**: send parameters to real procedure and send result back to client
![RPC](appendix\RPC.png)
- **Pipes**: Acts as a conduit allowing two processes to communicate.
  - **Ordinary Pipes**: Unidirectional and requires a parent-child relationship.
  - **Named Pipes**: Bidirectional and does not require a parent-child relationship.
  - example combined command : `head -3 /etc/passwd | tail -1` and `cal | head -1`

