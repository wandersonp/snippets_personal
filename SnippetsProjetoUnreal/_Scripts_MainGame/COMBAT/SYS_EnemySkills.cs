//==================================================================================================================
//
//	File:	SYS_EnemySkills.cs
//	Date:	21-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	base class for all enemy skills
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Combat
{
    //==================================================================================================================
    public interface IEnemySkill
    {
        void UpdateSkill();
    }

    #region FastSkill
    //==================================================================================================================
    public class FastSkill : IEnemySkill
    {
        private UNIT_ISoldier m_enemy;

        //------------------------------------------------------------------------------------------------------------------
        public FastSkill(IEnemySkill enemy)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        void IEnemySkill.UpdateSkill()
        {
        }
    }

    #endregion

    #region SKILLS LIST

    /*
    	-jailer
		-arcane
		-desecrator
		-teleporter
		-fast
		-vortex
		-thunderstorm
		-frozen
		-eletric
		-mortar
		-shield
		-molten
		-fire chains
		-waller
		-knockback
		-orbiter
		-plague
		-reflect damage
		-llusionist
		-nightmarish
		-horde
		-avenger
		-healthy link
    */

    #endregion
}
