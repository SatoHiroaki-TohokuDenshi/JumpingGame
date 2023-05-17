#include "Hole.h"

#include "Engine/Model.h"

//コンストラクタ
Hole::Hole(GameObject* parent)
    :GameObject(parent, "Hole"), hModel_(-1)
{
}

//デストラクタ
Hole::~Hole()
{
}

//初期化
void Hole::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Hole.fbx");
    assert(hModel_ >= 0);
}

//更新
void Hole::Update()
{
}

//描画
void Hole::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Hole::Release()
{
}