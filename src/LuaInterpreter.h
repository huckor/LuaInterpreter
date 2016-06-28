#ifndef LUAINTERPRETER_H
#define LUAINTERPRETER_H

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include <string>

class LuaInterpreter
{
public:
  LuaInterpreter();
  ~LuaInterpreter();
  int Start(std::string LuaFileName, std::string LuaFilePath, std::string LuaFunctionName);
  void Close();

private:
  lua_State *_LuaState;
  std::string _LuaFileName;
  std::string _LuaFilePath;
  std::string _LuaFunctionName;

  int DoFile();
  int DoFunction();
  int SetLuaPath();
  int Initialize();
};

#endif // LUAINTERPRETER_H
