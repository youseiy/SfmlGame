#include "Actor.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include "EngineStatics.h"

void Actor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

void Actor::tick(const float deltaTime)
{
	
}
