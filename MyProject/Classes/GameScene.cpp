#include "GameScene.h"
#include "EndingScene.h"
#include "SimpleAudioEngine.h"

#include <vector>

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
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
                                    CC_CALLBACK_1(GameScene::pushStart, this));
        // ボタンの設置
        startButton->setPosition(Point(winSize.width /2 ,winSize.height/2));
        
        // メニューを作成 自動解放オブジェクト
        auto menu = Menu::create(startButton, NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu, 1);
        
        auto text = Label::createWithSystemFont("GAME SCENE", "HiraKakuProN-W6", 48);
        text->setPosition(Point(winSize.width /2 ,winSize.height/2));
        this->addChild(text);
    }
    
    
    return true;
}

void GameScene::update(float delta) {
    
}

//
void GameScene::pushStart(Ref *pSender)
{
    CCLOG("Pushボタン");
    
    // 効果音を鳴らす
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("onepoint26.mp3");
    
    Scene *pScene = EndingScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
}

/*
void GameScene::createObjects(float delta) {
    count += delta;
    CCLog("数 : %d", count);
    
    CCSprite*sprite = CCSprite::create("piyo.png");
    sprite->setTextureRect(Rect(0, 0, 32, 32));
    sprite->setPosition(ccp(rand()%300,rand()%200));
    this->addChild(sprite);
}
*/



