#include "stdafx.h"
#include "Canvas.h"
#include <Windows.h>
#include <string>
#include <iostream>

Canvas::Canvas( size_t width, size_t height ) : m_width( width ), m_height( height )
{
    Fill();
    m_tickSpeed = 0.15f;
}

Canvas::~Canvas()
{

}

void Canvas::Update( float p_deltaTime )
{
    // Move the field sideways
    m_currentIndex = fmod( m_currentIndex + ( p_deltaTime / m_tickSpeed ), m_width );
}

void Canvas::Draw() const
{
    // Clear Screen
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

    size_t _sizeX = DRAW_WIDTH + 1;
    size_t _sizeY = m_height;

    std::string _text( _sizeX * _sizeY, ' ' );

    for ( size_t y = 0; y < _sizeY; ++y )
    {
        for ( size_t x = 0; x < _sizeX - 1; ++x )
        {
            size_t _indexX = ( x + (int)m_currentIndex + m_width ) % m_width;
            _text[ x + y * _sizeX ] = GetTile( _indexX, y )->GetChar();
        }

        _text[ _sizeX - 1 + y * _sizeX ] = '\n';
    }

    std::cout << _text;
}

void Canvas::Fill()
{
    m_tiles = std::make_unique<Tile[]>( m_width * m_height );
    for ( size_t x = 0; x < m_width; ++x )
        for ( size_t y = 0; y < m_height; ++y )
        {
            TileType _tileType;

            if ( y > m_height - 4 )
                _tileType = rand() % 10 ? Ground2 : Ground1;
            else if ( y == m_height - 4 )
                _tileType = GroundTopLevel;
            else
                _tileType = rand() % 60 ? Free : Wall;

            m_tiles[ x + y * m_width ] = Tile( _tileType );
        }
}
