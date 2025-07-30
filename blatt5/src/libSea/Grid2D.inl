
// Siehe Hinweis in 'game.inl'

#include <exception>
#include "Grid2D.h"


// TODO Aufgabe 3:
//  Implementiert den Konstruktor von Grid2D.
//  Stellt mithilfe von Exceptions sicher, dass kein Grid2D mit einer ungültigen Größe (< 1x1) erstellt werden kann.
//  Tipp: Zur Initialisierung stellt `std::vector` einen entsprechenden Konstruktor zur Verfügung: `std::vector<ElementTyp>(Anzahl, initElement)`
//        Dieser wurde auch schon für `gridOwnSea` in 'PlayerSea.h' verwendet.
class InvalidGrid : public std::exception{};

template<class T>
Sea::Grid2D<T>::Grid2D(unsigned int const sizeX,unsigned int const sizeY, T const & initElement)
:grid(sizeY, std::vector<T>(sizeX, initElement))
{
    if(sizeX < 1 || sizeY < 1){
        throw InvalidGrid();
    }
};

// TODO Aufgabe 3:
//  Implementiert `sizeX()` und `sizeY()`.
//  Erinnerung: die Größe in X-Richtung entspricht dabei der Anzahl der Elemente (vom Typ `T`) in den "inneren" Vektoren.
//                           Y-Richtung ist die Größe des "außeren" Vektors `grid`.
template <class T>
unsigned int const Sea::Grid2D<T>::sizeX() const {
    return grid[0].size();
}

template <class T>
unsigned int const Sea::Grid2D<T>::sizeY() const {
    return grid.size();
};
// TODO Aufgabe 3:
//  Implementiert die 4 Operator-Überladungen.
//  Stellt sicher, dass Exceptions geworfen werden, wenn ungültige Koordinaten übergeben wurden.
template <class T>
T const & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coordinates) const {
    if(coordinates.getX() > this->sizeX() -1 || coordinates.getY() > this->sizeY() - 1){
        throw InvalidGrid();
    }
    return grid.at(coordinates.getX()).at(coordinates.getY())
};

template <class T>
T & Sea::Grid2D<T>::operator[](Sea::Coordinates const & coordinates) {
    if(coordinates.getX() > this->sizeX() -1 || coordinates.getY() > this->sizeY() - 1){
        throw InvalidGrid();
    }
    return grid.at(coordinates.getX()).at(coordinates.getY());
};

template <class T>
T const & Sea::Grid2D<T>::operator()(unsigned int const x, unsigned int const y) const {
    if(x > this->sizeX() -1 || y > this->sizeY() - 1){
        throw InvalidGrid();
    }
    return grid.at(x).at(y);
};

template <class T>
T & Sea::Grid2D<T>::operator()(unsigned int const x, unsigned int const y) {
    if(x > this->sizeX() -1 || y > this->sizeY() - 1){
        throw InvalidGrid();
    }
    return grid.at(x).at(y);
    // return grid[][]
};



