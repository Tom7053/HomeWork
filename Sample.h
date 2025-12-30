//
// Created by tomma on 10/12/2025.
//

#ifndef SAMPLE_H
#define SAMPLE_H
#include <string>

#include "FeatureVector.h"


// Sample n'hérite pas de FeatureVector
// Sample contient un FeatureVector

class Sample {
private:
    FeatureVector _fv;
    int _tag;

public:
    Sample(const FeatureVector& fv, int label)
        : _fv(fv), _tag(label) {}    // Constructeur

    const FeatureVector& features() const;
    int tag() const;
    double operator[](int i) const;

    std::string toString() const;      // affichage du Sample
    Sample scale(double multiplicateur) const; // nouveau Sample multiplié

};



#endif //SAMPLE_H
