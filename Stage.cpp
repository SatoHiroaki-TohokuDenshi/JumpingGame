#include "Stage.h"

#include "Floor.h"
#include "Hole.h"
#include "BackGround.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //Instantiate<Floor>(this);
    //Instantiate<Hole>(this);
    //Instantiate<BackGround>(this);
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
}

//開放
void Stage::Release()
{
}