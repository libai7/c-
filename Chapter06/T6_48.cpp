/*
*FileName:   T6_48.cpp
*Author:     ʷ����
*E-mail:     208237042@qq.com
*Date:       2022.4.7
*College:    School of Computer Science and Information Engineering
*Function:   ��˫������Ϸ�ĸĽ��档
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//��˫���Ӻ���
unsigned int rollDice()
{
	unsigned int die1 = 1 + rand() % 6;
	unsigned int die2 = 1 + rand() % 6;
	cout << "Player rolled " << die1 << " + " << die2 << " = " << die1 + die2 << endl;
	return die1 + die2;
}
//��Ϸ���ֺ���
int game()
{
	srand(static_cast<unsigned int>(time(0)));
	enum Status{CONTINUE,WON,LOST};
	unsigned int myPoint = 0;
	Status gameStatus = CONTINUE;
	unsigned int sumOfDice = rollDice();
	switch (sumOfDice)
	{
	case 7:
	case 11:
		gameStatus = WON;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;
	default:
		gameStatus = CONTINUE;
		myPoint = sumOfDice;
		cout << "Point is " << myPoint << endl;
	}
	while (CONTINUE == gameStatus)
	{
		sumOfDice = rollDice();
		if(sumOfDice==myPoint){gameStatus=WON;}
		else if (7 == sumOfDice) { gameStatus = LOST; }
	}
	if (WON == gameStatus) { cout << "Player wins" << endl; }
	else { cout << "Player loses" << endl; }
	if (WON == gameStatus)return 1;
	return 0;
}
int main()
{
	int bankBalance = 1000;
	cout << "���������Ϊ1000$,�������ע�� " << endl;
	int wager = 0;
	while (1)
	{
		cin >> wager;
		if (wager <= 1000 && wager > 0)break;
		cout << "��ע����������������룡" << endl;
	}
	if (game()) { bankBalance += wager; }
	else { bankBalance -= wager; }
	if (0 == bankBalance)cout << "����������꣡" << endl;
	else cout << "�� " << bankBalance <<"$" << endl;
	return 0;
}