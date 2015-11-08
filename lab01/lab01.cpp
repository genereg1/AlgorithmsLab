#include "stdafx.h"
#include "lab01.h"
//git add
namespace main
{

	HINSTANCE hInst;
	bool boActive = false;
	HWND hWnd = 0;


	const TCHAR* szClass = L"IMOI Lab Class";
	const TCHAR* szTitle = L"Методы обработки информации. Лабораторная работа.";

	ATOM RegisterClass(HINSTANCE hInstance)
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = main::WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = 0;
		wcex.hCursor = LoadCursor(0, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = 0;
		wcex.lpszClassName = szClass;
		wcex.hIconSm = 0;

		return RegisterClassEx(&wcex);
	}

	bool InitInstance(HINSTANCE hInstance, int nCmdShow)
	{

		hInst = hInstance;

		DWORD wid = GetSystemMetrics(SM_CXSCREEN), hei = GetSystemMetrics(SM_CYSCREEN);

		hWnd = CreateWindow(szClass, szTitle, WS_CAPTION | WS_VISIBLE | WS_SYSMENU | WS_POPUP,
			0, 0, wid, hei, 0, 0, hInstance, 0);

		ShowWindow(hWnd, nCmdShow);
		UpdateWindow(hWnd);

		return true;
	}

	//функция обработки сообщений
	LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
	{

		switch (Message)
		{
		case WM_ACTIVATEAPP:
		{
			boActive = wParam == 1;
			break;
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			BeginPaint(hWnd, &ps);
			Paint(hWnd);
			EndPaint(hWnd, &ps);
			break;
		}
		default:
			return DefWindowProc(hWnd, Message, wParam, lParam);
		}
		return 0;
	}

	void Paint(HWND hwnd)
	{
	}

};// namespace main

//цикл обработки сообщений
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine,
	int nCmdShow)
{
	main::RegisterClass(hInstance);
	if (!main::InitInstance(hInstance, nCmdShow))
		return -1;

	MSG  msg;
	do
	{
		if (!PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			continue;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	} while (WM_QUIT != msg.message);

	return (int)msg.wParam;
}
