#include <iostream>
#include "Data.h"

int main() {
    Data data;
    data.load("digits.svm");  // ../cmake-build-debug

    // Test
    if (data.nbSamples() > 0) {
        const Sample& s = data[0];

        // Affichage
        std::cout << s.toString() << std::endl;

        std::cout << "Multiplie par 2 :" << std::endl;

        // Mise à l'échelle
        Sample s_scaled = s.scale(2);  // Multiplie par 2
        std::cout << s_scaled.toString() << std::endl;
    }

    return 0;
}