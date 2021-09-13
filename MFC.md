# MFC.

## Console 예제 코드.
```cpp
#include "pch.h"
#include "framework.h"
#include "Console.h“

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;
using namespace std;

int main()
{
    int nRetCode = 0; //응용 프로그램 객체가 전역 변수로 정의되어 있음 //전형적인 C 프로그램의 실행 시작점

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        { //A fxWinInit( )는 MFC를 사용하기 위한 초기화 함수
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
            else
            {
                CString str;
                str.LoadString(IDS_APP_TITLE); _tprintf(_T("Hello from %s!\n"), (LPCTSTR)str);
                getchar();
            }
    }
    else
    {
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }
    return nRetCode;
}
```

1. `wpirntf(L...)`
    - 유니코드 대상, (유니코드: 1자 → 1워드)
    - w = Wide
    - L = 유니코드 접두어
    - char c: ANSI → 1 byte, UNICODE → 2 byte

2. `_tprint(_T...)`
    - _T = 자동 변환 접두어
    - _t = 유니코드나 안시나 자동으로 컴파일 시 자동으로 변환

3. `CString`
    - C...은 클래스
    - 스트링 클래스
    - LoadString = 스트링 불러오기
    - IDS_APP_TITLE = 앱의 제목, 리소스, ID: 정수, 캡션: 문자열

4. 리소스
    - 코드를 제외하고 포함된 모든 소스
    - *.RC, Resource.h

5. `HANDLE` → 윈도우 OS에서 윈도우 관리에 사용하는 정수값
6. `(L)PCTSTR` → const char *: ANSI, const wchar *: UNICODE
