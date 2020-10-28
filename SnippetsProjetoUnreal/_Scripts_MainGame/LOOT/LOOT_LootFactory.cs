//==================================================================================================================
//
//	File:	SYS_LootFactory.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot factory class
//
//==================================================================================================================

#define ITEM_FACTORY

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    //==================================================================================================================
    public enum EnumLootStat
    {
        //primary stats
        STAT_VITALITY,
        STAT_STRENGTH,
        STAT_CRITICAL_CHANCE,
        STAT_CRITICAL_DAMAGE,
        STAT_ATTACK_SPEED,
        STAT_ARMOUR,

        //seconday stats
        STAT_ALL_RESISTANCE,
        STAT_FIRE_RESISTANCE,
        STAT_COLD_RESISTANCE,
        STAT_ARCANE_RESISTANCE,
        STAT_ELETRIC_RESISTANCE,
        STAT_POISON_RESISTANCE,
        STAT_PHYSICAL_RESISTANCE,
        STAT_MANA,
        STAT_LIFE_PER_SECOND,
        STAT_LIFE_PERCENT,
        STAT_MANA_PER_SECOND,

        //bonus stats
        STAT_MOVEMENT_SPEED,
        STAT_MAGIC_FIND,
        STAT_REDUCE_COOLDOWN_ALL_SKILLS,
        STAT_MONSTER_GRANT_EXPERIENCE,
    };

    #region ItemFactory Class
#if (ITEM_FACTORY)
    //==================================================================================================================
    public class LootFactory
    {
        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateBattleAxe(int itemLevel)
        {
            AUX_Utility.RandomSeedDateTime();

            ILoot item = new BattleAxeItem();
            item.SetLevelRequirement(itemLevel);
            CreateBattleAxeName(item);

            CreatePrimaryStats(itemLevel, item);
            CreateSecondaryStats(itemLevel, item);
            CreateBonusStats(itemLevel, item);

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateSword(int itemLevel)
        {
            AUX_Utility.RandomSeedDateTime();

            ILoot item = new BattleAxeItem();
            item.SetLevelRequirement(itemLevel);
            CreateSwordName(item);

            CreatePrimaryStats(itemLevel, item);
            CreateSecondaryStats(itemLevel, item);
            CreateBonusStats(itemLevel, item);

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateWarHammer(int itemLevel)
        {
            AUX_Utility.RandomSeedDateTime();

            ILoot item = new BattleAxeItem();
            item.SetLevelRequirement(itemLevel);
            CreateWarHammerName(item);

            CreatePrimaryStats(itemLevel, item);
            CreateSecondaryStats(itemLevel, item);
            CreateBonusStats(itemLevel, item);

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static void CreatePrimaryStats(int itemLevel, ILoot item)
        {
            int amountStats = AUX_Utility.IntRandomRange(2, 5);
            for (int i = 0; i < amountStats; i++)
            {
                int statType = AUX_Utility.IntRandomRange(0, 6);
                CreatePrimaryStatType((EnumLootStat)statType, itemLevel, item);
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        public static void CreateSecondaryStats(int itemLevel, ILoot item)
        {
            int amountStats = 2;
            for (int i = 0; i < amountStats; i++)
            {
                int statType = AUX_Utility.IntRandomRange(6, 17);
                CreateSecondaryStatType((EnumLootStat)statType, itemLevel, item);
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        public static void CreateBonusStats(int itemLevel, ILoot item)
        {
            int amountStats = 2;
            for (int i = 0; i < amountStats; i++)
            {
                int statType = AUX_Utility.IntRandomRange(17, 21);
                CreateBonusStatType((EnumLootStat)statType, itemLevel, item);
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateShoulder(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new ShoulderItem();
            CreateShoulderName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateBoot(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new BootsItem();
            CreateBootsName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateRing(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new RingItem();
            CreateRingName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateAmulet(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new AmuletItem();
            CreateAmuletName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateBelt(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new BeltItem();
            CreateBeltName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreatePants(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new PantsItem();
            CreatePantsName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateHelm(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new HelmItem();
            CreateHelmName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateBracer(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new BracerItem();
            CreateBracerName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateGlove(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new GloveItem();
            CreateGlovesName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateChest(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new ChestItem();
            CreateChestName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        public static ILoot CreateShield(int itemLevel)
        {
            ILoot item = new BattleAxeItem();
            //ILoot item = new ShieldItem();
            CreateShieldName(item);

            //TODO create random stats

            return item;
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateBattleAxeName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Lightbane");
            names.Add("Fate");
            names.Add("Typhoon");
            names.Add("Guard's Axe");
            names.Add("Vengeance Ravager");
            names.Add("Vindictive Steel Cleaver");
            names.Add("Soulless Skeletal Battle Axe");
            names.Add("Scourgeborne, Conqueror of Dragonsouls");
            names.Add("Apocalypse, Crusader of Hell's Games");
            names.Add("Worldcarver, Might of Assassins");
            names.Add("Corpsemaker");
            names.Add("Finality");
            names.Add("Enigma");
            names.Add("Windsong Broadaxe");
            names.Add("Warp Ravager");
            names.Add("Skyfall Ebon Axe");
            names.Add("Zealous Skeletal Battle Axe");
            names.Add("Vanquisher, Glory of Deception");
            names.Add("Skullcleaver, Guardian of Anguish");
            names.Add("Valkyrie, Ferocity of Diligence");
            names.Add("Grieving Blade");
            names.Add("Chieftain");
            names.Add("Ashes");
            names.Add("Twilight Crescent");
            names.Add("Vanquisher Edge");
            names.Add("Soul-Forged Ivory Ravager");
            names.Add("Vicious Glass Greataxe");
            names.Add("Nightfall, Bringer of the Enigma");
            names.Add("Retirement, Crescent of Blood");
            names.Add("Dawn's Edge, Cunning of Dragonsouls");
            names.Add("Orbit");
            names.Add("Piece Maker");
            names.Add("Fury's Gaze");
            names.Add("Defender's Cleaver");
            names.Add("Improved Dualblade");
            names.Add("Smooth Iron Broadaxe");
            names.Add("Lonely Silver War Axe");
            names.Add("Pendulum, Maul of the Night Sky");
            names.Add("Decimation, Greataxe of Inception");
            names.Add("Due Diligence, Legacy of Ending Misery");
            names.Add("Widow Maker");
            names.Add("Last Chance");
            names.Add("Reckoning");
            names.Add("Vicious Edge");
            names.Add("Impure Axe");
            names.Add("Lustful Skeletal Maul");
            names.Add("Renovated Titanium Greataxe");
            names.Add("Peacemaker, Wit of Executions");
            names.Add("Amnesia, Dark Blade of Lost Hope");
            names.Add("Storm Breaker, Promise of Power");
            names.Add("Midnight");
            names.Add("Piety");
            names.Add("Magma");
            names.Add("Burnished Crescent");
            names.Add("Sorrow's Broadaxe");
            names.Add("Sinister Ebon Reaver");
            names.Add("Hero Bone Crescent");
            names.Add("Reign, Etcher of the Lone Wolf");
            names.Add("Blazeguard, Defender of Eternal Sorrow");
            names.Add("Omega, Incarnation of the Moon");
            names.Add("Worldbreaker");
            names.Add("Cyclone");
            names.Add("The Chancellor");
            names.Add("War-Forged Axe");
            names.Add("Rusty Ravager");
            names.Add("Solitude's Steel Ravager");
            names.Add("Infused Ironbark Crescent");
            names.Add("Blind Justice, Might of Shifting Worlds");
            names.Add("Soul Breaker, Doomblade of Assassins");
            names.Add("King's Defender, Ferocity of Corruption");
            names.Add("Savagery");
            names.Add("Knight's Fall");
            names.Add("The Chief");
            names.Add("Reincarnated War Axe");
            names.Add("Keeper's Broadaxe");
            names.Add("Infused Iron Maul");
            names.Add("Blood Infused Ebon Axe");
            names.Add("Pride, Glory of Vengeance");
            names.Add("Honor's Call, Gift of the Fallen");
            names.Add("Dawnbreaker, Guardian of Shifting Sands");
            names.Add("Whirlwind");
            names.Add("Pork-Chopper");
            names.Add("Wolf");
            names.Add("Cataclysmic Edge");
            names.Add("Smooth Axe");
            names.Add("Primitive Titanium Dualblade");
            names.Add("Vanquisher Golden Battle Axe");
            names.Add("The Decapitator, Jaws of Honor");
            names.Add("Misery's End, Greataxe of the Empty Void");
            names.Add("Dawn's Edge, Legacy of Burdens");
            names.Add("Night's Fall");
            names.Add("Doom");
            names.Add("Arondite");
            names.Add("Liar's Ravager");
            names.Add("Spiteful Chopper");
            names.Add("Demonic Steel Cleaver");
            names.Add("Challenger's Titanium Reaver");
            names.Add("Undoing, Ender of the Cataclysm");
            names.Add("Valkyrie, Dualblade of Nightmares");
            names.Add("Destiny, Edge of Invocation");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateSwordName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Blazeguard");
            names.Add("Oathbreaker");
            names.Add("Thunder");
            names.Add("Renovated Spellblade");
            names.Add("Timeworn Protector");
            names.Add("Frail Diamond Scimitar");
            names.Add("Doom Steel Sculptor");
            names.Add("Aetherius, Sword of the Victor");
            names.Add("Agatha, Greatsword of the Forest");
            names.Add("Misery, Conqueror of the Flame");
            names.Add("Light's Bane");
            names.Add("Godslayer");
            names.Add("Divine Light");
            names.Add("Hungering Blade");
            names.Add("Lusting Warblade");
            names.Add("Ghostly Skeletal Shortsword");
            names.Add("Extinction Iron Doomblade");
            names.Add("Fate, Heirloom of Hate");
            names.Add("Worldslayer, Protector of the Protector");
            names.Add("Godslayer, Reaver of Darkness");
            names.Add("Frenzy");
            names.Add("Wit's End");
            names.Add("Ragnarok");
            names.Add("Engraved Spellblade");
            names.Add("Mended Claymore");
            names.Add("Terror Gold Skewer");
            names.Add("Thirsting Obsidian Protector");
            names.Add("Reign, Slayer of the Depth");
            names.Add("Venomshank, Tribute of the Covenant");
            names.Add("Dawn, Butcher of the Lost");
            names.Add("Reign of Misery");
            names.Add("Hope's End");
            names.Add("The Oculus");
            names.Add("Holy Skewer");
            names.Add("Trainee's Reaver");
            names.Add("Crazed Iron Greatsword");
            names.Add("Vicious Gold Reaver");
            names.Add("Grasscutter, Cunning of the West");
            names.Add("Swan Song, Longsword of Time-Lost Memories");
            names.Add("Tyrhung, Savagery of Heroes");
            names.Add("Severance");
            names.Add("Light's Bane");
            names.Add("Nirvana");
            names.Add("Soulcursed Crusader");
            names.Add("Ruby Infused Greatsword");
            names.Add("Liar's Steel Sabre");
            names.Add("Dragon's Gold Defender");
            names.Add("Blinkstrike, Pledge of the Claw");
            names.Add("Tranquility, Might of Shadows");
            names.Add("Amnesia, Deflector of Riddles");
            names.Add("Silverlight");
            names.Add("Hell's Scream");
            names.Add("Infamy");
            names.Add("Primitive Rapier");
            names.Add("Bone Crushing Reaver");
            names.Add("Blazefury Copper Doomblade");
            names.Add("Guardian's Steel Spellblade");
            names.Add("Dawn, Boon of Due Diligence");
            names.Add("Nightcrackle, Ferocity of the Queen");
            names.Add("Dawnbreaker, Spine of Stealth");
            names.Add("Alpha");
            names.Add("Gladius");
            names.Add("Decimation");
            names.Add("Timeworn Claymore");
            names.Add("Heartless Sculptor");
            names.Add("Twilight's Skeletal Doomblade");
            names.Add("Possessed Glass Claymore");
            names.Add("Doomblade, Boon of the Nightstalker");
            names.Add("Soulrapier, Bringer of Phantoms");
            names.Add("Unending Tyranny, Last Hope of the Moon");
            names.Add("Ghostwalker");
            names.Add("Stormbringer");
            names.Add("Righteous Might");
            names.Add("Replica Blade");
            names.Add("Sharpened Etcher");
            names.Add("Brutal Copper Mageblade");
            names.Add("Destiny's Gold Razor");
            names.Add("Mournblade, Whisper of the Basilisk");
            names.Add("Scar, Sabre of the Lasting Night");
            names.Add("Nethersbane, Broadsword of the Lasting Night");
            names.Add("Lightbane");
            names.Add("Stormcaller");
            names.Add("Wolf");
            names.Add("Cold-Forged Mageblade");
            names.Add("Timeworn Longsword");
            names.Add("Corrupted Obsidian Etcher");
            names.Add("Hateful Copper Broadsword");
            names.Add("Ghostwalker, Ender of Bloodlust");
            names.Add("Convergence, Favor of Shadow Strikes");
            names.Add("Needle, Favor of the World");
            names.Add("The Facelifter");
            names.Add("Kinslayer");
            names.Add("Draughtbane");
            names.Add("Vindictive Longsword");
            names.Add("Loyal Sabre");
            names.Add("Honed Gold Deflector");
            names.Add("Curved Glass Blade");
            names.Add("Winterthorn, Destroyer of Lost Worlds");
            names.Add("Seethe, Saber of the Oracle");
            names.Add("Tranquility, Slicer of Dragonsouls");
            
            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateWarHammerName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Termination");
            names.Add("Early Retirement");
            names.Add("Worldcarver");
            names.Add("Harmonized Warmace");
            names.Add("Malificent Pummeler");
            names.Add("Victor Ivory Hammer");
            names.Add("Mourning Bone Pummeler");
            names.Add("Earthshaper, Wit of Corruption");
            names.Add("Bloodmoon, Guardian of Degradation");
            names.Add("Last Rites, Champion of the Night");
            names.Add("Prophecy");
            names.Add("Orenmir");
            names.Add("Hellfire");
            names.Add("Crying Hammer");
            names.Add("Silent Crusher");
            names.Add("Blazefury Adamantite Mace");
            names.Add("Trainee's Bronze Maul");
            names.Add("Dawnbreaker, Call of the Occult");
            names.Add("Celeste, Butcher of Bloodlust");
            names.Add("Celeste, Voice of the Queen");
            names.Add("Oathbreaker");
            names.Add("King's Legacy");
            names.Add("The Chief");
            names.Add("Vile Crusher");
            names.Add("Fragile Crusher");
            names.Add("Moonlit Obsidian Greathammer");
            names.Add("Grim Iron Mallet");
            names.Add("The Chief, Glory of Regret");
            names.Add("Concussion, Ravager of Shifting Sands");
            names.Add("Perfect Storm, Last Stand of Fallen Souls");
            names.Add("Piety");
            names.Add("Lament");
            names.Add("Bloodquench");
            names.Add("Shadow Warmace");
            names.Add("Vindictive Warmace");
            names.Add("Phantom Bronze Scepter");
            names.Add("Soul Infused Ivory Hammer");
            names.Add("Justifier, Bruiser of Torment");
            names.Add("Harmony, Destroyer of the Beast");
            names.Add("Convergence, Last Hope of the Whispers");
            names.Add("Stormrider");
            names.Add("Maneater");
            names.Add("Eternity");
            names.Add("Isolated Battlehammer");
            names.Add("Challenger's Pummeler");
            names.Add("Defender Iron Hammer");
            names.Add("Singing Iron Hammer");
            names.Add("Perfect Storm, Whisper of the Sun");
            names.Add("Hell's Scream, Last Hope of Degradation");
            names.Add("Knight's Honor, Warmace of Ashes");
            names.Add("Jackhammer");
            names.Add("Omega");
            names.Add("Justifier");
            names.Add("Malicious Hammer");
            names.Add("Spectral-Forged Bludgeon");
            names.Add("Lich Bone Maul");
            names.Add("Primal Obsidian Smasher");
            names.Add("Nethersbane, Betrayer of Mountains");
            names.Add("Requiem, Soul of the Wind");
            names.Add("Nighttime, Battlehammer of Shadow Strikes");
            names.Add("Nighttime");
            names.Add("Last Rites");
            names.Add("Willbreaker");
            names.Add("Singed Pummeler");
            names.Add("Grim Mallet");
            names.Add("Thunder Ivory Mallet");
            names.Add("Vindication Bronzed Pummeler");
            names.Add("Amnesia, Boon of the Emperor");
            names.Add("Suspension, Vengeance of Shadows");
            names.Add("Ghostwalker, Defender of Storms");
            names.Add("Midnight");
            names.Add("Chieftain");
            names.Add("Suspension");
            names.Add("Misfortune's Maul");
            names.Add("Corrupted Warmace");
            names.Add("Forsaken Iron Bludgeon");
            names.Add("Mended Adamantite Crusher");
            names.Add("Termination, Dawn of Dark Magic");
            names.Add("Tank, Reach of the Whispers");
            names.Add("Ashrune, Betrayer of Ended Dreams");
            names.Add("Maneater");
            names.Add("Worldslayer");
            names.Add("Seism");
            names.Add("Hateful Smasher");
            names.Add("Undead Crusher");
            names.Add("Guard's Steel Battlehammer");
            names.Add("Bloodlord's Ivory Smasher");
            names.Add("Honor's Call, Boon of the Night");
            names.Add("Retirement, Bludgeon of Storms");
            names.Add("Grace, Protector of the Depth");
            names.Add("Deathraze");
            names.Add("Orenmir");
            names.Add("Earthshaper");
            names.Add("Retribution Maul");
            names.Add("Curved Pummeler");
            names.Add("Hopeless Skeletal Warmace");
            names.Add("Infused Skeletal Mallet");
            names.Add("Corpsemaker, Last Hope of the Gladiator");
            names.Add("Glimmer, Slayer of the Occult");
            names.Add("Nethersbane, Call of Riddles");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateShoulderName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Shoulderguards of Haunted Might");
            names.Add("Shoulderwraps of Divine Hell");
            names.Add("Demon Shoulders of Hallowed Ancestors");
            names.Add("Bronze Spaulders of Condemned Might");
            names.Add("Destiny's Demon Shoulders");
            names.Add("Fierce Obsidian Shoulderwraps");
            names.Add("Oathkeeper's Spaulders of the Storm");
            names.Add("Conqueror Spaulders of Miracles");
            names.Add("Crusader of the Damned");
            names.Add("Terror of Ended Dreams");
            names.Add("Shoulderguards of Infernal Vengeance");
            names.Add("Shoulders of Condemned Worlds");
            names.Add("Plate Shoulders of Endless Souls");
            names.Add("Steel Shoulderguards of Eternal Punishment");
            names.Add("Howling Skeletal Shoulderwraps");
            names.Add("Hatred Skeletal Mantle");
            names.Add("Shoulders of Defiance");
            names.Add("Dire Shoulders of Infinity");
            names.Add("Curator of the Lionheart");
            names.Add("Demise of the Lone Victor");
            names.Add("Mantle of Fleeting Worlds");
            names.Add("Mantle of Blind Bloodlust");
            names.Add("Chainmail Spaulders of Doomed Voices");
            names.Add("Chainmail Spaulders of Infernal Fortune");
            names.Add("Whistling Demon Shoulders");
            names.Add("Soul Obsidian Shoulders");
            names.Add("Doom Shoulders of the Lost");
            names.Add("Faith's Shoulders of Faded Memories");
            names.Add("Fall of Subtlety");
            names.Add("Boon of Terrors");
            names.Add("Shoulders of Conquered Souls");
            names.Add("Shoulderguards of Dark Kings");
            names.Add("Titanium Shoulders of Shattered Bloodlust");
            names.Add("Chainmail Shoulderwraps of Imminent Whispers");
            names.Add("Destiny's Plate Mantle");
            names.Add("Fire Infused Steel Shoulderwraps");
            names.Add("Thunderguard Spaulders of the Beast");
            names.Add("Ruby Infused Shoulders of the Gargoyle");
            names.Add("Emissary of the Sun");
            names.Add("Dawn of the Mage");
            names.Add("Shoulderguards of Timeless Dreams");
            names.Add("Shoulderwraps of Faded Voices");
            names.Add("Mail Shoulderwraps of Frozen Fires");
            names.Add("Silver Shoulders of Sacred Fires");
            names.Add("Dire Scaled Spaulders");
            names.Add("Thunder-Forged Chainmail Shoulders");
            names.Add("Guard's Shoulderguards of the Leviathan");
            names.Add("Bloodsurge Shoulderguards of Broken Bones");
            names.Add("Defiler of the Volcano");
            names.Add("Keeper of Eternal Bloodlust");
            names.Add("Shoulders of Holy Hells");
            names.Add("Shoulderwraps of Damned Magic");
            names.Add("Silver Shoulderguards of Blessed Power");
            names.Add("Chainmail Shoulderwraps of Shattered Magic");
            names.Add("Captain's Chainmail Shoulderwraps");
            names.Add("Reincarnated Skeletal Shoulders");
            names.Add("Brutal Shoulders of the Prisoner");
            names.Add("Jade Infused Shoulders of the Seer");
            names.Add("Steward of Cataclysms");
            names.Add("Dawn of Heroes");
            names.Add("Spaulders of Holy Memories");
            names.Add("Mantle of Blind Magic");
            names.Add("Silver Shoulders of Hallowed Hell");
            names.Add("Demon Shoulders of Haunted Memories");
            names.Add("Peacekeeper's Bone Shoulderguards");
            names.Add("Fortune's Scaled Shoulders");
            names.Add("Soul Infused Shoulderguards of Fools");
            names.Add("Peacekeeper's Shoulderwraps of Barriers");
            names.Add("Hope of the East");
            names.Add("Glory of the Bear");
            names.Add("Shoulders of Smoldering Dreams");
            names.Add("Mantle of Frozen Nights");
            names.Add("Plate Mantle of Endless Ancestors");
            names.Add("Mail Spaulders of Timeless Sorrow");
            names.Add("Zealous Demon Shoulderguards");
            names.Add("Vengeful Skeletal Shoulderwraps");
            names.Add("Ruby Infused Spaulders of Woe");
            names.Add("Vanquisher Shoulderguards of the Eagle");
            names.Add("Glory of Moonlight");
            names.Add("Call of Lifemending");
            names.Add("Spaulders of Ancient Powers");
            names.Add("Shoulders of Smoldering Whispers");
            names.Add("Skeletal Shoulderwraps of Smoldering Ancestors");
            names.Add("Silver Mantle of Haunted Comrades");
            names.Add("Vengeful Bone Mantle");
            names.Add("Windsong Adamantite Shoulderguards");
            names.Add("Reincarnated Shoulderwraps of Putrefaction");
            names.Add("Vindictive Shoulders of Honor");
            names.Add("End of Shadows");
            names.Add("Last Stand of Broken Worlds");
            names.Add("Spaulders of Condemned Torment");
            names.Add("Shoulderwraps of Hellish Nights");
            names.Add("Adamantite Shoulderwraps of Binding Fortune");
            names.Add("Bronzed Shoulderwraps of Timeless Dreams");
            names.Add("Vindictive Demon Mantle");
            names.Add("Lusting Golden Shoulderwraps");
            names.Add("Conqueror's Shoulders of the Moon");
            names.Add("Cataclysm Spaulders of Moonlight");
            names.Add("Ward of the Warrior");
            names.Add("Vengeance of the Undying");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateBootsName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Boots of Shattered Bloodlust");
            names.Add("Greaves of Distant Voices");
            names.Add("Titanium Stompers of Dark Fires");
            names.Add("Silver Greaves of Demonic Sorrow");
            names.Add("Firesoul Titanium Greaves");
            names.Add("Shadow Chainmail Warboots");
            names.Add("Cursed Ivory Footguards");
            names.Add("Hope's Spurs of the Titans");
            names.Add("Desire's Warboots of Truth");
            names.Add("Furious Stompers of Trust");
            names.Add("Boots of Endless Torment");
            names.Add("Spurs of Timeless Honor");
            names.Add("Iron Footguards of Infernal Kings");
            names.Add("Iron Boots of Doomed Whispers");
            names.Add("Demonic Chain Warboots");
            names.Add("Desolation Bronzed Walkers");
            names.Add("Twilight Bronze Warboots");
            names.Add("Twilight's Stompers of Tears");
            names.Add("Renovated Stompers of the Protector");
            names.Add("Thunder-Forged Treads of the Scourge");
            names.Add("Greatboots of Condemned Damnation");
            names.Add("Walkers of Burning Dreams");
            names.Add("Scaled Greaves of Lost Visions");
            names.Add("Ebon Treads of Cursed Glory");
            names.Add("Trainee's Ivory Treads");
            names.Add("Demonic Titanium Walkers");
            names.Add("Warrior's Adamantite Feet");
            names.Add("Gladiator Stompers of Pride's Fall");
            names.Add("Misfortune's Treads of Fleet Feet");
            names.Add("Bandit's Stompers of Anguish");
            names.Add("Treads of Dark Hells");
            names.Add("Sabatons of Endless Sorrow");
            names.Add("Chain Greaves of Demonic Visions");
            names.Add("Chain Warboots of Infernal Sorrow");
            names.Add("Captain's Ivory Spurs");
            names.Add("Cataclysm Golden Spurs");
            names.Add("Mourning Demon Warboots");
            names.Add("Wrathful Footguards of Ends");
            names.Add("Warlord's Treads of the Daywalker");
            names.Add("Forsaken Warboots of Frost Power");
            names.Add("Feet of Distant Torment");
            names.Add("Boots of Blessed Hells");
            names.Add("Mithril Warboots of Burning Protection");
            names.Add("Ivory Boots of Condemned Vengeance");
            names.Add("Firesoul Adamantite Greaves");
            names.Add("Thunder Iron Boots");
            names.Add("Tyrannical Obsidian Warboots");
            names.Add("Mercenary Boots of the Phoenix");
            names.Add("Keeper's Footguards of Broken Worlds");
            names.Add("Fierce Feet of Ended Dreams");
            names.Add("Greaves of Haunted Trials");
            names.Add("Treads of Eternal Powers");
            names.Add("Golden Boots of Demonic Hell");
            names.Add("Chain Sabatons of Smoldering Misery");
            names.Add("Enchanted Adamantite Greatboots");
            names.Add("War-Forged Bone Warboots");
            names.Add("Corrupted Golden Treads");
            names.Add("Guard's Greatboots of Blast Protection");
            names.Add("Arcane Boots of Grieving Widows");
            names.Add("Legionnaire's Greaves of the Summoner");
            names.Add("Footguards of Holy Hope");
            names.Add("Sabatons of Doomed Whispers");
            names.Add("Ivory Walkers of Dark Trials");
            names.Add("Scaled Warboots of Immortal Might");
            names.Add("Captain's Iron Spurs");
            names.Add("Restored Scaled Stompers");
            names.Add("Judgement Skeletal Feet");
            names.Add("Baneful Walkers of Hope");
            names.Add("Knightly Sabatons of the Mage");
            names.Add("Zealous Spurs of the Eclipse");
            names.Add("Footguards of Eternal Nightmares");
            names.Add("Greaves of Divine Illusions");
            names.Add("Bone Greaves of Relentless Might");
            names.Add("Demon Treads of Distant Sorrow");
            names.Add("Gladiator's Golden Spurs");
            names.Add("Roaring Iron Feet");
            names.Add("Demonic Golden Boots");
            names.Add("Warden's Feet of Ancient Powers");
            names.Add("Bandit's Boots of the Prophet");
            names.Add("Vindicator Walkers of Lost Souls");
            names.Add("Treads of Burning Might");
            names.Add("Treads of Hallowed Voices");
            names.Add("Scaled Spurs of Broken Hells");
            names.Add("Chainmail Greaves of Sacred Glory");
            names.Add("Burnished Chainmail Warboots");
            names.Add("Singing Mail Footguards");
            names.Add("Storm Chainmail Treads");
            names.Add("Malicious Feet of the Dreadlord");
            names.Add("Phantom Stompers of Dusk");
            names.Add("Thunderguard Warboots of Despair");
            names.Add("Footguards of Timeless Whispers");
            names.Add("Greatboots of Cursed Sorrow");
            names.Add("Golden Greatboots of Blind Damnation");
            names.Add("Chainmail Stompers of Hallowed Fire");
            names.Add("Hungering Bronzed Greatboots");
            names.Add("Retribution Demon Spurs");
            names.Add("Extinction Ebon Walkers");
            names.Add("Frozen Feet of Eternal Glory");
            names.Add("Rune-Forged Feet of the Night Sky");
            names.Add("Blood Infused Stompers of Prophecies");
            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRingName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Medieval Ring");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateAmuletName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Medieval Amulet");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");
            names.Add("");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateBeltName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Links of Ominous Visions");
            names.Add("Chain of Dark Voices");
            names.Add("Bronze Waistband of Fleeting Sorrow");
            names.Add("Ivory Links of Faded Whispers");
            names.Add("Doom Iron Belt");
            names.Add("Faith's Scaled Links");
            names.Add("Shadow Steel Waistguard");
            names.Add("Loyal Waistguard of the South");
            names.Add("Legionnaire's Links of the Light");
            names.Add("Frozen Links of Frost Resist");
            names.Add("Links of Ending Torment");
            names.Add("Gunbelt of Damned Wars");
            names.Add("Mithril Waistband of Divine Honor");
            names.Add("Titanium Links of Fallen Ancestors");
            names.Add("Thunder Bronze Cord");
            names.Add("Retribution Ebon Links");
            names.Add("Victor Bronze Girdle");
            names.Add("Unholy Belt of the South");
            names.Add("Thundersoul Cord of Swordbreaking");
            names.Add("Oathkeeper's Waistguard of Truth");
            names.Add("Band of Broken Nightmares");
            names.Add("Girdle of Immortal Misery");
            names.Add("Bronzed Belt of Unholy Nights");
            names.Add("Iron Chain of Burning Damnation");
            names.Add("Fierce Bronze Waistguard");
            names.Add("Loyal Silver Band");
            names.Add("Vicious Scaled Cord");
            names.Add("Roaring Links of Ending Misery");
            names.Add("Bandit's Cord of the Protector");
            names.Add("Hero's Cord of the Moonwalker");
            names.Add("Gunbelt of Divine Hells");
            names.Add("Girdle of Blessed Trials");
            names.Add("Silver Girdle of Frozen Hells");
            names.Add("Titanium Chain of Eternal Memories");
            names.Add("Cataclysmic Mithril Cord");
            names.Add("Storm-Forged Demon Cord");
            names.Add("Frenzied Bone Girdle");
            names.Add("Cord of Assassination");
            names.Add("Twisted Waistguard of Unholy Might");
            names.Add("Protector's Waistband of Assaults");
            names.Add("Links of Divine Kings");
            names.Add("Girdle of Silent Lands");
            names.Add("Bone Gunbelt of Smoldering Trials");
            names.Add("Titanium Band of Infernal Warlords");
            names.Add("Soul Bronzed Waistguard");
            names.Add("Vindication Bronzed Gunbelt");
            names.Add("Barbaric Bone Band");
            names.Add("Grieving Links of Infinite Trials");
            names.Add("Renovated Band of the Depths");
            names.Add("Woeful Waistband of the Dead");
            names.Add("Waistguard of Infernal Nights");
            names.Add("Waistband of Unholy Freedom");
            names.Add("Bronzed Girdle of Imminent Justice");
            names.Add("Bone Waistband of Eternal Powers");
            names.Add("Proud Steel Gunbelt");
            names.Add("Crazed Silver Gunbelt");
            names.Add("Solitude's Bone Belt");
            names.Add("Cataclysm Chain of Blessed Fortune");
            names.Add("Demonic Gunbelt of the Talon");
            names.Add("Warped Girdle of Cunning");
            names.Add("Girdle of Blessed Torment");
            names.Add("Links of Smoldering Visions");
            names.Add("Skeletal Gunbelt of Burning Fires");
            names.Add("Demon Chain of Infernal Illusions");
            names.Add("Guardian's Obsidian Waistband");
            names.Add("Tyrannical Skeletal Girdle");
            names.Add("Inherited Obsidian Belt");
            names.Add("Warrior Band of the Protector");
            names.Add("Girdle of Blight");
            names.Add("Loyal Band of Ending Hope");
            names.Add("Chain of Distant Whispers");
            names.Add("Cord of Twisted Lands");
            names.Add("Iron Waistband of Fleeting Lands");
            names.Add("Bronzed Waistband of Ominous Fires");
            names.Add("Malicious Skeletal Waistband");
            names.Add("Hope's Iron Gunbelt");
            names.Add("Ominous Titanium Waistguard");
            names.Add("Gladiator Band of Thorns");
            names.Add("Cataclysmic Band of the Depth");
            names.Add("Feral Chain of the World");
            names.Add("Waistband of Relentless Misery");
            names.Add("Girdle of Silent Ancestors");
            names.Add("Mithril Band of Fleeting Lands");
            names.Add("Ivory Gunbelt of Holy Fires");
            names.Add("Cold-Forged Demon Girdle");
            names.Add("Gladiator's Bronze Gunbelt");
            names.Add("Guardian's Titanium Waistguard");
            names.Add("Knightly Girdle of Broken Families");
            names.Add("Storm Waistband of Reckoning");
            names.Add("Jade Infused Waistband of Dreams");
            names.Add("Girdle of Fleeting Nights");
            names.Add("Band of Unholy Protection");
            names.Add("Iron Gunbelt of Blind Punishment");
            names.Add("Adamantite Waistband of Sacred Might");
            names.Add("Storm Skeletal Band");
            names.Add("Shadow Adamantite Band");
            names.Add("Loyal Iron Belt");
            names.Add("Thunder Cord of the North");
            names.Add("Malicious Waistband of Dishonor");
            names.Add("Extinction Belt of Unholy Blight");
            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreatePantsName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Kilt of Demonic Wars");
            names.Add("Skirt of Condemned Vengeance");
            names.Add("Chain Greaves of Doomed Warlords");
            names.Add("Obsidian Legplates of Imminent Dreams");
            names.Add("Keeper's Iron Leggings");
            names.Add("Judgement Mail Platelegs");
            names.Add("Tyrannical Skirt of Valor");
            names.Add("Eternal Leggings of Mists");
            names.Add("Guard of the Serpent");
            names.Add("Bond of Enchantments");
            names.Add("Leggings of Binding Magic");
            names.Add("Kilt of Frozen Wars");
            names.Add("Bronzed Platelegs of Hallowed Hells");
            names.Add("Titanium Skirt of Dark Justice");
            names.Add("Undead Skeletal Leggings");
            names.Add("Banished Chain Platelegs");
            names.Add("Pride's Legguards of the Knight");
            names.Add("Restored Kilt of the Harvest");
            names.Add("Hero of Lost Souls");
            names.Add("Legacy of Dread");
            names.Add("Platelegs of Ominous Fire");
            names.Add("Greaves of Cursed Warlords");
            names.Add("Bone Legguards of Demonic Whispers");
            names.Add("Titanium Leggings of Demonic Nightmares");
            names.Add("Vanquisher Bone Legguards");
            names.Add("Soul Infused Bronzed Greaves");
            names.Add("Recruit's Legplates of Fire Magic");
            names.Add("Thundersoul Legguards of Ending Misery");
            names.Add("Destroyer of the Basilisk");
            names.Add("Memory of the Depth");
            names.Add("Greaves of Cursed Fires");
            names.Add("Leggings of Unholy Fire");
            names.Add("Ebon Platelegs of Blessed Fortune");
            names.Add("Ebon Legguards of Infinite Dreams");
            names.Add("Primal Demon Kilt");
            names.Add("Malevolent Golden Skirt");
            names.Add("Kilt of Hellish Torment");
            names.Add("Twilight's Platelegs of Ancient Power");
            names.Add("Visage of Silence");
            names.Add("Fortune of the Prisoner");
            names.Add("Legguards of Demonic Nightmares");
            names.Add("Legplates of Blind Glory");
            names.Add("Skeletal Legguards of Unholy Honor");
            names.Add("Mail Platelegs of Condemned Glory");
            names.Add("Defender's Chainmail Skirt");
            names.Add("Massive Demon Legplates");
            names.Add("Leggings of the Warrior");
            names.Add("Heartless Platelegs of War");
            names.Add("Token of the Ward");
            names.Add("Legacy of Terrors");
            names.Add("Skirt of Haunted Nightmares");
            names.Add("Skirt of Infernal Powers");
            names.Add("Silver Leggings of Immortal Misery");
            names.Add("Ebon Platelegs of Haunted Ancestors");
            names.Add("Thunderfury Steel Legplates");
            names.Add("Knightly Ivory Skirt");
            names.Add("Hatred Skirt of Delusions");
            names.Add("Doom Leggings of Grieving Widows");
            names.Add("Vengeance of Whispers");
            names.Add("Curator of Eternity");
            names.Add("Leggings of Smoldering Lands");
            names.Add("Leggings of Blind Fortunes");
            names.Add("Mail Legplates of Conquered Magic");
            names.Add("Bone Legplates of Faded Freedom");
            names.Add("Mail Kilt");
            names.Add("Honed Bronze Legplates");
            names.Add("Spectral Skirt of the King");
            names.Add("Nightmare Skirt of the Gladiator");
            names.Add("Defense of Annihilation");
            names.Add("Bane of the Gargoyle");
            names.Add("Skirt of Demonic Worlds");
            names.Add("Leggings of Endless Lands");
            names.Add("Bone Platelegs of Eternal Power");
            names.Add("Ebon Leggings of Eternal Fires");
            names.Add("Renewed Bronzed Legplates");
            names.Add("Corrupted Iron Legplates");
            names.Add("Soul-Forged Legplates of Hell");
            names.Add("Tyrannical Legguards of the Setting Sun");
            names.Add("Legplates of Blast Protection");
            names.Add("Terror of Life");
            names.Add("Legplates of Unholy Protection");
            names.Add("Leggings of Doomed Magic");
            names.Add("Adamantite Leggings of Frozen Fire");
            names.Add("Skeletal Skirt of Infernal Comrades");
            names.Add("Hollow Chainmail Skirt");
            names.Add("Blood Infused Demon Leggings");
            names.Add("Burnished Platelegs of Resilience");
            names.Add("Champion Skirt of the Mountain");
            names.Add("Kilt of Sunfire");
            names.Add("Blessing of Hell");
            names.Add("Greaves of Smoldering Hell");
            names.Add("Kilt of Burning Lands");
            names.Add("Obsidian Kilt of Distant Damnation");
            names.Add("Bronzed Legplates of Twisted Glory");
            names.Add("Proud Chainmail Greaves");
            names.Add("Storm-Forged Ivory Skirt");
            names.Add("Silent Legguards of the Berserker");
            names.Add("Greaves of Desecration");
            names.Add("Might of Light's Hope");
            names.Add("Scales of Lost Voices");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateHelmName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Gaze of Faded Powers");
            names.Add("Helmet of Twisted Kings");
            names.Add("Silver Helm of Infernal Hell");
            names.Add("Titanium Faceguard of Smoldering Freedom");
            names.Add("Atuned Ebon Headguard");
            names.Add("Thunder-Forged Mithril Helm");
            names.Add("Holy Helm of Demons");
            names.Add("Destiny's Crown of Zeal");
            names.Add("Oath of the Phoenix");
            names.Add("Heirloom of Fire Resist");
            names.Add("Headguard of Blind Damnation");
            names.Add("Faceguard of Broken Wars");
            names.Add("Adamantite Crown of Fallen Illusions");
            names.Add("Scaled Helm of Ending Protection");
            names.Add("Howling Golden Casque");
            names.Add("Captain's Obsidian Casque");
            names.Add("Warrior Greathelm of Deception");
            names.Add("Mended Helm of Titans");
            names.Add("Legacy of Dragonsouls");
            names.Add("Death of Mercy");
            names.Add("Helmet of Imminent Illusions");
            names.Add("Helm of Silent Nights");
            names.Add("Adamantite Helm of Burning Honor");
            names.Add("Skeletal Crown of Infinite Punishment");
            names.Add("Relentless Obsidian Crown");
            names.Add("Brutal Adamantite Greathelm");
            names.Add("Bandit's Gaze of Mysteries");
            names.Add("Vindication Greathelm of Demon Fire");
            names.Add("Call of Undoing");
            names.Add("Visage of Truth");
            names.Add("Visage of Lost Kings");
            names.Add("Helm of Cursed Nightmares");
            names.Add("Golden Casque of Demonic Protection");
            names.Add("Plate Casque of Divine Wars");
            names.Add("Peacekeeper's Bronze Helm");
            names.Add("Doom Titanium Casque");
            names.Add("Hopeless Casque of the Banished");
            names.Add("Sorrow's Crown of the Wolf");
            names.Add("Hero of Thunders");
            names.Add("Helm of Patience");
            names.Add("Helmet of Dark Warlords");
            names.Add("Greathelm of Imminent Dreams");
            names.Add("Bronze Faceguard of Frozen Souls");
            names.Add("Demon Greathelm of Fallen Worlds");
            names.Add("Reincarnated Titanium Visage");
            names.Add("Reincarnated Silver Helmet");
            names.Add("Jaws of Dominance");
            names.Add("Solitude's Crown of the Incoming Storm");
            names.Add("Soul of Vengeance");
            names.Add("Dawn of Domination");
            names.Add("Faceguard of Divine Souls");
            names.Add("Headcover of Ominous Illusions");
            names.Add("Obsidian Helm of Smoldering Visions");
            names.Add("Ivory Casque of Distant Justice");
            names.Add("Gladiator Bone Headcover");
            names.Add("Cold-Forged Demon Headguard");
            names.Add("Ritual Greathelm of Clarity");
            names.Add("Howling Helm of Holy Might");
            names.Add("Burden of the Lion");
            names.Add("Promise of Suffering");
            names.Add("Crown of Divine Damnation");
            names.Add("Faceguard of Ancient Sorrow");
            names.Add("Ivory Helm of Binding Hells");
            names.Add("Bronze Headcover of Silent Trials");
            names.Add("Defender's Adamantite Headguard");
            names.Add("Military Bone Helm");
            names.Add("Misfortune's Helmet of the Gods");
            names.Add("Defiled Headcover of the Blessed");
            names.Add("Shepherd of Immortality");
            names.Add("Curator of Creation");
            names.Add("Helm of Fleeting Sorrow");
            names.Add("Headguard of Hellish Visions");
            names.Add("Steel Gaze of Broken Hells");
            names.Add("Ebon Greathelm of Cursed Memories");
            names.Add("Malicious Obsidian Helm");
            names.Add("Hero Ivory Helmet");
            names.Add("Champion's Casque of the Night");
            names.Add("Guardian's Visage of Blessed Fortune");
            names.Add("Deflector of the Summoner");
            names.Add("Voice of Lost Voices");
            names.Add("Gaze of Ominous Might");
            names.Add("Faceguard of Relentless Honor");
            names.Add("Skeletal Jaws of Damned Protection");
            names.Add("Plate Visage of Hallowed Misery");
            names.Add("Atuned Demon Greathelm");
            names.Add("Woeful Golden Greathelm");
            names.Add("Storm-Forged Helm of Zeal");
            names.Add("Fortune's Crown of Runes");
            names.Add("Emissary of the Crown");
            names.Add("Token of Pride");
            names.Add("Crown of Damned Magic");
            names.Add("Helmet of Distant Honor");
            names.Add("Bronzed Faceguard of Silent Voices");
            names.Add("Ivory Headguard of Imminent Vengeance");
            names.Add("Frozen Plate Casque");
            names.Add("Twisted Ivory Gaze");
            names.Add("Primal Helmet of Lost Voices");
            names.Add("Silent Helm of Lost Souls");
            names.Add("Bond of Horrors");
            names.Add("Bane of the Depths");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateBracerName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Wristguards of Timeless Visions");
            names.Add("Armbands of Demonic Fire");
            names.Add("Ebon Armguards of Damned Bloodlust");
            names.Add("Demon Bracers of Demonic Hope");
            names.Add("Possessed Mail Bracers");
            names.Add("Vanquisher Bronzed Bracers");
            names.Add("Timeworn Demon Vambraces");
            names.Add("Vanquisher Bracers of the Hunter");
            names.Add("Bloodsurge Armguards of Dismay");
            names.Add("Cold-Forged Wristguards of Reckoning");
            names.Add("Armguards of Holy Glory");
            names.Add("Armbands of Silent Power");
            names.Add("Silver Armbands of Binding Wars");
            names.Add("Scaled Armbands of Lost Wars");
            names.Add("Vindictive Steel Armbands");
            names.Add("Jade Infused Mail Vambraces");
            names.Add("Crazed Demon Armbands");
            names.Add("Brutal Vambraces of Ending Hope");
            names.Add("Renovated Armbands of the Wolf");
            names.Add("Blood Infused Armbands of Bravery");
            names.Add("Armbands of Faded Protection");
            names.Add("Armguards of Distant Power");
            names.Add("Mithril Wristguards of Sacred Hope");
            names.Add("Ivory Wristguards of Ending Dreams");
            names.Add("Vengeance Ivory Armbands");
            names.Add("Wicked Scaled Wristguards");
            names.Add("Loyal Adamantite Armbands");
            names.Add("Misfortune's Vambraces of the Prophet");
            names.Add("Peacekeeper's Bracers of the Storm");
            names.Add("Frenzied Armbands of the Emperor");
            names.Add("Heavy Bracers  Light Bracers");
            names.Add("Vambraces of Silent Protection");
            names.Add("Vambraces of Lost Bloodlust");
            names.Add("Chainmail Bracers of Imminent Justice");
            names.Add("Ebon Armguards of Doomed Protection");
            names.Add("Storm-Forged Iron Bracers");
            names.Add("Faith's Silver Wristguards");
            names.Add("Mourning Titanium Armbands");
            names.Add("Feral Wristguards of the Victor");
            names.Add("Sorrow's Armbands of Delusions");
            names.Add("Military Vambraces of Eternal Bloodlust");
            names.Add("Armbands of Timeless Nights");
            names.Add("Armguards of Timeless Whispers");
            names.Add("Chainmail Vambraces of Cursed Warlords");
            names.Add("Skeletal Wristguards of Damned Glory");
            names.Add("Lightning Titanium Vambraces");
            names.Add("Trainee's Mail Armbands");
            names.Add("Solitude's Titanium Vambraces");
            names.Add("Burnished Wristguards of Dread");
            names.Add("Bloodied Bracers of Greed");
            names.Add("Conqueror Armbands of Ice Magic");
            names.Add("Armguards of Infernal Torment");
            names.Add("Armbands of Binding Fires");
            names.Add("Ebon Armbands of Smoldering Illusions");
            names.Add("Ebon Armbands of Divine Fortune");
            names.Add("Hopeless Golden Armguards");
            names.Add("War-Forged Bronzed Armbands");
            names.Add("Engraved Obsidian Bracers");
            names.Add("Battleworn Vambraces of Terrors");
            names.Add("Conqueror's Bracers of the Ward");
            names.Add("Ancient Armguards of Broken Worlds");
            names.Add("Bracers of Endless Glory");
            names.Add("Wristguards of Lost Damnation");
            names.Add("Bronze Bracers of Hellish Trials");
            names.Add("Chain Vambraces of Divine Fires");
            names.Add("Warped Mail Bracers");
            names.Add("Proud Scaled Bracers");
            names.Add("Demonic Ebon Armbands");
            names.Add("Unholy Vambraces of Deception");
            names.Add("Cataclysm Armbands of the Phoenix");
            names.Add("Military Armguards of Ending Hope");
            names.Add("Wristguards of Blind Fortune");
            names.Add("Wristguards of Immortal Justice");
            names.Add("Skeletal Armguards of Binding Honor");
            names.Add("Titanium Wristguards of Unholy Misery");
            names.Add("Knightly Golden Wristguards");
            names.Add("Ruby Infused Demon Bracers");
            names.Add("Vicious Silver Vambraces");
            names.Add("Misfortune's Vambraces of Firmness");
            names.Add("Wristguards of Annihilation");
            names.Add("Warrior's Bracers of Deflection");
            names.Add("Vambraces of Smoldering Ancestors");
            names.Add("Armguards of Infinite Wars");
            names.Add("Ivory Armbands of Doomed Ancestors");
            names.Add("Iron Armbands of Fleeting Punishment");
            names.Add("War-Forged Obsidian Armbands");
            names.Add("Defender Titanium Vambraces");
            names.Add("Fortune's Scaled Armguards");
            names.Add("Fusion Armbands of the Caged Mind");
            names.Add("Oathkeeper's Armguards of the Queen");
            names.Add("Faith's Wristguards of Delirium");
            names.Add("Wristguards of Infernal Hell");
            names.Add("Vambraces of Fallen Protection");
            names.Add("Demon Bracers of Conquered Fortune");
            names.Add("Bone Armguards of Blind Glory");
            names.Add("Conqueror's Skeletal Armguards");
            names.Add("Military Scaled Armbands");
            names.Add("Military Iron Armguards");
            names.Add("Extinction Armbands of Eternal Sorrow");
            names.Add("Bloodsurge Wristguards of Titans");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateGlovesName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Handguards of Twisted Fortune");
            names.Add("Grasps of Imminent Souls");
            names.Add("Titanium Grasps of Burning Fortunes");
            names.Add("Adamantite Handguards of Hellish Might");
            names.Add("Crazed Iron Grasps");
            names.Add("Warrior's Bronzed Hands");
            names.Add("Timeworn Iron Warfists");
            names.Add("Yearning Handguards of Healing");
            names.Add("Phantom Hands of Demons");
            names.Add("Mended Warfists of the Flames");
            names.Add("Gloves of Silent Powers");
            names.Add("Fists of Blessed Vengeance");
            names.Add("Silver Grips of Sacred Comrades");
            names.Add("Iron Fists of Sacred Punishment");
            names.Add("Fierce Chainmail Grips");
            names.Add("Howling Iron Hands");
            names.Add("Challenger's Scaled Fists");
            names.Add("Cursed Fists of the Lone Wolf");
            names.Add("Malicious Fists of Stone");
            names.Add("Fiery Grasps of Glory");
            names.Add("Hands of Fallen Nightmares");
            names.Add("Fists of Hallowed Ancestors");
            names.Add("Skeletal Gloves of Demonic Warlords");
            names.Add("Bronzed Grips of Distant Torment");
            names.Add("Wrathful Golden Gauntlets");
            names.Add("Heartless Mail Fists");
            names.Add("Challenger Silver Gloves");
            names.Add("Thundersoul Warfists of Infinity");
            names.Add("Storm Grasps of the Burning Sun");
            names.Add("Soulless Gloves of Doom");
            names.Add("Grasps of Endless Dreams");
            names.Add("Fists of Smoldering Trials");
            names.Add("Ivory Grasps of Faded Fires");
            names.Add("Bone Handguards of Hellish Powers");
            names.Add("Hero Silver Warfists");
            names.Add("Malicious Mail Hands");
            names.Add("Cold-Forged Iron Grips");
            names.Add("Bandit's Warfists of Blight");
            names.Add("Incarnated Hands of Terror");
            names.Add("Bandit's Hands of the Archer");
            names.Add("Gloves of Cursed Nightmares");
            names.Add("Gauntlets of Fleeting Visions");
            names.Add("Bronzed Hands of Relentless Dreams");
            names.Add("Iron Grasps of Endless Souls");
            names.Add("Whistling Iron Grasps");
            names.Add("Victor Silver Gauntlets");
            names.Add("Guardian's Skeletal Grasps");
            names.Add("Legionnaire's Gloves of Frost Resist");
            names.Add("Destiny's Grasps of Infinite Trials");
            names.Add("Bloodlord's Grasps of Extinction");
            names.Add("Warfists of Sacred Torment");
            names.Add("Warfists of Fallen Fire");
            names.Add("Chainmail Handguards of Conquered Worlds");
            names.Add("Ivory Gauntlets of Hellish Nights");
            names.Add("Doom Golden Gloves");
            names.Add("War-Forged Silver Grasps");
            names.Add("Wind's Ivory Hands");
            names.Add("Cold-Forged Fists of the Wretched");
            names.Add("Wind-Forged Hands of Fallen Kings");
            names.Add("Haunted Warfists of Conquered Worlds");
            names.Add("Grips of Dark Voices");
            names.Add("Grips of Binding Hell");
            names.Add("Mithril Grips of Doomed Protection");
            names.Add("Steel Gauntlets of Conquered Damnation");
            names.Add("Renovated Skeletal Handguards");
            names.Add("Military Obsidian Grips");
            names.Add("Rune-Forged Golden Fists");
            names.Add("Mourning Grasps of Guardians");
            names.Add("Bloodsurge Fists of Lost Hope");
            names.Add("Soldier's Handguards of Demons");
            names.Add("Grips of Infernal Justice");
            names.Add("Gauntlets of Holy Hells");
            names.Add("Scaled Handguards of Burning Dreams");
            names.Add("Chainmail Grasps of Silent Souls");
            names.Add("Hero Mail Hands");
            names.Add("Nightmare Chain Grips");
            names.Add("Massive Obsidian Handguards");
            names.Add("Defender's Hands of the Night");
            names.Add("Fiery Grasps of Eternal Rest");
            names.Add("Doom Gauntlets of Holy Might");
            names.Add("Gauntlets of Endless Ancestors");
            names.Add("Grasps of Hallowed Vengeance");
            names.Add("Scaled Fists of Relentless Misery");
            names.Add("Adamantite Hands of Doomed Freedom");
            names.Add("Howling Iron Warfists");
            names.Add("Champion Scaled Hands");
            names.Add("Primal Steel Hands");
            names.Add("Doom's Hands of the Warrior");
            names.Add("Gladiator's Hands of Grieving Widows");
            names.Add("Wrathful Gauntlets of the Wicked");
            names.Add("Gauntlets of Conquered Memories");
            names.Add("Grips of Haunted Honor");
            names.Add("Demon Warfists of Lost Might");
            names.Add("Ivory Gauntlets of Twisted Nightmares");
            names.Add("Retribution Iron Grasps");
            names.Add("Ominous Chain Handguards");
            names.Add("Heartless Scaled Fists");
            names.Add("Battleworn Fists of the Immortal");
            names.Add("Wicked Grasps of the Wicked");
            names.Add("Grips of the Insane");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateChestName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Chestpiece of Relentless Wars");
            names.Add("Tunic of Ending Fortunes");
            names.Add("Obsidian Cuirass of Cursed Torment");
            names.Add("Ivory Chestpiece of Ending Lands");
            names.Add("Vengeful Scaled Chestpiece");
            names.Add("Thundersoul Chainmail Chestguard");
            names.Add("Loyal Vest of Twilight");
            names.Add("Faith's Chestguard of the Phoenix");
            names.Add("Blessing of Broken Worlds");
            names.Add("Death of Mists");
            names.Add("Armor of Lost Illusions");
            names.Add("Armor of Conquered Lands");
            names.Add("Skeletal Chestguard of Smoldering Glory");
            names.Add("Mithril Armor of Blind Illusions");
            names.Add("Crazed Bone Vest");
            names.Add("Vicious Bone Chestpiece");
            names.Add("Silent Tunic of Broken Bones");
            names.Add("Thundersoul Chestguard of Power");
            names.Add("Blight of Ice Magic");
            names.Add("Burden of the Brotherhood");
            names.Add("Batteplate of Doomed Powers");
            names.Add("Chestguard of Fleeting Fortunes");
            names.Add("Mithril Tunic of Conquered Memories");
            names.Add("Ivory Chestplate of Infinite Trials");
            names.Add("Reforged Silver Chestpiece");
            names.Add("Thunder Titanium Armor");
            names.Add("Peacekeeper's Chestpiece of Suffering");
            names.Add("Cataclysm Armor of Secrets");
            names.Add("Reach of the Void");
            names.Add("Fortune of the Eagle");
            names.Add("Chestpiece of Shattered Nightmares");
            names.Add("Vest of Fleeting Hells");
            names.Add("Bronze Chestpiece of Demonic Hope");
            names.Add("Chainmail Tunic of Relentless Whispers");
            names.Add("Ominous Silver Chestplate");
            names.Add("Captain's Obsidian Breastplate");
            names.Add("Gladiator Greatplate of Secrecy");
            names.Add("Defender's Chestplate of Blight");
            names.Add("Pact of the End");
            names.Add("Vindicator of Fortune");
            names.Add("Vest of Dark Lands");
            names.Add("Batteplate of Immortal Lands");
            names.Add("Bronze Cuirass of Fleeting Sorrow");
            names.Add("Chain Greatplate of Imminent Freedom");
            names.Add("Cataclysmic Silver Chestguard");
            names.Add("Recruit's Titanium Batteplate");
            names.Add("Trainee's Vest of Hell's Games");
            names.Add("Hopeless Vest of the Basilisk");
            names.Add("Promise of the Setting Sun");
            names.Add("Wit of the Mountains");
            names.Add("Breastplate of Faded Ancestors");
            names.Add("Cuirass of Burning Glory");
            names.Add("Demon Armor of Endless Dreams");
            names.Add("Demon Breastplate of Binding Magic");
            names.Add("Grieving Demon Tunic");
            names.Add("Defiled Bronze Armor");
            names.Add("Exile Armor of Lifemending");
            names.Add("Feral Chestplate of the Earth");
            names.Add("Guard of Valiance");
            names.Add("Call of the Harvest");
            names.Add("Vest of Ominous Powers");
            names.Add("Vest of Faded Wars");
            names.Add("Chain Chestguard of Sacred Hells");
            names.Add("Ivory Chestplate of Broken Sorrow");
            names.Add("Ebon Greatplate");
            names.Add("Savage Demon Cuirass");
            names.Add("Honor's Armor of Echoes");
            names.Add("Defender's Chestplate of Dark Souls");
            names.Add("Pledge of Blast Protection");
            names.Add("Bond of Infinity");
            names.Add("Armor of Silent Whispers");
            names.Add("Vest of Condemned Fires");
            names.Add("Adamantite Tunic of Unholy Warlords");
            names.Add("Chain Vest of Unholy Hope");
            names.Add("Vindictive Bone Chestpiece");
            names.Add("Barbaric Skeletal Batteplate");
            names.Add("Treachery's Greatplate of Fire Magic");
            names.Add("Tormented Greatplate of Phantoms");
            names.Add("Vest of the Ancients");
            names.Add("Hero of the Prophet");
            names.Add("Vest of Timeless Powers");
            names.Add("Chestguard of Eternal Warlords");
            names.Add("Bone Breastplate of Sacred Damnation");
            names.Add("Chain Cuirass of Ending Wars");
            names.Add("Doom Demon Tunic");
            names.Add("Guard's Skeletal Chestplate");
            names.Add("Extinction Chestguard of Lost Souls");
            names.Add("Engraved Chestplate of Power");
            names.Add("Birth of Doom");
            names.Add("Defender of the Falling Sky");
            names.Add("Batteplate of Dark Kings");
            names.Add("Cuirass of Divine Bloodlust");
            names.Add("Titanium Vest of Divine Bloodlust");
            names.Add("Golden Cuirass of Conquered Hell");
            names.Add("Cataclysmic Chain Chestpiece");
            names.Add("Restored Adamantite Chestguard");
            names.Add("Lonely Vest of Despair");
            names.Add("Armor of Domination");
            names.Add("Breastplate of Blight");
            names.Add("Guardian of Defiance");

            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateShieldName(ILoot item)
        {
            List<string> names = new List<string>();
            names.Add("Vacuum");
            names.Add("Nightfall");
            names.Add("Death's Touch");
            names.Add("Fragile Kite Shield");
            names.Add("Burnished Barricade");
            names.Add("Tyrannical Willow Heavy Shield");
            names.Add("Brutal Bone Bulwark");
            names.Add("Hero's Calling, Cunning of Putrefaction");
            names.Add("Apocalypse, Shield of the Sun");
            names.Add("Perfect Storm, Heirloom of the Prince");
            names.Add("Rumpel Steelskin");
            names.Add("Dawn");
            names.Add("The Boon");
            names.Add("Soulless Blockade");
            names.Add("Lightning Keeper");
            names.Add("Mourning Redwood Kite Shield");
            names.Add("Destiny's Willow Carapace");
            names.Add("The Brute, Kite Shield of the Void");
            names.Add("The Sentry, Shepherd of the Beast");
            names.Add("Volcano, Bane of Corruption");
            names.Add("Face of Death");
            names.Add("Lightbringer");
            names.Add("Witherbrand");
            names.Add("Lusting Greatshield");
            names.Add("Primitive Keeper");
            names.Add("Engraved Steel Aegis");
            names.Add("Hungering Ironbark Shield Wall");
            names.Add("Sierra, Whisper of the Protector");
            names.Add("Valkyrie, Hero of the Caged Mind");
            names.Add("Nethersbane, Bringer of Giants");
            names.Add("Dawnguard");
            names.Add("Honor's Call");
            names.Add("Dragonheart");
            names.Add("Polished Guard");
            names.Add("Warp Bulwark");
            names.Add("Destiny's Hardwood Blockade");
            names.Add("Mercenary Titanium Bastion");
            names.Add("Ebony, Glory of Eternity");
            names.Add("Rage, Favor of Riddles");
            names.Add("Hero's Surrender, Gift of the Falling Sky");
            names.Add("Cometfall");
            names.Add("Aegeus");
            names.Add("Enigma");
            names.Add("Frost Buckler");
            names.Add("Improved Blockade");
            names.Add("Furious Bronzed Kite Shield");
            names.Add("Champion's Warpwood Blockade");
            names.Add("Wit's End, Hope of Shadow Strikes");
            names.Add("Knightfall, Bulwark of Fools");
            names.Add("Deathgate, Last Hope of Eternal Sorrow");
            names.Add("Torrent");
            names.Add("The Iron Maiden");
            names.Add("Ivory");
            names.Add("Remorseful Aegis");
            names.Add("Windsong Kite Shield");
            names.Add("Frozen Copper Visage");
            names.Add("Hero Ivory Buffer");
            names.Add("Apocalypse, Memory of the Corrupted");
            names.Add("Skullcrusher, Destroyer of Timeless Battles");
            names.Add("Triumph, Cry of Nightmares");
            names.Add("Honor's Pride");
            names.Add("Remorse");
            names.Add("Ivory");
            names.Add("Ghost-Forged Armament");
            names.Add("Improved Buckler");
            names.Add("Yearning Silver Light Shield");
            names.Add("Warrior Mithril Barricade");
            names.Add("Skullcrusher, Token of the Damned");
            names.Add("Starlight, Tribute of the Insane");
            names.Add("Enforcer, Light Shield of Torment");
            names.Add("King's Defender");
            names.Add("Epilogue");
            names.Add("Cataclysm");
            names.Add("Peacekeeper Carapace");
            names.Add("Frail Tower Shield");
            names.Add("Forsaken Ebon Barricade");
            names.Add("Liar's Titanium Keeper");
            names.Add("Willbreaker, Protection of Regret");
            names.Add("Warmonger, Breaker of Faded Memories");
            names.Add("Coliseum, Defender of Hatred");
            names.Add("Shepherd");
            names.Add("Shroud");
            names.Add("Vacuum");
            names.Add("Yearning Blockade");
            names.Add("Ritual Warden");
            names.Add("Defiled Obsidian Aegis");
            names.Add("Lightning Adamantite Carapace");
            names.Add("Valkyrie, Bastion of the Blessed");
            names.Add("Extinction, Bastion of the Falling Sky");
            names.Add("Justice, Kite Shield of Dark Souls");
            names.Add("Get shield names");
            names.Add("Silverlight");
            names.Add("Reign Maker");
            names.Add("Despair");
            names.Add("Fusion Barricade");
            names.Add("Bloodcursed Bastion");
            names.Add("Soul Redwood Guardian");
            names.Add("Soul-Forged Glass Bulwark");
            names.Add("Despair, Heirloom of the Emperor");
            names.Add("Requiem, Savagery of Twilight's End");
            int indexName = AUX_Utility.IntRandomRange(0, names.Count - 1);
            item.SetName(names[indexName]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreatePrimaryStatType(EnumLootStat statType, int itemLevel, ILoot item)
        {
            switch (statType)
            {
                case EnumLootStat.STAT_VITALITY:
                    CreateRandomVitality(itemLevel, item);
                    break;
                case EnumLootStat.STAT_STRENGTH:
                    CreateRandomStrength(itemLevel, item);
                    break;
                case EnumLootStat.STAT_ARMOUR:
                    CreateRandomArmour(itemLevel, item);
                    break;
                case EnumLootStat.STAT_CRITICAL_CHANCE:
                    CreateRandomCriticalChance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_CRITICAL_DAMAGE:
                    CreateRandomCriticalDamage(itemLevel, item);
                    break;
                case EnumLootStat.STAT_ATTACK_SPEED:
                    CreateRandomAttackSpeed(itemLevel, item);
                    break;
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateSecondaryStatType(EnumLootStat statType, int itemLevel, ILoot item)
        {
            switch (statType)
            {
                case EnumLootStat.STAT_ALL_RESISTANCE:
                    CreateRandomAllResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_FIRE_RESISTANCE:
                    CreateRandomFireResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_COLD_RESISTANCE:
                    CreateRandomColdResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_ARCANE_RESISTANCE:
                    CreateRandomArcaneResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_ELETRIC_RESISTANCE:
                    CreateRandomEletricResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_POISON_RESISTANCE:
                    CreateRandomPoisonResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_PHYSICAL_RESISTANCE:
                    CreateRandomPhysicalResistance(itemLevel, item);
                    break;
                case EnumLootStat.STAT_MANA:
                    CreateRandomMana(itemLevel, item);
                    break;
                case EnumLootStat.STAT_LIFE_PER_SECOND:
                    CreateRandomLifePerSecond(itemLevel, item);
                    break;
                case EnumLootStat.STAT_LIFE_PERCENT:
                    CreateRandomLifePercent(itemLevel, item);
                    break;
                case EnumLootStat.STAT_MANA_PER_SECOND:
                    CreateRandomManaPerSecond(itemLevel, item);
                    break;
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateBonusStatType(EnumLootStat statType, int itemLevel, ILoot item)
        {
            switch (statType)
            {
                case EnumLootStat.STAT_MOVEMENT_SPEED:
                    CreateRandomMovementSpeed(itemLevel, item);
                    break;
                case EnumLootStat.STAT_MONSTER_GRANT_EXPERIENCE:
                    CreateRandomMonsterGrantExperience(itemLevel, item);
                    break;
                case EnumLootStat.STAT_REDUCE_COOLDOWN_ALL_SKILLS:
                    CreateRandomReduceCooldownAllSkills(itemLevel, item);
                    break;
                case EnumLootStat.STAT_MAGIC_FIND:
                    CreateRandomMagicFind(itemLevel, item);
                    break;
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomMana(int itemLevel, ILoot item)
        {
            float mana = AUX_Utility.FloatRoundRandomRange(10.0f, 30.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_MANA, mana);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomVitality(int itemLevel, ILoot item)
        {
            float vitality = AUX_Utility.FloatRoundRandomRange(200.0f, 500.0f);
            CreateRandomPrimaryStat(item, EnumLootStat.STAT_VITALITY, vitality);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomStrength(int itemLevel, ILoot item)
        {
            float strength = AUX_Utility.FloatRoundRandomRange(200.0f, 500.0f);
            CreateRandomPrimaryStat(item, EnumLootStat.STAT_STRENGTH, strength);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomArmour(int itemLevel, ILoot item)
        {
            float armour = AUX_Utility.FloatRoundRandomRange(200.0f, 800.0f);
            CreateRandomPrimaryStat(item, EnumLootStat.STAT_ARMOUR, armour);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomCriticalChance(int itemLevel, ILoot item)
        {
            float criticalChance = AUX_Utility.FloatRoundRandomRange(1.0f, 5.0f);
            CreateRandomPrimaryStat(item, EnumLootStat.STAT_CRITICAL_CHANCE, criticalChance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomCriticalDamage(int itemLevel, ILoot item)
        {
            float criticalDamage = AUX_Utility.FloatRoundRandomRange(1.0f, 50.0f);
            CreateRandomPrimaryStat(item, EnumLootStat.STAT_CRITICAL_DAMAGE, criticalDamage);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomAttackSpeed(int itemLevel, ILoot item)
        {
            float attackSpeed = AUX_Utility.FloatRoundRandomRange(1.0f, 10.0f);
            CreateRandomPrimaryStat(item, EnumLootStat.STAT_ATTACK_SPEED, attackSpeed);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomMovementSpeed(int itemLevel, ILoot item)
        {
            float movementSpeed = AUX_Utility.FloatRoundRandomRange(4.0f, 12.0f);
            CreateRandomBonusStat(item, EnumLootStat.STAT_MOVEMENT_SPEED, movementSpeed);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomAllResistance(int itemLevel, ILoot item)
        {
            float allResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_ALL_RESISTANCE, allResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomFireResistance(int itemLevel, ILoot item)
        {
            float fireResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_FIRE_RESISTANCE, fireResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomColdResistance(int itemLevel, ILoot item)
        {
            float coldResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_COLD_RESISTANCE, coldResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomArcaneResistance(int itemLevel, ILoot item)
        {
            float arcaneResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_COLD_RESISTANCE, arcaneResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomEletricResistance(int itemLevel, ILoot item)
        {
            float eletricResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_ELETRIC_RESISTANCE, eletricResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomPoisonResistance(int itemLevel, ILoot item)
        {
            float poisonResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_POISON_RESISTANCE, poisonResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomPhysicalResistance(int itemLevel, ILoot item)
        {
            float physicalResistance = AUX_Utility.FloatRoundRandomRange(20.0f, 200.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_PHYSICAL_RESISTANCE, physicalResistance);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomLifePerSecond(int itemLevel, ILoot item)
        {
            float lifePerSecond = AUX_Utility.FloatRoundRandomRange(1000.0f, 10000.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_LIFE_PER_SECOND, lifePerSecond);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomLifePercent(int itemLevel, ILoot item)
        {
            float lifePercent = AUX_Utility.FloatRoundRandomRange(5.0f, 15.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_LIFE_PERCENT, lifePercent);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomManaPerSecond(int itemLevel, ILoot item)
        {
            float manaPerSecond = AUX_Utility.FloatRoundRandomRange(2.0f, 10.0f);
            CreateRandomSecondaryStat(item, EnumLootStat.STAT_MANA_PER_SECOND, manaPerSecond);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomMonsterGrantExperience(int itemLevel, ILoot item)
        {
            float monsterGrantExperience = AUX_Utility.FloatRoundRandomRange(100.0f, 2000.0f);
            CreateRandomBonusStat(item, EnumLootStat.STAT_MONSTER_GRANT_EXPERIENCE, monsterGrantExperience);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomReduceCooldownAllSkills(int itemLevel, ILoot item)
        {
            float reduceCooldown = AUX_Utility.FloatRoundRandomRange(4.0f, 10.0f);
            CreateRandomBonusStat(item, EnumLootStat.STAT_REDUCE_COOLDOWN_ALL_SKILLS, reduceCooldown);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomMagicFind(int itemLevel, ILoot item)
        {
            float magicFind = AUX_Utility.FloatRoundRandomRange(5.0f, 50.0f);
            CreateRandomBonusStat(item, EnumLootStat.STAT_MAGIC_FIND, magicFind);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomPrimaryStat(ILoot item, EnumLootStat statType, float statValue)
        {
            item.AddPrimaryStat(statType, statValue);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomSecondaryStat(ILoot item, EnumLootStat statType, float statValue)
        {
            item.AddSecondaryStat(statType, statValue);
        }

        //------------------------------------------------------------------------------------------------------------------
        private static void CreateRandomBonusStat(ILoot item, EnumLootStat statType, float statValue)
        {
            item.AddBonusStat(statType, statValue);
        }
    }
#endif  //ITEM_FACTORY
    #endregion
}
