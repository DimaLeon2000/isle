#ifndef LEGOVARIABLES_H
#define LEGOVARIABLES_H

#include "mxvariable.h"

extern const char* g_varJETSPEED;
extern const char* g_varJETFUEL;
extern const char* g_varDUNESPEED;
extern const char* g_varDUNEFUEL;
extern const char* g_varMOTOSPEED;
extern const char* g_varMOTOFUEL;
extern const char* g_varAMBULSPEED;
extern const char* g_varAMBULFUEL;
extern const char* g_varTOWSPEED;
extern const char* g_varTOWFUEL;
extern const char* g_varVISIBILITY;
extern const char* g_varCAMERALOCATION;
extern const char* g_varCURSOR;
extern const char* g_varWHOAMI;

// VTABLE: LEGO1 0x100d86c8
// SIZE 0x24
class VisibilityVariable : public MxVariable {
public:
	VisibilityVariable() { m_key = g_varVISIBILITY; }

	void SetValue(const char* p_value) override; // vtable+0x04
};

// VTABLE: LEGO1 0x100d86b8
// SIZE 0x24
class CameraLocationVariable : public MxVariable {
public:
	CameraLocationVariable() { m_key = g_varCAMERALOCATION; }

	void SetValue(const char* p_value) override; // vtable+0x04
};

// VTABLE: LEGO1 0x100d86a8
// SIZE 0x24
class CursorVariable : public MxVariable {
public:
	CursorVariable() { m_key = g_varCURSOR; }

	void SetValue(const char* p_value) override; // vtable+0x04
};

// VTABLE: LEGO1 0x100d8698
// SIZE 0x24
class WhoAmIVariable : public MxVariable {
public:
	WhoAmIVariable() { m_key = g_varWHOAMI; }

	void SetValue(const char* p_value) override; // vtable+0x04
};

#endif // LEGOVARIABLES_H
