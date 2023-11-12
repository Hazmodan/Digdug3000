#include "WorldService.h"
#pragma once 

/// <summary>
/// Unloads/clears the current world service
/// </summary>
void WorldService::Unload()
{
	if (m_CurrentScene != nullptr)
	{
		for (auto entity : m_EntityInWorld)
		{
			entity->Destroy();
			delete entity;
		}
		m_EntityInWorld.clear();
		m_EntityMap.clear();
	}
}

/// <summary>
/// Loads the world named in the parameters
/// </summary>
/// <param name="scene"></param>
void WorldService::Load(const std::string& scene)
{
	if (m_Scenes.count(scene) > 0)
	{
		Unload();
		m_CurrentScene = m_Scenes[scene];
		m_CurrentScene->Load();
	}
}

/// <summary>
/// registers the world named in the params
/// </summary>
/// <param name="name"></param>
/// <param name="scene"></param>
void WorldService::Register(const std::string& name, IScene* scene)
{

}

/// <summary>
/// removes the world named in the params
/// </summary>
/// <param name="entity"></param>
void WorldService::Remove(Entity* entity)
{
	for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it) 
	{
		if (entity == *it)
		{
			m_EntityInWorld.erase(it--);
			break;
		}
	}
}

/// <summary>
/// Finds the world named in the params
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
Entity* WorldService::Find(const std::string& name)
{
	if (m_EntityMap.count(name) > 0)
		return m_EntityMap[name];

	return nullptr;
}

/// <summary>
/// creates the world with the id from the params
/// </summary>
/// <param name="EntityID"></param>
/// <returns></returns>
Entity* WorldService::Create(std::string EntityID)
{
	Entity* entity = new Entity(EntityID);
	m_EntityInWorld.emplace_back(entity);
	m_EntityMap.emplace(entity->GetName(), entity);
	return entity;
}
