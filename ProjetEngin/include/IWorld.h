#pragma once
#include <vector>
#include <map>
#include "Entity.h"
#include "IScene.h"

class IWorld
{
public:
	virtual void Unload() = 0;
	virtual void Load(const std::string& scene) = 0;
	virtual void Register(const std::string& name, IScene* scene ) = 0;
	virtual void Remove(Entity* entity) = 0;
	virtual Entity* Find(const std::string& name) = 0;
	virtual Entity* Create(std::string EntityID) = 0;



private:
	


};