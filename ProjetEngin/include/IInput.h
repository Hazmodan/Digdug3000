#pragma once




namespace ProjetEngin {
	class IInput {
	public:
		~IInput() = default;
		virtual bool IsKeyDown(int key) = 0;
		virtual bool IsButtonDown(int button) = 0;
		virtual void GetMousePosition(int* x, int* y) = 0;

	protected: 
		bool m_IsRunning = false;
		friend class Engine;
		virtual void Update() = 0;
	};
}