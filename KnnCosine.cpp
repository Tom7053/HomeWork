#include "KnnCosine.h"
#include <cmath>
#include <limits>

// Constructeur : UNE SEULE FOIS
KnnCosine::KnnCosine(int k) : Knn(k) {
}

// Méthode similarity
double KnnCosine::similarity(const Sample& s1, const Sample& s2) const {
    const FeatureVector& v1 = s1.features();
    const FeatureVector& v2 = s2.features();

    double dot_product = v1 * v2;
    double n1 = v1.norme();
    double n2 = v2.norme();

    if (n1 == 0 || n2 == 0) {
        return std::numeric_limits<double>::max();
    }

    double cosine_sim = dot_product / (n1 * n2);

    // On renvoie 1 - cosinus pour avoir une "distance" (0 est le meilleur score)
    return 1.0 - cosine_sim;
}