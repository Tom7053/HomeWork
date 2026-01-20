#include <iostream>
#include <string>
#include <vector>
#include "Data.h"
#include "KnnCosine.h"

int main(int argc, char* argv[]) {
    // 1. Vérification des arguments de la ligne de commande
    // On attend : ./main <fichier_train> <fichier_test> <k>
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <train_file> <test_file> <k>" << std::endl;
        return 1;
    }

    std::string trainFilename = argv[1];
    std::string testFilename = argv[2];
    int k = std::stoi(argv[3]); // Conversion de l'argument k en entier

    std::cout << "=== Lancement du k-NN (k=" << k << ") ===" << std::endl;

    // 2. Chargement des données d'apprentissage
    std::cout << "Chargement des donnees d'apprentissage : " << trainFilename << "..." << std::endl;
    Data trainData;
    trainData.load(trainFilename);
    std::cout << " -> " << trainData.nbSamples() << " exemples charges." << std::endl;

    // 3. Chargement des données de test
    std::cout << "Chargement des donnees de test : " << testFilename << "..." << std::endl;
    Data testData;
    testData.load(testFilename);
    std::cout << " -> " << testData.nbSamples() << " exemples a classer." << std::endl;

    // 4. Initialisation et entrainement de l'algorithme
    // On instancie KnnCosine (concret) mais on pourrait utiliser un pointeur Knn* (abstrait)
    KnnCosine knn(k);

    // "Lazy train" : on stocke juste les données en mémoire
    knn.train(trainData);

    // 5. Boucle de prédiction et calcul de précision
    int nb_correct = 0;
    int nb_total = testData.nbSamples();

    std::cout << "Debut de la classification..." << std::endl;

    for (int i = 0; i < nb_total; ++i) {
        // Récupération de l'exemple à tester
        const Sample& currentSample = testData[i];

        // Prédiction de l'étiquette
        int predictedTag = knn.predict(currentSample);
        int actualTag = currentSample.tag();

        // Comparaison
        if (predictedTag == actualTag) {
            nb_correct++;
        }

        // Optionnel : Affichage de progression tous les 100 exemples
        if ((i + 1) % 100 == 0) {
            std::cout << "Traitement : " << (i + 1) << "/" << nb_total << std::endl;
        }
    }

    // 6. Affichage des résultats finaux
    double accuracy = (double)nb_correct / nb_total * 100.0;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "Resultats pour k = " << k << std::endl;
    std::cout << "Nombre d'erreurs : " << (nb_total - nb_correct) << std::endl;
    std::cout << "Precision (Accuracy) : " << accuracy << "%" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    return 0;
}