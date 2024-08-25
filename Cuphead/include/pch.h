﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#ifndef __PCH_H
#define __PCH_H

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <ranges>
#include <atlimage.h>

#include <filesystem>
namespace fs = std::filesystem;

#include <cassert>

#include "define.hpp"
#include "struct.hpp"

#endif // __PCH_H