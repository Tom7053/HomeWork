#include "KnnCosine.h"
#include <cmath>

class FeatureVector;
KnnCosine::KnnCosine() : Knn() {}  // Appelle le constructeur de Knn

int KnnCosine::predictSingle(const Sample& s) const {
    return getKnn(s);
}