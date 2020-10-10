#ifndef __SETTINGS___
#define __SETTINGS___

#if defined(_WINDOWS) || defined(WIN32) || defined(_WIN32)
    #include "Platform/Windows/PlatformEntry.h"
	#include "Platform\Windows\Resource.h"
    
#elif defined(ANDROID)
    #include "Platform/Android/PlatformEntry.h"
    
#elif defined(WEBGL)
    #include "Platform\WebGl\PlatformEntry.h"
    
#elif defined(PLAYSTATION_1)
    #include "Platform/Playstation_1/PlatformEntry.h"
    
#elif defined(PLAYSTATION_2)
    #include "Platform/Playstation_2/PlatformEntry.h"

#endif


#endif //__SETTINGS___
