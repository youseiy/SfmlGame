#include <SFML/Graphics.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animation Example");
    window.setFramerateLimit(60);

    // Load the texture (whole sprite sheet)
    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/Yousei/Documents/Git/SfmlGame/resource/Sprites/Soldier/Idle.png"))
    {
        return -1; // Error handling, texture not loaded
    }

    // Create the sprite and set the texture
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Frame details (assuming all frames are 128x128)
    const int frameWidth = 128;
    const int frameHeight = 128;
    const int numFrames = 6;  // Number of frames in the animation

    // Set an initial position for the sprite
    sprite.setPosition(100.f, 100.f);

    // Define movement speed
    float movementSpeed = 200.f; // Pixels per second

    // Animation variables
    int currentFrame = 0;    // Current frame index
    float animationSpeed = 0.1f; // Time between frames (in seconds)
    float frameTime = 0.f;   // Time accumulator for frame switching

    // Main loop
    sf::Clock clock;  // Clock to manage frame time
    while (window.isOpen())
    {
        // Calculate delta time (time between frames)
        sf::Time deltaTime = clock.restart();
        float deltaSeconds = deltaTime.asSeconds();

        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move sprite based on key presses
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.move(-movementSpeed * deltaSeconds, 0.f); // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(movementSpeed * deltaSeconds, 0.f);  // Move right
        }

        // Update animation frame
        frameTime += deltaSeconds;
        if (frameTime >= animationSpeed)
        {
            // Move to the next frame in the sprite sheet
            currentFrame = (currentFrame + 1) % numFrames; // Loop through frames

            // Set the texture rectangle to the current frame
            sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));

            // Reset the frame timer
            frameTime = 0.f;
        }

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the new frame
        window.display();
    }

    return 0;
}
