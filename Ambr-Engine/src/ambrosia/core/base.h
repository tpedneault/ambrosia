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
#include <any>

#ifdef GLCORE_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#ifdef AMBR_ENGINE_EXPORT
#define AMBR_ENGINE_API __declspec(dllexport)
#else
#define AMBR_ENGINE_API __declspec(dllimport)
#endif

using std::string;

namespace ambr {

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

}; // namespace ambr