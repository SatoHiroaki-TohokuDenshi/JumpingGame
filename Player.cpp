#include "Player.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), prevPos_(transform_.position_)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Player_2.fbx");
    assert(hModel_ >= 0);

    //箱形の当たり判定を設定
    BoxCollider* collision = new BoxCollider(XMFLOAT3(-0.5f, 0.5f, 0.5f), XMFLOAT3(1.0f, 1.0f, 1.0f));
    AddCollider(collision);
}

//更新
void Player::Update()
{
    this->Move();
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
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

//何かに当たった
void Player::OnCollision(GameObject* pTarget)
{
    //当たったときの処理
    if (pTarget->GetObjectName() == "Floor")
    {
        transform_.position_ = prevPos_;
    }
}