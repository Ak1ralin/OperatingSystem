# Operating System Q&A

## Why do we need an OS?
**Ans:** Because most users do not fully understand or efficiently use hardware, an OS acts as an intermediary to help users utilize the computer system effectively. The OS has three main goals:
1. Ease of use
2. Ability to run programs and assist users in solving problems
3. Efficient utilization of hardware resources

## What does a computer system consist of?
**Ans:**
1. **Hardware (HW):** The fundamental computing resource
2. **Operating System (OS):** The intermediary between hardware and the user
3. **Application:** Software that solves user problems
4. **User:** Individuals, machines, or other computers using the hardware

## Does an OS always focus on one aspect?
**Ans:** No, it depends on computing needs. For example, mobile devices prioritize power efficiency, but in general, OS design aims for user convenience.

## Why must the bootstrap program be stored in ROM/EPROM?
**Ans:** Because otherwise, the data would be lost when power is cut off.

## What does dual-mode use to distinguish the current mode?
**Ans:** **Mode bit**

## What is used to prevent infinite loops?
**Ans:** **Timer**

## Why is multiprogramming necessary, and what is its goal?
**Ans:** Since a single process rarely utilizes the CPU all the time, multiprogramming helps increase **CPU utilization** by allowing multiple processes to share the CPU.

## How does virtual memory help?
**Ans:** It enables a program to run without being fully loaded into memory.

## What is the difference between emulation and virtualization?
**Ans:**
- **Emulation** simulates hardware to run software designed for a different system.
- **Virtualization** uses the existing hardware but manages resources using a Virtual Machine Monitor (VMM) to run multiple OSs on the same hardware.