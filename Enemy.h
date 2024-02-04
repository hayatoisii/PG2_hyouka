#pragma once
#include "Vector2.h"
#include<Novice.h>
#include"Player.h"
#include <corecrt_math.h>
class Enemy :public Player
{
private:
public:

	Vector2 enemypos_;
	Vector2 between_;
	float enemyradius_;
	float speed_;
	float distance;
	static int isAlive;
	int reborn;
	Enemy();
	~Enemy();
	int GH4 = Novice::LoadTexture("./blockenemy.png");

	
	void Move();
	void Draw();
	void Hit(Vector2 bullet);

	









	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X座標</param>
	/// <param name="posY">Y座標</param>
	/// <param name="speedX">移動速度X</param>
	/// <param name="speedY">移動速度Y</param>
	Enemy(int posX, int posY, int speedX, int speedY);


	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetspeedX() { return speedX_; };
	int GetspeedY() { return speedY_; };
	int Getradius() { return radius_; };

	void GetspeedX(int speed1) { this->speedX_ = speed1; };
	void GetspeedY(int speed) { this->speedY_ = speed; };


	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw12();


private:	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
};



