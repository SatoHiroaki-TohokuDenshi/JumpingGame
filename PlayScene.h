#pragma once
#include "Engine/GameObject.h"


//Playシーンを管理するクラス
class PlayScene : public GameObject
{
	enum STATE {
		S_LOAD = 0,		//ロード中
		S_PLAY,			//遊べる
		S_CLEAR,		//クリア
		S_DEAD			//死んだ
	};
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};