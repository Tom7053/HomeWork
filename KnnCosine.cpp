#include "KnnCosine.h"
#include <cmath>

class FeatureVector;
KnnCosine::KnnCosine() : Knn() {}  // Appelle le constructeur de Knn

int KnnCosine::predictSingle(const Sample& s) const {
    return getKnn(s);
}

double KnnCosine::similarity(const Sample& sample1, const Sample& sample2) const {
    double distance = 0.0;
    // Pour chaque "feature" distance = √((x₁-x₂)² + (y₁-y₂)² + ...)
    for (int i = 0; i < sample1.features().size(); ++i) {
        double diff = sample1[i] - sample2[i];
        distance = distance + diff * diff;
    }

    return std::sqrt(distance);
}