#include "GameScene.h"

#include "../layers/LevelLayer.h"
#include "../layers/SnakeLayer.h"
#include "../layers/TextGameLayer.h"
#include "../actors/WallActor.h"
#include "../actors/FoodActor.h"
#include "../actors/SnakeActor.h"
#include "../actors/TextEndActor.h"

//TODO: esta configuracion inicial la deberia hacer el director en un metodo
// goToSceneGame()
GameScene::GameScene()
{
    Layer* levelLayer    = new LevelLayer();
    Layer* snakeLayer    = new SnakeLayer();
    Layer* textGameLayer = new TextGameLayer();

    levelLayer->addChild(new WallActor());
    levelLayer->addChild(new FoodActor());

    snakeLayer->addChild(new SnakeActor());

    textGameLayer->addChild(new TextEndActor());

    addChild(levelLayer);
    addChild(snakeLayer);
    addChild(textGameLayer);
}
