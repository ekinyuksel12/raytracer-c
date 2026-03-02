#include <iostream>
#include <fstream>

#include "vec3.h"
#include "color.h"

using namespace std;

int main () {
    // File Operations

    ofstream ppm_image("render.ppm");

    // Image

    int img_width = 256;
    int img_height = 256;

    // Write the headers of ppm files. P3 for ASCII and the dimentions (columns x rows) at the first line.
    // The next line is 255 maximum limit for pixels.
    ppm_image << "P3\n" << img_width << " " << img_height << "\n255\n";

    // Render

    for (int j = 0; j < img_height; j++)
    {
        cout << "\nScanlines Remaining: " << (img_height - j) << flush;

        for (int i = 0; i < img_width; i++)
        {
            color pixel = color(double (i) / (img_width - 1),
                                double (j) / (img_height - 1),
                                0);

            write_pixel_color(ppm_image, pixel);
        }

        ppm_image << "\n";
        // Finished one scanline of rendering.
    }
    
    return 0;
}