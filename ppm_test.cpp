#include <iostream>
#include <fstream>

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
            // Normalize the values of rgb from 0 - 255 to 0.0 - 1.0.
            // That is because we will use them to calculate the pixel color values.
            // We basically turn these into percentages.
            double r = double(i) / (img_width - 1);
            double g = double(j) / (img_height - 1);
            double b = 0; // We ignore blue for this one.

            // Calculating the pixel color values.
            int pixel_r = int(255.999 * r);
            int pixel_g = int(255.999 * g);
            int pixel_b = int(255.999 * b);

            ppm_image << " " << pixel_r;
            ppm_image << " " << pixel_g;
            ppm_image << " " << pixel_b;
        }

        ppm_image << "\n";
        // Finished one scanline of rendering.
    }
    
    return 0;
}