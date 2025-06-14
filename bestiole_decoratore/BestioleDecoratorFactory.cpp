#include "BestioleDecoratorFactory.h"

std::unique_ptr<Bestiole> BestioleDecoratorFactory::decorate(std::unique_ptr<Bestiole> base, const BestioleConfig& config) {
    
    std::unique_ptr<Bestiole> decorated = std::move(base);

    // Sensorial Decorators
    if (config.has_eyes) {
        decorated = std::make_unique<EyesDecorator>(
            decorated.release(),
            config.eyes_field_of_view,
            config.eyes_delta_min,
            config.eyes_delta_max,
            config.eyes_detection_capacity
        );
    }

    if (config.has_ears) {
        decorated = std::make_unique<EarsDecorator>(
            decorated.release(),
            config.ears_range,
            config.ears_detection_capacity
        );
    }

    // Physical Decorators
    if (config.has_nageoires) {
        decorated = std::make_unique<Nageoires>(
            decorated.release(),
            config.nageoires_speed_multiplier
        );
    }

    if (config.has_carapace) {
        decorated = std::make_unique<Carapace>(
            decorated.release(),
            config.carapace_resistance_multiplier,
            config.carapace_slowdown_factor
        );
    }

    // Stealth Decorator
    if (config.has_camouflage) {
        decorated = std::make_unique<Camouflage>(
            decorated.release(),
            config.camouflage_factor
        );
    }

    return decorated;
}
