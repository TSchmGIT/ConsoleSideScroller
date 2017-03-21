#pragma once
#include "Enums.h"

class Tile
{
public:
    Tile();
    Tile( TileType p_tileType );
    ~Tile();

    char GetChar() const;
    TileType m_tileType;
private:
};

