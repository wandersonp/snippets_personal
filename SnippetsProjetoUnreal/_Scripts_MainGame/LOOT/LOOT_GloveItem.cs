//==================================================================================================================
//
//	File:	LOOT_GloveItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for glove itens
//
//==================================================================================================================

//#define GLOVE

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Glove Item Class
#if (GLOVE)
    //==================================================================================================================
    public class GloveItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public GloveItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //GLOVE
    #endregion
}
