#ifndef BESTIOLE_DECORATOR_FACTORY_H
#define BESTIOLE_DECORATOR_FACTORY_H

#include <memory>
#include "Bestiole.h"
#include "config.h"

// Décorateurs
#include "EyesDecorator.h"
#include "EarsDecorator.h"
#include "Nageoires.h"
#include "Carapace.h"
#include "Camouflage.h"

class BestioleDecoratorFactory {
public:
    static std::unique_ptr<Bestiole> decorate(std::unique_ptr<Bestiole> base, const BestioleConfig& config);
};

#endif // BESTIOLE_DECORATOR_FACTORY_H
