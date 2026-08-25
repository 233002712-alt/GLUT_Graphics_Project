# 🐟 2D Aquarium Simulation (OpenGL & GLUT Project)

## 📌 Project Overview
This project is an interactive 2D Aquarium Simulation built using **C++** and **OpenGL (GLUT)**. It showcases underwater aquatic life with multiple animated fishes moving horizontally, rising air bubbles, and underwater grass/seabed design.

The project demonstrates key Computer Graphics principles including **2D Transformations (Translation), Polygon Rendering, Timer-based Animation, and Quadric Objects**.

---

## 🏗️ Detailed Code & Function Architecture

The code is structured into several modular functions to handle rendering, transformation, and animation cleanly:

### 1. Global Variables & State Management
* `fish1X, fish2X, fish3X, fish4X`: Floating-point variables tracking the horizontal ($X$-axis) positions of four individual fishes.
* `bubble1Y, bubble2Y, bubble3Y`: Floating-point variables tracking the vertical ($Y$-axis) positions of rising bubbles.

### 2. Graphics Rendering Functions
* **`drawGrass()`**:
  * Renders the green seabed using `GL_POLYGON` (`glVertex2f`).
  * Draws three distinct clusters of underwater grass blades using `GL_TRIANGLES` at different $X$-coordinates to create visual depth.
* **`drawFish(float x, float y, float r, float g, float b)`**:
  * Accepts dynamic position ($x, y$) and RGB color values ($r, g, b$).
  * **Body:** Drawn using `GL_POLYGON` to create a rhombus-style body.
  * **Fins & Tail:** Uses `GL_TRIANGLES` for top/bottom fins and the tail fin. Color intensity is slightly scaled (`r * 0.8f`) for shading.
  * **Eye:** Drawn using `GL_POINTS` with `glPointSize(5.0f)`.
  * **Matrix Isolation:** Uses `glPushMatrix()` and `glPopMatrix()` along with `glTranslatef(x, y, 0)` to translate each fish independently without affecting global coordinates.
* **`drawBubble(float x, float y, float radius)`**:
  * Uses GLU Quadric Objects (`gluNewQuadric()`) combined with `gluDisk()` and `GLU_SILHOUETTE` style to render smooth, hollow 2D circular bubbles without complex trigonometric functions (`sin`/`cos`).
  * Memory is managed safely using `gluDeleteQuadric(quad)`.

### 3. Core Logic & Animation Control
* **`display()`**:
  * Clears the color buffer using `glClear(GL_COLOR_BUFFER_BIT)`.
  * Calls `drawGrass()`, `drawBubble()`, and `drawFish()` with specific color palettes (Orange, Yellow, Pink, and Green fishes).
  * Executes `glutSwapBuffers()` to achieve smooth double-buffered frame transitions.
* **`update(int value)`**:
  * **Fish Movement:** Increments fish $X$-coordinates at varying speeds ($1.8\text{f}$ to $3.5\text{f}$). When a fish crosses $X > 850$, its position resets to $X = -100$ for a continuous loop.
  * **Bubble Movement:** Increments bubble $Y$-coordinates upward. When $Y > 600$, it resets to the bottom ($Y = 50$).
  * Triggers frame redraw via `glutPostRedisplay()` and maintains a 60 FPS target rate using `glutTimerFunc(16, update, 0)`.
* **`init()`**:
  * Sets the background color to ocean blue (`glClearColor(0.1f, 0.5f, 0.8f, 1.0f)`).
  * Establishes a 2D Orthographic Projection matrix (`gluOrtho2D(0, 800, 0, 600)`).

---

## 🛠️ Concepts & Transformations Used
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
1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/233002712-alt/GLUT_Graphics_Project.git](https://github.com/233002712-alt/GLUT_Graphics_Project.git)
