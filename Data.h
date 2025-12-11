//
// Created by tomma on 10/12/2025.
//

#ifndef DATA_H
#define DATA_H
#include <string>
#include <vector>

#include "Sample.h"


class Data {
private:
    int _nb_features;   // Nombre de caractéristiques
    int _nb_samples;    // Nombre d'exemples
    std::vector<Sample> _data;
public:
    Data (); // Constructeur
    void load(const std::string& filename);
    int nbSamples() const;
    void add(const Sample& s);
    const Sample& operator[](int i) const; // acces à data [i] --> Sample
};

#endif //DATA_H
