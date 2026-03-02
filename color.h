#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

// Color Utility Functions
using color = vec3;

void write_pixel_color(std::ostream& out, const color& pixel_color) {
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    // Translate the [0,1] pixel into [0,255] color data.
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write the pixel color into the output stream.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif