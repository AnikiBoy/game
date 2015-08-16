#ifndef MyProject_TitleScene_h
#define MyProject_TitleScene_h

#include "cocos2d.h"
#include "GameScene.h"

class TitleScene : public cocos2d::Layer
{
private:
    
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(TitleScene);
    
    void update(float delta);
    void makeBackground();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart(Ref *pSender);
    
};

#endif