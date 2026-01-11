#ifndef KNN_H
#define KNN_H
#include "Data.h"



class Knn {
private:
    int _k;
protected:
    Data _lazy_train;  // Données d'entraînement
    
    // Obtenir les k plus proches voisins
    int getKnn(const Sample& s) const;

    int predictSingle(const Sample& s) const;

    double similarity(const Sample& s1, const Sample& s2) const; // distance point à point entre 2 samples --> + distance faible == Samples identiques

public:
    // Constructeur
    Knn();

    int predict(const Sample& s) const;
};

#endif // KNN_H