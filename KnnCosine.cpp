#include "KnnCosine.h"
#include <cmath>

class FeatureVector;
KnnCosine::KnnCosine() : Knn() {}  // Appelle le constructeur de Knn

int KnnCosine::predictSingle(const Sample& s) const {
    return getKnn(s);
}

double KnnCosine::similarity(const Sample& s1, const Sample& s2) const {
    // Récupération des vecteurs de caractéristiques
    // Note: Il faudra s'assurer que FeatureVector::norme() est bien 'const' (voir note plus bas)

    double dot_product = s1.features() * s2.features(); // Utilise votre operator*

    // On calcule les normes manuellement ou via la méthode si elle est const
    // Pour être sûr que ça compile avec votre code actuel, je recalcule ici :
    double norm1 = 0;
    for(int i=0; i<s1.features().size(); ++i) norm1 += s1[i]*s1[i];
    norm1 = std::sqrt(norm1);

    double norm2 = 0;
    for(int i=0; i<s2.features().size(); ++i) norm2 += s2[i]*s2[i];
    norm2 = std::sqrt(norm2);

    if (norm1 == 0 || norm2 == 0) return 1.0; // Évite division par 0

    double cosine = dot_product / (norm1 * norm2);

    // On retourne la "Distance Cosinus" pour que le tri fonctionne
    // (0 = vecteurs identiques, 1 = vecteurs orthogonaux)
    return 1.0 - cosine;
}