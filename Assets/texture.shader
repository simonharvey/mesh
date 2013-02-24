@vertex

uniform mat4 u_Projection;

attribute vec2 a_Position;
attribute vec2 a_TexCoord;

varying lowp vec2 v_TexCoord;

void main()
{
	v_TexCoord = a_TexCoord;
	gl_Position = u_Projection * vec4(a_Position, 0, 1);
}

@end

@fragment

uniform sampler2D u_Tex;
varying lowp vec2 v_TexCoord;

void main()
{
	gl_FragColor = texture2D(u_Tex, v_TexCoord);
}

@end