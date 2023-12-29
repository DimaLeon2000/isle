#include "mxstreamchunk.h"

#include "legoutil.h"
#include "mxdsbuffer.h"
#include "mxstreamlist.h"

// FUNCTION: LEGO1 0x100c2fe0
MxStreamChunk::~MxStreamChunk()
{
	if (m_buffer) {
		m_buffer->ReleaseRef(this);
	}
}

// FUNCTION: LEGO1 0x100c3050
MxResult MxStreamChunk::ReadChunk(MxDSBuffer* p_buffer, MxU8* p_chunkData)
{
	MxResult result = FAILURE;

	if (p_chunkData != NULL && *(MxU32*) p_chunkData == FOURCC('M', 'x', 'C', 'h')) {
		if (ReadChunkHeader(p_chunkData + 8)) {
			if (p_buffer) {
				SetBuffer(p_buffer);
				p_buffer->AddRef(this);
			}
			result = SUCCESS;
		}
	}

	return result;
}

// FUNCTION: LEGO1 0x100c30a0
MxU32 MxStreamChunk::ReadChunkHeader(MxU8* p_chunkData)
{
	MxU32 headersize = 0;
	if (p_chunkData) {
		MxU8* chunkData = p_chunkData;
		// Note: the alpha debug version uses memcpy calls here,
		// but the code generation is the same.
		GetScalar(&p_chunkData, m_flags);
		GetScalar(&p_chunkData, m_objectId);
		GetScalar(&p_chunkData, m_time);
		GetScalar(&p_chunkData, m_length);
		m_data = p_chunkData;
		headersize = p_chunkData - chunkData;
	}

	return headersize;
}

// FUNCTION: LEGO1 0x100c30e0
MxResult MxStreamChunk::SendChunk(MxStreamListMxDSSubscriber& p_subscriberList, MxBool p_append, MxS16 p_obj24val)
{
	for (MxStreamListMxDSSubscriber::iterator it = p_subscriberList.begin(); it != p_subscriberList.end(); it++) {
		if ((*it)->GetObjectId() == m_objectId && (*it)->GetUnknown48() == p_obj24val) {
			if (m_flags & MxDSChunk::Flag_Bit2 && m_buffer) {
				m_buffer->ReleaseRef(this);
				m_buffer = NULL;
			}

			(*it)->AddChunk(this, p_append);

			return SUCCESS;
		}
	}

	return FAILURE;
}

// FUNCTION: LEGO1 0x100c3170
void MxStreamChunk::SetBuffer(MxDSBuffer* p_buffer)
{
	m_buffer = p_buffer;
}

// FUNCTION: LEGO1 0x100c3180
MxU16* MxStreamChunk::IntoFlags(MxU8* p_buffer)
{
	return (MxU16*) (p_buffer + 8);
}

// FUNCTION: LEGO1 0x100c3190
MxU32* MxStreamChunk::IntoPlus0xa(MxU8* p_buffer)
{
	return (MxU32*) (p_buffer + 0xa);
}

// FUNCTION: LEGO1 0x100c31a0
MxU32* MxStreamChunk::IntoPlus0xe(MxU8* p_buffer)
{
	return (MxU32*) (p_buffer + 0xe);
}

// FUNCTION: LEGO1 0x100c31b0
MxU32* MxStreamChunk::IntoPlus0x12(MxU8* p_buffer)
{
	return (MxU32*) (p_buffer + 0x12);
}