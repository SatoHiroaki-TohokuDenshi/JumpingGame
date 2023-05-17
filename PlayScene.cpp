#include "PlayScene.h"

#include "Engine/Camera.h"

#include "Player.h"
#include "Stage.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	Instantiate<Stage>(this);
}

//�X�V
void PlayScene::Update()
{
	Player* pPlayer =  (Player*)FindObject("Player");
	float playerX = pPlayer->GetPosition().x;

	Camera::SetPosition(XMFLOAT3(playerX, 5, -15));
	Camera::SetTarget(XMFLOAT3(playerX, 5, 0));
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}