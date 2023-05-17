#include "Stage.h"

#include "Engine/CsvReader.h"

#include "Floor.h"
#include "Hole.h"
#include "BackGround.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), table_(nullptr),HEIGHT_(0), WIDTH_(0)
{
    CsvReader csv;
    csv.Load("FloorData.csv");

    HEIGHT_ = csv.GetHeight();   //データが何行あるか
    WIDTH_ = csv.GetWidth();    //１行に何個データがあるか

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

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //Stageオブジェクトをずらさずに、ステージを配置するための変数
    Transform t;
    //表示するモデルを管理する変数
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

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
}

//開放
void Stage::Release()
{
    for (int x = 0; x < HEIGHT_; x++)
    {
        delete[] table_[x];
    }
    delete[] table_;
}