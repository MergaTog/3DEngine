#version 430 core
	in vec3 fs_color;
    in vec2 fs_textureCoord;

    out vec4 outColor;

    uniform sampler2D texSampler;

    void main()
    {
        outColor = texture(texSampler, fs_textureCoord) * vec4(fs_color, 1);
    }