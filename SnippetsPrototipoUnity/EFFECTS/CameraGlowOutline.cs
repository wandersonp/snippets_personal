//==================================================================================================================
//
//	File:	CameraGlowOutline.cs
//	Date:	07-05-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	Glow Outline for items and enemies
//
//==================================================================================================================

using UnityEngine;
using UnityEngine.Rendering;
using UnityStandardAssets.ImageEffects;
using System.Collections;
using System.Collections.Generic;

//==================================================================================================================
namespace Effects
{
    //==================================================================================================================
    public class CameraGlowOutline : MonoBehaviour
    {
        //---------------------------------------------------------------------------------------------------
        public Shader m_highlightShader;

        private Renderer[] m_highLightObjects;
        private CommandBuffer m_renderBuffer;
        private Material m_highlightMaterial;
        private BlurOptimized m_blur;

        //---------------------------------------------------------------------------------------------------
        void Awake()
        {
            CreateRenderBuffer();
            CreateMaterial();

            this.m_blur = gameObject.AddComponent<BlurOptimized>();
            this.m_blur.enabled = false;
            this.m_blur.blurSize = 1.5f;
            this.m_blur.blurIterations = 2;
            this.m_blur.downsample = 1;
        }

        //---------------------------------------------------------------------------------------------------
        void FixedUpdate()
        {
            GameObject[] objects = GameObject.FindGameObjectsWithTag("GlowOutline");
            this.m_highLightObjects = new Renderer[objects.Length];

            for (int i = 0; i < objects.Length; i++)
            {
                this.m_highLightObjects[i] = objects[i].GetComponent<Renderer>();
            }
        }

        //---------------------------------------------------------------------------------------------------
        void OnRenderImage(RenderTexture source, RenderTexture destination)
        {
            //create and allocate RenderTexture buffer
            RenderTexture highlightRT;
            highlightRT = RenderTexture.GetTemporary(Screen.width, Screen.height, 0, RenderTextureFormat.R8);

            //set active fill with black pixels and release
            RenderTexture.active = highlightRT;
            GL.Clear(true, true, Color.clear);
            RenderTexture.active = null;

            //clear and draw the mesh
            ClearRenderBuffer();
            RenderHighlightObjects(highlightRT);

            //blur image
            RenderTexture blurred = RenderTexture.GetTemporary(Screen.width, Screen.height, 0, RenderTextureFormat.R8);
            m_blur.OnRenderImage(highlightRT, blurred);

            //resolve shader
            this.m_highlightMaterial.SetTexture("_MaskTex", highlightRT);
            this.m_highlightMaterial.SetTexture("_ColorTex", blurred);
            Graphics.Blit(source, destination, this.m_highlightMaterial, 1);

            //release buffer
            RenderTexture.ReleaseTemporary(highlightRT);
            RenderTexture.ReleaseTemporary(blurred);
        }

        //---------------------------------------------------------------------------------------------------
        private void CreateRenderBuffer()
        {
            this.m_renderBuffer = new CommandBuffer();
        }

        //---------------------------------------------------------------------------------------------------
        private void ClearRenderBuffer()
        {
            this.m_renderBuffer.Clear();
        }

        //---------------------------------------------------------------------------------------------------
        private void CreateMaterial()
        {
            this.m_highlightMaterial = new Material(this.m_highlightShader);
        }

        //---------------------------------------------------------------------------------------------------
        private void RenderHighlightObjects(RenderTexture rt)
        {
            if (this.m_highLightObjects == null)
                return;

            RenderTargetIdentifier rtid = new RenderTargetIdentifier(rt);
            this.m_renderBuffer.SetRenderTarget(rtid);

            for (int i = 0; i < this.m_highLightObjects.Length; i++)
            {
                if (this.m_highLightObjects[i] == null)
                    continue;

                this.m_renderBuffer.DrawRenderer(this.m_highLightObjects[i], this.m_highlightMaterial, 0, 0);
            }

            RenderTexture.active = rt;
            Graphics.ExecuteCommandBuffer(this.m_renderBuffer);
            RenderTexture.active = null;
        }
    }
}
