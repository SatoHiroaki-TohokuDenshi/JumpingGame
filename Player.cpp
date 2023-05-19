#include "Player.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), prevPos_(transform_.position_),
     jumpFlag_(true), jumpMotion_(0.0f)
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
    this->Jump();

    //�f�o�b�O��Ɨp�̃��Z�b�g�v���O����
    if (transform_.position_.y <= -20.0f) {
        transform_.position_ = XMFLOAT3(0.0f, 0.0f, 0.0f);
        jumpFlag_ = false;
    }
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

void Player::Jump() {
    const float GRAVITY = 0.1f;

    if (jumpFlag_) {
        transform_.position_.y += jumpMotion_;
        jumpMotion_ -= GRAVITY;
    }
    else {
        if (Input::IsKeyDown(DIK_SPACE)) {
            jumpMotion_ = 1.0f;
            jumpFlag_ = true;
        }
    }
}

//�����ɓ�������
void Player::OnCollision(GameObject* pTarget)
{
    //���������Ƃ��̏���
    if (pTarget->GetObjectName() == "Floor")
    {
        transform_.position_ = prevPos_;
        jumpFlag_ = false;
    }
}