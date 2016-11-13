#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h> 
#include "sio_client.h"

#define SINGLE_PLAY 1
#define MULTI_PLAY 2
#define SERVER_ADDRESS "http://192.168.0.7:3000"
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

using namespace sio;
using namespace std;

<<<<<<< HEAD
//함수
void initial();//사용자 보드 초기치 설정
void cp_initial();//컴퓨터의 보드 초기치 설정
void position();//사용자의 배 위치 오직 수평으로 그리고 수직으로
void cp_position();//65=항공모함(aircraft carrier), 66=전함(battleship), 68=구축함(destroyer), 83=잠수함(submarine), 80=초계정(patrol boat)

void multi_play();//방에 참가되어 멀티플레이 게임 시작 
void print_board();//사용자의 보드 출력
void cp_print_board();//컴퓨터의 보드 출력
void attack();//사용자의 공격
void cp_attack();//컴퓨터의 공격. 120=hit, 46=miss
int attack_check(int row, int column);//확인한다 지점을 공격하였을경우, 놓친경우 또는 컴퓨터의 새로운 지점  checks if the point is attacked, missed or new from the pc's board (새로운지점은 뭐죠?)
int cp_attack_check(int row, int column);//확인한다 지점을 공격하였을경우, 놓친경우 또는 사용자의 새로운 보드??checks if the point is attacked, missed or new from the player's board
int rand_num(int high); //파라미터값보다 낮은 랜덤함수
int victory_check();//사용자가 이겼는지 확인
int cp_victory_check();//컴퓨터가 이겼는지 확인
=======
//�븿�닔
void initial();//�궗�슜�옄 蹂대뱶 珥덇린移� �꽕�젙
void cp_initial();//而댄벂�꽣�쓽 蹂대뱶 珥덇린移� �꽕�젙
void position();//�궗�슜�옄�쓽 諛� �쐞移� �삤吏� �닔�룊�쑝濡� 洹몃━怨� �닔吏곸쑝濡�
void cp_position();//65=�빆怨듬え�븿(aircraft carrier), 66=�쟾�븿(battleship), 68=援ъ텞�븿(destroyer), 83=�옞�닔�븿(submarine), 80=珥덇퀎�젙(patrol boat)

void print_board();//�궗�슜�옄�쓽 蹂대뱶 異쒕젰
void cp_print_board();//而댄벂�꽣�쓽 蹂대뱶 異쒕젰
void attack();//�궗�슜�옄�쓽 怨듦꺽
void cp_attack();//而댄벂�꽣�쓽 怨듦꺽. 120=hit, 46=miss
int attack_check(int row, int column);//�솗�씤�븳�떎 吏��젏�쓣 怨듦꺽�븯����쓣寃쎌슦, �넃移쒓꼍�슦 �삉�뒗 而댄벂�꽣�쓽 �깉濡쒖슫 吏��젏  checks if the point is attacked, missed or new from the pc's board (�깉濡쒖슫吏��젏��� 萸먯짛?)
int cp_attack_check(int row, int column);//�솗�씤�븳�떎 吏��젏�쓣 怨듦꺽�븯����쓣寃쎌슦, �넃移쒓꼍�슦 �삉�뒗 �궗�슜�옄�쓽 �깉濡쒖슫 蹂대뱶??checks if the point is attacked, missed or new from the player's board
int rand_num(int high); //�뙆�씪誘명꽣媛믩낫�떎 �궙��� �옖�뜡�븿�닔
int victory_check();//�궗�슜�옄媛� �씠寃쇰뒗吏� �솗�씤
int cp_victory_check();//而댄벂�꽣媛� �씠寃쇰뒗吏� �솗�씤
>>>>>>> refs/remotes/KimHyeongSeon/master
void ship_coordinates();//goes through the board and records the player's ship coordinates
int distance_check(int a, int b, int num);//�솗�씤�븳�떎 蹂댄듃�쓽 �쐞移섍�� �쑀�슚�븳吏� 留욎쑝硫� 1, �븘�땲硫� 0 
void textcolor(int foreground, int background); //�뀓�뒪�듃 而щ윭 蹂�寃� �븿�닔
										  //�쟾�뿭�븿�닔
int board[10][10];
int cp_board[10][10];
int A[5][2];
int B[4][2];
int D[3][2];
int S[3][2];
int P[2][2];
int HIT = 0, row, column;
char SHIP;
char state[6];//而댄벂�꽣媛� 怨듦꺽�븯嫄곕굹 �넃移졖떷� 留먰븳�떎.
int multiPlayCheck;
string roomIndex;// 멀티플레이 접속한 방의 인덱스
sio::client h; // 멀티플레이에 쓰이는 socket.io 클라이언트.

int main()
{
	textcolor(YELLOW, BLACK);
	printf("\n\n\n\n\n\n");
	printf("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf("\n\n\n\n");
	textcolor(WHITE, BLACK);
<<<<<<< HEAD

	printf("1. 싱글 플레이 \n2. 멀티 플레이\n3. 정보\n");
	printf("입력 : ");
	scanf("%d", &multiPlayCheck); // 싱글플레이, 멀티플레이 선택 

	if (multiPlayCheck == SINGLE_PLAY) {  // 싱글플레이일경우
=======
	printf("1. �떛湲� �뵆�젅�씠 \n2. 硫��떚 �뵆�젅�씠");
	scanf("%d", &multiPlayCheck); // �떛湲��뵆�젅�씠, 硫��떚�뵆�젅�씠 �꽑�깮 
	
	if (multiPlayCheck == SINGLE_PLAY) {  // �떛湲��뵆�젅�씠�씪寃쎌슦
>>>>>>> refs/remotes/KimHyeongSeon/master
		int turn_count = 1;
		//player
		initial();
		position();
		ship_coordinates();
		//pc
		cp_initial();
		cp_position();
		system("cls");
		while (1)
		{
			//player's turn        
			printf("�궗�슜�옄�쓽 �꽩 %d:\n\n", turn_count);
			cp_print_board();
			attack();
			if (victory_check() == 0)    //�궓��� 諛곌�� �뾾�굹 �솗�씤
			{
				break;
			}

			//cp's turn
			cp_attack();
			system("cls");
			printf("而댄벂�꽣�쓽 �꽩 %d: (%d,%d) %s \n\n", turn_count, (row + 1), (column + 1), state);
			print_board();
			if (cp_victory_check() == 0)      // �궓��� 諛곌�� �뾾�굹 �솗�씤
			{
				break;
			}
			turn_count++;
		}
		if (victory_check() == 0)
		{
			printf("\nYou won!! Congratulations!\n");
			system("pause");
		}
		else if (cp_victory_check() == 0)
		{
			printf("\nYou lost! Good luck next time!\n");
			system("pause");
		}
	}
	else if (multiPlayCheck == MULTI_PLAY) // 멀티플레이일경우
	{
		int eventFlag = 0;

		h.connect(SERVER_ADDRESS);


		Sleep(250); // TODO 이부분 접속시 이벤트 발생처리로 변경해야함. https://github.com/socketio/socket.io-client-cpp/blob/master/API.md

		h.socket()->on("GetRoomListRes", [&](sio::event& ev)  // 방목록 가져오기 콜백 이벤트
		{

			cout << ev.get_messages()[0]->get_string(); // 방명단 출력

			cout << "\n 접속하실 방의 번호를 입력해주세요.";
			getline(cin, roomIndex);
			std::getline(cin, roomIndex);

			h.socket()->on("JoinRoom" + h.get_sessionid(), [&](sio::event& ev)  // 방목록 가져오기 콜백 이벤트
			{
				cout << "\n 게임을 시작합니다.";
				multi_play();
			});

			h.socket()->emit("JoinRoom", roomIndex);

		});

		int flag;
<<<<<<< HEAD

		printf("1. 방목록 가져오기 및 접속\n2. 방 생성하기\n");
		printf("입력 : ");
=======
		printf("1. 諛⑸ぉ濡� 媛��졇�삤湲�\n2. 諛� �깮�꽦�븯湲�");
>>>>>>> refs/remotes/KimHyeongSeon/master
		scanf("%d", &flag);

		if (flag == 1) {
			h.socket()->emit("GetRoomList");
		}
		else if (flag == 2)
		{
			string roomName; // 문자열 방이름
			printf("생성할 방의 이름을 입력하시오.\n");
			printf("입력 : ");
			getline(cin, roomName);
			std::getline(cin, roomName);

			h.socket()->on("JoinRoom" + h.get_sessionid(), [&](sio::event& ev)
			{
				roomIndex = ev.get_messages()[0]->get_string();
				cout << "\n 상대방이 접속하여 게임을 시작합니다.";
				multi_play();
			});

			h.socket()->emit("CreateRoom", roomName); // 서버에 통신.
			
			cout << "상대방이 접속할때까지 기다리십시오.";
		}

		while (true) {
			Sleep(200); // 리소스 부하 방지
		}
		
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void multi_play()
{
	initial();
	cp_initial();
	position();
	
	//TODO h.socket()->on("공격및대기이벤트"); 추가 해야함
	h.socket()->emit("SetPositionDone", roomIndex);
	cout << "상대방의 전함배치를 기다려주세요.";

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
int victory_check()
{
	int i, j, boats_left = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (cp_board[i][j] == 65 || cp_board[i][j] == 66 || cp_board[i][j] == 68 || cp_board[i][j] == 83 || cp_board[i][j] == 80)
			{
				boats_left += 1;
			}

		}
	}
	return boats_left;//�궓��� 諛곌�� �뾾�쑝硫� return 0;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////

int cp_victory_check()
{
	int i, j, boats_left = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 65 || board[i][j] == 66 || board[i][j] == 68 || board[i][j] == 83 || board[i][j] == 80)
			{
				boats_left += 1;
			}
		}
	}
	return boats_left;  //�궓��� 諛곌�� �뾾�쑝硫� return 0;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void initial()    //�궗�슜�옄 蹂대뱶 珥덇린移� �꽕�젙
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			board[i][j] = 126;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void cp_initial()     //而댄벂�꽣 蹂대뱶 珥덇린移� �꽕�젙
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cp_board[i][j] = 126;
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void print_board()
{
	int i, j, k;
	for (k = 0; k < 11; k++)
	{
		if (k == 0)
		{
			printf("   ");
		}
		else
		{
			printf("%3d", k);
		}

	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d", (i + 1));
		for (j = 0; j < 10; j++)
		{
			printf("%3c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void cp_print_board()
{
	int i, j, k;
	for (k = 0; k < 11; k++)
	{
		if (k == 0)
		{
			printf("   ");
		}
		else
		{
			printf("%3d", k);
		}
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%3d", (i + 1));
		for (j = 0; j < 10; j++)
		{
			switch (cp_board[i][j])
			{
			case 65:      //65 = �빆怨듬え�븿(aircraft carrier) 
			case 66:      //66 = �쟾�븿(battleship)
			case 68:      //68 = 援ъ텞�븿(destroyer)
			case 83:      //83 = �옞�닔�븿(submarine)
			case 80:      //80 = 珥덇퀎�젙(patrol boat)
				printf("%3c", 126);
				break;
			case 120:     //????
			case 126:     //????
			case 46:      //????
				printf("%3c", cp_board[i][j]);
				break;
			}
		}
		printf("\n");
	}
	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

int distance_check(int a, int b, int num)
{
	int temp;
	if (b > a)       //a媛� �빆�긽 �겕�떎 洹몃옒�꽌 b媛� �뜑 而ㅼ��硫� �옄由щ�� 諛붽씔�떎.
	{
		temp = b;
		b = a;
		a = temp;
	}
	if ((a - b) == (num - 1))
	{
		return 1;    //returns 1 if the value is ok
	}
	else
	{
		return 0;   //returns 0 if the value is not ok
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void position()
{
	int column, row, column2, row2, i, found, dist1, dist2;

	///////////////Aircraft carrier 65 �빆怨듬え�븿
	system("cls");
	printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
	print_board();
	do
	{
		printf("�빆怨듬え�븿 5���瑜� �븳以꾨줈 諛곗튂�빐二쇱꽭�슂. \n�떆�옉醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂 \n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row);
		} while (row < 1 || row>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column);
		} while (column < 1 || column>10);

		printf("諛곗튂媛� �걹�굹�뒗 醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row2);
		} while (row2 < 1 || row2>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column2);
		} while (column2 < 1 || column2>10);

		dist1 = distance_check(row, row2, 5);//vertical �닔吏�
		dist2 = distance_check(column, column2, 5);//horizontal  �닔�룊
		found = 0;
		if (dist1 == 1)    //諛곌�� �닔吏곸쑝濡� 諛곗뿴�릺�뿬�엳�떎硫� if the ship is placed vertically
		{
			if (row > row2)
			{
				for (i = 0; i < 5; i++)
				{
					if (board[row - 1 - i][column - 1] != 126)
					{
						found++;
					}
				}
			}
			else if (row2 > row)
			{
				for (i = 0; i < 5; i++)
				{
					if (board[row - 1 + i][column - 1] != 126)
					{
						found++;
					}
				}
			}
		}
		else if (dist2 == 1) //諛곌�� �닔�룊�쑝濡� 諛곗튂�릺�뿬�엳�떎硫�  if the ship is placed horizontally
		{
			if (column > column2)
			{
				for (i = 0; i < 5; i++)
				{
					if (board[row - 1][column - 1 - i] != 126)
					{
						found++;
					}
				}
			}
			else if (column2 > column)
			{
				for (i = 0; i < 5; i++)
				{
					if (board[row - 1][column - 1 + i] != 126)
					{
						found++;
					}
				}
			}
		}
		if ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0)
		{
			system("cls");
			printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
			print_board();
			printf("醫뚰몴瑜� �떎�떆 �엯�젰�빐二쇱꽭�슂\n\n");
		}
	} while ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0);

	if (dist1 == 1) //諛곌�� �닔吏곸쑝濡� 諛곗튂 �릺�뼱�엳�떎硫� if the ship is placed vertically
	{
		if (row > row2)
		{
			for (i = 0; i < 5; i++)
			{
				board[row - 1 - i][column - 1] = 65;
			}
		}
		else if (row2 > row)
		{
			for (i = 0; i < 5; i++)
			{
				board[row - 1 + i][column - 1] = 65;
			}
		}
	}
	else if (dist2 == 1)   //諛곌�� �닔�룊�쑝濡� 諛곗튂�릺�뼱�엳�떎硫큛f the ship is placed horizontally
	{
		if (column > column2)
		{
			for (i = 0; i < 5; i++)
			{
				board[row - 1][column - 1 - i] = 65;
			}
		}
		else if (column2 > column)
		{
			for (i = 0; i < 5; i++)
			{
				board[row - 1][column - 1 + i] = 65;
			}
		}
	}

	////////////////////////////Battleship 66 �쟾�븿
	system("cls");
<<<<<<< HEAD
	printf("★★★★★★함대 배치중★★★★★★\n\n");
=======
	printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
>>>>>>> refs/remotes/KimHyeongSeon/master
	print_board();
	do
	{
		printf("�쟾�븿 4���瑜� �븳以꾨줈 諛곗튂�빐二쇱꽭�슂. \n�떆�옉醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂 \n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row);
		} while (row < 1 || row>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column);
		} while (column < 1 || column>10);

		printf("諛곗튂媛� �걹�굹�뒗 醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row2);
		} while (row2 < 1 || row2>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column2);
		} while (column2 < 1 || column2>10);

		dist1 = distance_check(row, row2, 4);//vertical�닔吏�
		dist2 = distance_check(column, column2, 4);//horizontal �닔�룊
		found = 0;
		if (dist1 == 1) //if the ship is placed vertically �쟾�븿�씠 �닔吏곸씠�씪硫�
		{
			if (row > row2)
			{
				for (i = 0; i < 4; i++)
				{
					if (board[row - 1 - i][column - 1] != 126)
					{
						found++;
					}
				}
			}
			else if (row2 > row)
			{
				for (i = 0; i < 4; i++)
				{
					if (board[row - 1 + i][column - 1] != 126)
					{
						found++;
					}
				}
			}
		}
		else if (dist2 == 1) //if the ship is placed horizontally�쟾�븿�씠 �닔�룊�씠�씪硫�
		{
			if (column > column2)
			{
				for (i = 0; i < 4; i++)
				{
					if (board[row - 1][column - 1 - i] != 126)
					{
						found++;
					}
				}
			}
			else if (column2 > column)
			{
				for (i = 0; i < 4; i++)
				{
					if (board[row - 1][column - 1 + i] != 126)
					{
						found++;
					}
				}
			}
		}
		if ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0)
		{
			system("cls");
			printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
			print_board();
			printf("醫뚰몴瑜� �떎�떆 �엯�젰�빐二쇱꽭�슂\n\n");
		}
	} while ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0);

	if (dist1 == 1) //if the ship is placed vertically�븿���媛� �닔吏곸쑝濡� 諛곗튂�릺�뼱�엳�쑝硫�
	{
		if (row > row2)
		{
			for (i = 0; i < 4; i++)
			{
				board[row - 1 - i][column - 1] = 66;
			}
		}
		else if (row2 > row)
		{
			for (i = 0; i < 4; i++)
			{
				board[row - 1 + i][column - 1] = 66;
			}
		}
	}
	else if (dist2 == 1)//if the ship is placed horizontally �븿���媛� �닔�룊�쑝濡� 諛곗튂�릺�뼱�엳�쑝硫�
	{
		if (column > column2)
		{
			for (i = 0; i < 4; i++)
			{
				board[row - 1][column - 1 - i] = 66;
			}
		}
		else if (column2 > column)
		{
			for (i = 0; i < 4; i++)
			{
				board[row - 1][column - 1 + i] = 66;
			}
		}
	}
	////////////////////Destroyer 68  援ъ텞�븿 
	system("cls");
	printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
	print_board();
	do
	{
		printf("援ъ텞�븿 3���瑜� �븳以꾨줈 諛곗튂�빐二쇱꽭�슂.\n�떆�옉醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂 \n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row);
		} while (row < 1 || row>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column);
		} while (column < 1 || column>10);

		printf("諛곗튂媛� �걹�굹�뒗 醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row2);
		} while (row2 < 1 || row2>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column2);
		} while (column2 < 1 || column2>10);

		dist1 = distance_check(row, row2, 3);//vertical�닔吏�
		dist2 = distance_check(column, column2, 3);//horizontal �닔�룊
		found = 0;
		if (dist1 == 1) //if the ship is placed vertically�븿���媛� �닔吏곸쑝濡� 諛곗튂
		{
			if (row > row2)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1 - i][column - 1] != 126)
					{
						found++;
					}

				}
			}
			else if (row2 > row)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1 + i][column - 1] != 126)
					{
						found++;
					}
				}
			}
		}
		else if (dist2 == 1) //if the ship is placed horizontally �쟾�븿�씠 �닔�룊�쑝濡� 諛곗튂
		{
			if (column > column2)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1][column - 1 - i] != 126)
					{
						found++;
					}
				}
			}
			else if (column2 > column)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1][column - 1 + i] != 126)
					{
						found++;
					}
				}
			}
		}
		if ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0) {
			system("cls");
			printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
			print_board();
			printf("醫뚰몴瑜� �떎�떆 �엯�젰�빐二쇱꽭�슂\n\n");
		}
	} while ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0);

	if (dist1 == 1) //if the ship is placed vertically �쟾�븿�씠 �닔吏곸쑝濡� 諛곗튂
	{
		if (row > row2)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1 - i][column - 1] = 68;
			}
		}
		else if (row2 > row)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1 + i][column - 1] = 68;
			}
		}
	}
	else if (dist2 == 1) //if the ship is placed horizontally �쟾�븿�씠 �닔�룊�쑝濡� 諛곗튂
	{
		if (column > column2)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1][column - 1 - i] = 68;
			}
		}
		else if (column2 > column)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1][column - 1 + i] = 68;
			}
		}
	}

	//////////////////////////////Submarine  83 �옞�닔�븿
	system("cls");
	printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
	print_board();
	do
	{
		printf("�옞�닔�븿 3���瑜� �븳以꾨줈 諛곗튂�빐二쇱꽭�슂.\n�떆�옉醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂.\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row);
		} while (row < 1 || row>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column);
		} while (column < 1 || column>10);

		printf("諛곗튂媛� �걹�굹�뒗 醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row2);
		} while (row2 < 1 || row2>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column2);
		} while (column2 < 1 || column2>10);

		dist1 = distance_check(row, row2, 3);//vertical �닔吏�
		dist2 = distance_check(column, column2, 3);//horizontal �닔�룊
		found = 0;
		if (dist1 == 1) //if the ship is placed vertically �쟾�븿�씠 �닔吏곸씪혢혳
		{
			if (row > row2)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1 - i][column - 1] != 126)
					{
						found++;
					}
				}
			}
			else if (row2 > row)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1 + i][column - 1] != 126)
					{
						found++;
					}
				}
			}
		}
		else if (dist2 == 1) //if the ship is placed horizontally �쟾�븿�쓽 諛곗튂媛� �닔�룊�씪혢혳
		{
			if (column > column2)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1][column - 1 - i] != 126)
					{
						found++;
					}
				}
			}
			else if (column2 > column)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[row - 1][column - 1 + i] != 126)
					{
						found++;
					}
				}
			}
		}
		if ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0)
		{
			system("cls");
			printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
			print_board();
			printf("醫뚰몴瑜� �떎�떆 �엯�젰�빐二쇱꽭�슂\n\n");
		}
	} while ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0);

	if (dist1 == 1) //if the ship is placed vertically �쟾�븿�쓽 諛곗튂媛� �닔吏곸씪 寃쎌슦
	{
		if (row > row2)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1 - i][column - 1] = 83;
			}
		}
		else if (row2 > row)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1 + i][column - 1] = 83;
			}
		}
	}
	else if (dist2 == 1) //if the ship is placed horizontally �쟾�븿�쓽 諛곗튂媛� �닔�룊�씪寃⑥슦
	{
		if (column > column2)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1][column - 1 - i] = 83;
			}
		}
		else if (column2 > column)
		{
			for (i = 0; i < 3; i++)
			{
				board[row - 1][column - 1 + i] = 83;
			}
		}
	}

	//////////////////Patrol boat  80 珥덇퀎�젙
	system("cls");
	printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
	print_board();
	do
	{
		printf("珥덇퀎�젙 2���瑜� �븳以꾨줈 諛곗튂�빐二쇱꽭�슂.\n�떆�옉醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂.\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row);
		} while (row < 1 || row>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column);
		} while (column < 1 || column>10);

		printf("諛곗튂媛� �걹�굹�뒗 醫뚰몴瑜� �엯�젰�빐二쇱꽭�슂\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row2);
		} while (row2 < 1 || row2>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column2);
		} while (column2 < 1 || column2>10);

		dist1 = distance_check(row, row2, 2);//vertical �닔吏�
		dist2 = distance_check(column, column2, 2);//horizontal �닔�룊
		found = 0;
		if (dist1 == 1) //if the ship is placed vertically �쟾�븿�쓽 諛곗뿴�씠 �닔吏곸씪혢혳
		{
			if (row > row2)
			{
				for (i = 0; i < 2; i++)
				{
					if (board[row - 1 - i][column - 1] != 126)
					{
						found++;
					}
				}
			}
			else if (row2 > row)
			{
				for (i = 0; i < 2; i++)
				{
					if (board[row - 1 + i][column - 1] != 126)
					{
						found++;
					}
				}
			}
		}
		else if (dist2 == 1) //if the ship is placed horizontally �쟾�븿�쓽 諛곗튂媛� �닔�룊�씪혢혳
		{
			if (column > column2)
			{
				for (i = 0; i < 2; i++)
				{
					if (board[row - 1][column - 1 - i] != 126)
					{
						found++;
					}
				}
			}
			else if (column2 > column)
			{
				for (i = 0; i < 2; i++)
				{
					if (board[row - 1][column - 1 + i] != 126)
					{
						found++;
					}
				}
			}
		}
		if ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0)
		{
			system("cls");
			printf("�쁾�쁾�쁾�쁾�쁾�쁾�븿��� 諛곗튂以묅쁾�쁾�쁾�쁾�쁾�쁾\n\n");
			print_board();
			printf("醫뚰몴瑜� �떎�떆 �엯�젰�빐二쇱꽭�슂\n\n");
		}
	} while ((dist1 == 0 && dist2 == 0) || (dist1 == 1 && dist2 == 1) || found > 0);

	if (dist1 == 1) //if the ship is placed vertically �쟾�븿�쓽 諛곗튂媛� �닔吏�
	{
		if (row > row2)
		{
			for (i = 0; i < 2; i++)
			{
				board[row - 1 - i][column - 1] = 80;
			}
		}
		else if (row2 > row)
		{
			for (i = 0; i < 2; i++)
			{
				board[row - 1 + i][column - 1] = 80;
			}
		}
	}
	else if (dist2 == 1) //if the ship is placed horizontally �쟾�븿�쓽 諛곗튂媛� �닔�룊
	{
		if (column > column2)
		{
			for (i = 0; i < 2; i++)
			{
				board[row - 1][column - 1 - i] = 80;
			}
		}
		else if (column2 > column)
		{
			for (i = 0; i < 2; i++)
			{
				board[row - 1][column - 1 + i] = 80;
			}
		}
	}
	system("cls");
	print_board();
	system("pause");
}
///////////////////////////////////////////////////////////////////////////////////////////////
int rand_num(int high)
{
	int r;
	do
	{
		r = rand();
	} while (r >= high);

	return r;
}
///////////////////////////////////////////////////////////////////////////////////////////////

void cp_position()  //而댄벂�꽣�쓽 �쐞移�
{

	int battleship, aircraft, destroyer, patrol, submarine;
	int column, row, direction, check;
	int array[10] = { 0 };//�뼱�뒓 以꾩씠�굹 �뻾�씠 �궗�슜�뻽�뒗吏� 湲곕줉 records which row or columns have been used
	aircraft = 5;
	battleship = 4;
	destroyer = 3;
	submarine = 3;
	patrol = 2;

	direction = rand_num(2);// �쟾�븿�쓽 諛⑺뼢�쓣 怨좊Ⅸ�떎choosing the direction of the boats


	if (direction == 0)				//horizontally �닔�룊
	{								////////////aircraft�빆怨듬え�븿
		row = rand_num(10);
		array[row] = 1;				//registers which row has been used �뼱�뒓 以꾩씠 �궗�슜�뻼�뒗吏� 湲곕줉
		column = rand_num(6);
		while (aircraft > 0)			//lays the ship horizontally 諛곕�� �닔�룊�쑝濡� �넃�떎
		{
			cp_board[row][column] = 65;
			column++;
			aircraft--;
		}
		////////////battleship�쟾�븿
		do
		{
			check = 0;
			row = rand_num(10);
			if (array[row] == 1)
			{
				check = 1;
			}
		} while (check == 1);
		//checks whether the row has been used�뼱�뒓 以꾩씠 �궗�슜�뻼�뒗吏� 湲곕줉
		array[row] = 1;
		column = rand_num(7);
		while (battleship > 0)
		{
			cp_board[row][column] = 66;
			column++;
			battleship--;
		}
		//////////////////destroyer 援ъ텞�븿
		do
		{
			check = 0;
			row = rand_num(10);
			if (array[row] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[row] = 1;
		column = rand_num(8);
		while (destroyer > 0)
		{
			cp_board[row][column] = 68;
			column++;
			destroyer--;
		}
		//////////////////submarine �옞�닔�븿
		do
		{
			check = 0;
			row = rand_num(10);
			if (array[row] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[row] = 1;
		column = rand_num(8);
		while (submarine > 0)
		{
			cp_board[row][column] = 83;
			column++;
			submarine--;
		}
		/////////////////////////patrol 珥덇퀎�젙
		do
		{
			check = 0;
			row = rand_num(10);
			if (array[row] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[row] = 1;
		column = rand_num(9);
		while (patrol > 0)
		{
			cp_board[row][column] = 80;
			column++;
			patrol--;
		}
	}
	else if (direction == 1)
	{													//aircraft �빆怨듬え�븿
		column = rand_num(10);
		array[column] = 1;
		row = rand_num(6);
		while (aircraft > 0)
		{
			cp_board[row][column] = 65;
			row++;
			aircraft--;
		}
		//battleship �쟾�븿
		do
		{
			check = 0;
			column = rand_num(10);
			if (array[column] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[column] = 1;
		row = rand_num(7);
		while (battleship > 0)
		{
			cp_board[row][column] = 66;
			row++;
			battleship--;
		}
		//destroyer援ъ텞�븿
		do
		{
			check = 0;
			column = rand_num(10);
			if (array[column] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[column] = 1;
		row = rand_num(8);
		while (destroyer > 0)
		{
			cp_board[row][column] = 68;
			row++;
			destroyer--;
		}
		//submarine�옞�닔�븿
		do
		{
			check = 0;
			column = rand_num(10);
			if (array[column] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[column] = 1;
		row = rand_num(8);
		while (submarine > 0)
		{
			cp_board[row][column] = 83;
			row++;
			submarine--;
		}
		//patrol 珥덇퀎�젙
		do
		{
			check = 0;
			column = rand_num(10);
			if (array[column] == 1)
			{
				check = 1;
			}
		} while (check == 1);

		array[column] = 1;
		row = rand_num(9);
		while (patrol > 0)
		{
			cp_board[row][column] = 80;
			row++;
			patrol--;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////

int cp_attack_check(int row, int column)
{
	int result;
	if ((board[row][column]) == 120 || (board[row][column]) == 46)
	{
		result = 1;//attacked point
	}
	else if ((board[row][column]) == 46)
	{
		result = 2;//missed point
	}
	else
	{
		result = 0;//new point
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////

int attack_check(int row, int column)
{
	int result;
	if ((cp_board[row][column]) == 120 || (cp_board[row][column]) == 46)
	{
		result = 1;//attacked point
	}
	else if ((cp_board[row][column]) == 46)
	{
		result = 2;//missed point
	}
	else
	{
		result = 0;//new point
	}
	return result;
}
///////////////////////////////////////////////////////////////////////////////////////

void ship_coordinates()
{
	int i, j, k = 0;
	for (i = 0; i < 10; i++)	 //goes through the board and puts the ship's coordinates
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 65)
			{
				A[k][0] = i;
				A[k][1] = j;
				k++;
			}
		}
	}
	k = 0;
	for (i = 0; i < 10; i++)	//goes through the board and puts the ship's coordinates
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 66)
			{
				B[k][0] = i;
				B[k][1] = j;
				k++;
			}
		}
	}
	k = 0;
	for (i = 0; i < 10; i++)	//goes through the board and puts the ship's coordinates
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 68)
			{
				D[k][0] = i;
				D[k][1] = j;
				k++;
			}
		}
	}
	k = 0;
	for (i = 0; i < 10; i++)	//goes through the board and puts the ship's coordinates
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 83)
			{
				S[k][0] = i;
				S[k][1] = j;
				k++;
			}
		}
	}
	k = 0;
	for (i = 0; i < 10; i++)	//goes through the board and puts the ship's coordinates
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 80)
			{
				P[k][0] = i;
				P[k][1] = j;
				k++;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////

void cp_attack()
{
	int i;

	switch (HIT)
	{

	case 0://when not hit
		do
		{
			row = rand_num(10);
			column = rand_num(10);
		} while (cp_attack_check(row, column) == 1 || cp_attack_check(row, column) == 2);		//吏��젏�씠 �궗�슜�릺�뿀�뒗吏� 泥댄겕checks whether the point has been used

		switch (board[row][column])
		{
		case 65://aircraft carrier �빆怨듬え�븿
			HIT = 1;
			strcpy_s(state, 4, "Hit");
			SHIP = 'A';
			board[row][column] = 120;
			for (i = 0; i < 5; i++)
			{
				if ((A[i][0] == row) && (A[i][1] == column))
				{
					A[i][0] = -1;
					A[i][1] = -1;
				}
			}
			break;
		case 66://battleship�쟾�븿
			HIT = 1;
			strcpy_s(state, 4, "Hit");
			SHIP = 'B';
			board[row][column] = 120;
			for (i = 0; i < 4; i++)
			{
				if ((B[i][0] == row) && (B[i][1] == column))
				{
					B[i][0] = -1;
					B[i][1] = -1;
				}
			}
			break;
		case 68://destroyer援ъ텞�븿
			HIT = 1;
			strcpy_s(state, 4, "Hit");
			SHIP = 'D';
			board[row][column] = 120;
			for (i = 0; i < 3; i++)
			{
				if ((D[i][0] == row) && (D[i][1] == column))
				{
					D[i][0] = -1;
					D[i][1] = -1;
				}
			}
			break;
		case 83://submarine�옞�닔�븿
			HIT = 1;
			strcpy_s(state, 4, "Hit");
			SHIP = 'S';
			board[row][column] = 120;
			for (i = 0; i < 3; i++)
			{
				if ((S[i][0] == row) && (S[i][1] == column))
				{
					S[i][0] = -1;
					S[i][1] = -1;
				}
			}
			break;
		case 80://patrol boat 珥덇퀎�븿
			HIT = 1;
			strcpy_s(state, 4, "Hit");
			SHIP = 'P';
			board[row][column] = 120;
			for (i = 0; i < 2; i++)
			{
				if ((P[i][0] == row) && (P[i][1] == column))
				{
					P[i][0] = -1;
					P[i][1] = -1;
				}
			}
			break;
		case 126:           //???????????
			board[row][column] = 46;
			strcpy_s(state, 5, "Miss");
			break;
		}
		break;
	case 1:
	case 2:
	case 3:
	case 4://when hit
		switch (SHIP)
		{
		case 'A':
			HIT++;//increase the hit    hit利앷��
			strcpy_s(state, 4, "Hit");
			for (i = 0; i < 5; i++)		//searches for the remaining ship coordinate and attacks it �궓�븘�엳�뒗 �쟾�븿�쓣 李얘퀬 怨듦꺽
			{
				if ((A[i][0] != -1) && (A[i][1] != -1))
				{
					board[A[i][0]][A[i][1]] = 120;//changes the value in the board 蹂대뱶�쓽 媛믪쓣 諛붽씔�떎
					A[i][0] = -1;//removes the ship coordinate  諛곗쓽 醫뚰몴 吏��슦湲�
					A[i][1] = -1;//removes the ship coordinate  諛곗쓽 醫뚰몴 吏��슦湲�
					break;
				}
			}
			if (HIT == 5)	//if the ship is destroyed resets the counter �쟾�븿�씠 怨듦꺽�릺�뿀�쓣혢혳 移댁슫�꽣 由ъ뀑
			{
				HIT = 0;
			}
			break;
		case 'B':
			HIT++;//increase the hit 怨듦꺽利앷��
			strcpy_s(state, 4, "Hit");
			for (i = 0; i < 4; i++) //searches for the remaining ship coordinate and attacks it�궓�븘�엳�뒗 �쟾�븿�쓣 李얘퀬 怨듦꺽
			{
				if ((B[i][0] != -1) && (B[i][1] != -1))
				{
					board[B[i][0]][B[i][1]] = 120;//changes the value in the board蹂대뱶�쓽 媛믪쓣 諛붽씔�떎
					B[i][0] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					B[i][1] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					break;
				}
			}
			if (HIT == 4)	//if the ship is destroyed resets the counter�쟾�븿�씠 怨듦꺽�릺�뿀�쓣혢혳 移댁슫�꽣 由ъ뀑
			{
				HIT = 0;
			}
			break;
		case 'D':
			HIT++;//increase the hit �엳�듃 利앷��
			strcpy_s(state, 4, "Hit");
			for (i = 0; i < 3; i++) //searches for the remaining ship coordinate and attacks it�궓�븘�엳�뒗 �쟾�븿�쓣 李얘퀬 怨듦꺽
			{
				if ((D[i][0] != -1) && (D[i][1] != -1))
				{
					board[D[i][0]][D[i][1]] = 120;//changes the value in the board蹂대뱶�쓽 媛믪쓣 諛붽씔�떎
					D[i][0] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					D[i][1] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					break;
				}
			}
			if (HIT == 3) //if the ship is destroyed resets the counter�쟾�븿�씠 怨듦꺽�릺�뿀�쓣혢혳 移댁슫�꽣 由ъ뀑
			{
				HIT = 0;
			}
			break;
		case 'S':
			strcpy_s(state, 4, "Hit");
			HIT++;//increase the hit 怨듦꺽利앷��
			for (i = 0; i < 3; i++) //searches for the remaining ship coordinate and attacks it�궓�븘�엳�뒗 �쟾�븿�쓣 李얘퀬 怨듦꺽
			{
				if ((S[i][0] != -1) && (S[i][1] != -1))
				{
					board[S[i][0]][S[i][1]] = 120;//changes the value in the board蹂대뱶�쓽 媛믪쓣 諛붽씔�떎
					S[i][0] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					S[i][1] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					break;
				}
			}
			if (HIT == 3) //if the ship is destroyed resets the counter�쟾�븿�씠 怨듦꺽�릺�뿀�쓣혢혳 移댁슫�꽣 由ъ뀑
			{
				HIT = 0;
			}
			break;
		case 'P':
			strcpy_s(state, 4, "Hit");
			HIT++;//increase the hit
			for (i = 0; i < 2; i++) //searches for the remaining ship coordinate and attacks it�궓�븘�엳�뒗 �쟾�븿�쓣 李얘퀬 怨듦꺽
			{
				if ((P[i][0] != -1) && (P[i][1] != -1))
				{
					board[P[i][0]][P[i][1]] = 120;//changes the value in the board蹂대뱶�쓽 媛믪쓣 諛붽씔�떎
					P[i][0] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					P[i][1] = -1;//removes the ship coordinate諛곗쓽 醫뚰몴 吏��슦湲�
					break;
				}
			}
			if (HIT == 2) //if the ship is destroyed resets the counter�쟾�븿�씠 怨듦꺽�릺�뿀�쓣혢혳 移댁슫�꽣 由ъ뀑
			{
				HIT = 0;
			}
			break;
		}
	}
}
void attack()
{

	do
	{
		printf("�궗�슜�옄�쓽 怨듦꺽李⑤��:\n");
		do
		{
			printf("媛�濡�: ");
			scanf_s("%d", &row);
		} while (row < 1 || row>10);

		do
		{
			printf("�꽭濡�: ");
			scanf_s("%d", &column);
		} while (column < 1 || column>10);

		if (attack_check((row - 1), (column - 1)) == 1 || attack_check((row - 1), (column - 1)) == 2)
		{
			printf("醫뚰몴瑜� �떎�떆 �엯�젰�빐二쇱꽭�슂.\n\n");
		}
	} while (attack_check((row - 1), (column - 1)) == 1 || attack_check((row - 1), (column - 1)) == 2);//checks whether the point has been used

	switch (cp_board[row - 1][column - 1])
	{
	case 65:
	case 66:
	case 68:
	case 83:
	case 80:
		cp_board[row - 1][column - 1] = 120;
		strcpy_s(state, 4, "hit");
		break;
	case 126:
		cp_board[row - 1][column - 1] = 46;
		strcpy_s(state, 5, "miss");
		break;
	}
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
