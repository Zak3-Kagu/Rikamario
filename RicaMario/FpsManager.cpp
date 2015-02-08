#include "FpsManager.h"

void FpsManager::wait() const{
	const int tookTime = GetNowCount() - m_start_time;
	const int waitTime = m_count * 1000 / FPS - tookTime;
	if (waitTime > 0){
		Sleep(waitTime);
	}
}

void FpsManager::update(){
	if (m_count == 0){
		m_start_time = GetNowCount();
	}
	if (m_count == FPS){
		const int tmp = GetNowCount();
		m_fps = 1000.f / ((tmp - m_start_time) / (float)FPS);
		m_count = 0;
		m_start_time = tmp;
	}
	m_count++;
}

void FpsManager::draw() const{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", m_fps);
}