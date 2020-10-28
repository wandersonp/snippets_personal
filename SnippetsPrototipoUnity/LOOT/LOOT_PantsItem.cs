//==================================================================================================================
//
//	File:	LOOT_PantsItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for pants itens
//
//==================================================================================================================

//#define PANTS

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Pants Item Class
#if (PANTS)
    //==================================================================================================================
    public class PantsItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public PantsItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //PANTS
    #endregion
}
