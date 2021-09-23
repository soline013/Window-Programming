// HelloCode_20201736.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "HelloCode_20201736.h"
#include <afxtempl.h> //템플릿 클래스 정의를 담고 있다.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 애플리케이션 개체입니다.

CWinApp theApp; //응용 프로그램 객체가 전역 변수로 정의되어 있음

using namespace std;

//3차원 좌표를 저장할 수 있는 클래스
//모든 멤버가 public일 때는 class 대신 struct를 사용하면 좀 더 편리하다.
struct Point3D {
    int x, y, z;
    Point3D() {} //템플릿 클래스에 사용할 때는 기본 생성자가 필요하다.
    Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

//CString 타입에 해당하는 해시 함수가 없으므로 정의한다.
template <> UINT AFXAPI HashKey(CString& str) {
    LPCTSTR key = (LPCTSTR)str;
    return HashKey(key); //LPCTSTR 타입의 해시 함수를 재호출한다.
}

int main() //전형적인 c 프로그램의 실행 시작점
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0)) //AfxWinInit()은 MFC를 사용하기 위한 초기화 함수
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.

        /* 1) 10-11p */
            /*
            CString str;
            str.LoadString(IDS_APP_TITLE);
            _tprintf(_T("Hello from %s!\n"), (LPCTSTR)str);
            getchar();
            */

            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            _tprintf(_T("유니코드로 저장된 한국어를 출력합니다.\n"));
            */

        /* 2) 20p */
            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            CString str1;
            str1 = _T("안녕하세요."); //문자열을 직접 대입한다.
            CString str2(_T("오늘은")); //문자열을 생성자 인자로 전달한다.
            CString str3(str2); //CString 객체를 생성자 인자로 전달한다.
            //CString 객체와 문자열을 붙인다.
            CString str4 = str1 + _T("") + str2 + _T(" 즐거운 날입니다.");
            _tprintf(_T("%s\n"), (LPCTSTR)str1);
            _tprintf(_T("%s\n"), (LPCTSTR)str2);
            _tprintf(_T("%s\n"), (LPCTSTR)str3);
            _tprintf(_T("%s\n"), (LPCTSTR)str4);
            // + = 연산자를 이용하여 기존 문자열에 새로운 문자열을 덧붙인다.
            str4 += _T("하하하");
            _tprintf(_T("%s\n"), (LPCTSTR)str4);
            */

        /* 3) 21p */
            /*
            CString str;
            str.Format(_T("x=%d, y=%d"), 100, 200);
            MessageBox(NULL, str, _T("CString::Format() 연습"), MB_OK);
            */

        /* 4) 22p */
            /*
            CString str;
            str.LoadString(IDS_APP_TITLE); //문자열 리소스를 로드한다.
            str.Insert(0, _T("Hello from ")); //맨 앞에 문자열을 삽입한다.
            str.Append(_T("!")); //맨 끝에 문자열을 덧붙인다.
            MessageBox(NULL, str, _T("CString::LoadString() 연습"), MB_OK);
            */

        /* 5) 24p */
            /*
            //CPoint::CPoint(int x, int y);
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            CPoint pt1(10, 20); //x, y 좌표를 생성자 인자로 전달한다.
            POINT pt = {30, 40};
            CPoint pt2(pt); //POINT 타입 변수를 생성자 인자로 전달한다.
            _tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
            _tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
            pt1.Offset(40, 30); //x, y 좌표에 각각 40, 30을 더한다.
            pt2.Offset(20, 10); //x, y 좌표에 각각 20, 10을 더한다.
            _tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
            _tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
            if (pt1 == pt2) //두 객체의 내용이 같은지 확인한다.
                _tprintf(_T("두 점의 좌표가 같습니다.\n"));
            else
                _tprintf(_T("두 점의 좌표가 다릅니다.\n"));
            */

        /* 6) 26p */
            /*
            //CRect::CRect(int l, int t, int r, int b);
            //int CRect::Width();
            //int CRect::Height();
            //BOOL CRect::PtInRect(POINT point);
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            CRect rect1(0, 0, 200, 100); //직사각형의 좌표를 생성자의 인자로 전달한다.
            CRect rect2;
            rect2.SetRect(0, 0, 200, 100); //직사각형의 좌표를 실행 중에 설정한다.
            if (rect1 == rect2) //두 객체의 내용이 같은지 확인한다.
                _tprintf(_T("두 직사각형의 좌표가 같습니다.\n"));
            else
                _tprintf(_T("두 직사각형의 좌표가 다릅니다.\n"));
            RECT rect = { 100, 100, 300, 200 };
            CRect rect3(rect); //RECT 타입 변수를 생성자 인자로 전달한다.
            _tprintf(_T("%d, %d\n"), rect3.Width(), rect3.Height());
            CPoint pt(200, 150);
            if (rect3.PtInRect(pt)) //점이 직사각형 내부에 있는지 판단한다.
                _tprintf(_T("점이 직사각형 내부에 있습니다.\n"));
            else
                _tprintf(_T("점이 직사각형 외부에 있습니다.\n"));
            */

        /* 7) 27p */
            /*
            //CSize::CSize(int x, int y)
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            CSize size1(100, 200); //폭과 높이를 생성자 인자로 전달한다.
            SIZE size = { 100, 200 };
            CSize size2(size); //SIZE 타입 변수를 생성자 인자로 전달한다.
            _tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
            if (size1 == size2) //두 객체의 내용이 같은지 확인한다.
                _tprintf(_T("크기가 같습니다.\n"));
            else
                _tprintf(_T("크기가 다릅니다.\n"));
            */

        /* 8) 28p */
            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            //CTime::GetCurrentTime() 함수로 현재 시각을 구한다.
            CTime tm;
            tm = CTime::GetCurrentTime();
            //여러 방식으로 화면에 출력한다.
            CString str = tm.Format(_T("%A, %B %d, %Y"));
            _tprintf(_T("%s\n"), (LPCTSTR)str);
            str.Format(_T("현재 시작은 %d시 %d분 %d초입니다."), tm.GetHour(), tm.GetMinute(), tm.GetSecond());
            _tprintf(_T("%s\n"), (LPCTSTR)str);
            */
            
        /* 9) 29p */
            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            CTime startTime = CTime::GetCurrentTime();
            Sleep(2000); //2000 밀리초 지연
            CTime endTime = CTime::GetCurrentTime();
            CTimeSpan elapsedTime = endTime - startTime;
            CString str;
            str.Format(_T("%d초 지남!"), elapsedTime.GetTotalSeconds());
            _tprintf(_T("%s\n"), (LPCTSTR)str);
            */
            
        /* 10) 33p */
            /*
            CUIntArray array; //객체를 생성한다.
            array.SetSize(10); //배열 크기를 설정한다.
            for (int i = 0; i < 10; i++)
                array[i] = i * 10; //값을 대입한다.
            for (int i = 0; i < 10; i++)
                _tprintf(_T("%d "), array[i]); //값을 출력한다.
            _tprintf(_T("\n"));
            */

        /* 11) 34p */
            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            CStringArray array; //객체를 생성한다.
            array.SetSize(5); //배열 크기를 설정한다.
            for (int i = 0; i < 5; i++) {
                CString string;
                string.Format(_T("%d년이 지났습니다."), (i + 1) * 10);
                array[i] = string; //값을 대입한다.
            }
            for (int i = 0; i < 5; i++)
                _tprintf(_T("%s\n"), (LPCTSTR)array[i]); //값을 출력한다.
            */

        /* 12) 35p */
            /*
            CUIntArray array;
            array.SetSize(5);
            for (int i = 0; i < 5; i++)
                array[i] = i;
            */
            /* 배열 원소 삽입 */
            /*
            array.InsertAt(3, 77); //인덱스 3 위치에 원소를 삽입한다.
            for (int i = 0; i < array.GetSize(); i++) //변경된 배열의 크기만큼 반복한다.
                _tprintf(_T("%d "), array[i]);
            _tprintf(_T("\n"));
            */
            /* 배열 원소 삭제 */
            /*
            array.RemoveAt(4); //인덱스 4 위치의 원소를 삭제한다.
            for (int i = 0; i < array.GetSize(); i++)
                _tprintf(_T("%d "), array[i]);
            _tprintf(_T("\n"));
            */
            
        /* 13) 36-38p */
            /*
            //Point3D 객체를 저장할 수 있는 배열 객체를 생성한다.
            CArray<Point3D, Point3D&> array;
            array.SetSize(5);
            for (int i = 0; i < 5; i++) {
                Point3D pt(i, i * 10, i * 100);
                array[i] = pt;
            }
            for (int i = 0; i < 5; i++) {
                Point3D pt = array[i];
                _tprintf(_T("%d, %d, %d\n"), pt.x, pt.y, pt.z);
            }
            */

        /* 14) 41p */
            /*
            //CString 객체는 물론이고 일반 문자열도 리스트에 추가할 수 있다.
            const TCHAR* szFruits[] = {
                _T("사과"), _T("딸기"), _T("포도"), _T("오렌지"), _T("자두")
            };
            CStringList list; //리스트 객체를 생성한다.
            for (int i = 0; i < 5; i++)
                list.AddTail(szFruits[i]); //리스트 끝에 데이터를 추가한다.
            */

        /* 15) 43-44P */
            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요
            
            //리스트 맨 앞에서부터 순회하면서 데이터를 출력한다.
            POSITION pos = list.GetHeadPosition();
            while (pos != NULL) {
                CString str = list.GetNext(pos);
                _tprintf(_T("%s "), (LPCTSTR)str);
            }
            _tprintf(_T("\n"));
            //리스트 맨 뒤에서부터 순회하면서 데이터를 출력한다.
            pos = list.GetTailPosition();
            while (pos != NULL) {
                CString str = list.GetPrev(pos);
                _tprintf(_T("%s "), (LPCTSTR)str);
            }
            _tprintf(_T("\n"));

            pos = list.Find(_T("포도")); //데이터의 위치를 얻는다.
            list.InsertBefore(pos, _T("살구")); //앞쪽에 데이터를 삽입한다.
            list.InsertAfter(pos, _T("바나나")); //뒤쪽에 데이터를 삽입한다.
            list.RemoveAt(pos); //데이터를 삭제한다.
            //리스트 맨 앞에서부터 순회하면서 데이터를 출력한다.
            pos = list.GetHeadPosition();
            while (pos != NULL) {
                CString str = list.GetNext(pos);
                _tprintf(_T("%s "), (LPCTSTR)str);
            }
            _tprintf(_T("\n"));
            */

        /* 16) 45-47P */
            /*
            //Point3D 객체를 저장할 수 있는 리스트 객체를 생성한다.
            //CList<Point3D, Point3D&> list;
            CList<Point3D, Point3D> list;
            
            //리스트 끝에 데이터를 추가한다.
            for (int i = 0; i < 5; i++)
                list.AddTail(Point3D(i, i * 10, i * 100));

            //리스트 맨 앞에서부터 순회하면서 데이터를 출력한다.
            POSITION pos = list.GetHeadPosition();
            while (pos != NULL) {
                Point3D pt = list.GetNext(pos);
                _tprintf(_T("%d, %d, %d\n"), pt.x, pt.y, pt.z);
            }
            */
            
        /* 17) 51P */
            /*
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요

            //맵 객체를 생성하고 초기화한다.
            CMapStringToString map;
            map[_T("사과")] = _T("Apple");
            map[_T("딸기")] = _T("Strawberry");
            map[_T("포도")] = _T("Grape");
            map[_T("우유")] = _T("Milk");
            //특정 키 값을 가진 데이터를 검색한다.
            CString str;
            if (map.Lookup(_T("딸기"), str))
                _tprintf(_T("딸기 -> %s\n"), (LPCTSTR)str);
            */

        /* 18) 52-53P */
            /*
            _tprintf(_T("\n"));
            //맵을 순회하면서 모든 키와 데이터 값을 출력한다.
            POSITION pos = map.GetStartPosition();
            while (pos != NULL) {
                CString strKey, strValue;
                map.GetNextAssoc(pos, strKey, strValue);
                _tprintf(_T("%s -> %s\n"), (LPCTSTR)strKey, (LPCTSTR)strValue);
            }

            _tprintf(_T("\n"));
            map.RemoveKey(_T("우유")); //키값 "우유"에 해당하는 데이터를 삭제한다.
            map[_T("수박")] = _T("Watermelon"); //map.SetAt(_T("수박"), _T("Watermelon"));
            //맵을 순회하면서 모든 키와 데이터값을 출력한다.
            pos = map.GetStartPosition();
            while (pos != NULL) {
                CString strKey, strValue;
                map.GetNextAssoc(pos, strKey, strValue);
                _tprintf(_T("%s -> %s\n"), (LPCTSTR)strKey, (LPCTSTR)strValue);
            }
            */
            
            /*
            CMapStringToString map; //맵 객체를 생성한다.
            map.InitHashTable(12007); //해시 테이블 크기를 12007로 바꾼다.
            */

        /* 19) 55-57P */
            _tsetlocale(LC_ALL, _T("")); //유니코드 한국어 출력에 필요

            //맵(CString -> UINT) 객체를 생성하고 초기화한다.
            //CMap<CString, CString&, UINT, UINT&> map;
            CMap<CString, LPCTSTR, UINT, UINT> map;
            map[CString(_T("사과"))] = 10;
            map[CString(_T("딸기"))] = 25;
            map[CString(_T("포도"))] = 40;
            map[CString(_T("수박"))] = 15;
            //특정 키 값을 가진 데이터를 검색한다.
            UINT nCount;
            if (map.Lookup(CString(_T("수박")), nCount))
                _tprintf(_T("수박 %d상자가 남아 있습니다.\n"), nCount);
        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
