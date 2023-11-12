#pragma once
#include <vector>
#include "Entity.h"
#include "IWorld.h"
#include "IScene.h"
#include <map>

class WorldService : public IWorld
{
public:
	virtual void Unload() override;
	virtual void Load(const std::string& scene) override;
	virtual void Register(const std::string& name, IScene* scene ) override;
	virtual void Remove(Entity* entity) override;
	virtual Entity* Find(const std::string& name) override;
	virtual Entity* Create(std::string EntityID) override;



private:
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;

	IScene* m_CurrentScene = nullptr;
	std::map<std::string, IScene*> m_Scenes;

};