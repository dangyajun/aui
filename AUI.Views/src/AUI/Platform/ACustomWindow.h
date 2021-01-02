﻿#pragma once
#include "AWindow.h"

#if defined(_WIN32)

class API_AUI_VIEWS ACustomWindow: public AWindow
{
private:
    bool mDragging = false;

protected:
	LRESULT winProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
	void doDrawWindow() override;
	
public:
	ACustomWindow(const AString& name, int width, int height);
	ACustomWindow();
	~ACustomWindow() override;
	void setSize(int width, int height) override;

	virtual bool isCaptionAt(const glm::ivec2& pos);

signals:
    emits<> dragBegin;
    emits<> dragEnd;
};

#else
class API_AUI_VIEWS ACustomWindow: public AWindow
{
    friend class AWindowManager;
private:
    bool mDragging = false;

    void handleXConfigureNotify();

public:
    ACustomWindow(const AString& name, int width, int height);
    ACustomWindow() = default;
    ~ACustomWindow() override = default;

    void onMousePressed(glm::ivec2 pos, AInput::Key button) override;
    void onMouseReleased(glm::ivec2 pos, AInput::Key button) override;

signals:
    emits<glm::ivec2> dragBegin;
    emits<> dragEnd;
};
#endif