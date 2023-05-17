#include "Stage.h"

#include "Engine/CsvReader.h"

#include "Floor.h"
#include "Hole.h"
#include "BackGround.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), table_(nullptr),HEIGHT_(0), WIDTH_(0)
{
    CsvReader csv;
    csv.Load("FloorData.csv");

    HEIGHT_ = csv.GetHeight();   //�f�[�^�����s���邩
    WIDTH_ = csv.GetWidth();    //�P�s�ɉ��f�[�^�����邩

    table_ = new int* [WIDTH_];
    for (int x = 0; x < HEIGHT_; x++)
    {
        table_[x] = new int[HEIGHT_];
    }

    for (int x = 0; x < HEIGHT_; x++)
    {
        for (int y = 0; y < WIDTH_; y++)
        {
            table_[x][(WIDTH_ - 1) - y] = csv.GetValue(x, y);
        }
    }
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //Stage�I�u�W�F�N�g�����炳���ɁA�X�e�[�W��z�u���邽�߂̕ϐ�
    Transform t;
    //�\�����郂�f�����Ǘ�����ϐ�
    TYPE type;

    for (int x = 0; x < HEIGHT_; x++)
    {
        for (int y = 0; y < WIDTH_; y++)
        {
            t.position_ = XMFLOAT3((float)x, (float)y, 0.0f);
            type = (TYPE)table_[x][y];

            switch (type)
            {
            case(TYPE::TYPE_HOLE): {
                Hole* pHole = nullptr;
                pHole = Instantiate<Hole>(this);
                pHole->SetPosition(t.position_);
                break;
            }
            case(TYPE::TYPE_FLOOR): {
                Floor* pFloor = nullptr;
                pFloor = Instantiate<Floor>(this);
                pFloor->SetPosition(t.position_);
                break;
            }
            case(TYPE::TYPE_BACK): {
                BackGround* pBackGround = nullptr;
                pBackGround = Instantiate<BackGround>(this);
                pBackGround->SetPosition(t.position_);
                break;
            }
            default:
                break;
            }
        }
    }

    //for (int h = 0; h < HEIGHT; h++) {
    //    for (int w = 0; w < WIDTH; w++) {
    //        t.position_ = XMFLOAT3((float)w, (float)h, 0.0f);

    //        switch (csv.GetValue(h, w))
    //        {
    //        case(TYPE::TYPE_HOLE): {
    //                Hole* pHole = nullptr;
    //                pHole = Instantiate<Hole>(this);
    //                pHole->SetPosition(t.position_);
    //                break;
    //            }
    //        case(TYPE::TYPE_FLOOR): {
    //            Floor* pFloor = nullptr;
    //            pFloor = Instantiate<Floor>(this);
    //            pFloor->SetPosition(t.position_);
    //            break;
    //        }
    //        case(TYPE::TYPE_BACK): {
    //            BackGround* pBackGround = nullptr;
    //            pBackGround = Instantiate<BackGround>(this);
    //            pBackGround->SetPosition(t.position_);
    //            break;
    //        }
    //        default:
    //            break;
    //        }
    //    }
    //}

    //Instantiate<Floor>(this);
    //Instantiate<Hole>(this);
    //Instantiate<BackGround>(this);
}

//�X�V
void Stage::Update()
{
}

//�`��
void Stage::Draw()
{
}

//�J��
void Stage::Release()
{
    for (int x = 0; x < HEIGHT_; x++)
    {
        delete[] table_[x];
    }
    delete[] table_;
}