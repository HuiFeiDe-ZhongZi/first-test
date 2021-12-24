//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include <time.h>
//#include <stdbool.h>
//
//#define HANG  23    //������
//#define LIE   31    //������
//#define LEFT  9     //��Ϸ����߽�
//#define RIGHT 21    //��Ϸ���ұ߽�
//
//char g_back[HANG][LIE];  //��������
//
////��������
//char g_cPlaySqure = 0;  //��Ϸ������
//char g_cNextSqure = 0;  //next������
//char g_cHang = 0;       //���������
//char g_cLie = 0;        //����������
//char g_cState = 0;      //������״
//int g_iScore = 0;
//
////�������
//void GotoXY(short hang, short lie);
//void Head(void);
//void Frame(void);
//void LeftInfo(void);
//void RightInfo(void);
//void Init(void);
//
////��ʼ����
//void StartSqure(void);
//void NewSqure(void);
//void InitState(void);
//void DrawNextSqure(void);
//void Draw(char* pic); //"��" "��" "  "
//
////�����˶�
//void Down(void);
//void Left(void);
//void Right(void);
//void Change(void);
//
////��������
//void KeyState(void);
//
////��������
//bool CanMove(char state, char hang, char lie);
//void StopSqure(void);
//bool CanChange(char state);
//
////�÷�
//void GetRange(char* low, char* high);
//void Score(void);
//bool Full(char hang);
//void Disppear(char hang);
//void Fall(char hang);
//void DrawSocre(void);
//
////���ܿ���
//unsigned int g_time = 0;  //����ʱ���
//bool g_pause = true;      //������ͣ
//bool Die(void);
//int g_speed = 50;
//bool g_Quit = true;
//
//int main(void)
//{
//	Init();
//	while (1)
//	{
//		Sleep(10);
//		g_time++;
//        KeyState();
//
//		if (false == g_Quit)
//			break;
//
//		if (true == g_pause)
//		{
//			if (g_time % g_speed == 0)
//				Down();
//		}
//	}
//	system("pause>0");
//	return 0;
//}
//
//bool Full(char hang)
//{
//	char i, sum = 0;
//	for (i = LEFT + 1; i < RIGHT; i++)
//	{
//		sum += g_back[hang][i];
//	}
//	if (11 == sum)
//		return true;
//	return false;
//}
//void Disppear(char hang)
//{
//	int h = 5, l = 30;
//	char i;
//	for (i = LEFT + 1; i < RIGHT; i++)
//	{
//		if (1 == g_back[hang][i])
//		{
//			g_back[hang][i] = 0;
//			GotoXY(hang + h, i * 2 + l);
//			printf("  ");
//			Sleep(30);
//        }
//	}
//}
//void Fall(char hang)
//{
//	int i, j;
//	int h = 5, l = 30;
//	for (i = hang; i >= 2; i--)
//	{
//		for (j = LEFT + 1; j < RIGHT; j++)
//		{
//			if (1 == g_back[i - 1][j])
//			{
//				//1.�������¸�ֵ��
//				g_back[i][j] = g_back[i - 1][j];
//				g_back[i - 1][j] = 0;
//				//2.���·��� 
//				GotoXY(i + h, j * 2 + l);
//				printf("��");
//				//3.ǰһ��λ��ȥ������
//				GotoXY(i - 1 + h, j * 2 + l);
//				printf("  ");
//			}
//		}
//	}
//}
//void DrawSocre(void)
//{
//	g_iScore++;
//	int i = 8, j = 81;
//	GotoXY(i, j);
//	printf("%d", g_iScore*100);
//}
//void Score(void)
//{
//	//��ȡ�������з�Χ
//	char low = 0, high = 0;
//	GetRange(&low, &high);
//	char i;
//	for (i = low; i <= high; i++)
//	{
//		//�ж���������
//		if (true == Full(i))
//		{
//			//���У�gback����
//			Disppear(i);
//			//���� 
//			Fall(i);
//			//��ʾ����//�÷ּ���,��ʾ����
//			DrawSocre();
//		}
//	}
//}
//void GetRange(char* low, char* high)
//{
//	switch (g_cPlaySqure)
//	{
//	case 0:
//	case 1:
//	case 4:
//		switch (g_cState)
//		{
//		case 0:
//			*low = g_cHang - 1;
//			*high = g_cHang;
//			break;
//		case 1:
//		case 3:
//			*low = g_cHang - 1;
//			*high = g_cHang + 1;
//			break;
//		case 2:
//			*low = g_cHang;
//			*high = g_cHang + 1;
//			break;
//		}
//		break;
//	case 2:
//	case 3:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			*low = g_cHang - 1;
//			*high = g_cHang;
//			break;
//		case 1:
//		case 3:
//			*low = g_cHang - 1;
//			*high = g_cHang + 1;
//			break;
//		}
//		break;
//	case 5:
//		*low = g_cHang - 1;
//		*high = g_cHang;
//		break;
//	case 6:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			*low = g_cHang;
//			*high = g_cHang;
//			break;
//		case 1:
//		case 3:
//			*low = g_cHang - 2;
//			*high = g_cHang + 1;
//			break;
//		}
//		break;
//	}
//}
//
//bool CanChange(char state)
//{
//	if (true == CanMove(state, g_cHang, g_cLie))
//		return true;
//	if (true == CanMove(state, g_cHang, g_cLie - 1))
//	{
//		Draw("  ");
//		g_cLie -= 1;
//		return true;
//	}
//	if (true == CanMove(state, g_cHang, g_cLie + 1))
//	{
//		Draw("  ");
//		g_cLie += 1;
//		return true;
//	}
//	if (true == CanMove(state, g_cHang + 1, g_cLie))
//	{
//		Draw("  ");
//		g_cHang += 1;
//		return true;
//	}
//	if (6 == g_cPlaySqure && 1 == g_cState || 3 == g_cState)
//	{
//		if (true == CanMove(state, g_cHang, g_cLie + 2))
//		{
//			Draw("  ");
//			g_cLie += 2;
//			return true;
//		}
//	}
//
//	return false;
//}
//void StopSqure(void)
//{
//	switch (g_cPlaySqure)
//	{
//	case 0:
//		switch (g_cState)
//		{
//		case 0:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang - 1][g_cLie - 1] = 1;
//			break;
//		case 1:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie + 1] = 1;
//			break;
//		case 2:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang + 1][g_cLie + 1] = 1;
//			break;
//		case 3:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie - 1] = 1;
//			break;
//		}
//		break;
//	case 1:
//		switch (g_cState)
//		{
//		case 0:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang - 1][g_cLie + 1] = 1;
//			break;
//		case 1:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie + 1] = 1;
//			break;
//		case 2:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang + 1][g_cLie - 1] = 1;
//			break;
//		case 3:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie - 1] = 1;
//			break;
//		}
//		break;
//	case 2:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie - 1] = 1;
//			break;
//		case 1:
//		case 3:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang - 1][g_cLie + 1] = 1;
//			break;
//		}
//		break;
//	case 3:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie + 1] = 1;
//			break;
//		case 1:
//		case 3:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang + 1][g_cLie + 1] = 1;
//			break;
//		}
//		break;
//	case 4:
//		switch (g_cState)
//		{
//		case 0:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			break;
//		case 1:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			break;
//		case 2:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			break;
//		case 3:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			break;
//		}
//		break;
//	case 5:
//		g_back[g_cHang][g_cLie] = 1;
//		g_back[g_cHang][g_cLie - 1] = 1;
//		g_back[g_cHang - 1][g_cLie] = 1;
//		g_back[g_cHang - 1][g_cLie - 1] = 1;
//		break;
//	case 6:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang][g_cLie - 1] = 1;
//			g_back[g_cHang][g_cLie - 2] = 1;
//			g_back[g_cHang][g_cLie + 1] = 1;
//			break;
//		case 1:
//		case 3:
//			g_back[g_cHang][g_cLie] = 1;
//			g_back[g_cHang - 1][g_cLie] = 1;
//			g_back[g_cHang - 2][g_cLie] = 1;
//			g_back[g_cHang + 1][g_cLie] = 1;
//			break;
//		}
//		break;
//	}
//}
//bool CanMove(char state, char hang, char lie)
//{
//	switch (g_cPlaySqure)
//	{
//	case 0:
//		switch (state)
//		{
//		case 0:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang - 1][lie - 1])
//				return false;
//			break;
//		case 1:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie + 1])
//				return false;
//			break;
//		case 2:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang + 1][lie + 1])
//				return false;
//			break;
//		case 3:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie - 1])
//				return false;
//			break;
//		}
//		break;
//	case 1:
//		switch (state)
//		{
//		case 0:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang - 1][lie + 1])
//				return false;
//			break;
//		case 1:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie + 1])
//				return false;
//			break;
//		case 2:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang + 1][lie - 1])
//				return false;
//			break;
//		case 3:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie - 1])
//				return false;
//			break;
//		}
//		break;
//	case 2:
//		switch (state)
//		{
//		case 0:
//		case 2:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie - 1])
//				return false;
//			break;
//		case 1:
//		case 3:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang - 1][lie + 1])
//				return false;
//			break;
//		}
//		break;
//	case 3:
//		switch (state)
//		{
//		case 0:
//		case 2:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie + 1])
//				return false;
//			break;
//		case 1:
//		case 3:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang + 1][lie + 1])
//				return false;
//			break;
//		}
//		break;
//	case 4:
//		switch (state)
//		{
//		case 0:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			break;
//		case 1:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			break;
//		case 2:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			break;
//		case 3:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			break;
//		}
//		break;
//	case 5:
//		if (1 == g_back[hang][lie])
//			return false;
//		if (1 == g_back[hang][lie - 1])
//			return false;
//		if (1 == g_back[hang - 1][lie])
//			return false;
//		if (1 == g_back[hang - 1][lie - 1])
//			return false;
//		break;
//	case 6:
//		switch (state)
//		{
//		case 0:
//		case 2:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang][lie - 1])
//				return false;
//			if (1 == g_back[hang][lie - 2])
//				return false;
//			if (1 == g_back[hang][lie + 1])
//				return false;
//			break;
//		case 1:
//		case 3:
//			if (1 == g_back[hang][lie])
//				return false;
//			if (1 == g_back[hang - 1][lie])
//				return false;
//			if (1 == g_back[hang - 2][lie])
//				return false;
//			if (1 == g_back[hang + 1][lie])
//				return false;
//			break;
//		}
//		break;
//	}
//	return true;
//}
//
//void KeyState(void)
//{
//	if (true == g_pause)
//	{
//		if (GetAsyncKeyState(VK_LEFT) & 0x01 )
//		{
//			if (true == CanMove(g_cState, g_cHang, g_cLie - 1))
//				Left();
//		}
//		if (GetAsyncKeyState(VK_RIGHT) & 0x01)
//		{
//			if (true == CanMove(g_cState, g_cHang, g_cLie + 1))
//				Right();
//		}
//		if (GetAsyncKeyState(VK_DOWN) & 0x01)
//		{
//			Down();
//		}
//		if (GetAsyncKeyState(VK_UP) & 0x01)
//		{
//			if (true == CanChange( (g_cState+1) % 4 ) )
//				Change();
//		}
//	}
//	
//	if (GetAsyncKeyState(VK_RETURN) & 0x01)
//	{
//		g_pause = !g_pause;
//	}
//	if (GetAsyncKeyState(VK_F2) & 0x01)
//	{
//		Init();
//	}
//	if (GetAsyncKeyState(VK_ESCAPE) & 0x01)
//	{
//		g_Quit = false;
//		GotoXY(12, 55);
//		printf("Game over!!!");
//		GotoXY(13, 55);
//		printf("good bye!!!");
//		GotoXY(14, 52);
//		printf("��������رմ���!!!");
//	}
//	if (GetAsyncKeyState(VK_TAB) & 0x01)
//	{
//		g_speed -= 15;
//		if (g_speed < 5)
//			g_speed = 50;
//
//		int i = 18, j = 40;
//		GotoXY(i, j);
//		printf("%4d", g_speed);
//	}
//}
//
//void Change(void)
//{
//	Draw("  ");
//	g_cState ++;
//	//g_cState %= 4;
//	if (4 == g_cState)
//		g_cState = 0;
//	Draw("��");
//}
//void Left(void)
//{
//	Draw("  ");
//	g_cLie--;
//	Draw("��");
//}
//void Right(void)
//{
//	Draw("  ");
//	g_cLie++;
//	Draw("��");
//}
//bool Die(void)
//{
//	if (1 == g_cHang || 2 == g_cHang)
//	{
//		GotoXY(12, 55);
//		printf("Game over!!!");
//		GotoXY(13, 55);
//		printf("Esc�˳���Ϸ");
//		GotoXY(14, 55);
//		printf("F1��ʼ����Ϸ");
//		return true;
//	}
//	return false;
//}
//void Down(void)
//{
//	if (true == CanMove(g_cState, g_cHang + 1, g_cLie))
//	{
//		Draw("  ");
//		g_cHang++;
//		Draw("��");
//	}
//	else
//	{
//		//���ƽ���������
//		Draw("��");
//		StopSqure();
//		//�Ƿ�÷�
//		Score();
//		if (true == Die())
//		{
//			g_pause = false;
//		}
//		//�����¿�
//		NewSqure();
//		Draw("��");
//		DrawNextSqure();
//	}
//}
//
//void Draw(char* pic)
//{
//	int hang = 5, lie = 30;
//	switch (g_cPlaySqure)
//	{
//	case 0:
//		switch (g_cState)
//		{
//		case 0:
//			GotoXY(g_cHang + hang, g_cLie*2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 1:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, g_cLie* 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 2:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 3:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			break;
//		}
//		break;
//	case 1:
//		switch (g_cState)
//		{
//		case 0:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 1:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 2:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 3:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			break;
//		}
//		break;
//	case 2:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 1:
//		case 3:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			break;
//		}
//		break;
//	case 3:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 1:
//		case 3:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		}
//		break;
//	case 4:
//		switch (g_cState)
//		{
//		case 0:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, g_cLie * 2 + lie);
//			printf(pic);
//			break;
//		case 1:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			break;
//		case 2:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, g_cLie * 2 + lie);
//			printf(pic);
//			break;
//		case 3:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			break;
//		}
//		break;
//	case 5:
//		GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//		printf(pic);
//		GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//		printf(pic);
//		GotoXY(g_cHang + hang - 1, g_cLie * 2 + lie);
//		printf(pic);
//		GotoXY(g_cHang + hang - 1, (g_cLie - 1) * 2 + lie);
//		printf(pic);
//		break;
//	case 6:
//		switch (g_cState)
//		{
//		case 0:
//		case 2:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie + 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 1) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang, (g_cLie - 2) * 2 + lie);
//			printf(pic);
//			break;
//		case 1:
//		case 3:
//			GotoXY(g_cHang + hang, g_cLie * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang + 1, (g_cLie) * 2 + lie);
//			printf(pic);
//			GotoXY(g_cHang + hang - 2, (g_cLie) * 2 + lie);
//			printf(pic);
//			break;
//		}
//		break;
//	}
//}
//void DrawNextSqure(void)
//{
//	int hang = 12, lie = 80;//"��"
//	//��ղ���
//	GotoXY(hang, lie-2);
//	printf("           ");
//	GotoXY(hang+1, lie);
//	printf("         ");
//
//	switch (g_cNextSqure)
//	{
//	case 0:
//		GotoXY(hang, lie);
//		printf("��");
//		GotoXY(hang+1, lie);
//		printf("������");
//		break;
//	case 1:
//		GotoXY(hang, lie+4);
//		printf("��");
//		GotoXY(hang + 1, lie);
//		printf("������");
//		break;
//	case 2:
//		GotoXY(hang, lie);
//		printf("����");
//		GotoXY(hang + 1, lie+2);
//		printf("����");
//		break;
//	case 3:
//		GotoXY(hang, lie+2);
//		printf("����");
//		GotoXY(hang + 1, lie);
//		printf("����");
//		break;
//	case 4:
//		GotoXY(hang, lie+2);
//		printf("��");
//		GotoXY(hang + 1, lie);
//		printf("������");
//		break;
//	case 5:
//		GotoXY(hang, lie);
//		printf("����");
//		GotoXY(hang + 1, lie);
//		printf("����");
//		break;
//	case 6:
//		GotoXY(hang, lie-2);
//		printf("��������");
//		break;
//	}
//}
//void InitState(void)
//{
//	g_cHang = 2;
//	g_cLie = LEFT+6;
//
//	if (6 == g_cPlaySqure)
//	{
//		g_cHang = 1;
//		g_cLie = LEFT + 7;
//	}
//
//	g_cState = 0;
//}
//void StartSqure(void)
//{
//	g_cPlaySqure = rand() % 7;
//	g_cNextSqure = rand() % 7;
//	InitState();
//}
//void NewSqure(void)
//{
//	g_cPlaySqure = g_cNextSqure;
//	g_cNextSqure = rand() % 7;
//	InitState();
//}
//
//void LeftInfo(void)
//{
//	int i = 5, j = 32;
//	GotoXY(i += 2, j);
//	printf("    ������ʾ\n");
//	GotoXY(i += 2, j);
//	printf(" �� �� �����ƶ�\n");
//	GotoXY(i += 2, j);
//	printf(" ��   ����\n");
//	GotoXY(i += 2, j);
//	printf(" ��   ����\n");
//	GotoXY(i += 2, j);
//	printf("Enter ����/��ͣ\n");
//	GotoXY(i += 2, j);
//	printf(" Tab  �л��ٶ�\n");
//	GotoXY(i += 1, j + 8);
//	printf("%d", g_speed);
//	GotoXY(i += 2, j);
//	printf(" Esc  �˳���Ϸ\n");
//	GotoXY(i += 2, j);
//	printf(" F2   ����Ϸ\n");
//}
//void RightInfo(void)
//{
//	int i = 5, j = 76;
//	GotoXY(i += 2, j);
//	printf("   <score>\n");
//	GotoXY(i += 1, j);
//	printf("      0\n");
//	GotoXY(i += 2, j);
//	printf("    <next>\n");
//}
//void Frame(void)
//{
//	int i, j;
//	for (i = 0; i < HANG; i++)
//	{
//		GotoXY(5 + i, 30);
//		for (j = 0; j < LIE; j++)
//		{
//			if (0 == i || HANG - 1 == i || 0 == j || LIE - 1 == j || LEFT == j || RIGHT == j)
//			{
//				g_back[i][j] = 1;
//				printf("��");
//			}
//			else
//			{
//				g_back[i][j] = 0;
//				printf("  ");
//			}
//		}
//	}
//}
//void Head(void)
//{
//	GotoXY(0, 0);
//	printf("\t\t\t\t\t\t**************************\n");
//	printf("\t\t\t\t\t\t*                        *\n");
//	printf("\t\t\t\t\t\t*       ����˹����       *\n");
//	printf("\t\t\t\t\t\t*                        *\n");
//	printf("\t\t\t\t\t\t**************************\n");
//}
//void GotoXY(short hang, short lie)
//{
//	COORD cd = { lie, hang };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
//}
//void Init(void)
//{
//	srand((unsigned int)time(NULL));
//	Head();
//	Frame();
//	LeftInfo();
//	RightInfo();
//	StartSqure();
//	DrawNextSqure();
//	Draw("��");
//	g_pause = false;
//}
//
