//
// Created by tomma on 07/01/2026.
//

#include "Knn.h"

#include <algorithm>
#include <cmath>
Knn::Knn() : _k(0) {}  // Initialise k à 0 par défaut

int Knn::getKnn(const Sample& s) const {
    // Vecteur des distances entre sample `s` et chaque exemple (résultats de similarity)
    std::vector<std::pair<double, int>> distances;

    for (int i = 0; i < _lazy_train.nbSamples(); ++i) {
        double dist = similarity(s, _lazy_train[i]);
        distances.push_back(std::make_pair(dist, _lazy_train[i].tag())); // Vecteur = distance + tag
    }

    std::sort(distances.begin(), distances.end()); // trier +petite à +grande distance
}

double Knn::similarity(const Sample& sample1, const Sample& sample2) const {
    double distance = 0.0;
    // Pour chaque "feature" distance = √((x₁-x₂)² + (y₁-y₂)² + ...)
    for (int i = 0; i < sample1.features().size(); ++i) {
        double diff = sample1[i] - sample2[i];
        distance = distance + diff * diff;
    }
    
    return std::sqrt(distance);
}