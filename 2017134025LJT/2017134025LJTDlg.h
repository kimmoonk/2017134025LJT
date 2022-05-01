
// 2017134025LJTDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "math.h"

#define PTP_MAX 2
#define PI 3.1415926

// CMy2017134025LJTDlg 대화 상자
class CMy2017134025LJTDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy2017134025LJTDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MY2017134025LJT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	bool btn_ptp; //PTP 버튼 변수
	bool btn_cp; //CP 버튼 변수
	bool btn_Bezier;


	int ptp_points[PTP_MAX][2];
	int ptp_click_count;
	long lAxis[2], lPosSize, lCoordinate;	//MouseLbtndown용 변수들
	double dPos[2]; // mouse 버튼용 변수들

	// CP 변수
	int cp_dispos[2];
	int cp_radious;
	double cp_start[2];

	//Bezier 변수
	double bezier_start[2];


	int Point_to_DrawX[2];	// PictureControl에 클릭된 지점을 저장하기 위한 변수
	int Point_to_DrawY[2];	// 2회 클릭되어 직선을 나타낼 것이므로 2개 원소를 갖는 배열 선언
	double move_posX[2];	// 클릭된 지점으로 이동하기 위한 좌표를 저장하기 위한 배열
	double move_posY[2];
	int click_count;		// 클릭된 횟수를 파악하기 위한 변수



	bool m_bPTPThreadStart;
	CWinThread *m_pPTPThread;
	CStatic m_staticDisp;

	static UINT ThreadStart(LPVOID pParam);



	//********************************************************************************

	double m_dXOldCommPos, m_dYOldCommPos;
	double m_dXOldFeedPos, m_dYOldFeedPos;
	double m_dXOldFeedVel, m_dYOldFeedVel;
	long m_lAxisNoX, m_lAxisNoY;
	BOOL m_bXIsMoving, m_bYIsMoving, m_bXStop, m_bYStop;
	int m_pointX, m_pointY, m_realPointX, m_realPointY;
	int Set_Cursor;
	CRect m_rectStage;
	double m_posRevisionX, m_posRevisionY; 
	
	CSliderCtrl m_sliY;
	CSliderCtrl m_sliX;
	CEdit m_edtXInputVel;
	CEdit m_edtXInputAcc;
	CEdit m_edtXInputDec;
	CEdit m_stcXCommPos;
	CEdit m_stcXFeedPos;
	CEdit m_stcXFeedVel;
	CButton m_chkXServoOn;
	CButton m_chkXInMotion;
	CButton m_chkXAlarm;
	CButton m_chkXHomeSignal;
	CButton m_chkXInPosition;
	CButton m_chkXLimitP;
	CButton m_chkXLimitN;
	CButton m_chkXEmg;
	CProgressCtrl m_prgXHomeRate;
	CProgressCtrl m_prgYHomeRate;
	CEdit m_stcXP;
	CEdit m_stcXI;
	CEdit m_stcXD;
	CEdit m_edtXMovePos;
	CEdit m_edtYMovePos;
	CButton m_btnXAlarmClear;
	CButton m_btnXHomeSearch;
	CButton m_btnXPosClear;
	CButton m_btnXSStop;
	CButton m_btnXEStop;
	CEdit m_edtYInputVel;
	CEdit m_edtYInputAcc;
	CEdit m_edtYInputDec;
	CEdit m_stcYCommPos;
	CEdit m_stcYFeedPos;
	CEdit m_stcYFeedVel;
	CButton m_chkYServoOn;
	CButton m_chkYInMotion;
	CButton m_chkYAlarm;
	CButton m_chkYHomeSignal;
	CButton m_chkYInPosition;
	CButton m_chkYLimitP;
	CButton m_chkYLimitN;
	CButton m_chkYEmg;
	CEdit m_stcYP;
	CEdit m_stcYI;
	CEdit m_stcYD;
	CButton m_btnYAlarmClear;
	CButton m_btnYHomeSearch;
	CButton m_btnYPosClear;
	CButton m_btnYSStop;
	CButton m_btnYEStop;
	CButton m_btnLoadFile;
	CButton m_btnBothHomeSearch;
	CButton m_btnMoveZeroPos;
	CButton m_btnBothEStop;
	CStatic m_pcstage;
	CButton m_btnPosMove;

	BOOL InitState();
	BOOL UpdateState();
	void SetDlgItemDouble(int nID, double value, int nPoint = 1);
	double GetDlgItemDouble(int nID);
	CString TranslateAxmResult(DWORD dwAxmResult); 

	afx_msg void OnBnClickedChkXServoOn();
	afx_msg void OnBnClickedBtnXHomeSearch();
	afx_msg void OnBnClickedBtnXPosClear();
	afx_msg void OnBnClickedBtnXSstop();
	afx_msg void OnBnClickedBtnXEstop();
	afx_msg void OnBnClickedChkYServoOn();
	afx_msg void OnBnClickedBtnYHomeSearch();
	afx_msg void OnBnClickedBtnYPosClear();
	afx_msg void OnBnClickedBtnYSstop();
	afx_msg void OnBnClickedBtnYEstop();
	afx_msg void OnBnClickedBtnLoadFile();
	afx_msg void OnBnClickedBtnBothHomeSearch();
	afx_msg void OnBnClickedBtnMoveZeroPos();
	afx_msg void OnBnClickedBtnBothEstop();
	afx_msg void OnBnClickedBtnXAlarmClear();
	afx_msg void OnBnClickedBtnYAlarmClear();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnPosMove();
	afx_msg void OnBnClickedRadioPtp();
	afx_msg void OnBnClickedRadioCp();

	afx_msg void OnBnClickedRadioBezier();
};
