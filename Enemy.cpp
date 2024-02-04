#include "Enemy.h"


Enemy::Enemy() {
	enemypos_.x = 640.0f;
	enemypos_.y = 200.0f;
	enemyradius_ = 30.0f;
	speed_ = 3.0f;
	between_.x = 0;
	between_.y = 0;
	distance = 0;
	reborn = 0;
	isAlive = 1;
}

Enemy::~Enemy() {
	
}
void Enemy::Move() {
	if (isAlive == 1) {
		if (enemypos_.x <= 0.0f) {
			speed_ = 3.0f;
		}if (1280.0f <= enemypos_.x) {
			speed_ = -3.0f;
		}
		enemypos_.x += speed_;
	}
}
void Enemy::Draw() {
	if (isAlive == 1) {
		reborn = 0;
		Novice::DrawEllipse((int)enemypos_.x, (int)enemypos_.y, (int)enemyradius_, (int)enemyradius_, 0, RED, kFillModeSolid);
		Novice::DrawSprite((int)enemypos_.x-30, (int)enemypos_.y-30, GH4, 2, 2, 0.0f, 0xffffffff);
	}
}
void Enemy::Hit(Vector2 bullet1) {
	between_.x = (bullet1.x - enemypos_.x);
	between_.y = (bullet1.y - enemypos_.y);
	distance = sqrtf((between_.x) * (between_.x)) + sqrtf((between_.y) * (between_.y));
	if (distance <= playerradius_ + enemyradius_) {
		isbullet_ = 0;
		isAlive = 0;
		
	}
	if (isAlive == 0) {
		reborn++;
		if (reborn >= 120) {
			isAlive = 1;
		}
	}	
}



Enemy::Enemy(int posX, int posY, int speedX, int speedY)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 8;
}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Draw12() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}