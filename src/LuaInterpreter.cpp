#include "LuaInterpreter.h"
#include "Conv.h"
#include "Log.h"
#include "Global.h"

LuaInterpreter::LuaInterpreter()
{
  _LuaState = NULL;
}

LuaInterpreter::~LuaInterpreter()
{
  if(_LuaState != NULL)
  {
    lua_close(_LuaState);
    _LuaState = NULL;
  }
}

void LuaInterpreter::Close()
{
  if(_LuaState != NULL)
  {
    lua_close(_LuaState);
    _LuaState = NULL;
  }
}

int LuaInterpreter::Start(std::string LuaFileName, std::string LuaFilePath, std::string LuaFunctionName)
{
  _LuaFileName = LuaFileName;
  _LuaFilePath = LuaFilePath;
  _LuaFunctionName = LuaFunctionName;

  //Init LUA interpreter
  if(!Initialize())
      return LUA_INIT_FAILED;

  //Set LUA_PATH global variable
  if(!SetLuaPath())
      return LUA_SET_PATH_FAILED;

  //Execute lua script
  if(!DoFile())
      return LUA_DO_FILE_FAILED;

  return OK;
}

int LuaInterpreter::Initialize()
{
  _LuaState = luaL_newstate();
  if(_LuaState == NULL)
      return FAILED;

  //Load LUA libraries
  luaL_openlibs (_LuaState);

  return OK;
}

int LuaInterpreter::DoFile()
{
  std::string ToLog = "";
  int Ret = FAILED;

  if(_LuaState == NULL)
      return FAILED;

  Ret = luaL_dofile(_LuaState, (char *)_LuaFileName.c_str());
  if(Ret != 0)
  {
    ToLog = lua_tostring(_LuaState,-1);
    LOG("Error occurs when calling luaL_dofile, return code is: " + Conv::IntToStr(Ret), LUA_LOG_BIT);
    LOG("Error: " + ToLog, LUA_LOG_BIT);

    return FAILED;
  }

  if(_LuaFunctionName != "")
  {
	  lua_getglobal(_LuaState, (char *)_LuaFunctionName.c_str());
	  Ret = lua_pcall(_LuaState, 0, 0, 0);

    if(Ret != 0)
    {
      ToLog = lua_tostring(_LuaState,-1);
      LOG("Error occurs when calling lua_pcall, return code is: " + Conv::IntToStr(Ret), LUA_LOG_BIT);
      LOG("Error: " + ToLog, LUA_LOG_BIT);

      return FAILED;
    }
  }

  return OK;
}

int LuaInterpreter::SetLuaPath()
{
  std::string CurrentPath;

  lua_getglobal(_LuaState, "package");

  // get field "path" from table at top of stack (-1)
  lua_getfield(_LuaState, -1, "path");

  // grab path string from top of stack
  CurrentPath = lua_tostring(_LuaState, -1);

  // do your path magic here
  CurrentPath.append(";");
  CurrentPath.append(_LuaFilePath + "?.lua");

  // get rid of the string on the stack we just pushed on line 5
  lua_pop(_LuaState, 1);

  // push the new one
  lua_pushstring(_LuaState, CurrentPath.c_str());

  // set the field "path" in table at -2 with value at top of stack
  lua_setfield(_LuaState, -2, "path");

  // get rid of package table from top of stack
  lua_pop(_LuaState, 1 );

  return OK;
}
