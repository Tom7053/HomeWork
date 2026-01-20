#include "Knn.h"
#include <algorithm>
#include <vector>
#include <map>

Knn::Knn(int k) : _k(k) {}

void Knn::train(const Data& data) {
    _lazy_train = data;
}

int Knn::predict(const Sample& s) const {
    // 1. Calcul des distances avec tous les points d'apprentissage
    // On stocke des paires <Distance/Similarité, Étiquette>
    std::vector<std::pair<double, int>> neighbors;

    for (int i = 0; i < _lazy_train.nbSamples(); ++i) {
        // On appelle la méthode virtuelle similarity
        // Note: selon ta formule, plus c'est petit, plus c'est proche (Distance)
        // Si tu utilises Cosine plus tard, plus c'est grand, plus c'est proche (Similarité)
        double score = similarity(s, _lazy_train[i]);
        neighbors.push_back(std::make_pair(score, _lazy_train[i].tag()));
    }

    // 2. Tri (Plus petite distance en premier)
    // Attention : Si tu utilises Cosine (similarité), il faudra inverser le tri !
    std::sort(neighbors.begin(), neighbors.end());

    // 3. Le Vote parmi les k premiers
    // On utilise un tableau de taille 10 (pour les chiffres 0-9) pour compter les votes
    std::vector<int> votes(10, 0);

    // On regarde seulement les k premiers voisins
    int limit = std::min(_k, (int)neighbors.size()); // Sécurité si k > nb_samples

    for (int i = 0; i < limit; ++i) {
        int label = neighbors[i].second; // Récupère l'étiquette du voisin
        votes[label]++;                  // Ajoute un vote pour ce chiffre
    }

    // 4. Trouver le gagnant (l'indice avec le max de votes)
    int max_votes = -1;
    int winner_label = -1;

    for (int label = 0; label < 10; ++label) {
        if (votes[label] > max_votes) {
            max_votes = votes[label];
            winner_label = label;
        }
    }

    return winner_label;
}