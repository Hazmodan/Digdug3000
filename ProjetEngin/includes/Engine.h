#pragma once

#include <iostream>

namespace ProjetEngin {
	class Engine final {
	public:
		bool Init(const std::string& title, int w, int h);
		void Start();

	private:
		void ProcessInput();
		void Update();
		void Render();
		void Shutdown();

	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;

	};

}