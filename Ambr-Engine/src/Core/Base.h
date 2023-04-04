#pragma once

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef GLCORE_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#ifdef AMBR_ENGINE_EXPORT
#define AMBR_ENGINE_API __declspec(dllexport)
#else
#define AMBR_ENGINE_API __declspec(dllimport)
#endif

namespace ambr {

	typedef uint32_t U32;
	typedef uint16_t U16;
	typedef uint8_t  U8;

	typedef int32_t  I32;
	typedef int16_t  I16;
	typedef int8_t   I8;

	typedef std::string String;

};