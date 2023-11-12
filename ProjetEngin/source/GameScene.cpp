#pragma once
#include "IScene.h"

class GameScene : public IScene
{
	/// <summary>
	/// Loads a gamescene
	/// </summary>
	/// <param name="scene"></param>
	void GameScene::Load(const std::string& scene)
	{
		if (m_Scenes.count(scene) > 0)
		{
			m_Scenes[scene]->Load();
		}
	}

	/// <summary>
	/// Registers the named scene
	/// </summary>
	/// <param name="name"></param>
	/// <param name="scene"></param>
	void GameScene::Register(const std::string& name, IScene* scene)
	{
		if (m_Scenes.count(name) == 0)
		{
			m_Scenes[name] = scene;
		}
	}
};