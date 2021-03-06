// tankbattle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include<iostream>
#include<time.h>
#include<list>
#include "Shape.h"

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"

using namespace std;
list<Tank*> lstTanks;
list<Object*> lstBullets;
list<Object*> maintankBullets;
list<Object*> lstBombs;
MainTank mainTank;
void CheckCrash() {
	for (list<Object*>::iterator it = maintankBullets.begin(); it != maintankBullets.end(); it++) {
		for (list<Tank*>::iterator iit = lstTanks.begin(); iit!= lstTanks.end(); iit++) {
			if (Shape::CheckIntersect( (*it)->GetSphere(), (*iit)->GetSphere() ) ) {
				(*iit)->SetDisappear();
				(*it)->SetDisappear();
			}
		}
	}

	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++) {
		if (Shape::CheckIntersect((*it)->GetSphere(), mainTank.GetSphere())) {
			Setting::Die();
			if (Setting::GetLife() > 0) {
				(*it)->SetDisappear();
			}
			else {
				mainTank.SetDisappear();
			}
		}
	}
}



int main()
{
	srand(time(NULL));
	Graphic::Create();
	
	
	
	
	lstTanks.clear();

	
	lstBullets.clear();
	lstBombs.clear();
	bool loop = true;
	bool skip = false;
	bool bgameover = false;
	while (loop)
	{

	
		if (_kbhit())
		{
			int key = _getch();
			if (bgameover) {
				break;
			}
			switch (key)
			{
				// Up  
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
				// Down  
			case 80:
				mainTank.SetDir(Dir::DOWN);
				break;
				// Left  
			case 75:
				mainTank.SetDir(Dir::LEFT);
				break;
				// Right  
			case 77:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: // 方向键高8位  
				break;
				// Esc  
			case 113:
			{
				Dir tmp = mainTank.Getdir();
				mainTank.SetDir(Dir::UP);
				mainTank.Shoot(maintankBullets);
				mainTank.SetDir(Dir::DOWN);
				mainTank.Shoot(maintankBullets);
				mainTank.SetDir(Dir::RIGHT);
				mainTank.Shoot(maintankBullets);
				mainTank.SetDir(LEFT);
				mainTank.Shoot(maintankBullets);
				mainTank.SetDir(tmp);
				break;
			}
			case 27:
				loop = false;
				break;
				// Space  
			case 32:
				mainTank.Shoot(maintankBullets);
				break;
				// Enter  
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}

		if (!skip)
		{
			cleardevice();
			Graphic::DrawBattleGround();
			Graphic::ShowScore();
			if (Setting::m_bNewLevel) {

				Sleep(1000);
				Setting::m_bNewLevel = false;
				Setting::NewGameLevel();
				Graphic::ShowGameLevel(Setting::GetGameLevel());
				for (int i = 0; i < Setting::GetTankNum(); i++) {
					EnemyTank* p = new EnemyTank();
					lstTanks.push_back(p);
				}
				skip = true;
				continue;
			}


			CheckCrash();
			if (mainTank.IsDisappear()) {
				skip = true;
				Graphic::ShowGameOver();
				bgameover = true;
				continue;
			}
			mainTank.Move();
			mainTank.Display();
			
			for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); ) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					Setting::TankDamaged();

					(*it)->Boom(lstBombs);
					delete *it;
					it = lstTanks.erase(it);
					continue;
				}
				if ((*it)->NeedShoot()) {
					EnemyTank * p = (EnemyTank*)(*it);
					p->Shoot(lstBullets);
				}
				(*it)->Display();
				it++;

			}
			for (list<Object*>::iterator it = maintankBullets.begin(); it != maintankBullets.end();) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					(*it)->Boom(lstBombs);
					delete *it;
					it = maintankBullets.erase(it);
					continue;
				}
				(*it)->Display();
				it++;
			}
			for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); ) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					(*it)->Boom(lstBombs);
					delete *it;
					it = lstBullets.erase(it);
					continue;
				}
				(*it)->Display();
				it++;
			}
			for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end();) {
				(*it)->Move();
				if ((*it)->IsDisappear()) {
					delete *it;
					it = lstBombs.erase(it);
					continue;
				}
				(*it)->Display();
				it++;
			}
			
		}

		Sleep(50);
	}
	for (list<Tank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++) {
		delete *it;
	}
	lstTanks.clear();
	for (list<Object*>::iterator it = lstBullets.begin(); it != lstBullets.end(); it++) {
		delete *it;
	}
	lstBullets.clear();

	for (list<Object*>::iterator it = lstBombs.begin(); it != lstBombs.end(); it++) {
		delete *it;
	}
	for (list<Object*>::iterator it = maintankBullets.begin(); it != maintankBullets.end(); it++) {
		delete *it;
	}
	maintankBullets.clear();
	lstBombs.clear();


	Graphic::Destroy();
	return 0;
}


