#include "Stage.h"

#include "Floor.h"
#include "Hole.h"
#include "BackGround.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //Instantiate<Floor>(this);
    //Instantiate<Hole>(this);
    //Instantiate<BackGround>(this);
}

//�X�V
void Stage::Update()
{
}

//�`��
void Stage::Draw()
{
}

//�J��
void Stage::Release()
{
}