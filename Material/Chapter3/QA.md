## Process Q&A

### Process มีกี่ part อะไรบ้าง ทำอะไร？
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  Process ประกอบด้วย 4 ส่วนหลัก:
  - **Text**: เก็บ program code
  - **Stack**: เก็บข้อมูลชั่วคราว เช่น parameters, return address, local variables
  - **Data**: เก็บ global และ static variables
  - **Heap**: ใช้สำหรับ dynamic memory allocation
  
</details>

---

### Program กับ Process ต่างกันอย่างไร?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Program** เป็นไฟล์ที่เก็บชุดคำสั่ง
  - **Process** เป็น instance ของ program ที่กำลังทำงานอยู่
  
</details>

---

### 1 Program เป็นหลาย Process ได้ไหม?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  **ได้** เมื่อ multiple users รันโปรแกรมเดียวกัน จะเกิดหลาย process
  
</details>

---

### Process มีกี่ state อะไรบ้าง?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  มี **5 states**:
  - **New**: Process ถูกสร้างขึ้น
  - **Ready**: รอ CPU
  - **Running**: กำลังทำงานบน CPU
  - **Waiting**: รอ I/O หรือ event อื่น ๆ
  - **Terminated**: Process จบการทำงานแล้ว
  
</details>

---

### Scheduler ที่เรามักพูดถึงหมายถึง scheduler อะไร แล้ว scheduler อื่นมีไว้ทำไม?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Short-term scheduler**: เลือก process ที่จะ run บน CPU
  - **Long-term scheduler**: ควบคุมจำนวน process ในระบบ
  - **Medium-term scheduler**: ใช้สำหรับ swapping process เข้า/ออกจาก RAM เพื่อเพิ่ม performance
  
</details>

---

### ถ้า RAM เราน้อย scheduler ที่ควรมีอีกตัวคืออะไร เพราะอะไร?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Medium-term scheduler** เพราะช่วยทำ **memory swapping** เมื่อ RAM ไม่พอ
  
</details>

---

### Process Type I/O, CPU ดูจากอะไร？
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  ดูจาก **เวลาที่ใช้ในส่วนต่าง ๆ** เช่น ถ้าใช้เวลาส่วนใหญ่ไปกับ I/O -> เป็น I/O-bound process
  
</details>

---

### Context switching save และ load ข้อมูลอ้างอิงจากอะไร?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **Process Control Block (PCB)**
  
</details>

---

### ใน Client-server system client รู้ได้อย่างไรว่าต้องเรียก server อะไร?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - ผ่าน **Binding server**
  
</details>

---

### Client ได้เรียก procedure จริงๆ หรือไม่?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - **ไม่** Client เรียก **server-side stub** ซึ่งเป็นตัวกลางที่ไปเรียก procedure จริงๆ บน server
  
</details>

---

### `head -3 /etc/passwd | tail -1` ทำอะไร?
<details>
  <summary>🔒 Spoiler (Click to Reveal)</summary>
  
  - แสดงบรรทัดที่ **3** ของไฟล์ `passwd`
  
</details>

