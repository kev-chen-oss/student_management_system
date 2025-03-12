#include "student.h"

//���ù��λ��
void SetPosition(int x, int y) {
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
	for (i =0 ;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("1. ����ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("2. ����ѧ����Ϣ");
	SetPosition(POS_X1, posy+=2);
	printf("3. ɾ��ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("4. ��ѧ�Ų��Ҽ�¼");
	SetPosition(POS_X1, posy += 2);
	printf("5. ���������Ҽ�¼");
	SetPosition(POS_X4, posy);
	printf("6. �޸�ѧ����Ϣ");
	SetPosition(POS_X1, posy += 2);
	printf("7. ����ѧ���ɼ�");
	SetPosition(POS_X4, posy);
	printf("8. ����γ̳ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("9. ��ѧ������");
	SetPosition(POS_X4, posy);
	printf("10. ����������");
	SetPosition(POS_X1, posy += 2);
	printf("11. ���ܳɼ���������");
	SetPosition(POS_X4, posy);
	printf("12. ���ܳɼ���������");
	SetPosition(POS_X1, posy += 2);
	printf("13. ѧ���ɼ�ͳ��");
	SetPosition(POS_X4, posy);
	printf("14. ��ӡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("15. ѧ����¼����");
	SetPosition(POS_X4, posy);
	printf("16. �Ӵ��̶�ȡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("0. �˳�");
	//���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
	for (i = 0;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0;j < 55;j++) {
			printf("-");
		}
	}
	//��ʾ�û���Ҫִ�еĹ��ܴ���
	SetPosition(POS_X1, ++posy);
	printf("��ѡ������Ҫ���еĲ���[0-16]: [    ]\b\b\b\b\b");
	scanf_s("%d", &option);
	return option;
}
//����ѧ����Ϣ
void InputRecord(int *n,int*m, STU* stu) {
	int i, j;
	int posy = 6;
	SetPosition(POS_X2, posy);
	printf("����ѧ��������n<%d��: ",STU_NUM);
	scanf_s("%d",n);
	SetPosition(POS_X2, posy += 2);
	printf("����γ�������m<%d��:",COURSE_NUM);
	scanf_s("%d",m);
	for (i = 0;i < 2;i++) {
		SetPosition(POS_X1, ++posy);
		for (j = 0;j < 55;j++) {
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf("����ѧ����ѧ�š������͸��ſγ̳ɼ���");
	for (i = 0;i < *n;i++) {
		SetPosition(POS_X2, ++posy);
		printf("�����%d��ѧ����Ϣ��\t",i+1);
		scanf_s("%ld%s", &stu[i].num, stu[i].name, (unsigned)sizeof(long)+ (unsigned)sizeof(stu[i].name));
		for (j = 0;j < *m;j++) {
			scanf_s("%f", &stu[i].score[j]);
		}
	}
}
//����ѧ���ɼ�
void CalculateScoreOfStudent (int n, int m, STU* stu ) {
	int i, j;
	printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ���֣�\n");
	for (i = 0;i < n;i++) {
		stu[i].sum = 0;
		for (j = 0;j < m;j++) {
			stu[i].sum += stu[i].score[j];
		}
		stu[i].aver = stu[i].sum / m;
		printf("��%d��ѧ�����ܷ�=%.2f, ƽ����=%.2f\n",i+1,stu[i].sum,stu[i].aver);
	}
}
//����γ̳ɼ�
void CalculateScoreOfCourse(int n, int m, STU stu[]) {
	int i,j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��");
	for (j = 0;j < m;j++) {
		sum[j] = 0;
		for (i = 0;i < n;i++) {
			sum[j] += stu[i].score[j];
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1,++posy);
		printf("��%d���γ̣��ܷ�=%.2f, ƽ����=%.2f\n", j + 1, sum[j], aver[j]);
	}
}
//ѧ����¼����
void WritetoFile(int n,int m,STU stu[]) {
	int i, j;
	//�����ļ�ָ��
	FILE* fp;
	//���ļ�,ָ���ļ��Ĵ���ʽΪд�룬����ָ��ָ���ļ�
	if ((fopen_s(&fp,"D:\\Vsproject\\student_management_system\\student.txt", "w"))!=0) {
		printf("");
		exit(0);
	}
	//���ļ���ָ����ʽд���ļ�
	fprintf(fp, "%10d%10d\n", n, m);
	for (i = 0;i < n;i++) {
		fprintf(fp, "%10ld%10s\n", stu[i].num,stu[i].name);
		for (j = 0;j < m;j++) {
			fprintf(fp,"%10.1f", stu[i].score[j]);
		}
		fprintf(fp,"%10.1f%10.1f\n", stu[i].sum, stu[i].aver);
	}
	fclose(fp);
	//��ʾ�û����̲������
	printf("�������!\n");
}
//�Ӵ����ж�ȡѧ����¼
int ReadfromFile(int* n, int* m, STU stu[], int* first)
{
	FILE* fp;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);
	if ((fopen_s(&fp,"D:\\Vsproject\\student_management_system\\student.txt", "r"))!=0)
	{
		printf("�����ļ��޷��򿪣�");
		return 1;
	}
	fscanf_s(fp, "%10d%10d", n, m);
	for (i = 0;i < *n;i++)
	{
		fscanf_s(fp, "%10ld", &stu[i].num);
		fscanf_s(fp, "%10s", stu[i].name, (unsigned)sizeof(stu[i].name));
		for (j = 0;j < *m;j++)
		{
			fscanf_s(fp, "%10f", &stu[i].score[j]);
		}
		fscanf_s(fp, "%10f%10f", &stu[i].sum, &stu[i].aver);
	}
	*first = 0;
	fclose(fp);
	printf("���ݴӴ��̶�ȡ��ϣ�");
	return 0;
}
//����ѧ����¼
void AppendRecord(int* n, int m, STU stu[])
{
	int i, j;
	int num_record;
	printf("��������Ҫ���ӵ�������");
	scanf_s("%d", &num_record);
	while (*n + num_record > STU_NUM)
	{
		printf("����̫�࣬���������룺");
		scanf_s("%d", &num_record);
	}
	for (i = *n;i < *n + num_record;i++)
	{
		printf("�����%d��ѧ����Ϣ��ѧ�š�������%d���γ̣�\t", i + 1,m);
		scanf_s("%ld%s", &stu[i].num, stu[i].name, (unsigned)sizeof(stu[i].num)+ (unsigned)sizeof(stu[i].name));
		for (j = 0;j < m;j++)
		{
			scanf_s("%f", &stu[i].score[j]);
		}
	}
	*n = *n + num_record;
	printf("������!\n");
	return;
}
//��ѧ����
void SearchByNumber(int n, int m, STU* stu) {
	long id;
	int i, j;
	printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf_s("%ld", &id);
	for (i = 0;i < n;i++) {
		if (stu[i].num == id) {
			printf("�ҵ��ˣ���ѧ�Ŷ�Ӧ��ѧ����Ϣ��\n");
			printf("%10ld%15s",stu[i].num,stu[i].name);
			for (j = 0;j < m;j++) {
				printf("%10.2f",stu[i].score[j]);
			}
			printf("%10.2f%10.2f",stu[i].sum,stu[i].aver);
			return;
		}
	}
	printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼");
	return;
}
//����������
void SearchByName(int n,int m,STU*stu) {
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("��������Ҫ���ҵ�ѧ����������");
	scanf_s("%s", name,(unsigned)sizeof(name));
	for (i = 0;i < n;i++) {
		if (strcmp(stu[i].name, name) == 0) {
			printf("�ҵ��ˣ���%dѧ����ϢΪ��\n", ++k);
			printf("%10ld%15s", stu[i].num, stu[i].name);
		}
		for (j = 0;j < m;j++) {
			printf("%10.2f", stu[i].score[j]);
		}
		printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
		flag = 0;
	}
	if (flag) {
		printf("δ�ҵ����������Ӧ��ѧ����¼\n");
	}
	return;
}
//ɾ��ѧ����¼
void DeleteRecord(int* n, int m, STU stu[]) {
	int i, j;
	long id;
	char ch;
	printf("��������Ҫɾ����ѧ����Ϣ��Ӧ��ѧ�ţ�");
	scanf_s("%ld", &id);
	for (i = 0;i < *n;i++) {
		if (stu[i].num == id) {
			printf("�ҵ��˸���ѧ����Ϣ\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0;j < m;j++) {
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
			printf("��ȷ���Ƿ���Ҫɾ��������¼����Y/y��N/n����");
			getchar();
			scanf_s("%c", &ch);
			if (ch == 'Y' || ch == 'y') {
				for (j = i;j < *n - 1;j++) {
					stu[j] = stu[j + 1];
				}
				(*n)--;
				printf("ɾ�����\n");
				return;
			}
			else if (ch == 'N' || ch == 'n') {
				printf("�ҵ��˸�ѧ����¼������ɾ��\n");
				return;
			}
			else {
				printf("�������!\n");
				return;
			}
		}
	}
	printf("δ�ҵ�������¼\n");
	return;
}
//�޸�ѧ������
void ModifyRecord(int n, int m, STU* stu) {
	int i, j;
	long id;
	char ch;
	printf("��������Ҫ�޸���Ϣ��Ӧ��Ӧ��ѧ�ţ�");
	scanf_s("%ld", &id);
	for (i = 0;i < n;i++) {
		if (stu[i].num == id) {
			printf("�ҵ��˸���ѧ����Ϣ\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0;j < m;j++) {
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
			printf("��ȷ���Ƿ���Ҫ�޸ģ���Y/y��N/n����");
			getchar();
			scanf_s("%c", &ch);
			if (ch == 'Y' || ch == 'y') {
				printf("������Ҫ�޸ĵ�ѧ����Ϣ��");
				scanf_s("%ld%s", &stu[i].num, stu[i].name,(unsigned)sizeof(stu[i].num)+(unsigned)sizeof(stu[i].name));
				stu[i].sum = 0;
				for (j = 0;j < m;j++) {
					scanf_s("%f", &stu[i].score[j]);
					stu[i].sum += stu[i].score[j];
				}
				stu[i].aver = stu[i].sum / m;
				printf("�޸����\n");
				return;
			}
			else if (ch == 'N' || ch == 'n') {
				printf("�ҵ��˸�ѧ����¼�������޸�\n");
				return;
			}
			else {
				printf("�������!\n");
				return;
			}
		}
	}
	printf("δ�ҵ�������¼\n");
	return;
}
//���ѧ����¼
void PrintRecord(int n,int m,STU*stu) {
	int i, j;
	printf("ѧ��\t\t����\t\t");
	for (j = 0;j < m;j++) {
		printf("�γ�%d\t\t", j + 1);
	}
	printf("�ܷ�\t\tƽ����\n");
	for (i = 0;i < n;i++) {
		printf("%-16ld%-16s",stu[i].num,stu[i].name);
		for (j = 0;j < m;j++) {
			printf("%-16.1lf", stu[i].score[j]);
		}
		printf("%-16.1lf%-16.1lf\n",stu[i].sum,stu[i].aver);
	}
	return;
}