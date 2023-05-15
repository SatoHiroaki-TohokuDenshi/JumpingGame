#pragma once
#include "Engine/GameObject.h"

//Floorを管理するクラス
class Floor : public GameObject
{

public:
    //コンストラクタ
    Floor(GameObject* parent);

    //デストラクタ
    ~Floor();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};