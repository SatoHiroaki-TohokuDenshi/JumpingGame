#pragma once
#include "Engine/GameObject.h"


//Play�V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	enum STATE {
		S_LOAD = 0,		//���[�h��
		S_PLAY,			//�V�ׂ�
		S_CLEAR,		//�N���A
		S_DEAD			//����
	};
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};