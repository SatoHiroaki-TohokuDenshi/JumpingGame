#include "PlayScene.h"

#include "Engine/Camera.h"

#include "Player.h"
#include "Stage.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
}

//更新
void PlayScene::Update()
{
	Player* pPlayer =  (Player*)FindObject("Player");
	float playerX = pPlayer->GetPosition().x;

	Camera::SetPosition(XMFLOAT3(playerX, 5, -15));
	Camera::SetTarget(XMFLOAT3(playerX, 5, 0));
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}