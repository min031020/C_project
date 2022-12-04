#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

/* 연결 리스트 사용하기 위한 구조체 선언*/

struct node {
	float data;
	struct node* next;
};

/* 사용자의 신체 정보를 입력 받기 위해 구조체 공용체 선언 */

typedef struct peple { //구조체

	float m; //cm를 100으로 나눔
	float sex; //성별
}Person;

typedef union people { //공용체

	float age; //나이
	float act; //활동량
}person;

/* 사용자의 BMI지수를 계산하기 위한 함수
   인자로 사용자의 몸무게와 키를 받는다. */

void BMI(float a, float b, FILE* fp) {

	float BMI;
	float* ptr = &BMI; //포인터 사용
	BMI = b / (a * a);
	if (*ptr < 18.5) {
		printf("\n당신의 BMI : %.2f (저체중)\n", *ptr);
		fprintf(fp, "\n당신의 BMI : %.2f (저체중)\n", *ptr); //파일에 저장
	}
	else if (18.5 <= *ptr < 23) {
		printf("\n당신의 BMI : %.2f (정상)\n", *ptr);
		fprintf(fp, "당신의 BMI : %.2f (정상)\n", *ptr); //파일에 저장
	}
	else if (23 <= *ptr < 25) {
		printf("\n당신의 BMI : %.2f (과체중)\n", *ptr);
		fprintf(fp, "당신의 BMI : %.2f (과체중)\n", *ptr); //파일에 저장
	}
	else {
		printf("\n당신의 BMI : %.2f (비만)\n", *ptr);
		fprintf(fp, "당신의 BMI : %.2f (비만)\n", *ptr); //파일에 저장
	}
}

/* 사용자의 유지 칼로리를 계산하는 함수
   인자로 사용자의 성별, 키, 몸무게, 나이, 활동량을 받는다. */

float MC(float sex, float cm, float kg, float age, float act) {

	float MC, BM;
	BM = (10 * kg + 6.25 * cm - 5 * age) + sex;
	MC = BM * act;
	return MC; //유지 칼로리 값을 반환
}
/* 사용자의 몸무게를 5kg 별로 끊어서 각 구간의 평균을 사용자의 몸무게로 대체 해주는 함수
   운동을 추천하는 함수를 만들때의 편의성을 위해 만들어짐
   사용자의 몸무게를 함수 인자로 받는다. */

int ABKG(float a) { //a -> 사용자의 몸무게

	float abkg; //사용자의 몸무게를 대체할 구간에 따른 평균 몸무게
	if (a < 50) { //50 미만일 시
		abkg = 47;
	}
	else if (a >= 50 && a < 55) { //50에서 55사이
		abkg = 52;
	}
	else if (a >= 55 && a < 60) { //55에서 60사이
		abkg = 57;
	}
	else if (a >= 60 && a < 65) { //60에서 65사이
		abkg = 62;
	}
	else if (a >= 65 && a < 70) { //65에서 70사이
		abkg = 67;
	}
	else if (a >= 70 && a < 75) { //70에서 75사이
		abkg = 72;
	}
	else if (a >= 75 && a < 80) { //75에서 80사이
		abkg = 77;
	}
	else if (a >= 80 && a < 85) { //80에서 85사이
		abkg = 82;
	}
	else if (a >= 85 && a < 90) { //85에서 90사이
		abkg = 87;
	}
	else { //나머지
		abkg = 92;
	}
	return abkg;
}
/* 칼로리를 얻기 위해 먹어야 하는 음식과 음식의 개수를 추천하는 함수
   얻어야 하는 최종 칼로리를 각 음식의 칼로리로 나눈다. */

void Food(float G, FILE* fp) {

	char str[6][40] = { "식빵 2쪽", "군고구마", "삶은 달걀", "닭가슴살", "사과", "바나나" };
	int food[6] = { 222, 148, 68, 125, 140, 93 }; //str에 있는 음식의 칼로리 (순서대로)

	for (int i = 0; i < 6; i++) {
		food[i] = G / food[i];
		printf("%s : %d개\n", str[i], food[i]); //추천 음식과 개수를 출력
		fprintf(fp, "%s : %d개\n", str[i], food[i]); //추천 음식과 개수를 파일에 저장
	}
}

/* 칼로리를 소모하기 위해 운동해야 하는 종목과 운동을 해야하는 시간을 추천하는 함수
   소모해야 하는 칼로리와 사용자의 대략적인 몸무게를 인자로 받아 운동해야 하는 종목과 운동 시간을 계산해준다. */

void WorkOut(float G, int abkg, FILE* fp) { //G : 소모해야 하는 칼로리, abkg : 사용자의 대략적인 몸무게

	char str[8][20] = { "걷기", "계단", "수영", "줄넘기", "자전거", "달리기", "스쿼트", "윗몸일으키기" };
	float work[8] = { 16, 29, 37, 41, 33 , 29, 29, 33 };

	while (abkg - 47 > 0) {
		work[0] = work[0] + 1.5; //걷기
		work[1] = work[1] + 3; //계단
		work[2] = work[2] + 4; //수영
		work[3] = work[3] + 4.5; //줄넘기
		work[4] = work[4] + 3; //자전거
		work[5] = work[5] + 3; //달리기
		work[6] = work[6] + 3; //스쿼트
		work[7] = work[7] + 3.5; //윗몸일으키기
		abkg -= 5;
	}

	for (int i = 0; i < 8; i++) {

		int K = (G / work[i]) * 5;
		printf("%s : %d시간 %d분\n", str[i], K / 60, K % 60); //추천 운동과 운동 시간 출력
		fprintf(fp, "%s : %d시간 %d분\n", str[i], K / 60, K % 60); //추천 운동과 운동 시간을 파일에 저장
	}
}
/* 사용자가 먹은 칼로리
를 계산하기 위한 함수 선언 */

int MainCal();
int Protein();
int Fruit();
int Drink();

//main 함수

int main() {

	//노드에 메모리 할당
	struct node* node1 = malloc(sizeof(struct node));
	struct node* node2 = malloc(sizeof(struct node));
	node1->next = node2;

	FILE* fp = fopen("myinfo.txt", "w"); //파일 write 스트림 생성
	Person stdata; //구조체 선언
	person undata; //공용체 선언

	int maincal, protein, fruit, drink, sum, goal, abkg; //주식, 단백질, 과일, 음료, 합계, 목표, 평균 몸무게
	float mc, G; //유지 칼로리, 목표 칼로리
	char ch; //성별
	char str1[] = "당신의 성별 : ";

	//성별 입력 받기
	printf("성별 (남자: m, 여자: f 입력) : ");
	scanf("%c", &ch);
	printf("\n");

	//성별에 따라 메인 칼로리에 들어가는 값이 달라지므로 구분
	if (ch == 'M' || ch == 'm') {
		stdata.sex = 5; //메인 칼로리 계산시 5가 들어감
		fprintf(fp, "당신의 성별 : %c (남자)\n", ch); //파일에 저장
	}
	if (ch == 'F' || ch == 'f') {
		stdata.sex = -151; //메인 칼로리 계산시 -151이 들어감
		fprintf(fp, "당신의 성별 : %c (여자)\n", ch); //파일에 저장
	}
	//키 입력 받기
	printf("키(cm) : ");
	scanf("%f", &node1->data); //구조체 cm에 저장
	fprintf(fp, "당신의 키 : %.1f\n", node1->data); //파일에 저장
	printf("\n");

	//몸무게 입력 받기
	printf("몸무게(kg) : ");
	scanf("%f", &node2->data); //구조체 kg에 저장
	fprintf(fp, "당신의 몸무게 : %.1f\n", node2->data); //파일에 저장
	printf("\n");

	node2->next = NULL;

	abkg = ABKG(node2->data); // 사용자의 몸무게 대신 구간에 따른 평균 몸무게로 대체

	//나이 입력 받기
	printf("나이(만) : ");
	scanf("%f", &undata.age); //구조체 age에 저장
	fprintf(fp, "당신의 나이(만) : %.0f\n", undata.age); //파일에 저장
	printf("\n");

	//활동량 입력 받기
	printf("<활동량>\n적음(사무직, 운동을 따로 안함) : 1\n중간(서서 일함 or 사무직 + 하루 1시간 운동) : 2\n많음(활동적인 직장 + 하루 1시간 운동) : 3\n > 입력 : ");
	scanf("%f", &undata.act); //구조체 act를 입력 받기
	if (undata.act == 1) {//활동량이 1단계일 시
		undata.act = 1.2;
		fputs("당신의 활동량 : 적음\n", fp); //파일에 저장
	}
	else if (undata.act == 2) {//활동량이 2단계일 시
		undata.act = 1.4;
		fputs("당신의 활동량 : 중간\n", fp); //파일에 저장
	}
	else {//활동량이 3단계일 시
		undata.act = 1.55;
		fputs("당신의 활동량 : 많음\n", fp); //파일에 저장
	}

	stdata.m = node1->data / 100; //BMI 계산의 편의성을 위해 m를 구함

	BMI(stdata.m, node2->data, fp); //BMI계산 인자로 키와 몸무게 반환
	printf("\n");

	/* 메인 칼로리를 계산 하기 위해 성별, 키, 몸무게, 나이, 활동량을 인자로 반환
	계산된 값을 mc에 저장 */
	mc = MC(stdata.sex, node1->data, node2->data, undata.age, undata.act);

	/* 사용자가 목표를 입력
	목표에 따라서 maincal를 다르게 설정 함 */
	printf("<목표>\n유지 : 1\n컷팅 : 2\n벌킹 : 3\n > 입력 : ");
	scanf("%d", &goal);
	switch (goal) {
	case 1: //목표가 유지일 경우 -> maincal 그대로
		fputs("당신의 목표 : 유지\n", fp); //파일에 저장
		break;
	case 2: //목표가 다이어트일 경우 -> maincal - 500을 목표 칼로리로 설정
		mc -= 500;
		fputs("당신의 목표 : 컷팅\n", fp); //파일에 저장
		break;
	case 3: //목표가 살 찌우기일 경우 -> maincal + 500을 목표 칼로리로 설정
		mc += 500;
		fputs("당신의 목표 : 벌킹\n", fp); //파일에 저장
		break;
	default:
		break;
	}

	//사용자가 먹은 칼로리를 계산하기 위해 sum 변수에 각 종류별로 먹은 음식을 더함
	maincal = MainCal();
	protein = Protein();
	fruit = Fruit();
	drink = Drink();
	sum = maincal + protein + fruit + drink;

	G = mc - sum;

	//목표 칼로리를 출력
	printf("\n목표 칼로리 : %.2fkcal\n", mc);
	fprintf(fp, "당신의 목표 칼로리 : %.2fkcal\n", mc);
	//먹은 칼로리를 출력
	printf("먹은 칼로리 : %dkcal\n", sum);
	fprintf(fp, "당신이 먹은 칼로리 : %dkcal\n", sum);

	if (G >= 0) { //G > 0일 경우 살을 쪄야된다는 의미이므로 음식을 추천
		printf("\n목표 :  %.2fkcal 얻기\n", G);
		printf("\n>>>추천 음식\n");
		fputs("\n>>>추천 음식\n", fp); //파일에 저장
		Food(G, fp);
	}
	else { //G < 0일 경우 살을 빼야한다는 의미이므로 운동을 추천
		G = -G; //G의 부호를 바꿔줌
		printf("\n목표 : %.2fkcal 소모하기\n", G);
		printf("\n>>>추천 운동\n");
		fputs("\n>>>추천 운동\n", fp); //파일에 저장
		WorkOut(G, abkg, fp);
	}

	fclose(fp); //소멸
	free(node1);
	return 0;
}

/* 먹은 주식 칼로리를 계산하는 함수 */

int MainCal() {

	int food, num, menu, total;
	/* food : 사용자가 10개의 메뉴중에 먹은 음식을 선택시 저장할 변수
	   num : 사용자가 먹은 메뉴의 개수를 저장할 변수
	   menu : 사용자가 먹은 음식의 개수를 저장할 변수
	   sum : 사용자가 먹은 음식의 칼로리의 합을 저장할 변수 */

	total = 0; //합계 : 0으로 초기화
	printf("\n오늘 먹은 식단을 입력하세요.\n");
	printf("-----------------------------------------------------메뉴-----------------------------------------------------\n");
	printf("1. 쌀밥 1공기(210g)      2. 식빵 2쪽(80g)         3. 군고구마 1개(200g)  4. 찐고구마 1개(200g)\n");
	printf("5. 피자 1조각(90~150g)   6. 떡볶이 1인분(200g)    7. 김밥 1줄            8. 라면 1봉지\n");
	printf("9. 자장면 1인분          10. 햄버거 1개\n");
	printf("--------------------------------------------------------------------------------------------------------------");
	printf("\n> 입력할 메뉴 개수 : ");

	scanf("%d", &menu); //입력할 메뉴 개수 입력

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> 입력(메뉴%d 입력) \n번호 : ", i);
			scanf("%d", &food); //메뉴 번호 입력
			printf("개수 : ");
			scanf("%d", &num); //개수 입력

			switch (food) {
			case 1: //쌀밥
				total += 310 * num; break;
			case 2: //식빵 2쪽
				total += 222 * num; break;
			case 3: //군고구마 1개
				total += 148 * num; break;
			case 4: //찐고구마 1개
				total += 130 * num; break;
			case 5: //피자 1조각
				total += 322 * num; break;
			case 6: //떡볶이 1인분
				total += 303 * num; break;
			case 7: //김밥 1줄
				total += 318 * num; break;
			case 8: //라면 1봉지
				total += 493 * num; break;
			case 9: //자장면 1인분
				total += 665 * num; break;
			case 10: //햄버거 1개
				total += 395 * num; break;
			}
		}
		return total; //합계 반환
	}

}

/* 먹은 단백질 칼로리를 계산하는 함수*/

int Protein() {

	int food, num, menu, total;
	/* food : 사용자가 8개의 메뉴중에 먹은 음식을 선택시 저장할 변수
	   num : 사용자가 먹은 메뉴의 개수를 저장할 변수
	   menu : 사용자가 먹은 음식의 개수를 저장할 변수
	   sum : 사용자가 먹은 음식의 칼로리의 합을 저장할 변수 */

	total = 0; //합계 : 0으로 초기화
	printf("\n오늘 먹은 단백질을 입력하세요.\n");
	printf("-----------------------------------------------------메뉴-----------------------------------------------------\n");
	printf("1. 삶은 달걀 1개(50g)  2. 구운 계란 1개(45g)              3. 계란후라이 1개(46g)             4. 훈제 닭가슴살 1인분(100g)\n");
	printf("5. 두부(100g)          6. 돼지고기 삼겹살 1인분(150g)     7. 소고기 등심구이 1인분(200g)     8. 치킨 1조각\n");
	printf("--------------------------------------------------------------------------------------------------------------");
	printf("\n> 입력할 메뉴 개수 : ");

	scanf("%d", &menu); //입력할 메뉴 개수 입력

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> 입력(메뉴%d 입력) \n번호 : ", i);
			scanf("%d", &food); //메뉴 번호 입력
			printf("개수 : ");
			scanf("%d", &num); //개수 입력

			switch (food) {
			case 1: //삶은 달걀
				total += 68 * num; break;
			case 2: //구운 계란
				total += 73 * num; break;
			case 3: //계란후라이
				total += 89 * num; break;
			case 4: //닭가슴살
				total += 125 * num; break;
			case 5: //두부
				total += 88 * num; break;
			case 6: //삼겹살
				total += 407 * num; break;
			case 7: //소고기
				total += 434 * num; break;
			case 8: //치킨
				total += 317 * num; break;
			}
		}
		return total; //합계 반환
	}
}

/* 먹은 과일 칼로리를 계산하는 함수 */

int Fruit() {

	int food, num, menu, total;
	/* food : 사용자가 10개의 메뉴중에 먹은 음식을 선택시 저장할 변수
	   num : 사용자가 먹은 메뉴의 개수를 저장할 변수
	   menu : 사용자가 먹은 음식의 개수를 저장할 변수
	   sum : 사용자가 먹은 음식의 칼로리의 합을 저장할 변수 */

	total = 0; //합계 : 0으로 초기화
	printf("\n오늘 먹은 과일을 입력하세요.\n");
	printf("-----------------------------------------------------메뉴-----------------------------------------------------\n");
	printf("1. 사과 1개(250 ~ 300g)  2. 귤 1개(100g)    3. 딸기 5개(100g)                 4. 바나나 1개(100g)  5.방울토마토 1개(100g)\n");
	printf("6. 토마토 1개(100g)      7. 포도 1개(100g)  8. 야채샐러드 드레싱 1인분(150g)  9.양상추(100g)       10. 양배추(100g)\n");
	printf("--------------------------------------------------------------------------------------------------------------");
	printf("\n> 입력할 메뉴 개수 : ");

	scanf("%d", &menu); //입력할 메뉴 개수 입력

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> 입력(메뉴%d 입력) \n번호 : ", i);
			scanf("%d", &food); //메뉴 번호 입력
			printf("개수 : ");
			scanf("%d", &num); //개수 입력

			switch (food) {
			case 1: //사과
				total += 140 * num; break;
			case 2: //귤
				total += 39 * num; break;
			case 3: //딸기
				total += 27 * num; break;
			case 4: //바나나
				total += 93 * num; break;
			case 5: //방울 토마토
				total += 20 * num; break;
			case 6: //토마토
				total += 14 * num; break;
			case 7: //포도
				total += 60 * num; break;
			case 8: //야채 샐러드 드레싱
				total += 148 * num; break;
			case 9: //양상추
				total += 11 * num; break;
			case 10: //양배추
				total += 24 * num; break;
			}
		}
		return total; //합계 반환
	}
}

/* 먹은 음료 칼로리를 계산하는 함수 */

int Drink() {

	int food, num, menu, total;
	/* food : 사용자가 10개의 메뉴중에 먹은 음식을 선택시 저장할 변수
	   num : 사용자가 먹은 메뉴의 개수를 저장할 변수
	   menu : 사용자가 먹은 음식의 개수를 저장할 변수
	   sum : 사용자가 먹은 음식의 칼로리의 합을 저장할 변수 */

	total = 0; //합계 : 0으로 초기화
	printf("\n오늘 먹은 음료를 입력하세요.\n");
	printf("-----------------------------------------------------메뉴-----------------------------------------------------\n");
	printf("1. 우유 1컵(100ml)       2. 아메리카노 1잔(240ml)  3. 두유 1팩(190ml)      4. 아몬드브리즈 1팩(190ml)   5. 콜라 1/2병(250ml)\n");
	printf("6. 파워에이드 1병(600ml) 7. 탄산수                8.오렌지주스 1병(180ml)  9.소주 1병(375ml)            10. 맥주 1캔(355ml)\n");
	printf("--------------------------------------------------------------------------------------------------------------");
	printf("\n> 입력할 메뉴 개수 : ");

	scanf("%d", &menu); //입력할 메뉴 개수 입력

	if (menu == 0) {
		return total;
	}
	else {
		for (int i = 1; i <= menu; i++) {
			printf("\n> 입력(메뉴%d 입력) \n번호 : ", i);
			scanf("%d", &food); //메뉴 번호 입력
			printf("개수 : ");
			scanf("%d", &num); //개수 입력

			switch (food) {
			case 1: //우유
				total += 65 * num; break;
			case 2: //아메리카노
				total += 4 * num; break;
			case 3: //두유
				total += 115 * num; break;
			case 4: //아몬드브리즈
				total += 45 * num; break;
			case 5: //콜라
				total += 108 * num; break;
			case 6: //파워에이드
				total += 60 * num; break;
			case 7: //탄산수
				total += 0 * num; break;
			case 8: //오렌지주스
				total += 85 * num; break;
			case 9: //소주
				total += 572 * num; break;
			case 10: //맥주
				total += 142 * num; break;
			}
		}
		return total; //합계 반환
	}
}










