#pragma once
#include <string>
#include <map>

class IScene {
public:
	virtual ~IScene() = default;
	virtual void Load() = 0;

protected:
	std::map<std::string, IScene*> m_Scenes;

};