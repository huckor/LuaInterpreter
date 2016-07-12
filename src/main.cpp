#include "Log.h"
#include "LuaInterpreter.h"
#include "Global.h"
#include "Path.h"

Log *__LOG;
#ifdef __APPLE__
std::string LuaPath = "/Volumes/WORK/projects/Demos/LuaInterpreter/lua/";
#else
std::string LuaPath = Path::GetPathToExecutableFolder() + "../../../lua/";
#endif

int main(int argc, const char * argv[])
{
    //Create log class !importand to do it before anything else
    __LOG = new Log();
    __LOG->Create("stderr");
    

    //Create LUA interpreter
    LuaInterpreter *_Interpreter = new LuaInterpreter();
    int Ret = _Interpreter->Start(LuaPath + "test.lua", LuaPath, "main");
    
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
