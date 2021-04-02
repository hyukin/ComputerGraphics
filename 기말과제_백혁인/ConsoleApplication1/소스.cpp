#include <glut.h>
#include <Windows.h>
#include <stdio.h>
#include <GLU.H>
#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 500
#define HEIGHT 500
GLfloat balance;
float fix = 3.5;
int runn=1;
int TopLeftX = 0;
int TopLeftY = 0;
int swc = 2;
int sw1k = 0; //1번 동작제어키
int sw2k = 0; //2번 동작제어키
int keyChk;				//방향키
int keyChk2;
int xcount=0;
int rswc = 1; //런스위치
int win = 0;
int call1 = 0; //2컷랜덤함수 1번실행위해설정
int call2 = 0; //3컷랜덤함수 1번실행위해설정
int call3 = 0; //4컷랜덤함수 1번실행위해설정
int boxi1;
int boxi2; 
int boxi3;
int boxi4;
int boxi5;
int boxi6;//인트형 박스 랜덤값
int ra1n;
int ra2n;
int eventc11 = 0;
int eventc12 = 0; //수영장 일회키
int eventc21 = 0;
int eventc22 = 0;//사이클 1회키
int eventc31 = 0;
int eventc32 = 0;//런닝 1회키
int event11 = 0;
int event12 = 0;//수영 랜덤픽
int event21 = 0;
int event22 = 0; //이벤트 랜덤픽
int event31 = 0;
int event32 = 0; //런닝 랜덤픽
int cnt = 0; int cnt11 = 0; int cnt12 = 0; int  cnt21 = 0; int  cnt22 = 0; int  cnt31 = 0; int cnt32 = 0;
int enter = 0;

int ans1 = 50;
int ans2 = 4;//수영 
int ans3 = 50;
int ans4 = 4;//사이클
int ans5 = 50;
int ans6 = 4;//사이클

int tmp11 = 0; //키변화 스위치
int tmp12 = 0; //키변화 스위치
int tmp21 = 0; //키변화 스위치
int tmp22 = 0; //키변화 스위치
float boost11 = 0;
float boost12 = 0;
float boost21 = 0;
float boost22 = 0;
float boost31 = 0;
float boost32 = 0;
float  sc11 =0.0f; //수영 색 1
float  sc12 = 1.0f; //수영 색 1
float  sc21 = 0.0f; //수영 색 1
float  sc22 = 1.0f; //수영 색 1
float  sc13 = 0.0f; //사이클 색 1
float  sc135 = 0.0f; //사이클 색 1
float  sc14 = 1.0f; //사이클 색 1
float  sc23 = 0.0f; //사이클 색 1
float  sc24 = 1.0f; //사이클 색 1
float  sc15 = 0.0f; //사이클 색 1
float  sc16 = 0.0f; //사이클 색 1
float  sc17 = 1.0f; //사이클 색 1
float  sc25 = 0.0f; //사이클 색 1
float  sc26 = 0.0f; //사이클 색 1
float  sc27 = 1.0f; //사이클 색 1
float boxf1;
float boxf2;
float boxf3;
float boxf4;
float boxf5;
float boxf6;//플로트형 박스 랜덤값
float res = 0;
float obj1SY =0; //수영1p이동 사용
float obj2SY =0; //수영2p이동 사용
float obj1CY = 0; //사이클1p이동 사용
float obj2CY = 0; //사이클2p이동 사용
float obj1RY = 0; //런닝1p이동 사용
float obj2RY = 0; //2p이동 사용
float run=0;

GLfloat xRot = 0.0f;  GLfloat yRot = 0.0f;
static int s11k=0; int s12k=0; int s21k=0; int s22k=0;


void renderBitmapCharacher(float x, float y, float z, void *font, char *string);
void MyReshape(GLsizei width, GLsizei height);

int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;

	void MyDisplay()
{		
		GLUquadricObj *pObj;
		pObj = gluNewQuadric(); //동적할당
		
		gluQuadricNormals(pObj, GLU_SMOOTH);
		glPushMatrix();
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.84f, 1.0f);
		glVertex3f(-0.9f, 0.9f, 0.0f);
		glVertex3f(-0.1f, 0.9f, 0.0f);
		glVertex3f(-0.1f, 0.1f, 0.0f);
		glVertex3f(-0.9f, 0.1f, 0.0f);
		glEnd();


		glBegin(GL_POLYGON);
		glColor3f(0.45f, 0.45f, 0.45f);
		glVertex3f(0.1f, 0.9f, 0.0f);
		glVertex3f(0.1f, 0.1f, 0.0f);
		glVertex3f(0.9f, 0.1f, 0.0f);
		glVertex3f(0.9f, 0.9f, 0.0f);
		glEnd(); //배경색2
		
		glBegin(GL_POLYGON);
		glColor3f(0.9, 0.0, 0.0);
		glVertex3f(-0.70f, 0.35f, 0.0f);
		glVertex3f(-0.30f, 0.35f, 0.0f);
		glVertex3f(-0.30f, 0.20f, 0.0f);
		glVertex3f(-0.70f, 0.20f, 0.0f);
		glEnd(); //시작버튼

		glColor3f(0.7, 0.6, 0.5);
		renderBitmapCharacher(-0.6, 0.25, 0, (void *)font, "Start");

		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.32f, 1.0f);
		glVertex3f(0.1f, 0.1f, 0.0f);	
		glVertex3f(0.9f, 0.1f, 0.0f);
		glVertex3f(0.7f, 0.9f, 0.0f);
		glVertex3f(0.3f, 0.9f, 0.0f);
		
		glEnd(); //수영장

		if(call1 ==0) {
			srand((unsigned)time(NULL));
			while (boxi1 < 4) {
				boxi1 = rand() % 9;
			}
			while (boxi2 < 4) {
				boxi2 = rand() % 9;
			}
			boxf1 = (float)boxi1 /(float) 10;
			boxf2 = (float)boxi2 / (float)10;
			
			call1++;
		}

		if (obj1SY + 0.35 > boxf1) {		//수영장 랜덤박스 이벤트
			sc11 = 0.32f;
			sc12 = 1.0f;

			if (eventc11 == 0) {	
				srand((unsigned)time(NULL));
				event11 = rand() % 3; //3가중 이벤트 하나 생성
				ans1 = event11;
				eventc11++;
				switch (ans1) {
				
				case 0:
				obj1SY = obj1SY/2; //거리 절반 
				printf("1픽: 온만큼 절반 뒤로가기!\n");
					break;
				case 1:
					 boost11 = 0.005; //가속도
					 printf("1픽: 부스터발동+0.005의 스윔실력!\n");
					 break;
				case 2:
					obj1SY = 0; //원점시작
					printf("1픽: 출발점으로 돌아가라\n");
					break;
				}

			}
		}

		
		if (obj2SY + 0.35 > boxf2) {		//수영장 랜덤박스 이벤트
			sc21 = 0.32f;
			sc22 = 1.0f;

			if (eventc12 == 0) {
				srand((unsigned)time(NULL));
				event12 = rand() % 3; //3가중 이벤트 하나 생성
				ans2 = event12;
				eventc12++;
				switch (ans2) {
				case 0:
					obj2SY = obj2SY / 2; //거리 절반 
					printf("2픽: 온만큼 절반 뒤로가기!\n");
					break;
				case 1:
					boost12 = 0.005; //가속도
					printf("2픽:부스터발동+0.05의 스윔실력\n");
					break;
				case 2:
					obj2SY = 0; //원점시작
					printf("2픽:출발점으로 돌아가라!\n");
					break;
				}

			}
		}

		glBegin(GL_POLYGON);
		glColor3f(0.0f, sc11, sc12);
		glVertex3f(0.3f, boxf1, 0.0f);
		glVertex3f(0.4f, boxf1, 0.0f);
		glVertex3f(0.4f, boxf1+0.1f, 0.0f);
		glVertex3f(0.3f, boxf1+0.1f, 0.0f);
		glEnd(); //1p랜덤박스


		glBegin(GL_POLYGON);
		glColor3f(0.0f, sc21, sc22);
		glVertex3f(0.6f, boxf2, 0.0f);
		glVertex3f(0.7f, boxf2, 0.0f);
		glVertex3f(0.7f, boxf2 + 0.1f, 0.0f);
		glVertex3f(0.6f, boxf2 + 0.1f, 0.0f);
		glEnd(); //2p랜덤박스

		glColor3f(1.0f, 0.93f, 0.7f);
		glTranslated(0.35f, 0.3f + obj1SY, 0.0f);
		glutSolidSphere(0.05f, 26, 13); // 수영 1p대가리
		glTranslated(-0.35f, -0.3 -obj1SY, 0.0f);
		
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f, 0.7f);
		glVertex3f(0.3f, 0.16f + obj1SY, 0.0f);
		glVertex3f(0.4f, 0.16f + obj1SY, 0.0f);
		glVertex3f(0.4f, 0.28f + obj1SY, 0.0f);
		glVertex3f(0.3f, 0.28f + obj1SY, 0.0f);
		glEnd(); //1p몸통

		glPushMatrix();
		glTranslated(0.29f, 0.25f + obj1SY, 0.0f);
		glRotated(s11k, 1.0f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.02f, 0.02f, 0.1f, 15, 15);
		glTranslated(-0.29f, -0.25f - obj1SY, 0.0f);
		glPopMatrix(); //1p왼팔

		glPushMatrix();
		glTranslated(0.41f, 0.25f + obj1SY, 0.0f);
		glRotated(-s12k, 1.0f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.02f, 0.02f, 0.1f, 15, 15);
		glTranslated(-0.41f, -0.25f - obj1SY, 0.0f);
		glPopMatrix(); //1p오른팔

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f, 0.7f);
		glVertex3f(0.3f, 0.16f + obj1SY, 0.0f);
		glVertex3f(0.3f, 0.13f + obj1SY, 0.0f);
		glVertex3f(0.33f, 0.13f + obj1SY, 0.0f);
		glVertex3f(0.33f, 0.16f + obj1SY, 0.0f);
		glEnd(); //1p왼달

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f, 0.7f);
		glVertex3f(0.4f, 0.16f + obj1SY, 0.0f);
		glVertex3f(0.4f, 0.13f + obj1SY, 0.0f);
		glVertex3f(0.37f, 0.13f + obj1SY, 0.0f);
		glVertex3f(0.37f, 0.16f + obj1SY, 0.0f);
		glEnd(); //1p오달

		glColor3f(1.0f, 0.93f, 0.7f);
		glTranslated(0.65f, 0.3f + obj2SY, 0.0f);
		glutSolidSphere(0.05f, 26, 13);				// 수영 2p대가리
		glTranslated(-0.65f, -0.3f - obj2SY, 0.0f);

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f, 0.7f);
		glVertex3f(0.6f, 0.16f + obj2SY, 0.0f);
		glVertex3f(0.7f, 0.16f + obj2SY, 0.0f);
		glVertex3f(0.7f, 0.28f + obj2SY, 0.0f);
		glVertex3f(0.6f, 0.28f + obj2SY, 0.0f);
		glEnd(); //2p몸통

		glPushMatrix();
		glTranslated(0.59f, 0.25f + obj2SY, 0.0f);
		glRotated(s21k, 1.0f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.02f, 0.02f, 0.1f, 15, 15);
		glTranslated(-0.62f, -0.25f - obj2SY, 0.0f);
		glPopMatrix(); //2p왼팔

		glPushMatrix();
		glTranslated(0.71f, 0.25f+ obj2SY, 0.0f);
		glRotated(-s22k, 1.0f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.02f, 0.02f, 0.1f, 15, 15);
		glTranslated(-0.71f, -0.25f - obj2SY, 0.0f);
		glPopMatrix(); //1p오른팔

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f, 0.7f);
		glVertex3f(0.6f, 0.16f + obj2SY, 0.0f);
		glVertex3f(0.7f, 0.16f + obj2SY, 0.0f);
		glVertex3f(0.7f, 0.28f + obj2SY, 0.0f);
		glVertex3f(0.6f, 0.28f + obj2SY, 0.0f);
		glEnd(); //2p몸통

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f, 0.7f);
		glVertex3f(0.6f, 0.16f + obj2SY, 0.0f);
		glVertex3f(0.6f, 0.13f + obj2SY, 0.0f);
		glVertex3f(0.63f, 0.13f + obj2SY, 0.0f);
		glVertex3f(0.63f, 0.16f + obj2SY, 0.0f);
		glEnd(); //2p왼달

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.93f + obj2SY, 0.7f);
		glVertex3f(0.7f, 0.16f + obj2SY, 0.0f);
		glVertex3f(0.7f, 0.13f + obj2SY, 0.0f);
		glVertex3f(0.67f, 0.13f + obj2SY, 0.0f);
		glVertex3f(0.67f, 0.16f + obj2SY, 0.0f);
		glEnd(); //2p오달

		glBegin(GL_POLYGON);
		glColor3f(0.52f, 0.89f, 0.49f);
		glVertex3f(-0.9f, -0.1f, 0.0f);
		glVertex3f(-0.9f, -0.9f, 0.0f);
		glVertex3f(-0.1f, -0.9f, 0.0f);
		glVertex3f(-0.1f, -0.1f, 0.0f);
		glEnd(); //배경색3

		glBegin(GL_POLYGON);
		glColor3f(0.45f, 0.45f, 0.45f);
		glVertex3f(-0.9f, -0.9f, 0.0f);
		glVertex3f(-0.1f, -0.9f, 0.0f);
		glVertex3f(-0.1f, -0.1f, 0.0f);
		glVertex3f(-0.3f, -0.1f, 0.0f);
		glVertex3f(-0.9f, -0.7f, 0.0f);
		glEnd(); //아스팔트

		glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-0.6f, -0.9f, 0.0f);
		glVertex3f(-0.55f, -0.9f, 0.0f);
		glVertex3f(-0.1f, -0.4f, 0.0f);
		glVertex3f(-0.1f, -0.35f, 0.0f);
		glEnd(); //중앙선

		glBegin(GL_LINE_LOOP); //틀3
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.1f, -0.9f, 0.0f);
		glVertex3f(-0.9f, -0.9f, 0.0f);
		glEnd();


		glPushMatrix();
		
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslated(-0.5f, 0.6f, 0.0f);
		glutSolidSphere(0.2f, 26, 13);	// 1컷 아이언맨 머리 테두리
		
		if (swc == 1) { glRotated(yRot, 0.0f, 1.0f, 0.0f);}
		else if (swc == 0) {
			glTranslated(0.5f, -0.6f, 0.0f);
			
			glBegin(GL_POLYGON);
			glColor3f(0.67, 0.94, 0.0);
			glVertex3f(-0.70f, 0.35f, 0.0f);
			glVertex3f(-0.30f, 0.35f, 0.0f);
			glVertex3f(-0.30f, 0.20f, 0.0f);
			glVertex3f(-0.70f, 0.20f, 0.0f);
			glEnd(); //시작버튼

			glColor3f(0.7, 0.6, 0.5);
			renderBitmapCharacher(-0.6, 0.25, 0, (void *)font, "GO");		
			if (sw1k != 2||3) {		//2(사이클) or3(육상)
				if (cnt == 0) {
					printf("첫 종목은 수영입니다.\n");
					cnt++; //1회성진행
				}
				sw1k = 1; // 1p수영시작
			}
			if (sw2k != 2 || 3) {
				sw2k = 1; // 2p수영시작
			}
			glTranslated(-0.5f, 0.6f, 0.0f);
		}
		
		glTranslated(0.5f, -0.6f, 0.0f); //원점변경
		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(-0.56f, 0.7f, 0.0f);
		glVertex3f(-0.56f, 0.74f, 0.0f);
		glVertex3f(-0.6f, 0.74f, 0.0f);
		glVertex3f(-0.6f, 0.7f, 0.0f);
		glVertex3f(-0.65f, 0.67f, 0.0f);
		glVertex3f(-0.6f, 0.45f, 0.0f);
		glVertex3f(-0.4f, 0.45f, 0.0f);
		glVertex3f(-0.35f, 0.67f, 0.0f);
		glVertex3f(-0.4f, 0.7f, 0.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(-0.4f, 0.74f, 0.0f);
		glVertex3f(-0.44f, 0.74f, 0.0f);
		glVertex3f(-0.44f, 0.7f, 0.0f);
		glVertex3f(-0.4f, 0.7f, 0.0f);
		glEnd();
		
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		
		glVertex3f(-0.56f, 0.7f, 0.0f);
		glVertex3f(-0.56f, 0.74f, 0.0f);
		glEnd();

		
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.56f, 0.74f, 0.0f);
		glVertex3f(-0.6f, 0.74f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.6f, 0.74f, 0.0f);
		glVertex3f(-0.6f, 0.7f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.6f, 0.7f, 0.0f);
		glVertex3f(-0.65f, 0.67f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.65f, 0.67f, 0.0f);
		glVertex3f(-0.6f, 0.45f, 0.0f);
		glEnd(); //왼대가리

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.6f, 0.45f, 0.0f);
		glVertex3f(-0.4f, 0.45f, 0.0f);
		glEnd();//왼아구창

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.4f, 0.45f, 0.0f);
		glVertex3f(-0.35f, 0.67f, 0.0f);
		glEnd(); //턱주가리

		
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.35f, 0.67f, 0.0f);
		glVertex3f(-0.4f, 0.7f, 0.0f); //오른대가리
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.4f, 0.7f, 0.0f); //오른관자
		glVertex3f(-0.4f, 0.74f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.4f, 0.74f, 0.0f);
		glVertex3f(-0.44f, 0.74f, 0.0f); //오른대가리머리
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.44f, 0.74f, 0.0f); //오른대가리
		glVertex3f(-0.44f, 0.7f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.44f, 0.7f, 0.0f);	
		glVertex3f(-0.56f, 0.7f, 0.0f); //아이언맨 테두리 끝
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.60f, 0.65f, 0.0f);
		glVertex3f(-0.57f, 0.60f, 0.0f);
		glVertex3f(-0.54f, 0.60f, 0.0f);
		glVertex3f(-0.50f, 0.65f, 0.0f);
		glEnd(); //아이언맨 오른눈

		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.50f, 0.65f, 0.0f);
		glVertex3f(-0.47f, 0.60f, 0.0f);
		glVertex3f(-0.44f, 0.60f, 0.0f);
		glVertex3f(-0.40f, 0.65f, 0.0f);
		glEnd(); //아이언맨 왼눈

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.60f, 0.65f, 0.0f);
		glVertex3f(-0.40f, 0.65f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.60f, 0.65f, 0.0f);
		glVertex3f(-0.57f, 0.60f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.57f, 0.60f, 0.0f);
		glVertex3f(-0.54f, 0.60f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.54f, 0.60f, 0.0f);
		glVertex3f(-0.50f, 0.65f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.50f, 0.65f, 0.0f);
		glVertex3f(-0.47f, 0.60f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.47f, 0.60f, 0.0f);
		glVertex3f(-0.44f, 0.60f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.44f, 0.60f, 0.0f);
		glVertex3f(-0.40f, 0.65f, 0.0f);
		glEnd(); //아이언맨 눈썹

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.52f, 0.49f, 0.0f);
		glVertex3f(-0.47f, 0.49f, 0.0f);
		glEnd();//아이언맨 입

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.52f, 0.49f, 0.0f);
		glVertex3f(-0.53f, 0.47f, 0.0f);
		glEnd();//오른썩소

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-0.47f, 0.49f, 0.0f);
		glVertex3f(-0.46f, 0.47f, 0.0f);
		glEnd();//왼썩소
		glPopMatrix();

		


		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.84f, 1.0f);
		glVertex3f(0.2f, -0.3f, 0.0f);
		glVertex3f(0.8f, -0.3f, 0.0f);
		glVertex3f(0.8f, -0.9f, 0.0f);
		glVertex3f(0.2f, -0.9f, 0.0f);
		glEnd(); //도로

		glBegin(GL_POLYGON);
		glColor3f(0.8f, 0.23f, 0.23f);
		glVertex3f(0.3f, -0.3f, 0.0f);
		glVertex3f(0.7f, -0.3f, 0.0f);
		glVertex3f(0.8f, -0.9f, 0.0f);
		glVertex3f(0.2f, -0.9f, 0.0f);
		glEnd(); //철봉 도로

		glColor3f(0.0f, 0.0f, .0f);

		if (call2 == 0) {
			
			srand((unsigned)time(NULL));
			while (boxi3 < 4) {
				boxi3 = rand() % 9;
			}
			while (boxi4 <1) {
				boxi4 = rand() % 4;
			}
			boxf3 = (float)boxi3 / (float)10;
			boxf4 = (float)boxi4 / (float)10;
			call2++;
		}
		if (obj1CY+0.32f > boxf3) {		//사이클 랜덤박스 이벤트
			sc13 = 0.45f;
			sc14 = 0.45f;
			sc135 = 0.45f;

			if (eventc21 == 0) {
				srand((unsigned)time(NULL));
				event21 = rand() % 3; //3가중 이벤트 하나 생성
				ans3 = event21;
				eventc21++;
				switch (ans3) {
			
				case 0:
					tmp11 = 1;
					break;
				case 1:
					boost11 = 0.005; //가속도
					printf("1픽: 부스터발동+0.005의 스윔실력!!\n");
					break;
				case 2:
					obj1CY = 0; //원점시작
					printf("1픽: 출발점으로 돌아가라!\n");
					break;
				}

			}
		}


		glBegin(GL_POLYGON);
		glColor3f(sc135, sc13, sc14);
		glVertex3f(- boxf3-0.05f, -boxf3-0.05f, 0.0f);
		glVertex3f(- boxf3 + 0.05f,- boxf3 - 0.05, 0.0f);
		glVertex3f( - boxf3 +0.05,  - boxf3 + 0.05f, 0.0f);
		glVertex3f( - boxf3 - 0.05, - boxf3 + 0.05f, 0.0f);
		glEnd();							 //1p 사이클 박스

		if (obj2CY-0.1f  > boxf4) {		//2p사이클 랜덤박스 이벤트
			sc23 = 0.45f;
			sc24 = 0.45f;

			if (eventc22 == 0) {
				srand((unsigned)time(NULL));
				event22 = rand() % 3; //3가중 이벤트 하나 생성
				ans4 = event22;
				eventc22++;
				switch (ans4) {
				case 0:
					tmp12 = 1;
					break;
				case 1:
					boost12 = 0.005; //가속도
					printf("2픽: 부스터발동+0.005의 스윔실력!!\n");
					break;
				case 2:
					obj2CY = 0; //원점시작
					printf("2픽: 출발점으로 돌아가라!\n");
					break;
				}

			}
		}

		glBegin(GL_POLYGON);
		glColor3f(sc23, sc23, sc24);
		glVertex3f(-boxf4 -0.2f, -boxf4 -0.55, 0.0f);
		glVertex3f(-boxf4 -0.3f, -boxf4 -0.55, 0.0f);
		glVertex3f(-boxf4 -0.3f, -boxf4 -0.65 , 0.0f);
		glVertex3f(-boxf4 -0.2f, -boxf4 -0.65, 0.0f);
		glEnd(); //2p랜덤박스

		glTranslated(-0.35f, -0.35f , 0.0f); //원점변경
		glColor3f(1.0f, 1.0f, 1.0f);

		glColor3f(0.0f, 0.7f, 0.8f);
		glPushMatrix(); 
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //핸들 척추 신경변경
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //핸들 척추 신경변경
		glTranslated(-obj1CY, -obj1CY, 0.0f);
		gluCylinder(pObj, 0.01f, 0.01f, 0.2f, 15, 15); //몸통
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();
		glTranslated(-0.13f, 0.13f, 0.0f); //퀵손위치 이동
		glColor3f(0.7f, 0.4f, 0.8f);
		glTranslated(-obj1CY + obj1CY / fix, -obj1CY + obj1CY / fix, 0.0f);
		gluCylinder(pObj, 0.0f, 0.01f, 0.01f, 26, 13); //퀵보드 손잡이
		glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);
		glTranslated(0.0f, 0.0f, -0.13f); //반대 손잡이 이동
		glTranslated(-obj1CY + obj1CY / fix, -obj1CY + obj1CY / fix, 0.0f);
		gluCylinder(pObj, 0.0f, 0.01f, 0.01f, 26, 13); //퀵보드 손잡이 
		glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);
		glTranslated(0.0f, 0.0f, 0.13f); //반대 손잡이 복귀
		glTranslated(0.13f, -0.13f, 0.0f); //퀵손위치 복귀

		glColor3f(0.0f, 0.0f, 0.0f);	
		glTranslated(-obj1CY + obj1CY / fix, -obj1CY + obj1CY / fix, 0.0f);
		glutSolidSphere(0.05, 26, 13);
		glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslated(-obj1CY + obj1CY / fix, -obj1CY + obj1CY / fix, 0.0f);
		glutSolidSphere(0.03, 26, 13);//1P앞바퀴
		glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);
		//printf("%f\n",obj1CY);
		glTranslated(0.15f, 0.15f, 0.0f);				//glTranslated(-0.2f, -0.2f, 0.0f); 현재까지
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslated(-obj1CY + obj1CY / fix, -obj1CY + obj1CY / fix, 0.0f);
		glutSolidSphere(0.05, 26, 13);
		glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);		
		glTranslated(-obj1CY+ obj1CY/ fix, -obj1CY + obj1CY / fix, 0.0f);
		glutSolidSphere(0.03, 26, 13);//1P뒷바퀴
		glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);																					//킥보드 이동
			
		glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0f - obj1CY + obj1CY / fix, 0.0f - obj1CY + obj1CY / fix, 0.0f);
		glVertex3f(-0.15f - obj1CY + obj1CY / fix, -0.15f - obj1CY + obj1CY / fix, 0.0f);
		glVertex3f(-0.169f - obj1CY + obj1CY / fix, -0.149f - obj1CY + obj1CY / fix, 0.0f);
		glVertex3f(-0.01f - obj1CY + obj1CY / fix, 0.01f - obj1CY + obj1CY / fix, 0.0f);
		glEnd();//바퀴연결부
		
		glTranslated(-0.08f, -0.08f, 0.0f); //안장아래 

		glColor3f(0.0f, 0.0f, 0.0f);
		glPushMatrix(); 
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //핸들 척추 신경변경
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //핸들 척추 신경변경
		glTranslated(-obj1CY, -obj1CY, 0.0f); 	
		gluCylinder(pObj, 0.01f, 0.01f, 0.08f, 15, 15); //안장철
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();
		
		glTranslated(-0.06f, 0.06f, 0.0f); //34 28
		glColor3f(1.0f, 1.0f, 1.0f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj1CY, -obj1CY, 0.0f); 	
		gluCylinder(pObj, 0.03f, 0.03f, 0.03f, 15, 15);  //안장
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.02f, 0.02f, 0.0f); // 36 20
		glColor3f(1.0f, 0.93f, 0.7f);

		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj1CY, -obj1CY, 0.0f); 	
		gluCylinder(pObj, 0.03f, 0.03f, 0.1f, 15, 15); //몸뚱이
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.02f, -0.02f, 0.0f); // 38 22
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj1CY, -obj1CY, 0.0f); 	
		gluCylinder(pObj, 0.03f, 0.03f, 0.03f, 15, 15); //허벅지
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();

		glTranslated(0.03f, -0.07f, 0.0f); // 35 29
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj1CY, -obj1CY, 0.0f); 
		gluCylinder(pObj, 0.01f, 0.01f, 0.1f, 15, 15); //종아리
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();

		glTranslated(0.00f, -0.02f, 0.0f); // 35 31
		glColor3f(1.0f, 1.0f, 0.0f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj1CY, -obj1CY, 0.0f); 
		gluCylinder(pObj, 0.015f, 0.015f, 0.03f, 15, 15); //허벅지	
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.08f, 0.1f, 0.0f); //43 21
		glColor3f(1.0f, 0.93f, 0.7f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj1CY, -obj1CY, 0.0f); 	
		gluCylinder(pObj, 0.03f, 0.03f, 0.03f, 15, 15); //허벅지
		glTranslated(obj1CY, obj1CY, 0.0f);
		glPopMatrix();

		glColor3f(1.0f, 0.93f, 0.7f);
		glTranslated(0.008f, 0.1f, 0.0f); //422 11
		glTranslated(-obj1CY + obj1CY / fix, -obj1CY + obj1CY / fix, 0.0f);
		glutSolidSphere(0.05f, 26, 13); // 														사이클 1p끝
			glTranslated(obj1CY - obj1CY / fix, obj1CY - obj1CY / fix, 0.0f);

		glTranslated(0.6f, -0.07f, 0.0f); //178 -18
		glColor3f(0.0f, 0.0f, .0f);
		glTranslated(-0.35f, -0.35f, 0.0f); //원점변경 -172 -53
		
		glColor3f(1.0f, 1.0f, 1.0f);
		glColor3f(0.0f, 0.7f, .8f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //핸들 척추 신경변경
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //핸들 척추 신경변경
		glTranslated(-obj2CY, -obj2CY, 0.0f); 	
		gluCylinder(pObj, 0.01f, 0.01f, 0.2f, 15, 15); //몸통
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();
		glTranslated(-0.13f, 0.13f, 0.0f); //퀵손위치 이동  -302 -40

		glColor3f(0.7f, 0.4f, 0.8f);
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);
		gluCylinder(pObj, 0.0f, 0.01f, 0.01f, 26, 13); //퀵보드 손잡이 
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		glTranslated(0.0f, 0.0f, -0.13f); //반대 손잡이 이동
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);
		gluCylinder(pObj, 0.0f, 0.01f, 0.01f, 26, 13); //퀵보드 손잡이
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		glTranslated(0.0f, 0.0f, 0.13f); //반대 손잡이 복귀
		glTranslated(0.13f, -0.13f, 0.0f); //퀵손위치 복귀 -172  -53
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);		
		glutSolidSphere(0.05, 26, 13);	
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);	
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);		
		glutSolidSphere(0.03, 26, 13);//1P앞바퀴
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		glTranslated(0.15f, 0.15f, 0.0f); //-022 -38

		glColor3f(0.0f, 0.0f, 0.0f);	
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);		
		glutSolidSphere(0.05, 26, 13);	
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);		
		glutSolidSphere(0.03, 26, 13);//1P뒷바퀴	
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		
		glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0f - obj2CY + obj2CY / fix, 0.0f - obj2CY + obj2CY / fix, 0.0f);
		glVertex3f(-0.15f - obj2CY + obj2CY / fix, -0.15f - obj2CY + obj2CY / fix, 0.0f);
		glVertex3f(-0.169f - obj2CY + obj2CY / fix, -0.149f - obj2CY + obj2CY / fix, 0.0f);
		glVertex3f(-0.01f - obj2CY + obj2CY / fix, 0.01f - obj2CY + obj2CY / fix, 0.0f);
		glEnd();//바퀴연결부

		glTranslated(-0.08f, -0.08f, 0.0f); //-102 -46

		glColor3f(0.0f, 0.0f, 0.0f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //핸들 척추 신경변경
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //핸들 척추 신경변경
		glTranslated(-obj2CY, -obj2CY, 0.0f); 	
		gluCylinder(pObj, 0.01f, 0.01f, 0.08f, 15, 15); //안장철
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.06f, 0.06f, 0.0f); // -0.162 -40

		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj2CY, -obj2CY, 0.0f); 
		gluCylinder(pObj, 0.03f, 0.03f, 0.03f, 15, 15);  //안장
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.02f, 0.02f, 0.0f); // -0.182 -0.38
		glColor3f(1.0f, 0.93f, 0.7f);

		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj2CY, -obj2CY, 0.0f); 
		gluCylinder(pObj, 0.03f, 0.03f, 0.1f, 15, 15); //몸뚱이	
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.02f, -0.02f, 0.0f); // -0.202 -0.40
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj2CY, -obj2CY, 0.0f); 
		gluCylinder(pObj, 0.03f, 0.03f, 0.03f, 15, 15); //허벅지
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glTranslated(0.03f, -0.07f, 0.0f); // -0.172 -0.47

		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj2CY, -obj2CY, 0.0f); 
		gluCylinder(pObj, 0.01f, 0.01f, 0.1f, 15, 15); //종아리	
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glTranslated(0.00f, -0.02f, 0.0f); // -172 -49
		glColor3f(1.0f, 1.0f, 0.0f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj2CY, -obj2CY, 0.0f); 	
		gluCylinder(pObj, 0.015f, 0.015f, 0.03f, 15, 15); //허벅지
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glTranslated(-0.08f, 0.1f, 0.0f); // -0.252 -0.39

		glColor3f(1.0f, 0.93f, 0.7f);
		glPushMatrix();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-45.0f, 0.0f, 1.0f, 0.0f); //
		glTranslated(-obj2CY, -obj2CY, 0.0f); 	
		gluCylinder(pObj, 0.03f, 0.03f, 0.03f, 15, 15); //허벅지
		glTranslated(obj2CY, obj2CY, 0.0f);
		glPopMatrix();

		glColor3f(1.0f, 0.93f, 0.7f);
		glTranslated(0.008f, 0.1f, 0.0f);
		glTranslated(-obj2CY + obj2CY / fix, -obj2CY + obj2CY / fix, 0.0f);		
		glutSolidSphere(0.05f, 26, 13); //												사이클 2p대가리
		glTranslated(obj2CY - obj2CY / fix, obj2CY - obj2CY / fix, 0.0f);
		glTranslated(0.244f, 0.29f, 0.0f); //3컷끝 원점복귀

		glBegin(GL_POLYGON);
		glColor3f(0.91f, 0.91f, 0.91f);
		glVertex3f(-1.0f, 0.1f, 0.0f);
		glVertex3f(0.0f, 0.1f, 0.0f);
		glVertex3f(0.0f, -0.1f, 0.0f);
		glVertex3f(-1.0f, -0.1f, 0.0f);
		glEnd(); //틀삭제

		glBegin(GL_POLYGON);
		glColor3f(0.91f, 0.91f, 0.91f);
		glVertex3f(-0.1f, 0.0f, 0.0f);
		glVertex3f(0.1f, 0.0f, 0.0f);
		glVertex3f(0.1f, -1.0f, 0.0f);
		glVertex3f(-0.1f, -1.0f, 0.0f);
		glEnd(); //틀삭제

		if (call3 == 0) {
			srand((unsigned)time(NULL));
			while (boxi5 < 5) {
				boxi5 = rand() % 8;
			}
			while (boxi6 < 5) {
				boxi6 = rand() % 8;
			}
			boxf5 = (float)boxi5 / (float)10;
			boxf6 = (float)boxi6 / (float)10;

			call3++;
		}


		if (obj1RY + 0.42f > boxf5) {		//사이클 랜덤박스 이벤트
			sc15 = 0.8f;
			sc16 = 0.23f;
			sc17 = 0.23f;


			if (eventc31 == 0) {
				srand((unsigned)time(NULL));
				event21 = rand() % 3; //3가중 이벤트 하나 생성
				ans5 = event31;
				eventc31++;
				switch (ans5) {
				case 0:
					tmp21 = 1;
					break;
				case 1:
					boost31 = 0.005; //가속도
					printf("1픽: 부스터발동+0.005의 스윔실력!");
					break;
				case 2:
					obj1RY = 0; //원점시작
					printf("1픽: 출발점으로 돌아가라");
					break;
				}

			}
		}

		glBegin(GL_POLYGON);
		glColor3f(sc15, sc16, sc17);
		glVertex3f(0.35f, -boxf5, 0.0f);
		glVertex3f(0.45f, -boxf5, 0.0f);
		glVertex3f(0.45f, -boxf5 - 0.1f, 0.0f);
		glVertex3f(0.35f, -boxf5- 0.1f, 0.0f);
		glEnd(); //런1p랜덤박스

		if (obj2RY+0.5f   > boxf6) {		//2p런 랜덤박스 이벤트
			sc25 = 0.8f;
			sc26 = 0.23f;
			sc27 = 0.23f;

			if (eventc32 == 0) {
				srand((unsigned)time(NULL));
				event32 = rand() % 3; //3가중 이벤트 하나 생성
				ans6 = event32;
				eventc32++;
				switch (ans6) {
				case 0:
					tmp22 = 1;
					break;
				case 1:
					boost32 = 0.005; //가속도
					printf("2픽: 부스터발동+0.005의 스윔실력!!\n");
					break;
				case 2:
					obj2RY = 0; //원점시작
					printf("2픽: 출발점으로 돌아가라!\n");
					break;
				}

			}
		}
		glBegin(GL_POLYGON);
		glColor3f(sc25, sc26, sc27);
		glVertex3f(0.55f, -boxf6, 0.0f);
		glVertex3f(0.65f, -boxf6, 0.0f);
		glVertex3f(0.65f, -boxf6 + 0.1f, 0.0f);
		glVertex3f(0.55f, -boxf6 + 0.1f, 0.0f);
		glEnd(); //2p랜덤박스


		glPushMatrix();
		glColor3f(1.0f, 0.93f, 0.7f);
		glTranslated(0.4f, -0.2f-obj1RY, 0.0f);
		glutSolidSphere(0.05f, 26, 13); // 수영 1p대가리
		glTranslated(-0.4f, 0.2f + obj1RY, 0.0f); //오오류 
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(0.4f, -0.34f - obj1RY, 0.0f); //0.4 -0.34
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		gluCylinder(pObj, 0.04f, 0.04f, 0.1f, 15, 15); //몸통
		glTranslated(-0.4f, 0.34f + obj1RY, 0.0f); //0.4 -0.34
		glPopMatrix();

	
		glPushMatrix();
		glTranslated(0.38f, -0.34f - obj1RY, 0.0f); //0.38 -0.39 
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-180.0f, 0.0f, 1.0f, 0.0f); //					다리픽스
		gluCylinder(pObj, 0.015f, 0.015f, 0.05f-run, 15, 15); //우다리
		glTranslated(-0.38f, 0.34f + obj1RY, 0.0f); //0.38 -0.39 
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.42f, -0.34f - obj1RY, 0.0f); //0.42 -0.39
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-180.0f, 0.0f, 1.0f, 0.0f); //
		gluCylinder(pObj, 0.015f, 0.015f, 0.02f + run, 15, 15); //좌다리
		glTranslated(-0.42f, 0.39f + obj1RY, 0.0f); //0.38 -0.39 
		glPopMatrix();
		
		glPushMatrix();
		glTranslated(0.42f, -0.28f - obj1RY, 0.0f); // 0.42 -0.28
		glColor3f(1.0f, 0.0f, 1.0f);
		glutSolidSphere(0.015f, 26, 13); //	주먹
		glTranslated(-0.42f, 0.28f + obj1RY, 0.0f); // 0.42 -0.28
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.38f, -0.28f - obj1RY, 0.0f); //0.38 -0.28
		glutSolidSphere(0.015f, 26, 13); 
		glTranslated(-0.38f, 0.28f + obj1RY, 0.0f); //0.38 -0.28
		glPopMatrix();	 //런 1p끝

		glTranslated(0.2f, 0.0f, 0.0f); //0.38 -0.28

		glPushMatrix();
		glColor3f(1.0f, 0.93f, 0.7f);
		glTranslated(0.4f, -0.2f - obj2RY, 0.0f);
		glutSolidSphere(0.05f, 26, 13); // 달리기 2p대가리
		glTranslated(-0.4f, 0.2f + obj2RY, 0.0f); //오오류 
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.4f, -0.34f - obj2RY, 0.0f); //0.4 -0.34
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		gluCylinder(pObj, 0.04f, 0.04f, 0.1f, 15, 15); //몸통
		glTranslated(-0.4f, 0.34f + obj2RY, 0.0f); //0.4 -0.34
		glPopMatrix();


		glPushMatrix();
		glTranslated(0.38f, -0.34f - obj2RY, 0.0f); //0.38 -0.39 
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-180.0f, 0.0f, 1.0f, 0.0f); //
		gluCylinder(pObj, 0.015f, 0.015f, 0.02f+ run, 15, 15); //우다리
		glTranslated(-0.38f, 0.34f + obj2RY, 0.0f); //0.38 -0.39 
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.42f, -0.34f - obj2RY, 0.0f); //0.42 -0.39
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f); //
		glRotated(-180.0f, 0.0f, 1.0f, 0.0f); //
		gluCylinder(pObj, 0.015f, 0.015f, 0.05f - run, 15, 15); //좌다리
		glTranslated(-0.42f, 0.34f + obj2RY, 0.0f); //0.38 -0.39 
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.42f, -0.28f - obj2RY, 0.0f); // 0.42 -0.28
		glColor3f(1.0f, 0.0f, 1.0f);
		glutSolidSphere(0.015f, 26, 13); //	주먹
		glTranslated(-0.42f, 0.28f + obj2RY, 0.0f); // 0.42 -0.28
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.38f, -0.28f - obj2RY, 0.0f); //0.38 -0.28
		glutSolidSphere(0.015f, 26, 13);
		glTranslated(-0.38f, 0.28f + obj2RY, 0.0f); //0.38 -0.28
		glPopMatrix();
		glTranslated(-0.2f, 0.0f, 0.0f); //0.38 -0.28				 //런 2p끝


	glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.1f, -0.1f, 0.0f);
		glVertex3f(0.1f, -0.9f, 0.0f);
		glVertex3f(0.2f, -0.9f, 0.0f);
		glVertex3f(0.2f, -0.3f, 0.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glVertex3f(0.1f, -0.1f, 0.0f);
		glVertex3f(0.2f, -0.3f, 0.0f);
		glVertex3f(0.8f, -0.3f, 0.0f);
		glVertex3f(0.9f, -0.1f, 0.0f);
		glEnd(); //철봉 

		glBegin(GL_POLYGON);
		glVertex3f(0.9f, -0.1f, 0.0f);
		glVertex3f(0.8f, -0.3f, 0.0f);
		glVertex3f(0.8f, -0.9f, 0.0f);
		glVertex3f(0.9f, -0.9f, 0.0f);
		glEnd(); //철봉 
		
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.73f, 0.0f);
		glVertex3f(0.2f, -0.9f, 0.0f);
		glVertex3f(0.2f, -0.8f, 0.0f);
		glVertex3f(0.8f, -0.8f, 0.0f);
		glVertex3f(0.8f, -0.9f, 0.0f);
		glEnd(); //피니쉬 선
		renderBitmapCharacher(0.38, -0.88, 0, (void *)font, "Finish");///4컷완료 

		glBegin(GL_LINE_LOOP); //틀1
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.9f, 0.9f, 0.0f);
		glVertex3f(-0.1f, 0.9f, 0.0f);
		glEnd();


		glBegin(GL_LINE_LOOP); //틀1
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.1f, 0.9f, 0.0f);
		glVertex3f(-0.1f, 0.1f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀1
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.9f, 0.1f, 0.0f);
		glVertex3f(-0.1f, 0.1f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀1
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.9f, 0.1f, 0.0f);
		glVertex3f(-0.9f, 0.9f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀2
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.9f, 0.9f, 0.0f);
		glVertex3f(0.1f, 0.9f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀2
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.1f, 0.9f, 0.0f);
		glVertex3f(0.1f, 0.1f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀2
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.9f, 0.9f, 0.0f);
		glVertex3f(0.9f, 0.1f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀2
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.9f, 0.1f, 0.0f);
		glVertex3f(0.1f, 0.1f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀3
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.9f, -0.1f, 0.0f);
		glVertex3f(-0.9f, -0.9f, 0.0f);
		glEnd();


		glBegin(GL_LINE_LOOP); //틀3
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.9f, -0.1f, 0.0f);
		glVertex3f(-0.1f, -0.1f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀3
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.1f, -0.1f, 0.0f);
		glVertex3f(-0.1f, -0.9f, 0.0f);
		glEnd();


		glBegin(GL_LINE_LOOP); //틀4
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.1f, -0.1f, 0.0f);
		glVertex3f(0.9f, -0.1f, 0.0f);
		glEnd();


		glBegin(GL_LINE_LOOP); //틀4
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.9f, -0.1f, 0.0f);
		glVertex3f(0.9f, -0.9f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀4
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.9f, -0.9f, 0.0f);
		glVertex3f(0.1f, -0.9f, 0.0f);
		glEnd();

		glBegin(GL_LINE_LOOP); //틀4
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.1f, -0.9f, 0.0f);
		glVertex3f(0.1f, -0.1f, 0.0f);
		glEnd();

		if (win == 1) {
			renderBitmapCharacher(0.3, -0.25, 0, (void *)font, "1P Win");
			sw2k = 5;
		}
		else if (win == 2) {
			renderBitmapCharacher(0.3, -0.25, 0, (void *)font, "2P Win");
			sw1k = 5;
		}
		glutSwapBuffers();
	}

	void MyReshape(GLsizei width, GLsizei height)
	{
		if (height == 0) height = 1;                // 0으로 나누는 것 방지
		GLfloat aspect = (GLfloat)width / (GLfloat)height;//변경된 윈도우크기로 viewport를 설정한다.
		balance =aspect;
		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);  //뒤에 오는 계산들은 Projection matrix에 영향을 주도록 설정
		glLoadIdentity();             //projection matrix 초기화

		//gluPerspective(45.0, aspect,1.0, 4);
									  if (width >= height) {
			// aspect >= 1 이면, height를 [-1,1]로 설정하고 width는 [-1*aspect, 1*aspect]로 설정한다.
			// left, right, top, bottom
			gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
		}
		else {
			// aspect < 1이면, width를 [-1,1]로 설정하고 height를  [-1/aspect, 1/aspect]로 설정한다.
			gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
		}
		
		//gluPerspective(60.0f, aspect, 1.0, 10.0);
		//뒤에 오는 계산들은 Modelview Matrix에 영향을 주도록 설정한다. 

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity(); //Modelview matrix 초기화
	}
	

	void MyKeyboard(unsigned char KeyPressed, int X, int Y)
	{if (tmp11 == 1) {
		float tmpp = 0;
		tmpp = obj1CY;
		obj1CY = obj2CY;
		obj2CY = tmpp;

			printf("1p의 위치변환기 작동!\n");
			tmp11++;
		}

	if (tmp12 == 1) {
		float tmpp = 0;
		tmpp = obj2CY;
		obj2CY = obj1CY;
		obj1CY = tmpp;

		printf("2p의 위치변환기 작동!\n");
		tmp12++;
	}

	 if (tmp21 == 1) {
		float tmpp = 0;
		tmpp = obj1RY;
		obj1RY = obj2RY;
		obj2RY = tmpp;

		printf("1p의 위치변환기 작동!\n");
		tmp21++;
	}

	if (tmp22 == 1) {
		float tmpp = 0;
		tmpp = obj2RY;
		obj2RY = obj1RY;
		obj1RY = tmpp;
		printf("2p의 위치변환기 작동\n");
		tmp22++;
	}

		keyChk = KeyPressed;
		if (sw1k == 1) {
				if(keyChk=='a') {
					if (obj1SY <= 0.546997) {
						s11k = (s11k + 5) % 360;
						s12k = (s12k + 5) % 360;
						obj1SY += 0.006+ boost11;
						//printf("%f", obj1SY);
					}

					else  {
						if (cnt11 == 0) {
							printf("----------------------------------------------------------------------------------\n");
							printf("1p선수! 사이클로 넘어갑니다.\n");
							
							cnt11++;
						}sw1k = 2;
						
					}
				}
			}
	
		if (sw1k == 2) {
			switch (keyChk) {
				case'a':
					
				if (obj1CY <= 0.702) {
					obj1CY += 0.006 + boost21;
					}
				else {
					if (cnt21 == 0) {
						printf("----------------------------------------------------------------------------------\n");
						printf("마지막 육상을 달리는1p!\n");
						cnt21++;
					}
						sw1k = 3;
					}
				
			}
		}

		if (sw1k == 3) {
			switch (keyChk) {
			case'a':
				if (obj1RY <= 0.51) {
					obj1RY += 0.006+ boost31;
				}
				else {
					if (cnt31 == 0) {
						printf("----------------------------------------------------------------------------------\n");
						printf("1p가 이겼습니다!\n");
						cnt31++;
					}

					win = 1;
				}

			}
		}
	
		if (keyChk == 27)//esc는 27  
		{
			exit(0); //프로그램탈출
		}

		else if (keyChk == 13) { //달생성
			if (enter == 0) { 
				swc = 1;
				enter++; }
			
		}
	
		glutPostRedisplay();
	}

	void MySpecial(int key, int x, int y)
	{
		keyChk2 = key;
		if (sw2k == 1) {
			if (keyChk2 == GLUT_KEY_UP) {
				if (obj2SY <= 0.546997) {
					s21k = (s21k + 5) % 360;
					s22k = (s22k + 5) % 360;
					obj2SY += 0.006 + boost12;
				}

				else {
					if (cnt12 == 0) {
						printf("----------------------------------------------------------------------------------\n");
						printf("2p선수! 사이클로 넘어갑니다.\n");
						cnt12++;
					}
					sw2k = 2;
				}
			}
		}

		if (sw2k == 2) {
			switch (keyChk2) {
			case GLUT_KEY_UP:
				if (obj2CY <= 0.702) {
					obj2CY += 0.006 + boost22;
				}
				else {
					if (cnt22 == 0) {
						printf("----------------------------------------------------------------------------------\n");
						printf("마지막 육상을 달리는2p!\n");
						cnt22++;
					}
					sw2k = 3;
				}
			}
		}

		if (sw2k == 3) {
			switch (keyChk2) {
			case GLUT_KEY_UP:
				if (obj2RY <= 0.51) {
				obj2RY += 0.006 + boost32;
				}
				else {
					if (cnt32 == 0) {
						printf("----------------------------------------------------------------------------------\n");
						printf("2p가 이겼습니다!\n");
						cnt32++;
					}
					win = 2;
				
				}

			}
		}

		glutPostRedisplay();
	}

	void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y)
	{
/*		float base = 1;
		printf("%f ", balance);
		
		while (base < balance) {
			base += 0.3;
			xcount += 2;
			printf("엑스(%d)", xcount);
			
		} TopLeftX = X*xcount-2; xcount = 0;*/

		if (Button == GLUT_LEFT_BUTTON) {
				TopLeftX = X;
				TopLeftY = Y;
		}
	}

	void MyMouseMove(GLint X, GLint Y)
	{

	}

	void MyIdle()
	{

	}

	void MyTimer(int value)
	{
		if (175 >= TopLeftX&&TopLeftX >= 75  && 200 >= TopLeftY&&TopLeftY >= 163) {
			swc =1;
			}


		if (swc == 1) {  
			if (runn == 1) {
				yRot += 0.8;
				if (yRot >= 169) {
					swc = 0;
				}
			}
		}

		if (rswc == 1) {  //다리제어
				run += 0.001;
				if (run >= 0.03) {
					rswc = 0;
				}
			}
			else if (rswc == 0) {
				run -= 0.01;
				if (run <= 0.0) {
					rswc = 1;
				}
		}
		

		glutPostRedisplay(); //화면출력

		glutTimerFunc(10, MyTimer, 1);
	}

	void MenuProc(int entryID)
	{

	}

	void MenuMakeFunc()
	{

	}

	void MenuFunc()
	{

	}

	void initFunc() {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.91, 0.91, 0.91, 0.0);
	
	}

	void renderBitmapCharacher(float x, float y, float z, void *font, char *string)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		char *c;
		glRasterPos2f(x, y);
		for (c = string; *c != '\0'; c++) {
			glutBitmapCharacter(font, *c);
		}
	}

	int main(int argc, char** argv) {
		glutInit(&argc, argv);           // 운영체제를 초기화 시키며 연결
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(WIDTH, HEIGHT);  // 실행화면 (Monitor) 크기
		glutInitWindowPosition(0, 0);  // 모니터의 최 상단 좌측이 (0,0) 프로그램이 시작할 위치
		glutCreateWindow("철인 3종경기"); // 제목표시줄에 나타낼 문구

		glutDisplayFunc(MyDisplay);
		//glutFullScreen();
		glutReshapeFunc(MyReshape);// 창화면의 크기조절 가능
		glutKeyboardFunc(MyKeyboard); // F1~f12 및 Insert등의 특수키
		glutSpecialFunc(MySpecial);
		glutMouseFunc(MyMouseClick);
		//glutMotionFunc(MyMouseMove);
		//glutIdleFunc(MyIdle); //CPU가 쉬는 시간에 나타나는 불규칙한 함수 (like 화면보호기)
		 glutTimerFunc(10, MyTimer, 1); // 1000 = 1초
	//	glutTimerFunc(10, MyTimer2, 2); // 1000 = 1초
		initFunc();
	//	MenuMakeFunc();
		glutMainLoop(); // 콜백함수를 유지시키기 위한 명령
		return 0;
	}