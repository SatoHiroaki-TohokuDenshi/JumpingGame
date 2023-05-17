#include "Floor.h"

#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

//コンストラクタ
Floor::Floor(GameObject* parent)
    :GameObject(parent, "Floor"), hModel_(-1)
{
}

//デストラクタ
Floor::~Floor()
{
}

//初期化
void Floor::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Floor.fbx");
    assert(hModel_ >= 0);

    //箱形の当たり判定を設定
    BoxCollider* collision = new BoxCollider(XMFLOAT3(-0.5f, -0.5f, 0.5f), XMFLOAT3(1.0f, 1.0f, 1.0f));
    AddCollider(collision);
}

//更新
void Floor::Update()
{
}

//描画
void Floor::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Floor::Release()
{
}