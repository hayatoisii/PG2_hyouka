#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
const char kWindowTitle[] = "LC1C_02_イシイハヤト_タイトル";

int Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy*  enemy  = new Enemy;
	Enemy*  enemy1 = new Enemy;
	
	enemy1->enemypos_.x = 100;
	enemy1->enemypos_.y = 100;

	enum STAGE {
		STAGE1,
		STAGE2,
		STAGE3
	};

	STAGE scene = STAGE1;

	int GH2 = Novice::LoadTexture("./start.png");
	int GH3 = Novice::LoadTexture("./end.png");

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (scene) {
		case STAGE1:

			enemy->isAlive = 1;
			player->isbullet_ = 0;
			player->bulletpos_.x = player->outer_.x;
			player->bulletpos_.y = player->outer_.y;

			if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE]) {
				scene = STAGE2;
			}

			break;
		case STAGE2:

				player->PlayerMove(keys, preKeys);
				player->Bullet1();
				enemy->Hit(player->bulletpos_);
				player->Hit(player->playerpos_, enemy->enemypos_);
				player->Hit(player->playerpos_, enemy1->enemypos_);
				enemy->Move();
				enemy1->Hit(player->bulletpos_);
				enemy1->Move();

				if (enemy->isAlive == 0) {

					scene = STAGE3;

				}

				break;
		case STAGE3:


			if (keys[DIK_R] == 0 && preKeys[DIK_R]) {

				scene = STAGE1;

			}


			break;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		switch (scene) {
		case STAGE1:

			Novice::DrawSprite(0, 0, GH2, 1, 1, 0.0f, 0xffffffff);

			break;
		case STAGE2:

			Novice::DrawBox(0, 0, 1280, 720, 0, 0x9E76B4FF, kFillModeSolid);
			Novice::ScreenPrintf(10, 10, "shot　SPACE ");

			player->PlayerDraw();
			enemy->Draw();
			enemy1->Draw();

			break;
		case STAGE3:

			Novice::DrawSprite(0, 0, GH3, 1, 1, 0.0f, 0xffffffff);

			break;
		}


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemy;
	delete enemy1;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
