#pragma once

#include <iostream>
#include <IInput.h>
#include <iLogger.h>
#include <IGraphics.h>
#include <IAudio.h>
#include "Entity.h"
#include "IWorld.h"

namespace ProjetEngin {
	class Engine final 
	{
	public:
		static Engine* Get() 
		{
			static Engine* m_Instance; 
			if (m_Instance == nullptr)
			{
				m_Instance = new Engine();
			}
			return m_Instance;
		}

		bool Init(const char* name, int w, int h);
		void Start();
		void Exit();

	private:
		Engine() = default;

		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();

	public:
		IInput& Input() const { return *m_Input; }
		ILogger& Logger() const { return *m_Logger; }
		IGraphics& Graphics() const { return *m_Graphics; }
		IAudio& Audio() const { return *m_Audio; }
		IWorld& World() const { return *m_World; }

	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;

		IInput* m_Input = nullptr;
		ILogger* m_Logger = nullptr;
		IGraphics* m_Graphics = nullptr;
		IAudio* m_Audio = nullptr;
		IWorld* m_World = nullptr;
	};

}