#ifndef FPSCAPPER_H
#define FPSCAPPER_H

#include <SDL2/SDL.h>

class FpsCapper
{
	int startTicks;//at what point this object started
	int framesSinceStart;//howmany frames rendered
	float avgFPS;//the average fps
	int maxFPS;//the max desired fps
	int ticksPerFrame;//the amount milliseconds a frame has
	int ticksThisFrame;//the amount of milliseconds spent on this frame
	int startOfFrameInTicks;//when this frame started
	
	public:
		FpsCapper();
		void cap();
		void frameRendered();
		void start();
		float timeSinceStart();
		float getAvgFps();
		
	protected:
	private:
};

#endif // FPSCAPPER_H
