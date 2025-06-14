# Advanced C++ Project: Aquarium Simulation with Design Patterns

This project focuses on refactoring and extending an initial simulation of an ecosystem using **design patterns**. The goal is to create a flexible, maintainable, and extensible software solution that adheres to object-oriented principles and implements advanced C++ features.

- My Linkedin: https://www.linkedin.com/in/dang-khoa-huynh-50814017b/
---

## Project Overview

The simulation models an **aquarium ecosystem** containing `Bestiole` objects (creatures). Each `Bestiole` has specific attributes such as position, size, speed, and direction, and interacts dynamically with its environment and other `Bestiole` objects.

The project is divided into two main objectives:
1. **Analysis and Design**:
   - Formalize the problem using **UML diagrams** (class diagrams, sequence diagrams, etc.).
   - Use appropriate **design patterns** to address the problem.
2. **Implementation**:
   - Refactor the initial codebase to align with the new design.
   - Implement the specified features and behaviors in C++.

---

## Features

### 1. **Dynamic Behaviors**
Each `Bestiole` has a predefined dynamic behavior:
- **Gregarious**: Adjusts its direction based on the average direction of nearby `Bestiole` objects.
- **Fearful**: Flees in the opposite direction when surrounded by too many `Bestiole` objects.
- **Kamikaze**: Targets the nearest `Bestiole` and attempts to collide with it.
- **Foreseeing**: Estimates the trajectories of nearby `Bestiole` objects and adjusts its own trajectory to avoid collisions.
- **Multiple Personalities**: Randomly switches between behaviors over time.

### 2. **Lifecycle Management**
- **Birth**:
  - Centralized creation of `Bestiole` objects with configurable population distributions (e.g., 20% gregarious, 80% fearful).
  - New `Bestiole` objects can be born spontaneously during the simulation or triggered by external events.
- **Death**:
  - `Bestiole` objects die when they reach their age limit or due to collisions (with a probability of death).
  - External events can also terminate `Bestiole` objects.
- **Cloning**:
  - `Bestiole` objects can clone themselves with a certain probability, creating identical copies.

### 3. **Sensors and Accessories**
`Bestiole` objects can be equipped with sensors and accessories:
- **Sensors**:
  - **Eyes**: Detect other `Bestiole` objects within a specific angular field and distance.
  - **Ears**: Detect other `Bestiole` objects within a circular range.
- **Accessories**:
  - **Fins**: Increase speed by a configurable multiplier.
  - **Shell**: Reduces the probability of death during collisions but decreases speed.
  - **Camouflage**: Reduces detectability by other `Bestiole` objects.

### 4. **Detection Rules**
A `Bestiole` detects another if:
- It hears the other `Bestiole` and its detection capability (ears) is greater than the other's camouflage capability.
- It sees the other `Bestiole` and its detection capability (eyes) is greater than the other's camouflage capability.

### 5. **Simulation Environment**
- The simulation is managed by an **Aquarium** object, which coordinates the lifecycle and interactions of `Bestiole` objects.
- `Bestiole` objects perceive their environment, including the aquarium boundaries and nearby `Bestiole` objects.
- Collisions with aquarium boundaries result in a bounce without damage.

### 6. **Visualization**
- The simulation includes a graphical interface using the **CImg** library.
- Different types of `Bestiole` objects (based on behavior) are visually distinguishable.
- Sensors and accessories are visually represented for each `Bestiole`.

---

## How to Run the Project

1. Ensure you are in the root directory of the project.
2. Compile the project using the following command:
   ```bash
   $ make
   ```
3. Run the compiled binary:
   ```bash
   $ ./bin/main
   ```

---

## Design Patterns Used

1. **Decorator Pattern**:
   - Used to dynamically add sensors and accessories to `Bestiole` objects.
   - Example: Wrapping a `Bestiole` with `EyesDecorator`, `EarsDecorator`, or `FinsDecorator`.

2. **Factory Pattern**:
   - Centralized creation of `Bestiole` objects with configurable behaviors and attributes.

3. **Observer Pattern**:
   - Used to monitor and analyze the state of the simulation at each step.

4. **Strategy Pattern**:
   - Encapsulates dynamic behaviors (`Gregarious`, `Fearful`, etc.) as interchangeable strategies.

5. **Chain of Responsibility Pattern**:
   - Handles the lifecycle events of `Bestiole` objects, such as:
     - **Birth**: Determines when and how new `Bestiole` objects are created.
     - **Death**: Manages the conditions under which `Bestiole` objects die (e.g., age limit or external events).
     - **Collisions**: Resolves collisions between `Bestiole` objects, including bouncing or probabilistic death.

---

![Alt](docs/images/image.png)
