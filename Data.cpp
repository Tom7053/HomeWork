#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Data::Data() {
    _nb_features = 0;
    _nb_samples = 0;
}


void Data::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return; 
    }

    // Lecture des 2 premières lignes
    file >> _nb_samples >> _nb_features; 

    _data.clear();
    _data.reserve(_nb_samples);

    for (int i = 0; i < _nb_samples; ++i) { // Lecture du fichier
        int label;
        if (!(file >> label)) return; // Lire la première valeur rencontrée
        std::vector<double> features_vec(_nb_features); //  Vecteur capable de stocker 70 doubles.
        for (int j = 0; j < _nb_features; ++j) {    //  Boucle 70 fois ==> d'après le fichier d'exemple
            if (!(file >> features_vec[j])) return;  // Lecture des features
        }
        // Création d'un FeatureVector
        FeatureVector fv(features_vec); 

        // Création du Sample
        Sample s(fv, label);   //  Sample = FeatureVector (70 valeurs) + Label(1...9)

        this->add(s);
    }
}

void Data::add(const Sample &s) {
    _data.push_back(s);
    _nb_samples = _data.size(); // MAJ du nombre de sample
}


int Data::nbSamples() const {
    return _nb_samples;
}

const Sample &Data::operator[](int i) const {
    return _data[i];
}

