#pragma once
#include "Engine/GameObject.h"

//Playerを管理するクラス
class Player : public GameObject
{
    int hModel_;            //モデル番号
    XMFLOAT3 prevPos_;      //直前の位置を記録
    bool jumpFlag_;         //ジャンプしたか   true=ジャンプ中  false=ジャンプしていない
    float jumpMotion_;      //ジャンプの挙動

public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //移動
    void Move();

    //ジャンプ
    void Jump();

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;
};