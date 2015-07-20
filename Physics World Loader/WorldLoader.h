//
//  b2WorldLoader.h
//
//  Created by Amit Kumar Mehar on 19/07/15.
//  Copyright (c) 2015 Amit Kumar Mehar. All rights reserved.
//

#ifndef HelloKit_b2WorldLoader_h
#define HelloKit_b2WorldLoader_h

#import <SpriteKit/SpriteKit.h> // for creating physics objects
#import "JSONKIT.h"             // for parsing json scene

#define PTM_RATIO 30.0

enum ShapeTypes{
    SHAPE_BOX,
    SHAPE_CIRCLE,
    SHAPE_POLYGON,
    SHAPE_CHAIN
};

/*
 
 Joint loading is not predictable as sprite kit does not support
 many features included in box2d like separate anchor for revolute 
 joint(pin joint in sprite kit), enabling and disabling motor in pin joints, etc.
 
*/
enum JointTypes{
    JOINT_DISTANCE,     // created as spring joint
    JOINT_WELD,         // created as fixed joint
    JOINT_REVOLUTE,     // created as pin joint
    JOINT_WHEEL,        // not supported by sprite kit
    JOINT_PULLEY,       // not supported by sprite kit
    JOINT_GEAR,         // not supported by sprite kit
    JOINT_PRISMATIC,    // not supported by sprite kit
    JOINT_ROPE          // created as limit joint
};

@interface WorldLoader : NSObject

// to offset the world's position
@property float offsetX, offsetY;

// loadedBodies contains all the bodies loaded (SKPhysicsBody*)
// loadedJoints contains all the joints loaded (SKPhysicsJoints*)
@property NSMutableArray *loadedBodies, *loadedJoints;

+(id) init;
// to reset loader for loading new scene, called everytime a new scene is loaded
-(void) reset;
// loads the physics scene present in file
-(void) loadJsonSceneFromFile : (NSString*)file : (SKScene*)scene;
// loads fixtures present in bodies, also initializes parent node's physicsBody 
-(void) loadJsonFixtures : (NSArray*)jsonFixtures : (SKNode*) parent;

@end

#endif
