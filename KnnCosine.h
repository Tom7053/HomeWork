#ifndef KNNCOSINE_H
#define KNNCOSINE_H

#include "Knn.h"

// Hérite publiquement de Knn
class KnnCosine : public Knn {
public:
    // Constructeur : on passe juste le k au constructeur père
    KnnCosine(int k);

    // Destructeur (bonne pratique)
    virtual ~KnnCosine() {}

    // On implémente enfin la méthode virtuelle pure
    double similarity(const Sample& s1, const Sample& s2) const override;
};

#endif // KNNCOSINE_H//
// Created by tomma on 07/01/2026.
//

#ifndef KNNCOSINE_H
#define KNNCOSINE_H

#include "Knn.h"


class Sample;

class KnnCosine : public Knn {
protected:
    // Redéfinition de la méthode similarity qui est dans la class Knn
    virtual double similarity(const Sample& s1, const Sample& s2) const override;



    // Redéfinition de predictSingle qui est aussi dans la class Knn
    virtual int predictSingle(const Sample& s) const override;

public:
    // Constructeur
    KnnCosine();
};



#endif //KNNCOSINE_H
