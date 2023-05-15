#pragma once
#include "Engine/GameObject.h"

//Stage���Ǘ�����N���X
class Stage : public GameObject
{
    enum TYPE {
        TYPE_HOLE = 0,      //��
        TYPE_FLOOR,         //��
        TYPE_BACK,          //�w�i
    };

public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetPosition(XMFLOAT3 pos) { transform_.position_ = pos; }
};