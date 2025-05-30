#ifndef LEGOLOCOMOTIONANIMPRESENTER_H
#define LEGOLOCOMOTIONANIMPRESENTER_H

#include "legoloopinganimpresenter.h"
#include "legoroimaplist.h"

class LegoAnimActor;

// VTABLE: LEGO1 0x100d9170
// SIZE 0xd8
class LegoLocomotionAnimPresenter : public LegoLoopingAnimPresenter {
public:
	LegoLocomotionAnimPresenter();
	~LegoLocomotionAnimPresenter() override;

	// FUNCTION: BETA10 0x1005c4e0
	static const char* HandlerClassName()
	{
		// STRING: LEGO1 0x100f06e4
		return "LegoLocomotionAnimPresenter";
	}

	// FUNCTION: LEGO1 0x1006ce50
	// FUNCTION: BETA10 0x1005c4b0
	const char* ClassName() const override // vtable+0x0c
	{
		return HandlerClassName();
	}

	// FUNCTION: LEGO1 0x1006ce60
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, ClassName()) || LegoLoopingAnimPresenter::IsA(p_name);
	}

	void ReadyTickle() override;                          // vtable+0x18
	void StartingTickle() override;                       // vtable+0x1c
	void StreamingTickle() override;                      // vtable+0x20
	MxResult AddToManager() override;                     // vtable+0x34
	void Destroy() override;                              // vtable+0x38
	void EndAction() override;                            // vtable+0x40
	void PutFrame() override;                             // vtable+0x6c
	MxResult CreateAnim(MxStreamChunk* p_chunk) override; // vtable+0x88

	// SYNTHETIC: LEGO1 0x1006cfe0
	// LegoLocomotionAnimPresenter::`scalar deleting destructor'

	void FUN_1006d680(LegoAnimActor* p_actor, MxFloat p_value);

	void DecrementUnknown0xd4()
	{
		if (m_unk0xd4) {
			--m_unk0xd4;
		}
	}

	undefined2 GetUnknown0xd4() { return m_unk0xd4; }

private:
	void Init();
	void Destroy(MxBool p_fromDestructor);

	undefined4 m_unk0xc0;         // 0xc0
	undefined4* m_unk0xc4;        // 0xc4
	LegoROIMapList* m_roiMapList; // 0xc8
	MxS32 m_unk0xcc;              // 0xcc
	MxS32 m_unk0xd0;              // 0xd0
	undefined2 m_unk0xd4;         // 0xd4
};

#endif // LEGOLOCOMOTIONANIMPRESENTER_H
