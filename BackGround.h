#pragma once
#include "Engine/GameObject.h"

//BackGround���Ǘ�����N���X
class BackGround : public GameObject
{
    int hModel_;    //���f���ԍ�

public:
    //�R���X�g���N�^
    BackGround(GameObject* parent);

    //�f�X�g���N�^
    ~BackGround();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};