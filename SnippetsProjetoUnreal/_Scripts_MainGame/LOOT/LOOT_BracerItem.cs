//==================================================================================================================
//
//	File:	LOOT_BracerItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for bracer itens
//
//==================================================================================================================

//#define BRACER

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Bracer Item Class
#if (BRACER)
    //==================================================================================================================
    public class BracerItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_shoulderStats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public BracerItem()
        {
            this.m_shoulderStats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //BRACER
    #endregion
}
