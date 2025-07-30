#include "Object.h"


namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }
    // TODO Aufgabe 2:
    //  Nutzt die Funktionalität von `Coordinates`, um zu bestimmen, ob ein Teil dieses Objekts auf den übergebenen Koordinaten (`coordinates`) liegt.
    bool Object::atCoordinates(Coordinates const & coordinates) const
    {
        bool isAtCoordinate = false;
        switch(orientation){
            case Orientation::X:
                for(int currentX = getX(); currentX < this->getX() +  this->size; ++currentX) {
                    Coordinates currentCoordinate(currentX, this->getY());
                    isAtCoordinate = currentCoordinate.samePositionAs(coordinates);
                    if(isAtCoordinate){
                        break;
                    }
                }
                break;
            case Orientation::Y:
                for(int currentY = this->getY(); currentY < this->getY() + this->size; ++currentY) {
                    Coordinates currentCoordinate(this->getX(), currentY);
                    isAtCoordinate = currentCoordinate.samePositionAs(coordinates);
                    if(isAtCoordinate){
                        break;
                    }
                }
                break;
        }
        return isAtCoordinate;
    }
    // TODO Aufgabe 2:
    //  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
    bool Object::intersectsWith(Object const & otherObject) const
    {
        bool isIntersectsWith = false;
        switch(this->orientation){
            case Orientation::X:
                for(int currentX = this->getX(); currentX < this->size + this->getX(); ++currentX) {
                    Coordinates currentCoordinate(currentX, this->getY());
                    isIntersectsWith = otherObject.atCoordinates(currentCoordinate);
                    if(isIntersectsWith){
                        break;
                    }
                }
                break;
            case Orientation::Y:
                for(int currentY = this->getY(); currentY < this->size + this->getY(); ++currentY) {
                    Coordinates currentCoordinate(this->getX(), currentY);
                    isIntersectsWith = otherObject.atCoordinates(currentCoordinate);
                    if(isIntersectsWith){
                        break;
                    }
                }
                break;
        }
        return isIntersectsWith;
    }

}
