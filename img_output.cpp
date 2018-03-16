// Creates ppm image

// P3
// 3 2
// 255
// # The part above is the header
// # "P3" means this is a RGB color image in ASCII
// # "3 2" is the width and height of the image in pixels
// # "255" is the maximum value for each color
// # The part below is image data: RGB triplets
// 255   0   0     0 255   0     0   0 255
// 255 255   0   255 255 255     0   0   0

#include <iostream>
#include "vec3.h"

int main() {
    int height = 100;
    int width = 200;
    std::cout << "P3\n" << width << " " << height << "\n255\n";

    // From top to bottom
    for (int i = height; i > 0; i--) {
        // From left to right
        for (int j = 0; j < width; j++) {
            // Each r/g/b component range from 0.0 to 1.0 by convention
            // we translate to a new range from 0 to 255
            
            // Example g = 0.27, translates to 0.27 * 255.99 = 69.1173
            vec3 col(float(j) / float(width), float(i) / float(height), 0.2);

            int translatedR = int(255.99 * col[0]);
            int translatedG = int(255.99 * col[1]);
            int translatedB = int(255.99 * col[2]);

            // std::cout << r << " " << g << " " << b << "\n";
            std::cout << translatedR << " " << translatedG << " " << translatedB << "\n";
        }
    }

}
