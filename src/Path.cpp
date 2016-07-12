#include "Path.h"
#ifdef __APPLE__
#include <mach-o/dyld.h>
#elif WIN32
#include <windows.h>
#include <winbase.h>
#elif linux
#include <unistd.h>
#endif

std::string Path::GetPathToExecutableFolder()
{
  std::string FinalResult = "";
    
#ifdef __APPLE__
  char path[2048];
  uint32_t size = sizeof(path);
  if (_NSGetExecutablePath(path, &size) == 0)
    FinalResult = std::string(path);
  else
    FinalResult = "";
    
#elif WIN32
  std::wstring TmpResult;
  char ConvertBuffer[MAX_PATH];
  WCHAR PathWhithFileName[MAX_PATH];
  int Position;
    
  HMODULE Module = GetModuleHandleW(NULL);
  GetModuleFileNameW(Module, PathWhithFileName, MAX_PATH);
    
  TmpResult = std::wstring(PathWhithFileName);
  Position = TmpResult.find_last_of(L"/\\");
    
  if(Position != -1)
    TmpResult = TmpResult.substr(0, Position + 1);
    
  wcstombs(ConvertBuffer, TmpResult.c_str(), MAX_PATH);
  FinalResult = std::string(ConvertBuffer);

#elif linux
  char Buffer[2048];
  size_t BufSize = sizeof(Buffer);
  size_t Position = -1;
  ssize_t Ret = -1;

  Ret = readlink("/proc/self/exe", Buffer, BufSize);
  if(Ret != -1)
  {
	  for(ssize_t i = 0; i < Ret; i++)
		  FinalResult += Buffer[i];

	  Position = FinalResult.find_last_of("/");
	  if(Position != std::string::npos)
		  FinalResult = FinalResult.substr(0, Position + 1);
  }

#endif
    
  return FinalResult;
}
