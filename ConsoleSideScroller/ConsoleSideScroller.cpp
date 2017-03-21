// ConsoleSideScroller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Canvas.h"
#include <Windows.h>

const float FIXED_TIMESTEP = 1.0f / 60.0f;
const float FPS = 1.0f / 10.0f;

int main()
{
    // Seed random
    srand( time( NULL ) );

    // Hide cursor
    HANDLE consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo( consoleHandle, &info );

    Canvas _canvas( 200, 15 );

    Clock::time_point _drawClock = Clock::now();
    Clock::time_point _fixedUpdateClock = Clock::now();
    while ( true )
    {
        Clock::time_point _now = Clock::now();

        float _deltaTimeFixed = std::chrono::duration_cast<milliseconds>( _now - _fixedUpdateClock ).count() / 1000.0f;
        if ( _deltaTimeFixed >= FIXED_TIMESTEP )
        {
            _canvas.Update( _deltaTimeFixed );
            _fixedUpdateClock = _now;
        }

        float _deltaTimeDraw = std::chrono::duration_cast<milliseconds>( _now - _drawClock ).count() / 1000.0f;
        if ( _deltaTimeDraw >= FPS )
        {
            _canvas.Draw();
            _drawClock = _now;
        }
    }

    return 0;
}

