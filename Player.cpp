#include "Player.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), prevPos_(transform_.position_)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Player_2.fbx");
    assert(hModel_ >= 0);

    //���`�̓����蔻���ݒ�
    BoxCollider* collision = new BoxCollider(XMFLOAT3(-0.5f, 0.5f, 0.5f), XMFLOAT3(1.0f, 1.0f, 1.0f));
    AddCollider(collision);
}

//�X�V
void Player::Update()
{
    this->Move();
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}

void Player::Move() {
    prevPos_ = transform_.position_;
    if (Input::IsKey(DIK_A)) {
        transform_.position_.x -= 0.1f;
    }
    if (Input::IsKey(DIK_D)) {
        transform_.position_.x += 0.1f;
    }
    if (Input::IsKey(DIK_W)) {
        transform_.position_.y += 0.1f;
    }
    if (Input::IsKey(DIK_S)) {
        transform_.position_.y -= 0.1f;
    }
}

//�����ɓ�������
void Player::OnCollision(GameObject* pTarget)
{
    //���������Ƃ��̏���
    if (pTarget->GetObjectName() == "Floor")
    {
        transform_.position_ = prevPos_;
    }
}