#include <iostream>
#include <fstream>

using namespace std;

int main () {
    // File Operations

    ofstream ppm_image("render.ppm");

    // Image

    int img_size = 256;

    ppm_image << "P3\n" << img_size << " " << img_size << "\n255\n";

    // Render

    for (int j = 0; j < img_size; j++)
    {
        for (int i = 0; i < img_size; i++)
        {
            double r = double(i) / (img_size - 1);
            double g = double(j) / (img_size - 1);
            double b = 0;

            int pixel_r = int(255.999 * r);
            int pixel_g = int(255.999 * g);
            int pixel_b = int(255.999 * b);

            ppm_image << " " << pixel_r;
            ppm_image << " " << pixel_g;
            ppm_image << " " << pixel_b;
        }

        ppm_image << "\n";
    }
    
    return 0;
}