#include "lego3dview.h"

#include "legoroi.h"
#include "tgl/tgl.h"

DECOMP_SIZE_ASSERT(Lego3DView, 0xa8)

// STUB: LEGO1 0x100aae90
Lego3DView::Lego3DView()
{
}

// STUB: LEGO1 0x100aaf30
Lego3DView::~Lego3DView()
{
}

// STUB: LEGO1 0x100aaf90
MxBool Lego3DView::Init(MxRenderSettings& p_renderSettings, Tgl::Renderer& p_render)
{
	return FALSE;
}

// STUB: LEGO1 0x100ab2b0
LegoROI* Lego3DView::PickROI(MxLong p_a, MxLong p_b)
{
	// TODO
	return NULL;
}