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
	double getvalue(int left, int right, int top,int bottom,int count,int realcount);//��ȡ����ֵ������ֵԽ��Խ���ȴ���
	void rbutton();//����Ҽ�������˹�
	void drawend();//���ƴ������¾���
	void remove(int x,int y);//�����ѡ�飬�������¾���
	void drawselect(int x,int y);//��ʾ�˴ε�����������Ŀ�
	void check2(int x,int y,int a);//������ѡ���������
	void nextlevel();//������һ�أ������¾���
	int lastcount;//��¼����ʣ�����
	void lastgrade(int i);//����ʣ�ཱ��
	void grade(int i);//����˴������÷�
	bool pop;//�������������ܣ�Ϊtrueʱ������Ϊfalseʱѡ��
	bool isempty;//�ж�ĳ���Ƿ���ȫ������
	int count;//��¼��������
	void move(int x,int y);//(x,y)�ұ߾�������
	void deal(int x,int y);// (x,y)����������
	void check(int x,int y,int a);//������ѡ���������
	void draw();//�����¾���
	int score;//��¼��ǰ����
	int goal;//�˹�Ŀ��
	int level;//��ǰ����
	int start;//��ֹ������ͼ���µ���˸
	int wx;int wy;//�ؼ�����
	int ransto[10][10];//�洢��ɫֵ
	bool judge[10][10];//�洢���״̬
	bool empty[10][10];//�ж��Ƿ������ɫֵ
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
