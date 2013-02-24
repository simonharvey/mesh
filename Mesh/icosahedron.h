//
//  icosahedron.h
//  Mesh
//
//  Created by Simon Harvey on 12-01-08.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Mesh_icosahedron_h
#define Mesh_icosahedron_h

/*
static GLfloat ico_verts[12][3] = {    
	{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},    
	{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},    
	{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} 
};

static GLubyte ico_indices[20][3] = { 
	{0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},    
	{8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},    
	{7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, 
	{6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };
*/

static const float  x = .525731112119133606f;
static const float  z = .850650808352039932f;
static const float  o = 0;

// coordinates of the 12 vertices
static float ico_vertices[][3] = 
{
	{ -x,  o,  z },
	{  x,  o,  z },
	{ -x,  o, -z },
	{  x,  o, -z },
	{  o,  z,  x },
	{  o,  z, -x },
	{  o, -z,  x },
	{  o, -z, -x },
	{  z,  x,  o },
	{ -z,  x,  o },
	{  z, -x,  o },
	{ -z, -x,  o }
};


// indices of the 20 faces
static GLubyte ico_indices[][3] = 
{ 
	{0,4,1}, 
	{0,9,4}, 
	{9,5,4}, 
	{4,5,8}, 
	{4,8,1},    
	{8,10,1}, 
	{8,3,10}, 
	{5,3,8}, 
	{5,2,3}, 
	{2,7,3},    
	{7,10,3}, 
	{7,6,10}, 
	{7,11,6}, 
	{11,0,6}, 
	{0,1,6}, 
	{6,1,10}, 
	{9,0,11}, 
	{9,11,2}, 
	{9,2,5},
	{7,2,11} 
};
/*
static GLfloat ico_verts[] = 
{    
	-X, 0.0, Z,
	X, 0.0, Z, 
	-X, 0.0, -Z,
	X, 0.0, -Z,    
	0.0, Z, X,
	0.0, Z, -X, 
	0.0, -Z, X, 
	0.0, -Z, -X,    
	Z, X, 0.0, 
	-Z, X, 0.0, 
	Z, -X, 0.0,
	-Z, -X, 0.0 
};

static GLubyte ico_indices[] = { 
	0,4,1, 
	0,9,4,
	9,5,4,
	4,5,8,
	4,8,1,    
	8,10,1,
	8,3,10,
	5,3,8,
	5,2,3,
	2,7,3,    
	7,10,3,
	7,6,10,
	7,11,6,
	11,0,6,
	0,1,6, 
	6,1,10,
	9,0,11,
	9,11,2,
	9,2,5,
	7,2,11 
};*/

#endif
