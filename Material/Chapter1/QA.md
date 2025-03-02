# Operating System Q&A

## Why do we need an OS?
<details>
  <summary>Show Answer</summary>
  Because most users do not fully understand or efficiently use hardware, an OS acts as an intermediary to help users utilize the computer system effectively. The OS has three main goals:
  1. Ease of use
  2. Ability to run programs and assist users in solving problems
  3. Efficient utilization of hardware resources
</details>

## What does a computer system consist of?
<details>
  <summary>Show Answer</summary>
  1. **Hardware (HW):** The fundamental computing resource
  2. **Operating System (OS):** The intermediary between hardware and the user
  3. **Application:** Software that solves user problems
  4. **User:** Individuals, machines, or other computers using the hardware
</details>

## Does an OS always focus on one aspect?
<details>
  <summary>Show Answer</summary>
  No, it depends on computing needs. For example, mobile devices prioritize power efficiency, but in general, OS design aims for user convenience.
</details>

## Why must the bootstrap program be stored in ROM/EPROM?
<details>
  <summary>Show Answer</summary>
  Because otherwise, the data would be lost when power is cut off.
</details>

## What does dual-mode use to distinguish the current mode?
<details>
  <summary>Show Answer</summary>
  **Mode bit**
</details>

## What is used to prevent infinite loops?
<details>
  <summary>Show Answer</summary>
  **Timer**
</details>

## Why is multiprogramming necessary, and what is its goal?
<details>
  <summary>Show Answer</summary>
  Since a single process rarely utilizes the CPU all the time, multiprogramming helps increase **CPU utilization** by allowing multiple processes to share the CPU.
</details>

## How does virtual memory help?
<details>
  <summary>Show Answer</summary>
  It enables a program to run without being fully loaded into memory.
</details>

## What is the difference between emulation and virtualization?
<details>
  <summary>Show Answer</summary>
  - **Emulation** simulates hardware to run software designed for a different system.
  - **Virtualization** uses the existing hardware but manages resources using a Virtual Machine Monitor (VMM) to run multiple OSs on the same hardware.
</details>
