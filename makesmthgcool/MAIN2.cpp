#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main()
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Quadrat Blanc");
    sf::RectangleShape rectangle(sf::Vector2f(120, 50)); sf::Color::White;

    // Disable vertical synchronization to get maximum framerate
    App.UseVerticalSync(false);

    // Create a clock for measuring time
    sf::Clock Clock;

    // Some dummy variables to simulate an object that moves
    const float Speed = 0.05f;
    float Left = 0.f;
    float Top  = 0.f;

    // Start main loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();

            // Escape key : exit
            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
        }

        // Get elapsed time since last frame (we could as well use App.GetFrameTime())
        float ElapsedTime = Clock.GetElapsedTime();
        float Velo = 0.0f;

        // Make our virtual object move
        Left -= Speed * ElapsedTime;
        Velo = Left;

        Clock.Reset();

        App.Clear();
        App.Draw( Rectangle );

        // Display window on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
