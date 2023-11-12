#pragma once
#include <iostream>
#include "Component.h"
#include <vector>
#include <map>

class Entity
{
public:
	Entity(const std::string& name) : m_Name(name) {}
	virtual ~Entity() = default;

	virtual void Start();
	void Destroy();
	void Draw(void);
	void Update(float dt);

	std::string& GetName() { return m_Name; }

	template<typename T>
	T* AddComponent()
	{
		T* cmp = new T(this);

		const type_info* type = &typeid(*cmp);
		m_Components.emplace_back(type, cmp);

		IUpdatable* _updatable = dynamic_cast<IUpdatable*>(cmp);
		if (_updatable != nullptr)
		{
			m_Updatable.push_back(_updatable);
		}

		IDrawable* _drawable = dynamic_cast<IDrawable*>(cmp);
		if (_drawable != nullptr)
		{
			m_Drawable.push_back(_drawable);
		}


		//check if the cmp is drawable
		//--Add to mDrawable
		//check if the cmp is updatable
		//--Add to mUpdatable


	}


private:
	std::string m_Name;
	std::map<const type_info*, Component*> m_Components;
	std::vector<IDrawable*> m_Drawable;
	std::vector<IUpdatable*> m_Updatable;

};