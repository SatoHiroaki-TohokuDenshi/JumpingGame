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

    int** table_;
    int WIDTH_;
    int HEIGHT_;

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
};