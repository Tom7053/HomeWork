#include "FeatureVector.h"
#include <cmath>
#include <stdexcept> // Pour les erreurs (optionnel mais propre)

// Constructeur : On initialise le vecteur ET on calcule la norme tout de suite
FeatureVector::FeatureVector(const std::vector<double>& features) 
    : _vector(features) {
    
    double sum = 0.0;
    for (auto x : _vector) {
        sum += x * x;
    }
    _norme = std::sqrt(sum);
}

int FeatureVector::size() const {
    return _vector.size();
}

// Optimisation : on retourne juste la valeur stockée
double FeatureVector::norme() const {
    return _norme;
}

double FeatureVector::operator*(const FeatureVector &b) const {
    // Sécurité : vérification des tailles
    if (this->size() != b.size()) {
        throw std::invalid_argument("Les vecteurs doivent avoir la meme taille pour le produit scalaire.");
    }

    double sum = 0;
    for (int i = 0; i < size(); ++i)
        sum += _vector[i] * b[i];
    return sum;
}

double FeatureVector::operator[](int i) const {
    return _vector[i];
}

// Version modifiable (permet de faire : monVecteur[0] = 5.2;)
double& FeatureVector::operator[](int i) {
    return _vector[i];
}