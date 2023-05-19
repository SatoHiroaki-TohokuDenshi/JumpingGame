#pragma once
#include "Engine/GameObject.h"

//Player���Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;            //���f���ԍ�
    XMFLOAT3 prevPos_;      //���O�̈ʒu���L�^
    bool jumpFlag_;         //�W�����v������   true=�W�����v��  false=�W�����v���Ă��Ȃ�
    float jumpMotion_;      //�W�����v�̋���

public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�ړ�
    void Move();

    //�W�����v
    void Jump();

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;
};