#include "BackGround.h"

#include "Engine/Model.h"

//コンストラクタ
BackGround::BackGround(GameObject* parent)
    :GameObject(parent, "BackGround"), hModel_(-1)
{
}

//デストラクタ
BackGround::~BackGround()
{
}

//初期化
void BackGround::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("BackGround.fbx");
    assert(hModel_ >= 0);
}

//更新
void BackGround::Update()
{
}

//描画
void BackGround::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void BackGround::Release()
{
}