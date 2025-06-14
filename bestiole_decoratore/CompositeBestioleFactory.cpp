#include "CompositeBestioleFactory.h"

CompositeBestioleFactory::CompositeBestioleFactory(const BestioleConfig& config)
    : config(config)
{ }

std::unique_ptr<Bestiole> CompositeBestioleFactory::createBestiole(BestioleBehaviorType type) {
    // 1. Créer la bestiole avec un comportement
    std::unique_ptr<Bestiole> base = behaviorFactory.createBestiole(type);

    // 2. Appliquer les décorateurs en fonction de la configuration
    std::unique_ptr<Bestiole> full = BestioleDecoratorFactory::decorate(std::move(base), config);

    return full;
}
