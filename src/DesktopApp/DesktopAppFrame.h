#pragma once

#include "FrameWindow.h"
#include "Browser\BrowserScreen.h"


class DesktopAppFrame : public FrameWindow
{
	DECLARE_DYNCREATE(DesktopAppFrame)
public:
	DesktopAppFrame();           // protected constructor used by dynamic creation
	virtual ~DesktopAppFrame();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT, int, int);

	std::unique_ptr<desktop::ui::BrowserScreen> m_browser_dlg;
};


