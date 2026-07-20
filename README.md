# VeloX-Rescue V1: Airborne Receiver Telemetry & Failsafe System

An advanced, non-blocking airborne receiver firmware and failsafe telemetry node developed for the VeloX-Rescue V1 disaster response drone, designed to assist emergency teams during earthquakes and industrial building fires.

## ⚙️ Integrated Hardware Framework

* **Arduino Nano R3** (Central Microcontroller Architecture)
* **MPU6050 6-Axis IMU** (I2C-based dynamic dynamic balance & stabilization tracking)
* **Status Indication Dual-LED Matrix** (Green for active RF link, Red for emergency failsafe)
* **Acoustic Warning Piezo Buzzer** (1 kHz high-decibel disaster beacon alarm)
* **NRF24L01+ RF Transceiver Interface** (High-speed wireless communication link interface)

## 🔌 Circuit Simulation & Wiring Proof:

![Velo-X-rescue-v1-20260720-154131-0000.png](https://postimg.cc/xXg2b0Zb)

## 🚀 Firmware Automation Logic Summary

* **Dynamic Failsafe & Signal Timeout:** Built-in dynamic timing checks trigger an emergency hover mode, visual alert, and high-frequency acoustic beacon within 5000ms of signal loss.
* **Non-Blocking Execution Loop:** Programmed using `millis()` timing routines to ensure zero delay in processing flight stability vector data from the MPU6050 sensor.
* **Serial Telemetry Diagnostics:** Full hardware streams and RF state feedback outputted via the Serial Monitor for instant real-time troubleshooting during field testing.