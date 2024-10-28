#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Actor : public sf::Drawable, public sf::Transformable
{
public:
    Actor(const char* name, sf::Texture texture) :m_name(name), m_texture(texture), m_sprite(m_texture) 
    {
    };
    Actor() = delete;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void tick(const float deltaTime);


protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    std::string m_name;
};