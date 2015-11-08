#include "stdafx.h"
#include "lab01.h"
namespace lab02
{

	//���� ������ ��������� ���
	void Input(cont& c, int N, elem mn, elem mx)
	{
		c.reserve(N);	//������ ��� vector

		srand(GetTickCount());

		for (int i = 0; i < N; ++i)
		{
			elem k = (elem)rand() * (mx - mn) / RAND_MAX;
			c.push_back(k + mn);

		}// for( int i = 0; i < N; ++i )

	}

	//������������ ��������� ������� M
	elem Process(const cont& c, elem M)
	{
		elem sum = 0;
		for (it i = c.begin(), e = c.end(); i != e; ++i)
		{
			if (*i <= M)
				continue;
			sum += *i;

		}// for( it i = c.begin(), e = c.end(); i != e; ++i )

		return sum;
	}

	elem Result = 0;

	void PrintResults(HDC wdc, HWND wnd)
	{
		wchar_t buf[128];

		int sl = wsprintf(buf, L"���������: %u", Result);

		//������ ����
		RECT rc;
		GetClientRect(wnd, &rc);

		//������ ������
		SIZE size;
		GetTextExtentPoint32(wdc, buf, sl, &size);


		//���������� ������
		int x = ((rc.right - rc.left) - size.cx) / 2;
		int y = ((rc.bottom - rc.top) - size.cy) / 2;

		TextOut(wdc, x, y, buf, sl);

	}

}; // namespace lab02

