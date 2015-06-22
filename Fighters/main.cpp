
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "ResourcePath.hpp"
#include "Myplane.h"
#include "Sky.h"
#include "Game.h"
#include "Music.h"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(960, 1600), "Fighters");
    
    Music::load();
    GTexture::load();
    Level::load();
    
    Sky sky(&window);
    Myplane me(&sky);
    sky.add(&me);
    window.setFramerateLimit(60);
    Game game(&sky);
    game.start();

    
    return EXIT_SUCCESS;
}
