#pragma once
#include "IScene.h"

class TitleScene : public IScene
{
	/// <summary>
	/// Loads the title scene
	/// </summary>
	/// <param name="scene"></param>
	void TitleScene::Load(const std::string& scene)
	{
		if (m_Scenes.count(scene) > 0)
		{
			m_Scenes[scene]->Load();
		}
	}

	/// <summary>
	/// Registers the title scene
	/// </summary>
	/// <param name="name"></param>
	/// <param name="scene"></param>
	void TitleScene::Register(const std::string& name, IScene* scene) 
	{
		if (m_Scenes.count(name) == 0)
		{
			m_Scenes[name] = scene;
		}
	}




};

