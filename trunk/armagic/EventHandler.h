#ifndef ARMAGIC_EVENT_HANDLER_H_
#define ARMAGIC_EVENT_HANDLER_H_

#include <irrlicht.h>

using namespace irr;

class EventHandler : public IEventReceiver {
public:
	EventHandler() {
		for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}
	
	virtual bool OnEvent(const SEvent& event) {
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		else if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
			switch (event.MouseInput.Event) {
			case EMIE_LMOUSE_PRESSED_DOWN:
				MouseState.LeftButtonDown = true;
				break;
			case EMIE_LMOUSE_LEFT_UP:
				MouseState.LeftButtonDown = false;
				break;
			case EMIE_MOUSE_MOVED:
				MouseState.Position.X = event.MouseInput.X;
				MouseState.Position.Y = event.MouseInput.Y;
				break;

			default:
				// We won't use the wheel
				break;
			}
		}

		return false;
	}
	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const {
		return KeyIsDown[keyCode];
	}

	virtual bool IsMouseClicked() {
		bool ret = MouseState.LeftButtonDown;
		MouseState.LeftButtonDown = false;
		return ret;
	}

	core::position2di getMousePosition() const {
		return MouseState.Position;
	}

private:
	struct SMouseState {
		core::position2di Position;
		bool LeftButtonDown;
		SMouseState() :
		LeftButtonDown(false) {
		}
	} MouseState;

	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif