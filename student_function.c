#include "student.h"

//���ù��λ��
void GotoXY(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x;
	cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}
//���ع��
void Hide()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cor_info = { 1,0 };
	SetConsoleCursorInfo(hout, &cor_info);
}
//���˵�
int Menu() {
	int posy = 5;
	int option;		//�����û�����Ĳ�������ı���
	int i, j;
	SetPosition(POS_X3, posy);
	printf("ѧ���ɼ�����ϵͳ\n"); //����ϵͳ����
	//���ϵͳ���ֺ͹���˵��֮������ж̺���
	for (int i =0 ;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (int j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy+=2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	SetPosition(POS_X4, posy);
	printf("");
	SetPosition(POS_X1, posy += 2);
	printf("");
	//���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
	for (int i = 0;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (int j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//��ʾ�û���Ҫִ�еĹ��ܴ���
	printf("");
	scanf("%d", &option);
	return option;
}
//����ѧ����Ϣ
void InputRecord(STU* stu,int *n,int*m) {

}

