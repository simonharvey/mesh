//
//  ViewController.h
//  Mesh
//
//  Created by Simon Harvey on 13-02-23.
//  Copyright (c) 2013 Simon Harvey. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "scene.h"

@interface ViewController : GLKViewController <GLKViewDelegate, UIGestureRecognizerDelegate>
{
	Scene * scene;
	CGPoint last_pos;
}

@end
