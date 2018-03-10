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
            float r = float(j) / float(width);
            float g = float(i) / float(height);
            float b = 0.2;

            int translatedR = (255.99 * r);
            int translatedG = (255.99 * g);
            int translatedB = (255.99 * b);

            // std::cout << r << " " << g << " " << b << "\n";
            std::cout << translatedR << " " << translatedG << " " << translatedB << "\n";
        }
    }

}