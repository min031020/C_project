#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


/* ���� ����Ʈ ����ϱ� ���� ����ü ����*/

struct node* head = NULL;
struct node {
	float data;
	struct node* next;
};

/* ������� ��ü ������ �Է� �ޱ� ���� ����ü ����ü ���� */

typedef struct peple { //����ü

	float m; //cm�� 100���� ����
	float kg; //������
	float sex; //����
}Person;

typedef union people { //����ü

	float age; //����
	float act; //Ȱ����
}person;

/* ������� BMI������ ����ϱ� ���� �Լ�
   ���ڷ� ������� �����Կ� Ű�� �޴´�. */

void BMI(float a, float b, FILE* fp) {

	float BMI;
	float* ptr = &BMI; //������ ���
	BMI = b / (a * a);
	if (*ptr < 18.5) {
		printf("\n����� BMI : %.2f (��ü��)\n", *ptr);
		fprintf(fp, "\n����� BMI : %.2f (��ü��)\n", *ptr); //���Ͽ� ����
	}
	else if (18.5 <= *ptr < 23) {
		printf("\n����� BMI : %.2f (����)\n", *ptr);
		fprintf(fp, "����� BMI : %.2f (����)\n", *ptr); //���Ͽ� ����
	}
	else if (23 <= *ptr < 25) {
		printf("\n����� BMI : %.2f (��ü��)\n", *ptr);
		fprintf(fp, "����� BMI : %.2f (��ü��)\n", *ptr); //���Ͽ� ����
	}
	else {
		printf("\n����� BMI : %.2f (��)\n", *ptr);
		fprintf(fp, "����� BMI : %.2f (��)\n", *ptr); //���Ͽ� ����
	}
}

/* ������� ���� Į�θ��� ����ϴ� �Լ�
   ���ڷ� ������� ����, Ű, ������, ����, Ȱ������ �޴´�. */

float MC(float sex, float cm, float kg, float age, float act) {

	float MC, BM;
	BM = (10 * kg + 6.25 * cm - 5 * age) + sex;
	MC = BM * act;
	return MC; //���� Į�θ� ���� ��ȯ
}
/* ������� �����Ը� 5kg ���� ��� �� ������ ����� ������� �����Է� ��ü ���ִ� �Լ�
   ��� ��õ�ϴ� �Լ��� ���鶧�� ���Ǽ��� ���� �������
   ������� �����Ը� �Լ� ���ڷ� �޴´�. */

int ABKG(float a) { //a -> ������� ������

	float abkg; //������� �����Ը� ��ü�� ������ ���� ��� ������
	if (a < 50) { //50 �̸��� ��
		abkg = 47;
	}
	else if (a >= 50 && a < 55) { //50���� 55����
		abkg = 52;
	}
	else if (a >= 55 && a < 60) { //55���� 60����
		abkg = 57;
	}
	else if (a >= 60 && a < 65) { //60���� 65����
		abkg = 62;
	}
	else if (a >= 65 && a < 70) { //65���� 70����
		abkg = 67;
	}
	else if (a >= 70 && a < 75) { //70���� 75����
		abkg = 72;
	}
	else if (a >= 75 && a < 80) { //75���� 80����
		abkg = 77;
	}
	else if (a >= 80 && a < 85) { //80���� 85����
		abkg = 82;
	}
	else if (a >= 85 && a < 90) { //85���� 90����
		abkg = 87;
	}
	else { //������
		abkg = 92;
	}
	return abkg;
}
/* Į�θ��� ��� ���� �Ծ�� �ϴ� ���İ� ������ ������ ��õ�ϴ� �Լ�
   ���� �ϴ� ���� Į�θ��� �� ������ Į�θ��� ������. */

void Food(float G, FILE* fp) {

	char str[6][40] = { "�Ļ� 2��", "������", "���� �ް�", "�߰�����", "���", "�ٳ���" };
	int food[6] = { 222, 148, 68, 125, 140, 93 }; //str�� �ִ� ������ Į�θ� (�������)

	for (int i = 0; i < 6; i++) {
		food[i] = G / food[i];
		printf("%s : %d��\n", str[i], food[i]); //��õ ���İ� ������ ���
		fprintf(fp, "%s : %d��\n", str[i], food[i]); //��õ ���İ� ������ ���Ͽ� ����
	}
}

/* Į�θ��� �Ҹ��ϱ� ���� ��ؾ� �ϴ� ����� ��� �ؾ��ϴ� �ð��� ��õ�ϴ� �Լ�
   �Ҹ��ؾ� �ϴ� Į�θ��� ������� �뷫���� �����Ը� ���ڷ� �޾� ��ؾ� �ϴ� ����� � �ð��� ������ش�. */

void WorkOut(float G, int abkg, FILE* fp) { //G : �Ҹ��ؾ� �ϴ� Į�θ�, abkg : ������� �뷫���� ������

	char str[8][20] = { "�ȱ�", "���", "����", "�ٳѱ�", "������", "�޸���", "����Ʈ", "��������Ű��" };
	float work[8] = { 16, 29, 37, 41, 33 , 29, 29, 33 };

	while (abkg - 47 > 0) {
		work[0] = work[0] + 1.5; //�ȱ�
		work[1] = work[1] + 3; //���
		work[2] = work[2] + 4; //����
		work[3] = work[3] + 4.5; //�ٳѱ�
		work[4] = work[4] + 3; //������
		work[5] = work[5] + 3; //�޸���
		work[6] = work[6] + 3; //����Ʈ
		work[7] = work[7] + 3.5; //��������Ű��
		abkg -= 5;
	}

	for (int i = 0; i < 8; i++) {

		int K = (G / work[i]) * 5;
		printf("%s : %d�ð� %d��\n", str[i], K / 60, K % 60); //��õ ��� � �ð� ���
		fprintf(fp, "%s : %d�ð� %d��\n", str[i], K / 60, K % 60); //��õ ��� � �ð��� ���Ͽ� ����
	}
}
/* ����ڰ� ���� Į�θ�
�� ����ϱ� ���� �Լ� ���� */

int MainCal();
int Protein();
int Fruit();
int Drink();

//main �Լ�

int main() {

	struct node* temp; //���� ����Ʈ
	temp = (struct  node*)malloc(sizeof(struct node)); //���� ����Ʈ
	FILE* fp = fopen("myinfo.txt", "w"); //���� write ��Ʈ�� ����
	Person stdata; //����ü ����
	person undata; //����ü ����
	int maincal, protein, fruit, drink, sum, goal, abkg; //�ֽ�, �ܹ���, ����, ����, �հ�, ��ǥ, ��� ������
	float mc, G; //���� Į�θ�, ��ǥ Į�θ�
	char ch; //����
	char str1[] = "����� ���� : ";

	//���� �Է� �ޱ�
	printf("���� (����: m, ����: f �Է�) : ");
	scanf("%c", &ch);
	printf("\n");

	//������ ���� ���� Į�θ��� ���� ���� �޶����Ƿ� ����
	if (ch == 'M' || ch == 'm') {
		stdata.sex = 5; //���� Į�θ� ���� 5�� ��
		fprintf(fp, "����� ���� : %c (����)\n", ch); //���Ͽ� ����
	}
	if (ch == 'F' || ch == 'f') {
		stdata.sex = -151; //���� Į�θ� ���� -151�� ��
		fprintf(fp, "����� ���� : %c (����)\n", ch); //���Ͽ� ����
	}
	//Ű �Է� �ޱ�
	printf("Ű(cm) : ");
	scanf("%f", &temp->data); //����ü cm�� ����
	fprintf(fp, "����� Ű : %.1f\n", temp->data); //���Ͽ� ����
	printf("\n");

	//������ �Է� �ޱ�
	printf("������(kg) : ");
	scanf("%f", &stdata.kg); //����ü kg�� ����
	fprintf(fp, "����� ������ : %.1f\n", stdata.kg); //���Ͽ� ����
	printf("\n");

	abkg = ABKG(stdata.kg); // ������� ������ ��� ������ ���� ��� �����Է� ��ü

	//���� �Է� �ޱ�
	printf("����(��) : ");
	scanf("%f", &undata.age); //����ü age�� ����
	fprintf(fp, "����� ����(��) : %.0f\n", undata.age); //���Ͽ� ����
	printf("\n");

	//Ȱ���� �Է� �ޱ�
	printf("<Ȱ����>\n����(�繫��, ��� ���� ����) : 1\n�߰�(���� ���� or �繫�� + �Ϸ� 1�ð� �) : 2\n����(Ȱ������ ���� + �Ϸ� 1�ð� �) : 3\n > �Է� : ");
	scanf("%f", &undata.act); //����ü act�� �Է� �ޱ�
	if (undata.act == 1) {//Ȱ������ 1�ܰ��� ��
		undata.act = 1.2;
		fputs("����� Ȱ���� : ����\n", fp); //���Ͽ� ����
	}
	else if (undata.act == 2) {//Ȱ������ 2�ܰ��� ��
		undata.act = 1.4;
		fputs("����� Ȱ���� : �߰�\n", fp); //���Ͽ� ����
	}
	else {//Ȱ������ 3�ܰ��� ��
		undata.act = 1.55;
		fputs("����� Ȱ���� : ����\n", fp); //���Ͽ� ����
	}

	stdata.m = temp->data / 100; //BMI ����� ���Ǽ��� ���� m�� ����

	BMI(stdata.m, stdata.kg, fp); //BMI��� ���ڷ� Ű�� ������ ��ȯ
	printf("\n");

	/* ���� Į�θ��� ��� �ϱ� ���� ����, Ű, ������, ����, Ȱ������ ���ڷ� ��ȯ
	���� ���� mc�� ���� */
	mc = MC(stdata.sex, temp->data, stdata.kg, undata.age, undata.act);

	/* ����ڰ� ��ǥ�� �Է�
	��ǥ�� ���� maincal�� �ٸ��� ���� �� */
	printf("<��ǥ>\n���� : 1\n���� : 2\n��ŷ : 3\n > �Է� : ");
	scanf("%d", &goal);
	switch (goal) {
	case 1: //��ǥ�� ������ ��� -> maincal �״��
		fputs("����� ��ǥ : ����\n", fp); //���Ͽ� ����
		break;
	case 2: //��ǥ�� ���̾�Ʈ�� ��� -> maincal - 500�� ��ǥ Į�θ��� ����
		mc -= 500;
		fputs("����� ��ǥ : ����\n", fp); //���Ͽ� ����
		break;
	case 3: //��ǥ�� �� ������ ��� -> maincal + 500�� ��ǥ Į�θ��� ����
		mc += 500;
		fputs("����� ��ǥ : ��ŷ\n", fp); //���Ͽ� ����
		break;
	default:
		break;
	}

	//����ڰ� ���� Į�θ��� ����ϱ� ���� sum ������ �� �������� ���� ������ ����
	maincal = MainCal();
	protein = Protein();
	fruit = Fruit();
	drink = Drink();
	sum = maincal + protein + fruit + drink;

	G = mc - sum;

	//��ǥ Į�θ��� ���
	printf("\n��ǥ Į�θ� : %.2f\n", mc);
	fprintf(fp, "����� ��ǥ Į�θ� : %.2fkcal\n", mc);
	//���� Į�θ��� ���
	printf("���� Į�θ� : %d\n", sum);
	fprintf(fp, "����� ���� Į�θ� : %dkcal\n", sum);

	if (G >= 0) { //G > 0�� ��� ���� �Ǿߵȴٴ� �ǹ��̹Ƿ� ������ ��õ
		printf("\n��ǥ :  %.2fkcal ���\n", G);
		printf("\n>>>��õ ����\n");
		fputs("\n>>>��õ ����\n", fp); //���Ͽ� ����
		Food(G, fp);
	}
	else { //G < 0�� ��� ���� �����Ѵٴ� �ǹ��̹Ƿ� ��� ��õ
		G = -G; //G�� ��ȣ�� �ٲ���
		printf("\n��ǥ : %.2f �Ҹ��ϱ�\n", G);
		printf("\n>>>��õ �\n");
		fputs("\n>>>��õ �\n", fp); //���Ͽ� ����
		WorkOut(G, abkg, fp);
	}

	fclose(fp); //�Ҹ�

	return 0;
}

/* ���� �ֽ� Į�θ��� ����ϴ� �Լ� */

int MainCal() {

	int food, num, menu, total;
	/* food : ����ڰ� 10���� �޴��߿� ���� ������ ���ý� ������ ����
	   num : ����ڰ� ���� �޴��� ������ ������ ����
	   menu : ����ڰ� ���� ������ ������ ������ ����
	   sum : ����ڰ� ���� ������ Į�θ��� ���� ������ ���� */

	total = 0; //�հ� : 0���� �ʱ�ȭ
	printf("\n���� ���� �Ĵ��� �Է��ϼ���.\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------\n");
	printf("1. �ҹ� 1����(210g)      2. �Ļ� 2��(80g)         3. ������ 1��(200g)  4. ����� 1��(200g)\n");
	printf("5. ���� 1����(90~150g)   6. ������ 1�κ�(200g)    7. ��� 1��            8. ��� 1����\n");
	printf("9. ����� 1�κ�          10. �ܹ��� 1��\n");
	printf("--------------------------------------------------------------------------------------------------------------");
	printf("\n> �Է��� �޴� ���� : ");

	scanf("%d", &menu); //�Է��� �޴� ���� �Է�

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> �Է�(�޴�%d �Է�) \n��ȣ : ", i);
			scanf("%d", &food); //�޴� ��ȣ �Է�
			printf("���� : ");
			scanf("%d", &num); //���� �Է�

			switch (food) {
			case 1: //�ҹ�
				total += 310 * num; break;
			case 2: //�Ļ� 2��
				total += 222 * num; break;
			case 3: //������ 1��
				total += 148 * num; break;
			case 4: //����� 1��
				total += 130 * num; break;
			case 5: //���� 1����
				total += 322 * num; break;
			case 6: //������ 1�κ�
				total += 303 * num; break;
			case 7: //��� 1��
				total += 318 * num; break;
			case 8: //��� 1����
				total += 493 * num; break;
			case 9: //����� 1�κ�
				total += 665 * num; break;
			case 10: //�ܹ��� 1��
				total += 395 * num; break;
			}
		}
		return total; //�հ� ��ȯ
	}

}

/* ���� �ܹ��� Į�θ��� ����ϴ� �Լ�*/

int Protein() {

	int food, num, menu, total;
	/* food : ����ڰ� 8���� �޴��߿� ���� ������ ���ý� ������ ����
	   num : ����ڰ� ���� �޴��� ������ ������ ����
	   menu : ����ڰ� ���� ������ ������ ������ ����
	   sum : ����ڰ� ���� ������ Į�θ��� ���� ������ ���� */

	total = 0; //�հ� : 0���� �ʱ�ȭ
	printf("\n���� ���� �ܹ����� �Է��ϼ���.\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------\n");
	printf("1. ���� �ް� 1��(50g)  2. ���� ��� 1��(45g)              3. ����Ķ��� 1��(46g)             4. ���� �߰����� 1�κ�(100g)\n");
	printf("5. �κ�(100g)          6. ������� ���� 1�κ�(150g)     7. �Ұ�� ��ɱ��� 1�κ�(200g)     8. ġŲ 1����\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------");
	printf("\n> �Է��� �޴� ���� : ");

	scanf("%d", &menu); //�Է��� �޴� ���� �Է�

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> �Է�(�޴�%d �Է�) \n��ȣ : ", i);
			scanf("%d", &food); //�޴� ��ȣ �Է�
			printf("���� : ");
			scanf("%d", &num); //���� �Է�

			switch (food) {
			case 1: //���� �ް�
				total += 68 * num; break;
			case 2: //���� ���
				total += 73 * num; break;
			case 3: //����Ķ���
				total += 89 * num; break;
			case 4: //�߰�����
				total += 125 * num; break;
			case 5: //�κ�
				total += 88 * num; break;
			case 6: //����
				total += 407 * num; break;
			case 7: //�Ұ��
				total += 434 * num; break;
			case 8: //ġŲ
				total += 317 * num; break;
			}
		}
		return total; //�հ� ��ȯ
	}
}

/* ���� ���� Į�θ��� ����ϴ� �Լ� */

int Fruit() {

	int food, num, menu, total;
	/* food : ����ڰ� 10���� �޴��߿� ���� ������ ���ý� ������ ����
	   num : ����ڰ� ���� �޴��� ������ ������ ����
	   menu : ����ڰ� ���� ������ ������ ������ ����
	   sum : ����ڰ� ���� ������ Į�θ��� ���� ������ ���� */

	total = 0; //�հ� : 0���� �ʱ�ȭ
	printf("\n���� ���� ������ �Է��ϼ���.\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------\n");
	printf("1. ��� 1��(250 ~ 300g)  2. �� 1��(100g)    3. ���� 5��(100g)                 4. �ٳ��� 1��(100g)  5.����丶�� 1��(100g)\n");
	printf("6. �丶�� 1��(100g)      7. ���� 1��(100g)  8. ��ä������ �巹�� 1�κ�(150g)  9.�����(100g)       10. �����(100g)\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------");
	printf("\n> �Է��� �޴� ���� : ");

	scanf("%d", &menu); //�Է��� �޴� ���� �Է�

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> �Է�(�޴�%d �Է�) \n��ȣ : ", i);
			scanf("%d", &food); //�޴� ��ȣ �Է�
			printf("���� : ");
			scanf("%d", &num); //���� �Է�

			switch (food) {
			case 1: //���
				total += 140 * num; break;
			case 2: //��
				total += 39 * num; break;
			case 3: //����
				total += 27 * num; break;
			case 4: //�ٳ���
				total += 93 * num; break;
			case 5: //��� �丶��
				total += 20 * num; break;
			case 6: //�丶��
				total += 14 * num; break;
			case 7: //����
				total += 60 * num; break;
			case 8: //��ä ������ �巹��
				total += 148 * num; break;
			case 9: //�����
				total += 11 * num; break;
			case 10: //�����
				total += 24 * num; break;
			}
		}
		return total; //�հ� ��ȯ
	}
}

/* ���� ���� Į�θ��� ����ϴ� �Լ� */

int Drink() {

	int food, num, menu, total;
	/* food : ����ڰ� 10���� �޴��߿� ���� ������ ���ý� ������ ����
	   num : ����ڰ� ���� �޴��� ������ ������ ����
	   menu : ����ڰ� ���� ������ ������ ������ ����
	   sum : ����ڰ� ���� ������ Į�θ��� ���� ������ ���� */

	total = 0; //�հ� : 0���� �ʱ�ȭ
	printf("\n���� ���� ���Ḧ �Է��ϼ���.\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------\n");
	printf("1. ���� 1��(100ml)       2. �Ƹ޸�ī�� 1��(240ml)  3. ���� 1��(190ml)      4. �Ƹ��긮�� 1��(190ml)   5. �ݶ� 1/2��(250ml)\n");
	printf("6. �Ŀ����̵� 1��(600ml) 7. ź���                8.�������ֽ� 1��(180ml)  9.���� 1��(375ml)            10. ���� 1ĵ(355ml)\n");
	printf("-----------------------------------------------------�޴�-----------------------------------------------------");
	printf("\n> �Է��� �޴� ���� : ");

	scanf("%d", &menu); //�Է��� �޴� ���� �Է�

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> �Է�(�޴�%d �Է�) \n��ȣ : ", i);
			scanf("%d", &food); //�޴� ��ȣ �Է�
			printf("���� : ");
			scanf("%d", &num); //���� �Է�

			switch (food) {
			case 1: //����
				total += 65 * num; break;
			case 2: //�Ƹ޸�ī��
				total += 4 * num; break;
			case 3: //����
				total += 115 * num; break;
			case 4: //�Ƹ��긮��
				total += 45 * num; break;
			case 5: //�ݶ�
				total += 108 * num; break;
			case 6: //�Ŀ����̵�
				total += 60 * num; break;
			case 7: //ź���
				total += 0 * num; break;
			case 8: //�������ֽ�
				total += 85 * num; break;
			case 9: //����
				total += 572 * num; break;
			case 10: //����
				total += 142 * num; break;
			}
		}
		return total; //�հ� ��ȯ
	}
}










