//==================================================================================================================
//
//	File:	TorchLightFlicking.cs
//	Date:	04-05-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	torch animation class
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Anim
{
    public class TorchLightFlicking : MonoBehaviour
    {
        public GameObject m_gameObject;
        private Light m_light;
        private float m_intensity;

        //------------------------------------------------------------------------------------------------------------------
        void Awake()
        {
            this.m_light = m_gameObject.GetComponent<Light>();
            this.m_intensity = this.m_light.intensity;
        }

        //------------------------------------------------------------------------------------------------------------------
        void Update()
        {
			//float oscilate = Mathf.Abs(Mathf.Cos(Time.time*20 + m_gameObject.GetInstanceID()))/4.0f;//
            float oscilate = Mathf.PerlinNoise(Mathf.Abs(m_gameObject.GetInstanceID()), (float)Time.frameCount / 10.0f);
			
            this.m_light.intensity = this.m_intensity + oscilate;
            //this.m_light.intensity = Mathf.PerlinNoise((float)Time.frameCount / 8, m_maxIntensity) + 1.0f;
        }
    }
}