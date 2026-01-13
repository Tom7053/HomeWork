#ifndef FEATUREVECTOR_H
#define FEATUREVECTOR_H
#include <vector>

class FeatureVector {
private:
    std::vector<double> _vector;
    double _norme;

public:
    FeatureVector(const std::vector<double>& features);

    int size() const;

    double norme() const; 

    double operator*(const FeatureVector& b) const; 
    double operator[](int i) const;
};

#endif //FEATUREVECTOR_H