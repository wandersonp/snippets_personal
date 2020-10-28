//==================================================================================================================
//
//	File:	LOOT_RingItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for ring itens
//
//==================================================================================================================

//#define RING

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Ring Item Class
#if (RING)
    //==================================================================================================================
    public class RingItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public RingItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //RING
    #endregion
}
