//==================================================================================================================
//
//	File:	LOOT_WeaponItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for weapon itens
//
//==================================================================================================================

#define WEAPON

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region WeaponItem Class
#if (WEAPON)
    //==================================================================================================================
    public class BattleAxeItem : ILoot
    {
        private SLootDescription m_lootDescription;
        //------------------------------------------------------------------------------------------------------------------
        public BattleAxeItem()
        {
            this.m_lootDescription = new SLootDescription();
            this.m_lootDescription.m_typeName = "BattleAxe";
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void AddPrimaryStat(EnumLootStat statType, float statValue)
        {
            SortedList<EnumLootStat, float> stats = this.m_lootDescription.m_primaryStats;
            if (stats.ContainsKey(statType))
            {
                return;
            }
            stats.Add(statType, statValue);
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void AddSecondaryStat(EnumLootStat statType, float statValue)
        {
            SortedList<EnumLootStat, float> stats = this.m_lootDescription.m_secondaryStats;
            if (stats.ContainsKey(statType))
            {
                return;
            }
            stats.Add(statType, statValue);
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void AddBonusStat(EnumLootStat statType, float statValue)
        {
            SortedList<EnumLootStat, float> stats = this.m_lootDescription.m_bonusStats;
            if (stats.ContainsKey(statType))
            {
                return;
            }
            stats.Add(statType, statValue);
        }

        //------------------------------------------------------------------------------------------------------------------
        public override string GetName()
        {
            return this.m_lootDescription.m_name;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void SetName(string name)
        {
            this.m_lootDescription.m_name = name;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void SetLevelRequirement(int level)
        {
            this.m_lootDescription.m_levelRequirement = level;
        }
        //------------------------------------------------------------------------------------------------------------------
        public override int GetLevelRequirement()
        {
            return this.m_lootDescription.m_levelRequirement;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void SetItemTypeName(string type)
        {
            this.m_lootDescription.m_typeName = type;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override string GetItemTypeName()
        {
            return this.m_lootDescription.m_typeName;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override string GetStringByEnumStat(EnumLootStat statType)
        {
            string statName = "";
            switch (statType)
            {
                case EnumLootStat.STAT_MANA:
                    statName = "STAT_MANA";
                    break;
                case EnumLootStat.STAT_VITALITY:
                    statName = "STAT_VITALITY";
                    break;
                case EnumLootStat.STAT_STRENGTH:
                    statName = "STAT_STRENGTH";
                    break;
                case EnumLootStat.STAT_ARMOUR:
                    statName = "STAT_ARMOUR";
                    break;
                case EnumLootStat.STAT_CRITICAL_CHANCE:
                    statName = "STAT_CRITICAL_CHANCE";
                    break;
                case EnumLootStat.STAT_CRITICAL_DAMAGE:
                    statName = "STAT_CRITICAL_DAMAGE";
                    break;
                case EnumLootStat.STAT_ATTACK_SPEED:
                    statName = "STAT_ATTACK_SPEED";
                    break;
                case EnumLootStat.STAT_MOVEMENT_SPEED:
                    statName = "STAT_MOVEMENT_SPEED";
                    break;
                case EnumLootStat.STAT_ALL_RESISTANCE:
                    statName = "STAT_ALL_RESISTANCE";
                    break;
                case EnumLootStat.STAT_FIRE_RESISTANCE:
                    statName = "STAT_FIRE_RESISTANCE";
                    break;
                case EnumLootStat.STAT_COLD_RESISTANCE:
                    statName = "STAT_COLD_RESISTANCE";
                    break;
                case EnumLootStat.STAT_ARCANE_RESISTANCE:
                    statName = "STAT_ARCANE_RESISTANCE";
                    break;
                case EnumLootStat.STAT_ELETRIC_RESISTANCE:
                    statName = "STAT_ELETRIC_RESISTANCE";
                    break;
                case EnumLootStat.STAT_POISON_RESISTANCE:
                    statName = "STAT_POISON_RESISTANCE";
                    break;
                case EnumLootStat.STAT_PHYSICAL_RESISTANCE:
                    statName = "STAT_PHYSICAL_RESISTANCE";
                    break;
                case EnumLootStat.STAT_LIFE_PER_SECOND:
                    statName = "STAT_LIFE_PER_SECOND";
                    break;
                case EnumLootStat.STAT_LIFE_PERCENT:
                    statName = "STAT_LIFE_PERCENT";
                    break;
                case EnumLootStat.STAT_MANA_PER_SECOND:
                    statName = "STAT_MANA_PER_SECOND";
                    break;
                case EnumLootStat.STAT_MONSTER_GRANT_EXPERIENCE:
                    statName = "STAT_MONSTER_GRANT_EXPERIENCE";
                    break;
                case EnumLootStat.STAT_REDUCE_COOLDOWN_ALL_SKILLS:
                    statName = "STAT_REDUCE_COOLDOWN_ALL_SKILLS";
                    break;
                case EnumLootStat.STAT_MAGIC_FIND:
                    statName = "STAT_MAGIC_FIND";
                    break;
            }

            return statName;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override int GetPrimaryStatCount()
        {
            return m_lootDescription.m_primaryStats.Count;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override int GetSecondaryStatCount()
        {
            return m_lootDescription.m_secondaryStats.Count;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override int GetBonusStatCount()
        {
            return m_lootDescription.m_bonusStats.Count;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void GetStatInfo(int index, out string name, out float value)
        {
            name = GetStringByEnumStat(this.m_lootDescription.m_primaryStats.Keys[index]);
            value = this.m_lootDescription.m_primaryStats.Values[index];
        }

        //------------------------------------------------------------------------------------------------------------------
        public override string GetPrimaryStatNiceNameDescription(int index)
        {
            EnumLootStat statType = this.m_lootDescription.m_primaryStats.Keys[index];
            float value = this.m_lootDescription.m_primaryStats.Values[index];
            string niceName = "";

            switch (statType)
            {
                case EnumLootStat.STAT_VITALITY:
                    niceName = "+ " + value.ToString() + " Vitality";
                    break;
                case EnumLootStat.STAT_STRENGTH:
                    niceName = "+ " + value.ToString() + " Strength";
                    break;
                case EnumLootStat.STAT_ARMOUR:
                    niceName = "+ " + value.ToString() + " Armour";
                    break;
                case EnumLootStat.STAT_CRITICAL_CHANCE:
                    niceName = "Critical Chance Increased by " + value.ToString() + "%";
                    break;
                case EnumLootStat.STAT_CRITICAL_DAMAGE:
                    niceName = "Critical Damage Increased by " + value.ToString() + "%";
                    break;
                case EnumLootStat.STAT_ATTACK_SPEED:
                    niceName = "Attack Speed Increased by " + value.ToString() + "%";
                    break;
            }

            return niceName;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override string GetSecondaryStatNiceNameDescription(int index)
        {
            EnumLootStat statType = this.m_lootDescription.m_secondaryStats.Keys[index];
            float value = this.m_lootDescription.m_secondaryStats.Values[index];
            string niceName = "";

            switch (statType)
            {
                case EnumLootStat.STAT_ALL_RESISTANCE:
                    niceName = "All Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_FIRE_RESISTANCE:
                    niceName = "Fire Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_COLD_RESISTANCE:
                    niceName = "Cold Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_ARCANE_RESISTANCE:
                    niceName = "Arcane Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_ELETRIC_RESISTANCE:
                    niceName = "Eletric Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_POISON_RESISTANCE:
                    niceName = "Poison Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_PHYSICAL_RESISTANCE:
                    niceName = "Physical Resistance - " + value.ToString();
                    break;
                case EnumLootStat.STAT_MANA:
                    niceName = "+ " + value.ToString() + " Mana";
                    break;
                case EnumLootStat.STAT_LIFE_PER_SECOND:
                    niceName = "Generate " + value.ToString() + " Life Per Second";
                    break;
                case EnumLootStat.STAT_LIFE_PERCENT:
                    niceName = value.ToString() + "% Life";
                    break;
                case EnumLootStat.STAT_MANA_PER_SECOND:
                    niceName = "Generate " + value.ToString() + " Mana Per Second";
                    break;
            }

            return niceName;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override string GetBonusStatNiceNameDescription(int index)
        {
            EnumLootStat statType = this.m_lootDescription.m_bonusStats.Keys[index];
            float value = this.m_lootDescription.m_bonusStats.Values[index];
            string niceName = "";

            switch (statType)
            {
                case EnumLootStat.STAT_MOVEMENT_SPEED:
                    niceName = "+ " + value.ToString() + "% Movement Speed";
                    break;
                case EnumLootStat.STAT_MAGIC_FIND:
                    niceName = value.ToString() + "% MagicFind";
                    break;
                case EnumLootStat.STAT_MONSTER_GRANT_EXPERIENCE:
                    niceName = "Monster kill grant " + value.ToString() + " experience";
                    break;
                case EnumLootStat.STAT_REDUCE_COOLDOWN_ALL_SKILLS:
                    niceName = "Reduce Cooldown of All Skills - " + value.ToString() + "%";
                    break;
            }

            return niceName;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override void ShowStats()
        {
            foreach (KeyValuePair<EnumLootStat, float> pair in this.m_lootDescription.m_primaryStats)
            {
                string statType = "";
                switch (pair.Key)
                {
                    case EnumLootStat.STAT_MANA:
                        statType = "STAT_MANA";
                        break;
                    case EnumLootStat.STAT_VITALITY:
                        statType = "STAT_VITALITY";
                        break;
                    case EnumLootStat.STAT_STRENGTH:
                        statType = "STAT_STRENGTH";
                        break;
                    case EnumLootStat.STAT_ARMOUR:
                        statType = "STAT_ARMOUR";
                        break;
                    case EnumLootStat.STAT_CRITICAL_CHANCE:
                        statType = "STAT_CRITICAL_CHANCE";
                        break;
                    case EnumLootStat.STAT_CRITICAL_DAMAGE:
                        statType = "STAT_CRITICAL_DAMAGE";
                        break;
                    case EnumLootStat.STAT_ATTACK_SPEED:
                        statType = "STAT_ATTACK_SPEED";
                        break;
                    case EnumLootStat.STAT_MOVEMENT_SPEED:
                        statType = "STAT_MOVEMENT_SPEED";
                        break;
                    case EnumLootStat.STAT_ALL_RESISTANCE:
                        statType = "STAT_ALL_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_FIRE_RESISTANCE:
                        statType = "STAT_FIRE_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_COLD_RESISTANCE:
                        statType = "STAT_COLD_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_ARCANE_RESISTANCE:
                        statType = "STAT_ARCANE_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_ELETRIC_RESISTANCE:
                        statType = "STAT_ELETRIC_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_POISON_RESISTANCE:
                        statType = "STAT_POISON_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_PHYSICAL_RESISTANCE:
                        statType = "STAT_PHYSICAL_RESISTANCE";
                        break;
                    case EnumLootStat.STAT_LIFE_PER_SECOND:
                        statType = "STAT_LIFE_PER_SECOND";
                        break;
                    case EnumLootStat.STAT_LIFE_PERCENT:
                        statType = "STAT_LIFE_PERCENT";
                        break;
                    case EnumLootStat.STAT_MANA_PER_SECOND:
                        statType = "STAT_MANA_PER_SECOND";
                        break;
                    case EnumLootStat.STAT_MONSTER_GRANT_EXPERIENCE:
                        statType = "STAT_MONSTER_GRANT_EXPERIENCE";
                        break;
                    case EnumLootStat.STAT_REDUCE_COOLDOWN_ALL_SKILLS:
                        statType = "STAT_REDUCE_COOLDOWN_ALL_SKILLS";
                        break;
                    case EnumLootStat.STAT_MAGIC_FIND:
                        statType = "STAT_MAGIC_FIND";
                        break;
                }
                Debug.Log(statType + " = " + pair.Value.ToString());
            }
        }
    }
#endif  //WEAPON
    #endregion
}
