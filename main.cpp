#include <Novice.h>

const char kWindowTitle[] = "LC1B_03_オイカワユウマ";

typedef struct Vector2 {
	float x;
	float y;
};

typedef struct Car {
	Vector2 pos;
	Vector2 size;
	Vector2 velocoty;
	Vector2 aceel;
};
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Car normal;
	normal.pos = { 50,100 };
	normal.size = { 50,50 };
	normal.velocoty = { 10,10 };

	Car eaz;
	eaz.pos = { 50,250 };
	eaz.size = { 50,50 };
	eaz.velocoty = { 10,10 };

	Car eazOut;
	eazOut.pos = { 50,400 };
	eazOut.size = { 50,50 };
	eazOut.velocoty = { 10,10 };

	Car eazIn;
	eazIn.pos = { 50,550 };
	eazIn.size = { 50,50 };
	eazIn.velocoty = { 10,10 };



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
		normal.pos.x += normal.velocoty.x;
		if (normal.pos.x>= 1230) {
			normal.pos.x = 1230.0f;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawEllipse(normal.pos.x, normal.pos.y, normal.size.x, normal.size.y, 0.0f, RED, kFillModeSolid);

		Novice::DrawEllipse(
			eaz.pos.x,
			eaz.pos.y,
			eaz.size.x,
			eaz.size.y,
			0.0f,
			RED,
			kFillModeSolid);

		Novice::DrawEllipse(
			eazOut.pos.x,
			eazOut.pos.y,
			eazOut.size.x,
			eazOut.size.y,
			0.0f,
			RED,
			kFillModeSolid);

		Novice::DrawEllipse(
			eazIn.pos.x,
			eazIn.pos.y,
			eazIn.size.x,
			eazIn.size.y,
			0.0f,
			RED,
			kFillModeSolid);
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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
