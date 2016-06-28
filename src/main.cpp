#include "Log.h"
#include "LuaInterpreter.h"
#include "Global.h"
#include "Path.h"

Log *__LOG;

int main(int argc, const char * argv[])
{
    //Create log class !importand to do it before anything else
    __LOG = new Log();
    __LOG->Create("stderr");
    
    
    //Create LUA interpreter
    LuaInterpreter *_Interpreter = new LuaInterpreter();
    
#ifdef WIN32
	int Ret = _Interpreter->Start(Path::GetPathToExecutableFolder() + "../../../lua/test.lua", Path::GetPathToExecutableFolder() + "../../../lua/", "main");
#elif __APPLE__
    int Ret = _Interpreter->Start("/Volumes/WORK/projects/LuaInterpreter/lua/test.lua", "/Volumes/WORK/projects/LuaInterpreter/lua/", "main");
#endif
    
    //After we finished with LUA, delete interpreter class
    delete _Interpreter;
    
    if(Ret)
        LOG("Lua interpreter executed sucesfully", MAIN_LOG_BIT);
    else
        LOG("Lua interpreter execution failed", MAIN_LOG_BIT);
    
    
    //Delete log class !important to do it as last thing
    delete __LOG;
    
    return 0;
}
