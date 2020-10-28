//==================================================================================================================
//
//	File:	SYS_Weather.cs
//	Date:	01-05-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	weather random generator
//
//==================================================================================================================

using UnityEngine;
using UnityEngine.Rendering;
using System.Collections;
using System.Collections.Generic;

//==================================================================================================================
namespace GameSystem
{
    //==================================================================================================================
    public class SYS_Weather : MonoBehaviour
    {
        private Color m_ambientEquatorColor;
        private Color m_ambientGroundColor;
        private float m_ambientIntensity;
        private Color m_ambientLight;
        private AmbientMode m_ambientMode;
        private SphericalHarmonicsL2 m_ambientProbe;	
        private Color m_ambientSkyColor;
        private Cubemap m_customReflection;
        private DefaultReflectionMode m_defaultReflectionMode;
        private int m_defaultReflectionResolution;
        private float m_flareFadeSpeed;
        private float m_flareStrength;	
        private bool m_fog;	
        private Color m_fogColor;	
        private float m_fogDensity;	
        private float m_fogEndDistance;
        private FogMode m_fogMode;	
        private float m_fogStartDistance;	
        private float m_haloStrength;	
        private int m_reflectionBounces;	
        private float m_reflectionIntensity;	
        private Material m_skybox;

        //------------------------------------------------------------------------------------------------------------------
        public enum WeatherType
        {
            WEATHER_TYPE_1 = 0,
            WEATHER_TYPE_2 = 1,
            WEATHER_TYPE_3 = 2,
            WEATHER_TYPE_4 = 3
        }

        //------------------------------------------------------------------------------------------------------------------
        //public SYS_Weather()
        //{
        //}

        //------------------------------------------------------------------------------------------------------------------
        void Start()
        {
            PrintWeather();
        }

        //------------------------------------------------------------------------------------------------------------------
        public void SetRandomWeather()
        {
            int weather = Random.Range(0, 4);
            SetMainWeather((WeatherType)weather);
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetMainWeather(WeatherType weather)
        {
            switch (weather)
            {
                case WeatherType.WEATHER_TYPE_1:
                    SetWeatherType_1();
                    break;
                case WeatherType.WEATHER_TYPE_2:
                    SetWeatherType_2();
                    break;
                case WeatherType.WEATHER_TYPE_3:
                    SetWeatherType_3();
                    break;
                case WeatherType.WEATHER_TYPE_4:
                    SetWeatherType_4();
                    break;
            }
            SetRenderSettingsForWeather();
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetWeatherType_1()
        {
            this.m_ambientEquatorColor = new Color(1.0f, 1.0f, 1.0f);
            this.m_ambientGroundColor = new Color(1.0f, 1.0f, 1.0f);
            this.m_ambientIntensity = 1.0f;
            this.m_ambientLight = new Color(1.0f, 1.0f, 1.0f);
            this.m_ambientMode = AmbientMode.Skybox;
            //this.m_ambientProbe = SphericalHarmonicsL2;
            this.m_ambientSkyColor = new Color(1.0f, 1.0f, 1.0f);
            this.m_customReflection = null;
            this.m_defaultReflectionMode = DefaultReflectionMode.Skybox;
            this.m_defaultReflectionResolution = 128;
            this.m_flareFadeSpeed = 3.0f;
            this.m_flareStrength = 1.0f;
            this.m_fog = true;
            this.m_fogColor = new Color(0.5f, 0.5f, 0.5f);
            this.m_fogDensity = 0.01f;
            this.m_fogEndDistance = 300.0f;
            this.m_fogMode = FogMode.Linear;
            this.m_fogStartDistance = 0;
            this.m_haloStrength = 0.5f;
            this.m_reflectionBounces = 1;
            this.m_reflectionIntensity = 1.0f;

            Material skyboxMaterial = null;
            this.m_skybox = skyboxMaterial;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetWeatherType_2()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetWeatherType_3()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetWeatherType_4()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetRenderSettingsForWeather()
        {
            RenderSettings.ambientEquatorColor = this.m_ambientEquatorColor;
            RenderSettings.ambientGroundColor = this.m_ambientGroundColor;
            RenderSettings.ambientIntensity = this.m_ambientIntensity;
            RenderSettings.ambientLight = this.m_ambientLight;
            RenderSettings.ambientMode = this.m_ambientMode;
            RenderSettings.ambientProbe = this.m_ambientProbe;
            RenderSettings.ambientIntensity = this.m_ambientIntensity;
            RenderSettings.ambientSkyColor = this.m_ambientSkyColor;
            RenderSettings.customReflection = this.m_customReflection;
            RenderSettings.defaultReflectionMode = this.m_defaultReflectionMode ;
            RenderSettings.defaultReflectionResolution = this.m_defaultReflectionResolution;
            RenderSettings.flareFadeSpeed = this.m_flareFadeSpeed;
            RenderSettings.flareStrength = this.m_flareStrength;
            RenderSettings.fog = this.m_fog;
            RenderSettings.fogColor = this.m_fogColor;
            RenderSettings.fogDensity = this.m_fogDensity;
            RenderSettings.fogEndDistance = this.m_fogEndDistance;
            RenderSettings.fogMode = this.m_fogMode;
            RenderSettings.fogStartDistance = this.m_fogStartDistance;
            RenderSettings.haloStrength = this.m_haloStrength;
            RenderSettings.reflectionBounces = this.m_reflectionBounces;
            RenderSettings.reflectionIntensity = this.m_reflectionIntensity;
            RenderSettings.skybox = this.m_skybox;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void PrintWeather()
        {
            Debug.Log("RenderSettings.ambientEquatorColor:    " + RenderSettings.ambientEquatorColor);
            Debug.Log("RenderSettings.ambientGroundColor:    " + RenderSettings.ambientGroundColor);
            Debug.Log("RenderSettings.ambientIntensity:    " + RenderSettings.ambientIntensity);
            Debug.Log("RenderSettings.ambientLight:    " + RenderSettings.ambientLight);
            Debug.Log("RenderSettings.ambientMode:    " + RenderSettings.ambientMode);
            Debug.Log("RenderSettings.ambientProbe:    " + RenderSettings.ambientProbe);
            Debug.Log("RenderSettings.ambientIntensity:    " + RenderSettings.ambientIntensity);
            Debug.Log("RenderSettings.ambientSkyColor:    " + RenderSettings.ambientSkyColor);
            Debug.Log("RenderSettings.customReflection:    " + RenderSettings.customReflection);
            Debug.Log("RenderSettings.defaultReflectionMode:    " + RenderSettings.defaultReflectionMode);
            Debug.Log("RenderSettings.defaultReflectionResolution:    " + RenderSettings.defaultReflectionResolution);
            Debug.Log("RenderSettings.flareFadeSpeed:    " + RenderSettings.flareFadeSpeed);
            Debug.Log("RenderSettings.flareStrength:    " + RenderSettings.flareStrength);
            Debug.Log("RenderSettings.fog:    " + RenderSettings.fog);
            Debug.Log("RenderSettings.fogColor:    " + RenderSettings.fogColor);
            Debug.Log("RenderSettings.fogDensity:    " + RenderSettings.fogDensity);
            Debug.Log("RenderSettings.fogEndDistance:    " + RenderSettings.fogEndDistance);
            Debug.Log("RenderSettings.fogMode:    " + RenderSettings.fogMode);
            Debug.Log("RenderSettings.fogStartDistance:    " + RenderSettings.fogStartDistance);
            Debug.Log("RenderSettings.haloStrength:    " + RenderSettings.haloStrength);
            Debug.Log("RenderSettings.reflectionBounces:    " + RenderSettings.reflectionBounces);
            Debug.Log("RenderSettings.reflectionIntensity:    " + RenderSettings.reflectionIntensity);
            Debug.Log("RenderSettings.skybox:    " + RenderSettings.skybox); 
        }
    }
}
