// popstarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "popstar.h"
#include "popstarDlg.h"
#include <stdlib.h>
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopstarDlg dialog

CPopstarDlg::CPopstarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPopstarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPopstarDlg)
	m_level = _T("");
	m_goal = _T("");
	m_score = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPopstarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPopstarDlg)
	DDX_Control(pDX, IDC_exit, m_exit);
	DDX_Text(pDX, IDC_level, m_level);
	DDX_Text(pDX, IDC_goal, m_goal);
	DDX_Text(pDX, IDC_score, m_score);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPopstarDlg, CDialog)
	//{{AFX_MSG_MAP(CPopstarDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_newgame, Onnewgame)
	ON_BN_CLICKED(IDC_exit, Onexit)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_Solve, OnSolve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopstarDlg message handlers
int aim[9]={1000,3000,6000,8000,10000,13000,15000,17000,20000};
BOOL CPopstarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
lastcount=0;
isempty=true;
pop=false;
count=0;
start=0;
level=1;
goal=1000;
score=0;
m_level="";
m_goal="";
m_score="";
	UpdateData(false);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPopstarDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CPopstarDlg::OnPaint() 
{if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
CDialog::OnPaint();	}
	}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPopstarDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPopstarDlg::Onnewgame() 
{
	// TODO: Add your control notification handler code here
	CRect rc1;
GetDlgItem(IDC_show)->GetWindowRect(&rc1);
ScreenToClient(&rc1);
wx=rc1.left;
wy=rc1.top;
lastcount=0;
isempty=true;
pop=false;
count=0;
level=1;
goal=1000;
score=0;
	start=1;
	CString p;
p.Format("%d",level);
m_level="Level\r\n"+p;
p.Format("%d",goal);
m_goal="Goal\r\n"+p;
p.Format("%d",score);
m_score="Score\r\n"+p;
	UpdateData(false);
	srand(time(NULL));
	draw();
}

void CPopstarDlg::Onexit() 
{
	// TODO: Add your control notification handler code here
	start=0;
	GetDlgItem(IDC_show)->RedrawWindow();
	m_level="";
    m_goal="";
    m_score="";
	UpdateData(false);
	
}



void CPopstarDlg::draw()
{
if(start==1)
{
	CClientDC dc(GetDlgItem(IDC_show));
	CRect rc;
GetDlgItem(IDC_show)->GetClientRect(rc);
int width=rc.Width();
int height=rc.Height();
CRgn reg;
width=width/10;
height=height/10;
CPoint b[4];
for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{ b[0].x=i*width+1;b[0].y=j*height+1;
  b[1].x=i*width+width-1;b[1].y=j*height+1;
  b[2].x=i*width+width-1;b[2].y=j*height+height-1;
  b[3].x=i*width+1;b[3].y=j*height+height-1;
reg.CreatePolygonRgn(b, 4, ALTERNATE);
CBrush brush;
int rander=rand()%5;
ransto[i][j]=rander;
judge[i][j]=true;//表示不符合要求
empty[i][j]=true;//表示不为空
if(rander==0){	brush.CreateSolidBrush(RGB(227,23,13));}//红
else if(rander==1){	brush.CreateSolidBrush(RGB(160,32,240));}//紫
else if(rander==2){	brush.CreateSolidBrush(RGB(255,255,0));}//黄
else if(rander==3){	brush.CreateSolidBrush(RGB(3,168,158));}//蓝
else if(rander==4){	brush.CreateSolidBrush(RGB(127,255,0));}//绿
CBrush *pOldBrush =dc.SelectObject(&brush);
dc.FillRgn(&reg, &brush);
brush.DeleteObject();
reg.DeleteObject();
}
}
start=0;
}	
}

void CPopstarDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(start==1)
{	GetDlgItem(IDC_show)->RedrawWindow();
	
CClientDC dc(GetDlgItem(IDC_show));
	CRect rc;
GetDlgItem(IDC_show)->GetClientRect(rc);

int width=rc.Width();
int height=rc.Height();
CRgn reg;
width=width/10;
height=height/10;
int px=(point.x-wx)/width;
int py=(point.y-wy)/height;
CPoint b[4];


if(!pop)
{check(px,py,ransto[px][py]);
for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{b[0].x=i*width+1;b[0].y=j*height+1;
  b[1].x=i*width+width-1;b[1].y=j*height+1;
  b[2].x=i*width+width-1;b[2].y=j*height+height-1;
  b[3].x=i*width+1;b[3].y=j*height+height-1;
reg.CreatePolygonRgn(b, 4, ALTERNATE);
CBrush brush;
int rander=ransto[i][j];
if(rander==0){	brush.CreateSolidBrush(RGB(227,23,13));}//红
else if(rander==1){	brush.CreateSolidBrush(RGB(160,32,240));}//紫
else if(rander==2){	brush.CreateSolidBrush(RGB(255,255,0));}//黄
else if(rander==3){	brush.CreateSolidBrush(RGB(3,168,158));}//蓝
else if(rander==4){	brush.CreateSolidBrush(RGB(127,255,0));}//绿
else {brush.CreateSolidBrush(RGB(255,255,255));}
CBrush *pOldBrush =dc.SelectObject(&brush);
dc.FillRgn(&reg, &brush);
brush.DeleteObject();
reg.DeleteObject();
if(!judge[i][j]&&empty[i][j])
{dc.MoveTo(i*width+2,j*height+2);dc.LineTo(i*width+width-2,j*height+2);
dc.MoveTo(i*width+width-2,j*height+2);dc.LineTo(i*width+width-2,j*height+height-2);
dc.MoveTo(i*width+width-2,j*height+height-2);dc.LineTo(i*width+2,j*height+height-2);
dc.MoveTo(i*width+2,j*height+height-2);dc.LineTo(i*width+2,j*height+2);}
}
}

if(count>1)
{
for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{deal(i,j);
}
}
for(i=0;i<10;i++)
{move(i,9);
if(isempty) {break;}
isempty=true;
}
}

}
if(pop)
{drawend();
pop=false;start=0;
}
if(count>1) {pop=true;grade(count);}
count=0;

for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{if(empty[i][j]) judge[i][j]=true;}
}

}	
	CDialog::OnLButtonUp(nFlags, point);
}

void CPopstarDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	start=1;
	CDialog::OnLButtonDown(nFlags, point);
}


void CPopstarDlg::check(int x, int y, int a)
{if(empty[x][y]&&judge[x][y])
{if(ransto[x][y]==a)
{judge[x][y]=false;count++;
if(x>0)check(x-1,y,a);
if(x<9)check(x+1,y,a);
if(y>0)check(x,y-1,a);
if(y<9)check(x,y+1,a);
}
}

}

void CPopstarDlg::deal(int x, int y)
{if(judge[x][y]==false)
{	ransto[x][y]=7;empty[x][y]=false;//自上而下
while(y>0)
{if(ransto[x][y-1]==7) break;
ransto[x][y]=ransto[x][y-1];empty[x][y]=empty[x][y-1];judge[x][y]=judge[x][y-1];y--;}
ransto[x][y]=7;empty[x][y]=false;


}
}

void CPopstarDlg::move(int x, int y)
{
for(int i=x+1;i<10;i++)//判断右边是否为空
{if(empty[i][y])isempty=false;}
if(ransto[x][y]==7&&x<9&&!isempty)//自右向左
{
int nextx=x+1;
while(ransto[nextx][y]==7){nextx++;}
for(i=0;i<10;i++)
{ransto[x][i]=ransto[nextx][i];empty[x][i]=empty[nextx][i];judge[x][i]=judge[nextx][i];
ransto[nextx][i]=7;empty[nextx][i]=false;}

}
}


void CPopstarDlg::grade(int i)
{	CString p;
score=score+i*i*5;
p.Format("%d",score);
m_score="Score\r\n"+p;
	UpdateData(false);
}

void CPopstarDlg::lastgrade(int i)
{if(i<11)
{score=score+2000-i*i*20;
	CString p;
	p.Format("%d",score);
m_score="Score\r\n"+p;
	UpdateData(false);
}
}

void CPopstarDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	rbutton();
	CDialog::OnRButtonDown(nFlags, point);
}

void CPopstarDlg::nextlevel()
{CRect rc1;
GetDlgItem(IDC_show)->GetWindowRect(&rc1);
ScreenToClient(&rc1);
wx=rc1.left;
wy=rc1.top;
	start=1;
	CString p;
	 srand(time(NULL));
	draw();
lastcount=0;
	isempty=true;
	pop=false;
count=0;
start=0;
level++;
if(level<10)
goal=aim[level-1];
else
goal=goal+4000;
p.Format("%d",level);
m_level="Level\r\n"+p;
p.Format("%d",goal);
m_goal="Goal\r\n"+p;
	UpdateData(false);

}


CPoint line[50];//存储可消除位置；
int linecount=0;//记录可消除块数
bool isjudge[10][10];//用于记录点是否检查过
int count0,count1,count2,count3,count4;//记录每种颜色个数
int cx,cy;//数组编号
double pcount;//用于记录最小value值
int left,right,top,bottom;//记录可消除块的最左、最右、最下、最上值	

void CPopstarDlg::OnSolve() 
{
	// TODO: Add your control notification handler code here
linecount=2;
while(linecount>1)	
{	int i,j;
	int solve[10][10];//状态保存
	bool so_empty[10][10];
	bool so_judge[10][10];

	for(i=0;i<10;i++)
	{for(j=0;j<10;j++)
	{solve[i][j]=ransto[i][j];
	so_empty[i][j]=empty[i][j];
	so_judge[i][j]=judge[i][j];}
	}
count0=0,count1=0,count2=0,count3=0,count4=0;//记录每种颜色个数
pcount=100000;

for(i=0;i<10;i++)
{for(j=0;j<10;j++)
{isjudge[i][j]=false;
if(ransto[i][j]==0) count0++;
else if(ransto[i][j]==1) count1++;
else if(ransto[i][j]==2) count2++;
else if(ransto[i][j]==3) count3++;
else if(ransto[i][j]==4) count4++;}
}
count=0;linecount=0;
int num=0;int selecttop;
for(i=0;i<10;i++)//寻找最小value数
{for(j=0;j<10;j++)
{if(!isjudge[i][j]&&empty[i][j])
{	left=i;right=i;top=j;bottom=j;
	check2(i,j,ransto[i][j]);
if(count>1)
{line[num].x=i;line[num].y=j;num++;
	double tem;
	if(ransto[i][j]==0) tem=getvalue(left,right,top,bottom,count0,count);
else if(ransto[i][j]==1) tem=getvalue(left,right,top,bottom,count1,count);
else if(ransto[i][j]==2) tem=getvalue(left,right,top,bottom,count2,count);
else if(ransto[i][j]==3) tem=getvalue(left,right,top,bottom,count3,count);
else if(ransto[i][j]==4) tem=getvalue(left,right,top,bottom,count4,count);
if(pcount>tem)
{pcount=tem;cx=i;cy=j;selecttop=top;linecount=count;}//if(tem<pcount)

}count=0;//if(count>1)
}//if(!isjudge[i][j]&&empty[i][j])
}
}
/*for(i=0;i<10;i++)
{for(j=0;j<10;j++)
	{ransto[i][j]=solve[i][j];
	empty[i][j]=so_empty[i][j];
	judge[i][j]=so_judge[i][j];
isjudge[i][j]=false;}
	}
for(i=0;i<num;i++)
{	int a=line[i].x;int b=line[i].y;
	left=a;right=a;top=b;bottom=b;
	check2(a,b,ransto[a][b]);
    if(b>selecttop) break;
	if(top=bottom&&ransto[a][b]!=ransto[cx][cy]) {cx=a;cy=b;linecount=count;break;}

count=0;
}
count=0;*/
if(linecount>1)
{
drawselect(cx,cy);
//Sleep(1000);
remove(cx,cy);
}
else
{rbutton();}
for( i=0;i<10;i++)
{for(int j=0;j<10;j++)
{if(empty[i][j]) judge[i][j]=true;}
}
//Sleep(500);
}//while
}

void CPopstarDlg::check2(int x, int y, int a)
{
if(empty[x][y]&&judge[x][y])
{if(ransto[x][y]==a)
{judge[x][y]=false;count++;isjudge[x][y]=true;
if(left>x)left=x;
if(right<x)right=x;
if(bottom>y)bottom=y;
if(top<y)top=y;
if(x>0){check2(x-1,y,a);}
if(x<9){check2(x+1,y,a);}
if(y>0){check2(x,y-1,a);}
if(y<9){check2(x,y+1,a);}
}
}

}

void CPopstarDlg::drawselect(int x, int y)
{

GetDlgItem(IDC_show)->RedrawWindow();
	
CClientDC dc(GetDlgItem(IDC_show));
	CRect rc;
GetDlgItem(IDC_show)->GetClientRect(rc);
for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{if(empty[i][j]) judge[i][j]=true;}
}
int width=rc.Width();
int height=rc.Height();
CRgn reg;
width=width/10;
height=height/10;
int px=x;
int py=y;
CPoint b[4];
check(px,py,ransto[px][py]);
grade(count);
for(i=0;i<10;i++)
{for(int j=0;j<10;j++)
{b[0].x=i*width+1;b[0].y=j*height+1;
  b[1].x=i*width+width-1;b[1].y=j*height+1;
  b[2].x=i*width+width-1;b[2].y=j*height+height-1;
  b[3].x=i*width+1;b[3].y=j*height+height-1;
reg.CreatePolygonRgn(b, 4, ALTERNATE);
CBrush brush;
int rander=ransto[i][j];
if(rander==0){	brush.CreateSolidBrush(RGB(227,23,13));}//红
else if(rander==1){	brush.CreateSolidBrush(RGB(160,32,240));}//紫
else if(rander==2){	brush.CreateSolidBrush(RGB(255,255,0));}//黄
else if(rander==3){	brush.CreateSolidBrush(RGB(3,168,158));}//蓝
else if(rander==4){	brush.CreateSolidBrush(RGB(127,255,0));}//绿
else {brush.CreateSolidBrush(RGB(255,255,255));}
CBrush *pOldBrush =dc.SelectObject(&brush);
dc.FillRgn(&reg, &brush);
brush.DeleteObject();
reg.DeleteObject();
if(!judge[i][j]&&empty[i][j])
{dc.MoveTo(i*width+2,j*height+2);dc.LineTo(i*width+width-2,j*height+2);
dc.MoveTo(i*width+width-2,j*height+2);dc.LineTo(i*width+width-2,j*height+height-2);
dc.MoveTo(i*width+width-2,j*height+height-2);dc.LineTo(i*width+2,j*height+height-2);
dc.MoveTo(i*width+2,j*height+height-2);dc.LineTo(i*width+2,j*height+2);}
}
}
	
}

void CPopstarDlg::remove(int x, int y)
{

for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{deal(i,j);
}
}
for(i=0;i<10;i++)
{move(i,9);
if(isempty) {break;}
isempty=true;
}
drawend();
count=0;
}

void CPopstarDlg::drawend()
{GetDlgItem(IDC_show)->RedrawWindow();
	
CClientDC dc(GetDlgItem(IDC_show));
	CRect rc;
GetDlgItem(IDC_show)->GetClientRect(rc);

int width=rc.Width();
int height=rc.Height();
CRgn reg;
width=width/10;
height=height/10;

CPoint b[4];
	for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{b[0].x=i*width+1;b[0].y=j*height+1;
  b[1].x=i*width+width-1;b[1].y=j*height+1;
  b[2].x=i*width+width-1;b[2].y=j*height+height-1;
  b[3].x=i*width+1;b[3].y=j*height+height-1;
reg.CreatePolygonRgn(b, 4, ALTERNATE);
CBrush brush;
int rander=ransto[i][j];
if(rander==0){	brush.CreateSolidBrush(RGB(227,23,13));}//红
else if(rander==1){	brush.CreateSolidBrush(RGB(160,32,240));}//紫
else if(rander==2){	brush.CreateSolidBrush(RGB(255,255,0));}//黄
else if(rander==3){	brush.CreateSolidBrush(RGB(3,168,158));}//蓝
else if(rander==4){	brush.CreateSolidBrush(RGB(127,255,0));}//绿
else {brush.CreateSolidBrush(RGB(255,255,255));}
CBrush *pOldBrush =dc.SelectObject(&brush);
dc.FillRgn(&reg, &brush);
brush.DeleteObject();
reg.DeleteObject();
}
}
}

void CPopstarDlg::rbutton()
{
for(int i=0;i<10;i++)
{for(int j=0;j<10;j++)
{if(empty[i][j]) lastcount++;}
}
	lastgrade(lastcount);
	if(score>=goal)
	{nextlevel();}
	else
	{start=0;
	GetDlgItem(IDC_show)->RedrawWindow();
	m_level="";
    m_goal="";
    m_score="";
	UpdateData(false);
	}
}

double CPopstarDlg::getvalue(int left, int right, int top, int bottom, int count,int realcount)//值小的先处理
{int width1=right-left+1;//越宽越先处理
int height1=top-bottom+1;//越高越晚处理
count=count;//颜色越少越先处理
int center=(top+bottom+1)/2;//越往上越先处理
int mul=height1/width1;
return center+(count-realcount)+mul*10;

}
