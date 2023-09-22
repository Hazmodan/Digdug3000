#pragma once

#include <iostream>
#include "IInput.h"

namespace ProjetEngin {
	class Engine final {
	public:
		bool Init(const char* name, int w, int h);
		void Start();

	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();

	private:
		IInput* m_Input = nullptr;

		bool m_IsInit = false;

	};

}