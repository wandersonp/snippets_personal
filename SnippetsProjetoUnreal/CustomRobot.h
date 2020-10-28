//==================================================================================================================
//
//	File:	CustomRobot.cpp
//	Date:	15-11-2016
//	Author:	wandersonp@gmail.com
//
//	Description:    
//
//==================================================================================================================

#pragma once

#include "GameFramework/Character.h"
#include "DynamicMeshBuilder.h"
#include "Components/ChildActorComponent.h"
#include "Runtime/GeometryCache/Classes/GeometryCacheComponent.h"
#include "Components/WidgetComponent.h"
#include "Loot/LootFactory.h"
#include "Weapon/PEM.h"
#include "CustomRobot.generated.h"

//------------------------------------------------------------------------------------------------------------------
class ABulletProjectile;
class AMissile;
class UCameraShake;
class AKeyboardHint;
class UHeroDynamicSkills;

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ESkillType : uint8
{
	ST_Primary			UMETA(DisplayName = "Primary"),
	ST_Secondary		UMETA(DisplayName = "Secondary"),
	ST_Shield			UMETA(DisplayName = "Shield"),
	ST_FullBatery		UMETA(DisplayName = "Full Battery"),
	ST_ArmyOfHeroes		UMETA(DisplayName = "Army of Heroes"),
	ST_PEM				UMETA(DisplayName = "PEM"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EShieldSkillType : uint8
{
	SST_TypeA			UMETA(DisplayName = "Type A"),
	SST_TypeB			UMETA(DisplayName = "Type B"),
	SST_TypeC			UMETA(DisplayName = "Type C"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EFullBatterySkillType : uint8
{
	FBST_TypeA			UMETA(DisplayName = "Type A"),
	FBST_TypeB			UMETA(DisplayName = "Type B"),
	FBST_TypeC			UMETA(DisplayName = "Type C"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EArmyOfHeroesSkillType : uint8
{
	AHST_TypeA			UMETA(DisplayName = "Type A"),
	AHST_TypeB			UMETA(DisplayName = "Type B"),
	AHST_TypeC			UMETA(DisplayName = "Type C"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EPrimarySkillType : uint8
{
	PST_TypeA			UMETA(DisplayName = "Type A"),
	PST_TypeB			UMETA(DisplayName = "Type B"),
	PST_TypeC			UMETA(DisplayName = "Type C"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ESecondarySkillType : uint8
{
	SST_TypeA			UMETA(DisplayName = "Type A"),
	SST_TypeB			UMETA(DisplayName = "Type B"),
	SST_TypeC			UMETA(DisplayName = "Type C"),
};

//------------------------------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct FHeroStat
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_baseDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_finalDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_attackSpeedWeapon;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_weaponColor;

	//------------------------------------------------------------------------------------------------------------------
	//	Primary
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_attackSpeedBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_criticalStrikeChance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_criticalStrikeDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_energyPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_dynamicForcePoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_energyPercent;

	//------------------------------------------------------------------------------------------------------------------
	//	Secondary
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_movementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_energySteal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_energyPerhit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_energyPerKill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_energyPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_damageReduction;

	//------------------------------------------------------------------------------------------------------------------
	//	Bonus
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_bitbots;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_experiencePerKill;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_technologyFind;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_cooldownReductionSkill_A;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_cooldownReductionSkill_B;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_cooldownReductionSkill_C;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_cooldownReductionSkill_D;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Stat")
	FSafeInt m_cooldownReductionAllSkills;

	FHeroStat()
	{
		m_baseDamage = FSafeInt(0);
		m_finalDamage = FSafeInt(0);
		m_attackSpeedWeapon = FSafeInt(0);
		m_weaponColor = FSafeInt(0);

		m_attackSpeedBonus = FSafeInt(0);
		m_criticalStrikeChance = FSafeInt(0);
		m_criticalStrikeDamage = FSafeInt(0);
		m_energyPoints = FSafeInt(0);
		m_energyPercent = FSafeInt(0);
		m_dynamicForcePoints = FSafeInt(0);

		m_movementSpeed = FSafeInt(0);
		m_energySteal = FSafeInt(0);
		m_energyPerhit = FSafeInt(0);
		m_energyPerKill = FSafeInt(0);
		m_energyPerSecond = FSafeInt(0);
		m_damageReduction = FSafeInt(0);

		m_bitbots = FSafeInt(0);
		m_experiencePerKill = FSafeInt(0);
		m_technologyFind = FSafeInt(0);
		m_cooldownReductionSkill_A = FSafeInt(0);
		m_cooldownReductionSkill_B = FSafeInt(0);
		m_cooldownReductionSkill_C = FSafeInt(0);
		m_cooldownReductionSkill_D = FSafeInt(0);
		m_cooldownReductionAllSkills = FSafeInt(0);
	}
};

//------------------------------------------------------------------------------------------------------------------
UCLASS()
class CUSTOMGAME_API ACustomRobot : public ACharacter
{
	GENERATED_BODY()

public:
	ACustomRobot(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
	void ActorBeginOverlap(class AActor* thisActor, class AActor* otherActor);

	UFUNCTION(BlueprintCallable, Category = "Hero Functions")
	void OnRightShootPressed();

	UFUNCTION(BlueprintCallable, Category = "Hero Functions")
	void PrimarySkillBlast(float intensity, bool normalBlast);

	void TakeLaserDamagePerTimeStep(int damage, float timeStep);

	//------------------------------------------------------------------------------------------------------------------
	//	Skills
	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void ChangeSkillType(ESkillType skillType, uint8 index);

	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	bool ISSkillUnlocked(ESkillType skillType, uint8 index);

	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	void EnableShielding();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	void FullBattery();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	void PEM();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	void ArmyOfHeroes();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	void PrimarySkill();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	bool SecondarySkill();

	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	bool TimeWarpSkill();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	bool IncreaseDamageSkill();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	bool IncreaseEnergySkill();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Skills")
	bool IncreaseMovementSpeedSkill();

	void GetHitResult(FVector &hitLocation) const;
	void GetLookAtVector(FRotator &lookAtVector) const;

	UFUNCTION(BlueprintCallable, Category = "Hero Functions")
	void SpawnLevelUpFX() const;
	void TickForUnlockedSkills();	

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementShieldLevelStackAmount();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementFullBatteryLevelStackAmount();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementArmyOfHeroesLevelStackAmount();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementForceFieldLevelStackAmount();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementTimeWarpLevelStackAmount();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementIncreaseDamageLevelStackAmount();
	
	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementIncreaseEnergyStackAmount();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void IncrementIncreaseMovementSpeedStackAmount();

	void DecrementShieldLevelStackAmount();
	void DecrementFullBatteryLevelStackAmount();
	void DecrementArmyOfHeroesLevelStackAmount();
	void DecrementForceFieldLevelStackAmount();
	void DecrementTimeWarpLevelStackAmount();
	void DecrementIncreaseDamageLevelStackAmount();
	void DecrementIncreaseEnergyLevelStackAmount();
	void DecrementIncreaseMovementSpeedLevelStackAmount();

	//------------------------------------------------------------------------------------------------------------------
	//	Get Acumulated Stats
	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetDamage();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	float GetAttackSpeed();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetAttackSpeedWeapon();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetAttackSpeedBonus();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetCriticalStrikeChance();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetCriticalStrikeDamage();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetEnergyPoints();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetEnergyPercent();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetDynamicForcePoints();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetMaxEnergy();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetMovementSpeed();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetEnergySteal();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetEnergyPerHit();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetEnergyPerKill();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetEnergyPerSecond();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetDamageReduction();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetBitBots();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetRobotsKillGrantXP();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetTechnologyFind();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetCooldownReductionSkill_A();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetCooldownReductionSkill_B();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetCooldownReductionSkill_C();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	int32 GetCooldownReductionSkill_D();

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateLeftWeaponStats(FLootInfo loot);

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateRightWeaponStats(FLootInfo loot);

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateMicrochipStats(FLootInfo loot);

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateJetpackStats(FLootInfo loot);

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateCellEnergyStats(FLootInfo loot);

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateHeroStats();

	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void UpdateLootStats(TArray<FLootInfo> loots);

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	float GetNewDamagePercentIfEquipped(int32 lootIndex, FLootInfo loot);

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	float GetNewEnergyIfEquipped(int32 lootIndex, FLootInfo loot);

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	float GetNewResistanceIfEquipped(int32 lootIndex, FLootInfo loot);
	
	//------------------------------------------------------------------------------------------------------------------
	//	Allies
	void AddAlly(class AEnemyRobot *robot);
	void RefreshAllies();
	class AEnemyRobot* GetNearAlly(FVector fromLocation);
	class AEnemyRobot* GetLessHealthAlly(FVector fromLocation) const;
	void KillAllies();

	UFUNCTION()
	void RefreshAllyTargets();
	
	bool ExistTargetToAllyShoot();
	AActor* GetRandomTargetToAlly(AActor* oldTarget);

	//------------------------------------------------------------------------------------------------------------------
	//	Loot
	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	bool HaveSomeWeaponEquiped();

	//------------------------------------------------------------------------------------------------------------------
	//	Damage
	void ApplyDamage(int32 damage);
	void ApplyDamage(ABulletProjectile *projectile);
	void ApplyDamage(AMissile *missile);
	void Kill();
	void ShowDeadScreenUMG();
	void Explode();
	
	UFUNCTION(BlueprintCallable, Category = "Hero Stats")
	void Respawn();

	UFUNCTION(BlueprintPure, Category = "Hero Stats")
	float GetTorsoLookAtRotation();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void DoCameraShake(float scale);

	void IncreaseDamageFromRareKill(float percent, float secondsActive);
	void DisableIncreaseDamageFromRareKill();

	//------------------------------------------------------------------------------------------------------------------
	//	Skills
	UFUNCTION(BlueprintPure, Category = "Skills")
	float GetShieldNormalizedActiveTimer();

	UFUNCTION(BlueprintPure, Category = "Skills")
	float GetArmyOfHeroesNormalizedActiveTimer();

	UFUNCTION(BlueprintPure, Category = "Skills")
	float GetTimeWarpNormalizedActiveTimer();

	UFUNCTION(BlueprintPure, Category = "Skills")
	float GetIncreaseDamageNormalizedActiveTimer();

	UFUNCTION(BlueprintPure, Category = "Skills")
	float GetIncreaseEnergyNormalizedActiveTimer();

	UFUNCTION(BlueprintPure, Category = "Skills")
	float GetIncreaseMovementSpeedNormalizedActiveTimer();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseProtectionSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseRegenerationSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseSupportSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseAreaCombatSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UsePrimarySkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseSecondarySkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseTimeControlSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseDamageControlSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseEnergyControlSkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void UseMobilitySkill();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapProtectionSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapRegenerationSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapSupportSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapAreaCombatSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapPrimarySkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapSecondarySkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapTimeControlSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapDamageControlSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapEnergyControlSkill(int32 skillIndex);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void SwapMobilitySkill(int32 skillIndex);

protected:
	void InitializeVars();
	void InitializeOnlineVars();
	void InitializeCustomComponents();
	void InitializeTimers();
	void InitializeEquipment();
	void InitializeMaterials();
	void InitializeSkills();
	void InitializeGameplayOptions();
	void InitializeCheatCodes();

	void TickRobot();
	void TickMaterialDamage();
	void TickMousePosition();

	UFUNCTION()
	void TakeLaserDamage(int damage);
	
	void ProcessWalk();
	void ProcessShoot();

	void EnergyRegeneration();
	void MoveForward(float value);
	void MoveRight(float value);
	void TargetForward(float value);
	void TargetRight(float value);
	void TurnAtRate(float rate);
	void LockTarget(AActor *enemy);
	void TargetLock();
	void TargetFree();
	void FireLeftWeapon();
	void FireRightWeapon();
	void FireWeapon(UChildActorComponent *socket);
	void SetShield(bool enabled);
	void DisableShielding();
	void SpawnKeyboardHint(UWorld *world);

	//------------------------------------------------------------------------------------------------------------------
	//	PowerUps
	void TickPowerUps();
	void TickShieldPowerUp();
	void TickArmyOfHeroesPowerUp();
	void TickTimeWarpPowerUp();
	void TickIncreaseDamagePowerUp();
	void TickIncreaseMovementSpeedPowerUp();
	void TickIncreaseEnergyPowerUp();

	void SetShieldPowerUp(bool enabled);
	void SetArmyOfHeroesPowerUp(bool enabled);
	void SetTimeWarpPowerUp(bool enabled);
	void SetIncreaseDamagePowerUp(bool enabled);
	void SetIncreaseMovementSpeedPowerUp(bool enabled);
	void SetIncreaseEnergyPowerUp(bool enabled);

	void EnableShieldPowerUp(float timer);
	void EnableArmyOfHeroesPowerUp(float timer);
	void EnableTimeWarpPowerUp(float timer);
	void EnableIncreaseDamagePowerUp(float timer);
	void EnableIncreaseEnergyPowerUp(float timer);
	void EnableIncreaseMovementSpeedPowerUp(float timer);

	void AcumulateShieldPowerUp(float appendTimer);
	void AcumulateTimeWarpPowerUp(float appendTimer);
	void AcumulateIncreaseDamagePowerUp(float appendTimer);
	void AcumulateIncreaseMovementSpeedPowerUp(float appendTimer);

	void DisableShieldPowerUp();
	void DisableArmyOfHeroesPowerUp();
	void DisableTimeWarpPowerUp();
	void DisableIncreaseDamagePowerUp();
	void DisableIncreaseEnergyPowerUp();
	void DisableIncreaseMovementSpeedPowerUp();

	//------------------------------------------------------------------------------------------------------------------
	//	Skill
	void EnableWalk();

	void ChangePrimarySkillType(EPrimarySkillType type);
	void ChangeSecondarySkillType(ESecondarySkillType type);
	void ChangeShieldSkillType(EShieldSkillType type);
	void ChangeFullBatterySkillType(EFullBatterySkillType type);
	void ChangeArmyOfHeroesSkillType(EArmyOfHeroesSkillType type);
	void ChangePEMSkillType(EPEMSkillType type);
	void ShootNormalBlast();
	void ShootHyperBlast(float intensity);

	void ShieldSkill();
	
	void FullBattery_Only();
	void FullBattery_IncreaseMovementSpeed();
	void FullBattery_IncreaseDamage();
	void FullBattery_DamageReduction();
	
	void ArmyOfHeroesSkill();

	UFUNCTION()
	void SpawnFirstAllyArmyOfHeroes(FVector projectedPosition);
	
	UFUNCTION()
	void SpawnSecondAllyArmyOfHeroes(FVector projectedPosition);
	
	UFUNCTION()
	void SpawnThirdAllyArmyOfHeroes(FVector projectedPosition);
	
	UFUNCTION()
	void SpawnFourthAllyArmyOfHeroes(FVector projectedPosition);
	
	void PrimarySkill_A();
	void PrimarySkill_B();
	void PrimarySkill_C();
	
	bool SecondarySkill_A();
	bool SecondarySkill_B();
	bool SecondarySkill_C();
	bool TeleportPlayerWithTrail(FColor skillColor, FVector &teleportPosition);

	void SpawnTeleportFieldFX(FVector position, float delayActivate, float life, float radius, int32 damage);

	UFUNCTION()
	void TeleportActor(FVector position);

	UFUNCTION()
	void DamageReductionByFullBattery(float value);
	
	UFUNCTION()
	void IncreaseMovementSpeedByFullBattery(float value);
	
	UFUNCTION()
	void IncreaseDamageByFullBattery(float value);

	//------------------------------------------------------------------------------------------------------------------
	//	Loot
	void UpdateMovementSpeedFromLoot();
	void UpdateEnergyFromLoot();

	//------------------------------------------------------------------------------------------------------------------
	//	Sound
	void PlayPowerUpPickupSoundFX();

	//------------------------------------------------------------------------------------------------------------------
	//	FX
	void SpawnPowerUpPickupFX();

	//------------------------------------------------------------------------------------------------------------------
	//	Widget
	void PlayTimeWarpPowerUpWidget();
	void PlayIncreaseDamagePowerUpWidget();
	void PlayIncreaseEnergyPowerUpWidget();
	void PlayIncreaseMovementSpeedPowerUpWidget();
	void PlayEnergyRegenerationPowerUpWidget();

public:
	//------------------------------------------------------------------------------------------------------------------
	//	Default
	FSafeBool m_godMode;
	float m_deltaTime;
	FString m_heroName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool m_heroIsDead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool m_enableDeath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool m_enableDebugSuperSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero")
	bool m_enableInteraction;

	//------------------------------------------------------------------------------------------------------------------
	//	Ally
	UPROPERTY()
	TArray<class AEnemyRobot*> m_robotAllyes;
	
	UPROPERTY()
	TArray<class ARobotAlly*> m_armyOfHeroesAllyes;

	//------------------------------------------------------------------------------------------------------------------
	//	Loot
	UPROPERTY()
	TArray<FLootInfo> m_equipment;
	
	FHeroStat m_heroStat;

	//------------------------------------------------------------------------------------------------------------------
	//	Cursor
	FVector m_aimCursorWorldPosition;
	FVector m_aimCursorLastWorldPosition;
	FVector2D m_aimCursorScreenPosition;
	FVector2D m_aimCursorLastScreenPositionClicked;
	FVector2D m_aimCursorThumbStickValue;
	float m_aimCursorSpeed;
	bool m_aimCursorLocked;

	//------------------------------------------------------------------------------------------------------------------
	//	Damage
	bool m_isIncreaseDamageFromRareKill;
	int32 m_baseMaxEnergy;
	int32 m_baseDamage;
	int32 m_finalDamage;

	UPROPERTY()
	class UUserWidget* m_deadScreenUMG;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> m_deadScreenWidget;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Hero Config")
	TSubclassOf<AActor> m_explosionBP;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	UPhysicsAsset *m_physicsAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Config")
	int m_currentEnergy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero Config")
	int m_maxEnergy;
	
	//------------------------------------------------------------------------------------------------------------------
	//	FX
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AActor> m_missionCompleteBP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AActor> m_missionFailedBP;

	float m_fractionTimeSeconds;
	float m_baseTurnRate;
	bool m_enableWalk;
	FHitResult m_hitProjection;
	FRotator m_lastFrameRotator;
	FRotator m_currentRotator;
	FRotator m_targetRotator;

	float m_height;
	float m_xMovement;
	float m_yMovement;
		
	UPROPERTY()
	TArray<class AActor*> m_surroundHiddenTargets;
	
	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_bulletProjectileNormal;
	
	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_bulletProjectileHyper;
		
	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_particlePEM_BP;
	
	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_laserBlast_BP;
	
	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_levelUP_BP;

	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_dummyActor;

	UPROPERTY(EditAnywhere, Category = "FX")
	TSubclassOf<AActor> m_powerUpPickupFX;

	//------------------------------------------------------------------------------------------------------------------
	//	Ally
	UPROPERTY(EditAnywhere, Category = "Ally")
	TSubclassOf<AFXDelayed> m_teleportFieldFX;

	UPROPERTY(EditAnywhere, Category = "Ally")
	TSubclassOf<ARobotAlly> m_robotAlly_Red;

	UPROPERTY(EditAnywhere, Category = "Ally")
	TSubclassOf<ARobotAlly> m_robotAlly_Green;

	UPROPERTY(EditAnywhere, Category = "Ally")
	TSubclassOf<ARobotAlly> m_robotAlly_Blue;

	UPROPERTY(EditAnywhere, Category = "Ally")
	TSubclassOf<ARobotAlly> m_robotAlly_White;

	UPROPERTY(EditAnywhere, Category = "Ally")
	TArray<AActor *> m_allyTargetsToShoot;

	//------------------------------------------------------------------------------------------------------------------
	//	Components
	UPROPERTY()
	UStaticMeshComponent* m_shieldMeshComponent;
		
	UPROPERTY()
	UChildActorComponent* m_leftWeaponSocket;
	
	UPROPERTY()
	UChildActorComponent* m_rightWeaponSocket;

	UPROPERTY()
	UWidgetComponent* m_healthBarWidgetComponent;

	UPROPERTY()
	UParticleSystemComponent* m_fullBatteryParticleSystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UParticleSystem* m_fullBatteryParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UParticleSystem* m_teleportTrailParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	float m_shieldDelay;

	class FDynamicMeshBuilder *m_meshTarget;
		
	bool m_shieldEnabled;
	float m_leftWeaponDelay;
	float m_rightWeaponDelay;

	float m_armyOfHeroesDelay;
	float m_timeWarpDelay;
	float m_increaseDamageDelay;
	float m_increaseEnergyDelay;
	float m_increaseMovementSpeedDelay;

	//------------------------------------------------------------------------------------------------------------------
	//	PowerUps
	bool m_isActiveArmyOfHeroesPowerUp;
	bool m_isActiveIncreaseDamagePowerUp;
	bool m_isActiveIncreaseEnergyPowerUp;
	bool m_isActiveIncreaseMovementSpeedPowerUp;
	bool m_isActiveShieldPowerUp;
	bool m_isActiveTimeWarpPowerUp;
	
	//------------------------------------------------------------------------------------------------------------------
	//	Tutorial
	UPROPERTY(EditAnywhere, Category = "Hero Config")
	TSubclassOf<AKeyboardHint> m_keyboardHintActor;

	//------------------------------------------------------------------------------------------------------------------
	//	Skills
	UPROPERTY()
	UHeroDynamicSkills *m_heroDynamicSkills;

	float m_increaseDamageMaxActiveTime;
	float m_forceFieldMaxActiveTime;
	float m_increaseMovementSpeedMaxActiveTime;
	float m_shieldMaxActiveTime;
	float m_timeWarpMaxActiveTime;
	float m_damageReductionByFullBatterySkill;
	float m_increaseDamageByFullBatterySkill;
	float m_increaseMovementSpeedFullBatterySkill;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_shieldCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_fullBatteryCooldown;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_armyOfHeroesCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_forceFieldCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_plasmaGunCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_teleportCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_timewarpCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_increaseDamageCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_increaseEnergyCooldown;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_increaseMovementSpeedCooldown;

	//	TODO: Check or remove this vars
	EPEMSkillType m_PEMSkillType;
	EShieldSkillType m_shieldSkillType;
	EFullBatterySkillType m_fullBatterySkillType;
	EArmyOfHeroesSkillType m_armyOfHeroesSkillType;
	EPrimarySkillType m_primarySkillType;
	ESecondarySkillType m_secondarySkillType;

	int32 m_maxSkillStackAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_shieldLevelAmount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_fullBatteryLevelAmount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_armyOfHeroesLevelAmount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_forceFieldLevelAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_timeWarpLevelAmount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_increaseDamageLevelAmount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_increaseEnergyLevelAmount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	int32 m_increaseMovementSpeedLevelAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	float m_primarySkillActivationTimer;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Skills")
	float m_primarySkillMaxTimeToNormalBlast = 1.5f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Skills")
	float m_primarySkillMaxTimeToHyperBlast = 4.0f;

	UPROPERTY()
	TArray<bool> m_shieldSkillsUnlocked;

	UPROPERTY()
	TArray<bool> m_fullBatterySkillsUnlocked;

	UPROPERTY()
	TArray<bool> m_armyOfHeroesSkillsUnlocked;

	UPROPERTY()
	TArray<bool> m_pemSkillsUnlocked;

	UPROPERTY()
	TArray<bool> m_primarySkillsUnlocked;

	UPROPERTY()
	TArray<bool> m_secondarySkillsUnlocked;

	//	Permanent
	int32 m_shieldPermanentLevelAmount;
	int32 m_fullPermanentBatteryLevelAmount;
	int32 m_armyOfHeroesPermanentLevelAmount;
	int32 m_forceFieldPermanentLevelAmount;
	int32 m_timeWarpPermanentLevelAmount;
	int32 m_increaseDamagePermanentLevelAmount;
	int32 m_increaseEnergyPermanentLevelAmount;
	int32 m_increaseMovementSpeedPermanentLevelAmount;


	//------------------------------------------------------------------------------------------------------------------
	//	Timers
	FTimerManager *m_timerManager;
	FTimerHandle m_energyRegenTimer;
	FTimerHandle m_shieldPowerUpTimer;
	FTimerHandle m_armyOfHeroesPowerUpTimer;
	FTimerHandle m_timeWarpPowerUpTimer;
	FTimerHandle m_increaseDamagePowerUpTimer;
	FTimerHandle m_increaseEnergyPowerUpTimer;
	FTimerHandle m_increaseMovementSpeedPowerUpTimer;

	FTimerDelegate m_laserDamageDelegate;
	FTimerHandle m_shieldTimer;
	FTimerHandle m_laserDamageTimer;
	FTimerHandle m_alliesRefreshTimer;
	FTimerHandle m_walkDelayTimer;
	FTimerHandle m_fullBatterySkillTimer;
	FTimerHandle m_teleportSkillTimer;
	FTimerHandle m_spawnSecondAllyTimer;
	FTimerHandle m_spawnThirdAllyTimer;
	FTimerHandle m_spawnFourthAllyTimer;
	FTimerHandle m_refreshAllyTargetsTimer;
	FTimerHandle m_increaseDamageFromRareKill;

	float m_shieldActiveTimer;
	float m_armyOfHeroesActiveTimer;
	float m_timeWarpActiveTimer;
	float m_increaseDamageActiveTimer;
	float m_increaseEnergyActiveTimer;
	float m_increaseMovementSpeedActiveTimer;
	
	//------------------------------------------------------------------------------------------------------------------
	//	Camera
	bool m_cameraShakeState;
		
	UPROPERTY()
	TSubclassOf<UCameraShake> m_cameraShake;
	//------------------------------------------------------------------------------------------------------------------
	//	AI
	bool m_isArtificialInteligence;

	//------------------------------------------------------------------------------------------------------------------
	//	Base
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Hero Config")
	bool m_showEnergyBar;

	//------------------------------------------------------------------------------------------------------------------
	//	Material damage
	bool m_firstFrameTakeDamage;
	float m_damageColorIntensity;

	//------------------------------------------------------------------------------------------------------------------
	//	Colors
	FLinearColor m_damageColor;
	FLinearColor m_shieldColor;
	FLinearColor m_primarySkillColor;

	//------------------------------------------------------------------------------------------------------------------
	//	Material
	UPROPERTY()
	UMaterialInstanceDynamic* m_heroMaterialInstanceDynamic;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Materials")
	UMaterialParameterCollection* m_heroMaterialParameterCollection;

	UPROPERTY()
	UGeometryCacheComponent* m_shieldGeometryCacheComponent;

	//------------------------------------------------------------------------------------------------------------------
	//	Sound
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SoundFX")
	USoundCue* m_armyOfHeroesSoundFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SoundFX")
	USoundCue* m_powerUpPickupSoundFX;

	//------------------------------------------------------------------------------------------------------------------
	//	Online vars
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Online")
	int m_currentLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Online")
	float m_baseMovementSpeed;

	int32 m_baseEnergy;
	int m_maxDronesAllyEarned;
	int m_maxRobotsAllyEarned;
	int m_currentXPForThisLevel;
	int m_maxXPForThisLevel;

	friend class UHeroDynamicSkills;
};