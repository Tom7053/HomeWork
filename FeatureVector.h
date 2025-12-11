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
};



#endif //FEATUREVECTOR_H
