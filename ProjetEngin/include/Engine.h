#pragma once

#include <iostream>
#include <fstream>
#include "IInput.h"
#include "iLogger.h"

namespace ProjetEngin {
	class Engine final {
	public:
		static Engine* Get() {
			static Engine* m_Instance; {
				if (m_Instance == nullptr) m_Instance = new Engine; } }

		bool Init(const char* name, int w, int h);
		void Start();

	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();
		ILogger& Logger() { return *m_Logger; }

	private:
		IInput* m_Input = nullptr;

		bool m_IsInit = false;

		ILogger* m_Logger = nullptr;

	};

}