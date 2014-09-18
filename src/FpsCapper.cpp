#include "FpsCapper.h"



FpsCapper::FpsCapper()
{
	startTicks=SDL_GetTicks();
	framesSinceStart=0;
	avgFPS=0;
	maxFPS=60;
	ticksPerFrame=1000/maxFPS;
	ticksThisFrame=0;
	startOfFrameInTicks=0;
}

void FpsCapper::cap(){
	if(ticksThisFrame < ticksPerFrame ){
		SDL_Delay(ticksPerFrame-ticksThisFrame);//waits a set amount milliseconds per frame
	}
}

void FpsCapper::frameRendered(){
	framesSinceStart++;//amount of frames incremented
	ticksThisFrame=SDL_GetTicks()-startOfFrameInTicks;//sets the amount of milliseconds that was used for this frame
	
}

void FpsCapper::start(){
	startOfFrameInTicks=SDL_GetTicks();//starts counting from the begining of frame
}

float FpsCapper::timeSinceStart(){
	return ((SDL_GetTicks()-startTicks)/1000.f); //the time since start
}

float FpsCapper::getAvgFps(){
	avgFPS=framesSinceStart/timeSinceStart();//calculates the average fps
	return avgFPS;
}
