#ifndef FEATUREVECTOR_H
#define FEATUREVECTOR_H
#include <vector>

class FeatureVector {
private:
    std::vector<double> _vector;
    double _norme; // Stocke la norme pour éviter de la recalculer

public:
    // Constructeur
    FeatureVector(const std::vector<double>& features);

    int size() const;

    // Getter pour la norme (devient const car on lit juste la valeur stockée)
    double norme() const; 

    double operator*(const FeatureVector& b) const; 

    // Accès en lecture (celui que tu avais)
    double operator[](int i) const;
    
    // Accès en écriture (La surcharge demandée par l'UML pour modifier une valeur)
    double& operator[](int i);
};

#endif //FEATUREVECTOR_H