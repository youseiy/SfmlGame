#include "Actor.h"

Actor::Actor(const char* name, sf::Texture texture)
	:m_name(name),m_texture(texture),m_sprite(m_texture)
{
}

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
