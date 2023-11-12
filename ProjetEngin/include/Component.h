#pragma once

class Entity;
class IUpdatable
{
public:
	virtual void Update(float dt) = 0;
};

class IDrawable
{
public:
	virtual void Draw() = 0;
};

/// <summary>
/// Components, to be added to entities
/// </summary>
class Component
{
public:
	virtual ~Component() = default;

	Component();
	Component(Entity* parent);

	virtual void Start() {}
	virtual void Destroy() {}

protected: 
	Entity* m_Entity = nullptr;

};