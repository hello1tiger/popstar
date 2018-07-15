// popstarDlg.h : header file
//

#if !defined(AFX_POPSTARDLG_H__A2918A2B_F6B1_498D_9D5D_52F9E169AB8B__INCLUDED_)
#define AFX_POPSTARDLG_H__A2918A2B_F6B1_498D_9D5D_52F9E169AB8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPopstarDlg dialog

class CPopstarDlg : public CDialog
{
// Construction
public:
	double getvalue(int left, int right, int top,int bottom,int count,int realcount);//获取评价值，评价值越低越优先处理
	void rbutton();//点击右键，结算此关
	void drawend();//绘制处理后的新局面
	void remove(int x,int y);//清除所选块，并绘制新局面
	void drawselect(int x,int y);//显示此次点击所会消除的块
	void check2(int x,int y,int a);//搜索所选方块关联块
	void nextlevel();//进入下一关，绘制新局面
	int lastcount;//记录最终剩余块数
	void lastgrade(int i);//计算剩余奖励
	void grade(int i);//计算此次消除得分
	bool pop;//控制鼠标左键功能，为true时消除，为false时选择
	bool isempty;//判断某列是否已全部消除
	int count;//记录消除块数
	void move(int x,int y);//(x,y)右边局面左移
	void deal(int x,int y);// (x,y)以上列下移
	void check(int x,int y,int a);//搜索所选方块关联块
	void draw();//绘制新局面
	int score;//记录当前分数
	int goal;//此关目标
	int level;//当前关数
	int start;//阻止持续绘图导致的闪烁
	int wx;int wy;//控件坐标
	int ransto[10][10];//存储颜色值
	bool judge[10][10];//存储标机状态
	bool empty[10][10];//判断是否存在颜色值
	CPopstarDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPopstarDlg)
	enum { IDD = IDD_POPSTAR_DIALOG };
	CButton	m_exit;
	CString	m_level;
	CString	m_goal;
	CString	m_score;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopstarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPopstarDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onnewgame();
	afx_msg void Onexit();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSolve();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPSTARDLG_H__A2918A2B_F6B1_498D_9D5D_52F9E169AB8B__INCLUDED_)
