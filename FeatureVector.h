//
// Created by tomma on 10/12/2025.
//

#ifndef FEATUREVECTOR_H
#define FEATUREVECTOR_H
#include <vector>


class FeatureVector {
private:
    std::vector<double> _vector;

public:
    FeatureVector(const std::vector<double>& features)
        : _vector(features) {}   // Constructeur
    int size() const;

    double norme() const;

    double operator*(const FeatureVector& b) const; // Produit scalaire entre 2 vecteurs

};



#endif //FEATUREVECTOR_H
