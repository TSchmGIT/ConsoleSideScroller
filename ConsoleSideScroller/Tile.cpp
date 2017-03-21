#include "stdafx.h"
#include "Tile.h"
#include <stdlib.h>

Tile::Tile() {}

Tile::Tile( TileType p_tileType )
{
    m_tileType = p_tileType;
}

Tile::~Tile() {}

char Tile::GetChar() const
{
    switch ( m_tileType )
    {
        case Free:
            return ' ';
        case Wall:
            return 'o';
        case Ground1:
            return '/';
        case Ground2:
            return '\\';
        case GroundTopLevel:
            return char( 240 ); // ≡
        default:
            break;
    }
    return 0;
}
