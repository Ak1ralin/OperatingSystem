# Process Synchronization

## Objectives
- Introduce the **critical-section problem** and solutions to ensure **data consistency**.
- Explore **software and hardware solutions** for critical-section problem.
- Examine several **classical process-synchronization problems**.
- Learn about **synchronization tools** like mutexes, semaphores, and condition variables.

## The Need for Synchronization
- **Processes execute concurrently**, leading to **data inconsistency**.
  - **Data inconsistency**: same data different values.
  - maintaining data consistency **requires orderly execution** of cooperating processes.
- **Race Condition**: When multiple processes access shared resources simultaneously, leading to unpredictable results.
- **Critical Section**: A section of code where **Race condition** might occur.
  - As a result, each process must ask permission to enter the critical section in this order 
  
  `entry section -> critical section -> exit section -> remainder section.`

## Critical Section Problem
A solution must satisfy:
1. **Mutual Exclusion**: No two processes in critical section simultaneously.
2. **Progress**: If no process is in the critical section, one must be allowed to enter.
3. **Bounded Waiting**: A process should not wait indefinitely to enter its critical section.

## Critical-Section Handling in OS
Two approaches to handle:
  - **Non-preemptive kernel**: can't be interrupted
  - **Preemptive kernel**: can be interrupted, run in kernel mode in different processors.
  
## Synchronization Mechanisms
Requires Hardware Support for implementing the critical section code.

**All solutions below based on idea of locking (protecting critical section via locks)**
  - Modern machines provide **atomic hardware instructions (non-interruptible)**

### **Mutex Locks/Spinlocks**
- A **binary lock** that allows only one process/thread to access the critical section at a time.
- Uses `acquire()` and `release()` operations (implement via hardware atomic instructions).
- **Problem**: Leads to **busy waiting** (CPU can't do any other task).

### **Semaphores**
Semaphore **S** - interger variable (only accessed via two operations below)
- **Counting Semaphore**: Unrestricted domain.
- **Binary Semaphore**: Restricted domain (0 or 1) similar to mutex locks. 
- Atomic operations:
  - `wait(S)`: Wait if S $\leq$ 0, then decrements S.
  - `signal(S)`: Increments S -> wakes up a waiting process.
- Used in **producer-consumer, reader-writer problems**.

![Semaphore](appendix\Semaphore.png)

#### Semaphore implementation
Each semaphore there is an associated waiting queue (instead of using **queue**)

Two operation : 
- `block` : place process on appropriate waiting queue.
- `wakeup`: remove process from waiting queue to ready queue.

```c++
typedef struct {
  int value;
  struct process *list; // list of waiting processes (queue)
} semaphore;

wait (semaphore *s) {
  S->value --;
  if(S->value < 0) {
    block(); // add this process to S->list
  }
}

signal (semaphore *s) {
  S->value ++;
  if(S->value <= 0) {
    wakeup(); // remove a process from S->list and put it in ready queue
  }
}
```

### Deadlocks & Starvation
- **Deadlock**: Two or more processes are waiting indefinitely.

![Deadlock](appendix\Deadlock.png)

- **Starvation**: Process never be removed from the semaphore queue.
- **Priority Inversion**: Lower priority hold lock, higher priority get CPU.
  - Solved by priority-inheritance (inherit higher priority until they finish process).

### Classical Synchronization Problems
#### **1. Bounded-Buffer (Producer-Consumer) Problem**

#### **2. Readers-Writers Problem** : Multiple readers can read simultaneously

#### **3. Dining Philosophers Problem**
- Philosophers need multiple chopsticks (semaphore) to eat (access shared data).
- **Solution**: allow n-1 philosophers, allow pick up if both chopsticks are available, assymmetric solution.

### Incorrect use of semaphore operations
- signal ... wait
- wait ... wait
- omitting of either wait or signal

### Synchronization in Operating Systems
- **Linux Synchronization Tools**:
  - **Atomic operations**
  - **Spinlocks** (used in multiprocessor systems)
  - **Mutexes & semaphores** (for process/thread synchronization)


