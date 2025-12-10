//
// Created by tomma on 10/12/2025.
//

#ifndef SAMPLE_H
#define SAMPLE_H
#include "FeatureVector.h"


class Sample {
private:
    FeatureVector _features;
    int _tag;
public:
    Sample(FeatureVector& fv, int tag);
};



#endif //SAMPLE_H
