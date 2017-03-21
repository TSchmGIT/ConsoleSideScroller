#pragma once
#include <memory>
#include "Tile.h"
#include <time.h>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;

/// <summary>
/// Class that stores the <see cref="Tile"/>s and that draws inside the console
/// </summary>
class Canvas
{
public:
    const int DRAW_WIDTH = 70;

    Canvas( size_t width, size_t height );
    ~Canvas();

#pragma region Logic

    /// <summary>
    /// Executes a tick for the canvas
    /// </summary>
    void Update( float p_deltaTime );

    /// <summary>
    /// Returns the tile at the given location TODO Argument error checking
    /// </summary>
    inline Tile* GetTile( size_t x, size_t y ) const { return &m_tiles[ x + y * m_width ]; };
#pragma endregion


#pragma region Visuals
    /// <summary>
    /// Draws the canvas inside the console
    /// </summary>
    void Draw() const;
#pragma endregion

private:
#pragma region Methods
    void Fill();
#pragma endregion

#pragma region Fields
    /// <summary>
    /// The array that stores the tiles
    /// </summary>
    std::unique_ptr<Tile[]> m_tiles;

    /// <summary>
    /// The amount of tiles in x-direction
    /// </summary>
    size_t m_width;
    /// <summary>
    /// The amount of tiles in y-direction
    /// </summary>
    size_t m_height;

    /// <summary>
    /// The current index of the canvas
    /// </summary>
    float m_currentIndex;

    /// <summary>
    /// The speed at which the board flows sideways
    /// </summary>
    float m_tickSpeed;
#pragma endregion
};

