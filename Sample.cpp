//
// Created by tomma on 10/12/2025.
//

#include "Sample.h"

int Sample::tag() const {
    { return _tag; }
}
const FeatureVector& Sample::features() const {
    return _fv;
}