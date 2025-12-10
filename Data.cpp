//
// Created by tomma on 10/12/2025.
//

#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void Data::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir " << filename << std::endl;
        return;
    }

    int nb_samples, nb_features;
    file >> nb_samples >> nb_features;

    samples.clear();
    samples.reserve(nb_samples);

    for (int i = 0; i < nb_samples; ++i) {
        int label;
        file >> label;

        std::vector<double> features(nb_features);
        for (int j = 0; j < nb_features; ++j)
            file >> features[j];

        samples.push_back({label, features});
    }
}

