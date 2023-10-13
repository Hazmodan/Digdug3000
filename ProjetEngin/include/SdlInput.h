
#include "IInput.h"

namespace ProjetEngin {
	class SdlInput final : public IInput
	{
	public:
		virtual ~SdlInput() = default;
		virtual void Update() override;
		virtual bool IsKeyDown(int key) override;
		virtual bool IsButtonDown(int button) override;
		virtual void GetMousePosition(int* x, int* y) override;

	private:

		const unsigned char* m_keyStates;
	};

}