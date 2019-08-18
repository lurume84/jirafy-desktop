// CustomFrameTest.cpp : implementation file
//

#include "stdafx.h"
#include "DesktopApp.h"
#include "DesktopAppFrame.h"

#include "DesktopCore\System\Services\ApplicationDataService.h"
#include "DesktopCore\System\Services\IniFileService.h"

#include <boost\filesystem.hpp>
#include <boost\filesystem\operations.hpp>
// DesktopAppFrame

IMPLEMENT_DYNCREATE(DesktopAppFrame, FrameWindow)

DesktopAppFrame::DesktopAppFrame()
{

}

DesktopAppFrame::~DesktopAppFrame()
{
}


BEGIN_MESSAGE_MAP(DesktopAppFrame, FrameWindow)
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// DesktopAppFrame message handlers
BOOL DesktopAppFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	std::string url;

	desktop::core::service::ApplicationDataService applicationService;

	if (boost::filesystem::exists(applicationService.getViewerFolder() + "/index.html"))
	{
		desktop::core::service::IniFileService iniFileService;

		url = iniFileService.get<std::string>(applicationService.getMyDocuments() + "Jirafy.ini", "FileServer", "Endpoint", "http://127.0.0.1:9292/");
	}
	else
	{
		url = boost::filesystem::canonical("Html/loading/index.html").string();
	}

	m_browser_dlg = std::make_unique<desktop::ui::BrowserScreen>(url, this);
	m_browser_dlg->Create(desktop::ui::BrowserScreen::IDD, this);

	CRect rect;
	GetClientRect(rect);
	rect.right -= 20;
	rect.bottom -= 20;
	rect.left = rect.right - 100;
	rect.top = rect.bottom - 50;
//	m_Btn.Create(L"Hello", WS_VISIBLE, rect, this, 1);
	return FrameWindow::OnCreateClient(lpcs, pContext);
}

BOOL DesktopAppFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
//	if (m_view.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	//	return TRUE;

	return FrameWindow::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void DesktopAppFrame::OnSetFocus(CWnd* pOldWnd)
{
//	m_view.SetFocus();
	FrameWindow::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
}

void DesktopAppFrame::OnSize(UINT nType, int cx, int cy)
{
	if (m_browser_dlg->GetSafeHwnd() != NULL)
	{
		//m_browser_dlg->MoveWindow(20, 20, cx, cy);
	}

	FrameWindow::OnSize(nType, cx, cy);
}