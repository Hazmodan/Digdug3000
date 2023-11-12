#include "Entity.h"


void Entity::Start()
{
}

/// <summary>
/// Draws the entity if the entity has a IDrawable component
/// </summary>
/// <param name=""></param>
void Entity::Draw(void) 
{
	for (auto c : m_Components)
	{
		//c.second.;
	}
}

/// <summary>
/// Updates the entity if the entity has an IUpdatable component
/// </summary>
/// <param name="dt"></param>
void Entity::Update(float dt) 
{
	for (auto c : m_Components)
	{
		
	}
}

/// <summary>
/// Destroy the entity
/// </summary>
void Entity::Destroy()
{
}
