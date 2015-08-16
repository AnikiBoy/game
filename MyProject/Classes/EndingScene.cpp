//
//  EndingScene.cpp
//  MyProject
//
//  Created by 植村拳斗 on 2015/07/31.
//
//

#include "EndingScene.h"
#include "TitleScene.h"
#include "SimpleAudioEngine.h"

#include <vector>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

Scene* EndingScene::createScene()
{
    auto scene = Scene::create();
    auto layer = EndingScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool EndingScene::init()
{
    // フレームごとに呼び出す
    this->scheduleUpdate();
    
    // 秒数を指定してメソッドを入れる事で指定した秒数毎に呼ばれる「放置系の生成部分？」
    //this->schedule(schedule_selector(GameScene::createObjects), 1);
    
    if ( !Layer::init() ) {
        return false;
    }
    
    srand((unsigned)time(NULL));
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    /**
     * デバッグ用
     */
    {
        // スタートボタンを設置
        auto startButton
            = MenuItemImage::create("piyo.png",  // 通常状態の画像
                                    "puyo.png",  // 押下状態の画像
                                    CC_CALLBACK_1(EndingScene::pushStart, this));
        // ボタンの設置
        startButton->setPosition(Point(winSize.width /2 ,winSize.height/2));
        
        // メニューを作成 自動解放オブジェクト
        auto menu = Menu::create(startButton, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        auto text = Label::createWithSystemFont("ENDING SCENE", "HiraKakuProN-W6", 48);
        text->setPosition(Point(winSize.width /2 ,winSize.height/2));
        this->addChild(text);
    }
    
    
    return true;
}

void EndingScene::update(float delta) {
    
}

void EndingScene::makeBackground()
{
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getWinSize();
    //マルチレゾリューション対応がどうとか
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    // タイトルを設置
    auto lbl_title = Label::createWithSystemFont("Top","HiraKakuProN-W6", 100);
    lbl_title->setPosition(Point(origin.x + winSize.width/2,
                                 origin.y + winSize.height
                                 -lbl_title->getContentSize().height));
    // ラベルタイトルを追加
    this->addChild(lbl_title,1);
}

//
void EndingScene::pushStart(Ref *pSender)
{
    CCLOG("Pushボタン");
    
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    Scene *pScene = TitleScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
}



