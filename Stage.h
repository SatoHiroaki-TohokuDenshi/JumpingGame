#pragma once
#include "Engine/GameObject.h"

//Stageを管理するクラス
class Stage : public GameObject
{
    enum TYPE {
        TYPE_HOLE = 0,      //穴
        TYPE_FLOOR,         //床
        TYPE_BACK,          //背景
    };

    int** table_;
    int WIDTH_;
    int HEIGHT_;

public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};