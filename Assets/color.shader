@vertex

precision mediump float;

uniform mat4 u_Projection;
attribute vec3 a_Position;

void main()
{
	gl_Position = u_Projection * vec4(a_Position, 1);
}

@end

@fragment

precision mediump float;

uniform vec4 u_Color;

void main()
{
	gl_FragColor = u_Color;
}

@end