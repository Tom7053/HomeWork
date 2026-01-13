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

