/*
 * Copyright 2011-2024 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "bgfx_p.h"

namespace bgfx
{

#define BGFX_DECLARE_EMBEDDED_SHADER(_name)                                           \
	extern const uint8_t* BX_CONCATENATE(_name, _nvn);                                \
	extern const uint32_t BX_CONCATENATE(_name, _nvn_size);                           \
	static const uint8_t  BX_CONCATENATE(_name, _int_nvn)[] = { 0 };                  \
	const uint8_t* BX_CONCATENATE(_name, _nvn) = &BX_CONCATENATE(_name, _int_nvn)[0]; \
	const uint32_t BX_CONCATENATE(_name, _nvn_size) = 1

BGFX_DECLARE_EMBEDDED_SHADER(vs_debugfont);
BGFX_DECLARE_EMBEDDED_SHADER(fs_debugfont);
BGFX_DECLARE_EMBEDDED_SHADER(vs_clear);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear0);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear1);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear2);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear3);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear4);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear5);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear6);
BGFX_DECLARE_EMBEDDED_SHADER(fs_clear7);

#undef BGFX_DECLARE_EMBEDDED_SHADER

} // namespace bgfx

namespace bgfx { namespace nvn
{
	RendererContextI* rendererCreate(const Init& _init)
	{
		BX_UNUSED(_init);
		return NULL;
	}

	void rendererDestroy()
	{
	}

} /* namespace nvn */ } // namespace bgfx
