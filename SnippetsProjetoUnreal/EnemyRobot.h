//==================================================================================================================
//
//	File:	EnemyRobot.h
//	Date:	15-11-2016
//	Author:	wandersonp@gmail.com
//
//	Description:    
//
//==================================================================================================================

#pragma once

#include "GameFramework/Character.h"
#include "Enemy/Drone.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Gameplay/SquadManager.h"
#include "Runtime/AIModule/Classes/Navigation/CrowdManager.h"
#include "EnemyRobot.generated.h"

//------------------------------------------------------------------------------------------------------------------
class APortal;

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ERobotWeaponType : uint8
{
	RB_Missile				UMETA(DisplayName = "Missile"),
	RB_Weapon_A				UMETA(DisplayName = "Weapon A"),
	RB_Weapon_B				UMETA(DisplayName = "Weapon B"),
	RB_Weapon_C				UMETA(DisplayName = "Weapon C"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EDyplomacyType : uint8
{
	DT_Enemy				UMETA(DisplayName = "Enemy"),
	DT_Ally					UMETA(DisplayName = "Ally"),
};

//------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ERobotBehavior : uint8
{
	RB_Walk													UMETA(DisplayName = "Walk"),
	RB_WalkAndShootWeaponA									UMETA(DisplayName = "Walk and Shoot Weapon A"),
	RB_WalkAndShootWeaponB									UMETA(DisplayName = "Walk and Shoot Weapon B"),
	RB_WalkAndShootWeaponC									UMETA(DisplayName = "Walk and Shoot Weapon C"),
	RB_ForceNewSpot											UMETA(DisplayName = "Force New Spot"),
	RB_StandBy												UMETA(DisplayName = "StandBy"),
	RB_Patrol												UMETA(DisplayName = "Patrolling"),
	RB_WeaponShootA											UMETA(DisplayName = "Shooting Weapon A"),
	RB_WeaponShootB											UMETA(DisplayName = "Shooting Weapon B"),
	RB_WeaponShootC											UMETA(DisplayName = "Shooting Weapon C"),
	RB_Fly													UMETA(DisplayName = "Fly"),
	RB_WeaponShootAWhileSurround							UMETA(DisplayName = "Shooting Weapon A While Surround"),
	RB_ShootingMissile										UMETA(DisplayName = "Shooting Missile"),
	RB_EvasionWhileSurround									UMETA(DisplayName = "Evasion While Surround"),	//Spiral
	RB_EvasionByLife										UMETA(DisplayName = "Evasion By Life"),
	RB_ChaseWhileSurround									UMETA(DisplayName = "Chase While Surround"),
	RB_ShootGunWhileSurround								UMETA(DisplayName = "Shoot Gun While Surround"),
	RB_ShootGunWhileSurroundAtBack							UMETA(DisplayName = "Shoot Gun While Surround At Back"),
	RB_ShootLaserWhileSurround								UMETA(DisplayName = "Shoot Laser While Surrond"),
	RB_ShootLaserWhileSurroundAtBack						UMETA(DisplayName = "Shoot Laser While Surround At Back"),
	RB_EnergyBlast											UMETA(DisplayName = "Energy Blast"),
	RB_Shielding											UMETA(DisplayName = "Shielding"),
	RB_DieExplode											UMETA(DisplayName = "Die Explode"),
	RB_ReactionToPlayerSkill_A								UMETA(DisplayName = "Reaction To Player Skill A"),
	RB_ReactionToPlayerSkill_B								UMETA(DisplayName = "Reaction To Player Skill B"),
	RB_ReactionToPlayerSkill_C								UMETA(DisplayName = "Reaction To Player Skill C"),
	RB_ReactionToPlayerSkill_D								UMETA(DisplayName = "Reaction To Player Skill D"),
	RB_ReactionToPlayerSkill_E								UMETA(DisplayName = "Reaction To Player Skill E"),
	RB_ReactionToPlayerSkill_F								UMETA(DisplayName = "Reaction To Player Skill F"),
	RB_Teleport												UMETA(DisplayName = "Teleport"),
};

//------------------------------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct FRobotBehaviorChance
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Behavior")
	ERobotBehavior m_behavior;
	
	UPROPERTY(EditAnywhere, Category = "Behavior")
	float m_chance;

	FRobotBehaviorChance()
	{
		m_behavior = ERobotBehavior::RB_StandBy;
		m_chance = 1.0f;
	}

	FRobotBehaviorChance(ERobotBehavior behavior, float chance)
	{
		m_behavior = behavior;
		m_chance = chance;
	}
};

//------------------------------------------------------------------------------------------------------------------
UCLASS()
class CUSTOMGAME_API AEnemyRobot : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyRobot(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick( float DeltaSeconds ) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION()
	void ActorBeginOverlap(class AActor* thisActor, class AActor* otherActor);

	void ForceKill(EKillType type);

	void TakeForceDamage(int damage, FVector force);
	//------------------------------------------------------------------------------------------------------------------
	//	Behavior
	void SetDiplomacyType(EDyplomacyType dyplomacy);
	void ResumeBrain();
	void PauseBrain();

	//	Target
	//	Shield
	//	Die

	//	Update by events
	void UpdateMovementSpeed(float multiplier);

	//------------------------------------------------------------------------------------------------------------------
	//	Difficult
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void SetNewRandomStateBasedOnDifficult(bool enableRepeat);

	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void SetNewState(ERobotBehavior state);

	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootLeftWeaponA();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootRightWeaponA();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootLeftWeaponB();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootRightWeaponB();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootLeftMachineGun();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootRightMachineGun();

	//------------------------------------------------------------------------------------------------------------------
	//	Fly
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	bool CreateSplinePath();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void DestroySplinePath() const;
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void FlyJump();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void StartJetPack();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void StopJetPack();
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void SetFly(bool enable);
	
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	float GetNormalizedFlyDistance() const;

	//------------------------------------------------------------------------------------------------------------------
	//	Missile
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootLeftMissile();

	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void ShootRightMissile();

	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void OpenMissilePack();

	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void CloseMissilePack();

	//------------------------------------------------------------------------------------------------------------------
	//	Damage
	UFUNCTION(BlueprintCallable, Category = "Drone Functions")
	void ApplyDamage(int32 damage);

	UFUNCTION()
	void OnCapsuleBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnCapsuleEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//------------------------------------------------------------------------------------------------------------------
	//	Jetpack
	void SetLookAtState(bool state);
	void SetCurrentBehavior(ERobotBehavior behavior);
	void PrepateToShootArmWeapon(bool state);
	void SetShootAtSameSpot(int32 value);
	void UpdateShootAtSameSpot();
	void StartTorsoLookAt();
	void StopTorsoLookAt();
	
	UFUNCTION(BlueprintPure, Category = "Robot Functions")
	float GetTorsoLookAtRotation() const;

	//------------------------------------------------------------------------------------------------------------------
	//	Weapon
	void StartShootWeaponA();
	void StopShootWeaponA();

	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void SetMuzzleParticlesState(bool enabled, float delay);
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void StartMuzzleParticlesState() const;
	UFUNCTION(BlueprintCallable, Category = "Robot Functions")
	void StopMuzzleParticlesState() const;

	//------------------------------------------------------------------------------------------------------------------
	//	Sound
	void PlayRobotSound();

protected:
	void InitializeVars();
	void InitializeMaterials();
	void InitializeTimers();
	void InitializeComponents();
	void InitializeTarget();
	void InitializeBehaviorTree();
	void InitializeSound();
	void TickRobotAsEnemy();
	void TickRobotAsAlly();
	void TickMaterialDamage();
	void TickBehaviors();//	TODO: move this to BTree

	//------------------------------------------------------------------------------------------------------------------
	//	Behavior
	void SetCustomDepth(bool enable);

	//------------------------------------------------------------------------------------------------------------------
	//	Target
	void TickLookAtTarget();
	void RefreshTargetActor();
	void TickTargetPosition();
	void TickFlyOnSplinePath();
	void GetTargetPositionLastSight();

	//------------------------------------------------------------------------------------------------------------------
	//	Die
	void Kill();
	void RemoveFromCrowdManager();
	void IncreaseDamageBonusToPlayer();
	bool UpdateCheckForKill();

	//------------------------------------------------------------------------------------------------------------------
	//	Difficult
	void CreateRandomStateEasyDifficult();
	void CreateRandomStateNormalDifficult();
	void CreateRandomStateHardDifficult();

	void Explode();
	void ChangeToDeadFadeMaterials() const;
	void RemoveDecals() const;

	void ShootLeftWeaponAnimationNormalATimer(float duration);
	void StopLeftWeaponAnimationNormalA();
	void ShootRightWeaponAnimationNormalATimer(float duration);
	void StopRightWeaponAnimationNormalA();
	void ShootLeftWeaponAnimationNormalBTimer(float duration);
	void StopLeftWeaponAnimationNormalB();
	void ShootRightWeaponAnimationNormalBTimer(float duration);
	void StopRightWeaponAnimationNormalB();
	void ShootLeftWeaponAnimationSpinTimer(float duration);
	void StopLeftWeaponAnimationSpin();
	void ShootRightWeaponAnimationSpinTimer(float duration);
	void StopRightWeaponAnimationSpin();

	//------------------------------------------------------------------------------------------------------------------
	//	Component
	void DisableCapsuleComponent();
	void DisableCustomDepth();
	void UpdateKillCounter();
	void UpdateXPTable();
	void KillAfterSeconds();

	//------------------------------------------------------------------------------------------------------------------
	//	Loot
	void SpawnLoot() const;
	void SpawnPortal_A() const;
	void SpawnPortal_B() const;
	void SpawnPortal_C() const;
	void SpawnPortal_D() const;
	void SpawnPortal_E() const;
	void SpawnPortal_F() const;
	void SpawnPortal_G() const;
	void SpawnPortal_H() const;
	void SpawnPortal_I() const;

public:

	//------------------------------------------------------------------------------------------------------------------
	//	Debug
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Config")
	bool m_enableKillParticleFX;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Config")
	bool m_enableKillDestruction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot Config")
	bool m_enableActorDestruction;

	//------------------------------------------------------------------------------------------------------------------
	//	Default
	float m_deltaTime;
	EDyplomacyType m_diplomacyType;
	bool m_isRare;
	int32 m_enemyCrowdManagerIndex;
		
	UPROPERTY()
	class AActor *m_target;

	//	Activated by spawner object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	bool m_enableToCombat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	bool m_enableLookAt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	ERobotBehavior m_currentRobotBehavior;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	ERobotBehavior m_lastRobotBehavior;

	UPROPERTY()
	FSquadFormation m_squadFormation;

	//------------------------------------------------------------------------------------------------------------------
	//	Sounds
	UPROPERTY()
	UAudioComponent* m_audioComponent;
	
	//------------------------------------------------------------------------------------------------------------------
	//	Movement
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float m_movementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	float m_movementSpeedMultiplier;

	//------------------------------------------------------------------------------------------------------------------
	//	Timers
	FTimerManager *m_timerManager;
	FTimerHandle m_targetUpdateTimer;
	FTimerHandle m_robotDestroyActorTimer;
	FTimerHandle m_restartBehaviorTree;
	FTimerHandle m_shootLeftWeaponAnimationNormalATimer;
	FTimerHandle m_shootRightWeaponAnimationNormalATimer;
	FTimerHandle m_shootLeftWeaponAnimationNormalBTimer;
	FTimerHandle m_shootRightWeaponAnimationNormalBTimer;
	FTimerHandle m_shootLeftWeaponAnimationSpinTimer;
	FTimerHandle m_shootRightWeaponAnimationSpinTimer;
	FTimerHandle m_shootLeftWeaponATimer;
	FTimerHandle m_shootRightWeaponATimer;
	FTimerHandle m_muzzleParticlesTimer;

	//------------------------------------------------------------------------------------------------------------------
	//	Target
	float m_targetDelayUpdate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	FVector m_targetPositionLastSight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	FVector m_targetPositionCurrentSight;

	//------------------------------------------------------------------------------------------------------------------
	//	Materials
	FLinearColor m_color;

	UPROPERTY()
	UMaterialInstanceDynamic* m_materialInstanceDynamic_01;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	UMaterialInterface* m_materialInterfaceBodyDeadFade;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	UMaterialInterface* m_materialInterfacePipeDeadFade;

	UPROPERTY()
	UMaterialInstanceDynamic* m_materialInstanceDynamicBodyDeadFade;

	UPROPERTY()
	UMaterialInstanceDynamic* m_materialInstanceDynamicPipeDeadFade;

	//------------------------------------------------------------------------------------------------------------------
	//	Shield

	//------------------------------------------------------------------------------------------------------------------
	//	Dead
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
	EEnemyDifficult m_robotDifficult;

	//------------------------------------------------------------------------------------------------------------------
	//	Weapons
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_bulletProjectileA;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_bulletProjectileB;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_bulletProjectileC;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_missile;

	//------------------------------------------------------------------------------------------------------------------
	//	Secrets
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<APortal> m_portal_A;

	//------------------------------------------------------------------------------------------------------------------
	//	Fly
	float m_flySpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_splineFlyPath;

	UPROPERTY(EditAnywhere, Category = "Robot")
	UCurveFloat* m_flySpeedMultiplier;

	UPROPERTY()
	USplineComponent* m_splineComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	float m_splineCurrentDistance;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	float m_splineLength;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_jetPackEnable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Robot")
	bool m_enableFly;

	UPROPERTY()
	class AActor *m_splineFlyPathInstance;

	//------------------------------------------------------------------------------------------------------------------
	//	Progression
	int32 m_baseDamage;
	int32 m_experience;

	//------------------------------------------------------------------------------------------------------------------
	//	Components
	bool m_firstFrameTakeDamage;
	float m_height;
	float m_energyMultiplier;
	float m_damageMultiplier;
	float m_XPMultiplier;
	bool m_enableBehaviors;
	float m_maxDistanceFromHero;
	FVector m_spawnPosition;

	UPROPERTY()
	UChildActorComponent* m_leftWeaponSocket;

	UPROPERTY()
	UChildActorComponent* m_rightWeaponSocket;

	UPROPERTY()
	UParticleSystemComponent* m_leftJetPackParticleSystem;

	UPROPERTY()
	UParticleSystemComponent* m_rightJetPackParticleSystem;

	UPROPERTY()
	UParticleSystemComponent* m_muzzleLeftParticleSystem;

	UPROPERTY()
	UParticleSystemComponent* m_muzzleRightParticleSystem;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	UPhysicsAsset* m_physicsAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	int m_currentEnergy;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	int m_maxEnergy;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	bool m_robotIsDead;

	//------------------------------------------------------------------------------------------------------------------
	//	BehaviorTree
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	UBehaviorTree* m_behaviorTreeEasy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	UBehaviorTree* m_behaviorTreeNormal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	UBehaviorTree* m_behaviorTreeHard;

	UPROPERTY()
	UBehaviorTree* m_behaviorTreeSelected;

	UPROPERTY()
	TArray<FRobotBehaviorChance> m_enemyBehaviors;

	UPROPERTY()
	TArray<FRobotBehaviorChance> m_allyBehaviors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Robot")
	UBehaviorTree* m_behaviorTree;

	//------------------------------------------------------------------------------------------------------------------
	//	Dead
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_explosionBP;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	TSubclassOf<AActor> m_explosionRareBP;

	//------------------------------------------------------------------------------------------------------------------
	//	Used by AnimBP
	int32 m_maxShootAtSameSpot;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isFlying;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isPrepareToShootArmWeapon;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmLeftWeaponNormalA;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmRightWeaponNormalA;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmLeftWeaponNormalB;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmRightWeaponNormalB;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmLeftWeaponSpin;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmRightWeaponSpin;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingMissile;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmLeftWeaponB;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_isShootingArmRightWeaponB;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Robot")
	bool m_enableTorsoLookAt;

	//------------------------------------------------------------------------------------------------------------------
	//	Sockets
	UPROPERTY()
	TArray<FName> m_leftMissileSockets;
	
	UPROPERTY()
	TArray<FName> m_rightMissileSockets;
	
	UPROPERTY()
	TArray<FName> m_leftMachineGunSockets;
	
	UPROPERTY()
	TArray<FName> m_rightMachineGunSockets;
	
	UPROPERTY()
	TArray<FName> m_leftWeaponSockets;
	
	UPROPERTY()
	TArray<FName> m_rightWeaponSockets;

	//friend UCrowdManager;
};
