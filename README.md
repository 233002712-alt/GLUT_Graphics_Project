# 🐟 2D Aquarium Simulation (OpenGL & GLUT Project)

## 📌 Project Overview
This project is an interactive 2D Aquarium Simulation built using **C++** and **OpenGL (GLUT)**. It showcases underwater aquatic life with multiple animated fishes moving horizontally, rising air bubbles, and underwater grass/seabed design.

The project demonstrates core Computer Graphics concepts like **2D Transformations (Translation)**, **Polygon Rendering**, **Timer-based Animation**, and **Quadric Objects**.

---

## 👥 Authors / Team Members

* **Samrat Anish Paul** - ID: 233002712
* **Priyanti Mohajon Prapti** - ID: 233006612

---

## 📖 Detailed Code Architecture

The code is structured into modules handling graphics rendering, transformations, and animation cleanly:

### 1. Global Variables & State
* `fish1X, fish2X, fish3X, fish4X`: Tracks position (X-axis) of four individual fishes.
* `bubble1Y, bubble2Y`: Tracks rising position (Y-axis) of rising bubbles.

### 2. Graphics Rendering Functions
* `drawGrass()`: Renders green seabed using `GL_POLYGON` (`glVertex2f`).
* `drawFish(float r, float g, float b)`: Custom parameterized fish model using triangles for fins and polygon for body.
* `drawBubble(float x, float y)`: Uses GLUT/GLU Quadrics (`gluDisk`) to draw translucent air bubbles.

### 3. Animation & Logic
* `update(int value)`: Timer callback using `glutTimerFunc`. Updates X-coordinates of fishes and Y-coordinates of bubbles for smooth movement.

---

## ⚙️ Concepts & Transformations Used

* **Translation (`glTranslatef`)**: Used for positioning and moving objects independently.
* **Double Buffering (`GLUT_DOUBLE`)**: Prevents screen flickering during movement.
* **Quadrics (`gluDisk`)**: Used for rendering circular bubble geometry efficiently.
* **Timer Callback (`glutTimerFunc`)**: Controls frame updates and movement velocity.

---

## 💻 Setup & Execution Instructions

### Prerequisites
* C++ Compiler (MinGW / GCC)
* OpenGL & GLUT Libraries (`freeglut`)

### How to Run

1. Clone the Repository:
```bash
git clone https://github.com/233002712-alt/GLUT_Graphics_Project.git
