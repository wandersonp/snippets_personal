//==================================================================================================================
//
//	File:	UNIT_ISoldier.cs
//	Date:	17-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	base class for all soldier units
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//------------------------------------------------------------------------------------------------------------------
namespace Combat
{		
	//------------------------------------------------------------------------------------------------------------------
	public interface UNIT_ISoldier {

        void Update(Combat.IMediator mediator);
		void Attack(Combat.IMediator mediator, int damage);
		void ReceiveAttack(int damage);
		bool IsDead();
		void SetMaterialEmissionDamage();

        //------------------------------------------------------------------------------------------------------------------
        void MoveTo(Vector3 destination);
        void SetState(int state);

		//------------------------------------------------------------------------------------------------------------------
		int GetMaxLife();
		void SetMaxLife(int value);
        void IncrementMaxLife(int value);
        void DecreaseMaxLife(int value);

		//------------------------------------------------------------------------------------------------------------------
		int GetCurrentLife();
		void SetCurrentLife(int value);
        void IncrementCurrentLife(int value);
        void DecreaseCurrentLife(int value);
		
		//------------------------------------------------------------------------------------------------------------------
		float GetDamage();	
		void SetDamage(float value);	
		
		//------------------------------------------------------------------------------------------------------------------
		float GetMovementSpeed();	
		void SetMovementSpeed(float value);	
		
		//------------------------------------------------------------------------------------------------------------------
		Vector3 GetPosition();
		void SetPosition(Vector3 position);
		
		//------------------------------------------------------------------------------------------------------------------
		float GetAtackSpeed();	
		void SetAttackSpeed(float value);	

		//------------------------------------------------------------------------------------------------------------------
		int GetMaxMana();	
		void SetMaxMana(int value);
        void IncrementMaxMana(int value);
        void DecreaseMaxMana(int value);

        //------------------------------------------------------------------------------------------------------------------
        int GetCurrentMana();
        void SetCurrentMana(int value);
        void IncrementCurrentMana(int value);
        void DecreaseCurrentMana(int value);
        
        //------------------------------------------------------------------------------------------------------------------
        float GetAnimatorSpeed();
        void SetAnimatorSpeed(float value);

        //------------------------------------------------------------------------------------------------------------------
		void ReceiveRunnerSkillBehaviour();
		void DoRunnerSkillBehaviour(Combat.IMediator mediator);

		//------------------------------------------------------------------------------------------------------------------
		void ReceiveImpactSliceSkillBehaviour();
		void DoImpactSliceSkillBehaviour(Combat.IMediator mediator);

		//------------------------------------------------------------------------------------------------------------------
		void ReceiveBlindTortureSkillBehaviour();
		void DoBlindTortureSkillBehaviour(Combat.IMediator mediator);
		
		//------------------------------------------------------------------------------------------------------------------
		void ReceiveShoutSkillBehaviour();
		void DoShoutSkillBehaviour(Combat.IMediator mediator);
		
		//------------------------------------------------------------------------------------------------------------------
		void ReceiveLeapOfFaithSkillBehaviour();
		void DoLeapOfFaithSkillBehaviour(Combat.IMediator mediator);
		
		//------------------------------------------------------------------------------------------------------------------
        void ReceiveHeavenSpinSkillBehaviour();
        void DoHeavenSpinSkillBehaviour(Combat.IMediator mediator);	
		
		//------------------------------------------------------------------------------------------------------------------
		void ReceiveInvencibleShieldSkillBehaviour();	
		void DoInvencibleShieldSkillBehaviour(Combat.IMediator mediator);	
	}
}