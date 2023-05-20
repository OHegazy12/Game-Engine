#pragma once

#ifdef SKY_WINDOWS
	#ifdef SKY_LIB
		#define SKY_API  __declspec(dllexport)
	#else
		#define SKY_API  __declspec(dllimport)
	#endif 
#else
	#define SKY_API
#endif


#define SKY_GAME_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}

#if SKY_DEBUG==2
#define SKY_LOG(x) std::clog<<"Log: "<<x<<std::endl;
#define SKY_ERROR(x) std::cerr<<"Error: "<<x<<std::endl;
#elif SKY_DEBUG==1
#define SKY_LOG(x)
#define SKY_ERROR(x) std::cerr<<"ERROR: "<<x<<std::endl;
#else
#define SKY_LOG(x)
#define SKY_ERROR(x)
#endif