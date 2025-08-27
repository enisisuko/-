
#pragma once
// Fix for Windows headers defining min/max as macros.
// Include this before any Windows headers or as the first include in your .cpp files.
#ifndef NOMINMAX
#define NOMINMAX 1
#endif

// Some translation units may already have <windows.h> included via engine headers.
// As a belt-and-suspenders approach, undef the macros if they slipped in.
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

// Ensure std::max/std::min are available.
#include <algorithm>
