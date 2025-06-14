#ifndef COMPOSITE_BESTIOLE_FACTORY_H
#define COMPOSITE_BESTIOLE_FACTORY_H

#include <memory>
#include "Bestiole.h"
#include "BestioleFactory.h"
#include "BestioleDecoratorFactory.h"
#include "config.h"

class CompositeBestioleFactory {
private:
    BehaviorBasedFactory behaviorFactory;
    BestioleConfig config;

public:
    CompositeBestioleFactory(const BestioleConfig& config);

    std::unique_ptr<Bestiole> createBestiole(BestioleBehaviorType type);
};

#endif // COMPOSITE_BESTIOLE_FACTORY_H
