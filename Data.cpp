#include "Data.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Utilisation des noms des attributs de classe
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
        if (!(file >> label)) return; // Gestion de l'erreur
        std::vector<double> features_vec(_nb_features); 
        for (int j = 0; j < _nb_features; ++j) {
            if (!(file >> features_vec[j])) return;
        }

        // Création le FeatureVector
        FeatureVector fv(features_vec); 

        // Création du Sample
        Sample s(fv, label);

        _data.push_back(s);
    }
}