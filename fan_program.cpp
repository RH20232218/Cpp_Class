#include <iostream>
#include <cstring>
using namespace std;


bool get_bool_input() 
{
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y')
		return true;
	else if (input == 'n' || input == 'N')
		return false;
	else cout << endl << "잘못된 입력입니다" << endl;
}

void fan(char fan_mode,bool fan_rotate, int *fan_timer) 
{
	
	if (fan_timer != 0)
		switch (fan_mode)
		{
		case 0:cout << "선풍기가 작동하지 않고있다." << endl;break;
		case 1:cout << "선풍기가 약풍으로 돌고있다." << endl;break;
		case 2:cout << "선풍기가 중풍으로 돌고있다." << endl;break;
		case 3:cout << "선풍기가 강풍으로 돌고있다." << endl;break;
		default: cout << "잘못된 입력입니다." << endl;break;
		}
	else
		cout << "선풍기가 작동을 멈췄다." << endl;
	if (fan_rotate)
		cout << "선풍기가 회전하고 있다." << endl;
	if (*fan_timer > 0)
		cout << "선풍기 작동이 " << *fan_timer << "초 남았다." << endl;
	fan_timer--;
}

int select_fan_mode() 
{
	while (true)
	{
		char input;
		cout << endl << "선풍기 모드를 선택해 주세요." << endl;
		cout << "0. 정지, 1.약풍, 2.중풍, 3.강풍 (q로 프로그램 종료)" << endl;
		cin >> input;
		if (input == 'q')
			return -1;
		if (input > 47 && input < 52)
			return input - 48;
		else cout << endl << "잘못된 입력입니다" << endl;
	}
}

bool select_fan_rotate() {
	while (true)
	{
		char input;
		cout << endl << "선풍기를 회전시키겠습니까? (Y/N)" << endl;
		return get_bool_input();
	}
}

int select_timer(int fan_timer) {
	int input = 0;
	cout << "선풍기의 타이머를 설정하시겠습니까? (Y/N)" << endl;
	bool tempbool = get_bool_input();
	if (tempbool)
	{
		cout << "시간을 설정해 주세요\n";
		cin >> input;
		return input;
	}
	return fan_timer;
}


int main()
{

	char fan_mode = 0;
	bool fan_rotate = false;
	int fan_timer = -1;

	while (true)
	{
		cout << "\x1B[2J\x1B[H";
		fan(fan_mode, fan_rotate, &fan_timer);
		fan_mode = select_fan_mode();
		if (fan_mode == -1)
			return 0;
		fan_rotate = select_fan_rotate();
		fan_timer = select_timer(fan_timer);
	}



	return 0;
}
