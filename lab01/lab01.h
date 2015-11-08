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

namespace lab02
{
	typedef int elem;
	typedef vector<elem> cont;
	typedef cont::const_iterator it;

	void Input(cont& c, int N, elem mn, elem mx);
	elem Process(const cont& c, elem M);

	extern elem Result;
	void PrintResults(HDC wdc, HWND wnd);

}; // namespace lab02


