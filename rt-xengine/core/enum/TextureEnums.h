#pragma once

enum class TextureFiltering
{
	NEAREST,
	LINEAR,
	NEAREST_MIPMAP_NEAREST,
	NEAREST_MIPMAP_LINEAR,
	LINEAR_MIPMAP_NEAREST,
	LINEAR_MIPMAP_LINEAR
};

enum class TextureWrapping
{
	CLAMP_TO_EDGE,
	MIRRORED_REPEAT,
	REPEAT
};

enum TextureChannel : int32
{
	TC_RED = BIT(0),
	TC_GREEN = BIT(1),
	TC_BLUE = BIT(2),
	TC_ALPHA = BIT(3)
};

enum CubeMapFace : int32
{
	CMF_RIGHT = 0,
	CMF_LEFT,
	CMF_UP,
	CMF_DOWN,
	CMF_FRONT,
	CMF_BACK,
	CMF_COUNT
};
