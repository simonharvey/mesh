//
//  ViewController.m
//  Mesh
//
//  Created by Simon Harvey on 13-02-23.
//  Copyright (c) 2013 Simon Harvey. All rights reserved.
//

#import "ViewController.h"
#import "arcball.h"
#import "cg_extensions.h"

@interface ViewController ()
	
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
	self.preferredFramesPerSecond = 60;
	
	GLKView *glkView = (GLKView *)self.view;
	glkView.delegate = self;
	EAGLContext *ctx = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
	glkView.context = ctx;
	[ctx release];
	
	scene = new Scene();
	
	// arcball gesture recognizer
	UIPanGestureRecognizer *rec = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(onPan:)];
	[self.view addGestureRecognizer:rec];
	rec.delegate = self;
	[rec release];
}

- (void)viewDidAppear:(BOOL)animated
{
	CGSize size = self.view.bounds.size;
	scene->SetSize(size.width, size.height);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) glkView:(GLKView *)view drawInRect:(CGRect)rect
{
	scene->Render();
}

- (BOOL) gestureRecognizerShouldBegin:(UIGestureRecognizer *)gestureRecognizer
{
	last_pos = [gestureRecognizer locationInView:self.view];
	return YES;
}

- (void) onPan:(UIPanGestureRecognizer *)r
{
	CGPoint cur_pos = [r locationInView:self.view];
	
	if (last_pos != cur_pos) {
		CGSize size = self.view.bounds.size;
		glm::vec3 va = arcball::get_vector(last_pos.x, last_pos.y, size.width, size.height);
		glm::vec3 vb = arcball::get_vector(cur_pos.x, cur_pos.y, size.width, size.height);
		float angle = acos(std::min(1.0f, glm::dot(va, vb)))*2.5f;
		glm::vec3 axis_in_camera_coord = glm::cross(va, vb);
		scene->matrices.camera = rotate(scene->matrices.camera, glm::degrees(angle), glm::inverse(mat3(scene->matrices.camera)) * axis_in_camera_coord);
	}
	
	last_pos = cur_pos;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
	CGSize size = self.view.bounds.size;
	scene->SetSize(size.width, size.height);
}

@end
