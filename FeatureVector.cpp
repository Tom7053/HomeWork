#include "FeatureVector.h"
#include <cmath>

// Constructeur : On calcule la norme immédiatement
// (Nécessite de modifier le .h, voir explications plus bas)
FeatureVector::FeatureVector(const std::vector<double>& features)
    : _vector(features) {
    
    double sum = 0.0;
    for (double val : _vector) {
        sum += val * val;
    }
    _norme = std::sqrt(sum);
}

int FeatureVector::size() const {
    return _vector.size();
}

// Cette méthode est maintenant 'const' et très rapide (elle renvoie juste la valeur calculée)
double FeatureVector::norme() const {
    return _norme;
}

double FeatureVector::operator*(const FeatureVector &b) const {    
    // Produit scalaire
    double sum = 0;
    // On suppose que les vecteurs font la même taille
    // (Pour être robuste, on pourrait ajouter un check ici)
    for (int i = 0; i < size(); ++i)
        sum += _vector[i] * b[i];
    return sum;
}

double FeatureVector::operator[](int i) const {
    return _vector[i];
}