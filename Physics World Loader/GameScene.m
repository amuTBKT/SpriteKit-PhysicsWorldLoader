//
//  GameScene.m
//  Physics World Loader
//
//  Created by Amit Kumar Mehar on 20/07/15.
//  Copyright (c) 2015 Amit Kumar Mehar. All rights reserved.
//

#import "GameScene.h"

@implementation GameScene

-(void)didMoveToView:(SKView *)view {
    
    // create new instance of WorldLoader
    WorldLoader *loader = [[WorldLoader alloc] init];
    
    // offset depends on the device and your scene
    // given values used for iphone 4s
    loader.offsetX = 0;
    loader.offsetY = 50;
    
    // load the scene from "scene.json" file
    [loader loadJsonSceneFromFile:@"scene" : self];
}

@end
