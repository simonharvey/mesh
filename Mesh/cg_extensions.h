//
//  cg_extensions.h
//  Mesh
//
//  Created by Simon Harvey on 13-02-23.
//  Copyright (c) 2013 Simon Harvey. All rights reserved.
//

#ifndef Mesh_cg_extensions_h
#define Mesh_cg_extensions_h

bool operator != (const CGPoint &p1, const CGPoint &p2) {
	return p1.x != p2.x || p1.y != p2.y;
}

#endif
