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

    int nb_to_read = 0; // Variable temporaire pour la boucle
    int nb_feat = 0;    // Variable temporaire pour les features

    // Lecture des 2 premières lignes
    file >> nb_to_read >> nb_feat;

    // On prépare le stockage
    _data.clear();
    _data.reserve(nb_to_read);

    // On met à jour les attributs de la classe
    _nb_samples = 0; // On repart à 0 et on laissera add() incrémenter
    _nb_features = nb_feat;

    for (int i = 0; i < nb_to_read; ++i) {
        int label;
        // On vérifie qu'on arrive bien à lire le label
        if (!(file >> label)) break;

        std::vector<double> features_vec(_nb_features);
        for (int j = 0; j < _nb_features; ++j) {
            file >> features_vec[j];
        }

        FeatureVector fv(features_vec);
        Sample s(fv, label);

        // add() va incrémenter _nb_samples correctement à chaque ajout
        this->add(s);
    }
}

void Data::add(const Sample &s) {
    // Si c'est le tout premier sample, on fixe le nombre de features
    if (_nb_samples == 0) {
        _nb_features = s.features().size();
    }
    // Sinon, on vérifie que le sample a la bonne taille
    else if (s.features().size() != _nb_features) {
        std::cerr << "Erreur : Taille du sample incohérente !" << std::endl;
        return;
    }

    _data.push_back(s);
    _nb_samples = _data.size();
}


int Data::nbSamples() const {
    return _nb_samples;
}

const Sample &Data::operator[](int i) const {
    return _data[i];
}

