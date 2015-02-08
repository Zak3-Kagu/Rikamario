#ifndef _FPSMANAGER_H
#define _FPSMANAGER_H

class FpsManager{
private:
	const int FPS = 60;
	int m_start_time = 0;
	int m_count = 0;
	float m_fps = 0;
public:
	FpsManager() = default;
	~FpsManager() = default;
	void update();
	void wait() const;
	void draw() const;
};

#endif