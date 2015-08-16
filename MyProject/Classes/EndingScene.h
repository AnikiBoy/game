//
//  EndingScene.h
//  MyProject
//
//  Created by 植村拳斗 on 2015/07/31.
//
//

#ifndef MyProject_EndingScene_h
#define MyProject_EndingScene_h

#include "cocos2d.h"

class EndingScene : public cocos2d::Layer {
private:
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(EndingScene);
    
    void update(float delta);
    void makeBackground();
    
    // スタートボタン押下時の処理宣言 戻る Object →　Ref に変更
    void pushStart(Ref *pSender);

    
};

#endif
