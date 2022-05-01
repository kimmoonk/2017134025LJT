
// 2017134025LJTDlg.cpp : 구현 파일

#include "stdafx.h"
#include "2017134025LJT.h"
#include "2017134025LJTDlg.h"
#include "afxdialogex.h"

#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXL.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXM.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXDev.h"
#include "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/C, C++/AXHS.h"

// ++ =============================================================
// >> AXL(AjineXtek Library) 관련 Library파일을 Link시킵니다.
// ※ [CAUTION] 예제를 복사하여 다른 위치에서 실행시 참조경로 변경이 필요합니다.
// ----------------------------------------------------------------
#ifdef _M_X640
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/64Bit/AxL.lib")
#else
#pragma comment(lib, "C:/Program Files (x86)/EzSoftware UC/AXL(Library)/Library/32Bit/AxL.lib")
#endif


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TM_DISPLAY 100
#define TM_X_HOME_INFO 101
#define TM_Y_HOME_INFO 102
#define DEFAULT_VEL 50
#define DEFAULT_ACC 40
#define DEFAULT_DEC 40
#define DEFAULT_HOME_VEL_FIRST 10
#define DEFAULT_HOME_ACC_FIRST 40
#define DEFAULT_AXIS_NUMBER_X 0
#define DEFAULT_AXIS_NUMBER_Y 1
#define MARGIN 30
#define GAIN_MAIN_ADDRESS_P 0x3100
#define GAIN_MAIN_ADDRESS_D 0x3101
#define GAIN_MAIN_ADDRESS_I 0x3102
#define GAIN_SUB_ADDRESS 0
#define DEFAULT_UNIT 1250 //신형 1250 구형은 10으로 수정
#define DEFAULT_PULSE 1048576
#define DEFAULT_REVISION_X 199.1
#define DEFAULT_REVISION_Y 194.7 


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy2017134025LJTDlg 대화 상자



CMy2017134025LJTDlg::CMy2017134025LJTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy2017134025LJTDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2017134025LJTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLI_Y, m_sliY);
	DDX_Control(pDX, IDC_SLI_X, m_sliX);
	DDX_Control(pDX, IDC_EDT_X_INPUT_VEL, m_edtXInputVel);
	DDX_Control(pDX, IDC_EDT_X_INPUT_ACC, m_edtXInputAcc);
	DDX_Control(pDX, IDC_EDT_X_INPUT_DEC, m_edtXInputDec);
	DDX_Control(pDX, IDC_STC_X_COMMAND_POS, m_stcXCommPos);
	DDX_Control(pDX, IDC_STC_X_FEEDBACK_POS, m_stcXFeedPos);
	DDX_Control(pDX, IDC_STC_X_FEEDBACK_VEL, m_stcXFeedVel);
	DDX_Control(pDX, IDC_CHK_X_SERVO_ON, m_chkXServoOn);
	DDX_Control(pDX, IDC_CHK_X_IN_MOTION, m_chkXInMotion);
	DDX_Control(pDX, IDC_CHK_X_ALARM, m_chkXAlarm);
	DDX_Control(pDX, IDC_CHK_X_HOME_SIGNAL, m_chkXHomeSignal);
	DDX_Control(pDX, IDC_CHK_X_IN_POSITION, m_chkXInPosition);
	DDX_Control(pDX, IDC_CHK_X_LIMIT_P, m_chkXLimitP);
	DDX_Control(pDX, IDC_CHK_X_LIMIT_N, m_chkXLimitN);
	DDX_Control(pDX, IDC_CHK_X_EMG, m_chkXEmg);
	DDX_Control(pDX, IDC_PRG_X_HOME_RATE, m_prgXHomeRate);
	DDX_Control(pDX, IDC_STC_X_P, m_stcXP);
	DDX_Control(pDX, IDC_STC_X_I, m_stcXI);
	DDX_Control(pDX, IDC_STC_X_D, m_stcXD);
	DDX_Control(pDX, IDC_EDT_X_MOVE_POS, m_edtXMovePos);
	DDX_Control(pDX, IDC_EDT_Y_MOVE_POS, m_edtYMovePos);
	DDX_Control(pDX, IDC_BTN_X_ALARM_CLEAR, m_btnXAlarmClear);
	DDX_Control(pDX, IDC_BTN_X_HOME_SEARCH, m_btnXHomeSearch);
	DDX_Control(pDX, IDC_BTN_X_POS_CLEAR, m_btnXPosClear);
	DDX_Control(pDX, IDC_BTN_X_SSTOP, m_btnXSStop);
	DDX_Control(pDX, IDC_BTN_X_ESTOP, m_btnXEStop);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_VEL, m_edtYInputVel);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_ACC, m_edtYInputAcc);
	DDX_Control(pDX, IDC_EDT_Y_INPUT_DEC, m_edtYInputDec);
	DDX_Control(pDX, IDC_STC_Y_COMMAND_POS, m_stcYCommPos);
	DDX_Control(pDX, IDC_STC_Y_FEEDBACK_POS, m_stcYFeedPos);
	DDX_Control(pDX, IDC_STC_Y_FEEDBACK_VEL, m_stcYFeedVel);
	DDX_Control(pDX, IDC_CHK_Y_SERVO_ON, m_chkYServoOn);
	DDX_Control(pDX, IDC_CHK_Y_IN_MOTION, m_chkYInMotion);
	DDX_Control(pDX, IDC_CHK_Y_ALARM, m_chkYAlarm);
	DDX_Control(pDX, IDC_CHK_Y_HOME_SIGNAL, m_chkYHomeSignal);
	DDX_Control(pDX, IDC_CHK_Y_IN_POSITION, m_chkYInPosition);
	DDX_Control(pDX, IDC_CHK_Y_LIMIT_P, m_chkYLimitP);
	DDX_Control(pDX, IDC_CHK_Y_LIMIT_N, m_chkYLimitN);
	DDX_Control(pDX, IDC_CHK_Y_EMG, m_chkYEmg);
	DDX_Control(pDX, IDC_STC_Y_P, m_stcYP);
	DDX_Control(pDX, IDC_STC_Y_I, m_stcYI);
	DDX_Control(pDX, IDC_STC_Y_D, m_stcYD);
	DDX_Control(pDX, IDC_BTN_Y_ALARM_CLEAR, m_btnYAlarmClear);
	DDX_Control(pDX, IDC_BTN_Y_HOME_SEARCH, m_btnYHomeSearch);
	DDX_Control(pDX, IDC_BTN_Y_POS_CLEAR, m_btnYPosClear);
	DDX_Control(pDX, IDC_BTN_Y_SSTOP, m_btnYSStop);
	DDX_Control(pDX, IDC_BTN_Y_ESTOP, m_btnYEStop);
	DDX_Control(pDX, IDC_BTN_LOAD_FILE, m_btnLoadFile);
	DDX_Control(pDX, IDC_BTN_BOTH_HOME_SEARCH, m_btnBothHomeSearch);
	DDX_Control(pDX, IDC_BTN_MOVE_ZERO_POS, m_btnMoveZeroPos);
	DDX_Control(pDX, IDC_BTN_BOTH_ESTOP, m_btnBothEStop);
	DDX_Control(pDX, IDC_PC_STAGE, m_pcstage);
	DDX_Control(pDX, IDC_BTN_POS_MOVE, m_btnPosMove);
	DDX_Control(pDX, IDC_PRG_Y_HOME_RATE, m_prgYHomeRate);
	DDX_Control(pDX, IDC_SLI_X_Vel, m_sliX_vel);
	DDX_Control(pDX, IDC_SLI_X_Acc, m_sliX_acc);
	DDX_Control(pDX, IDC_SLI_X_Dec, m_sliX_dec);
	DDX_Control(pDX, IDC_SLI_Y_Vel, m_sliY_vel);
	DDX_Control(pDX, IDC_SLI_Y_Acc, m_sliY_acc);
	DDX_Control(pDX, IDC_SLI_Y_Dec, m_sliY_dec);
}

BEGIN_MESSAGE_MAP(CMy2017134025LJTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHK_X_SERVO_ON, &CMy2017134025LJTDlg::OnBnClickedChkXServoOn)
	ON_BN_CLICKED(IDC_BTN_X_HOME_SEARCH, &CMy2017134025LJTDlg::OnBnClickedBtnXHomeSearch)
	ON_BN_CLICKED(IDC_BTN_X_POS_CLEAR, &CMy2017134025LJTDlg::OnBnClickedBtnXPosClear)
	ON_BN_CLICKED(IDC_BTN_X_SSTOP, &CMy2017134025LJTDlg::OnBnClickedBtnXSstop)
	ON_BN_CLICKED(IDC_BTN_X_ESTOP, &CMy2017134025LJTDlg::OnBnClickedBtnXEstop)
	ON_BN_CLICKED(IDC_CHK_Y_SERVO_ON, &CMy2017134025LJTDlg::OnBnClickedChkYServoOn)
	ON_BN_CLICKED(IDC_BTN_Y_HOME_SEARCH, &CMy2017134025LJTDlg::OnBnClickedBtnYHomeSearch)
	ON_BN_CLICKED(IDC_BTN_Y_POS_CLEAR, &CMy2017134025LJTDlg::OnBnClickedBtnYPosClear)
	ON_BN_CLICKED(IDC_BTN_Y_SSTOP, &CMy2017134025LJTDlg::OnBnClickedBtnYSstop)
	ON_BN_CLICKED(IDC_BTN_Y_ESTOP, &CMy2017134025LJTDlg::OnBnClickedBtnYEstop)
	ON_BN_CLICKED(IDC_BTN_LOAD_FILE, &CMy2017134025LJTDlg::OnBnClickedBtnLoadFile)
	ON_BN_CLICKED(IDC_BTN_BOTH_HOME_SEARCH, &CMy2017134025LJTDlg::OnBnClickedBtnBothHomeSearch)
	ON_BN_CLICKED(IDC_BTN_MOVE_ZERO_POS, &CMy2017134025LJTDlg::OnBnClickedBtnMoveZeroPos)
	ON_BN_CLICKED(IDC_BTN_BOTH_ESTOP, &CMy2017134025LJTDlg::OnBnClickedBtnBothEstop)
	ON_BN_CLICKED(IDC_BTN_X_ALARM_CLEAR, &CMy2017134025LJTDlg::OnBnClickedBtnXAlarmClear)
	ON_BN_CLICKED(IDC_BTN_Y_ALARM_CLEAR, &CMy2017134025LJTDlg::OnBnClickedBtnYAlarmClear)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BTN_POS_MOVE, &CMy2017134025LJTDlg::OnBnClickedBtnPosMove)
	ON_BN_CLICKED(IDC_RADIO_PTP, &CMy2017134025LJTDlg::OnBnClickedRadioPtp)
	ON_BN_CLICKED(IDC_RADIO_CP, &CMy2017134025LJTDlg::OnBnClickedRadioCp)
	ON_BN_CLICKED(IDC_RADIO_Bezier, &CMy2017134025LJTDlg::OnBnClickedRadioBezier)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLI_X_Vel, &CMy2017134025LJTDlg::OnNMReleasedcaptureSliXVel)
END_MESSAGE_MAP()

BOOL CMy2017134025LJTDlg::InitState()
{
	long lAxisCount = 0;
	DWORD dwRetCode = 0;
	long lPulse = 0;
	CString strResult;
	int nSliderEndPosX, nSliderEndPosY;

	// PTP 변수 초기화
	btn_ptp = false;
	btn_cp = false;
	btn_Bezier = false;

	click_count = 0;
	lPosSize = 2;
	lCoordinate = 0;
	lAxis[0] = 0;
	lAxis[1] = 0;

	cp_radious = 30;

	// AXL 초기화
	if ((AxlIsOpened() == FALSE))
	{
		if (AxlOpenNoReset(7) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("AxlOpen Fail");
			return FALSE;
		} 
	}

	// 현재 보드에서 인식할 수 있는 최대 축수가 2개 이상이 아니면 에러를 출력합니다.
	dwRetCode = AxmInfoGetAxisCount(&lAxisCount);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("AxmInfoGetAxisCount fail.\nError Msg : " + strResult);
		return FALSE;
	}
	else if (lAxisCount < 2)
	{
		AfxMessageBox("Please connect 2 Axis");
		return FALSE;
	}

	// X축과 Y축의 번호를 임의로 설정합니다.
	m_lAxisNoX = DEFAULT_AXIS_NUMBER_X;
	m_lAxisNoY = DEFAULT_AXIS_NUMBER_Y;

	// 좌표를 초기화합니다.
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;

	// 사용하지 않는 Emergency 신호를 UNUSED로 설정
	dwRetCode = AxmSignalSetStop(m_lAxisNoX, EMERGENCY_STOP, UNUSED);
	dwRetCode = AxmSignalSetStop(m_lAxisNoY, EMERGENCY_STOP, UNUSED);

	// Limit Level을 HIGH로 설정합니다. (구형은 LOW)
	dwRetCode = AxmSignalSetLimit(m_lAxisNoX, EMERGENCY_STOP, HIGH, HIGH);
	dwRetCode = AxmSignalSetLimit(m_lAxisNoY, EMERGENCY_STOP, HIGH, HIGH);

	// Unit Per Pulse를 1250:1048576으로 설정합니다. (구형은 10)
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoX, 1250, 1048576);
	dwRetCode = AxmMotSetMoveUnitPerPulse(m_lAxisNoY, 1250, 1048576);

	// Edit Contorl에 초기값을 설정합니다.
	SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_X_INPUT_DEC, DEFAULT_DEC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, DEFAULT_VEL, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_ACC, DEFAULT_ACC, 1);
	SetDlgItemDouble(IDC_EDT_Y_INPUT_DEC, DEFAULT_DEC, 1);
	m_edtXMovePos.SetWindowText("0");
	m_edtYMovePos.SetWindowText("0");

	// 원점검색 진행율을 표시할 프로그래스바를 초기화합니다.
	m_prgXHomeRate.SetRange(0, 100);
	m_prgXHomeRate.SetStep(1);
	m_prgXHomeRate.SetPos(0);
	m_prgXHomeRate.EnableWindow(FALSE);
	m_prgYHomeRate.SetRange(0, 100);
	m_prgYHomeRate.SetStep(1);
	m_prgYHomeRate.SetPos(0);
	m_prgYHomeRate.EnableWindow(FALSE);

	// Dialog내에서의 XY Stage의 위치를 저장합니다.
	m_pcstage.GetWindowRect(&m_rectStage);
	ScreenToClient(&m_rectStage);

	// X, Y축 슬라이더를 초기화합니다.
	nSliderEndPosX = m_rectStage.right - m_rectStage.left - (MARGIN * 2);
	nSliderEndPosY = m_rectStage.bottom - m_rectStage.top - (MARGIN * 2);
	m_sliX.SetRange(0, nSliderEndPosX, FALSE);
	m_sliY.SetRange(0, nSliderEndPosY, FALSE);
	m_sliX.SetPos(0);
	m_sliY.SetPos(nSliderEndPosY);

	// X, Y축 Vel, Acc, Dec 슬라이더를 초기화합니다.
	m_sliX_vel.SetRange(0, 100, FALSE);
	m_sliY_vel.SetRange(0, 100, FALSE);
	m_sliX_vel.SetRangeMin(0);
	m_sliY_vel.SetRangeMin(0);
	m_sliX_vel.SetRangeMax(100);
	m_sliY_vel.SetRangeMax(100);
	m_sliX_vel.SetPos(DEFAULT_VEL);
	m_sliY_vel.SetPos(DEFAULT_VEL);

	m_sliX_acc.SetRange(0, 100, FALSE);
	m_sliY_acc.SetRange(0, 100, FALSE);
	m_sliX_acc.SetRangeMin(0);
	m_sliY_acc.SetRangeMin(0);
	m_sliX_acc.SetRangeMax(100);
	m_sliY_acc.SetRangeMax(100);
	m_sliX_acc.SetPos(DEFAULT_ACC);
	m_sliY_acc.SetPos(DEFAULT_ACC);

	m_sliX_dec.SetRange(0, 100, FALSE);
	m_sliY_dec.SetRange(0, 100, FALSE);
	m_sliX_dec.SetRangeMin(0);
	m_sliY_dec.SetRangeMin(0);
	m_sliX_dec.SetRangeMax(100);
	m_sliY_dec.SetRangeMax(100);
	m_sliX_dec.SetPos(DEFAULT_DEC);
	m_sliY_dec.SetPos(DEFAULT_DEC);



	// X, Y축의 이동 확인 변수를 초기화합니다.
	m_bXIsMoving = FALSE;

	m_bYIsMoving = FALSE;

	// Stop 명령 확인 변수를 초기화합니다.
	m_bXStop = FALSE;
	m_bYStop = FALSE;

	// 좌표 보정치값을 계산합니다.
	m_posRevisionX = DEFAULT_REVISION_X / (m_rectStage.right - m_rectStage.left -(MARGIN * 2));
	m_posRevisionY = DEFAULT_REVISION_Y / (m_rectStage.bottom - m_rectStage.top -(MARGIN * 2));
	// X, Y축의 현재 위치와 각종 상태값을 주기적으로 표시할 타이머를 활성화합니다.
	SetTimer(TM_DISPLAY, 100, NULL);

	return TRUE;
} 

void CMy2017134025LJTDlg::SetDlgItemDouble(int nID, double value, int nPoint)
{
	CString sTemp, sTemp2;
	sTemp2.Format("%%.%df", nPoint);
	sTemp.Format(sTemp2, value);
	GetDlgItem(nID)->SetWindowText(sTemp);
} 

double CMy2017134025LJTDlg::GetDlgItemDouble(int nID)
{
	double dRet;
	CString sTemp;
	GetDlgItem(nID)->GetWindowText(sTemp);
	dRet = atof((LPCTSTR)sTemp);
	return dRet;
} 

BOOL CMy2017134025LJTDlg::UpdateState()
{
	DWORD dwRetCode = 0;
	double dUnit = 0.0, dMaxRangeX = 0.0, dMaxRangeY = 0.0;
	long lPulse = 0;

	// 좌표 보정치값을 계산합니다.
	dwRetCode = AxmMotGetMoveUnitPerPulse(m_lAxisNoX, &dUnit, &lPulse);
	dMaxRangeX = DEFAULT_REVISION_X * (double)(DEFAULT_PULSE / DEFAULT_UNIT) * (dUnit / lPulse);
	m_posRevisionX = dMaxRangeX / (m_rectStage.right - m_rectStage.left - (MARGIN * 2));

	dwRetCode = AxmMotGetMoveUnitPerPulse(m_lAxisNoY, &dUnit, &lPulse);
	dMaxRangeY = DEFAULT_REVISION_Y * (double)(DEFAULT_PULSE / DEFAULT_UNIT) * (dUnit / lPulse);
	m_posRevisionY = dMaxRangeY / (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2));

	Invalidate();

	return TRUE;
} 

// CMy2017134025LJTDlg 메시지 처리기

CString CMy2017134025LJTDlg::TranslateAxmResult(DWORD dwAxmResult)
{
	CString strResult;

		switch(dwAxmResult){
			case AXT_RT_SUCCESS :strResult.Format("[0000] API함수 수행 성공"); break;
			case AXT_RT_OPEN_ERROR :strResult.Format("[1001] 라이브러리가 오픈되어 있지 않음"); break;
			case AXT_RT_OPEN_ALREADY : strResult.Format("[1002] 라이브러리가 오픈되어 있고 사용 중임"); break;
			case AXT_RT_NOT_OPEN :strResult.Format("[1053] 라이브러리 초기화 실패"); break;
			case AXT_RT_NOT_SUPPORT_VERSION :strResult.Format("[1054] 지원하지 않는 하드웨어"); break;
			case AXT_RT_NETWORK_ERROR : strResult.Format("[1152] 네트워크에 연결된 슬레이브 노드 연결되지 않았거나 연결상태가 불량함"); break;
			case AXT_RT_MOTION_OPEN_ERROR :strResult.Format("[4001] 모션 라이브러리 Open 실패"); break;
			case AXT_RT_MOTION_NOT_MODULE :strResult.Format("[4051] 시스템에 장착된 모션 모듈이 없음"); break;
			case AXT_RT_MOTION_INVALID_AXIS_NO :strResult.Format("[4101] 해당 축이 존재하지 않음"); break;
			case AXT_RT_MOTION_INVALID_METHOD : strResult.Format("[4102] 해당 축 구동에 필요한 설정이 잘못됨"); break;
			case AXT_RT_MOTION_INVALID_VELOCITY : strResult.Format("[4113] 모션 구동 속도값이 0으로 설정되어 모션 에러 발생"); break;
			case AXT_RT_MOTION_INVALID_ACCELTIME : strResult.Format("[4114] 모션 구동 가속 시간 값이 0으로 설정되어 모션 에러 발생"); break;
			case AXT_RT_MOTION_ERROR_IN_MOTION : strResult.Format("[4152] 모션 구동 중에다른 모션 구동 함수를 실행함"); break;
			case AXT_RT_MOTION_ERROR : strResult.Format("[4153] 다축 구동 정지 함수 실행중 에러 발생함"); break;
			case AXT_RT_MOTION_HOME_SEARCHING : strResult.Format("[4201] 홈을 찾고 있는중일 때 다른 모션 함수를 사용함"); break;
			case AXT_RT_MOTION_SETTING_ERROR : strResult.Format("[4255] 속도, 가속도 등설정이 잘못됨"); break;
			case AXT_RT_PROTECTED_DURING_SERVOON : strResult.Format("[4260] 서보 온 상태에서 사용할 수 없는 함수 또는 입력 값을 사용하였음"); break;
			case AXT_RT_HW_ACCESS_ERROR : strResult.Format("[4261] 보드의 H/W 접근 오류가 발생함"); break;
			default: strResult.Format("기타에러발생"); break;
		}

	return strResult;
} 


BOOL CMy2017134025LJTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	InitState();

	m_pPTPThread = NULL;

	return TRUE;
}

void CMy2017134025LJTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy2017134025LJTDlg::OnPaint()
{
		CString strPosX, strPosY, strEndPos;
		if (IsIconic())
		{
			CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

			SendMessage(WM_ICONERASEBKGND,reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

			// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect; 
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// 아이콘을 그립니다.
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			CDialog::OnPaint();
			CClientDC dc(this);

			// XY Stage 배경을 그립니다.
			dc.Rectangle(&m_rectStage);

			// XY Stage의 좌측 벽면에서 MARGIN값만큼 떨어진 위치에 Y축 기준선을 그립니다.
			dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN);
			dc.LineTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);

			// XY Stage의 하단 벽면에서 MARGIN값만큼 떨어진 위치에 X축 기준선을 그립니다.
			dc.MoveTo(m_rectStage.left + MARGIN, m_rectStage.bottom - MARGIN);
			dc.LineTo(m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

			// 각 축의 시작점(0,0)을 표시합니다.
			dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.bottom - MARGIN + 5,"(0, 0)");

			// X축의 끝 지점(?, 0)을 표시합니다.
			strEndPos.Format("(%d, 0)", (int)((double)((m_rectStage.right - m_rectStage.left)- (MARGIN * 2)) * m_posRevisionX));
			dc.TextOut(m_rectStage.right - MARGIN - 30, m_rectStage.bottom - MARGIN + 5,strEndPos);

			// Y축의 끝 지점(0, ?)을 표시합니다.
			strEndPos.Format("(0, %d)", (int)((double)((m_rectStage.bottom -m_rectStage.top) - (MARGIN * 2)) * m_posRevisionY));
			dc.TextOut(m_rectStage.left + MARGIN - 15, m_rectStage.top + MARGIN - 20,strEndPos);

			if (btn_ptp == true) {
				int iNewPointRectY[PTP_MAX];

				for (int i = 0; i < ptp_click_count; i++)
				{
					iNewPointRectY[i] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - ptp_points[i][1];
					if (iNewPointRectY[i] > 0)
					{
						dc.Rectangle((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 5,
							(m_rectStage.left + MARGIN + ptp_points[i][0]) - 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) - 5);
						strPosX.Format("X:%d", (int)(ptp_points[i][0] * m_posRevisionX));
						strPosY.Format("Y:%d", (int)(ptp_points[i][1] * m_posRevisionY));
						dc.TextOut((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 5, strPosX);
						dc.TextOut((m_rectStage.left + MARGIN + ptp_points[i][0]) + 5, (m_rectStage.top + MARGIN + iNewPointRectY[i]) + 20, strPosY);
					}
				}
				if (ptp_click_count == PTP_MAX)
				{
					for (int i = 0; i < ptp_click_count - 1; i++)
					{
						dc.MoveTo(m_rectStage.left + MARGIN + ptp_points[i][0], m_rectStage.top + MARGIN + iNewPointRectY[i]);		/////  현재 포지션을 특정위치로 이동
						dc.LineTo(m_rectStage.left + MARGIN + ptp_points[i + 1][0], m_rectStage.top + MARGIN + iNewPointRectY[i + 1]);	/////  이동된 특정위치에서 지정한 지점까지 선 그림
					}
				}
			}

			else if (btn_cp == true) {
				int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - cp_dispos[1];

				dc.Ellipse((m_rectStage.left + MARGIN + cp_dispos[0]) - cp_radious, (m_rectStage.top + MARGIN + iNewPointY) - cp_radious,
					(m_rectStage.left + MARGIN + cp_dispos[0]) + cp_radious, (m_rectStage.top + MARGIN + iNewPointY) + cp_radious);

				dc.Rectangle((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 5,
					(m_rectStage.left + MARGIN + cp_dispos[0]) - 5, (m_rectStage.top + MARGIN + iNewPointY) - 5);

				strPosX.Format("X:%d", m_realPointX);
				strPosY.Format("Y:%d", m_realPointY);
				dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 5, strPosX);
				dc.TextOut((m_rectStage.left + MARGIN + cp_dispos[0]) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 20, strPosY);

			}

			else if (btn_Bezier == true) {

			}


			else if (btn_ptp == false && btn_cp == false && btn_Bezier == false){
			// point 위치를 나타내는 작은 사각형을 그립니다. Y좌표는 상하 반전을 수행합니다.
			int iNewPointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - m_pointY;
			dc.Rectangle((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top + MARGIN + iNewPointY) + 5,
			(m_rectStage.left + MARGIN + m_pointX) - 5, (m_rectStage.top + MARGIN + iNewPointY) - 5);

			// 포인터 위치 우측 하단에 작게 좌표를 표시합니다.
			strPosX.Format("X:%d", m_realPointX);
			strPosY.Format("Y:%d", m_realPointY);
			dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +MARGIN + iNewPointY) + 5, strPosX);
			dc.TextOut((m_rectStage.left + MARGIN + m_pointX) + 5, (m_rectStage.top +MARGIN + iNewPointY) + 20, strPosY);
			}
		}
	
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy2017134025LJTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2017134025LJTDlg::OnBnClickedChkXServoOn()
{
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_X_SERVO_ON);
	// 지정 축의 Servo On/Off 신호를 출력합니다.
	dwRetCode = AxmSignalServoOn(m_lAxisNoX, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	}
}


void CMy2017134025LJTDlg::OnBnClickedBtnXHomeSearch()
{
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast,	dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// X축이 Servo Off이면 이 작업을 수행하지 않습니다.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// X축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// - 그 외의 정보는 AXM 매뉴얼을 참고하시기 바랍니다.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop 확인 변수를 초기화합니다.
	m_bXStop = FALSE;

	// Edit control에서 속도, 가속도 값을 받아옵니다.
	m_edtXInputVel.GetWindowText(strVel);
	strVel = strVel.Trim();
	dHomeVelFirst = atof(strVel);
	if (dHomeVelFirst < DEFAULT_HOME_VEL_FIRST)
	{
		dHomeVelFirst = DEFAULT_HOME_VEL_FIRST;
	}
	dHomeVelSecond = dHomeVelFirst;
	dHomeVelThird = dHomeVelSecond / 2;
	dHomeVelLast = dHomeVelThird / 3;

	m_edtXInputAcc.GetWindowText(strAcc);
	strAcc = strAcc.Trim();
	dHomeAccFirst = atof(strAcc);
	if (dHomeAccFirst < DEFAULT_HOME_ACC_FIRST)
	{
		dHomeAccFirst = DEFAULT_HOME_ACC_FIRST;
	}
	dHomeAccSecond = dHomeAccFirst;
	// 원점검색에 사용되는 검색방법을 설정합니다.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoX, DIR_CCW, Signal_HomeSensor,
	UNUSED, 1000, 0);

	// 원점검색에 사용되는 단계별 속도를 설정합니다.
	dwRetCode = AxmHomeSetVel(m_lAxisNoX, dHomeVelFirst, dHomeVelSecond,
	dHomeVelThird, dHomeVelLast,
	dHomeAccFirst, dHomeAccSecond);
	if(dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// X축 원점검색을 진행합니다.
	m_prgXHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoX);
	if(dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult);
		m_prgXHomeRate.EnableWindow(FALSE); 
		return;
	}

	// 원점 검색 진행 상황을 표시할 타이머를 시작합니다.
	m_bXIsMoving = TRUE;
	SetTimer(TM_X_HOME_INFO, 200, NULL); // 일정한 주기로 변경되는 원점검색 관련정보를 Control에 반영할 타이머를 실행합니다.

}


void CMy2017134025LJTDlg::OnBnClickedBtnXPosClear()
{
	DWORD dwRetCode;
	CString strResult;

	// Command위치와 Actual위치를 지정한 값으로 설정합니다.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoX, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	} 
}


void CMy2017134025LJTDlg::OnBnClickedBtnXSstop()
{
	 AxmMoveSStop(m_lAxisNoX);
	 m_bXIsMoving = FALSE;
	 m_bXStop = TRUE; 
}


void CMy2017134025LJTDlg::OnBnClickedBtnXEstop()
{
 AxmMoveEStop(m_lAxisNoX);
 m_bXIsMoving = FALSE;
 m_bXStop = TRUE;
}


void CMy2017134025LJTDlg::OnBnClickedChkYServoOn()
{
	DWORD dwOnOff, dwRetCode;
	CString strResult;

	dwOnOff = IsDlgButtonChecked(IDC_CHK_Y_SERVO_ON);
	// 지정 축의 Servo On/Off 신호를 출력합니다.
	dwRetCode = AxmSignalServoOn(m_lAxisNoY, dwOnOff);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmSignalServoOn fail.\nError Msg : " + strResult);
	} 
}


void CMy2017134025LJTDlg::OnBnClickedBtnYHomeSearch()
{
	double dHomeVelFirst, dHomeVelSecond, dHomeVelThird, dHomeVelLast,dHomeAccFirst, dHomeAccSecond;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult, strVel, strAcc;

	// Y축이 Servo Off이면 이 작업을 수행하지 않습니다.
	dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus == FALSE)
	{
		return;
	}

	// Y축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// - 그 외의 정보는 AXM 매뉴얼을 참고하시기 바랍니다.
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	// Stop 확인 변수를 초기화합니다.
	m_bYStop = FALSE;

	// Edit control에서 속도, 가속도 값을 받아옵니다.
	m_edtYInputVel.GetWindowText(strVel);
	strVel = strVel.Trim();
	dHomeVelFirst = atof(strVel);
	if (dHomeVelFirst < DEFAULT_HOME_VEL_FIRST)
	{
		dHomeVelFirst = DEFAULT_HOME_VEL_FIRST;
	}
	dHomeVelSecond = dHomeVelFirst;
	dHomeVelThird = dHomeVelSecond / 2;
	dHomeVelLast = dHomeVelThird / 3;

	m_edtYInputAcc.GetWindowText(strAcc);
	strAcc = strAcc.Trim();
	dHomeAccFirst = atof(strAcc);
	if (dHomeAccFirst < DEFAULT_HOME_ACC_FIRST)
	{
		dHomeAccFirst = DEFAULT_HOME_ACC_FIRST;
	}
	dHomeAccSecond = dHomeAccFirst;

	// 원점검색에 사용되는 검색방법을 설정합니다.
	dwRetCode = AxmHomeSetMethod(m_lAxisNoY, DIR_CCW, Signal_HomeSensor,
	UNUSED, 1000, 0);

	// 원점검색에 사용되는 단계별 속도를 설정합니다.
	dwRetCode = AxmHomeSetVel(m_lAxisNoY, dHomeVelFirst, dHomeVelSecond,dHomeVelThird, dHomeVelLast, dHomeAccFirst, dHomeAccSecond);
	if(dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home Search velocity set fail.\nError Msg : " + strResult);
	}

	// Y축 원점검색을 진행합니다.
	m_prgYHomeRate.EnableWindow(TRUE);
	dwRetCode = AxmHomeSetStart(m_lAxisNoY);
	if(dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Home search fail.\nError Msg : " + strResult);
		m_prgYHomeRate.EnableWindow(FALSE);
		return;
	}

	// 원점 검색 진행 상황을 표시할 타이머를 시작합니다.
	m_bYIsMoving = TRUE;
	SetTimer(TM_Y_HOME_INFO, 200, NULL); // 일정한 주기로 변경되는 원점검색 관련정보를 Control에 반영할 타이머를 실행합니다. 
}


void CMy2017134025LJTDlg::OnBnClickedBtnYPosClear()
{
	DWORD dwRetCode; 
	CString strResult;

	// Command위치와 Actual위치를 지정한 값으로 설정합니다.
	dwRetCode = AxmStatusSetPosMatch(m_lAxisNoY, 0.0);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis AxmStatusSetPosMatch fail.\nError Msg : " + strResult);
	} 
}


void CMy2017134025LJTDlg::OnBnClickedBtnYSstop()
{
	 AxmMoveSStop(m_lAxisNoY);
	 m_bYIsMoving = FALSE;
	 m_bYStop = TRUE; 
}


void CMy2017134025LJTDlg::OnBnClickedBtnYEstop()
{

 AxmMoveEStop(m_lAxisNoY);
 m_bYIsMoving = FALSE;
 m_bYStop = TRUE; 

}


void CMy2017134025LJTDlg::OnBnClickedBtnLoadFile()
{
	CString temp;
	CFileDialog dlg(TRUE, "Mot", NULL, OFN_HIDEREADONLY, "AXM File (*.mot)|*.mot|AllFiles (*.*)|*.*||");

	if (dlg.DoModal() == IDOK)
	{
		LPTSTR strFilename;
		temp = dlg.GetPathName();
		strFilename = temp.GetBuffer(0);

		// 함수 실행 성공시 지정한 Mot파일의 설정값으로 모션축 설정이 일괄 변경됩니다.
		if (AxmMotLoadParaAll(strFilename) != AXT_RT_SUCCESS)
		{
			AfxMessageBox("File load fail!");
		}
		else
		{
			AfxMessageBox("File load success!");
			UpdateState();
		}
	}  
}


void CMy2017134025LJTDlg::OnBnClickedBtnBothHomeSearch()
{
	OnBnClickedBtnXHomeSearch();
	OnBnClickedBtnYHomeSearch(); 
}


void CMy2017134025LJTDlg::OnBnClickedBtnMoveZeroPos()
{
	double dPosX = 0.0, dPosY = 0.0;
	int nSliderEndPosY = m_sliY.GetRangeMax();

	// (0, 0) 좌표로 이동합니다.
	m_pointX = 0;
	m_pointY = 0;
	m_realPointX = 0;
	m_realPointY = 0;
	Invalidate();
	m_sliX.SetPos(m_pointX);
	m_sliY.SetPos(nSliderEndPosY - m_pointY);

	AxmMoveStartPos(m_lAxisNoX, dPosX,
	GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
	GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
	GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

	AxmMoveStartPos(m_lAxisNoY, dPosY,
	GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
	GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
	GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC)); 
}


void CMy2017134025LJTDlg::OnBnClickedBtnBothEstop()
{
	// 전 축에 대한 ESTOP 명령을 수행합니다.
	OnBnClickedBtnXEstop();
	OnBnClickedBtnYEstop(); 
}


void CMy2017134025LJTDlg::OnBnClickedBtnXAlarmClear()
{
	DWORD dwRetCode = 0;
	CString strResult;

	dwRetCode = AxmSignalServoAlarmReset(m_lAxisNoX, ENABLE);
	if(dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis Alarm Clear fail.\nError Msg : " + strResult);
		return;
	} 
}


void CMy2017134025LJTDlg::OnBnClickedBtnYAlarmClear()
{
	DWORD dwRetCode = 0;
	CString strResult;

	dwRetCode = AxmSignalServoAlarmReset(m_lAxisNoY, ENABLE);
	if(dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("Y Axis Alarm Clear fail.\nError Msg : " + strResult);
		return;
	}
}


void CMy2017134025LJTDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// "종료 하시겠습니까?" 확인 팝업 창을 출력하여 종료 여부를 한 번 더 확인합니다.
	if (AfxMessageBox("종료 하시겠습니까?", MB_OKCANCEL) == IDCANCEL)
	{
		return;
	} 
	CDialogEx::OnClose();
}


void CMy2017134025LJTDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// 종료 처리를 위하여 AXL 라이브러리가 열려 있으면 닫습니다.
	if (AxlIsOpened())
	{
		AxlClose();
	} 
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CMy2017134025LJTDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;

	CSliderCtrl *pSlider = (CSliderCtrl *)pScrollBar;
	double dPosX = 0.0;

	// 매 이벤트마다 마지막으로 자동호출되는 이벤트에만 작업을 수행합니다.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}

	// X축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion(..) : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// ...
	dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	switch (pSlider->GetDlgCtrlID())
	{
		case IDC_SLI_X:
		m_pointX = pSlider->GetPos();
		break;
	}

	Invalidate();

	UpdateData(TRUE);

	dPosX = m_pointX * m_posRevisionX;
	m_realPointX = (int)dPosX;

	// 이동 정보값을 각 Edit Control에서 읽어옵니다. 
	dVel = GetDlgItemDouble(IDC_EDT_X_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_X_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_X_INPUT_DEC);

	// Absolute 좌표계 이동으로 설정합니다.
	AxmMotSetAbsRelMode(m_lAxisNoX, POS_ABS_MODE);

	// 이동을 수행합니다.
	dwRetCode = AxmMoveStartPos(m_lAxisNoX, dPosX, dVel, dAcc, dDec);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
		strResult = TranslateAxmResult(dwRetCode);
		AfxMessageBox("X Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
	}
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy2017134025LJTDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	double dPosX = 0.0, dPosY = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	int nSliderEndPosY = m_sliY.GetRangeMax();
	CWinThread* pWinThread;	//쓰레드 변수


	if (m_bXIsMoving || m_bYIsMoving)
	{
		return;
	}

	// 영역 판단
	CRect rect1(&m_rectStage);
	CRect rect2(m_rectStage.left + MARGIN, m_rectStage.top + MARGIN, m_rectStage.right - MARGIN, m_rectStage.bottom - MARGIN);

	if (rect1.PtInRect(point))
	{
		if (rect2.PtInRect(point))
		{
			Set_Cursor = 2;
		}
		else
		{
			Set_Cursor = 1;
		}
	}
	
	else
	{
		Set_Cursor = 0;
	}

	if (Set_Cursor == 1)
	{
		AfxMessageBox("표현할 수 없는 위치입니다.");
	}
	
	else if(Set_Cursor == 2)
	{
		// PTP Mode
		if (btn_ptp == true) {
			ptp_points[ptp_click_count][0] = point.x - (m_rectStage.left + MARGIN);
			ptp_points[ptp_click_count][1] = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y - (m_rectStage.top + MARGIN));

			Invalidate();
			m_sliX.SetPos(ptp_points[ptp_click_count][0]);
			m_sliY.SetPos(nSliderEndPosY - ptp_points[ptp_click_count][1]);  //////  이 부분 역시 y좌표계를 상하 반전하여 적용

			ptp_click_count++;

			if (ptp_click_count == PTP_MAX)
			{
				Invalidate();
				UpdateWindow();

				DWORD StatusX = FALSE, StatusY = FALSE;

				lAxis[0] = 0;
				lAxis[1] = 1;

				AxmContiWriteClear(lCoordinate);
				AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
				AxmContiSetAbsRelMode(lCoordinate, 0);
				AxmContiBeginNode(lCoordinate);
				for (int i = 0; i < PTP_MAX; i++)
				{
					dPos[0] = ptp_points[i][0] * m_posRevisionX;
					dPos[1] = ptp_points[i][1] * m_posRevisionY;

					AxmLineMove(lCoordinate, dPos,
						GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
						GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
						GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
				}

				pWinThread = AfxBeginThread(ThreadStart, this);
				AxmContiEndNode(lCoordinate);
				AxmContiStart(lCoordinate, 0, 0);
				ptp_click_count = 0;
				return;
			}
		}

		//CP Mode
		else if (btn_cp == true) {
			lAxis[0] = 0;
			lAxis[1] = 1;
			
			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(nSliderEndPosY - m_pointY);

			m_pointX = point.x - (m_rectStage.left + MARGIN);
			// Y좌표계를 상하 반전하여 적용합니다.
			m_pointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y -
				(m_rectStage.top + MARGIN));

			cp_dispos[0] = m_pointX;
			cp_dispos[1] = m_pointY;

			Invalidate();
			UpdateWindow();

			AxmContiWriteClear(lCoordinate);
			AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
			AxmContiSetAbsRelMode(lCoordinate, 0);
			AxmContiBeginNode(lCoordinate);

			for (int i = 0; i < 360; i++) {
				dPos[0] = (m_pointX + cos(i * (PI / 180)) * cp_radious) * m_posRevisionX;
				dPos[1] = (m_pointY + sin(i * (PI / 180)) * cp_radious) * m_posRevisionY;

				if (i == 0)
				{
					cp_start[0] = dPos[0];
					cp_start[1] = dPos[1];
				}

				AxmLineMove(lCoordinate, dPos,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

			}

			pWinThread = AfxBeginThread(ThreadStart, this);
			AxmContiEndNode(lCoordinate);
			AxmContiStart(lCoordinate, 0, 0);
			return;
		}


		//Bezier Mode
		else if (btn_Bezier == true) {

			double sp[2] = { 10.0, 10.0 };
			double c1[2] = { 10.0, 60.0 };
			double c2[2] = { 60.0, 10.0 };
			double ep[2] = { 60.0, 60.0 };
			//double t[11] = { 0, 0.1, 0.2, 0.3 , 0.4, 0.5 , 0.6 , 0.7, 0.8, 0.9, 1.0 };
			

			double t = 0.0;

			lAxis[0] = 0;
			lAxis[1] = 1;

			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(nSliderEndPosY - m_pointY);

			m_pointX = point.x - (m_rectStage.left + MARGIN);
			// Y좌표계를 상하 반전하여 적용합니다.
			m_pointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y -
				(m_rectStage.top + MARGIN));


			Invalidate();
			UpdateWindow();

			AxmContiWriteClear(lCoordinate);
			AxmContiSetAxisMap(lCoordinate, lPosSize, lAxis);
			AxmContiSetAbsRelMode(lCoordinate, 0);
			AxmContiBeginNode(lCoordinate);

			for (t = 0.0; t <= 1.0; t += 0.1)
			{
				dPos[0] = pow(1 - t, 3) * sp[0]
					+ 3 * t * pow(1 - t, 2) * c1[0]
					+ 3 * pow(t, 2) * (1 - t) * c2[0]
					+ pow(t, 3) * ep[0];

				dPos[1] = pow(1 - t, 3) * sp[1]
					+ 3 * t * pow(1 - t, 2) * c1[1]
					+ 3 * pow(t, 2) * (1 - t) * c2[1]
					+ pow(t, 3) * ep[1];

				if (t == 0)
				{
					bezier_start[0] = dPos[0];
					bezier_start[1] = dPos[1];
				}

				AxmLineMove(lCoordinate, dPos,
					GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
					GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
					GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
			}

			pWinThread = AfxBeginThread(ThreadStart, this);
			TRACE("btn_Bezier = %d\n", btn_Bezier);

			AxmContiEndNode(lCoordinate);
			AxmContiStart(lCoordinate, 0, 0);
			return;
		}

		else if (!btn_ptp && !btn_cp && !btn_Bezier){
			m_pointX = point.x - (m_rectStage.left + MARGIN);
			// Y좌표계를 상하 반전하여 적용합니다.
			m_pointY = (m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) - (point.y -
				(m_rectStage.top + MARGIN));

			Invalidate();
			m_sliX.SetPos(m_pointX);
			m_sliY.SetPos(nSliderEndPosY - m_pointY);

			dPosX = m_pointX * m_posRevisionX;
			m_realPointX = (int)dPosX;
			AxmMoveStartPos(m_lAxisNoX, dPosX,
				GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
				GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
				GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));
			if (dwRetCode != AXT_RT_SUCCESS)
			{
				strResult = TranslateAxmResult(dwRetCode);
				AfxMessageBox("X Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
				return;
			}

			dPosY = m_pointY * m_posRevisionY;
			m_realPointY = (int)dPosY;
			AxmMoveStartPos(m_lAxisNoY, dPosY,
				GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
				GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
				GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
			if (dwRetCode != AXT_RT_SUCCESS)
			{
				strResult = TranslateAxmResult(dwRetCode);
				AfxMessageBox("Y Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
				return;
			}
		}
	} 

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMy2017134025LJTDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
 double dXCommPos = 0.0, dXFeedPos = 0.0, dXFeedVel = 0.0;
 double dYCommPos = 0.0, dYFeedPos = 0.0, dYFeedVel = 0.0;
 DWORD dwRetCode = 0, dwValue = 0, dwStepMain = 0, dwStepSub = 0;
 WORD wGainP = 0, wGainI = 0, wGainD = 0;
 long lCheck = 0; 
 CString strResult;
 CString strGainXP, strGainXI, strGainXD, strGainYP, strGainYI, strGainYD;

 switch(nIDEvent){
 case TM_DISPLAY:
 // X, Y축의 지령(Command)위치를 반환합니다.
 AxmStatusGetCmdPos(m_lAxisNoX, &dXCommPos);
 if(m_dXOldCommPos != dXCommPos){
 SetDlgItemDouble(IDC_STC_X_COMMAND_POS, dXCommPos);
 m_dXOldCommPos = dXCommPos;
 }
 AxmStatusGetCmdPos(m_lAxisNoY, &dYCommPos);
 if(m_dYOldCommPos != dYCommPos){
 SetDlgItemDouble(IDC_STC_Y_COMMAND_POS, dYCommPos);
 m_dYOldCommPos = dYCommPos;
 }

 // X, Y축의 실제(Feedback)위치를 반환합니다.
 AxmStatusGetActPos(m_lAxisNoX, &dXFeedPos);
 if(m_dXOldFeedPos != dXFeedPos){
 SetDlgItemDouble(IDC_STC_X_FEEDBACK_POS, dXFeedPos);
 m_dXOldFeedPos = dXFeedPos;
 }
 AxmStatusGetActPos(m_lAxisNoY, &dYFeedPos);
 if(m_dYOldFeedPos != dYFeedPos){
 SetDlgItemDouble(IDC_STC_Y_FEEDBACK_POS, dYFeedPos);
 m_dYOldFeedPos = dYFeedPos;
 }

 // X, Y축의 구동 속도를 반환합니다.
 AxmStatusReadVel(m_lAxisNoX, &dXFeedVel);
 if(m_dXOldFeedVel != dXFeedVel){
 SetDlgItemDouble(IDC_STC_X_FEEDBACK_VEL, dXFeedVel);
 m_dXOldFeedVel = dXFeedVel;
 }
 AxmStatusReadVel(m_lAxisNoY, &dYFeedVel);
if(m_dYOldFeedVel != dYFeedVel){
 SetDlgItemDouble(IDC_STC_Y_FEEDBACK_VEL, dYFeedVel);
 m_dYOldFeedVel = dYFeedVel;
 }

 // X축 외부 센서 및 모터 관련 신호들의 상태를 가져옵니다.
 dwRetCode = AxmStatusReadMechanical(m_lAxisNoX, &dwValue);
 if (dwRetCode == AXT_RT_SUCCESS)
 {
 // + Limit
 lCheck = dwValue & 0x1;
 CheckDlgButton(IDC_CHK_X_LIMIT_P, lCheck);

 // - Limit
 lCheck = (dwValue >> 1) & 0x1;
 CheckDlgButton(IDC_CHK_X_LIMIT_N, lCheck);

 // Alarm
 lCheck = (dwValue >> 4) & 0x1;
 CheckDlgButton(IDC_CHK_X_ALARM, lCheck);

 // Inposition
 lCheck = (dwValue >> 5) & 0x1;
 CheckDlgButton(IDC_CHK_X_IN_POSITION, lCheck);

 // Emergency
 lCheck = (dwValue >> 6) & 0x1;
 CheckDlgButton(IDC_CHK_X_EMG, lCheck);

 // Home
 lCheck = (dwValue >> 7) & 0x1;
 CheckDlgButton(IDC_CHK_X_HOME_SIGNAL, lCheck);
 }

 // In Motion
 dwRetCode = AxmStatusReadMotion(m_lAxisNoX, &dwValue);

 if (dwRetCode == AXT_RT_SUCCESS)
 {
 lCheck = dwValue & QIDRIVE_STATUS_0;
 CheckDlgButton(IDC_CHK_X_IN_MOTION, lCheck);
 // 이동 중이면 이동 관련 컨트롤을 비활성화하고, 이동이 종료하면 활성화합니다.
 if (lCheck)
 {
 m_bXIsMoving = TRUE;
 m_sliX.EnableWindow(FALSE);
 m_btnXHomeSearch.EnableWindow(FALSE);
 m_btnPosMove.EnableWindow(FALSE);
 }
 else
 {
 m_bXIsMoving = FALSE;
 m_sliX.EnableWindow(TRUE);
 m_btnXHomeSearch.EnableWindow(TRUE);
 }
 }

 // Servo On
 dwRetCode = AxmSignalIsServoOn(m_lAxisNoX, &dwValue);
 CheckDlgButton(IDC_CHK_X_SERVO_ON, dwValue);

 // X축의 P 게인 튜닝값을 표시합니다.
 dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX, GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
 strGainXP.Format("%d", (wGainP / 10));
 m_stcXP.SetWindowText(strGainXP);

 // X축의 D 게인 튜닝값을 표시합니다.
 dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD);
 strGainXD.Format("%d", (wGainD / 10));
 m_stcXD.SetWindowText(strGainXD);
 // X축의 I 게인 튜닝값을 표시합니다.
 dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoX,
GAIN_MAIN_ADDRESS_I, GAIN_SUB_ADDRESS, &wGainI);
 strGainXI.Format("%d", (wGainI / 10));
 m_stcXI.SetWindowText(strGainXI);

 // Y축 외부 센서 및 모터 관련 신호들의 상태를 가져옵니다.
 dwRetCode = AxmStatusReadMechanical(m_lAxisNoY, &dwValue);
 if (dwRetCode == AXT_RT_SUCCESS)
 {
 // + Limit
 lCheck = dwValue & 0x1;
 CheckDlgButton(IDC_CHK_Y_LIMIT_P, lCheck);

 // - Limit
 lCheck = (dwValue >> 1) & 0x1;
 CheckDlgButton(IDC_CHK_Y_LIMIT_N, lCheck);

 // Alarm
 lCheck = (dwValue >> 4) & 0x1;
 CheckDlgButton(IDC_CHK_Y_ALARM, lCheck);

 // Inposition
 lCheck = (dwValue >> 5) & 0x1;
 CheckDlgButton(IDC_CHK_Y_IN_POSITION, lCheck);

 // Emergency
 lCheck = (dwValue >> 6) & 0x1;
 CheckDlgButton(IDC_CHK_Y_EMG, lCheck);

 // Home
 lCheck = (dwValue >> 7) & 0x1;
 CheckDlgButton(IDC_CHK_Y_HOME_SIGNAL, lCheck);
 } 

 // In Motion
 dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwValue);
 if (dwRetCode == AXT_RT_SUCCESS)
 {
 lCheck = dwValue & QIDRIVE_STATUS_0;
 CheckDlgButton(IDC_CHK_Y_IN_MOTION, lCheck);
 // 이동 중이면 이동 관련 컨트롤을 비활성화하고, 이동이 종료하면 활성화합니다.
 if (lCheck)
 {
 m_bYIsMoving = TRUE;
 m_sliY.EnableWindow(FALSE);
 m_btnYHomeSearch.EnableWindow(FALSE);
 m_btnPosMove.EnableWindow(FALSE);
 }
 else
 {
 m_bYIsMoving = FALSE;
 m_sliY.EnableWindow(TRUE);
 m_btnYHomeSearch.EnableWindow(TRUE);
 }
 }

 // Servo On
 dwRetCode = AxmSignalIsServoOn(m_lAxisNoY, &dwValue);
 CheckDlgButton(IDC_CHK_Y_SERVO_ON, dwValue);

 // Y축의 P 게인 튜닝값을 표시합니다.
 dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
GAIN_MAIN_ADDRESS_P, GAIN_SUB_ADDRESS, &wGainP);
 strGainYP.Format("%d", (wGainP / 10));
 m_stcYP.SetWindowText(strGainYP);

 // Y축의 D 게인 튜닝값을 표시합니다.
 dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
GAIN_MAIN_ADDRESS_D, GAIN_SUB_ADDRESS, &wGainD); 

 strGainYD.Format("%d", (wGainD / 10));
 m_stcYD.SetWindowText(strGainYD);

 // Y축의 I 게인 튜닝값을 표시합니다.
 dwRetCode = AxlECatReadSdoFromAxisWord(m_lAxisNoY,
GAIN_MAIN_ADDRESS_I, GAIN_SUB_ADDRESS, &wGainI);
 strGainYI.Format("%d", (wGainI / 10));
 m_stcYI.SetWindowText(strGainYI);

 // X축과 Y축의 이동이 종료되면 좌표이동 버튼을 활성화
 if ((m_btnPosMove.IsWindowEnabled() == FALSE) && (m_bXIsMoving == FALSE)
&& (m_bYIsMoving == FALSE) )
 {
 m_btnPosMove.EnableWindow(TRUE);

 // 현재 위치로 스테이지 좌표를 이동합니다.
 m_pointX = (int)(dXFeedPos / m_posRevisionX);
 m_pointY = (int)(dYFeedPos / m_posRevisionY);
 m_realPointX = (int)(dXFeedPos);
 m_realPointY = (int)(dYFeedPos);
 m_sliX.SetPos(m_pointX);
 m_sliY.SetPos(m_sliY.GetRangeMax() - m_pointY);
 Invalidate();
 }

 break;

 case TM_X_HOME_INFO :
 // 긴급 정지일 때에는 종료 처리를 합니다.
 if (m_bXStop)
 {
 m_prgXHomeRate.EnableWindow(FALSE);
 m_bXIsMoving = FALSE;
 m_bXStop = FALSE;
 KillTimer(TM_X_HOME_INFO);
 AfxMessageBox("X Axis Home Search Stop.", MB_OK | MB_ICONQUESTION); 
m_prgXHomeRate.SetPos(0);
 break;
 }

 // X축의 원점검색 진행율을 확인합니다.
 dwRetCode = AxmHomeGetRate(m_lAxisNoX, &dwStepMain, &dwStepSub);
 if(dwRetCode == AXT_RT_SUCCESS){
 m_prgXHomeRate.SetPos(dwStepSub);
 }

 // X축의 원점검색 결과를 확인합니다.
 dwRetCode = AxmHomeGetResult(m_lAxisNoX, &dwValue);
 if(dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
(dwValue == HOME_SEARCHING)))
 {
 if (dwValue == HOME_SUCCESS)
 {
 // 원점 검색 작업이 정상적으로 종료함에 따른 후속 처리를 합니다.
 m_prgXHomeRate.EnableWindow(FALSE);
 m_bXIsMoving = FALSE;
 KillTimer(TM_X_HOME_INFO);
 AfxMessageBox("X Axis Home Search Success.");
 }
 }
 else
 {
 // 원점 검색 작업이 비정상적으로 종료함에 따른 후속 처리를 합니다.
 strResult = TranslateAxmResult(dwRetCode);
 m_bXIsMoving = FALSE;
 m_prgXHomeRate.EnableWindow(FALSE);
 KillTimer(TM_X_HOME_INFO);
 AfxMessageBox("X Axis Home Search fail.\nError Msg : " + strResult, MB_OK
| MB_ICONQUESTION);
 m_prgXHomeRate.SetPos(0);
 } 
 break;

 case TM_Y_HOME_INFO :
 // 긴급 정지일 때에는 종료 처리를 합니다.
 if (m_bYStop)
 {
 m_prgYHomeRate.EnableWindow(FALSE);
 m_bYIsMoving = FALSE;
 m_bYStop = FALSE;
 KillTimer(TM_Y_HOME_INFO);
 AfxMessageBox("Y Axis Home Search Stop.", MB_OK | MB_ICONQUESTION);
 m_prgYHomeRate.SetPos(0);
 break;
 }

 // Y축의 원점검색 진행율을 확인합니다.
 dwRetCode = AxmHomeGetRate(m_lAxisNoY, &dwStepMain, &dwStepSub);
 if(dwRetCode == AXT_RT_SUCCESS){
 m_prgYHomeRate.SetPos(dwStepSub);
 }

 // Y축의 원점검색 결과를 확인합니다.
 dwRetCode = AxmHomeGetResult(m_lAxisNoY, &dwValue);
 if(dwRetCode == AXT_RT_SUCCESS && ((dwValue == HOME_SUCCESS) ||
(dwValue == HOME_SEARCHING)))
 {
 if (dwValue == HOME_SUCCESS)
 {
 // 원점 검색 작업이 정상적으로 종료함에 따른 후속 처리를 합니다.
 m_prgYHomeRate.EnableWindow(FALSE);
 m_bYIsMoving = FALSE;
 KillTimer(TM_Y_HOME_INFO);
 AfxMessageBox("Y Axis Home Search Success.");
 }
 }
 else
	 {
 // 원점 검색 작업이 비정상적으로 종료함에 따른 후속 처리를 합니다.
 strResult = TranslateAxmResult(dwRetCode);
 m_bYIsMoving = FALSE;
 m_prgYHomeRate.EnableWindow(FALSE);
 KillTimer(TM_Y_HOME_INFO);
 AfxMessageBox("Y Axis Home Search fail.\nError Msg : " + strResult, MB_OK
| MB_ICONQUESTION);
 m_prgYHomeRate.SetPos(0);
 }
 break;
 }

	CDialogEx::OnTimer(nIDEvent);
}


void CMy2017134025LJTDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	int nValue = 0;

	double dVel = 0.0, dAcc = 0.0, dDec = 0.0;
	DWORD dwRetCode = 0, dwStatus = 0;
	CString strResult;
	

	CSliderCtrl *pSlider = (CSliderCtrl *)pScrollBar;
	double dPosY = 0.0;
	int nSliderEndPosY = pSlider->GetRangeMax();

	if (pScrollBar)
	{
		if (pScrollBar == (CScrollBar*)&m_sliX_vel)
		{
			nValue = m_sliX_vel.GetPos();
			SetDlgItemDouble(IDC_EDT_X_INPUT_VEL, nValue, 1);
		}

		else if (pScrollBar == (CScrollBar*)&m_sliX_acc)
		{
			nValue = m_sliX_acc.GetPos();
			SetDlgItemDouble(IDC_EDT_X_INPUT_ACC, nValue, 1);
		}

		else if (pScrollBar == (CScrollBar*)&m_sliX_dec)
		{
			nValue = m_sliX_dec.GetPos();
			SetDlgItemDouble(IDC_EDT_X_INPUT_DEC, nValue, 1);
		}

		else if (pScrollBar == (CScrollBar*)&m_sliY_vel)
		{
			nValue = m_sliY_vel.GetPos();
			SetDlgItemDouble(IDC_EDT_Y_INPUT_VEL, nValue, 1);
		}

		else if (pScrollBar == (CScrollBar*)&m_sliY_acc)
		{
			nValue = m_sliY_acc.GetPos();
			SetDlgItemDouble(IDC_EDT_Y_INPUT_ACC, nValue, 1);
		}

		else if (pScrollBar == (CScrollBar*)&m_sliY_dec)
		{
			nValue = m_sliY_dec.GetPos();
			SetDlgItemDouble(IDC_EDT_Y_INPUT_DEC, nValue, 1);
		}
	}

	// 매 이벤트마다 마지막으로 자동호출되는 이벤트에만 작업을 수행합니다.
	if (nSBCode != SB_ENDSCROLL)
	{
		return;
	}

	// Y축이 구동 중이면 이 작업을 수행하지 않습니다.
	// AxmStatusReadMotion(..) : 지정 축의 모션 구동 상태 값을 반환합니다.
	// - dwStatus 비트값의 의미 : (0x00000001) 0 bit. 드라이브 구동 중
	// (0x00000002) 1 bit. 감속 중
	// ...
	dwRetCode = AxmStatusReadMotion(m_lAxisNoY, &dwStatus);
	if (dwRetCode != AXT_RT_SUCCESS || dwStatus & QIDRIVE_STATUS_0)
	{
		return;
	}

	switch (pSlider->GetDlgCtrlID())
	{
		case IDC_SLI_Y:
		m_pointY = nSliderEndPosY - pSlider->GetPos();
		break;
	}
	Invalidate();

	UpdateData(TRUE);

	dPosY = m_pointY * m_posRevisionY;
	m_realPointY = (int)dPosY;

	// 이동 정보값을 각 Edit Control에서 읽어옵니다.
	dVel = GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL);
	dAcc = GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC);
	dDec = GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC);

	// Absolute 좌표계 이동으로 설정합니다.
	AxmMotSetAbsRelMode(m_lAxisNoY, POS_ABS_MODE);

	// 이동을 수행합니다.
	dwRetCode = AxmMoveStartPos(m_lAxisNoY, dPosY, dVel, dAcc, dDec);
	if (dwRetCode != AXT_RT_SUCCESS)
	{
	strResult = TranslateAxmResult(dwRetCode);
	AfxMessageBox("Y Axis AxmMoveStartPos fail.\nError Msg : " + strResult);
	} 


	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL CMy2017134025LJTDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	 // Esc키 입력에 대한 처리를 합니다.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN))&& (pMsg->wParam == VK_ESCAPE))
	{
	// 전 축에 대한 ESTOP 명령을 수행합니다. 
	OnBnClickedBtnBothEstop();
	return TRUE;
	} 

 // Enter키 입력에 대한 처리를 합니다.
	if (((pMsg->message == WM_KEYDOWN) || (pMsg->message == WM_SYSKEYDOWN)) && (pMsg->wParam == VK_RETURN))
	 {
	 // 아무 것도 수행하지 않습니다.
	 return TRUE;
	 }

	return CDialog::PreTranslateMessage(pMsg);
} 


void CMy2017134025LJTDlg::OnBnClickedBtnPosMove()
{
CString strMovePosX, strMovePosY, strMsg;
 int iMovePosX, iMovePosY, iLimitPosX, iLimitPosY;
 double dPosX, dPosY;
 int nSliderEndPosY = m_sliY.GetRangeMax();
 // XY Stage내의 이동 한계점을 계산합니다.
 iLimitPosX = (int)((m_rectStage.right - m_rectStage.left - (MARGIN * 2)) *
m_posRevisionX);
iLimitPosY = (int)((m_rectStage.bottom - m_rectStage.top - (MARGIN * 2)) *
	m_posRevisionX);

// Edit Control에서 입력 좌표 값을 받아옵니다.
m_edtXMovePos.GetWindowText(strMovePosX);
strMovePosX = strMovePosX.Trim();
iMovePosX = atoi(strMovePosX);
// 입력받은 좌표가 XY Stage를 벗어난 좌표이면 에러 팝업을 출력하고 이동하지 않습니다.
if (iMovePosX < 0 || iMovePosX > iLimitPosX)
{
	strMsg.Format("유효한 X좌표 값을 입력하세요. (입력범위 : 0 ~ %d)", iLimitPosX);
	AfxMessageBox(strMsg);
	return;
}

m_edtYMovePos.GetWindowText(strMovePosY);
strMovePosY = strMovePosY.Trim();
iMovePosY = atoi(strMovePosY);
// 입력받은 좌표가 XY Stage를 벗어난 좌표이면 에러 팝업을 출력하고 이동하지 않습니다.
if (iMovePosY < 0 || iMovePosY > iLimitPosY)
{
	strMsg.Format("유효한 Y좌표 값을 입력하세요. (입력범위 : 0 ~ %d)", iLimitPosY);
	AfxMessageBox(strMsg);
	return;
}

// 해당 좌표로 이동합니다.
m_pointX = (int)((double)iMovePosX / (m_posRevisionX));
m_pointY = (int)((double)iMovePosY / (m_posRevisionY));
Invalidate();
m_sliX.SetPos(m_pointX);
m_sliY.SetPos(nSliderEndPosY - m_pointY);

dPosX = iMovePosX;
m_realPointX = iMovePosX;
AxmMoveStartPos(m_lAxisNoX, dPosX,
	GetDlgItemDouble(IDC_EDT_X_INPUT_VEL),
	GetDlgItemDouble(IDC_EDT_X_INPUT_ACC),
	GetDlgItemDouble(IDC_EDT_X_INPUT_DEC));

dPosY = iMovePosY;
m_realPointY = iMovePosY;
AxmMoveStartPos(m_lAxisNoY, dPosY,
	GetDlgItemDouble(IDC_EDT_Y_INPUT_VEL),
	GetDlgItemDouble(IDC_EDT_Y_INPUT_ACC),
	GetDlgItemDouble(IDC_EDT_Y_INPUT_DEC));
}


void CMy2017134025LJTDlg::OnBnClickedRadioPtp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	btn_ptp = true;
	btn_cp = false;
	btn_Bezier = false;
}


void CMy2017134025LJTDlg::OnBnClickedRadioCp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	btn_ptp = false;
	btn_cp = true;
	btn_Bezier = false;

}

void CMy2017134025LJTDlg::OnBnClickedRadioBezier()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	btn_ptp = false;
	btn_cp = false;
	btn_Bezier = true;

}


UINT CMy2017134025LJTDlg::ThreadStart(LPVOID pParam)
{
	CMy2017134025LJTDlg* line_thread = (CMy2017134025LJTDlg*)AfxGetApp()->m_pMainWnd;
	double m_posrevX = 0.504051;
	double m_posrevY = 0.492911;

	CWnd* pWnd = AfxGetMainWnd();
	HWND hWnd = pWnd->m_hWnd;
	HDC h_screen_dc = ::GetDC(hWnd);
	CDC* dc = CDC::FromHandle(h_screen_dc);

	int kk = 0;
	kk = (line_thread->m_rectStage.left) + MARGIN;


	CPen pen;
	pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen* oldPen = dc->SelectObject(&pen);

	if (line_thread->btn_ptp)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			if (abs(line_thread->ptp_points[0][0] * line_thread->m_posRevisionX - dreal_posX) < 10.0 &&
				abs(line_thread->ptp_points[0][1] * line_thread->m_posRevisionX - dreal_posY) < 10.0)
			{
				if (flag == 0)
					flag = 1;
			}

			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}

			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);
			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
				break;
		}
	}

	else if (line_thread->btn_cp)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			if (abs(line_thread->cp_start[0] - dreal_posX) < 10.0 &&
				abs(line_thread->cp_start[1] - dreal_posY) < 10.0)
			{
				if (flag == 0)
					flag = 1;
			}

			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}

			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);
			TRACE("velocity_x1 = %d\n", velocity_x1);
			TRACE("velocity_y1 = %d\n", velocity_y1);
			Sleep(10);
			AxmStatusReadVel(1, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);
			TRACE("velocity_x2 = %d\n", velocity_x2);
			TRACE("velocity_y2 = %d\n", velocity_y2);


			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
			{
				break;
			}
		}
	}

	else if (line_thread->btn_Bezier)
	{
		int flag = 0;
		double dreal_posX = 0, dreal_posY = 0;
		double velocity_x1 = 0.0;
		double velocity_x2 = 0.0;
		double velocity_y1 = 0.0;
		double velocity_y2 = 0.0;

		while (1)
		{
			AxmStatusGetActPos(0, &dreal_posX);
			AxmStatusGetActPos(1, &dreal_posY);

			if (abs(line_thread->bezier_start[0] - dreal_posX) < 10.0 &&
				abs(line_thread->bezier_start[1] - dreal_posY) < 10.0)
			{
				if (flag == 0)
					flag = 1;
			}

			TRACE("Flag = %d\n", flag);

			if (flag == 1)
			{
				dc->MoveTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
				dc->LineTo((dreal_posX / m_posrevX) + kk, 532 - (dreal_posY / m_posrevY));
			}

			AxmStatusReadVel(0, &velocity_x1);
			AxmStatusReadVel(1, &velocity_y1);

			Sleep(10);
			AxmStatusReadVel(0, &velocity_x2);
			AxmStatusReadVel(1, &velocity_y2);


			if ((velocity_x1 == 0 && velocity_x2 == 0) && (velocity_y1 == 0 && velocity_y2 == 0))
			{
				break;
			}
		}
	}


	return 0;
}



void CMy2017134025LJTDlg::OnNMReleasedcaptureSliXVel(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int xVel = m_sliX_vel.GetPos();
	int xAcc = m_sliX_vel.GetPos();
	int xDec = m_sliX_vel.GetPos();
	int yVel = m_sliX_vel.GetPos();
	int yAcc = m_sliX_vel.GetPos();
	int yDec = m_sliX_vel.GetPos();



	*pResult = 0;
}
