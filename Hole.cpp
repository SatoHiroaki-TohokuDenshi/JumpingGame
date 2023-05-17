#include "Hole.h"

#include "Engine/Model.h"

//�R���X�g���N�^
Hole::Hole(GameObject* parent)
    :GameObject(parent, "Hole"), hModel_(-1)
{
}

//�f�X�g���N�^
Hole::~Hole()
{
}

//������
void Hole::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Hole.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Hole::Update()
{
}

//�`��
void Hole::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Hole::Release()
{
}