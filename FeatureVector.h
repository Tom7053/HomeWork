//
// Created by tomma on 10/12/2025.
//

#ifndef FEATUREVECTOR_H
#define FEATUREVECTOR_H
#include <vector>


class FeatureVector {
private:
    std::vector<double> _vector;
    double _norme;

public:
    FeatureVector(const std::vector<double>& features)
        : _vector(features),_norme(0){}   // Constructeur
    int size() const;

    double norme();

    double operator*(const FeatureVector& b) const; // Produit scalaire entre 2 vecteurs

    double operator[](int i) const;

};



#endif //FEATUREVECTOR_H
