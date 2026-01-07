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

public:
    // Constructeur
    Knn();
};

#endif // KNN_H