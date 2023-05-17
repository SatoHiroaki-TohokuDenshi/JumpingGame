#include "Floor.h"

#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Floor::Floor(GameObject* parent)
    :GameObject(parent, "Floor"), hModel_(-1)
{
}

//�f�X�g���N�^
Floor::~Floor()
{
}

//������
void Floor::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Floor.fbx");
    assert(hModel_ >= 0);

    //���`�̓����蔻���ݒ�
    BoxCollider* collision = new BoxCollider(XMFLOAT3(-0.5f, -0.5f, 0.5f), XMFLOAT3(1.0f, 1.0f, 1.0f));
    AddCollider(collision);
}

//�X�V
void Floor::Update()
{
}

//�`��
void Floor::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Floor::Release()
{
}