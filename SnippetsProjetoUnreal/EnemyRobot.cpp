//==================================================================================================================
//
//	File:	EnemyRobot.cpp
//	Date:	15-11-2016
//	Author:	wandersonp@gmail.com
//
//	Description:    
//
//==================================================================================================================

#include "CustomGame.h"
#include "Enemy/EnemyRobot.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystemComponent.h"
#include "Collision/ColisionChannels.h"

#pragma region UE4
//------------------------------------------------------------------------------------------------------------------
AEnemyRobot::AEnemyRobot(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationYaw = false;
	this->bUseControllerRotationRoll = false;
	//this->OnActorBeginOverlap.AddDynamic(this, &AEnemyRobot::ActorBeginOverlap);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::BeginPlay()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	Super::BeginPlay();
	
	//ARobotAIController *aiController = Cast<ARobotAIController>(this->GetController());
	//if (aiController != nullptr)
	//{
	//	UCrowdFollowingComponent *crowdFollowingComponent = Cast<UCrowdFollowingComponent>(aiController->GetPathFollowingComponent());
	//	if (crowdFollowingComponent != nullptr)
	//	{
	//		UCrowdManager *crowdManager = UCrowdManager::GetCurrent(GetWorld());
	//		if (crowdManager != nullptr)
	//		{
	//			ICrowdAgentInterface* IAgent = Cast<ICrowdAgentInterface>(crowdFollowingComponent);
	//			if (IAgent != nullptr)
	//			{
	//				//crowdManager->RegisterAgent(IAgent);
	//				print("register this AGENT WORKS");
	//			}
	//			// CrowdManager->UpdateAgentParams(IAgent);
	//			//crowdManager->RegisterAgent(this);
	//		}
	//	}
	//}

	this->InitializeVars();
	this->InitializeMaterials();
	this->InitializeComponents();
	this->InitializeTimers();
	this->InitializeTarget();
	this->InitializeBehaviorTree();
	this->InitializeSound();
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	Super::EndPlay(EndPlayReason);
	this->m_timerManager->ClearAllTimersForObject(this);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::Tick( float DeltaTime )
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG
	Super::Tick( DeltaTime );

	if (this->m_enableToCombat)
	{
		this->m_deltaTime = DeltaTime;
		switch (this->m_diplomacyType)
		{
		case EDyplomacyType::DT_Enemy:
			this->TickRobotAsEnemy();
			break;
		case EDyplomacyType::DT_Ally:
			this->TickRobotAsAlly();
			break;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetupPlayerInputComponent(class UInputComponent* inputComponent)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	Super::SetupPlayerInputComponent(inputComponent);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ActorBeginOverlap(class AActor* thisActor, class AActor* otherActor)
{
	return;
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	if (otherActor == nullptr)
	{
		GAME_SHIPPING_LOG(GameShippingLog, "Unable to get nullptr AActor");
		return;
	}

	if (thisActor == otherActor)
	{
		return;
	}

	//	Check if class is a projectile from hero
	if (otherActor->IsA(ABulletProjectile::StaticClass()))
	{
		ABulletProjectile *projectile = Cast<ABulletProjectile>(otherActor);
		if (projectile != nullptr)
		{
			if (projectile->m_weaponOwner == EWeaponOwner::WO_Player)
			{
#ifndef SHIPPING_GAME_VERSION
				print("hit by hero projectile");
#endif  //SHIPPING_GAME_VERSION
				this->ApplyDamage(projectile->m_damage);
				//TakeForceDamage(projectile->m_damage, FVector::ZeroVector);
			}
		}
	}
	//	Check if class is a missile from hero
	if (otherActor->IsA(AMissile::StaticClass()))
	{
		AMissile *missile = Cast<AMissile>(otherActor);
		if (missile != nullptr)
		{
			if (missile->m_weaponOwner == EWeaponOwner::WO_Player)
			{
				this->ApplyDamage(missile->m_damage);
				//TakeForceDamage(missile->m_damage, FVector::ZeroVector);
			}
		}
	}
}
#pragma endregion

#pragma region INITIALIZE
//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeVars()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Default
	//m_enableToCombat = false;

	this->m_isRare = FMath::RandRange(0, 10) == 0 ? true : false;
	this->SetCustomDepth(this->m_isRare);

	//	Diplomacy
	//this->m_diplomacyType = EDyplomacyType::DT_Enemy;
	//this->SetDiplomacyType(this->m_diplomacyType);

	UWorld* world = this->GetWorld();
	if (world != nullptr)
	{
		AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			//	Energy and damage regards to hero level
			if (this->m_isRare)
			{
				this->m_damageMultiplier = 4.0f * gameMode->m_arenaDifficultMultiplier;
				this->m_XPMultiplier = 4.0f * gameMode->m_arenaDifficultMultiplier;
				this->m_energyMultiplier = 4.0f * gameMode->m_arenaDifficultMultiplier;
				this->m_maxEnergy = FMath::CeilToInt(static_cast<float>(gameMode->GetEnemyEnergyBasedOnHeroLevel()) * this->m_energyMultiplier);
				this->m_currentEnergy = this->m_maxEnergy;
				this->m_baseDamage = gameMode->GetEnemyBaseDamageBasedOnHeroLevel() * this->m_energyMultiplier;
				this->m_experience = gameMode->GetEnemyXPBasedOnHeroLevel() * this->m_energyMultiplier;
				//this->SetActorScale3D(FVector(2.2f, 2.2f, 2.5f));
			}
			else
			{
				this->m_damageMultiplier = 1.0f * gameMode->m_arenaDifficultMultiplier;
				this->m_XPMultiplier = 1.0f * gameMode->m_arenaDifficultMultiplier;
				this->m_energyMultiplier = 1.0f * gameMode->m_arenaDifficultMultiplier;
				this->m_maxEnergy = FMath::CeilToInt(static_cast<float>(gameMode->GetEnemyEnergyBasedOnHeroLevel()) * this->m_energyMultiplier);
				this->m_currentEnergy = this->m_maxEnergy;
				this->m_baseDamage = gameMode->GetEnemyBaseDamageBasedOnHeroLevel() * this->m_energyMultiplier;
				this->m_experience = gameMode->GetEnemyXPBasedOnHeroLevel() * this->m_energyMultiplier;
			}
		}
	}

	this->m_enableBehaviors = false;
	this->m_maxDistanceFromHero = 5000.0f;
	this->m_spawnPosition = this->GetActorLocation();

	this->m_height = 400.0f;
	this->m_robotIsDead = false;
	this->m_currentRobotBehavior = ERobotBehavior::RB_WeaponShootA;
	this->m_lastRobotBehavior = ERobotBehavior::RB_WeaponShootA;
	this->m_enableLookAt = false;
	this->m_enableFly = false;
	this->m_splineFlyPathInstance = nullptr;
	this->m_splineComponent = nullptr;
	this->m_splineCurrentDistance = 0;
	this->m_flySpeed = 1000.0f;

	//	AnimationBP
	this->m_isFlying = false;
	this->m_isShootingArmLeftWeaponNormalA = false;
	this->m_isShootingArmRightWeaponNormalA = false;
	this->m_isShootingArmLeftWeaponNormalB = false;
	this->m_isShootingArmRightWeaponNormalB = false;
	this->m_isShootingArmLeftWeaponSpin = false;
	this->m_isShootingArmRightWeaponSpin = false;
	this->m_isShootingMissile = false;
	this->m_maxShootAtSameSpot = FMath::RandRange(3, 8);

	//	Material
	this->m_firstFrameTakeDamage = false;

	//	Target
	this->m_targetDelayUpdate = 0.05f;// FMath::FRandRange(0.02f, 0.1f);	//	Change by enemy difficult

	//	Set robot difficult
	if (world != nullptr)
	{
		UMercilessBotsGameInstance* gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			float bonusSpeed = 1.0f;
			if (this->m_isRare)
			{
				bonusSpeed = 1.7f;
			}
			switch (gameInstance->GetGameDifficult())
			{
			case EGameDifficult::GD_Easy:
				this->m_robotDifficult = EEnemyDifficult::ED_Easy;
				this->m_movementSpeedMultiplier = FMath::FRandRange(0.7f, 1.0f) * bonusSpeed;
				break;
			case EGameDifficult::GD_Normal:
				this->m_robotDifficult = EEnemyDifficult::ED_Normal;
				this->m_movementSpeedMultiplier = FMath::FRandRange(1.5f, 2.5f) * bonusSpeed;
				break;
			case EGameDifficult::GD_Hard:
				this->m_robotDifficult = EEnemyDifficult::ED_Hard;
				this->m_movementSpeedMultiplier = FMath::FRandRange(2.5f, 4.0f) * bonusSpeed;
				break;
			}
		}
	}

	//	Set movement speed
	//	Base speed == 500
	//	Walk animation ratio  = 1.85
	this->GetCharacterMovement()->MaxWalkSpeed = this->m_movementSpeed * this->m_movementSpeedMultiplier;
	this->GetCharacterMovement()->bUseRVOAvoidance = false;

	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr)
	{
		skeletalMesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::Type::OnlyTickPoseWhenRendered;
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeMaterials()
{
	//	Set skeletal mesh materials
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr)
	{
		class UMaterialInterface *bodyMaterial = skeletalMesh->GetMaterial(7);
		if (bodyMaterial != nullptr)
		{
			this->m_materialInstanceDynamic_01 = UMaterialInstanceDynamic::Create(bodyMaterial, this);
			if (this->m_materialInstanceDynamic_01 != nullptr)
			{
				this->m_materialInstanceDynamic_01->SetVectorParameterValue(FName("RobotColor"), this->m_color);
				if (this->m_isRare)
				{
					this->m_materialInstanceDynamic_01->SetScalarParameterValue(FName("Rare"), 1.0f);
				}
				skeletalMesh->SetMaterial(7, this->m_materialInstanceDynamic_01);
			}
		}
		
		if (this->m_materialInterfaceBodyDeadFade != nullptr && this->m_materialInterfacePipeDeadFade != nullptr)
		{
			this->m_materialInstanceDynamicBodyDeadFade = UMaterialInstanceDynamic::Create(this->m_materialInterfaceBodyDeadFade, this);
			this->m_materialInstanceDynamicBodyDeadFade->SetVectorParameterValue(FName("RobotColor"), this->m_color);
			this->m_materialInstanceDynamicBodyDeadFade->SetScalarParameterValue(FName("Rare"), 0);
			this->m_materialInstanceDynamicPipeDeadFade = UMaterialInstanceDynamic::Create(this->m_materialInterfacePipeDeadFade, this);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeTimers()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_timerManager = &GetWorldTimerManager();
	this->m_timerManager->SetTimer(this->m_targetUpdateTimer, this, &AEnemyRobot::GetTargetPositionLastSight, this->m_targetDelayUpdate, true, 0);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeComponents()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Get particle systems
	TArray<UParticleSystemComponent *> particleSystemComponents;
	GetComponents<UParticleSystemComponent>(particleSystemComponents);
	for (int i = 0; i < particleSystemComponents.Num(); i++) 
	{
		FString name = particleSystemComponents[i]->GetName();
		if (name == FString("JetPackLeft_Particle"))
		{
			this->m_leftJetPackParticleSystem = particleSystemComponents[i];
		}
		if (name == FString("JetPackRight_Particle"))
		{
			this->m_rightJetPackParticleSystem = particleSystemComponents[i];
		}
		if (name == FString("MuzzleLeft_Particle"))
		{
			this->m_muzzleLeftParticleSystem = particleSystemComponents[i];
		}
		if (name == FString("MuzzleRight_Particle"))
		{
			this->m_muzzleRightParticleSystem = particleSystemComponents[i];
		}
	}

	//	Initialize capsule delegates
	UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
	if (capsuleComponent != nullptr)
	{
		capsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyRobot::OnCapsuleBeginOverlap);
		capsuleComponent->OnComponentEndOverlap.AddDynamic(this, &AEnemyRobot::OnCapsuleEndOverlap);
	}
	
	//	Initialize sockets names
	this->m_leftMissileSockets.Empty();
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_1"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_2"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_3"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_4"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_5"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_6"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_7"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_8"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_9"));
	this->m_leftMissileSockets.Add(FName("LeftSocketMissile_10"));

	this->m_rightMissileSockets.Empty();
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_1"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_2"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_3"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_4"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_5"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_6"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_7"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_8"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_9"));
	this->m_rightMissileSockets.Add(FName("RightSocketMissile_10"));

	this->m_leftMachineGunSockets.Empty();
	this->m_leftMachineGunSockets.Add(FName("LeftMachineGun_1"));
	this->m_leftMachineGunSockets.Add(FName("LeftMachineGun_2"));
	this->m_leftMachineGunSockets.Add(FName("LeftMachineGun_3"));
	this->m_leftMachineGunSockets.Add(FName("LeftMachineGun_4"));
	this->m_leftMachineGunSockets.Add(FName("LeftMachineGun_5"));
	this->m_leftMachineGunSockets.Add(FName("LeftMachineGun_6"));

	this->m_rightMachineGunSockets.Empty();
	this->m_rightMachineGunSockets.Add(FName("RightMachineGun_1"));
	this->m_rightMachineGunSockets.Add(FName("RightMachineGun_2"));
	this->m_rightMachineGunSockets.Add(FName("RightMachineGun_3"));
	this->m_rightMachineGunSockets.Add(FName("RightMachineGun_4"));
	this->m_rightMachineGunSockets.Add(FName("RightMachineGun_5"));
	this->m_rightMachineGunSockets.Add(FName("RightMachineGun_6"));

	this->m_leftWeaponSockets.Empty();
	this->m_leftWeaponSockets.Add(FName("LeftGun_1"));
	this->m_leftWeaponSockets.Add(FName("LeftGun_2"));
	this->m_leftWeaponSockets.Add(FName("LeftGun_3"));
	this->m_leftWeaponSockets.Add(FName("LeftGun_4"));
	this->m_leftWeaponSockets.Add(FName("LeftGun_5"));
	this->m_leftWeaponSockets.Add(FName("LeftGun_6"));
	this->m_leftWeaponSockets.Add(FName("LeftGun_7"));

	this->m_rightWeaponSockets.Empty();
	this->m_rightWeaponSockets.Add(FName("RightGun_1"));
	this->m_rightWeaponSockets.Add(FName("RightGun_2"));
	this->m_rightWeaponSockets.Add(FName("RightGun_3"));
	this->m_rightWeaponSockets.Add(FName("RightGun_4"));
	this->m_rightWeaponSockets.Add(FName("RightGun_5"));
	this->m_rightWeaponSockets.Add(FName("RightGun_6"));
	this->m_rightWeaponSockets.Add(FName("RightGun_7"));
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeTarget()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Get hero actor
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		//if (m_squadFormation.m_isLeader)
		{
			this->m_target = Cast<AActor>(UGameplayStatics::GetPlayerPawn(world, 0));
			if (this->m_target != nullptr)
			{
				this->m_targetPositionLastSight = this->m_target->GetActorLocation();
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeBehaviorTree()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_enemyBehaviors.Empty();
	this->m_allyBehaviors.Empty();

	switch (this->m_robotDifficult)
	{
	case EEnemyDifficult::ED_Easy:
		this->CreateRandomStateEasyDifficult();
		break;
	case EEnemyDifficult::ED_Normal:
		this->CreateRandomStateNormalDifficult();
		break;
	case EEnemyDifficult::ED_Hard:
		this->CreateRandomStateHardDifficult();
		break;
	}

	this->m_behaviorTreeSelected = nullptr;
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			//	Get AI controller
			AAIController *controller = Cast<AAIController>(this->GetController());
			if (controller != nullptr)
			{
				int value = FMath::RandRange(0, 10);

				//	Get suitable difficult BT
				switch (gameInstance->GetGameDifficult())
				{
				case EGameDifficult::GD_Easy:
					if (value < 9)
					{
						this->m_behaviorTreeSelected = this->m_behaviorTreeEasy;
					}
					else
					{
						this->m_behaviorTreeSelected = this->m_behaviorTreeNormal;
					}
					break;
				case EGameDifficult::GD_Normal:
					if (value < 9)
					{
						this->m_behaviorTreeSelected = this->m_behaviorTreeNormal;
					}
					else
					{
						this->m_behaviorTreeSelected = this->m_behaviorTreeHard;
					}
					break;
				case EGameDifficult::GD_Hard:
					this->m_behaviorTreeSelected = this->m_behaviorTreeHard;
					break;
				}
			}
			this->SetNewRandomStateBasedOnDifficult(true);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::InitializeSound()
{
	TArray<UAudioComponent *> audioComponents;
	this->GetComponents<UAudioComponent>(audioComponents);
	if (audioComponents.Num() > 0)
	{
		this->m_audioComponent = audioComponents[0];
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ResumeBrain()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Get AI controller
	ARobotAIController *aiController = Cast<ARobotAIController>(this->GetController());
	if (aiController != nullptr)
	{
		aiController->ResumeBrain();
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::PauseBrain()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Get AI controller
	ARobotAIController *aiController = Cast<ARobotAIController>(this->GetController());
	if (aiController != nullptr)
	{
		aiController->PauseBrain();
	}
}

#pragma endregion

#pragma region UPDATE
//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TickRobotAsEnemy()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Clear animations flags
	//if (m_isShootingArmLeftWeapon) { m_isShootingArmLeftWeapon = false; }
	//if (m_isShootingArmRightWeapon) { m_isShootingArmRightWeapon = false; }
	//m_isShootingArmRightWeapon = false;
	//m_isShootingShoulderLeftWeapon = false;
	//m_isShootingShoulderRightWeapon = false;
	//m_isShootingArmLeftWeaponB = false;
	//m_isShootingArmRightWeaponB = false;

	//	Check if enable to combat
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			if (!gameMode->m_enableCombat)
			{
				return;
			}
		}
			
		//	First check if character was rendered to update this material
		if (this->WasRecentlyRendered())
		{
			this->TickMaterialDamage();
		}

		//	Avoid tick after dead flag
		if (this->m_robotIsDead)
		{
			//m_destructibleDrone->SetVisibility(true);
			//m_destructibleDrone->SetEnableGravity(true);
			//m_destructibleDrone->SetSimulatePhysics(true);
			return;
		}

		//	if life is zero disable all dynamic behavior and 
		if (this->UpdateCheckForKill())
		{
			return;
		}

		this->TickLookAtTarget();
		this->TickTargetPosition();
		this->TickFlyOnSplinePath();
		this->TickBehaviors();
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TickRobotAsAlly()
{
	//	Check if enable to combat
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			if (!gameMode->m_enableCombat)
			{
				return;
			}
		}

		//	First check if character was rendered to update this material
		if (this->WasRecentlyRendered())
		{
			//TickMaterialDamage();
		}

		//	Avoid tick after dead flag
		if (this->m_robotIsDead)
		{
			//m_destructibleDrone->SetVisibility(true);
			//m_destructibleDrone->SetEnableGravity(true);
			//m_destructibleDrone->SetSimulatePhysics(true);
			return;
		}

		//	if life is zero disable all dynamic behavior and 
		if (this->UpdateCheckForKill())
		{
			return;
		}

		//TickLookAtTarget();
		//TickTargetPosition();
		this->TickFlyOnSplinePath();
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TickMaterialDamage()
{
	UWorld *world = this->GetWorld();
	if (this->m_firstFrameTakeDamage && world != nullptr && this->m_materialInstanceDynamic_01 != nullptr)
	{
		this->m_firstFrameTakeDamage = false;
		float worldSeconds = world->GetTimeSeconds();
		this->m_materialInstanceDynamic_01->SetScalarParameterValue(FName(TEXT("DamageColor")), worldSeconds);
	}
}

//------------------------------------------------------------------------------------------------------------------
//	TODO: move this to BTree
void AEnemyRobot::TickBehaviors()
{
	//	TODO: check this
	return;
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		ACustomRobot *hero = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(world, 0));
		if (hero != nullptr)
		{
			if (FVector::Dist(hero->GetActorLocation(), this->GetActorLocation()) > this->m_maxDistanceFromHero)
			{
				this->m_enableBehaviors = false;
			}
			else
			{
				this->m_enableBehaviors = true;
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetCustomDepth(bool enable)
{
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr)
	{
		skeletalMesh->SetRenderCustomDepth(enable);
		skeletalMesh->SetCustomDepthStencilValue(1);
		//skeletalMesh->SetCustomDepthStencilValue(STENCIL_ENEMY_OUTLINE);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ApplyDamage(int32 damage)
{
	//	Append damage number
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		this->m_currentEnergy -= damage;
		this->m_firstFrameTakeDamage = true;

		//	TODO: nao precisa executar se nao esta setado showdamage numbers nas configuracoes
		AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			FVector position = this->GetActorLocation() + FMath::VRand() * FMath::FRandRange(0, 300.0f);
			gameMode->AppendDamageNumbers(damage, position, EDamageType::DT_Normal);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr)
	{
		//	Check if class is a projectile from hero
		if (OtherActor->IsA(ABulletProjectile::StaticClass()))
		{
			ABulletProjectile *projectile = Cast<ABulletProjectile>(OtherActor);
			if (projectile != nullptr)
			{
				if (projectile->m_weaponOwner == EWeaponOwner::WO_Player)
				{
#ifndef SHIPPING_GAME_VERSION
					print("hit by hero projectile");
#endif  //SHIPPING_GAME_VERSION
					this->ApplyDamage(projectile->m_damage);
					projectile->Destroy();
					//TakeForceDamage(projectile->m_damage, FVector::ZeroVector);
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::OnCapsuleEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
#pragma endregion

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TakeForceDamage(int damage, FVector force)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_currentEnergy -= damage;
	this->m_firstFrameTakeDamage = true;

	//	Append damage number
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			APlayerController *playerController = world->GetFirstPlayerController();
			if (playerController != nullptr)
			{
				FVector2D screenPosition;
				FVector position = GetActorLocation();
				playerController->ProjectWorldLocationToScreen(position, screenPosition);
				//gameMode->AppendDamageNumbers(damage, screenPosition, EDamageType::DT_Normal);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetDiplomacyType(EDyplomacyType dyplomacy)
{
	this->m_diplomacyType = dyplomacy;
	switch (m_diplomacyType)
	{
	case EDyplomacyType::DT_Enemy:
		this->SetCustomDepth(false);
		break;
	case EDyplomacyType::DT_Ally:
		this->SetCustomDepth(true);
		this->SetMuzzleParticlesState(false, 0);
		
		//	Disable collision to hero
		UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
		if (capsuleComponent != nullptr)
		{
			capsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::COLLISION_HERO, ECollisionResponse::ECR_Ignore);
			capsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::COLLISION_HERO_WEAPON, ECollisionResponse::ECR_Ignore);
			capsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::COLLISION_ROBOT_ENEMY, ECollisionResponse::ECR_Block);
			capsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::COLLISION_ENEMY_WEAPON, ECollisionResponse::ECR_Overlap);
		}
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ForceKill(EKillType type)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	switch (type)
	{
	case EKillType::KT_Default:
		break;
	case EKillType::KT_Explosion:
		break;
	}
}

#pragma region DIFFICULT
//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::CreateRandomStateEasyDifficult()
{
	//	TODO:	Variation of easy
	this->CreateRandomStateNormalDifficult();

	//this->GetCharacterMovement()->AvoidanceGroup.SetGroup(0);
	//this->GetCharacterMovement()->GroupsToAvoid.SetGroup(0);
	//this->GetCharacterMovement()->GroupsToIgnore.SetGroup(0);

	//FNavAvoidanceMask
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::CreateRandomStateNormalDifficult()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_allyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_StandBy, 1.0f));
	this->m_allyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootA, 1.0f));
	//m_allyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootB, 1.0f));
	//m_allyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootC, 1.0f));
	//m_allyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_ShootingMissile, 1.0f));
	//m_allyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_Fly, 0.15f));

	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_StandBy, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootA, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootB, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootC, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_ShootingMissile, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_Fly, 0.15f));	//Check why is crashing here
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_Teleport, 1.0f));	

	//	FUTURE
	//m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WalkAndShootWeaponA, 1.0f));
	//m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WalkAndShootWeaponB, 1.0f));
	//m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WalkAndShootWeaponC, 1.0f));
	//m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootAWhileSurround, 1.0f));
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::CreateRandomStateHardDifficult()
{
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_StandBy, 0.1f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootA, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootB, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_WeaponShootC, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_ShootingMissile, 1.0f));
	this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_Fly, 0.15f));	
	////Check why is crashing here
	//this->m_enemyBehaviors.Add(FRobotBehaviorChance(ERobotBehavior::RB_Teleport, 1.0f));
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetNewRandomStateBasedOnDifficult(bool enableRepeat)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_lastRobotBehavior = this->m_currentRobotBehavior;
	float chance;
	int indexRandomBehavior;

	//	copy current diplomacy behavior
	TArray<FRobotBehaviorChance> dyplomacyBehaviors;
	dyplomacyBehaviors.Empty();
	if (m_diplomacyType == EDyplomacyType::DT_Enemy)
	{
		dyplomacyBehaviors = TArray<FRobotBehaviorChance>(this->m_enemyBehaviors);
	}
	else
	{
		dyplomacyBehaviors = TArray<FRobotBehaviorChance>(this->m_allyBehaviors);
	}

	if (!enableRepeat)
	{
		while(true)
		{
			indexRandomBehavior = FMath::RandRange(0, dyplomacyBehaviors.Num() - 1);
			chance = FMath::FRand();
			m_currentRobotBehavior = dyplomacyBehaviors[indexRandomBehavior].m_behavior;

			//	Check chance
			if (chance < dyplomacyBehaviors[indexRandomBehavior].m_chance && this->m_currentRobotBehavior != this->m_lastRobotBehavior)
			{
				break;
			}
		}
#ifdef SHOW_LOG
		UE_LOG(EnemiesLog, Warning, TEXT("Inside SetNewRandomStateBasedOnDifficult %f"), chance);
#endif  //SHOW_LOG
	}
	else
	{
		while(true)
		{
			indexRandomBehavior = FMath::RandRange(0, dyplomacyBehaviors.Num() - 1);
			chance = FMath::FRand();
			this->m_currentRobotBehavior = dyplomacyBehaviors[indexRandomBehavior].m_behavior;
			if (chance < dyplomacyBehaviors[indexRandomBehavior].m_chance)
			{
				break;
			}
		}
#ifdef SHOW_LOG
		UE_LOG(EnemiesLog, Warning, TEXT("Inside SetNewRandomStateBasedOnDifficult %f"), chance);
#endif  //SHOW_LOG
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetNewState(ERobotBehavior state)
{
	this->m_currentRobotBehavior = state;
}
#pragma endregion

#pragma region TARGET
//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TickTargetPosition()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_targetPositionLastSight = FMath::VInterpTo(this->m_targetPositionLastSight, this->m_targetPositionCurrentSight, this->m_deltaTime, 10.0f);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::RefreshTargetActor()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		ACustomRobot *hero = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(world, 0));
		AEnemyRobot* ally = nullptr;
		if (hero != nullptr)
		{
			switch (this->m_diplomacyType)
			{
			case EDyplomacyType::DT_Enemy:
				ally = hero->GetNearAlly(this->GetActorLocation());
				if (ally != nullptr)
				{
#ifndef SHIPPING_GAME_VERSION
					//print("Ally found");
					UE_LOG(MercilessLog, Warning, TEXT("Ally found"));
#endif  //SHIPPING_GAME_VERSION
					this->m_target = ally;
				}
				else
				{
#ifndef SHIPPING_GAME_VERSION
					//print("Ally not found");
					UE_LOG(MercilessLog, Warning, TEXT("Ally not found"));
#endif  //SHIPPING_GAME_VERSION
					this->m_target = hero;
				}
				break;
			case EDyplomacyType::DT_Ally:
				break;
			}
		}

#ifndef SHIPPING_GAME_VERSION
		//print("Refresh Target Actors");
		UE_LOG(MercilessLog, Warning, TEXT("Refresh Target Actors"));
#endif  //SHIPPING_GAME_VERSION
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TickLookAtTarget()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	UWorld *world = this->GetWorld();
	if (this->m_enableLookAt && world != nullptr)
	{
#ifndef SHIPPING_GAME_VERSION
		//print("AEnemyRobot::TickLookAtTarget Enable");
		UE_LOG(MercilessLog, Warning, TEXT("AEnemyRobot::TickLookAtTarget Enable"));
#endif  //SHIPPING_GAME_VERSION
		FVector targetPosition = this->m_targetPositionLastSight;
		FVector position = this->GetActorLocation();
		position.Z = targetPosition.Z;
		float deltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(world);
		FRotator desiredRotation = FMath::RInterpTo(this->GetActorRotation(), UKismetMathLibrary::FindLookAtRotation(position, targetPosition), deltaSeconds, 15.0f);
		this->SetActorRotation(desiredRotation);
	}
	//else
	//{
	//	print("AEnemyRobot::TickLookAtTarget Disable");
	//}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::TickFlyOnSplinePath()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	if (this->m_enableFly && this->m_splineFlyPathInstance != nullptr)
	{
		float splineNormalizedDistance = UKismetMathLibrary::MapRangeClamped(this->m_splineCurrentDistance, 0, this->m_splineLength, 0, 1.0f);
		float intensity = this->m_flySpeedMultiplier->GetFloatValue(splineNormalizedDistance);

		//	Update Speed
		this->m_splineCurrentDistance += m_deltaTime * (m_flySpeed * intensity);

		//	Update Position
		FVector newPosition = this->m_splineComponent->GetLocationAtDistanceAlongSpline(this->m_splineCurrentDistance, ESplineCoordinateSpace::World);
		this->SetActorLocation(newPosition);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::GetTargetPositionLastSight()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//RefreshTargetActor();

	//UWorld *world = GetWorld();
	//ACustomRobot *target = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(world, 0));
	//if (target == nullptr)
	//{
	//	GAME_SHIPPING_LOG(GameShippingLog, "Unable to get nullptr ACustomRobot");
	//	return;
	//}
	//m_targetPositionCurrentSight = target->GetActorLocation();

	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		ACustomRobot *hero = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(world, 0));
		AEnemyRobot* ally = nullptr;
		if (hero != nullptr)
		{
			switch (this->m_diplomacyType)
			{
			case EDyplomacyType::DT_Enemy:
				ally = hero->GetNearAlly(this->GetActorLocation());
				if (ally != nullptr)
				{
#ifndef SHIPPING_GAME_VERSION
					//print("Ally found");
#endif  //SHIPPING_GAME_VERSION
					this->m_target = ally;
				}
				else
				{
#ifndef SHIPPING_GAME_VERSION
					//print("Ally not found");
#endif  //SHIPPING_GAME_VERSION
					this->m_target = hero;
				}
				break;
			case EDyplomacyType::DT_Ally:
				//	Get near enemy
				break;
			}
		}
		if (this->m_target != nullptr)
		{
			this->m_targetPositionCurrentSight = this->m_target->GetActorLocation();
		}
	}
}
#pragma endregion

#pragma region WEAPON
//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftWeaponA()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	float laserSpeed = 6.0f;
	float laserLifeTime = 0.3f;

	//	Set animation flag
	this->ShootLeftWeaponAnimationNormalATimer(0.2f);
	
	//	Get sockets
	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set index
		int indexProjectile = FMath::RandRange(0, this->m_leftWeaponSockets.Num() - 1);
		
		//	Define position and rotation
		FTransform transform;
		transform.SetLocation(skeletalMesh->GetSocketLocation(this->m_leftWeaponSockets[indexProjectile]));
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = this->m_targetPositionLastSight + littleVectorRandom;
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		if (this->m_bulletProjectileA != nullptr)
		{
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileA, transform);
			if (projectile != nullptr)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();
				projectile->m_velocity = velocity * 1000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				projectile->m_damage = this->m_baseDamage;
				projectile->m_speed = laserSpeed;
				projectile->m_lifetime = laserLifeTime;

				//	Finish spawn actor
				//transform.SetScale3D(FVector(2.0f));
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightWeaponA()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG
	//	TODO fazer versao de aliado atirando nos inimigos

	float laserSpeed = 6.0f;
	float laserLifeTime = 0.3f;
	
	//	Set animation flag
	this->ShootRightWeaponAnimationNormalATimer(0.2f);
	
	//	Get sockets
	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set index
		int indexProjectile = FMath::RandRange(0, this->m_rightWeaponSockets.Num() - 1);

		//	Define position and rotation
		FTransform transform;
		transform.SetLocation(skeletalMesh->GetSocketLocation(this->m_rightWeaponSockets[indexProjectile]));
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = m_targetPositionLastSight + littleVectorRandom;
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		if (this->m_bulletProjectileA != nullptr)
		{
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileA, transform);
			if (projectile != nullptr)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();
				projectile->m_velocity = velocity * 1000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				projectile->m_damage = this->m_baseDamage;
				projectile->m_speed = laserSpeed;
				projectile->m_lifetime = laserLifeTime;

				//	Finish spawn actor
				//transform.SetScale3D(FVector(2.0f));
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftWeaponB()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	float laserSpeed = 6.0f;
	float laserLifeTime = 0.3f;

	//	Set animation flag
	this->ShootLeftWeaponAnimationNormalBTimer(0.07f);

	//	Get sockets
	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set index
		int indexProjectile = FMath::RandRange(0, this->m_leftWeaponSockets.Num() - 1);

		//	Define position and rotation
		FTransform transform;
		transform.SetLocation(skeletalMesh->GetSocketLocation(this->m_leftWeaponSockets[indexProjectile]));
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = this->m_targetPositionLastSight + littleVectorRandom;
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		if (m_bulletProjectileB != nullptr)
		{
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileB, transform);
			if (projectile != nullptr)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();
				projectile->m_velocity = velocity * 1000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				projectile->m_damage = this->m_baseDamage;
				projectile->m_speed = laserSpeed;
				projectile->m_lifetime = laserLifeTime;

				//	Finish spawn actor
				//transform.SetScale3D(FVector(2.0f));
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightWeaponB()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	float laserSpeed = 6.0f;
	float laserLifeTime = 0.3f;
	
	//	Set animation flag
	this->ShootRightWeaponAnimationNormalBTimer(0.07f);

	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set index
		int indexProjectile = FMath::RandRange(0, this->m_rightWeaponSockets.Num() - 1);

		//	Define position and rotation
		FTransform transform;
		transform.SetLocation(skeletalMesh->GetSocketLocation(this->m_rightWeaponSockets[indexProjectile]));
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = m_targetPositionLastSight + littleVectorRandom;
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		if (m_bulletProjectileB != nullptr)
		{
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileB, transform);
			if (projectile != nullptr)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();
				projectile->m_velocity = velocity * 1000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				projectile->m_damage = this->m_baseDamage;
				projectile->m_speed = laserSpeed;
				projectile->m_lifetime = laserLifeTime;

				//	Finish spawn actor
				//transform.SetScale3D(FVector(2.0f));
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftMachineGun()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Set animation flag
	this->ShootLeftWeaponAnimationSpinTimer(0.5f);

	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set origin
		FVector originPosition = skeletalMesh->GetSocketLocation(this->m_leftMachineGunSockets[0]);
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = this->m_targetPositionLastSight + littleVectorRandom;

		//	Trace ray and check if hit the hero robot
		FHitResult hitData(ForceInit);

		//	Check line of sight
		TArray<TEnumAsByte<EObjectTypeQuery>> objectsToTrace;
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(COLLISION_HERO));

		bool hit = UKismetSystemLibrary::LineTraceSingleForObjects(world, originPosition, targetPosition, objectsToTrace, false, TArray<AActor*>(), EDrawDebugTrace::None, hitData, true);
		if (hit)
		{
			ACustomRobot *hero = Cast<ACustomRobot>(hitData.Actor.Get());
			if (hero != nullptr)
			{
				if (!hero->m_shieldEnabled)
				{
					hero->ApplyDamage(m_baseDamage);
				}
#ifndef SHIPPING_GAME_VERSION
				print("Machine gun shoot Hero robot");
#endif  //SHIPPING_GAME_VERSION
			}
		}
	}


	/*
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh)
	{
		for (int i = 0; i < m_leftMachineGunSockets.Num(); i++)
		{
			//	Define position and rotation
			FTransform transform;
			transform.SetLocation(skeletalMesh->GetSocketLocation(m_leftMachineGunSockets[i]));
			FVector littleVectorRandom = FMath::VRand() * 80.0f;
			FVector targetPosition = m_targetPositionLastSight + littleVectorRandom;
			FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
			transform.SetRotation(rotation.Quaternion());

			//	Spawn a projetile
			if (m_bulletProjectileC == nullptr)
			{
				GAME_SHIPPING_LOG(GameShippingLog, "Unable to get nullptr m_bulletProjectileC");
				return;
			}
			UWorld *world = GetWorld();
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(m_bulletProjectileC, transform);
			if (projectile)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();
				projectile->m_velocity = velocity * 1000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				projectile->m_damage = m_baseDamage;
				projectile->m_speed = 3;
				projectile->m_lifetime = 1.5f;

				//	Finish spawn actor
				//transform.SetScale3D(FVector(2.0f));
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
	*/
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightMachineGun()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Set animation flag
	this->ShootRightWeaponAnimationSpinTimer(0.5f);

	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set origin
		FVector originPosition = skeletalMesh->GetSocketLocation(this->m_rightMachineGunSockets[0]);
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = this->m_targetPositionLastSight + littleVectorRandom;

		//	Trace ray and check if hit the hero robot
		FHitResult hitData(ForceInit);

		//	Check line of sight
		TArray<TEnumAsByte<EObjectTypeQuery>> objectsToTrace;
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(COLLISION_HERO));

		bool hit = UKismetSystemLibrary::LineTraceSingleForObjects(world, originPosition, targetPosition, objectsToTrace, false, TArray<AActor*>(), EDrawDebugTrace::None, hitData, true);
		if (hit)
		{
			ACustomRobot *hero = Cast<ACustomRobot>(hitData.Actor.Get());
			if (hero != nullptr)
			{
#ifndef SHIPPING_GAME_VERSION
				print("Machine gun shoot Hero robot");
#endif  //SHIPPING_GAME_VERSION
				if (!hero->m_shieldEnabled)
				{
					hero->ApplyDamage(m_baseDamage);
				}
			}
		}
	}
	
	/*
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh)
	{
		for (int i = 0; i < m_rightMachineGunSockets.Num(); i++)
		{
			//	Define position and rotation
			FTransform transform;
			transform.SetLocation(skeletalMesh->GetSocketLocation(m_rightMachineGunSockets[i]));
			FVector littleVectorRandom = FMath::VRand() * 80.0f;
			FVector targetPosition = m_targetPositionLastSight + littleVectorRandom;
			FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
			transform.SetRotation(rotation.Quaternion());

			//	Spawn a projetile
			if (m_bulletProjectileC == nullptr)
			{
				GAME_SHIPPING_LOG(GameShippingLog, "Unable to get nullptr m_bulletProjectileC");
				return;
			}
			UWorld *world = GetWorld();
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(m_bulletProjectileC, transform);
			if (projectile)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();
				projectile->m_velocity = velocity * 1000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				projectile->m_damage = m_baseDamage;
				projectile->m_speed = 3;
				projectile->m_lifetime = 1.5f;

				//	Finish spawn actor
				//transform.SetScale3D(FVector(2.0f));
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
	*/
}
#pragma endregion

//------------------------------------------------------------------------------------------------------------------
bool AEnemyRobot::CreateSplinePath()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Set transform
	FTransform transform;
	transform.SetLocation(FVector(0, 0, 0));

	//	Spawn spline path
	UWorld *world = this->GetWorld();
	if (this->m_splineFlyPath != nullptr && world != nullptr)
	{
		//	Trace ray to the ground
		FHitResult hitData(ForceInit);

		//	Check line of sight
		TArray<TEnumAsByte<EObjectTypeQuery>> objectsToTrace;
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(COLLISION_HERO));
		objectsToTrace.Add(UEngineTypes::ConvertToObjectType(COLLISION_ROBOT_ENEMY));

		bool hit = UKismetSystemLibrary::LineTraceSingleForObjects(world, this->GetActorLocation(), this->m_target->GetActorLocation(), objectsToTrace, false, TArray<AActor*>(), EDrawDebugTrace::None, hitData, true);
		if (hit)
		{
			AEnemyRobot *otherRobot = Cast<AEnemyRobot>(hitData.Actor.Get());
			if (otherRobot != nullptr)
			{
				//print("Behind other enemy robot");
			}
			else
			{
				//print("Skip fly because the hero is visible");
				return false;
			}
		}

		//	Create the fly spline
		this->m_splineFlyPathInstance = world->SpawnActor<AActor>(this->m_splineFlyPath, transform);
		if (this->m_splineFlyPathInstance != nullptr)
		{
			float distanceFromStartPoint = FMath::RandRange(600.0f, 2000.0f);
			float height = 3000.0f;
			this->m_splineCurrentDistance = 0;

			//	Check if final point is projected at navmesh
			FNavLocation NavLocation;
			FVector QueryingExtent = FVector(0, 0, 1000.0f);
			//Set you NavAgentProps properties here (radius, height, etc)
			//FNavAgentProperties *NavAgentProps;

			UNavigationSystem* const navigationSystem = world->GetNavigationSystem();
			if (navigationSystem != nullptr)
			{
				bool bProjectedLocationValid = false;

				//	Check valid location at nav mesh
				for (int32 i = 0; i < 10; i++)
				{
					//	Set random destination and subpoints
					//direction = FMath::VRand() * FVector(1.0f, 1.0f, 0);
					FVector direction = this->m_target->GetActorLocation() - this->GetActorLocation();
					direction.Normalize();
					direction *= distanceFromStartPoint;
					bProjectedLocationValid = navigationSystem->ProjectPointToNavigation(this->m_target->GetActorLocation() + direction, NavLocation, QueryingExtent);// , NavAgentProps);
#ifndef SHIPPING_GAME_VERSION
					DrawDebugLine(
						world,
						this->GetActorLocation(),
						this->GetActorLocation() + direction,
						FColor(255, 0, 0),
						false,
						5.0f, 10.0f);
#endif  //SHIPPING_GAME_VERSION

					if (bProjectedLocationValid)
					{
						break;
					}
					else if (i == 9 && !bProjectedLocationValid)
					{
						//	Destroy spline here in case there is not valid navmesh goal
						this->DestroySplinePath();
						return false;
					}
				}

				TArray<FVector> splinePoints;
				splinePoints.Add(GetActorLocation());
				splinePoints.Add(GetActorLocation() + FVector(0, 0, height));
				splinePoints.Add(NavLocation.Location + FVector(0, 0, height));
				splinePoints.Add(NavLocation.Location);

				//	Get spline component
				TArray<USplineComponent *> splineComponents;
				this->m_splineFlyPathInstance->GetComponents<USplineComponent>(splineComponents);
				for (auto i = 0; i < splineComponents.Num(); i++)
				{
					this->m_splineComponent = splineComponents[i];
					break;
				}

				//	Set point positions
				this->m_splineComponent->AddSplinePoint(FVector::ZeroVector, ESplineCoordinateSpace::World);
				this->m_splineComponent->AddSplinePoint(FVector::ZeroVector, ESplineCoordinateSpace::World);
				for (auto i = 0; i < splinePoints.Num(); i++)
				{
					this->m_splineComponent->SetLocationAtSplinePoint(i, splinePoints[i], ESplineCoordinateSpace::World);
				}

				this->m_splineLength = this->m_splineComponent->GetSplineLength();

				//splineComponent->SetTangentAtSplinePoint(0, FVector(1.0f, 1.0f, 1.0f), ESplineCoordinateSpace::World);
			}
		}
	}
	return true;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::DestroySplinePath() const
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	if (this->m_splineFlyPathInstance != nullptr)
	{
		this->m_splineFlyPathInstance->Destroy();
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetFly(bool enable)
{
	this->m_enableFly = enable;
	if (enable)
	{
		UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
		if (capsuleComponent != nullptr)
		{
			capsuleComponent->SetEnableGravity(false);
		}
		UCharacterMovementComponent *characterMovement = this->GetCharacterMovement();
		if (characterMovement != nullptr)
		{
			characterMovement->GravityScale = 0;
		}
	}
	else
	{
		UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
		if (capsuleComponent != nullptr)
		{
			capsuleComponent->SetEnableGravity(true);
		}
		UCharacterMovementComponent *characterMovement = this->GetCharacterMovement();
		if (characterMovement != nullptr)
		{
			characterMovement->GravityScale = 1.0f;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
float AEnemyRobot::GetNormalizedFlyDistance() const
{
	return this->m_splineCurrentDistance / this->m_splineLength;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::FlyJump()
{
	FVector direction = this->m_targetPositionLastSight - this->GetActorLocation();
	direction *= 0.5f;
	direction.Z = direction.Size();
	this->LaunchCharacter(direction, false, false);
	//this->Jump();
#ifndef SHIPPING_GAME_VERSION
	print("FlyJump");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::KillAfterSeconds()
{
	//  Destroy after few seconds
	if (this->m_enableActorDestruction)
	{
		this->m_timerManager->SetTimer(this->m_robotDestroyActorTimer, this, &AEnemyRobot::Kill, 5.0f, false);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::Kill()
{
	print("Robot killed");
	this->Destroy();
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::RemoveFromCrowdManager()
{
	//print("AEnemyRobot::RemoveFromCrowdManager");

	UWorld* world = this->GetWorld();
	AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
	if (gameMode != nullptr)
	{
		AEnemyCrowdManager *crowdManager = gameMode->GetEnemyCrowdManager();
		if (crowdManager != nullptr)
		{
			crowdManager->RemoveEnemyByIndexDescription(this->m_enemyCrowdManagerIndex);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::IncreaseDamageBonusToPlayer()
{
	if (this->m_isRare)
	{
		print("AEnemyRobot::IncreaseDamageBonusToPlayer");
		UWorld *world = this->GetWorld();
		if (world != nullptr)
		{
			ACustomRobot *hero = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(world, 0));
			if (hero != nullptr)
			{
				hero->IncreaseDamageFromRareKill(100.0f, 30.0f);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
bool AEnemyRobot::UpdateCheckForKill()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	//	Explode if current life is zero
	UWorld *world = this->GetWorld();
	this->m_currentEnergy = FMath::Clamp(this->m_currentEnergy, 0, this->m_maxEnergy);
	if (this->m_currentEnergy <= 0 && world != nullptr)
	{
		this->m_robotIsDead = true;
		this->m_timerManager->ClearAllTimersForObject(this);

		this->IncreaseDamageBonusToPlayer();
		this->RemoveFromCrowdManager();
		this->UpdateXPTable();
		this->UpdateKillCounter();
		this->PauseBrain();
		this->DisableCapsuleComponent();
		this->DisableCustomDepth();
		this->Explode();
		this->StopJetPack();
		this->StopMuzzleParticlesState();
		this->DestroySplinePath();
		this->ChangeToDeadFadeMaterials();
		this->RemoveDecals();
		this->KillAfterSeconds();

		//FVector location = this->GetActorLocation();
		//print(location.ToString());
		
		//	Remove from crowd manager
		//ARobotAIController *aiController = Cast<ARobotAIController>(this->GetController());
		//if (aiController != nullptr)
		//{
		//	UCrowdFollowingComponent *crowdFollowingComponent = Cast<UCrowdFollowingComponent>(aiController->GetPathFollowingComponent());
		//	if (crowdFollowingComponent != nullptr)
		//	{
		//		UCrowdManager *crowdManager = UCrowdManager::GetCurrent(GetWorld());
		//		if (crowdManager != nullptr)
		//		{
		//			const ICrowdAgentInterface* IAgent = Cast<ICrowdAgentInterface>(crowdFollowingComponent);
		//			if (IAgent != nullptr)
		//			{
		//				crowdManager->UnregisterAgent(IAgent);
		//				print("Unregister this AGENT WORKS");
		//			}
		//			// CrowdManager->UpdateAgentParams(IAgent);
		//			//crowdManager->RegisterAgent(this);
		//		}
		//	}
		//}

		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::Explode()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->StopJetPack();

	UWorld *world = this->GetWorld();
	if (this->m_enableKillParticleFX && world != nullptr)
	{
		//	Spawn particle explosion with instance parameters
		FTransform transform;
		transform.SetLocation(this->GetActorLocation());
		float angle = FMath::FRandRange(0, 360.0f);
		transform.SetRotation(FRotator(0, angle, 0).Quaternion());

		if (this->m_explosionBP != nullptr && this->m_explosionRareBP != nullptr)
		{
			AActor* explosion = nullptr;
			if (this->m_isRare)
			{
				explosion = world->SpawnActorDeferred<AActor>(this->m_explosionRareBP, transform);
			}
			else
			{
				explosion = world->SpawnActorDeferred<AActor>(this->m_explosionBP, transform);
			}

			if (explosion != nullptr)
			{
				UParticleSystemComponent *particleSystem = nullptr;
				TArray<UParticleSystemComponent *> particleSystemComponents;
				GetComponents<UParticleSystemComponent>(particleSystemComponents);
				if (particleSystemComponents.Num() > 0)
				{
					particleSystem = particleSystemComponents[0];
				}

				if (particleSystem != nullptr)
				{
					FParticleSysParam param;
					param.Name = FName("RobotActor");
					param.ParamType = EParticleSysParamType::PSPT_Actor;
					param.Actor = this;

					TArray<FParticleSysParam> params;
					params.Add(param);
					particleSystem->InstanceParameters = params;
				}

				//	Finish spawn actor
				UGameplayStatics::FinishSpawningActor(explosion, transform);
			}
		}
	}

	if (this->m_enableKillDestruction)
	{
		//	Create array of possibles bones to add force
		TArray<FName> boneNames;

		boneNames.Add(FName("j_foot_left"));
		boneNames.Add(FName("j_foot_right"));
		boneNames.Add(FName("j_pelvis_pivot"));
		boneNames.Add(FName("j_knee_inner_left"));
		boneNames.Add(FName("j_knee_inner_right"));

		//	Add force to random bones
		USkeletalMeshComponent *skeletalMesh = this->GetMesh();
		if (skeletalMesh != nullptr)
		{
			if (this->m_physicsAsset != nullptr)
			{
				skeletalMesh->SetPhysicsAsset(this->m_physicsAsset, false);
			}
			skeletalMesh->SetCollisionProfileName(FName("BlockAll"));
			skeletalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			skeletalMesh->SetCastShadow(false);
			skeletalMesh->SetSimulatePhysics(true);

			float rangeForce = 1000000.0f;
			UUtility::Array_Shuffle(boneNames);

			for (int i = 0; i < boneNames.Num() - 1; i++)
			{
				FVector force = FVector(FMath::FRandRange(-rangeForce, rangeForce), FMath::FRandRange(-rangeForce, rangeForce), 3000000.0f);
				FVector torque = FVector(FMath::FRandRange(-rangeForce, rangeForce), FMath::FRandRange(-rangeForce, rangeForce), FMath::FRandRange(-rangeForce, rangeForce));
				skeletalMesh->AddForce(force, boneNames[i]);
				skeletalMesh->AddTorque(torque, boneNames[i]);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::DisableCapsuleComponent()
{
	//	Disable Capsule collider
	UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
	if (capsuleComponent != nullptr)
	{
		capsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::DisableCustomDepth()
{
	//	Disable custom depth and change collistion type 
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr)
	{
		skeletalMesh->SetRenderCustomDepth(false);
		skeletalMesh->SetCollisionProfileName(FName("Destructible"));
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::UpdateXPTable()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		//	Update xp table for this robot
		bool enableDrop = false;
		bool enableSecrets = false;
		AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			enableDrop = gameMode->m_enableDropFromEnemies;
			enableSecrets = gameMode->m_enableSecrets;
			gameMode->m_robotsDestroyed++;
			gameMode->NotifySpawerIncrementDeadEnemies();
			if (gameMode->m_enableXPFromEnemies)
			{
				//gameMode->TickEnemiesCountAchievements();
				//gameMode->TickHeroLevelProgression(this->m_experience);
			}
		}
		return;
#ifdef ENEMIES_SPAWN_LOOT
		if (enableDrop)
		{
			this->SpawnLoot();
		}
		if (enableSecrets)
		{
			this->SpawnPortal_A();
		}
#endif
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::UpdateKillCounter()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		//	Update enemies killed counter
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			//	Write google analytics statistics
			gameInstance->m_analyticsEventQueue->AppendToEventQueueKillEnemy(EEnemyType::ET_Robot);

			//	Write steam cloud progression
			gameInstance->m_enemiesKilledLastFrame++;
			gameInstance->m_heroProgression->AddEnemiesKilled(1);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ChangeToDeadFadeMaterials() const
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		float currentTimeInSeconds = world->GetTimeSeconds();
		class USkeletalMeshComponent *skeletalMesh = this->GetMesh();
		if (skeletalMesh != nullptr)
		{
			if (this->m_materialInstanceDynamicBodyDeadFade != nullptr)
			{
				this->m_materialInstanceDynamicBodyDeadFade->SetScalarParameterValue(FName(TEXT("InitialTime")), currentTimeInSeconds);
				skeletalMesh->SetMaterial(7, this->m_materialInstanceDynamicBodyDeadFade);
			}
			if (this->m_materialInstanceDynamicPipeDeadFade != nullptr)
			{
				this->m_materialInstanceDynamicPipeDeadFade->SetScalarParameterValue(FName(TEXT("InitialTime")), currentTimeInSeconds);
				for (int32 i = 0; i < 7; i++)
				{
					skeletalMesh->SetMaterial(i, this->m_materialInstanceDynamicPipeDeadFade);
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::RemoveDecals() const
{
	//	Remove Decal
	TArray<UDecalComponent *> decalComponents;
	this->GetComponents<UDecalComponent>(decalComponents);
	if (decalComponents.Num() > 0)
	{
		for (int32 i = decalComponents.Num() - 1; i >= 0; i--)
		{
			decalComponents[i]->DestroyComponent();
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftWeaponAnimationNormalATimer(float duration)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_isShootingArmLeftWeaponNormalA = true;
	this->m_timerManager->SetTimer(this->m_shootLeftWeaponAnimationNormalATimer, this, &AEnemyRobot::StopLeftWeaponAnimationNormalA, duration, false);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopLeftWeaponAnimationNormalA()
{
	this->m_isShootingArmLeftWeaponNormalA = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightWeaponAnimationNormalATimer(float duration)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_isShootingArmRightWeaponNormalA = true;
	this->m_timerManager->SetTimer(this->m_shootRightWeaponAnimationNormalATimer, this, &AEnemyRobot::StopRightWeaponAnimationNormalA, duration, false);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopRightWeaponAnimationNormalA()
{
	this->m_isShootingArmRightWeaponNormalA = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftWeaponAnimationNormalBTimer(float duration)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_isShootingArmLeftWeaponNormalB = true;
	this->m_timerManager->SetTimer(this->m_shootLeftWeaponAnimationNormalBTimer, this, &AEnemyRobot::StopLeftWeaponAnimationNormalB, duration, false);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopLeftWeaponAnimationNormalB()
{
	this->m_isShootingArmLeftWeaponNormalB = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightWeaponAnimationNormalBTimer(float duration)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_isShootingArmRightWeaponNormalB = true;
	this->m_timerManager->SetTimer(this->m_shootRightWeaponAnimationNormalBTimer, this, &AEnemyRobot::StopRightWeaponAnimationNormalB, duration, false);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopRightWeaponAnimationNormalB()
{
	this->m_isShootingArmRightWeaponNormalB = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftWeaponAnimationSpinTimer(float duration)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_isShootingArmLeftWeaponSpin = true;
	this->m_timerManager->SetTimer(this->m_shootLeftWeaponAnimationSpinTimer, this, &AEnemyRobot::StopLeftWeaponAnimationSpin, duration, false);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopLeftWeaponAnimationSpin()
{
	this->m_isShootingArmLeftWeaponSpin = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightWeaponAnimationSpinTimer(float duration)
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	this->m_isShootingArmRightWeaponSpin = true;
	this->m_timerManager->SetTimer(this->m_shootRightWeaponAnimationSpinTimer, this, &AEnemyRobot::StopRightWeaponAnimationSpin, duration, false);
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopRightWeaponAnimationSpin()
{
	this->m_isShootingArmRightWeaponSpin = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::UpdateMovementSpeed(float multiplier)
{
	//	Set movement speed
	//	Base speed == 500
	//	Walk animation ratio  = 1.85

	UCharacterMovementComponent *characterMovement = this->GetCharacterMovement();
	if (characterMovement != nullptr)
	{
		this->m_movementSpeedMultiplier = multiplier;
		this->GetCharacterMovement()->MaxWalkSpeed = this->m_movementSpeed * this->m_movementSpeedMultiplier;
		this->GetCharacterMovement()->bUseRVOAvoidance = false;
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootLeftMissile()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set index
		int indexMissile = FMath::RandRange(0, this->m_leftMissileSockets.Num() - 1);

		//	Define position and rotation
		FTransform transform;
		transform.SetLocation(skeletalMesh->GetSocketLocation(this->m_leftMissileSockets[indexMissile]));
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = this->m_targetPositionLastSight + littleVectorRandom;
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		if (this->m_missile != nullptr)
		{
			AMissile* missile = world->SpawnActorDeferred<AMissile>(this->m_missile, transform);
			if (missile != nullptr)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();

				//	Get hero position
				//ACustomRobot *hero = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
				//if (hero == nullptr)
				//{
				//	GAME_SHIPPING_LOG(GameShippingLog, "Unable to get nullptr ACustomRobot");
				//	return;
				//}
				missile->m_hitPosition = this->m_target->GetActorLocation();
				missile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				missile->m_damage = this->m_baseDamage;

				//projectile->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
				//projectile->m_velocity = velocity * 1000.0f;
				//projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				//projectile->m_damage = m_damage;

				//	Finish spawn actor
				UGameplayStatics::FinishSpawningActor(missile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::ShootRightMissile()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	UWorld *world = this->GetWorld();
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr && world != nullptr)
	{
		//	Set index
		int indexMissile = FMath::RandRange(0, this->m_rightMissileSockets.Num() - 1);

		//	Define position and rotation
		FTransform transform;
		transform.SetLocation(skeletalMesh->GetSocketLocation(this->m_rightMissileSockets[indexMissile]));
		FVector littleVectorRandom = FMath::VRand() * 80.0f;
		FVector targetPosition = this->m_targetPositionLastSight + littleVectorRandom;
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transform.GetLocation(), targetPosition);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		if (this->m_missile != nullptr)
		{
			AMissile* missile = world->SpawnActorDeferred<AMissile>(this->m_missile, transform);
			if (missile != nullptr)
			{
				FVector velocity = targetPosition - transform.GetLocation();
				//velocity.Z = 0;
				velocity.Normalize();

				//	Get hero position
				//ACustomRobot *hero = Cast<ACustomRobot>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
				//if (hero == nullptr)
				//{
				//	GAME_SHIPPING_LOG(GameShippingLog, "Unable to get nullptr ACustomRobot");
				//	return;
				//}
				missile->m_hitPosition = this->m_target->GetActorLocation();
				missile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				missile->m_damage = this->m_baseDamage;

				//projectile->m_velocity = velocity * 1000.0f;
				//projectile->m_weaponOwner = EWeaponOwner::WO_Enemy;
				//projectile->m_damage = m_damage;

				//	Finish spawn actor
				UGameplayStatics::FinishSpawningActor(missile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::OpenMissilePack()
{
	this->m_isShootingMissile = true;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::CloseMissilePack()
{
	this->m_isShootingMissile = false;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StartJetPack()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	if (this->m_leftJetPackParticleSystem != nullptr && this->m_rightJetPackParticleSystem != nullptr)
	{
		this->m_jetPackEnable = true;
		this->m_leftJetPackParticleSystem->SetFloatParameter(FName("Rate"), 500.0f);
		this->m_rightJetPackParticleSystem->SetFloatParameter(FName("Rate"), 500.0f);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopJetPack()
{
#ifdef ENEMIES_LOG
	GAME_TRACKING_LOG(EnemiesLog);
#endif	//ENEMIES_LOG

	if (this->m_leftJetPackParticleSystem != nullptr && this->m_rightJetPackParticleSystem != nullptr)
	{
		this->m_jetPackEnable = false;
		this->m_leftJetPackParticleSystem->SetFloatParameter(FName("Rate"), 0);
		this->m_rightJetPackParticleSystem->SetFloatParameter(FName("Rate"), 0);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetMuzzleParticlesState(bool enabled, float delay)
{
	//float rate = 0;
	if (enabled)
	{
		this->m_timerManager->SetTimer(this->m_muzzleParticlesTimer, this, &AEnemyRobot::StartMuzzleParticlesState, delay, false);
	}
	else
	{
		this->StopMuzzleParticlesState();
		//m_timerManager->SetTimer(m_muzzleParticlesTimer, this, &AEnemyRobot::StopMuzzleParticlesState, delay, false);
		//m_timerManager->SetTimer(m_muzzleParticlesTimer, this, &AEnemyRobot::StopMuzzleParticlesState, delay, false);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StartMuzzleParticlesState() const
{
	if (this->m_muzzleLeftParticleSystem != nullptr && this->m_muzzleRightParticleSystem != nullptr)
	{
		this->m_muzzleLeftParticleSystem->SetFloatParameter(FName("Rate"), 100.0f);
		this->m_muzzleRightParticleSystem->SetFloatParameter(FName("Rate"), 100.0f);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopMuzzleParticlesState() const
{
	if (this->m_muzzleLeftParticleSystem != nullptr && this->m_muzzleRightParticleSystem != nullptr)
	{
		this->m_muzzleLeftParticleSystem->SetFloatParameter(FName("Rate"), 0);
		this->m_muzzleRightParticleSystem->SetFloatParameter(FName("Rate"), 0);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetLookAtState(bool state)
{
	this->m_enableLookAt = state;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetCurrentBehavior(ERobotBehavior behavior)
{
	this->m_currentRobotBehavior = behavior;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::PrepateToShootArmWeapon(bool state)
{
	this->m_isPrepareToShootArmWeapon = state;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SetShootAtSameSpot(int32 value)
{
	this->m_maxShootAtSameSpot = value;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::UpdateShootAtSameSpot()
{
	this->m_maxShootAtSameSpot--;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StartTorsoLookAt()
{
	this->m_enableTorsoLookAt = true;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopTorsoLookAt()
{
	this->m_enableTorsoLookAt = false;
}

//------------------------------------------------------------------------------------------------------------------
float AEnemyRobot::GetTorsoLookAtRotation() const
{
	//m_enableTorsoLookAt = true;

	//	Get current bone rotation
	FRotator actorRotation = this->GetActorRotation();

	//	Get hero Vector
	FVector targetPosition = this->m_targetPositionLastSight;
	FVector position = this->GetActorLocation();
	position.Z = targetPosition.Z;
	FRotator desiredRotation = UKismetMathLibrary::FindLookAtRotation(position, targetPosition);
	float angle = desiredRotation.Yaw - actorRotation.Yaw;

	//	Force disable
	//if (FMath::Abs(angle) > 90.0f)
	//{
	//	angle = FMath::Clamp(angle, -90.0f, 90.0f);
	//	m_enableTorsoLookAt = false;
	//	//StopShootWeaponA();
	//}
	return angle;
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StartShootWeaponA()
{
	if (this->m_timerManager != nullptr)
	{
		this->m_timerManager->SetTimer(this->m_shootLeftWeaponATimer, this, &AEnemyRobot::ShootLeftWeaponA, 0.2f, true, 0);
		this->m_timerManager->SetTimer(this->m_shootRightWeaponATimer, this, &AEnemyRobot::ShootRightWeaponA, 0.2f, true, 0.1f);
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::StopShootWeaponA()
{
	if (this->m_timerManager != nullptr)
	{
		if (this->m_timerManager->IsTimerActive(this->m_shootLeftWeaponATimer))
		{
			this->m_timerManager->ClearTimer(this->m_shootLeftWeaponATimer);
		}
		if (this->m_timerManager->IsTimerActive(this->m_shootRightWeaponATimer))
		{
			this->m_timerManager->ClearTimer(this->m_shootRightWeaponATimer);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnLoot() const
{
	bool enableSpawnLoot = false;
#ifdef SHIPPING_GAME_VERSION
	//	Spawn based on difficult
	float chance = FMath::FRand();
	switch (this->m_robotDifficult)
	{
	case EEnemyDifficult::ED_Easy:
		if (chance < 0.05f)
		{
			enableSpawnLoot = true;
		}
		break;
	case EEnemyDifficult::ED_Normal:
		if (chance < 0.1f)
		{
			enableSpawnLoot = true;
		}
		break;
	case EEnemyDifficult::ED_Hard:
		if (chance < 0.15f)
		{
			enableSpawnLoot = true;
		}
		break;
	}
#else
	enableSpawnLoot = true;
#endif
		
	UWorld* world = this->GetWorld();
	if (enableSpawnLoot && world != nullptr)
	{
		const UNavigationSystem* navigationSystem = world->GetNavigationSystem();
		if (navigationSystem != nullptr)
		{
			FNavLocation NavLocation;
			FVector QueryingExtent = FVector(0, 0, 1000.0f);
			bool bProjectedLocationValid = navigationSystem->ProjectPointToNavigation(this->GetActorLocation(), NavLocation, QueryingExtent);// , NavAgentProps);
#ifndef SHIPPING_GAME_VERSION
			FVector direction = FVector(0, 0, -1000.0f);
			DrawDebugLine(
				world,
				this->GetActorLocation(),
				this->GetActorLocation() + direction,
				FColor(255, 0, 0),
				false,
				5.0f, 10.0f);
#endif // SHIPPING_GAME_VERSION

			if (bProjectedLocationValid)
			{
				AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
				if (gameMode != nullptr)
				{
					ASpawner *spawner = gameMode->GetSpawner();
					if (spawner != nullptr) {
						FTransform transform;
						transform.SetLocation(NavLocation.Location);
						world->SpawnActor<AActor>(spawner->m_lootBase, transform);
					}
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_A() const
{
	//#ifdef SHIPPING_GAME_VERSION
//	int32 chanceToSpawnPortal = FMath::RandRange(0, 1000);
//#else
//	int32 chanceToSpawnPortal = 0;// FMath::RandRange(0, 10);
//#endif // SHIPPING_GAME_VERSION

	UWorld* world = this->GetWorld();
	if (world != nullptr)
	{
		for (TActorIterator<APortal> ActorItr(world); ActorItr; ++ActorItr)
		{
			APortal *portal = *ActorItr;
			if (portal != nullptr)
			{
				if (portal->m_portalType == EPortalType::PT_PortalRed)
				{
					return;
				}
			}
		}

		if (this->m_isRare)
		{
			//	TODO: spawn some FX quando o portal aparece
			if (this->m_portal_A != nullptr)
			{
				//	Snap to navmesh
				const UNavigationSystem* navigationSystem = world->GetNavigationSystem();
				if (navigationSystem != nullptr)
				{
					FNavLocation NavLocation;
					FVector QueryingExtent = FVector(0, 0, 1000.0f);
					bool bProjectedLocationValid = navigationSystem->ProjectPointToNavigation(this->GetActorLocation(), NavLocation, QueryingExtent);
					if (bProjectedLocationValid)
					{
						FTransform transform;
						transform.SetLocation(NavLocation.Location);
						transform.SetScale3D(FVector(2.0f));
						APortal *portal = world->SpawnActor<APortal>(this->m_portal_A, transform);
						if (portal != nullptr)
						{
#ifndef SHIPPING_GAME_VERSION
							print("AEnemyRobot::SpawnPortal_A");
#endif  //SHIPPING_GAME_VERSION

							//	Write statistics for google analytics
							UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
							if (gameInstance != nullptr)
							{
								gameInstance->m_analyticsEventQueue->AppendToEventQueueSecret(FString("Portal_A"));
							}
							//AGoogleAnalytics::RegisterEventSecret(FString("Portal_A"));
						}
					}
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_B() const
{
	//	TODO: this portal is opened by have weapon level 1 equipped and the robot must be level 2 and higher the resulting portal have 200% more drops from robots
	//	The portal level will have a thousand of crate em high level damage robots the 3 robots Red, green blue, like in 3 scale size
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_A");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_C() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 400% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_C");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_D() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 600% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_D");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_E() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 800% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_E");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_F() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 1000% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_F");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_G() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 1200% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_G");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_H() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 1400% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_H");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::SpawnPortal_I() const
{
	//	TODO: Define spawn condition
	//	The resulting portal have 2000% more drops from robots
#ifndef SHIPPING_GAME_VERSION
	print("AEnemyRobot::SpawnPortal_I");
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
void AEnemyRobot::PlayRobotSound()
{
	if (this->m_audioComponent != nullptr && !this->m_robotIsDead && !this->m_isFlying)
	{
		if (!this->m_audioComponent->IsPlaying())
		{
			this->m_audioComponent->Play();
		}
	}
}
