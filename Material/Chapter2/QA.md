# System Structure Q&A
## Why use system calls instead of direct kernel access?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  User applications run in **user mode** and do not have direct permission to perform many tasks. System calls allow controlled access to kernel functions.
  
</details>

---

## Why use APIs rather than system calls?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  System calls vary between operating systems. Using APIs increases **portability** across different OS environments.
  
</details>

---

## How many types of system call parameter passing exist? Which ones are not limited in length?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  There are **three** types:
  
  1. Stored in **registers** (limited by register size)
  2. Stored **elsewhere**, with the address kept in a register
  3. **Stack-based** passing (Types 2 and 3 are not limited in length)
  
</details>

---

## How does a Microkernel differ from a Modular Kernel?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Microkernel** moves some kernel functionalities into user modules.
  - **Modular Kernel** allows loading additional modules dynamically into the kernel when needed.
  
</details>

---

## What is the difference between one-step and two-step boot?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **One-step boot:** Fixed location -> Bootstrap loader finds and loads the kernel into memory for execution.
  - **Two-step boot:** Fixed location -> Boot block finds the bootstrap loader (which may be on disk) -> Bootstrap loader finds and loads the kernel into memory.
  
</details>

---

## What causes Core Dump and Crash Dump?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Core Dump:** Runtime crash, often caused by accessing invalid memory.
  - **Crash Dump:** Bug within the OS that leads to a system crash.
  
</details>

---

## What are Trace Listing and Profiling?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Trace Listing:** Records events in a program for debugging.
  - **Profiling:** Records execution time of different code sections to identify bottlenecks.
  
</details>

---

## What command is used to monitor resource usage in Linux?

<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  **top** command
  
</details>