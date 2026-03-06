# Photon C

A CPU-based ray tracing engine built entirely in C, focusing on data-oriented design and raw mathematical performance. 

## Architectural & Engineering Focus
While inspired by traditional ray tracing literature (e.g., Shirley's methodologies), this engine was built to explore the challenges of implementing complex optical physics without the crutch of C++ Object-Oriented paradigms.

* **Data-Oriented C Architecture:** Bypasses traditional C++ virtual function overhead by utilizing struct-packing and function pointers to handle complex material scattering (Lambertian, Metal, Dielectrics) and hitable geometries.
* **Custom Vector Mathematics:** Implemented a lightweight, zero-dependency linear algebra header from scratch to handle 3D vector operations, dot/cross products, and ray-sphere intersections.
* **Memory & State Management:** Strictly avoids memory leaks in a highly recursive environment (ray bouncing), optimizing the stack depth to prevent overflow during high-sample-rate renders.


## Overview

This project implements a simple ray tracer that renders scenes by tracing rays through a 3D space and calculating how light interacts with objects.

## Project Structure

- `src/`: Contains the source code files (e.g., `main.cpp`).
- `include/`: Contains header files.
  - `raytracer/`: Project-specific headers (e.g., `vec3.h`, `color.h`).
- `render/`: Destination folder for generated PPM images.

## Output

The program generates a PPM image file that can be viewed with any image viewer supporting the PPM format.

## References

- [Ray Tracing in One Weekend](https://raytracing.github.io/)
