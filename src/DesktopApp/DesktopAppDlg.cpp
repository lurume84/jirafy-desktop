#include "stdafx.h"
#include "DesktopApp.h"
#include "DesktopAppDlg.h"
#include "DesktopCore\System\Services\ApplicationDataService.h"
#include "DesktopCore\System\Services\IniFileService.h"

#include <boost\filesystem.hpp>
#include <boost\filesystem\operations.hpp>

DesktopAppDlg::DesktopAppDlg(_In_opt_ CWnd* pParent)
: CDialogEx(DesktopAppDlg::IDD, pParent)
{

}

void DesktopAppDlg::DoDataExchange(CDataExchange* pDX)
{
  //Let the base class do its thing
  __super::DoDataExchange(pDX);

 /* DDX_Control(pDX, IDC_PAYLOADS, m_wndPayloads);
  DDX_Control(pDX, IDC_PAYLOAD, m_wndPayload);
  DDX_Text(pDX, IDC_PAYLOAD, m_sPayload);
  DDX_Control(pDX, IDC_MESSAGES, m_wndStatusMessages);*/
}

BEGIN_MESSAGE_MAP(DesktopAppDlg, CDialogEx)
  ON_WM_PAINT()
  ON_WM_SIZE()
  ON_WM_NCACTIVATE()
  ON_WM_ACTIVATE()
  ON_WM_NCCALCSIZE()
  ON_WM_NCHITTEST()
  ON_WM_QUERYDRAGICON()
  /*
  ON_EN_CHANGE(IDC_PAYLOAD, &DesktopAppDlg::OnChangePayload)
  ON_BN_CLICKED(IDC_CLEAR, &DesktopAppDlg::OnClickedClear)*/
END_MESSAGE_MAP()

BOOL DesktopAppDlg::OnInitDialog()
{
  //Let the base class do its thing
  __super::OnInitDialog();
  
  /*MARGINS m{ 0, 0, 0, 0 };
  DwmExtendFrameIntoClientArea(m_hWnd, &m);*/
  
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

  m_frame = std::make_unique<DesktopAppFrame>();
  m_frame->LoadFrame(IDR_MAINFRAME,
	  0, NULL,
	  NULL);

  m_frame->GetMenu()->Detach();
  m_frame->SetMenu(NULL);

  // The one and only window has been initialized, so show and update it
  m_frame->ShowWindow(SW_SHOW);
  m_frame->UpdateWindow();

  // Force the system to recalculate NC area (making it send WM_NCCALCSIZE).
  /*SetWindowPos(nullptr, 0, 0, 0, 0,
	  SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);*/
  /*LONG lStyle = GetWindowLong(m_hWnd, GWL_STYLE);
  lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_SYSMENU);
  SetWindowLong(m_hWnd, GWL_STYLE, lStyle);
  LONG lExStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
  lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
  SetWindowLong(m_hWnd, GWL_EXSTYLE, lExStyle);
  SetWindowPos(NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
*/
 ShowWindow(SW_RESTORE);

  return TRUE;
}

void DesktopAppDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this);

    SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

    //Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    //Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
    __super::OnPaint();
}

HCURSOR DesktopAppDlg::OnQueryDragIcon()
{
  return static_cast<HCURSOR>(m_hIcon);
}

void DesktopAppDlg::OnSize(UINT nType, int cx, int cy)
{
	if (nType == SIZE_MAXIMIZED ||
		nType == SIZE_RESTORED)
	{
		OnNcPaint();
	}

	if (m_browser_dlg->GetSafeHwnd() != NULL)
	{
		m_browser_dlg->MoveWindow(0, 0, cx, cy);
	}
}

void DesktopAppDlg::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	/*if (bCalcValidRects == TRUE)
	{
		
		RECT rcNewWnd;
		CopyRect(&rcNewWnd, &lpncsp->rgrc[0]);

		RECT rcNewClient;
		rcNewClient.top = rcNewWnd.top + 0;
		rcNewClient.bottom = rcNewWnd.bottom - 0;
		rcNewClient.left = rcNewWnd.left + 0;
		rcNewClient.right = rcNewWnd.right - 0;

		CopyRect(&lpncsp->rgrc[0], &rcNewClient);

		OnSize(SIZE_RESTORED, rcNewWnd.right, rcNewWnd.bottom);
	}
	*/
	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);
}

LRESULT DesktopAppDlg::OnNcHitTest(CPoint point)
{
	return CDialogEx::OnNcHitTest(point);
}

BOOL DesktopAppDlg::OnNcActivate(BOOL bActive)
{
	return CDialogEx::OnNcActivate(bActive);
}

void DesktopAppDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
}