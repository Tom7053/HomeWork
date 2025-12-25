//
// Created by tomma on 10/12/2025.
//

#include "FeatureVector.h"
#include <cmath>


int FeatureVector::size() const {
    return _vector.size();
}

double FeatureVector::norme() {     // norme
    double sum = 0.0;
    for (auto x : _vector) {
        sum += x * x;
    }
    _norme = sqrt(sum);
    return std::sqrt(sum);
}

double FeatureVector::operator*(const FeatureVector &b) const {    // Produit scalaire entre le vecteur et un autre
        double sum = 0;
        for (int i = 0; i < size(); ++i)
            sum += this->_vector[i] * b[i];
        return sum;
}

double FeatureVector::operator[](int i) const {
    return _vector[i];
}
