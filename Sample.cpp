//
// Created by tomma on 10/12/2025.
//

#include "Sample.h"

#include <sstream>

int Sample::tag() const {
    { return _tag; }
}
const FeatureVector& Sample::features() const {
    return _fv;
}

double Sample::operator[](int i) const {
        return _fv[i];
}

std::string Sample::toString() const {
    std::ostringstream affiche;  // Chap 3 --> page 43
    // Affiche le tag
    affiche << "Sample(tag=" << _tag << ") : [";
    // Affiche chaque FeatureVector
    for (int i = 0; i < _fv.size(); ++i) {
        affiche << _fv[i];
        if (i < _fv.size() - 1) {
            affiche << ", ";
        }
    }
    affiche << "]";
    return affiche.str(); // retourne un string
}


Sample Sample::scale(double multiplicateur) const {
    // Nouveau vecteur
    std::vector<double> scaled_features;
    for (int i = 0; i < _fv.size(); ++i) {
        scaled_features.push_back(_fv[i] * multiplicateur); // Multiplie chaque composante
    }
    // Nouveau FeatureVector
    FeatureVector scaled_fv(scaled_features);
    // Retourne nouveau Sample avec le même tag
    return Sample(scaled_fv, _tag);
}
