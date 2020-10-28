//==================================================================================================================
//
//	File:	SYS_HUD.cs
//	Date:	19-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	HUD main class
//
//==================================================================================================================

using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

//------------------------------------------------------------------------------------------------------------------
namespace HUD
{
    //------------------------------------------------------------------------------------------------------------------
    public class SYS_PlayerHUD
    {
        private List<GameObject> m_imageSkills;
        private List<GameObject> m_imageCooldownBars;
        private List<float> m_skillTimers;
        private List<float> m_skillEndTimers;
        private GameObject m_imagePlayerLevelBar;
        private GameObject m_healthGlobe;
        private GameObject m_manaGlobe;

        //private Combat.ISoldier m_hero;

        //------------------------------------------------------------------------------------------------------------------
        public SYS_PlayerHUD()
        {
            this.m_imageSkills = new List<GameObject>();
            this.m_imageCooldownBars = new List<GameObject>();
            this.m_skillTimers = new List<float>();
            this.m_skillEndTimers = new List<float>();

            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillA_Cooldown") );
            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillB_Cooldown") );
            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillC_Cooldown") );
            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillD_Cooldown") );
            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillE_Cooldown") );
            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillF_Cooldown") );
            this.m_imageSkills.Add( (GameObject)GameObject.Find("Image_SkillG_Cooldown") );

            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_A_Cooldown") );
            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_B_Cooldown") );
            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_C_Cooldown") );
            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_D_Cooldown") );
            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_E_Cooldown") );
            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_F_Cooldown") );
            this.m_imageCooldownBars.Add( (GameObject)GameObject.Find("ImageBar_G_Cooldown") );

            this.m_healthGlobe = (GameObject)GameObject.Find("Image_HealthGlobe");
            this.m_manaGlobe = (GameObject)GameObject.Find("Image_ManaGlobe");
            this.m_imagePlayerLevelBar = (GameObject)GameObject.Find("ImageBar_PlayerLevel");

            for (int i = 0; i < 7; i++)
            {
                this.m_skillTimers.Add(0);
                this.m_skillEndTimers.Add( Random.Range(0.1f, 1.0f) );
            }

            //mouse skills
            //this.m_skillEndTimers[5] = 2.0f;
            //this.m_skillEndTimers[6] = 2.0f;
	    }

        //------------------------------------------------------------------------------------------------------------------
        public void Update()
        {
            //UpdateTimerSkill();
            //SimulateButtonClickByKeyboard();
            UpdateRunnerSkillInfo();
        }

        //------------------------------------------------------------------------------------------------------------------
        private void UpdateRunnerSkillInfo()
        {
            //Button buttonSkill = this.m_imageSkills[6].GetComponent<Button>();
            //if (this.m_skillTimers[6] >= 1.0f)
            //{
            //    buttonSkill.interactable = true;
            //}
            //else
            //{
            //    buttonSkill.interactable = false;
            //}

            //Image imageSkill = this.m_imageSkills[6].GetComponent<Image>();
            //imageSkill.fillAmount = this.m_skillTimers[6];

            Image imageCooldown = this.m_imageCooldownBars[6].GetComponent<Image>();
            imageCooldown.fillAmount = 1.0f - (this.m_skillTimers[6] / this.m_skillEndTimers[6]);

            //this.m_skillTimers[6] += Time.deltaTime * this.m_skillEndTimers[6];
            //this.m_skillTimers[6] = Mathf.Clamp(this.m_skillTimers[6], 0, 1);
        }
        //------------------------------------------------------------------------------------------------------------------
        private void UpdateTimerSkill()
        {
            for (int i = 0; i < this.m_imageSkills.Count; i++)
            {
                Button buttonSkill = this.m_imageSkills[i].GetComponent<Button>();
                if (this.m_skillTimers[i] >= 1.0f)
                {
                    buttonSkill.interactable = true;
                }
                else
                {
                    buttonSkill.interactable = false;
                }

                Image imageSkill = this.m_imageSkills[i].GetComponent<Image>();
                imageSkill.fillAmount = this.m_skillTimers[i];

                Image imageCooldown = this.m_imageCooldownBars[i].GetComponent<Image>();
                imageCooldown.fillAmount = this.m_skillTimers[i];

                this.m_skillTimers[i] += Time.deltaTime * this.m_skillEndTimers[i];
                this.m_skillTimers[i] = Mathf.Clamp(this.m_skillTimers[i], 0, 1);
            }

    //        Image imagePlayerLevelBar = this.m_imagePlayerLevelBar.GetComponent<Image>();
    //        imagePlayerLevelBar.fillAmount = this.m_skillTimers[0];

        }

        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillA()
        {
            this.m_skillTimers[0] = 0.0f;
        }
        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillB()
        {
            this.m_skillTimers[1] = 0.0f;
        }
        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillC()
        {
            this.m_skillTimers[2] = 0.0f;
        }
        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillD()
        {
            this.m_skillTimers[3] = 0.0f;
        }
        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillE()
        {
            this.m_skillTimers[4] = 0.0f;
        }
        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillF()
        {
            this.m_skillTimers[5] = 0.0f;
        }
        //------------------------------------------------------------------------------------------------------------------
        public void ActivateSkillG()
        {
            this.m_skillTimers[6] = 0.0f;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SimulateButtonClickByKeyboard()
        {
            Button button = m_imageSkills[0].GetComponent<Button>();
            if (Input.GetKeyDown(KeyCode.Alpha1) && button.interactable)
            {
                button.onClick.Invoke();
            }
        
            button = m_imageSkills[1].GetComponent<Button>();
            if (Input.GetKeyDown(KeyCode.Alpha2) && button.interactable)
            {
                button.onClick.Invoke();
            }
        
            button = m_imageSkills[2].GetComponent<Button>();
            if (Input.GetKeyDown(KeyCode.Alpha3) && button.interactable)
            {
                button.onClick.Invoke();
            }

            button = m_imageSkills[3].GetComponent<Button>();
            if (Input.GetKeyDown(KeyCode.Alpha4) && button.interactable)
            {
                button.onClick.Invoke();
            }

            button = m_imageSkills[4].GetComponent<Button>();
            if (Input.GetKeyDown(KeyCode.Alpha5) && button.interactable)
            {
                button.onClick.Invoke();
            }
        
            button = m_imageSkills[5].GetComponent<Button>();
            if (Input.GetMouseButtonDown(0) && button.interactable)
            {
                button.onClick.Invoke();
            }

            button = m_imageSkills[6].GetComponent<Button>();
            if (Input.GetMouseButtonDown(1) && button.interactable)
            {
                button.onClick.Invoke();
            }
        }
        
        #region GETTERS AND SETTERS
        //------------------------------------------------------------------------------------------------------------------
        public void SetHealthGlobePercentage(float percentage)
        {
            Image imageHealthGlobe = this.m_healthGlobe.GetComponent<Image>();
            imageHealthGlobe.fillAmount = percentage;
        }

        //------------------------------------------------------------------------------------------------------------------
        public void SetManaGlobePercentage(float percentage)
        {
            Image imageManaGlobe = this.m_manaGlobe.GetComponent<Image>();
            imageManaGlobe.fillAmount = percentage;
        }

        //------------------------------------------------------------------------------------------------------------------
        public void SetSkillGCurrentTimer(float seconds)
        {
            this.m_skillTimers[6] = seconds;
        }

        //------------------------------------------------------------------------------------------------------------------
        public void SetSkillGEndTimer(float seconds)
        {
            this.m_skillEndTimers[6] = seconds;
        }

        #endregion
    }
}
