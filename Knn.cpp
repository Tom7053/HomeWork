//
// Created by tomma on 07/01/2026.
//

#include "Knn.h"

#include <algorithm>
#include <cmath>
Knn::Knn() : _k(0) {}  // Initialise k à 0 par défaut

#include <map> // Nécessaire pour compter les votes

int Knn::getKnn(const Sample& s) const {
    // 1. Calcul des distances
    std::vector<std::pair<double, int>> distances;

    for (int i = 0; i < _lazy_train.nbSamples(); ++i) {
        // Appelle la version de similarity définie dans la classe fille (KnnCosine)
        double dist = similarity(s, _lazy_train[i]);
        distances.push_back(std::make_pair(dist, _lazy_train[i].tag()));
    }

    // 2. Tri (plus petite distance en premier)
    std::sort(distances.begin(), distances.end());

    // 3. Le Vote des k voisins
    std::map<int, int> votes; // Clé=Label, Valeur=Nombre de votes

    // On prend les k premiers (ou moins si on n'a pas assez de données)
    int limit = (_k < distances.size()) ? _k : distances.size();

    for (int i = 0; i < limit; ++i) {
        int label = distances[i].second;
        votes[label]++; // On ajoute une voix pour ce label
    }

    // 4. Trouver le vainqueur
    int best_tag = -1;
    int max_votes = -1;

    for (auto const& paire : votes) {
        if (paire.second > max_votes) {
            max_votes = paire.second;
            best_tag = paire.first;
        }
    }

    return best_tag;
}

