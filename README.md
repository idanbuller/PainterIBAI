# PainterIBAI
## _Painter Application, C++ Object Oriented Programming, HIT_

![](/Pics/PainterIBAI.png)

✨Idan Buller✨

✨Avichai Iluz✨

## Features
- Create Rectangle
- Create Line
- Create Ellipse
- Create Circle
- Create Square
- Undo paint
- Redo paint
- Save paint into file
- Load paint from file
- Polymorphism as presented in the Class Diagram below:

![](/Pics/ClassDiagram.png)

> The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism, a person at the same time can have different characteristics. Like a man at the same time is a father, a husband, an employee. So the same person posses different behavior in different situations. This is called polymorphism. Polymorphism is considered as one of the important features of Object Oriented Programming.


## Classes
PainterIBAI uses a number of classes based on the polymorphism principals :
- **Figure** - The parent class, Creates CDC object, 2 points and 2 Get functions to save the points.
- **Line** - Inherits from Figure, Creates CDC object and a Draw function.
- **Rectangle** - Inherits from Figure and Creates CDC object.
- **Ellipse** - Inherits from Figure, Creates CDC object and a Draw function.
- **Circle** - Inherits from Ellipse, Creates CDC object and a Draw function.
- **Square** - Inherits from Rectangle, Creates CDC object and a Draw function.


## PainterIBAIDlg.cpp - Main Functions
This file is the worker where all the buttons and wotking functions will be executed.
The following is the functions written inside PainterIBAIDlg.cpp:
#### OnInitDialog
Responsible for the defaults inside the dialog.
For example, the default figure is Rectangle(1).
```C++
CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO1); // Set default radio button to IDC_RADIO1
```
#### OnPaint
Creates CpaintDC type variable to device context for painting.
Generally, this function responsible for the activities inside the dialog, for example:
- Undo - When the user press the 'undo' button, the application rewrite the figures already created in the dialog,
except for the last figure. Therefor the user can undo only the last figure created.
- Draw - Const Virtual function created inside Figure.h, in order to use the CDC object.
```C++
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
```
- Set Icon - Alligns the icon to the center.
```C++
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
```
## Important Functions
MFC contains multiple classes we used in order to create the objects and the painting abillity.
| Class | Description |
| ------ | ------ |
| Serialization | Serialization is the process of writing or reading an object to or from a persistent storage medium such as a disk file. Serialization is ideal for situations where it is desired to maintain the state of structured data (such as C++ classes or structures) during or after the execution of a program. |
| Invalidate | The client area is marked for painting when the next WM_PAINT message occurs. The region can also be validated before a WM_PAINT message occurs by the ValidateRect or ValidateRgn member function. |

## MFC Important Classes
MFC contains multiple classes we used in order to create the objects and the painting abillity.
| Class | Description |
| ------ | ------ |
| CDC | This object allows the user the draw options, the connection to the worker tools and buttons, graphic devices etc. |
| CArchive | Part of the Serialization options, allows to store figures and rewrite them. Used as temporary memory. |
| CPoint | Stores the point values (X,Y) on screen. |
| CpaintDc | Prepares the application window for painting. |

## Buttons
#### OnLBtuttonDown
Allows the appendence of new figures into figs[] (The array responsible for saving the figures created).
The dufault figure is Rectangle.
```C++
switch (KindOfShape)
	{
		case 1:
			figs.Add(new RectangleP(start, start));
			break;
			// Continute the rest of the figures enabled.
```

#### OnLButtonUp

```C++
	if (isPressed)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate();
	}
```
#### OnBnClickedOk
Exit Button
```C++
void CPainterIBAIDlg::OnBnClickedOk() // Exit btn
{
	CDialogEx::OnOK();
}
```

#### OnBnClickedRadio1
Rectangle -- default figure
```C++
void CPainterIBAIDlg::OnBnClickedRadio1()
{
	KindOfShape = 1;
}
```

#### OnBnClickeRadio2
Ellipse
```C++
void CPainterIBAIDlg::OnBnClickedRadio2() // Ellipse
{
	KindOfShape = 2;
}
```

#### OnBnClickedRadio3
Line
```C++
void CPainterIBAIDlg::OnBnClickedRadio3() // Line
{
	KindOfShape = 3;
}
```

#### OnBnClickedRadio4
Circle
```C++
void CPainterIBAIDlg::OnBnClickedRadio4()
{
	KindOfShape = 4;
}
```

#### OnBnClickedRadio5
Square
```C++
void CPainterIBAIDlg::OnBnClickedRadio5()
{
	KindOfShape = 5;
}
```

#### OnBnClickedButton1
Save Button
```C++
void CPainterIBAIDlg::OnBnClickedButton1() // Save Btn
{
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}
```

#### OnBnClickedButton2
Load Button
```C++
void CPainterIBAIDlg::OnBnClickedButton2() // Load Btn
{
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}
```

#### OnBnClickedButton3
Undo Button
```C++
void CPainterIBAIDlg::OnBnClickedButton3() // Undo Btn
{
	if (clear_btn_activated) // if we clear all screen and want to undo it
	{
		for (int i = 0; i < (temp_figs.GetSize()); i++) // restore figs[]
			figs.Add(temp_figs[i]);
		temp_figs.RemoveAll(); // delete temp_figs[]
		clear_btn_activated = false; // clear all btn not activated
		Invalidate();
		return;
	}

	CheckUndo = true;
	Invalidate();
}
```

#### OnBnClickedButton4
Redo Button
```C++
void CPainterIBAIDlg::OnBnClickedButton4() // Redo Btn
{
	CheckUndo = false;
	Invalidate();
}
```

#### OnBnClickedButton5
Clear all button
```C++
void CPainterIBAIDlg::OnBnClickedButton5() // Clear All Btn
{
	clear_btn_activated = true;
	for (int i = 0; i < (figs.GetSize()); i++)
		temp_figs.Add(figs[i]);
	figs.RemoveAll();
	Invalidate();
}
```

# Line Drawing Tutorial
![](/Pics/LineTutorial.PNG)

> When we click the mouse inside the PainterIBAI console the function PainteIBAI::OnLButtonDown is executing.
This function gets point (X, Y) as a parameter, which reffers to the mouse place inside the PainterIBAI console,
and save it in startP and endP variables.
In addition, the function signes the mouse as signed in the class variable called isPressed. Then, the function
PainteIBAI::OnLButtonDown calls the Invalidate() function, which responsible for the deletion of the previous console.
For example, when we are drawing a line inside the console and trying to add one more drawing, Invalidate() makes
the previous line to disappear.

> Invalidate() also creating a ON_PAINT event which calls the PainteIBAI::OnPaint function to draw a line from the start to
the end (startP -> endP).

> On every move of the mouse the function PainteIBAI::OnMouseMove is checking if the mouse is pressed (isPressed). If so, the function is changing the value of endP and and calls the Invalidate() finction to delete the previous line.

> On every release of the mouse the function PainteIBAI::OnLButtonUp is executing the checks is the nouse is presses (iדPresses) and changing the value of endP.

## Background
_The following is a simple method to add a Line figure into our MFC project._
- **Step 1** - At the beginning of the execution the project pops up empty and then the user is able to draw the line.
- **Step 2** - Head to the header file PainterIBAIDlg.h and add the following:
``` C++
// protected:
afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
// public:
afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
afx_msg void OnMouseMove(UINT nFlags, CPoint point);
```
- **step 3** - Head to the PainterIBAIDlg.cpp and add the following:
```C++
// into the BEGIN_MESSAGE_MAP
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()

//into void PainterIBAIDlg::OnPaint()
void PainterIBAIDlg::OnPaint()
{
    CPaintDC dc(this);
    dc.MoveTo(startP);
    dc.LineTo(endP.x, endP.y);
}
```
- **Step 4** - Add the buttons code to the end of the PainterIBAIDlg.cpp
```C++
void PainterIBAIDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    endP = startP = point;
    isPressed = true;
    Invalidate();
    CDialog::OnLButtonDown(nFlags, point);
}
void PainterIBAIDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
    if (isPressed)
    {
        endP = point;
        isPressed = false;
        Invalidate();
    }
    CDialog::OnLButtonUp(nFlags, point);
}
void PainterIBAIDlg::OnMouseMove(UINT nFlags, CPoint point)
{
    if (isPressed)
    {
        endP = point;
        Invalidate();
    }
    CDialog::OnMouseMove(nFlags, point);
}
```
