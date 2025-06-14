#include "Aquarium.h"
#include "Milieu.h"
#include "CompositeBestioleFactory.h"
#include "config.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // 1. Créer l’aquarium (affichage + simulation)
    Aquarium ecosysteme(640, 480, 30);

    // 2. Initialiser le générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(NULL)));

    // 3. Créer la configuration d'une bestiole
    BestioleConfig config;
    config.has_eyes = true;
    config.eyes_field_of_view = 1.047;
    config.eyes_delta_min = 10;
    config.eyes_delta_max = 50;
    config.eyes_detection_capacity = 0.8;

    config.has_ears = true;
    config.ears_range = 40;
    config.ears_detection_capacity = 0.7;

    config.has_carapace = true;
    config.carapace_resistance_multiplier = 1.2;
    config.carapace_slowdown_factor = 2.0;

    config.has_camouflage = true;
    config.camouflage_factor = 0.9;

    config.has_nageoires = true;
    config.nageoires_speed_multiplier = 1.5;

    // 4. Créer une factory composite avec cette config
    CompositeBestioleFactory factory(config);

    // 5. Ajouter des bestioles à l’écosystème
    int numBestioles = 50;
    for (int i = 0; i < numBestioles; i++) {
        // Exemple avec comportement aléatoire
        BestioleBehaviorType behavior;
        int random = rand() % 3;
        switch (random) {
            case 0: behavior = BestioleBehaviorType::KAMIKAZE; break;
            case 1: behavior = BestioleBehaviorType::PEUREUSE; break;
            case 2: behavior = BestioleBehaviorType::GREGAIRE; break;
        }

        auto b = factory.createBestiole(behavior);
        b->initCoords(640, 480);
        ecosysteme.getMilieu().addMember(std::move(b));
    }

    // 6. Lancer la simulation
    ecosysteme.run();

    return 0;
}
