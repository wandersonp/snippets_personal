//==================================================================================================================
//
//	File:	LOOT_BeltItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for belt itens
//
//==================================================================================================================

//#define BELT

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Belt Item Class
#if (BELT)
    //==================================================================================================================
    public class BeltItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public BeltItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //BELT
    #endregion
}
