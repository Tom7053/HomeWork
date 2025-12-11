//
// Created by tomma on 10/12/2025.
//

#ifndef SAMPLE_H
#define SAMPLE_H
#include "FeatureVector.h"


class Sample {
private:
    FeatureVector _fv;
    int _tag;

public:
    Sample(const FeatureVector& fv, int label)
        : _fv(fv), _tag(label) {}    // Constructeur

    const FeatureVector& features() const;
    int tag() const;
};



#endif //SAMPLE_H
