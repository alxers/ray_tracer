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
#include "sphere.h"
#include "hitable.h"
#include "hitable_list.h"
#include "float.h"

// Blends two colors depending of up/downess of the y coord.
// "linear blend" or "lerp" is always of the form:
// blended_val = (1-t) * start_value + t * end_value
vec3 color(const ray &r, hitable *world) {
    hit_record rec;
    if(world->hit(r, 0.0, MAXFLOAT, rec)) {
        return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
    } else {
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    int height = 100;
    int width = 200;
    std::cout << "P3\n" << width << " " << height << "\n255\n";

    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);
    
    hitable *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0, -100.5, -1), 100);
    hitable *world = new hitable_list(list, 2);

    // From top to bottom
    for (int i = height; i > 0; i--) {
        // From left to right
        for (int j = 0; j < width; j++) {
            // Each r/g/b component range from 0.0 to 1.0 by convention
            // we translate to a new range from 0 to 255
            
            // Example g = 0.27, translates to 0.27 * 255.99 = 69.1173

            float u = float(j) / float(width);
            float v = float(i) / float(height);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical);

            vec3 p = r.point_at_parameter(2.0);
            vec3 col = color(r, world);
            
            int translatedR = int(255.99 * col[0]);
            int translatedG = int(255.99 * col[1]);
            int translatedB = int(255.99 * col[2]);

            // std::cout << r << " " << g << " " << b << "\n";
            std::cout << translatedR << " " << translatedG << " " << translatedB << "\n";
        }
    }
}

//int main() {
//    int nx = 200;
//    int ny = 100;
//
//    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
// 
//    vec3 lower_left_corner(-2.0, -1.0, -1.0);
//    vec3 horizontal(4.0, 0.0, 0.0);
//    vec3 vertical(0.0, 2.0, 0.0);
//    vec3 origin(0.0, 0.0, 0.0);
//
//    hitable *list[2];
//    list[0] = new sphere(vec3(0, 0, -1), 0.5);
//    list[1] = new sphere(vec3(0, -100.5, -1), 100);
//    hitable *world = new hitable_list(list, 2);
//
//    for (int j = ny-1; j >= 0; j--) {
//        for (int i = 0; i < nx; i++) {
//
//            float u = float(i) / float(nx);
//            float v = float(j) / float(ny);
//            ray r(origin, lower_left_corner + u * horizontal + v * vertical);
//            vec3 p = r.point_at_parameter(2.0);
//            vec3 col = color(r, world);
//            int ir = int(255.99*col[0]); 
//            int ig = int(255.99*col[1]); 
//            int ib = int(255.99*col[2]); 
//            std::cout << ir << " " << ig << " " << ib << "\n";
//        }
//    }
//}