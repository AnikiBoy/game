#ifndef _GAME_SCENE_
#define _GAME_SCENE_

#include "cocos2d.h"

class GameScene : public cocos2d::Layer {
private:
    int count;
    
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(GameScene);
    
    void update(float delta);
    void createObjects(float delta);
    
    void makeBackground();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart(Ref *pSender);
    
};

#endif
