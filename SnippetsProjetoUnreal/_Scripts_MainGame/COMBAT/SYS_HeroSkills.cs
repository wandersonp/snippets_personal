//==================================================================================================================
//
//	File:	HeroSkills.cs
//	Date:	17-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	base class for all hero skills
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Combat
{
	//==================================================================================================================
	public interface IHeroSkill {
        void UseSkill(bool enable);
        void UpdateSkill();
        float GetTimeInUse();
        float GetMinCooldown();
        void SetMinCooldown(float seconds);

        float GetEndTime();
        float GetCurrentTime();
	}

    #region HeroRunnerSkill
    //==================================================================================================================
	public class HeroRunnerSkill : IHeroSkill
	{
		private UNIT_ISoldier m_hero;
        private int m_manaCost;
        private float m_movementSpeed;
		private float m_movementSpeedMultiplier;
        private float m_minCoolDown;
        private float m_currentTimeInSeconds;
        private float m_lastTimeInSeconds;
        private float m_skillEndTime;
        private float m_skillCurrentTime;
        private float m_animatorSpeed;
        private float m_animatorSpeedMultiplier;
		
		//------------------------------------------------------------------------------------------------------------------
		public HeroRunnerSkill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
			this.m_movementSpeed = m_hero.GetMovementSpeed();
			this.m_movementSpeedMultiplier = 3.0f;
            this.m_animatorSpeed = m_hero.GetAnimatorSpeed();
            this.m_animatorSpeedMultiplier = this.m_movementSpeedMultiplier;

            this.m_skillEndTime = 5.0f;

            //rules to use this skill
            this.m_minCoolDown = 3.0f;
            this.m_manaCost = 0;
            this.m_currentTimeInSeconds = Time.time;
            this.m_lastTimeInSeconds = this.m_currentTimeInSeconds;
            this.m_skillCurrentTime = 0;
        }

		//------------------------------------------------------------------------------------------------------------------
		void IHeroSkill.UseSkill(bool enable)
		{
            if (enable)
            {
                EnableSkill();
                ////check for enough mana
                //if (IsAvailable())
                //{
                //    EnableSkill();
                //}
                //else
                //{
                //    Debug.Log("Runner Skill not available");
                //}
            }
            //else
            //{
            //    DisableSkill();
            //}
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
            //check for cooldown
            this.m_currentTimeInSeconds = Time.time;
            this.m_skillCurrentTime = this.m_currentTimeInSeconds - this.m_lastTimeInSeconds;
            if (this.m_skillCurrentTime >= this.m_skillEndTime)
            {
                DisableSkill();
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            this.m_skillCurrentTime = Mathf.Clamp(this.m_skillCurrentTime, 0, this.m_skillEndTime);
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return this.m_minCoolDown;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
            this.m_minCoolDown = seconds;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        private bool IsAvailable()
        {
            float secondsPassed = this.m_currentTimeInSeconds - this.m_lastTimeInSeconds;

            //check for mana and min cooldown in seconds
            if (secondsPassed >= this.m_minCoolDown && this.m_hero.GetCurrentMana() >= this.m_manaCost)
            {
                //update last time 
                this.m_lastTimeInSeconds = this.m_currentTimeInSeconds;
                return true;
            }
            return false;
        }
        
        //------------------------------------------------------------------------------------------------------------------
        private void EnableSkill()
        {
            this.m_hero.SetMovementSpeed(this.m_movementSpeed * this.m_movementSpeedMultiplier);
            this.m_hero.SetAnimatorSpeed(this.m_animatorSpeed * this.m_animatorSpeedMultiplier);
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DisableSkill()
        {
            //reset player movement
            this.m_hero.SetMovementSpeed(this.m_movementSpeed);
            this.m_hero.SetAnimatorSpeed(this.m_animatorSpeed);
            
            //reset timer for next use
            this.m_lastTimeInSeconds = this.m_currentTimeInSeconds;
        }
    }
    #endregion

    #region HeroImpactSliceSkill
    //==================================================================================================================
	public class HeroImpactSliceSkill : IHeroSkill
	{
		private UNIT_ISoldier m_hero;
		private float m_damage;
		private float m_damageMultiplier;
		private float m_attackSpeed;
		private float m_attackSpeedMultiplier;

        private float m_skillEndTime;
        private float m_skillCurrentTime;

		//------------------------------------------------------------------------------------------------------------------
		public HeroImpactSliceSkill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
			this.m_damage = m_hero.GetDamage();
			this.m_damageMultiplier = 1.1f; 
			this.m_attackSpeed = m_hero.GetAtackSpeed();
			this.m_attackSpeedMultiplier = 1.1f;
		}
		
		//------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UseSkill(bool enable)
		{
			if (enable){
				EnableSkill();
			}
			else{
				DisableSkill();
			}
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
		private void EnableSkill()
		{
			m_hero.SetDamage(m_damage * m_damageMultiplier);
			m_hero.SetAttackSpeed(m_attackSpeed * m_attackSpeedMultiplier);
            Debug.Log("Hero using ImpactSlice Skill");
        }
		
		//------------------------------------------------------------------------------------------------------------------
		private void DisableSkill()
		{
			m_hero.SetDamage(m_damage);
			m_hero.SetAttackSpeed(m_attackSpeed);
		}		
	}
    #endregion

    #region HeroInvencibleShieldSkill
    //==================================================================================================================
	public class HeroInvencibleShieldSkill : IHeroSkill
	{
        private UNIT_ISoldier m_hero;
        private float m_skillEndTime;
        private float m_skillCurrentTime;
 
        //------------------------------------------------------------------------------------------------------------------
        public HeroInvencibleShieldSkill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UseSkill(bool enable)
        {
            if (enable)
            {
                EnableSkill();
            }
            else
            {
                DisableSkill();
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void EnableSkill()
        {
            Debug.Log("Hero using InvencibleShield Skill");
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DisableSkill()
        {
        }
    }
    #endregion

    #region HeroBlindTortureSkill
    //==================================================================================================================
	public class HeroBlindTortureSkill : IHeroSkill
	{
        private UNIT_ISoldier m_hero;
        private float m_skillEndTime;
        private float m_skillCurrentTime;
     
        //------------------------------------------------------------------------------------------------------------------
        public HeroBlindTortureSkill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UseSkill(bool enable)
        {
            if (enable)
            {
                EnableSkill();
            }
            else
            {
                DisableSkill();
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void EnableSkill()
        {
            Debug.Log("Hero using BlindTorture Skill");
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DisableSkill()
        {
        }
	}
    #endregion

    #region HeroLeapOfFaithSkill
    //==================================================================================================================
	public class HeroLeapOfFaithSkill : IHeroSkill
	{
        private UNIT_ISoldier m_hero;
        private float m_skillEndTime;
        private float m_skillCurrentTime;
   
        //------------------------------------------------------------------------------------------------------------------
        public HeroLeapOfFaithSkill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UseSkill(bool enable)
        {
            if (enable)
            {
                EnableSkill();
            }
            else
            {
                DisableSkill();
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void EnableSkill()
        {
            Debug.Log("Hero using LeapOfFaith Skill");
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DisableSkill()
        {
        }
	}
    #endregion

    #region HeroShoutSkill
    //==================================================================================================================
	public class HeroShoutSkill : IHeroSkill
	{
        private UNIT_ISoldier m_hero;
        private float m_skillEndTime;
        private float m_skillCurrentTime;
    
        //------------------------------------------------------------------------------------------------------------------
        public HeroShoutSkill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UseSkill(bool enable)
        {
            if (enable)
            {
                EnableSkill();
            }
            else
            {
                DisableSkill();
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void EnableSkill()
        {
            Debug.Log("Hero using Shout Skill");
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DisableSkill()
        {
        }
	}
    #endregion

    #region HeroHeavenSpinSKill
    //==================================================================================================================
	public class HeroHeavenSpinSKill : IHeroSkill
	{
        private UNIT_ISoldier m_hero;
        private float m_skillEndTime;
        private float m_skillCurrentTime;
   
        //------------------------------------------------------------------------------------------------------------------
        public HeroHeavenSpinSKill(UNIT_ISoldier hero)
		{
			this.m_hero = hero;
		}

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UseSkill(bool enable)
        {
            if (enable)
            {
                EnableSkill();
            }
            else
            {
                DisableSkill();
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetTimeInUse()
        {
            return 0;
        }
        
        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.UpdateSkill()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetMinCooldown()
        {
            return 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        void IHeroSkill.SetMinCooldown(float seconds)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetEndTime()
        {
            return this.m_skillEndTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        float IHeroSkill.GetCurrentTime()
        {
            return this.m_skillCurrentTime;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void EnableSkill()
        {
            Debug.Log("Hero using HeavenSpin Skill");
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DisableSkill()
        {
        }
	}
    #endregion
}
