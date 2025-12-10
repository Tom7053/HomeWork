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
    void load(const std::string& filename);
};

#endif //DATA_H
