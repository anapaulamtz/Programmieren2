#include "DoubleMissile.h"


namespace GameObjects {

    DoubleMissile::DoubleMissile(Sea::Coordinates const & coordinates)
    : Missile(coordinates), secondaryMissile(coordinates)
    {}

    DoubleMissile::DoubleMissile(DoubleMissile const & missile)
    : Missile(missile), secondaryMissile(missile.secondaryMissile)
    {}

    std::string DoubleMissile::getName()
    {
        return "Doppelrakete";
    }

    bool DoubleMissile::checkHit(Sea::Coordinates const & coordinates)
    {
        bool primaryHit = Missile::checkHit(coordinates);
        bool secondaryHit = secondaryMissile.checkHit(coordinates);
        return primaryHit || secondaryHit;
    }

    bool DoubleMissile::hasHitSomething() const
    {
        return Missile::hasHitSomething() || secondaryMissile.hasHitSomething();
    }

    void DoubleMissile::output(OutputGrid & grid) const
    {
        Missile::output(grid);
        secondaryMissile.output(grid);
    }

}
