#pragma once
#include "Engine/GameObject.h"

//Hole���Ǘ�����N���X
class Hole : public GameObject
{

public:
    //�R���X�g���N�^
    Hole(GameObject* parent);

    //�f�X�g���N�^
    ~Hole();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};