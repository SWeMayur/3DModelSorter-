# 3D Model Visualizer

### Problem Statement
The 3D Model Sorter Based On Geometrical Information is a QT and OpenGL based project which is used to render 3D STL models and perform sort operation based on some geometrical parameters like heigh of STL model and some other parameters like cost and year of establishment.
The 3D Model Visualizer is a Qt-based application that allows users to visualize and interact with 3D models. The application provides a user-friendly interface for rendering and sorting 3D models based on various parameters such as height, construction cost, and year of establishment. It leverages the Qt framework and OpenGL for graphics rendering.

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
  - [Visualizer](#visualizer)
  - [OpenGLWindow](#openglwindow)
  - [IOOperation](#iooperation)
    - [JsonFileReader](#jsonfilereader)
    - [STLReader](#stlreader)
  - [GeometricEntity](#geometricentity)
  - [COMPARATORS](#comparators)
    - [MaxYDifferenceComparator](#maxydifferencecomparator)
    - [MaxCostComparator](#maxcostcomparator)
    - [YearOfEstablishmentComparator](#yearofestablishmentcomparator)
  - [modelFactory](#modelfactory)
- [How to Use](#how-to-use)
- [Dependencies](#dependencies)
- [Building and Running](#building-and-running)
- [Contributing](#contributing)
- [Architecture Class Diagrams](#Architecture-Class-Diagrams)
- [Output Video](#Output-Video)
## Overview

The project is organized into several components:

### Visualizer

- **Visualizer class (Visualizer.h):** The main application class that extends QMainWindow and handles the user interface and interactions.

### OpenGLWindow

- **OpenGLWindow class (OpenGLWindow.h):** A custom QOpenGLWidget for rendering 3D graphics using OpenGL. It includes functionality for mouse events, STL file reading, sorting, and displaying models.

### IOOperation

#### JsonFileReader

- **JsonFileReader class (JsonFileReader.h):** Handles reading JSON files and populating an unordered_map with the data.

#### STLReader

- **STLReader class (STLReader.h):** Reads STL files and extracts vertices, colors, and normals for 3D models.

### GeometricEntity

#### Point3D

- **Point3D class (Point3D.h):** Represents a point in 3D space with x, y, and z coordinates.

#### Triangle

- **Triangle class (triangle.h):** Represents a triangle in 3D space using three Point3D objects.

### COMPARATORS

#### MaxYDifferenceComparator

- **MaxYDifferenceComparator class (MaxYDifferenceComparator.h):** Comparator for sorting 3D models based on the maximum height difference.

#### MaxCostComparator

- **MaxCostComparator class (MaxCostComparator.h):** Comparator for sorting 3D models based on maximum construction cost.

#### YearOfEstablishmentComparator

- **YearOfEstablishmentComparator class (YearOfEstablishComparator.h):** Comparator for sorting 3D models based on the year of establishment.

### modelFactory

- **ModelGenerator class (modelgenerator.h):** Generates and updates 3D models based on STL files.

## How to Use

1. Open the application by running the executable.
2. Use the "Add Model" button to select STL files for visualization.
3. Select a sorting parameter from the dropdown menu.
4. Click the "Sort" button to rearrange the models based on the chosen parameter.
5. Use the "Show Model" button to visualize the sorted 3D models.
6. Explore the rendered 3D models with mouse interactions.
7. Exit the application using the "Done" button.

## Dependencies

- Qt framework
- OpenGL
- C++ Standard Library

## Building and Running

To build and run the application, follow these steps:

1. Install Qt and ensure the necessary dependencies are available.
2. Open the project in your preferred C++ IDE.
3. Build the project.
4. Run the executable.

## Contributing

If you would like to contribute to the project, please follow the standard GitHub workflow:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes.
4. Submit a pull request to the main repository.

## Architecture Class Diagrams
![3D_Model_Sorter](https://github.com/SWeMayur/3DModelSorter-/assets/149293586/ede30b56-1cb5-4113-be8d-271d06160555)
![Comparators](https://github.com/SWeMayur/3DModelSorter-/assets/149293586/450ee583-40dd-4595-bedf-25918417f6d9)


![ClassDiagram](https://github.com/SWeMayur/3DModelSorter-/assets/149293586/31f84a57-9562-471c-883d-969146304c27)

![Geometry](https://github.com/SWeMayur/3DModelSorter-/assets/149293586/2a15c233-7f55-4d86-8a52-088e2390c2a9)
![Reader](https://github.com/SWeMayur/3DModelSorter-/assets/149293586/9d976edf-d0b3-4c70-b8bd-fae0f4457e2e)

## Output Video

https://github.com/SWeMayur/3DModelSorter-/assets/149293586/d47d895c-8e16-43cb-bf91-aec40daab04a

