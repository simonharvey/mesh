//
//  arcball.h
//  Mesh
//
//  Created by Simon Harvey on 13-02-23.
//  Copyright (c) 2013 Simon Harvey. All rights reserved.
//

#ifndef Mesh_arcball_h
#define Mesh_arcball_h

#include <glm/glm.hpp>

namespace arcball
{
	static inline glm::vec3 get_vector(float x, float y, float w, float h) {
		glm::vec3 P = glm::vec3(1.0*x/w*2 - 1.0,
								1.0*y/h*2 - 1.0,
								0);
		P.y = -P.y;
		float OP_squared = P.x * P.x + P.y * P.y;
		if (OP_squared <= 1*1)
			P.z = sqrt(1*1 - OP_squared);  // Pythagore
		else
			P = glm::normalize(P);  // nearest point
		return P;
	}
}

#endif
