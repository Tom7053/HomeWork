#ifndef KNN_H
#define KNN_H
#include "Data.h"

class Knn {
protected:
    int _k;
    Data _lazy_train;  // Données d'entraînement

    // 1. Virtuelle Pure : Knn ne sait pas calculer la sim, c'est le boulot des enfants
    virtual double similarity(const Sample& s1, const Sample& s2) const = 0;

public:
    // On force l'utilisateur à donner k dès le début
    Knn(int k);
    virtual ~Knn() {} // Destructeur virtuel important pour l'héritage

    // 2. Méthode pour charger les données (indispensable)
    void train(const Data& data);

    // Prédit l'étiquette pour un seul exemple (contient la logique de vote)
    int predict(const Sample& s) const;
};

#endif // KNN_H