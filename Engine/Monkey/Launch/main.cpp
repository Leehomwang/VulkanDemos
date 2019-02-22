#include "Common/Common.h"
#include "Common/Log.h"
#include "Configuration/PerPlatformCppDefines.h"
#include "Vulkan/VulkanRHI.h"
#include "Math/Matrix.h"
#include "Math/Plane.h"
#include "Math/Quat.h"

#include <stdio.h>
#include <string>

extern int32 GuardedMain(const char* CmdLine, int32 nCmdShow);

int main(int argc, const char * argv[])
{
	Quat quat;
	Plane plane;
	
    std::string cmdline;
    for (int i = 0; i < argc; ++i) {
        cmdline += std::string(argv[i]) + " ";
    }
    MLOG("CMDLine:%s", cmdline.c_str());
    return GuardedMain(cmdline.c_str(), argc);
}