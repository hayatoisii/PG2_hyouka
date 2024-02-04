#pragma once
#include"Vector2.h"
#include <corecrt_math.h>
#include "Bullet.h"
#include<Novice.h>
class Player
{
public:
	//player
	Vector2 playerpos_;
	Vector2 bulletpos_;
	Vector2 outer_;
	float playerradius_;
	float speed_;
	int isbullet_;

	Vector2 between_;
	float distance2;
	int isAlive2;
	int reborn2;

	int GH1 = Novice::LoadTexture("./bloc12.png");

public:

	Bullet* bullet;

	Player();
	~Player();
	void Hit(Vector2 player,Vector2 enemy);
	void PlayerMove(char* keys,char *preKeys);
	void PlayerDraw();
	void PlayerDraw1(int GH);
	void Bullet1();
	
};

