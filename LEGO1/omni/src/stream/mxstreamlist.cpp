#include "mxstreamlist.h"

// Wrappers around STL list that are used by the MxStream* classes.
DECOMP_SIZE_ASSERT(MxStreamListMxDSAction, 0x0c);
DECOMP_SIZE_ASSERT(MxStreamListMxNextActionDataStart, 0x0c);
DECOMP_SIZE_ASSERT(MxStreamListMxDSSubscriber, 0x0c);

// FUNCTION: LEGO1 0x100b8450
// FUNCTION: BETA10 0x10134c1d
MxDSSubscriber* MxStreamListMxDSSubscriber::Find(MxDSObject* p_object)
{
	for (iterator it = begin(); it != end(); it++) {
		if (p_object->GetObjectId() == -1 || p_object->GetObjectId() == (*it)->GetObjectId()) {
			if (p_object->GetUnknown24() == -2 || p_object->GetUnknown24() == (*it)->GetUnknown48()) {
				return *it;
			}
		}
	}

	return NULL;
}

// FUNCTION: LEGO1 0x100bfa80
// FUNCTION: BETA10 0x10147e02
MxDSAction* MxStreamListMxDSAction::FindInternal(MxDSAction* p_action, MxBool p_delete)
{
	// DECOMP ALPHA 0x1008b99d ?

	MxDSAction* found = NULL;

#ifdef COMPAT_MODE
	iterator it;
	for (it = begin(); it != end(); it++) {
#else
	for (iterator it = begin(); it != end(); it++) {
#endif
		if (p_action->GetObjectId() == -1 || p_action->GetObjectId() == (*it)->GetObjectId()) {
			if (p_action->GetUnknown24() == -2 || p_action->GetUnknown24() == -3 ||
				p_action->GetUnknown24() == (*it)->GetUnknown24()) {
				found = *it;
				if (p_action->GetUnknown24() != -3) {
					break;
				}
			}
		}
	}

	if (p_delete && found != NULL) {
		erase(it);
	}

	return found;
}

// FUNCTION: LEGO1 0x100c21e0
// FUNCTION: BETA10 0x1014f4e6
MxNextActionDataStart* MxStreamListMxNextActionDataStart::Find(MxU32 p_id, MxS16 p_value)
{
	for (iterator it = begin(); it != end(); it++) {
		if (p_id == (*it)->GetObjectId() && p_value == (*it)->GetUnknown24()) {
			return *it;
		}
	}

	return NULL;
}

// FUNCTION: LEGO1 0x100c2240
// FUNCTION: BETA10 0x1014f58c
MxNextActionDataStart* MxStreamListMxNextActionDataStart::FindAndErase(MxU32 p_id, MxS16 p_value)
{
	MxNextActionDataStart* match = NULL;

	for (iterator it = begin(); it != end(); it++) {
		if (p_id == (*it)->GetObjectId() && (p_value == -2 || p_value == (*it)->GetUnknown24())) {
			match = *it;
			erase(it);
			break;
		}
	}

	return match;
}
