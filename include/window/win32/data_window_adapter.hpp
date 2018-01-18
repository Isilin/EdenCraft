#ifndef DATA_WINDOW_ADAPTER_HPP
#define DATA_WINDOW_ADAPTER_HPP

#include <Windows.h>

#include "window/window_event/keyboard.hpp"

namespace ece
{
	struct DataWindowAdapter
	{
		inline DataWindowAdapter(HWND windowId) : _windowId(windowId) {}

		HWND _windowId;
	};

	struct WindowMessage
	{
		HWND _windowId;
		UINT _message;
		WPARAM _wParam;
		LPARAM _lParam;
	};

	static constexpr LPCWSTR className = L"ECE Window";

	void registerPattern();
	LRESULT CALLBACK processMessages(HWND windowId, UINT message, WPARAM wParam, LPARAM lParam);
	Keyboard::Key interpretKey(WPARAM wParam);
}

#endif // DATA_WINDOW_ADAPTER_HPP

