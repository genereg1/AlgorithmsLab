#pragma once
#pragma warning ( disable:4100 )

namespace main
{
	extern HWND hWnd;
	extern bool boActive;

	ATOM RegisterClass(HINSTANCE hInstance);
	bool InitInstance(HINSTANCE, int);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	void Paint(HWND);

}; // namespace main

