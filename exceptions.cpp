// exceptions.cpp
// mastering c++ exception handling

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <exception>
#include <vector>

typedef struct {
  int id;
  int locationId;
  int level;
  TCHAR* description;
  TCHAR* reason;
} ERRORINFO, *PERRORINFO;

class myexception: public std::exception {
  TCHAR* m_msg;
  std::vector<PERRORINFO> m_errorlist;
public:
  myexception(TCHAR* msg)
    :m_msg(msg) {}
  virtual ~myexception() noexcept {
    m_errorlist.clear();
  }
  virtual char const* what() const { // an accessor function
    return m_msg;
  }
  void adderror(PERRORINFO info) throw(std::bad_alloc) {
    try {
      m_errorlist.push_back(info);
    }
    catch(...) {
      std::cout<<"Bad alloc in adderror function\n";
    }
  }
  auto begin() { return m_errorlist.begin(); }
  auto end() { return m_errorlist.end(); }
};

int _tmain(int argc, TCHAR** argv, TCHAR** env) {
	try {
		try {
			try {
				myexception myex(_T("myexception object thrown"));
				_tprintf(_T("sizeof(myexception) = %d\n"), sizeof(myexception));
				_tprintf(_T("sizeof(ERRORINFO) = %d\n"), sizeof(ERRORINFO));
				throw myex;
			}
			catch(myexception& ex) {
				ERRORINFO errinfo;
				errinfo.id = 1;
				errinfo.locationId = 1;
				errinfo.level = 1;
				errinfo.description = _T("First level exception thrown.");
				ex.adderror(&errinfo);
				throw ex;
			}
		}
		catch(myexception& ex) {
			ERRORINFO errinfo;
			errinfo.id = 2;
			errinfo.locationId = 2;
			errinfo.level = 2;
			errinfo.description = _T("Second level exception thrown.");
			ex.adderror(&errinfo);
			throw ex;
		}
	}
	catch(myexception& ex) {
		// print out erroinfo structs
		for(auto it = ex.begin(); it != ex.end(); ++it) {
			ERRORINFO einfo = **it;
			std::cout<<einfo.id<<" "<<einfo.locationId<<" "<<einfo.level<<" "<<einfo.description<<" "<<'\n';
		}
	}
	return 0;
}	