#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

const float pi = 3.14F;


int main() {
    auto calc_area = [](float radius, float &perimeter)->float{
        perimeter = 2 * pi * radius;
        return(pi * pow(radius, 2));
    };

    float perimeter = 0, radius;
    cout << "Please enter radius of the circle: ";
    cin >> radius;
    float area = calc_area(radius, perimeter);
    cout << "Area of the cicle = " << area << endl;
    cout << "Perimeter of the cicle = " << perimeter << endl;
    return 0;
}
