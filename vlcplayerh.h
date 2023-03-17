#pragma once

#include<QtCore/qglobal.h>

#ifdef HRVIDEOPLAYER_LIB
#define HRVIDEOPLAYER_EXPORT _declspec(dllexport)
#else
#define HRVIDEOPLAYER_EXPORT _declspec(dllexport)
#pragma comment(lib,"HRVideoPlayer.lib")
#endif