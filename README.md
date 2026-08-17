# VeloX-Rescue V1: Airborne Receiver Telemetry & Failsafe System

An advanced, non-blocking airborne receiver firmware and failsafe telemetry node developed for the VeloX-Rescue V1 disaster response drone, designed to assist emergency teams during earthquakes and industrial building fires.

## ⚙️ Integrated Hardware Framework

* **Arduino Nano R3** (Central Microcontroller Architecture)
* **MPU6050 6-Axis IMU** (I2C-based dynamic dynamic balance & stabilization tracking)
* **Status Indication Dual-LED Matrix** (Green for active RF link, Red for emergency failsafe)
* **Acoustic Warning Piezo Buzzer** (1 kHz high-decibel disaster beacon alarm)
* **NRF24L01+ RF Transceiver Interface** (High-speed wireless communication link interface)

## 🔌 Circuit Simulation & Wiring Proof:

[![Velo-X-rescue-v1-20260720-154131-0000.png](https://i.postimg.cc/VNPLpvB4/Velo-X-rescue-v1-20260720-154131-0000.png)](https://postimg.cc/xXg2b0Zb)

## CAD Model Preview 
[![Screenshot-20260729-195602-display-0-png.png](https://i.postimg.cc/L8rzSC4p/Screenshot-20260729-195602-display-0-png.png)](https://postimg.cc/CRsZH4fP)
[![Screenshot-20260729-195534-display-0-png.png](https://i.postimg.cc/Y0qFRTRb/Screenshot-20260729-195534-display-0-png.png)](https://postimg.cc/xJhqTxWz)
[![Screenshot-20260729-195506-display-0-png.png](https://i.postimg.cc/fWBmyTTT/Screenshot-20260729-195506-display-0-png.png)](https://postimg.cc/grLnBpZf)
[![Screenshot-20260729-195446-display-0-png.png](https://i.postimg.cc/3w5DVk9S/Screenshot-20260729-195446-display-0-png.png)](https://postimg.cc/hXsj7PkT)
[![Screenshot-20260729-195418-display-0-png.png](https://i.postimg.cc/bJLDZ3Pm/Screenshot-20260729-195418-display-0-png.png)](https://postimg.cc/ZBBKgPCN)
[![Screenshot-20260729-195329-display-0-png.png](https://i.postimg.cc/597Q17nX/Screenshot-20260729-195329-display-0-png.png)](https://postimg.cc/vDnZtzRy)

## 🚀 Firmware Automation Logic Summary

* **Dynamic Failsafe & Signal Timeout:** Built-in dynamic timing checks trigger an emergency hover mode, visual alert, and high-frequency acoustic beacon within 5000ms of signal loss.
* **Non-Blocking Execution Loop:** Programmed using `millis()` timing routines to ensure zero delay in processing flight stability vector data from the MPU6050 sensor.
* **Serial Telemetry Diagnostics:** Full hardware streams and RF state feedback outputted via the Serial Monitor for instant real-time troubleshooting during field testing.

* ### 🌐 System Architecture Navigation

| [🏠 Master System Repo](https://github.com/KhadijaDawood/VeloX-Rescue-V1-System-Glove-Transmitter-Airborne-Drone-Receiver-Framework-) | [🧤 Glove Transmitter Repo](https://github.com/KhadijaDawood/VeloX-Glove-Transmitter-V1) | [🛸 Drone Receiver Telemetry](https://github.com/KhadijaDawood/VeloX-Rescue-V1-Receiver-Telemetry) |
| :---: | :---: | :---: |

---
