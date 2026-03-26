# UART Protocol Communication System (C)

## 📌 Overview

This project implements a custom UART communication protocol using Embedded C concepts. It simulates communication between a host and an embedded device.

---

## 🧠 Features

* Packet-based communication protocol
* State machine parser
* Command handling system
* Checksum-based validation

---

## 📦 Packet Structure

[START][LENGTH][COMMAND][DATA][CHECKSUM]

---

## ⚙️ Commands

* `0x01` → LED ON/OFF
* `0x02` → Read Temperature

---

## ▶️ Example Output

LED ON
AA 01 00 01 AC

Temperature: 30
AA 01 00 1E C9

---

## 🏗️ Architecture

UART Input → Protocol Parser → Command Handler → Response

---

## 🚀 How to Run

```bash
gcc src/*.c -Iinclude -o uart
./uart
```

---

## 🎯 Learning Outcomes

* UART protocol design
* Embedded C modular structure
* State machine implementation
* Error handling using checksum

---
