#include "BackGround.h"

#include "Engine/Model.h"

//�R���X�g���N�^
BackGround::BackGround(GameObject* parent)
    :GameObject(parent, "BackGround"), hModel_(-1)
{
}

//�f�X�g���N�^
BackGround::~BackGround()
{
}

//������
void BackGround::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("BackGround.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void BackGround::Update()
{
}

//�`��
void BackGround::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void BackGround::Release()
{
}