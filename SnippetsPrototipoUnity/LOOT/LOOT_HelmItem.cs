//==================================================================================================================
//
//	File:	LOOT_HelmItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for helm itens
//
//==================================================================================================================

//#define HELM

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Helm Item Class
#if (HELM)
    //==================================================================================================================
    public class HelmItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public HelmItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //HELM
    #endregion
}
