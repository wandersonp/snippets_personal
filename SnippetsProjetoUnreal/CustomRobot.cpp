//==================================================================================================================
//
//	File:	CustomRobot.cpp
//	Date:	15-11-2016
//	Author:	wandersonp@gmail.com
//
//	Description:    
//
//==================================================================================================================

//	TODO: Remover todas as fun�oes de Loot e equipamento

#include "CustomGame.h"
#include "CustomRobot.h"
#include "Weapon/BulletProjectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#pragma region UE4
//------------------------------------------------------------------------------------------------------------------
ACustomRobot::ACustomRobot(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->PrimaryActorTick.bStartWithTickEnabled = true;
	this->bUseControllerRotationPitch = false;
	this->bUseControllerRotationYaw = true;
	this->bUseControllerRotationRoll = false;

	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->GetCharacterMovement()->RotationRate = FRotator(0.f, 10.f, 0.f);
	this->OnActorBeginOverlap.AddDynamic(this, &ACustomRobot::ActorBeginOverlap);
	this->GetCapsuleComponent()->SetRelativeRotation(FRotator(0, 90.0f, 0));

	//	Load camera shake
	static ConstructorHelpers::FClassFinder<UCameraShake> cameraShakeClass(TEXT("/Game/PrototipoGame/Asset/Utils/BP_CameraShake"));
	if (cameraShakeClass.Succeeded())
	{
		this->m_cameraShake = cameraShakeClass.Class;
	}

	this->m_heroDynamicSkills = ObjectInitializer.CreateDefaultSubobject<UHeroDynamicSkills>(this, TEXT("HeroSkills"));
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::BeginPlay()
{
	Super::BeginPlay();
	this->InitializeVars();
	this->InitializeOnlineVars();
	this->InitializeCustomComponents();
	this->InitializeTimers();
	this->InitializeEquipment();
	this->InitializeMaterials();
	this->InitializeSkills();
	this->InitializeGameplayOptions();
	this->InitializeCheatCodes();

	this->m_heroStat.m_finalDamage = 50000000;
	this->m_heroStat.m_attackSpeedBonus = 100;
	this->m_heroStat.m_attackSpeedWeapon = 500;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	this->m_deltaTime = deltaTime;
	this->TickRobot();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetupPlayerInputComponent(class UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

	inputComponent->BindAxis("MoveForward", this, &ACustomRobot::MoveForward);
	inputComponent->BindAxis("MoveRight", this, &ACustomRobot::MoveRight);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ActorBeginOverlap(class AActor* thisActor, class AActor* otherActor)
{
	//	Check if class is a projectile from enemy
	if (otherActor->IsA(ABulletProjectile::StaticClass()))
	{
		ABulletProjectile *projectile = Cast<ABulletProjectile>(otherActor);
		if (projectile != nullptr)
		{
			if (projectile->m_weaponOwner == EWeaponOwner::WO_Enemy)
			{
				//	Check if shield is disabled
				if (!this->m_isActiveShieldPowerUp)
				{
					this->ApplyDamage(projectile);
					projectile->Destroy();
				}
			}
		}
	}

	//	Check if class is a projectile from enemy
	if (otherActor->IsA(AMissile::StaticClass()))
	{
		AMissile *missile = Cast<AMissile>(otherActor);
		if (missile != nullptr)
		{
			if (missile->m_weaponOwner == EWeaponOwner::WO_Enemy)
			{
				//	Check if shield is disabled
				if (!this->m_isActiveShieldPowerUp)
				{
					this->ApplyDamage(missile);
				}
			}
		}
	}

	//	Check if is powerUps
	if (otherActor->IsA(APowerUp::StaticClass()))
	{
		APowerUp *powerUp = Cast<APowerUp>(otherActor);
		if (powerUp != nullptr)
		{
			switch (powerUp->m_powerUPType)
			{
			case EPowerUPType::PU_Shield:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementShieldLevelStackAmount();
				//this->m_shieldMaxActiveTime = powerUp->m_maxActiveTime;
				//if (this->m_isActiveIncreaseDamagePowerUp)
				//{
				//	this->AcumulateShieldPowerUp(this->m_forceFieldMaxActiveTime);
				//}
				//else
				//{
				//	this->EnableShieldPowerUp(this->m_forceFieldMaxActiveTime);
				//}
				break;
			
			case EPowerUPType::PU_FullBattery:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementFullBatteryLevelStackAmount();
				//this->m_currentEnergy += static_cast<int>(powerUp->m_powerUpValue);
				break;
			
			case EPowerUPType::PU_ArmyOfHeroes:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementArmyOfHeroesLevelStackAmount();
				break;
			
			case EPowerUPType::PU_ForceField:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementForceFieldLevelStackAmount();
				//this->m_forceFieldMaxActiveTime = powerUp->m_maxActiveTime;
				//if (this->m_isActiveIncreaseDamagePowerUp)
				//{
				//	this->AcumulateForceFieldPowerUp(this->m_forceFieldMaxActiveTime);
				//}
				//else
				//{
				//	this->EnableForceFieldPowerUp(this->m_forceFieldMaxActiveTime);
				//}
				break;

			case EPowerUPType::PU_IncreaseDamage:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementIncreaseDamageLevelStackAmount();
				break;
			
			case EPowerUPType::PU_IncreaseMovementSpeed:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementIncreaseMovementSpeedStackAmount();
				break;
		
			case EPowerUPType::PU_TimeWarp:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementTimeWarpLevelStackAmount();
				break;

			case EPowerUPType::PU_IncreaseEnergy:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->IncrementIncreaseEnergyStackAmount();
				break;

				//	TODO: make this only instant loot without skill activation button
			case EPowerUPType::PU_EnergyRegeneration:
				this->PlayPowerUpPickupSoundFX();
				this->SpawnPowerUpPickupFX();
				this->PlayEnergyRegenerationPowerUpWidget();
				break;
			}
		}
	}
}
#pragma region

#pragma region INITIALIZE
//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeVars()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->InitializeSkills(this);
	}
	
	this->m_PEMSkillType = EPEMSkillType::PST_Destruction;

	//	Default
	UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (gameInstance != nullptr)
	{
		//	TODO: how to do safe godmode
		this->m_godMode.SetValue(false);// gameInstance->GetGodMode();
	}
	
	this->m_heroIsDead = false;
	this->m_showEnergyBar = true;
	this->m_baseEnergy = 100;
	this->m_currentEnergy = this->m_baseEnergy;
	this->m_maxEnergy = this->m_baseEnergy;
	this->m_baseDamage = 10;
	this->m_finalDamage = this->m_baseDamage;
	this->m_xMovement = 0;
	this->m_yMovement = 0;
	this->m_fractionTimeSeconds = 0;
	this->m_baseTurnRate = 45.0f;
	this->m_enableWalk = true;
	this->m_height = 300.0f;
	this->m_aimCursorSpeed = 10.0f;
	this->m_aimCursorScreenPosition = FVector2D::ZeroVector;
	this->m_aimCursorLocked = false;
	this->m_aimCursorWorldPosition = FVector::ZeroVector;
	this->m_aimCursorLastWorldPosition = FVector::ZeroVector;
	this->m_shieldDelay = 5.0f;
	this->m_armyOfHeroesDelay = 30.0f;
	this->m_timeWarpDelay = 5.0f;
	this->m_increaseDamageDelay = 60.0f;
	this->m_increaseEnergyDelay = 60.0f;
	this->m_increaseMovementSpeedDelay = 60.0f;


	this->m_isIncreaseDamageFromRareKill = false;

	//	Skills
	this->m_primarySkillActivationTimer = 0.0f;
	this->m_primarySkillMaxTimeToNormalBlast = 0.1f;
	this->m_primarySkillMaxTimeToHyperBlast = 3.0f;
	this->m_damageReductionByFullBatterySkill = 0;
	this->m_increaseDamageByFullBatterySkill = 0;
	this->m_increaseMovementSpeedFullBatterySkill = 0;

	//	Weapon
	this->m_leftWeaponDelay = 0.05f;
	this->m_rightWeaponDelay = 0.05f;

		//	PowerUps
	this->m_isActiveShieldPowerUp = false;
	this->m_isActiveArmyOfHeroesPowerUp = false;
	this->m_isActiveTimeWarpPowerUp = false;
	this->m_isActiveIncreaseDamagePowerUp = false;
	this->m_isActiveIncreaseEnergyPowerUp = false;
	this->m_isActiveIncreaseMovementSpeedPowerUp = false;

	this->m_increaseDamageMaxActiveTime = 0;
	this->m_forceFieldMaxActiveTime = 0;
	this->m_increaseMovementSpeedMaxActiveTime = 0;
	this->m_shieldMaxActiveTime = 0;
	this->m_timeWarpMaxActiveTime = 0;

	//	Movement
	this->m_baseMovementSpeed = 1000.0f;

	//	Allies
	this->m_armyOfHeroesAllyes.Init(nullptr, 4);

//#ifndef SHIPPING_GAME_VERSION
	//	movement speed debugMode
	if (this->m_enableDebugSuperSpeed)
	{
		UCharacterMovementComponent *characterMovement = this->GetCharacterMovement();
		if (characterMovement != nullptr)
		{
			characterMovement->MaxWalkSpeed = 10000.0f;
		}
	}
//#endif	//SHIPPING_GAME_VERSION	

	//	Debug only
	this->m_enableDeath = false;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeOnlineVars()
{
	this->m_maxDronesAllyEarned = 10;
	this->m_maxRobotsAllyEarned = 3;
	this->m_currentLevel = 1;
	this->m_currentXPForThisLevel = 0;
	this->m_maxXPForThisLevel = 1000;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeCustomComponents()
{
	TArray<UChildActorComponent *> chieldComponents;
	this->GetComponents<UChildActorComponent>(chieldComponents);
	for (auto i = 0; i < chieldComponents.Num(); i++)
	{
		//	Get weapon sockets
		FString name = chieldComponents[i]->GetName();
		if (name == FString("rightWeapon"))
		{
			this->m_rightWeaponSocket = chieldComponents[i];
			continue;
		}
		if (name == FString("leftWeapon"))
		{
			this->m_leftWeaponSocket = chieldComponents[i];
			continue;
		}

		//	TODO: REMOVER ISTO
		//	Get surround targets
		if (name.Contains(FString("surroundTarget_")))
		{
			this->m_surroundHiddenTargets.Add(chieldComponents[i]->GetChildActor());
		}
	}

	//	Get shield mesh component
	TArray<UStaticMeshComponent *> meshComponent;
	this->GetComponents<UStaticMeshComponent>(meshComponent);
	for (auto i = 0; i < meshComponent.Num(); i++)
	{
		FString name = meshComponent[i]->GetName();
		if (name == FString("shieldMesh"))
		{
			this->m_shieldMeshComponent = meshComponent[i];
			break;
		}
	}

	//	Get widget component
	TArray<UWidgetComponent *> widgetComponenst;
	this->GetComponents<UWidgetComponent>(widgetComponenst);
	if (widgetComponenst.Num() > 0)
	{
		this->m_healthBarWidgetComponent = widgetComponenst[0];
	}

	//	Get particles system components
	TArray<UParticleSystemComponent *> particleSystemComponenst;
	this->GetComponents<UParticleSystemComponent>(particleSystemComponenst);
	if (particleSystemComponenst.Num() > 0)
	{
		for (auto i = 0; i < particleSystemComponenst.Num(); i++)
		{
			FString name = particleSystemComponenst[i]->GetName();
			if (name == FString("fullBatteryParticleSystem"))
			{
				this->m_fullBatteryParticleSystemComponent = particleSystemComponenst[i];
				break;
			}
		}
	}

	//	Get shield alembic
	TArray<UGeometryCacheComponent *> geometryCaches;
	this->GetComponents<UGeometryCacheComponent>(geometryCaches);
	if (geometryCaches.Num() > 0)
	{
		for (auto i = 0; i < geometryCaches.Num(); i++)
		{
			FString name = geometryCaches[i]->GetName();
			if (name == FString("shieldGeometryCache"))
			{
				this->m_shieldGeometryCacheComponent = geometryCaches[i];
				break;
			}
		}
	}

	//	Spawn keyboard hint
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			if (gameInstance->GetShowKeyboardHint())
			{
				this->SpawnKeyboardHint(world);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeTimers()
{
	this->m_timerManager = &this->GetWorldTimerManager();
	if (this->m_timerManager != nullptr)
	{
		this->m_timerManager->SetTimer(this->m_alliesRefreshTimer, this, &ACustomRobot::RefreshAllies, 3.0f, true);
		this->m_timerManager->SetTimer(this->m_refreshAllyTargetsTimer, this, &ACustomRobot::RefreshAllyTargets, 2.0f, true);
	}

	//	TODO: check energy regen as powerup
	//m_timerManager->SetTimer(m_energyRegenTimer, this, &ACustomRobot::EnergyRegeneration, 0.5f, true, 0);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeEquipment()
{
	//	TODO: remove loot equipment for this game
	this->m_equipment.Init(FLootInfo(), 5);
	this->m_heroStat = FHeroStat();
	//for (int i = 0; i < 5; i++)
	//{
	//	m_equipment.Add(FLootInfo());
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeMaterials()
{
	//	Default skill colors
	this->m_shieldColor = FLinearColor(0.75f, 0.07f, 0, 1.0f);
	this->m_primarySkillColor = FLinearColor(1.0, 0.136f, 0, 1.0f);

	//	Body color
	if (this->m_heroMaterialParameterCollection != nullptr)
	{
		UWorld *world = this->GetWorld();
		if (world != nullptr)
		{
			UKismetMaterialLibrary::SetVectorParameterValue(world, this->m_heroMaterialParameterCollection, FName("ShieldColor"), this->m_shieldColor);
			UKismetMaterialLibrary::SetVectorParameterValue(world, this->m_heroMaterialParameterCollection, FName("PrimarySkillColor"), this->m_primarySkillColor);
		}
	}

	//	Setup material damage blink and robot color based on character configuration
	USkeletalMeshComponent *skeletalMeshBody = this->GetMesh();
	if (skeletalMeshBody != nullptr)
	{
		UMaterialInterface *bodyMaterial = skeletalMeshBody->GetMaterial(7);
		if (bodyMaterial != nullptr)
		{
			this->m_heroMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(bodyMaterial, this);
			if (this->m_heroMaterialInstanceDynamic != nullptr)
			{
				this->m_heroMaterialInstanceDynamic->SetVectorParameterValue(FName("RobotColor"), FLinearColor(1.0f, 0.082f, 0, 1.0f));
				skeletalMeshBody->SetMaterial(7, this->m_heroMaterialInstanceDynamic);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeSkills()
{
	this->m_maxSkillStackAmount = 900;
	this->m_shieldLevelAmount = 1;
	this->m_fullBatteryLevelAmount = 1;
	this->m_armyOfHeroesLevelAmount = 1;
	this->m_forceFieldLevelAmount = 1;
	this->m_timeWarpLevelAmount = 1;
	this->m_increaseDamageLevelAmount = 1;
	this->m_increaseEnergyLevelAmount = 1;
	this->m_increaseMovementSpeedLevelAmount = 1;

	this->m_shieldCooldown = 5.0f;
	this->m_fullBatteryCooldown = 5.0f;
	this->m_armyOfHeroesCooldown = 5.0f;
	this->m_forceFieldCooldown = 5.0f;
	this->m_plasmaGunCooldown = 0.5f;
	this->m_teleportCooldown = 0.5f;
	this->m_timewarpCooldown = 5.0f;
	this->m_increaseDamageCooldown = 5.0f;
	this->m_increaseEnergyCooldown = 5.0f;
	this->m_increaseMovementSpeedCooldown = 5.0f;

	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			bool unlocked = false;

			for (int32 i = 0; i < 3; i++)
			{
				if (i == 0)
				{
					unlocked = true;
				}
				else
				{
					unlocked = false;
				}

				this->m_primarySkillsUnlocked.Add(unlocked);
				this->m_secondarySkillsUnlocked.Add(unlocked);
				this->m_shieldSkillsUnlocked.Add(unlocked);
				this->m_fullBatterySkillsUnlocked.Add(unlocked);
				this->m_armyOfHeroesSkillsUnlocked.Add(unlocked);
				this->m_pemSkillsUnlocked.Add(unlocked);
			}

			if (gameInstance->m_heroProgression != nullptr)
			{
				this->m_currentLevel = gameInstance->m_heroProgression->GetCurrentLevel();

				//	TODO: Check if sub skills will be used in this game
				if (this->m_currentLevel >= 2)
				{
					this->m_primarySkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 4) 
				{
					this->m_secondarySkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 6)
				{
					this->m_shieldSkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 8)
				{
					this->m_fullBatterySkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 10)
				{
					this->m_armyOfHeroesSkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 12)
				{
					this->m_pemSkillsUnlocked[1] = true;
				}

				if (this->m_currentLevel >= 14) 
				{
					this->m_primarySkillsUnlocked[2] = true; 
				}
				if (this->m_currentLevel >= 16)
				{
					this->m_secondarySkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 18)
				{
					this->m_shieldSkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 20)
				{
					this->m_fullBatterySkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 22)
				{
					this->m_armyOfHeroesSkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 24)
				{
					this->m_pemSkillsUnlocked[2] = true;
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeGameplayOptions()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		this->m_cameraShakeState = false;
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			this->m_cameraShakeState = gameInstance->GetCameraShake();
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::InitializeCheatCodes()
{
	UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (gameInstance != nullptr)
	{
		this->m_heroName = gameInstance->GetCurrentHeroName();

		if (this->m_heroName == FString("Tesla"))
		{
			//	TODO: enable eletric ray
			print("Death Ray");
		}
		if (this->m_heroName == FString("Einstein"))
		{
			//	TODO: enable timewarp
			print("Time Warp");
		}
	}
}

#pragma endregion

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickRobot()
{
#ifndef SHIPPING_GAME_VERSION
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		DrawDebugPoint(world, FVector(0, 0, 100.0f), 10, FColor(0, 0, 255), false, 0.03);
	}
#endif	//SHIPPING_GAME_VERSION	

	if (this->m_enableDeath)
	{
		if (this->m_heroIsDead)
		{
			return;
		}

		//	Show Dead Screen
		if (this->m_currentEnergy <= 0)
		{
			this->KillAllies();
			this->Kill();
		}
	}

	if (this->m_enableInteraction)
	{
		this->ProcessWalk();
		this->ProcessShoot();
		this->TickMousePosition();
		this->TickMaterialDamage();
		this->TickPowerUps();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickMaterialDamage()
{
	if (this->m_firstFrameTakeDamage)
	{
		UWorld *world = this->GetWorld();
		if (world != nullptr && this->m_heroMaterialInstanceDynamic != nullptr)
		{
			this->m_firstFrameTakeDamage = false;
			float worldSeconds = world->GetTimeSeconds();
			this->m_heroMaterialInstanceDynamic->SetScalarParameterValue(FName(TEXT("DamageColor")), worldSeconds);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickMousePosition()
{
	//	Get mouse position
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			float x, y;
			if (playerController->GetMousePosition(x, y))
			{
				this->m_aimCursorScreenPosition = FVector2D(x, y);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickForUnlockedSkills()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			if (gameInstance->m_heroProgression != nullptr)
			{
				this->m_currentLevel = gameInstance->m_heroProgression->GetCurrentLevel();

				if (this->m_currentLevel >= 2)
				{
					this->m_primarySkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 4) 
				{
					this->m_secondarySkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 6)
				{
					this->m_shieldSkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 8)
				{
					this->m_fullBatterySkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 10)
				{
					this->m_armyOfHeroesSkillsUnlocked[1] = true;
				}
				if (this->m_currentLevel >= 12)
				{
					this->m_pemSkillsUnlocked[1] = true;
				}

				if (this->m_currentLevel >= 14) 
				{
					this->m_primarySkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 16)
				{
					this->m_secondarySkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 18)
				{
					this->m_shieldSkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 20)
				{
					this->m_fullBatterySkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 22)
				{
					this->m_armyOfHeroesSkillsUnlocked[2] = true;
				}
				if (this->m_currentLevel >= 24)
				{
					this->m_pemSkillsUnlocked[2] = true;
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementShieldLevelStackAmount()
{
	this->m_shieldLevelAmount--;
	this->m_shieldLevelAmount = FMath::Clamp(this->m_shieldLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementFullBatteryLevelStackAmount()
{
	this->m_fullBatteryLevelAmount--;
	this->m_fullBatteryLevelAmount = FMath::Clamp(this->m_fullBatteryLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementArmyOfHeroesLevelStackAmount()
{
	this->m_armyOfHeroesLevelAmount--;
	this->m_armyOfHeroesLevelAmount = FMath::Clamp(this->m_armyOfHeroesLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementForceFieldLevelStackAmount()
{
	this->m_forceFieldLevelAmount--;
	this->m_forceFieldLevelAmount = FMath::Clamp(this->m_forceFieldLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementTimeWarpLevelStackAmount()
{
	this->m_timeWarpLevelAmount--;
	this->m_timeWarpLevelAmount = FMath::Clamp(this->m_timeWarpLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementIncreaseDamageLevelStackAmount()
{
	this->m_increaseDamageLevelAmount--;
	this->m_increaseDamageLevelAmount = FMath::Clamp(this->m_increaseDamageLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementIncreaseEnergyLevelStackAmount()
{
	this->m_increaseEnergyLevelAmount--;
	this->m_increaseEnergyLevelAmount = FMath::Clamp(this->m_increaseEnergyLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DecrementIncreaseMovementSpeedLevelStackAmount()
{
	this->m_increaseMovementSpeedLevelAmount--;
	this->m_increaseMovementSpeedLevelAmount = FMath::Clamp(this->m_increaseMovementSpeedLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementShieldLevelStackAmount()
{
	this->m_shieldLevelAmount++;
	this->m_shieldLevelAmount = FMath::Clamp(this->m_shieldLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementFullBatteryLevelStackAmount()
{
	this->m_fullBatteryLevelAmount++;
	this->m_fullBatteryLevelAmount = FMath::Clamp(this->m_fullBatteryLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementArmyOfHeroesLevelStackAmount()
{
	this->m_armyOfHeroesLevelAmount++;
	this->m_armyOfHeroesLevelAmount = FMath::Clamp(this->m_armyOfHeroesLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementForceFieldLevelStackAmount()
{
	this->m_forceFieldLevelAmount++;
	this->m_forceFieldLevelAmount = FMath::Clamp(this->m_forceFieldLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementTimeWarpLevelStackAmount()
{
	this->m_timeWarpLevelAmount++;
	this->m_timeWarpLevelAmount = FMath::Clamp(this->m_timeWarpLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementIncreaseDamageLevelStackAmount()
{
	this->m_increaseDamageLevelAmount++;
	this->m_increaseDamageLevelAmount = FMath::Clamp(this->m_increaseDamageLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementIncreaseEnergyStackAmount()
{
	this->m_increaseEnergyLevelAmount++;
	this->m_increaseEnergyLevelAmount = FMath::Clamp(this->m_increaseEnergyLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncrementIncreaseMovementSpeedStackAmount()
{
	this->m_increaseMovementSpeedLevelAmount++;
	this->m_increaseMovementSpeedLevelAmount = FMath::Clamp(this->m_increaseMovementSpeedLevelAmount, 0, this->m_maxSkillStackAmount);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TargetLock()
{
	this->m_aimCursorLocked = true;
	//	TODO: REMOVER ISTO
	//m_aimCursorLastWorldPosition = m_aimCursorWorldPosition;
	
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, TEXT("TargetLock"));
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TargetFree()
{
	this->m_aimCursorLocked = false;
	//	TODO: REMOVER ISTO
	//m_aimCursorWorldPosition = GetActorLocation() + GetActorForwardVector() * 500.0f;
	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, TEXT("TargetFree"));
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::MoveForward(float value)
{
	if (this->m_heroIsDead)
	{
		return;
	}
	
	//	TODO: REMOVER ISTO
	//	Stop controls
	//AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//if (gameMode != nullptr)
	//{
	//	if (!gameMode->m_enableCombat)
	//	{
	//		return;
	//	};
	//}

	//	Update movement
	if (value != 0.0f && this->m_enableWalk)
	{	
		this->m_xMovement = value;
		FVector forward = FVector(1.0f, -1.0f, 0.0f);
		//FVector forward = FVector::ForwardVector;
		this->AddMovementInput(forward, value, true);

		//	TODO: REMOVER ISTO
		//FVector direction = FVector(m_aimCursorLastWorldPosition.X, m_aimCursorLastWorldPosition.Y, this->GetActorLocation().Z);
		//m_targetRotator = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), this->GetActorLocation() + (forward*100.0f));
		//m_currentRotator = FMath::RInterpTo(m_currentRotator, m_targetRotator, m_deltaTime, 20.0f);
		//SetActorRotation(m_currentRotator);
		//GetCapsuleComponent()->SetRelativeRotation(forward.ToOrientationQuat());
	}
	else
	{
		//SetActorRotation(m_lastFrameRotator);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::MoveRight(float value)
{
	if (this->m_heroIsDead)
	{
		return;
	}
	
	//	TODO: REMOVER ISTO
	//	Stop controls
	//AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//if (gameMode != nullptr)
	//{
	//	if (!gameMode->m_enableCombat)
	//	{
	//		return;
	//	};
	//}

	//	Update movement
	if (value != 0.0f && this->m_enableWalk)
	{
		this->m_yMovement = value;
		FVector rightVector = FVector(1.0f, 1.0f, 0.0f);
		//FVector rightVector = FVector::RightVector;
		//SetActorRotation(rightVector.ToOrientationQuat());
		this->AddMovementInput(rightVector, value, true);
	}
	else
	{
		//SetActorRotation(m_lastFrameRotator);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TargetForward(float value)
{
	if (value != 0.0f)
	{
		this->m_aimCursorScreenPosition.Y += value * this->m_aimCursorSpeed;
	}
	this->m_aimCursorThumbStickValue.Y = value;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TargetRight(float value)
{
	if (value != 0.0f)
	{
		this->m_aimCursorScreenPosition.X += value * this->m_aimCursorSpeed;
	}
	this->m_aimCursorThumbStickValue.X = value;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TurnAtRate(float rate)
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		this->AddControllerYawInput(rate * world->GetDeltaSeconds());
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ProcessWalk()
{
	if (this->m_enableWalk)
	{
		FVector velocity = this->GetCharacterMovement()->Velocity;
		if (velocity.Size() > 1.0f)
		{
			FVector direction = this->GetCharacterMovement()->Velocity * 100.0f;
			this->m_targetRotator = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), this->GetActorLocation() + direction);
			this->m_currentRotator = FMath::RInterpTo(this->m_currentRotator, this->m_targetRotator, this->m_deltaTime, 5.0f);
			this->SetActorRotation(this->m_currentRotator.Quaternion());
		}
		else
		{
			this->SetActorRotation(this->m_lastFrameRotator);
		}
		this->m_lastFrameRotator = this->GetActorRotation();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ProcessShoot()
{
	//	The trace data is stored here
	FHitResult hitData(ForceInit);
	
	//	Actors to Ignore
	TArray<AActor*> actorsToIgnore;

	//	TODO: REMOVER ISTO
	//for (TObjectIterator<AActor> It; It; ++It)
	//{
	//	//actorsToIgnore.Add(*It);
	//}

	//	Ignore the player character too!
	actorsToIgnore.Add(this);

	//	Check if hit any actor
	FVector forwardVector = GetActorLocation() + (GetActorForwardVector() * 5000.0f);
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		if (UUtility::Trace(world, actorsToIgnore, this->GetActorLocation(), forwardVector, hitData))
		{
			if (hitData.GetActor())
			{
#ifndef SHIPPING_GAME_VERSION
				DrawDebugPoint(world, hitData.ImpactPoint, 10, FColor(255, 255, 255), false, 0.03f, -1);
#endif  //SHIPPING_GAME_VERSION
				//	TODO: REMOVER ISTO
				//if (GEngine)
				//{
				//	FString message = hitData.GetActor()->GetName();
				//	message += FString(": " ) + FString::SanitizeFloat(hitData.Distance);
				//	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow, message);
				//}
				//ACustomPlayerController *playerController = Cast<ACustomPlayerController>(GetWorld()->GetFirstPlayerController());
				//if (playerController != nullptr)
				//{
				//	playerController->ClientMessage(hitData.GetActor()->GetName());
				//	playerController->ClientMessage("Trace Distance: " + FString::SanitizeFloat(hitData.Distance));
				//}
			}
		}

		if (this->m_aimCursorLocked)
		{
			//	TODO: REMOVER ISTO
			//m_aimCursorLastWorldPosition = m_aimCursorWorldPosition;
			//m_targetRotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), m_aimCursorLastWorldPosition);
			//m_currentRotator = GetActorRotation();
			//SetActorRotation(m_targetRotator);
		}
		else
		{
			//m_aimCursorWorldPosition = GetActorLocation() + GetActorForwardVector() * 500.0f;
		}

		//	TODO: REMOVER ISTO
		//m_aimCursorWorldPosition = GetActorLocation() + GetActorForwardVector() * 500.0f;
		//m_aimCursorLastWorldPosition = m_aimCursorWorldPosition;
		//const FVector cubeLocation = FVector(0, 0, 0);
		//const FRotator cubeRotation = FRotator::ZeroRotator;

		//	Smootly lerp to center screen
		//if(m_aimCursorThumbStickValue.X == 0.0f && m_aimCursorThumbStickValue.Y == 0.0f)
		//{
		//	ACustomHUD *hud = Cast<ACustomHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		//	if (hud != nullptr)
		//	{
		//		FVector2D viewportSize = hud->m_viewportSize;
		//		float aimCursorTargetX = viewportSize.X / 2.0f - 50.0f;
		//		float aimCursorTargetY = viewportSize.Y / 2.0f - 50.0f;
		//		m_aimCursorPosition.X = FMath::FInterpTo(m_aimCursorPosition.X, aimCursorTargetX, m_deltaTime, 1.0f);
		//		m_aimCursorPosition.Y = FMath::FInterpTo(m_aimCursorPosition.Y, aimCursorTargetY, m_deltaTime, 1.0f);
		//	}
		//}
	}
}

#pragma region SKILLS
//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FullBattery()
{
	if (this->m_heroIsDead)
	{
		return;
	}

	this->FullBattery_Only();
	return;
	
	switch (this->m_fullBatterySkillType)
	{
	case EFullBatterySkillType::FBST_TypeA:
		this->FullBattery_IncreaseMovementSpeed();
		break;
	case EFullBatterySkillType::FBST_TypeB:
		this->FullBattery_IncreaseDamage();
		break;
	case EFullBatterySkillType::FBST_TypeC:
		this->FullBattery_DamageReduction();
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PEM()
{
	if (this->m_heroIsDead)
	{
		return;
	}

	//	Check if have skill stack
	if (this->m_forceFieldLevelAmount > 0)
	{
		//	Set transform
		FTransform transform;
		transform.SetLocation(this->GetActorLocation());

		//  Spawn PEM blueprint
		UWorld *world = this->GetWorld();
		if (world != nullptr)
		{
			APEM* pem = world->SpawnActor<APEM>(this->m_particlePEM_BP, transform);
			if (pem != nullptr)
			{
				UParticleSystemComponent *particleSystem = nullptr;
				TArray<UParticleSystemComponent *> particleSystemComponents;
				pem->GetComponents<UParticleSystemComponent>(particleSystemComponents);
				if (particleSystemComponents.Num() > 0)
				{
					particleSystem = particleSystemComponents[0];
				}

				if (particleSystem != nullptr)
				{
					FColor color = FColor(0, 255, 0, 0);
					//switch (this->m_PEMSkillType)
					//{
					//case EPEMSkillType::PST_Destruction:
					//	color = FColor(243, 139, 0, 0);
					//	break;
					//case EPEMSkillType::PST_HackSystem:
					//	color = FColor(0, 255, 0, 0);
					//	break;
					//case EPEMSkillType::PST_TypeC:
					//	color = FColor(255, 128, 177, 0);
					//	break;
					//}

					FParticleSysParam param;
					param.Name = FName("ColorSkill");
					param.ParamType = EParticleSysParamType::PSPT_Color;
					param.Color = color;

					TArray<FParticleSysParam> params;
					params.Add(param);
					particleSystem->InstanceParameters = params;

					this->DecrementForceFieldLevelStackAmount();
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ArmyOfHeroes()
{
	if (this->m_heroIsDead)
	{
		return;
	}
	this->ArmyOfHeroesSkill();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PrimarySkill()
{
	if (this->m_heroIsDead)
	{
		return;
	}
	this->PrimarySkill_A();
	return;

	switch (this->m_primarySkillType)
	{
	case EPrimarySkillType::PST_TypeA:
		this->PrimarySkill_A();
		break;
	case EPrimarySkillType::PST_TypeB:
		this->PrimarySkill_B();
		break;
	case EPrimarySkillType::PST_TypeC:
		this->PrimarySkill_C();
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::SecondarySkill()
{
	if (this->m_heroIsDead)
	{
		return false;
	}

	switch (this->m_secondarySkillType)
	{
	case ESecondarySkillType::SST_TypeA:
		return this->SecondarySkill_A();
	case ESecondarySkillType::SST_TypeB:
		return this->SecondarySkill_B();
	case ESecondarySkillType::SST_TypeC:
		return this->SecondarySkill_C();
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ShieldSkill()
{
	//	Check if have skill stack
	int32 amount = this->m_shieldLevelAmount;
	if (amount <= 0)
	{
		return;
	}

	if (this->m_timerManager != nullptr)
	{
		if (this->m_timerManager->IsTimerActive(this->m_shieldTimer))
		{
			return;
		}

		this->DecrementShieldLevelStackAmount();

		//	Activate Skill
		this->SetShieldPowerUp(true);
		this->m_shieldActiveTimer = this->m_shieldDelay;
		this->m_timerManager->SetTimer(this->m_shieldPowerUpTimer, this, &ACustomRobot::DisableShieldPowerUp, this->m_shieldDelay, false);

		//	Play animation scale in alembic
		if (this->m_shieldGeometryCacheComponent != nullptr)
		{
			this->m_shieldGeometryCacheComponent->PlayFromStart();
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FullBattery_Only()
{
	//	Check if have skill stack
	int32 amount = this->m_fullBatteryLevelAmount;
	if (amount <= 0)
	{
		return;
	}

	//	Fill energy
	this->m_currentEnergy = this->m_maxEnergy;
	this->DecrementFullBatteryLevelStackAmount();

	//	Spawn particle attached with unique color
	if (this->m_fullBatteryParticleSystem != nullptr)
	{
		UParticleSystemComponent *particleSystem = UGameplayStatics::SpawnEmitterAttached(this->m_fullBatteryParticleSystem, this->RootComponent, NAME_None);
		if (particleSystem != nullptr)
		{
			FParticleSysParam param;
			param.Name = FName("Color");
			param.ParamType = EParticleSysParamType::PSPT_Color;
			param.Color = FColor(192, 0, 166);

			TArray<FParticleSysParam> params;
			params.Add(param);
			particleSystem->InstanceParameters = params;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FullBattery_IncreaseMovementSpeed()
{
	//	Check if have skill stack
	int32 amount = this->m_fullBatteryLevelAmount;
	if (amount <= 0)
	{
		return;
	}

	//	Activate bonus increase movement speed
	float value = 0;
	this->IncreaseMovementSpeedByFullBattery(1.5f);

	//	Zero movement speed after N seconds
	FTimerDelegate timerDelegate;
	timerDelegate.BindUFunction(this, FName("IncreaseMovementSpeedByFullBattery"), value);
	this->m_timerManager->SetTimer(this->m_fullBatterySkillTimer, timerDelegate, 5.0f, false);

	//	Fill energy
	this->m_currentEnergy = this->m_maxEnergy;

	this->DecrementFullBatteryLevelStackAmount();

	//	Spawn particle attached with unique color
	if (this->m_fullBatteryParticleSystem != nullptr)
	{
		class UParticleSystemComponent *particleSystem = UGameplayStatics::SpawnEmitterAttached(this->m_fullBatteryParticleSystem, this->RootComponent, NAME_None);
		if (particleSystem != nullptr)
		{
			FParticleSysParam param;
			param.Name = FName("Color");
			param.ParamType = EParticleSysParamType::PSPT_Color;
			param.Color = FColor(241, 108, 0);

			TArray<FParticleSysParam> params;
			params.Add(param);
			particleSystem->InstanceParameters = params;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FullBattery_IncreaseDamage()
{
	//	Check if have skill stack
	int32 amount = this->m_fullBatteryLevelAmount;
	if (amount <= 0)
	{
		return;
	}

	//	Activate bonus increase damage
	float value = 0;
	this->IncreaseDamageByFullBattery(1.5f);

	//	Zero increase damage bonus after N seconds
	FTimerDelegate timerDelegate;
	timerDelegate.BindUFunction(this, FName("IncreaseDamageByFullBattery"), value);
	this->m_timerManager->SetTimer(this->m_fullBatterySkillTimer, timerDelegate, 5.0f, false);

	//	Fill energy
	this->m_currentEnergy = this->m_maxEnergy;

	this->DecrementFullBatteryLevelStackAmount();

	//	Spawn particle attached with unique color
	if (this->m_fullBatteryParticleSystem)
	{
		class UParticleSystemComponent *particleSystem = UGameplayStatics::SpawnEmitterAttached(this->m_fullBatteryParticleSystem, this->RootComponent, NAME_None);
		if (particleSystem != nullptr)
		{
			FParticleSysParam param;
			param.Name = FName("Color");
			param.ParamType = EParticleSysParamType::PSPT_Color;
			param.Color = FColor(0, 241, 40);

			TArray<FParticleSysParam> params;
			params.Add(param);
			particleSystem->InstanceParameters = params;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FullBattery_DamageReduction()
{
	//	Check if have skill stack
	int32 amount = this->m_fullBatteryLevelAmount;
	if (amount <= 0)
	{
		return;
	}

	//	Activate bonus damage reduction
	float value = 0;
	this->DamageReductionByFullBattery(1.5f);

	//	Zero damage reduction bonus after N seconds
	FTimerDelegate timerDelegate;
	timerDelegate.BindUFunction(this, FName("DamageReductionByFullBattery"), value);
	this->m_timerManager->SetTimer(this->m_fullBatterySkillTimer, timerDelegate, 5.0f, false);

	//	Fill energy
	this->m_currentEnergy = this->m_maxEnergy;

	this->DecrementFullBatteryLevelStackAmount();

	//	Spawn particle attached with unique color
	if (this->m_fullBatteryParticleSystem != nullptr)
	{
		class UParticleSystemComponent *particleSystem = UGameplayStatics::SpawnEmitterAttached(this->m_fullBatteryParticleSystem , this->RootComponent, NAME_None);
		if (particleSystem != nullptr)
		{
			FParticleSysParam param;
			param.Name = FName("Color");
			param.ParamType = EParticleSysParamType::PSPT_Color;
			param.Color = FColor(229, 28, 245);

			TArray<FParticleSysParam> params;
			params.Add(param);
			particleSystem->InstanceParameters = params;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ArmyOfHeroesSkill()
{
	//	Check if have skill stack
	int32 amount = this->m_armyOfHeroesLevelAmount;
	if (amount <= 0)
	{
		return;
	}

	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		//	Spawn Skill sound
		UAudioComponent* audioComponent = nullptr;
		if (this->m_armyOfHeroesSoundFX != nullptr)
		{
			float volume = 1.0f;
			UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
			if (gameInstance != nullptr)
			{
				volume = gameInstance->GetSoundFXVolume();
			}
			audioComponent = UGameplayStatics::SpawnSoundAttached(this->m_armyOfHeroesSoundFX, this->GetRootComponent(),
				NAME_None, FVector(ForceInit), FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset, true, volume);
		}

		//	Set offscreen positions
		TArray<FVector> positionsHeroes;
		FVector basePosition = FMath::VRand() * FVector(1.0f, 1.0f, 0);
		basePosition.Normalize();
		FVector position = basePosition * FMath::FRandRange(300.0f, 600.0f);
		position += this->GetActorLocation() + FVector(0, 0, 2000.0f);
		positionsHeroes.Add(position);

		for (int32 i = 0; i < 3; i++)
		{
			position = basePosition.RotateAngleAxis((90.0f * i) + 90.0f, FVector::UpVector);
			position *= FMath::FRandRange(300.0f, 600.0f);
			position += this->GetActorLocation() + FVector(0, 0, 2000.0f);
			positionsHeroes.Add(position);
		}

		UUtility::Array_Shuffle(positionsHeroes);

		//	Spawn heroes
		this->SpawnFirstAllyArmyOfHeroes(positionsHeroes[0]);
		FTimerDelegate spawnSecondHeroDelegate;
		spawnSecondHeroDelegate.BindUFunction(this, FName("SpawnSecondAllyArmyOfHeroes"), positionsHeroes[1]);
		this->m_timerManager->SetTimer(this->m_spawnSecondAllyTimer, spawnSecondHeroDelegate, 0.1f, false);

		FTimerDelegate spawnThirdHeroDelegate;
		spawnThirdHeroDelegate.BindUFunction(this, FName("SpawnThirdAllyArmyOfHeroes"), positionsHeroes[2]);
		this->m_timerManager->SetTimer(this->m_spawnThirdAllyTimer, spawnThirdHeroDelegate, 0.2f, false);

		FTimerDelegate spawnFourthHeroDelegate;
		spawnFourthHeroDelegate.BindUFunction(this, FName("SpawnFourthAllyArmyOfHeroes"), positionsHeroes[3]);
		this->m_timerManager->SetTimer(this->m_spawnFourthAllyTimer, spawnFourthHeroDelegate, 0.3f, false);

		//	Decrement stack
		this->DecrementArmyOfHeroesLevelStackAmount();

		//	Activate Skill
		this->m_armyOfHeroesActiveTimer = this->m_armyOfHeroesDelay;
		this->EnableArmyOfHeroesPowerUp(this->m_armyOfHeroesDelay);
	}
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::TimeWarpSkill()
{
	if (this->m_heroIsDead)
	{
		return false;
	}

	//	Available in stack?
	if (this->m_timeWarpLevelAmount > 0)
	{
		//	Play widget
		this->PlayTimeWarpPowerUpWidget();

		//this->m_timeWarpMaxActiveTime = powerUp->m_maxActiveTime;
		//this->EnableTimeWarpPowerUp(this->m_timeWarpMaxActiveTime);

		//	TODO: acumulate timewarp stack time
		//if (this->m_isActiveIncreaseDamagePowerUp)
		//{
		//	this->AcumulateTimeWarpPowerUp(this->m_forceFieldMaxActiveTime);
		//}
		//else
		//{
		//	this->EnableTimeWarpPowerUp(this->m_forceFieldMaxActiveTime);
		//}

		//	Decrement Stack
		this->DecrementTimeWarpLevelStackAmount();

		//	Activate Skill
		this->m_timeWarpActiveTimer = this->m_timeWarpDelay;
		this->EnableTimeWarpPowerUp(this->m_timeWarpDelay);

		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::IncreaseDamageSkill()
{
	if (this->m_heroIsDead)
	{
		return false;
	}

	//	Available in stack?
	if (this->m_increaseDamageLevelAmount > 0)
	{
		//	Play widget
		this->PlayIncreaseDamagePowerUpWidget();
		//if (this->m_isActiveIncreaseDamagePowerUp)
		//{
		//	this->AcumulateIncreaseDamagePowerUp(this->m_increaseDamageMaxActiveTime);
		//}
		//else
		//{
		//	this->EnableIncreaseDamagePowerUp(this->m_increaseDamageMaxActiveTime);
		//}
		
		//	Decrement Stack
		this->DecrementIncreaseDamageLevelStackAmount();

		//	Activate Skill
		this->m_increaseDamageActiveTimer = this->m_increaseDamageDelay;
		this->EnableIncreaseDamagePowerUp(this->m_increaseDamageDelay);

		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::IncreaseEnergySkill()
{
	if (this->m_heroIsDead)
	{
		return false;
	}

	//	Available in Stack?
	if (this->m_increaseEnergyLevelAmount > 0)
	{
		//	Play widget
		this->PlayIncreaseEnergyPowerUpWidget();
		
		//	Decrement Stack
		this->DecrementIncreaseEnergyLevelStackAmount();
		
		//	Activate Skill
		this->m_increaseEnergyActiveTimer = this->m_increaseEnergyDelay;
		this->EnableIncreaseEnergyPowerUp(this->m_increaseEnergyDelay);

		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::IncreaseMovementSpeedSkill()
{
	if (this->m_heroIsDead)
	{
		return false;
	}

	//	Available in Stack?
	if (this->m_increaseMovementSpeedLevelAmount > 0)
	{
		//this->m_increaseMovementSpeedMaxActiveTime = powerUp->m_maxActiveTime;
		//if (this->m_isActiveIncreaseDamagePowerUp)
		//{
		//	this->AcumulateIncreaseMovementSpeedPowerUp(this->m_forceFieldMaxActiveTime);
		//}
		//else
		//{
		//	this->EnableIncreaseMovementSpeedPowerUp(this->m_forceFieldMaxActiveTime);
		//}

		//	Play widget
		this->PlayIncreaseMovementSpeedPowerUpWidget();
		
		//	Decrement Stack
		this->DecrementIncreaseMovementSpeedLevelStackAmount();

		//	Activate Skill
		this->m_increaseMovementSpeedActiveTimer = this->m_increaseMovementSpeedDelay;
		this->EnableIncreaseMovementSpeedPowerUp(this->m_increaseMovementSpeedDelay);

		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnFirstAllyArmyOfHeroes(FVector projectedPosition)
{
	float angle = FMath::FRandRange(0, 360.0f);
	FTransform transform;
	transform.SetRotation(FRotator(0, angle, 0).Quaternion());
	transform.SetLocation(projectedPosition);
	UWorld *world = this->GetWorld();
	if (world != nullptr && this->m_robotAlly_Red != nullptr)
	{
		ARobotAlly* ally = world->SpawnActor<ARobotAlly>(this->m_robotAlly_Red, transform);
		if (ally != nullptr)
		{
			this->m_armyOfHeroesAllyes[0] = ally;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnSecondAllyArmyOfHeroes(FVector projectedPosition)
{
	float angle = FMath::FRandRange(0, 360.0f);
	FTransform transform;
	transform.SetRotation(FRotator(0, angle, 0).Quaternion());
	transform.SetLocation(projectedPosition);
	UWorld *world = this->GetWorld();
	if (world != nullptr && this->m_robotAlly_Green != nullptr)
	{
		ARobotAlly* ally = world->SpawnActor<ARobotAlly>(this->m_robotAlly_Green, transform);
		if (ally != nullptr)
		{
			this->m_armyOfHeroesAllyes[1] = ally;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnThirdAllyArmyOfHeroes(FVector projectedPosition)
{
	float angle = FMath::FRandRange(0, 360.0f);
	FTransform transform;
	transform.SetRotation(FRotator(0, angle, 0).Quaternion());
	transform.SetLocation(projectedPosition);
	UWorld *world = this->GetWorld();
	if (world != nullptr && this->m_robotAlly_Blue != nullptr)
	{
		ARobotAlly* ally = world->SpawnActor<ARobotAlly>(this->m_robotAlly_Blue, transform);
		if (ally != nullptr)
		{
			this->m_armyOfHeroesAllyes[2] = ally;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnFourthAllyArmyOfHeroes(FVector projectedPosition)
{
	float angle = FMath::FRandRange(0, 360.0f);
	FTransform transform;
	transform.SetRotation(FRotator(0, angle, 0).Quaternion());
	transform.SetLocation(projectedPosition);
	UWorld *world = this->GetWorld();
	if (world != nullptr && this->m_robotAlly_White != nullptr)
	{
		ARobotAlly* ally = world->SpawnActor<ARobotAlly>(this->m_robotAlly_White, transform);
		if (ally != nullptr)
		{
			this->m_armyOfHeroesAllyes[3] = ally;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PrimarySkill_A()
{
	this->ShootNormalBlast();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PrimarySkill_B()
{
	//	TODO: Implement or remove
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PrimarySkill_C()
{
	//	TODO: Implement or remove
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TeleportActor(FVector position)
{
	this->TeleportTo(position, this->GetActorRotation());
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::SecondarySkill_A()
{
	FColor skillColor = FColor(127, 26, 241);
	FVector teleportPosition;
	bool success = this->TeleportPlayerWithTrail(skillColor, teleportPosition);
	if (success)
	{
		//	Libera um FX Force field antes do teleport
		if (this->m_teleportFieldFX != nullptr)
		{
			FVector oldPosition = this->GetActorLocation();
			FVector currentPosition;
			for (int32 i = 0; i < 5; i++)
			{
				float bias = 1.0f / 5 * static_cast<float>(i);
				currentPosition = FMath::Lerp(oldPosition, teleportPosition, bias);
				this->SpawnTeleportFieldFX(currentPosition, static_cast<float>(i) * 0.2f, 5.0f, 100.0f, 10);
				print("this->SpawnTeleportFieldFX");
			}
		}

		//	Zero movement speed after N seconds
		FTimerDelegate timerDelegate;
		timerDelegate.BindUFunction(this, FName("TeleportActor"), teleportPosition);
		this->m_timerManager->SetTimer(this->m_teleportSkillTimer, timerDelegate, 0.05f, false);
	}
	return true;
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::SecondarySkill_B()
{
	FColor skillColor = FColor(241, 40, 40);
	FVector teleportPosition;
	bool success = this->TeleportPlayerWithTrail(skillColor, teleportPosition);
	if (success)
	{
		//	TODO: Teleport Skill deixa um force field no lugar antes do teleport que causa X% dano eletrico

		//	Zero movement speed after N seconds
		FTimerDelegate timerDelegate;
		timerDelegate.BindUFunction(this, FName("TeleportActor"), teleportPosition);
		this->m_timerManager->SetTimer(this->m_teleportSkillTimer, timerDelegate, 0.05f, false);
	}
	return true;
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::SecondarySkill_C()
{
#ifndef SHIPPING_GAME_VERSION
	print("Teleport Skill C");
#endif	//SHIPPING_GAME_VERSION

	FColor skillColor = FColor(53, 241, 40);
	FVector teleportPosition;
	bool success = this->TeleportPlayerWithTrail(skillColor, teleportPosition);
	if (success)
	{
		//	TODO Change to Teleport Skill gain 400% increase damage por 2 segundos

		//	Zero movement speed after N seconds
		FTimerDelegate timerDelegate;
		timerDelegate.BindUFunction(this, FName("TeleportActor"), teleportPosition);
		this->m_timerManager->SetTimer(this->m_teleportSkillTimer, timerDelegate, 0.05f, false);
	}
	return true;
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::TeleportPlayerWithTrail(FColor skillColor, FVector &teleportPosition)
{
	FHitResult hit;
	TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));

	FNavLocation NavLocation;
	FVector QueryingExtent = FVector(0, 0, 500.0f);

	//	Get player controller
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//	Get 3d hit location
			playerController->GetHitResultUnderCursorForObjects(objectTypes, true, hit);
			if (hit.IsValidBlockingHit())
			{
				this->m_aimCursorLastWorldPosition = hit.Location + FVector(0, 0, 200.0f);

				UNavigationSystem* const navigationSystem = world->GetNavigationSystem();
				if (navigationSystem != nullptr)
				{
					bool bProjectedLocationValid = navigationSystem->ProjectPointToNavigation(this->m_aimCursorLastWorldPosition, NavLocation, QueryingExtent);
#ifndef SHIPPING_GAME_VERSION
					DrawDebugLine(
						world,
						this->GetActorLocation(),
						this->m_aimCursorLastWorldPosition,
						FColor(255, 255, 255),
						false,
						2.0f, 10.0f);

					//	Debug
					FString name;
					hit.Actor->GetName(name);
					print(name);
#endif	//SHIPPING_GAME_VERSION
					if (bProjectedLocationValid)
					{
						teleportPosition = NavLocation.Location;
						if (this->m_teleportTrailParticleSystem != nullptr)
						{
							//	Spawn particle trail with unique color
							USkeletalMeshComponent *skeletalMesh = this->GetMesh();
							TArray<FName> bonesNames;
							bonesNames.Add("j_pelvis_pivot");
							bonesNames.Add("j_sholder_right");
							bonesNames.Add("j_sholder_left");
							bonesNames.Add("j_spin_weapon_right");
							bonesNames.Add("j_spin_weapon_left");
							bonesNames.Add("j_knee_inner_right");
							bonesNames.Add("j_knee_inner_left");
							if (skeletalMesh != nullptr)
							{
								UParticleSystemComponent *particleSystem = nullptr;

								//	Initialize Instance parameters
								FParticleSysParam param;
								param.Name = FName("TrailColor");
								param.ParamType = EParticleSysParamType::PSPT_Color;
								param.Color = skillColor;

								TArray<FParticleSysParam> params;
								params.Add(param);

								for (int32 i = 0; i < bonesNames.Num(); i++)
								{
									particleSystem = UGameplayStatics::SpawnEmitterAttached(this->m_teleportTrailParticleSystem, skeletalMesh, bonesNames[i]);
									if (particleSystem != nullptr)
									{
										//	Apply instance parameters
										particleSystem->InstanceParameters = params;
									}
								}
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnTeleportFieldFX(FVector position, float delayActivate, float life, float radius, int32 damage)
{
	if (this->m_teleportFieldFX != nullptr)
	{
		FTransform transform;
		transform.SetLocation(position);
		UWorld *world = this->GetWorld();
		if (world != nullptr)
		{
			AFXDelayed* forceField = world->SpawnActorDeferred<AFXDelayed>(this->m_teleportFieldFX, transform);
			if (forceField != nullptr)
			{
				forceField->m_delayActivateSeconds = delayActivate;
				forceField->m_lifeSecondsAfterActivate = life;
				forceField->m_radius = radius;
				forceField->m_damage = damage;

				//	Finish spawn actor
				UGameplayStatics::FinishSpawningActor(forceField, transform);

				//	Play FX
				UFunction *playFX = forceField->FindFunction(FName("PlayBlueprintFX"));
				if (playFX != nullptr)
				{
					forceField->ProcessEvent(playFX, nullptr);
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DamageReductionByFullBattery(float value)
{
	this->m_damageReductionByFullBatterySkill = value;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncreaseMovementSpeedByFullBattery(float value)
{
	this->m_increaseMovementSpeedFullBatterySkill = value;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncreaseDamageByFullBattery(float value)
{
	this->m_increaseDamageByFullBatterySkill = value;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetTorsoLookAtRotation()
{
	FHitResult hit;
	TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	//objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	//	Get player controller
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//	Get hit location as screen position
			playerController->GetHitResultAtScreenPosition(this->m_aimCursorScreenPosition, objectTypes, true, hit);

			//	Get hero Vector
			FVector actorLocation = this->GetActorLocation();
			FVector targetLocation = hit.Location;
			float actorHeight = FMath::Abs(actorLocation.Z - targetLocation.Z);

			//	Get camera vector
			FVector cameraLocation = playerController->PlayerCameraManager->GetCameraLocation();
			FVector cameraDirection = cameraLocation - targetLocation;
			cameraDirection.Normalize();
			cameraDirection *= actorHeight * 0.85f * 2.0f;	// 0.85 = sin(45) Camera angle
			targetLocation = hit.Location + cameraDirection;

#ifndef SHIPPING_GAME_VERSION
			DrawDebugLine(
				world,
				targetLocation,
				hit.Location,
				FColor(255, 255, 255),
				false,
				2.0f, 10.0f);
#endif	//SHIPPING_GAME_VERSION

			FRotator desiredRotation = UKismetMathLibrary::FindLookAtRotation(actorLocation, targetLocation);
			return desiredRotation.Yaw - this->m_lastFrameRotator.Yaw;
		}
	}
	return this->m_lastFrameRotator.Yaw;
}
#pragma endregion

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnergyRegeneration()
{
	this->m_currentEnergy++;
	this->m_currentEnergy = FMath::Clamp(this->m_currentEnergy, 0, this->m_maxEnergy);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::OnRightShootPressed()
{
	//	TODO: Implement or remove
	this->FireLeftWeapon();
	this->FireRightWeapon();
	//m_timerManager->SetTimer(m_leftWeaponTimer, this, &ACustomRobot::FireLeftWeapon, m_leftWeaponDelay, true, 0);
	//m_timerManager->SetTimer(m_rightWeaponTimer, this, &ACustomRobot::FireRightWeapon, m_rightWeaponDelay, true, 0);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PrimarySkillBlast(float intensity, bool normalBlast)
{
	//	Tick xp level
	UWorld* world = this->GetWorld();
	AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
	if (gameMode != nullptr)
	{ 
		//gameMode->TickLevelXP();
	}

	if (normalBlast)
	{
		this->ShootNormalBlast();
	}
	else
	{
		this->ShootHyperBlast(intensity);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FireLeftWeapon()
{
	if (this->m_leftWeaponSocket != nullptr)
	{
		this->FireWeapon(this->m_leftWeaponSocket);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FireRightWeapon()
{
	if (this->m_rightWeaponSocket != nullptr)
	{
		this->FireWeapon(this->m_rightWeaponSocket);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::FireWeapon(UChildActorComponent *socket)
{
	//	Convert screen to world coordinates
	FVector aim3DPosition;
	FVector aim3DDirection;
	FVector cameraDirection;
	FVector actorLocation;
	FHitResult hit;
	TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	//objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UWorld *world = this->GetWorld();
	if (world != nullptr && socket != nullptr)
	{
		//	Get player controller
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//	Get camera vector
			FVector cameraLocation = playerController->PlayerCameraManager->GetCameraLocation();
			actorLocation = this->GetActorLocation();
			cameraDirection = actorLocation - cameraLocation;
			cameraDirection.Normalize();

			//	Get hit location as screen position
			playerController->GetHitResultAtScreenPosition(this->m_aimCursorScreenPosition, objectTypes, true, hit);
		}
		this->m_aimCursorLastWorldPosition = hit.Location;

		//	Spawn a bullet capsule
		FTransform transform;
		transform.SetLocation(socket->GetComponentLocation());
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(socket->GetComponentLocation(), hit.Location);
		transform.SetRotation(rotation.Quaternion());

		//	Spawn a projetile
		TArray<float> angles;
		//angles.Add(14.0f);
		//angles.Add(7.0f);
		angles.Add(0);
		//angles.Add(-7.0f);
		//angles.Add(-14.0f);

		for (int i = 0; i < angles.Num(); i++)
		{
			ABulletProjectile* projectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileNormal, transform);
			if (projectile != nullptr)
			{
				FVector desiredVector = hit.Location;
				float multiplierZ = actorLocation.Z / cameraDirection.Z;
				cameraDirection *= multiplierZ;
				FVector desiredTarget = desiredVector + cameraDirection;
				FRotator rotationProjectile = UKismetMathLibrary::FindLookAtRotation(desiredTarget, transform.GetLocation());
				rotationProjectile.Yaw += angles[i];
				FVector velocityProjectile = desiredTarget - transform.GetLocation();
				velocityProjectile.Normalize();
				velocityProjectile = velocityProjectile.RotateAngleAxis(angles[i], FVector::UpVector);

				projectile->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
				projectile->SetActorRotation(rotationProjectile);
				projectile->m_velocity = velocityProjectile * 2000.0f;
				projectile->m_weaponOwner = EWeaponOwner::WO_Player;
				projectile->m_damage = this->m_finalDamage;
				projectile->m_speed = 1;
				projectile->m_lifetime = 1.5f;

				//	Finish spawn actor
				UGameplayStatics::FinishSpawningActor(projectile, transform);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DoCameraShake(float scale)
{
	//	TODO: Check if this camera shake is in use

	if (!this->m_cameraShakeState)
	{
		return;
	}

	//	Camera Shake event
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//m_cameraShake->GetDefaultObject<UCameraShake>()->AnimScale = 10.0f;
			playerController->ClientPlayCameraShake(this->m_cameraShake, scale, ECameraAnimPlaySpace::World);
		}
	}

	
	//	TODO: Remove this if is not using
	//UWorld *world = this->GetWorld();
	//if (world != nullptr)
	//{
	//	APlayerController *playerController = world->GetFirstPlayerController();
	//	if (playerController != nullptr)
	//	{
	//		//m_cameraShake->OscillationDuration = 1.0f;
	//		//m_cameraShake->OscillationBlendInTime = 0.5f;
	//		//m_cameraShake->OscillationBlendOutTime = 0.5f;
	//		//m_cameraShake->LocOscillation.X.Amplitude = 1.0f;
	//		//m_cameraShake->GetDefaultObject<UCameraShake>()->LocOscillation.X.Frequency = 5000.0f;
	//		//m_cameraShake->LocOscillation.Y.Amplitude = 1.0f;
	//		//m_cameraShake->GetDefaultObject<UCameraShake>()->LocOscillation.Z.Frequency = 5000.0f;
	//		//m_cameraShake->AnimScale = 1.0f;
	//		this->m_cameraShake->GetDefaultObject<UCameraShake>()->AnimPlayRate = 0.1f;
	//		//m_cameraShake->AnimBlendInTime = 0.2f;
	//		//m_cameraShake->AnimBlendOutTime = 0.2f;
	//		playerController->ClientPlayCameraShake(this->m_cameraShake, 10.0f, ECameraAnimPlaySpace::World);
	//	}
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::IncreaseDamageFromRareKill(float percent, float secondsActive)
{
	if (!this->m_isIncreaseDamageFromRareKill)
	{
		//	Play UMG and SFX and increase N% damage to hero for X seconds
		if (!this->m_timerManager->IsTimerActive(this->m_increaseDamageFromRareKill))
		{
			print("ACustomRobot::IncreaseDamageFromRareKill");

			this->m_isIncreaseDamageFromRareKill = true;

			//	TODO: Increase damage here
			//	TODO: Play increase damage UMG

			this->m_timerManager->SetTimer(this->m_increaseDamageFromRareKill, this, &ACustomRobot::DisableIncreaseDamageFromRareKill, secondsActive, false);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableIncreaseDamageFromRareKill()
{
	print("ACustomRobot::DisableIncreaseDamageFromRareKill");
	this->m_isIncreaseDamageFromRareKill = false;
}

#pragma region SKILLS
//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetShieldNormalizedActiveTimer()
{
	return this->m_shieldActiveTimer / this->m_shieldDelay;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetArmyOfHeroesNormalizedActiveTimer()
{
	return this->m_armyOfHeroesActiveTimer / this->m_armyOfHeroesDelay;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetTimeWarpNormalizedActiveTimer()
{
	return this->m_timeWarpActiveTimer / this->m_timeWarpDelay;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetIncreaseDamageNormalizedActiveTimer()
{
	return this->m_increaseDamageActiveTimer / this->m_increaseDamageDelay;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetIncreaseEnergyNormalizedActiveTimer()
{
	return this->m_increaseEnergyActiveTimer / this->m_increaseEnergyDelay;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetIncreaseMovementSpeedNormalizedActiveTimer()
{
	return this->m_increaseMovementSpeedActiveTimer / this->m_increaseMovementSpeedDelay;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseProtectionSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseProtectionSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseRegenerationSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseRegenerationSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseSupportSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseSupportSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseAreaCombatSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseAreaCombatSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UsePrimarySkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UsePrimarySkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseSecondarySkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseSecondarySkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseTimeControlSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseTimeControlSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseDamageControlSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseDamageControlSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseEnergyControlSkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseEnergyControlSkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UseMobilitySkill()
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->UseMobilitySkill();
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapProtectionSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapProtectionSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapRegenerationSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapRegenerationSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapSupportSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapSupportSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapAreaCombatSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapAreaCombatSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapPrimarySkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapPrimarySkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapSecondarySkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapSecondarySkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapTimeControlSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapTimeControlSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapDamageControlSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapDamageControlSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapEnergyControlSkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapEnergyControlSkill(skillIndex);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SwapMobilitySkill(int32 skillIndex)
{
	if (this->m_heroDynamicSkills != nullptr)
	{
		this->m_heroDynamicSkills->SwapMobilitySkill(skillIndex);
	}
}
#pragma endregion SKILLS

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::LockTarget(AActor *enemy)
{
	//	TODO: Implement or remove
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ApplyDamage(int32 damage)
{
	if (this->m_heroIsDead)
	{
		return;
	}
	if (!this->m_godMode.GetValue())
	{
		this->m_currentEnergy -= damage;
		this->m_currentEnergy = FMath::Clamp(this->m_currentEnergy, 0, this->m_maxEnergy);
		this->m_firstFrameTakeDamage = true;
	}
	this->DoCameraShake(30.0f);


	//	Append damage number
	//AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//if (gameMode != nullptr)
	//{
	//	APlayerController *playerController = GetWorld()->GetFirstPlayerController();
	//	if (playerController != nullptr)
	//	{
	//		FVector2D screenPosition;
	//		FVector position = GetActorLocation();
	//		playerController->ProjectWorldLocationToScreen(position, screenPosition);
	//		gameMode->AppendDamageNumbers(damage, screenPosition, EDamageType::DT_Normal);
	//	}
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ApplyDamage(ABulletProjectile *projectile)
{
	if (this->m_heroIsDead)
	{
		return;
	}
	if (!this->m_godMode.GetValue())
	{
		this->m_firstFrameTakeDamage = true;
		this->m_currentEnergy -= projectile->m_damage;
		this->m_currentEnergy = FMath::Clamp(this->m_currentEnergy, 0, this->m_maxEnergy);
	}
	this->DoCameraShake(30.0f);

	//	Append damage number
	//AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//if (gameMode != nullptr)
	//{
	//	APlayerController *playerController = GetWorld()->GetFirstPlayerController();
	//	if (playerController != nullptr)
	//	{
	//		FVector2D screenPosition;
	//		FVector position = GetActorLocation();
	//		playerController->ProjectWorldLocationToScreen(position, screenPosition);
	//		gameMode->AppendDamageNumbers(damage, screenPosition, EDamageType::DT_Normal);
	//	}
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ApplyDamage(AMissile *missile)
{
	if (this->m_heroIsDead)
	{
		return;
	}
	if (!this->m_godMode.GetValue())
	{
		this->m_firstFrameTakeDamage = true;
		this->m_currentEnergy -= missile->m_damage;
		this->m_currentEnergy = FMath::Clamp(this->m_currentEnergy, 0, this->m_maxEnergy);
	}
	this->DoCameraShake(30.0f);
	
	//	Append damage number
	//AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//if (gameMode != nullptr)
	//{
	//	APlayerController *playerController = GetWorld()->GetFirstPlayerController();
	//	if (playerController != nullptr)
	//	{
	//		FVector2D screenPosition;
	//		FVector position = GetActorLocation();
	//		playerController->ProjectWorldLocationToScreen(position, screenPosition);
	//		gameMode->AppendDamageNumbers(damage, screenPosition, EDamageType::DT_Normal);
	//	}
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::Kill()
{
	this->m_heroIsDead = true;
	this->ShowDeadScreenUMG();
	this->Explode();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ShowDeadScreenUMG()
{
#ifndef SHIPPING_GAME_VERSION
	print("You Are dead UMG Here");
#endif  //SHIPPING_GAME_VERSION

	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			APlayerController *playerController = UGameplayStatics::GetPlayerController(world, 0);
			AArenaGameMode* gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
			if (this->m_deadScreenWidget != nullptr && gameMode != nullptr && playerController != nullptr)
			{
				//	Setup UMG
				this->m_deadScreenUMG = CreateWidget<UUserWidget>(playerController, this->m_deadScreenWidget);
				this->m_deadScreenUMG->AddToViewport();

				//	Get localized strings
				FText title;
				FText penalty;
				int32 titleIndex = 10;
				int32 penaltyIndex = 12;
				switch (gameMode->GetGameDifficult())
				{
				case EGameDifficult::GD_Easy:
					penaltyIndex = 12;
					break;
				case EGameDifficult::GD_Normal:
					gameMode->IncreaseEnemiesCurrentEnergyByPercent(2);
					penaltyIndex = 13;
					break;
				case EGameDifficult::GD_Hard:
					gameMode->IncreaseEnemiesCurrentEnergyByPercent(5);
					penaltyIndex = 14;
					break;
				}
				gameInstance->GetLocalizedString(world, titleIndex, ELanguageStringCategory::LSC_GameplayHUD, title);
				gameInstance->GetLocalizedString(world, penaltyIndex, ELanguageStringCategory::LSC_GameplayHUD, penalty);

				struct FDeadScreenParams
				{
					FText title;
					FText penalty;
				};

				//	Setup texts
				UFunction* setupVars = this->m_deadScreenUMG->FindFunction(FName("InitVars"));
				if (setupVars != nullptr)
				{
					FDeadScreenParams params;
					params.title = title;
					params.penalty = penalty;
					this->m_deadScreenUMG->ProcessEvent(setupVars, &params);
				}

				//	Play animation
				UFunction* playAnimation = this->m_deadScreenUMG->FindFunction(FName("PlayAnimationUMG"));
				if (playAnimation != nullptr)
				{
					this->m_deadScreenUMG->ProcessEvent(playAnimation, nullptr);
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::Explode()
{
	//	Spawn particle explosion with instance parameters
	FTransform transform;
	transform.SetLocation(this->GetActorLocation());
	float angle = FMath::FRandRange(0, 360.0f);
	transform.SetRotation(FRotator(0, angle, 0).Quaternion());

	//	Spawn particle explosion
	UWorld *world = this->GetWorld();
	if (this->m_explosionBP != nullptr && world != nullptr)
	{
		AActor* explosion = world->SpawnActor<AActor>(this->m_explosionBP, transform);
		if (explosion != nullptr)
		{
			//UParticleSystemComponent *particleSystem = nullptr;
			//TArray<UParticleSystemComponent *> particleSystemComponents;
			//GetComponents<UParticleSystemComponent>(particleSystemComponents);
			//if (particleSystemComponents.Num() > 0)
			//{
			//	particleSystem = particleSystemComponents[0];
			//}

			//if (particleSystem)
			//{
			//	FParticleSysParam param;
			//	param.Name = FName("RobotActor");
			//	param.ParamType = EParticleSysParamType::PSPT_Actor;
			//	param.Actor = this;

			//	TArray<FParticleSysParam> params;
			//	params.Add(param);
			//	particleSystem->InstanceParameters = params;
			//}

			//	Finish spawn actor
			//UGameplayStatics::FinishSpawningActor(explosion, transform);
		}
	}
	
	//	Destruct robot
	//if (m_enableKillDestruction)
	{
		UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
		if (capsuleComponent != nullptr)
		{
			//capsuleComponent->SetCollisionProfileName(FName("NoCollision"));
			//capsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}

		//	Add force to random bones
		USkeletalMeshComponent *skeletalMesh = this->GetMesh();
		if (skeletalMesh != nullptr && m_physicsAsset != nullptr)
		{
			//	Create array of possibles bones to add force
			TArray<FName> boneNames;
			boneNames.Add(FName("j_foot_left"));
			boneNames.Add(FName("j_foot_right"));
			boneNames.Add(FName("j_pelvis_pivot"));
			boneNames.Add(FName("j_knee_inner_left"));
			boneNames.Add(FName("j_knee_inner_right"));

			skeletalMesh->SetAllBodiesBelowSimulatePhysics(FName("j_root"), true, false);
			skeletalMesh->SetPhysicsAsset(m_physicsAsset, false);
			skeletalMesh->SetCollisionProfileName(FName("BlockAll"));
			skeletalMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
			//skeletalMesh->SetCastShadow(false);
			skeletalMesh->SetSimulatePhysics(true);
			skeletalMesh->WakeAllRigidBodies();

			//float rangeForce = 5000000.0f;
			//UUtility::Array_Shuffle(boneNames);

			//for (int i = 0; i < boneNames.Num() - 1; i++)
			//{
			//	FVector force = FVector(FMath::FRandRange(-rangeForce, rangeForce), FMath::FRandRange(-rangeForce, rangeForce), 10000000.0f);
			//	FVector torque = FVector(FMath::FRandRange(-rangeForce, rangeForce), FMath::FRandRange(-rangeForce, rangeForce), FMath::FRandRange(-rangeForce, rangeForce));
			//	skeletalMesh->AddForce(force, boneNames[i]);
			//	skeletalMesh->AddTorque(torque, boneNames[i]);
			//}
		}
	}

	//	TODO: Lock robot controls

	//	Hide health bar UMG
	if (this->m_healthBarWidgetComponent != nullptr)
	{
		this->m_healthBarWidgetComponent->SetVisibility(false);
	}

	//	Disable combat mode
	if (world != nullptr)
	{
		AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			gameMode->SetCombatModeForEnemies(false);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::Respawn()
{
	//	Restart skeletalMesh
	USkeletalMeshComponent *skeletalMesh = this->GetMesh();
	if (skeletalMesh != nullptr)
	{
		skeletalMesh->SetCastShadow(true);
		skeletalMesh->PutAllRigidBodiesToSleep();
		skeletalMesh->SetSimulatePhysics(false);
		skeletalMesh->SetPhysicsBlendWeight(1.0f);
		
		UCapsuleComponent *capsuleComponent = this->GetCapsuleComponent();
		if (capsuleComponent != nullptr)
		{
			//skeletalMesh->AttachTo(capsuleComponent, NAME_None, EAttachLocation::SnapToTarget, true);
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
			//ConvertAttachLocation(AttachType, AttachmentRules.LocationRule, AttachmentRules.RotationRule, AttachmentRules.ScaleRule);
			skeletalMesh->AttachToComponent(capsuleComponent, AttachmentRules, NAME_None);

			capsuleComponent->SetCollisionProfileName(FName("Custom"));
			capsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}

		skeletalMesh->SetRelativeRotation(FRotator(0, -90.0f, 0).Quaternion());
		skeletalMesh->SetRelativeLocation(FVector(0, 0, -170.0f));
		this->m_heroIsDead = false;
		this->m_currentEnergy = this->m_maxEnergy;

		//skeletalMesh->ResetAllBodiesSimulatePhysics();

		//skeletalMesh->SetCollisionProfileName(FName("NoCollision"));
		//skeletalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		//skeletalMesh->SetCastShadow(true);
		//skeletalMesh->SetRelativeLocationAndRotation(FVector(0, 0, -170.0f), FRotator(0, -90.0f, 0).Quaternion(), true, nullptr, ETeleportType::TeleportPhysics);
		//skeletalMesh->SetPhysicsAsset(nullptr, true);
	}

	//	TODO: Unlock robot controls

	//	Unhide health bar UMG
	if (this->m_healthBarWidgetComponent != nullptr)
	{
		this->m_healthBarWidgetComponent->SetVisibility(true);
	}

	//	Enable combat mode
	UWorld* world = this->GetWorld();
	if (world != nullptr)
	{
		AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
		if (gameMode != nullptr)
		{
			gameMode->SetCombatModeForEnemies(true);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetShield(bool enabled)
{
	//this->m_shieldEnabled = enabled;
	//m_shieldMeshComponent->SetVisibility(enabled);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableShielding()
{
	this->ShieldSkill();

	//switch (this->m_shieldSkillType)
	//{
	//case EShieldSkillType::SST_TypeA:
	//	break;
	//case EShieldSkillType::SST_TypeB:
	//	this->ShieldSkill_B();
	//	break;
	//case EShieldSkillType::SST_TypeC:
	//	this->ShieldSkill_C();
	//	break;
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableShielding()
{
	if (this->m_shieldGeometryCacheComponent != nullptr)
	{
		this->m_shieldGeometryCacheComponent->PlayReversedFromEnd();
	}
	this->SetShield(false);
	this->m_timerManager->ClearTimer(this->m_shieldTimer);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnKeyboardHint(UWorld *world)
{
	if (this->m_keyboardHintActor != nullptr && world != nullptr)
	{
		FTransform transform;
		transform.SetLocation(this->GetActorLocation());
		world->SpawnActor<AKeyboardHint>(this->m_keyboardHintActor, transform);
	}
}

#pragma region POWER_UPS
//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickPowerUps()
{
	this->TickShieldPowerUp();
	this->TickArmyOfHeroesPowerUp();
	this->TickTimeWarpPowerUp();
	this->TickIncreaseDamagePowerUp();
	this->TickIncreaseEnergyPowerUp();
	this->TickIncreaseMovementSpeedPowerUp();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickShieldPowerUp()
{
	if (this->m_isActiveShieldPowerUp)
	{
		this->m_shieldActiveTimer -= this->m_deltaTime;
		this->m_shieldActiveTimer = FMath::Clamp<float>(this->m_shieldActiveTimer, 0, this->m_shieldDelay);
	}
	else
	{
		this->m_shieldActiveTimer = 0;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickArmyOfHeroesPowerUp()
{
	if (this->m_isActiveArmyOfHeroesPowerUp)
	{
		this->m_armyOfHeroesActiveTimer -= this->m_deltaTime;
		this->m_armyOfHeroesActiveTimer = FMath::Clamp<float>(this->m_armyOfHeroesActiveTimer, 0, this->m_armyOfHeroesDelay);
	}
	else
	{
		this->m_armyOfHeroesActiveTimer = 0;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickTimeWarpPowerUp()
{
	if (this->m_isActiveTimeWarpPowerUp)
	{
		this->m_timeWarpActiveTimer -= this->m_deltaTime;
		this->m_timeWarpActiveTimer = FMath::Clamp<float>(this->m_timeWarpActiveTimer, 0, this->m_timeWarpDelay);
	}
	else
	{
		this->m_timeWarpActiveTimer = 0;
	}

	//return;


	////	TODO: Implement or remove
	//if (this->m_isActiveTimeWarpPowerUp)
	//{
	//	//	TODO: slowdown enemies and weapons
	//	print("Time warp is active");

	//	UWorld *world = this->GetWorld();
	//	if (world != nullptr)
	//	{
	//		UGameplayStatics::SetGlobalTimeDilation(world, 0.5f);
	//		//this->CustomTimeDilation = 0.5f;
	//	}
	//}
	//else
	//{
	//	this->CustomTimeDilation = 1.0f;
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickIncreaseDamagePowerUp()
{
	if (this->m_isActiveIncreaseDamagePowerUp)
	{
		this->m_increaseDamageActiveTimer -= this->m_deltaTime;
		this->m_increaseDamageActiveTimer = FMath::Clamp<float>(this->m_increaseDamageActiveTimer, 0, this->m_increaseDamageDelay);
	}
	else
	{
		this->m_increaseDamageActiveTimer = 0;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickIncreaseEnergyPowerUp()
{
	if (this->m_isActiveIncreaseEnergyPowerUp)
	{
		this->m_increaseEnergyActiveTimer -= this->m_deltaTime;
		this->m_increaseEnergyActiveTimer = FMath::Clamp<float>(this->m_increaseEnergyActiveTimer, 0, this->m_increaseEnergyDelay);
	}
	else
	{
		this->m_increaseEnergyActiveTimer = 0;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TickIncreaseMovementSpeedPowerUp()
{
	if (this->m_isActiveIncreaseMovementSpeedPowerUp)
	{
		this->m_increaseMovementSpeedActiveTimer -= this->m_deltaTime;
		this->m_increaseMovementSpeedActiveTimer = FMath::Clamp<float>(this->m_increaseMovementSpeedActiveTimer, 0, this->m_increaseMovementSpeedDelay);
	}
	else
	{
		this->m_increaseMovementSpeedActiveTimer = 0;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetShieldPowerUp(bool enabled)
{
	this->m_isActiveShieldPowerUp = enabled;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetArmyOfHeroesPowerUp(bool enabled)
{
	this->m_isActiveArmyOfHeroesPowerUp = enabled;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetTimeWarpPowerUp(bool enabled)
{
	this->m_isActiveTimeWarpPowerUp = enabled;
	return;
	bool lastState = this->m_isActiveTimeWarpPowerUp;
	if (enabled)
	{
		UWorld *world = this->GetWorld();
		if (world != nullptr)
		{
			UGameplayStatics::SetGlobalTimeDilation(world, 0.25f);
			this->CustomTimeDilation = 4.0f;
		}
	}
	else
	{
		UWorld *world = this->GetWorld();
		if (world != nullptr)
		{
			UGameplayStatics::SetGlobalTimeDilation(world, 1.0f);
			this->CustomTimeDilation = 1.0f;
		}
	}

	//	Play function animation in BP_HeroRobot
	//	TODO: avoid multiples widgets
	if (!lastState)
	{
		UFunction *playTimeWarpUMGFunction = this->FindFunction(FName("cl_PlayTimeWarpUMG"));
		if (playTimeWarpUMGFunction != nullptr)
		{
			this->ProcessEvent(playTimeWarpUMGFunction, nullptr);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetIncreaseDamagePowerUp(bool enabled)
{
	this->m_isActiveIncreaseDamagePowerUp = enabled;
	if (enabled)
	{
		this->m_finalDamage = this->m_baseDamage * 10;
	}
	else
	{
		this->m_finalDamage = this->m_baseDamage;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetIncreaseEnergyPowerUp(bool enabled)
{
	this->m_isActiveIncreaseEnergyPowerUp = enabled;
	if (enabled)
	{
		this->m_maxEnergy = this->m_baseEnergy * 3;
		this->m_currentEnergy *= 3;
	}
	else
	{
		this->m_maxEnergy = this->m_baseEnergy;
		this->m_currentEnergy  = this->m_baseEnergy;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SetIncreaseMovementSpeedPowerUp(bool enabled)
{
	this->m_isActiveIncreaseMovementSpeedPowerUp = enabled;
	if (enabled)
	{
	}
	else
	{
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableShieldPowerUp(float timer)
{
	if (this->m_timerManager != nullptr)
	{
		this->SetShieldPowerUp(true);
		this->m_timerManager->SetTimer(this->m_shieldPowerUpTimer, this, &ACustomRobot::DisableShieldPowerUp, timer, true);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableArmyOfHeroesPowerUp(float timer)
{
	if (this->m_timerManager != nullptr)
	{
		this->SetArmyOfHeroesPowerUp(true);
		this->m_timerManager->SetTimer(this->m_armyOfHeroesPowerUpTimer, this, &ACustomRobot::DisableArmyOfHeroesPowerUp, timer, true);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableTimeWarpPowerUp(float timer)
{
	if (this->m_timerManager != nullptr)
	{
		this->SetTimeWarpPowerUp(true);
		this->m_timerManager->SetTimer(this->m_timeWarpPowerUpTimer, this, &ACustomRobot::DisableTimeWarpPowerUp, timer /*/ 4.0f*/, true);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableIncreaseDamagePowerUp(float timer)
{
	if (this->m_timerManager != nullptr)
	{
		this->SetIncreaseDamagePowerUp(true);
		this->m_timerManager->SetTimer(this->m_increaseDamagePowerUpTimer, this, &ACustomRobot::DisableIncreaseDamagePowerUp, timer, true);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableIncreaseEnergyPowerUp(float timer)
{
	if (this->m_timerManager != nullptr)
	{
		this->SetIncreaseEnergyPowerUp(true);
		this->m_timerManager->SetTimer(this->m_increaseEnergyPowerUpTimer, this, &ACustomRobot::DisableIncreaseEnergyPowerUp, timer, true);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableIncreaseMovementSpeedPowerUp(float timer)
{
	if (this->m_timerManager != nullptr)
	{
		this->SetIncreaseMovementSpeedPowerUp(true);
		this->m_timerManager->SetTimer(this->m_increaseMovementSpeedPowerUpTimer, this, &ACustomRobot::DisableIncreaseMovementSpeedPowerUp, timer, true);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::AcumulateShieldPowerUp(float appendTimer)
{
	float newTimer = this->m_timerManager->GetTimerRemaining(this->m_shieldPowerUpTimer) + appendTimer;
	this->m_timerManager->ClearTimer(this->m_shieldPowerUpTimer);
	this->SetShieldPowerUp(true);
	this->m_timerManager->SetTimer(this->m_shieldPowerUpTimer, this, &ACustomRobot::DisableShieldPowerUp, newTimer, true);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::AcumulateTimeWarpPowerUp(float appendTimer)
{
	float newTimer = this->m_timerManager->GetTimerRemaining(this->m_timeWarpPowerUpTimer) + appendTimer;
	this->m_timerManager->ClearTimer(this->m_timeWarpPowerUpTimer);
	this->SetTimeWarpPowerUp(true);
	this->m_timerManager->SetTimer(this->m_timeWarpPowerUpTimer, this, &ACustomRobot::DisableTimeWarpPowerUp, newTimer, true);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::AcumulateIncreaseDamagePowerUp(float appendTimer)
{
	float newTimer = this->m_timerManager->GetTimerRemaining(this->m_increaseDamagePowerUpTimer) + appendTimer;
	this->m_timerManager->ClearTimer(this->m_increaseDamagePowerUpTimer);
	this->SetIncreaseDamagePowerUp(true);
	this->m_timerManager->SetTimer(this->m_increaseDamagePowerUpTimer, this, &ACustomRobot::DisableIncreaseDamagePowerUp, newTimer, true);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::AcumulateIncreaseMovementSpeedPowerUp(float appendTimer)
{
	float newTimer = this->m_timerManager->GetTimerRemaining(this->m_increaseMovementSpeedPowerUpTimer) + appendTimer;
	this->m_timerManager->ClearTimer(this->m_increaseMovementSpeedPowerUpTimer);
	this->SetIncreaseMovementSpeedPowerUp(true);
	this->m_timerManager->SetTimer(this->m_increaseMovementSpeedPowerUpTimer, this, &ACustomRobot::DisableIncreaseMovementSpeedPowerUp, newTimer, true);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableShieldPowerUp()
{
	if (this->m_shieldGeometryCacheComponent != nullptr)
	{
		this->m_shieldGeometryCacheComponent->PlayReversedFromEnd();
	}
	this->SetShieldPowerUp(false);
	this->m_timerManager->ClearTimer(this->m_shieldPowerUpTimer);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableArmyOfHeroesPowerUp()
{
	this->SetArmyOfHeroesPowerUp(false);
	this->m_timerManager->ClearTimer(this->m_armyOfHeroesPowerUpTimer);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableTimeWarpPowerUp()
{
	this->SetTimeWarpPowerUp(false);
	this->m_timerManager->ClearTimer(this->m_timeWarpPowerUpTimer);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableIncreaseDamagePowerUp()
{
	this->SetIncreaseDamagePowerUp(false);
	this->m_timerManager->ClearTimer(this->m_increaseDamagePowerUpTimer);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableIncreaseEnergyPowerUp()
{
	this->SetIncreaseEnergyPowerUp(false);
	this->m_timerManager->ClearTimer(this->m_increaseEnergyPowerUpTimer);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::DisableIncreaseMovementSpeedPowerUp()
{
	this->SetIncreaseMovementSpeedPowerUp(false);
	this->m_timerManager->ClearTimer(this->m_increaseMovementSpeedPowerUpTimer);
}
#pragma endregion

#pragma region SKILL
//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangeSkillType(ESkillType skillType, uint8 index)
{
	switch (skillType)
	{
	case ESkillType::ST_Primary:
		this->ChangePrimarySkillType(static_cast<EPrimarySkillType>(index));
		break;
	case ESkillType::ST_Secondary:
		this->ChangeSecondarySkillType(static_cast<ESecondarySkillType>(index));
		break;
	case ESkillType::ST_Shield:
		this->ChangeShieldSkillType(static_cast<EShieldSkillType>(index));
		break;
	case ESkillType::ST_FullBatery:
		this->ChangeFullBatterySkillType(static_cast<EFullBatterySkillType>(index));
		break;
	case ESkillType::ST_ArmyOfHeroes:
		this->ChangeArmyOfHeroesSkillType(static_cast<EArmyOfHeroesSkillType>(index));
		break;
	case ESkillType::ST_PEM:
		this->ChangePEMSkillType(static_cast<EPEMSkillType>(index));
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::ISSkillUnlocked(ESkillType skillType, uint8 index)
{
	switch (skillType)
	{
	case ESkillType::ST_Primary:
		return this->m_primarySkillsUnlocked[index];
	case ESkillType::ST_Secondary:
		return this->m_secondarySkillsUnlocked[index];
	case ESkillType::ST_Shield:
		return this->m_shieldSkillsUnlocked[index];
	case ESkillType::ST_FullBatery:
		return this->m_fullBatterySkillsUnlocked[index];
	case ESkillType::ST_ArmyOfHeroes:
		return this->m_armyOfHeroesSkillsUnlocked[index];
	case ESkillType::ST_PEM:
		return this->m_pemSkillsUnlocked[index];
	default:
		break;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangePrimarySkillType(EPrimarySkillType type)
{
	return;
	this->m_primarySkillType = type;

	switch (type)
	{
	case EPrimarySkillType::PST_TypeA:
		//	Green
		this->m_primarySkillColor = FLinearColor(0.246f, 0.845f, 0, 1.0f);
		break;
	case EPrimarySkillType::PST_TypeB:
		//	Blue
		this->m_primarySkillColor = FLinearColor(0, 0.202f, 1.0f, 1.0f);
		break;
	case EPrimarySkillType::PST_TypeC:
		//	Orange
		this->m_primarySkillColor = FLinearColor(1.0, 0.136f, 0, 1.0f);
		break;
	}
	UWorld *world = this->GetWorld();
	if (this->m_heroMaterialParameterCollection != nullptr && world != nullptr)
	{
		UKismetMaterialLibrary::SetVectorParameterValue(world, this->m_heroMaterialParameterCollection, FName("PrimarySkillColor"), this->m_primarySkillColor);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangeSecondarySkillType(ESecondarySkillType type)
{
	this->m_secondarySkillType = type;

	switch (type)
	{
	case ESecondarySkillType::SST_TypeA:
		break;
	case ESecondarySkillType::SST_TypeB:
		break;
	case ESecondarySkillType::SST_TypeC:
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangeShieldSkillType(EShieldSkillType type)
{
	return;
	this->m_shieldSkillType = type;

	switch (type)
	{
	case EShieldSkillType::SST_TypeA:
		this->m_shieldColor = FLinearColor(0.75f, 0.07f, 0, 1.0f);
		break;
	case EShieldSkillType::SST_TypeB:
		this->m_shieldColor = FLinearColor(0.23f, 0.75f, 0, 1.0f);
		break;
	case EShieldSkillType::SST_TypeC:
		this->m_shieldColor = FLinearColor(0.1f, 0.09f, 0.75f, 1.0f);
		break;
	}

	UWorld *world = this->GetWorld();
	if (this->m_heroMaterialParameterCollection != nullptr && world != nullptr)
	{
		UKismetMaterialLibrary::SetVectorParameterValue(world, this->m_heroMaterialParameterCollection, FName("ShieldColor"), this->m_shieldColor);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangeFullBatterySkillType(EFullBatterySkillType type)
{
	this->m_fullBatterySkillType = type;

	switch (type)
	{
	case EFullBatterySkillType::FBST_TypeA:
		break;
	case EFullBatterySkillType::FBST_TypeB:
		break;
	case EFullBatterySkillType::FBST_TypeC:
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangeArmyOfHeroesSkillType(EArmyOfHeroesSkillType type)
{
	this->m_armyOfHeroesSkillType = type;

	switch (type)
	{
	case EArmyOfHeroesSkillType::AHST_TypeA:
		break;
	case EArmyOfHeroesSkillType::AHST_TypeB:
		break;
	case EArmyOfHeroesSkillType::AHST_TypeC:
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ChangePEMSkillType(EPEMSkillType type)
{
	this->m_PEMSkillType = type;

	//	TODO: Change PEM to EMP
	switch (type)
	{
	case EPEMSkillType::PST_Destruction:
		break;
	case EPEMSkillType::PST_HackSystem:
		break;
	case EPEMSkillType::PST_TypeC:
		break;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::EnableWalk()
{
	this->m_enableWalk = true;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ShootNormalBlast()
{
	if (this->m_heroIsDead)
	{
		return;
	}

	bool thisFunctionDebug = false;

	//	TODO face shoot direction
	this->m_enableWalk = false;
	this->m_timerManager->SetTimer(this->m_walkDelayTimer, this, &ACustomRobot::EnableWalk, 0.3f, false);

	//  Convert screen to world coordinates
	FVector aim3DPosition;
	FVector aim3DDirection;
	FVector cameraDirection;
	FVector actorLocation;
	FHitResult hit;
	TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		//  Get player controller
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//  Get camera vector
			FVector cameraLocation = playerController->PlayerCameraManager->GetCameraLocation();
			actorLocation = this->GetActorLocation();
			cameraDirection = actorLocation - cameraLocation;
			cameraDirection.Normalize();

			//  Get hit location as screen position
			playerController->GetHitResultAtScreenPosition(this->m_aimCursorScreenPosition, objectTypes, true, hit);
		}
		this->m_aimCursorLastWorldPosition = hit.Location;

		FVector minVectorDistance = actorLocation - FVector(hit.Location.X, hit.Location.Y, actorLocation.Z);
		minVectorDistance.Normalize();
		minVectorDistance *= 1000.0f;
		FVector adjustHitLocation = actorLocation + minVectorDistance;

		//	Get socket positions
		FTransform transformLeftGun;
		transformLeftGun.SetLocation(this->m_leftWeaponSocket->GetComponentLocation());
		FRotator rotation = UKismetMathLibrary::FindLookAtRotation(this->m_leftWeaponSocket->GetComponentLocation(), adjustHitLocation);
		transformLeftGun.SetRotation(rotation.Quaternion());

		FTransform transformRightGun;
		transformRightGun.SetLocation(this->m_rightWeaponSocket->GetComponentLocation());
		rotation = UKismetMathLibrary::FindLookAtRotation(this->m_rightWeaponSocket->GetComponentLocation(), adjustHitLocation);
		transformRightGun.SetRotation(rotation.Quaternion());

		//  Spawn a projetile
		TArray<float> angles;
		angles.Add(14.0f);
		angles.Add(7.0f);
		angles.Add(0);
		angles.Add(-7.0f);
		angles.Add(-14.0f);

		int damage = 0;
		//	Spawn left bullet
		if (this->m_bulletProjectileNormal != nullptr)
		{
			for (int i = 0; i < angles.Num(); i++)
			{
				ABulletProjectile* leftProjectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileNormal, transformLeftGun);
				if (leftProjectile != nullptr)
				{
					FVector desiredVector = adjustHitLocation;
					float multiplierZ = actorLocation.Z / cameraDirection.Z;
					cameraDirection *= multiplierZ;
					FVector desiredTarget = desiredVector + cameraDirection;
					FRotator rotationProjectile = UKismetMathLibrary::FindLookAtRotation(desiredTarget, transformLeftGun.GetLocation());
					rotationProjectile.Yaw += angles[i];
					FVector velocityProjectile = desiredTarget - transformLeftGun.GetLocation();
					velocityProjectile.Normalize();
					velocityProjectile = velocityProjectile.RotateAngleAxis(angles[i], FVector::UpVector);

					transformLeftGun.SetScale3D(FVector(4.0f, 4.0f, 4.0f));
					leftProjectile->SetActorRotation(rotationProjectile);
					leftProjectile->m_velocity = velocityProjectile * 2000.0f;
					leftProjectile->m_weaponOwner = EWeaponOwner::WO_Player;
					leftProjectile->m_speed = 1;
					leftProjectile->m_lifetime = 1.5f;

					//	Set inverse Time dilation
					if (this->m_isActiveTimeWarpPowerUp)
					{
						leftProjectile->CustomTimeDilation = 4.0f;
					}

					//	Set damage
					leftProjectile->m_damage = this->m_finalDamage;// this->m_heroStat.m_finalDamage.GetValue() / 5;

					//	Finish spawn actor
					UGameplayStatics::FinishSpawningActor(leftProjectile, transformLeftGun);
				}

				//	Spawn right bullet
				ABulletProjectile* rightProjectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileNormal, transformRightGun);
				if (rightProjectile != nullptr)
				{
					FVector desiredVector = adjustHitLocation;
					float multiplierZ = actorLocation.Z / cameraDirection.Z;
					cameraDirection *= multiplierZ;
					FVector desiredTarget = desiredVector + cameraDirection;
					FRotator rotationProjectile = UKismetMathLibrary::FindLookAtRotation(desiredTarget, transformRightGun.GetLocation());
					rotationProjectile.Yaw += angles[i];
					FVector velocityProjectile = desiredTarget - transformRightGun.GetLocation();
					velocityProjectile.Normalize();
					velocityProjectile = velocityProjectile.RotateAngleAxis(angles[i], FVector::UpVector);

					transformRightGun.SetScale3D(FVector(4.0f, 4.0f, 4.0f));
					rightProjectile->SetActorRotation(rotationProjectile);
					rightProjectile->m_velocity = velocityProjectile * 2000.0f;
					rightProjectile->m_weaponOwner = EWeaponOwner::WO_Player;
					rightProjectile->m_speed = 1;
					rightProjectile->m_lifetime = 1.5f;

					//	Set inverse Time dilation
					if (this->m_isActiveTimeWarpPowerUp)
					{
						rightProjectile->CustomTimeDilation = 4.0f;
					}

					//	Set damage
					rightProjectile->m_damage = this->m_finalDamage;// this->m_heroStat.m_finalDamage.GetValue() / 5;

					//	Finish spawn actor
					UGameplayStatics::FinishSpawningActor(rightProjectile, transformRightGun);
				}
			}
		}

		if (thisFunctionDebug)
		{
			//	Append damage number for test
			AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
			if (gameMode != nullptr)
			{
				//APlayerController *playerController = GetWorld()->GetFirstPlayerController();
				if (playerController != nullptr)
				{
					FVector2D screenPosition;
					FVector position = this->GetActorLocation();
					playerController->ProjectWorldLocationToScreen(position, screenPosition);
					screenPosition += FVector2D(FMath::FRandRange(-1.0f, 1.0f), FMath::FRandRange(-1.0f, 1.0f)) * 50;
					//gameMode->AppendDamageNumbers(damage, screenPosition, EDamageType::DT_Normal);
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::ShootHyperBlast(float intensity)
{
	bool thisFunctionDebug = false;
	float projetileSpeed = 5.0f;
	float projetileLifeTime = 0.4f;
	float projetileScale = 1.5f;

	if (this->m_heroIsDead)
	{
		return;
	}
	
	if (this->m_godMode.GetValue())
	{
	}

	//  Convert screen to world coordinates
	FVector aim3DPosition;
	FVector aim3DDirection;
	FVector cameraDirection;
	FVector actorLocation;
	FHitResult hit;
	TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));

	//  Get player controller
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//  Get hit location as screen position
			playerController->GetHitResultAtScreenPosition(this->m_aimCursorScreenPosition, objectTypes, true, hit);
	
			//  Get camera vector
			FVector targetLocation = hit.Location;
			FVector cameraLocation = playerController->PlayerCameraManager->GetCameraLocation();
			actorLocation = this->GetActorLocation();
			cameraDirection = cameraLocation - actorLocation;
			cameraDirection.Normalize();
		}

		this->m_aimCursorLastWorldPosition = hit.Location;
		this->m_aimCursorLastWorldPosition.Z = actorLocation.Z;	//	Keep same height
		float minVectorDistanceFromHero = 1000.0f;
		FVector desiredHitPosition = hit.Location;
		desiredHitPosition.Z = actorLocation.Z;
		if (FVector::Dist(actorLocation, hit.Location) <= minVectorDistanceFromHero)
		{
			desiredHitPosition = FVector(hit.Location.X, hit.Location.Y, actorLocation.Z) - actorLocation;
			desiredHitPosition.Normalize();
			desiredHitPosition = actorLocation + (desiredHitPosition * minVectorDistanceFromHero);
		}

#ifndef SHIPPING_GAME_VERSION
		DrawDebugPoint(world, desiredHitPosition, 10, FColor(255, 255, 255), false, 5.0f, -1);
		DrawDebugLine(
			world,
			this->GetActorLocation(),
			desiredHitPosition,
			FColor(255, 255, 255),
			false,
			5.0f, 10.0f);
#endif	//SHIPPING_GAME_VERSION

		//	Get socket positions
		USkeletalMeshComponent *skeletalMesh = this->GetMesh();
		if (skeletalMesh != nullptr)
		{
			FTransform transformLeftGun;
			transformLeftGun.SetLocation(skeletalMesh->GetSocketLocation(FName("LeftMachineGun_Center")));
			FRotator rotation = UKismetMathLibrary::FindLookAtRotation(transformLeftGun.GetLocation(), desiredHitPosition);
			transformLeftGun.SetRotation(rotation.Quaternion());

			FTransform transformRightGun;
			transformRightGun.SetLocation(skeletalMesh->GetSocketLocation(FName("RightMachineGun_Center")));
			rotation = UKismetMathLibrary::FindLookAtRotation(transformRightGun.GetLocation(), desiredHitPosition);
			transformRightGun.SetRotation(rotation.Quaternion());

			//  Spawn a projetile
			TArray<float> angles;
			angles.Add(-20.0f);
			angles.Add(-10.0f);
			angles.Add(0);
			angles.Add(10.0f);
			angles.Add(20.0f);

			int currentDamage = 0;
			if (this->m_bulletProjectileHyper != nullptr)
			{
				for (int32 i = 0; i < angles.Num(); i++)
				{
					//	Spawn left bullet
					ABulletProjectile* leftProjectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileHyper, transformLeftGun);
					if (leftProjectile != nullptr)
					{
						//	Get Target
						FVector desiredVector = desiredHitPosition;
						float multiplierZ = actorLocation.Z / cameraDirection.Z;
						FVector tempCameraDirection = cameraDirection;
						tempCameraDirection *= multiplierZ;
						FVector desiredTarget = desiredVector + tempCameraDirection;
					
						//	Get rotation
						FRotator rotationProjectile = UKismetMathLibrary::FindLookAtRotation(transformLeftGun.GetLocation(), FVector(desiredTarget.X, desiredTarget.Y, transformLeftGun.GetLocation().Z));
						rotationProjectile.Yaw += angles[i];
					
						//	Get direction
						FVector velocityProjectile = desiredTarget - transformLeftGun.GetLocation();
						velocityProjectile.Z = 0;
						velocityProjectile.Normalize();
						velocityProjectile = velocityProjectile.RotateAngleAxis(angles[i], FVector::UpVector);

						//	Set attribs
						leftProjectile->m_velocity = velocityProjectile * 2000.0f;
						leftProjectile->m_weaponOwner = EWeaponOwner::WO_Player;
						leftProjectile->m_speed = projetileSpeed;
						leftProjectile->m_lifetime = projetileLifeTime;
						leftProjectile->m_damage = this->m_finalDamage;

						//	Set inverse Time dilation
						if (this->m_isActiveTimeWarpPowerUp)
						{
							leftProjectile->CustomTimeDilation = 4.0f;
						}

						//	Finish spawn actor
						FTransform projectileTransform;
						projectileTransform.SetLocation(transformLeftGun.GetLocation());
						projectileTransform.SetRotation(rotationProjectile.Quaternion());
						projectileTransform.SetScale3D(FVector(projetileScale));
						UGameplayStatics::FinishSpawningActor(leftProjectile, projectileTransform);
					}

					//	Spawn right bullet
					ABulletProjectile* rightProjectile = world->SpawnActorDeferred<ABulletProjectile>(this->m_bulletProjectileHyper, transformRightGun);
					if (rightProjectile != nullptr)
					{
						//	Get Target
						FVector desiredVector = desiredHitPosition;
						float multiplierZ = actorLocation.Z / cameraDirection.Z;
						FVector tempCameraDirection = cameraDirection;
						tempCameraDirection *= multiplierZ;
						FVector desiredTarget = desiredVector + tempCameraDirection;

						//	Get rotation
						FRotator rotationProjectile = UKismetMathLibrary::FindLookAtRotation(transformRightGun.GetLocation(), FVector(desiredTarget.X, desiredTarget.Y, transformLeftGun.GetLocation().Z));
						rotationProjectile.Yaw += angles[i];

						//	Get direction
						FVector velocityProjectile = desiredTarget - transformRightGun.GetLocation();
						velocityProjectile.Z = 0;
						velocityProjectile.Normalize();
						velocityProjectile = velocityProjectile.RotateAngleAxis(angles[i], FVector::UpVector);

						//	Set attribs
						rightProjectile->m_velocity = velocityProjectile * 2000.0f;
						rightProjectile->m_weaponOwner = EWeaponOwner::WO_Player;
						rightProjectile->m_speed = projetileSpeed;
						rightProjectile->m_lifetime = projetileLifeTime;
						rightProjectile->m_damage = this->m_finalDamage;

						//	Set inverse Time dilation
						if (this->m_isActiveTimeWarpPowerUp)
						{
							rightProjectile->CustomTimeDilation = 4.0f;
						}

						//	Finish spawn actor
						FTransform projectileTransform;
						projectileTransform.SetLocation(transformRightGun.GetLocation());
						projectileTransform.SetRotation(rotationProjectile.Quaternion());
						projectileTransform.SetScale3D(FVector(projetileScale));
						UGameplayStatics::FinishSpawningActor(rightProjectile, projectileTransform);
					}
				}
			}

			if (thisFunctionDebug)
			{
				//	Append damage number for test
				AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(world));
				if (gameMode != nullptr)
				{
					//APlayerController *playerController = GetWorld()->GetFirstPlayerController();
					if (playerController != nullptr)
					{
						FVector2D screenPosition;
						FVector position = this->GetActorLocation();
						playerController->ProjectWorldLocationToScreen(position, screenPosition);
						screenPosition += FVector2D(FMath::FRandRange(-1.0f, 1.0f), FMath::FRandRange(-1.0f, 1.0f)) * 50;
						//gameMode->AppendDamageNumbers(currentDamage, screenPosition, EDamageType::DT_Normal);
					}
				}
			}
		}
	}
}
#pragma endregion

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TakeLaserDamagePerTimeStep(int damage, float timeStep)
{
	if (!this->m_isActiveShieldPowerUp)
	{
		if (!this->m_timerManager->IsTimerActive(this->m_laserDamageTimer))
		{
			this->m_laserDamageDelegate = FTimerDelegate::CreateUObject(this, &ACustomRobot::TakeLaserDamage, damage);
			this->m_timerManager->SetTimer(this->m_laserDamageTimer, this->m_laserDamageDelegate, timeStep, false);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::TakeLaserDamage(int damage)
{
	this->m_currentEnergy -= damage;
	this->m_firstFrameTakeDamage = true;

	//	TODO: remove isto

	//	Append damage number
	//AArenaGameMode *gameMode = Cast<AArenaGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	//if (gameMode != nullptr)
	//{
	//	APlayerController *playerController = GetWorld()->GetFirstPlayerController();
	//	if (playerController != nullptr)
	//	{
	//		FVector2D screenPosition;
	//		FVector position = GetActorLocation();
	//		playerController->ProjectWorldLocationToScreen(position, screenPosition);
	//		screenPosition += FVector2D(FMath::FRandRange(-1.0f, 1.0f), FMath::FRandRange(-1.0f, 1.0f)) * 50;
	//		gameMode->AppendDamageNumbers(damage, screenPosition, EDamageType::DT_Normal);
	//	}
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::GetHitResult(FVector &hitLocation) const
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		FHitResult hit;
		TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
		objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		//	Get player controller
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//	TODO: remove isto
			////	Get camera vector
			//FVector cameraLocation = playerController->PlayerCameraManager->GetCameraLocation();
			//actorLocation = GetActorLocation();
			//cameraDirection = actorLocation - cameraLocation;
			//cameraDirection.Normalize();

			//	Get hit location as screen position
			playerController->GetHitResultAtScreenPosition(this->m_aimCursorScreenPosition, objectTypes, true, hit);
		}
		hitLocation = hit.Location;
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::GetLookAtVector(FRotator &lookAtVector) const
{
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		FHitResult hit;
		TArray<TEnumAsByte<EObjectTypeQuery> > objectTypes;
		objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		//objectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		//	Get player controller
		APlayerController *playerController = world->GetFirstPlayerController();
		if (playerController != nullptr)
		{
			//	Get camera vector
			FVector cameraLocation = playerController->PlayerCameraManager->GetCameraLocation();
			FVector actorLocation = this->GetActorLocation();
			FVector cameraDirection = actorLocation - cameraLocation;
			cameraDirection.Normalize();

			//	Get hit location as screen position
			playerController->GetHitResultAtScreenPosition(this->m_aimCursorScreenPosition, objectTypes, true, hit);

			//	Get lookat vector
			FVector desiredVector = hit.Location;
			float multiplierZ = actorLocation.Z / cameraDirection.Z;
			cameraDirection *= multiplierZ;
			FVector desiredTarget = desiredVector + cameraDirection;
			desiredTarget.Z = actorLocation.Z;
			lookAtVector = UKismetMathLibrary::FindLookAtRotation(actorLocation, desiredTarget);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnLevelUpFX() const
{
	//  Spawn levelUP blueprint
	UWorld *world = this->GetWorld();
	if (m_levelUP_BP != nullptr && world != nullptr)
	{
		//	Set transform
		FTransform transform;
		transform.SetLocation(this->GetActorLocation());

		AActor* levelUP = world->SpawnActor<AActor>(this->m_levelUP_BP, transform);
		if (levelUP != nullptr)
		{
			//	TODO attach this actor to hero
		}
	}
}

#pragma region STATS
//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetDamage()
{
	//	Damage equation
	//	http://diablo.blizzpro.com/2014/05/17/basic-theorycrafting-damage-formula/
	//	http://diablodamagecalculator.com/
	//	http://diablodamagecalculator.com/js/calculate.js

	float weaponDamage = static_cast<float>(this->m_heroStat.m_baseDamage.GetValue());
	float itemBonusDamage = 0;
	float averageDamage = weaponDamage + itemBonusDamage;

	float weaponAttackSpeed = static_cast<float>(this->GetAttackSpeedWeapon()) / 100.0f;
	float attackSpeedFromItens = static_cast<float>(this->GetAttackSpeedBonus()) / 100.0f;
	float attackSpeed = weaponAttackSpeed * (1.0f + attackSpeedFromItens);
	
	float dynamicForceStats = 1.0f + (static_cast<float>(this->GetDynamicForcePoints()) / 100.0f);
	
	float criticalStrikeDamage = static_cast<float>(this->GetCriticalStrikeDamage()) / 100.0f;
	float criticalStrikeChance = static_cast<float>(this->GetCriticalStrikeChance()) / 100.0f;
	float criticalFactor = 1.0f + (criticalStrikeDamage * criticalStrikeChance);
	
	float finalDamage = averageDamage * dynamicForceStats * criticalFactor * attackSpeed;

	this->m_heroStat.m_finalDamage = static_cast<int32>(finalDamage);
	return this->m_heroStat.m_finalDamage.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetAttackSpeedWeapon()
{
	return this->m_heroStat.m_attackSpeedWeapon.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetAttackSpeedBonus()
{
	int32 attackSpeedBonus = 0;
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			attackSpeedBonus = this->m_heroStat.m_attackSpeedBonus.GetValue() + gameInstance->m_bitbotsDistribution.m_attackSpeedBitBots;
		}
	}
	return attackSpeedBonus;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetAttackSpeed()
{
	float attackSpeed = 0;
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			int32 attackSpeedBonus = this->m_heroStat.m_attackSpeedBonus.GetValue() + gameInstance->m_bitbotsDistribution.m_attackSpeedBitBots;
			attackSpeed = (static_cast<float>(this->m_heroStat.m_attackSpeedWeapon.GetValue()) / 100.0f) * (1.0f + (static_cast<float>(attackSpeedBonus) / 100.0f));
		}
	}
	return attackSpeed;
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetCriticalStrikeChance()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return m_heroStat.m_criticalStrikeChance.GetValue() + gameInstance->m_bitbotsDistribution.m_criticalStrikeChanceBitBots;
		}
	}
	return this->m_heroStat.m_criticalStrikeChance.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetCriticalStrikeDamage()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_criticalStrikeDamage.GetValue() + gameInstance->m_bitbotsDistribution.m_criticalStrikeDamageBitBots;
		}
	}
	return this->m_heroStat.m_criticalStrikeDamage.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetMaxEnergy()
{
	int32 finalEnergy = 0;

	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			int32 energyPoints = this->m_heroStat.m_energyPoints.GetValue() + gameInstance->m_bitbotsDistribution.m_EnergyBitBots;
			float maxEnergy = static_cast<float>(this->m_baseEnergy) + static_cast<float>(energyPoints);
			maxEnergy += maxEnergy * (static_cast<float>(this->m_heroStat.m_energyPercent.GetValue()) / 100.0f);
			finalEnergy = static_cast<int32>(maxEnergy);
		}
	}
	return finalEnergy;
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetEnergyPoints()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_energyPoints.GetValue() + gameInstance->m_bitbotsDistribution.m_EnergyBitBots;
		}
	}
	return this->m_heroStat.m_energyPoints.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetEnergyPercent()
{
	return this->m_heroStat.m_energyPercent.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetDynamicForcePoints()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_dynamicForcePoints.GetValue() + gameInstance->m_bitbotsDistribution.m_dynamicForceBitBots;
		}
	}
	return this->m_heroStat.m_dynamicForcePoints.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetMovementSpeed()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_movementSpeed.GetValue() + gameInstance->m_bitbotsDistribution.m_movementSpeedBitBots;
		}
	}
	return this->m_heroStat.m_movementSpeed.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetEnergySteal()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_energySteal.GetValue() + gameInstance->m_bitbotsDistribution.m_energyStealBitBots;
		}
	}
	return this->m_heroStat.m_energySteal.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetEnergyPerHit()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_energyPerhit.GetValue() + gameInstance->m_bitbotsDistribution.m_energyPerHitBitBots;
		}
	}
	return this->m_heroStat.m_energyPerhit.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetEnergyPerKill()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_energyPerKill.GetValue() + gameInstance->m_bitbotsDistribution.m_energyPerKillBitBots;
		}
	}
	return this->m_heroStat.m_energyPerKill.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetEnergyPerSecond()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_energyPerSecond.GetValue() + gameInstance->m_bitbotsDistribution.m_energyPerSecondBitBots;
		}
	}
	return this->m_heroStat.m_energyPerSecond.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetDamageReduction()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_damageReduction.GetValue() + gameInstance->m_bitbotsDistribution.m_damageReductionBitBots;
		}
	}
	return this->m_heroStat.m_damageReduction.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetBitBots()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_bitbots.GetValue() + gameInstance->m_bitbotsDistribution.m_maxBitBots;
		}
	}
	return this->m_heroStat.m_bitbots.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetRobotsKillGrantXP()
{
	return this->m_heroStat.m_experiencePerKill.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetTechnologyFind()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_technologyFind.GetValue() + gameInstance->m_bitbotsDistribution.m_technologyFindBitBots;
		}
	}
	return this->m_heroStat.m_technologyFind.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetCooldownReductionSkill_A()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_cooldownReductionSkill_A.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue() + gameInstance->m_bitbotsDistribution.m_cooldownSkill_A_BitBots;
		}
	}
	return this->m_heroStat.m_cooldownReductionSkill_A.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetCooldownReductionSkill_B()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_cooldownReductionSkill_B.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue() + gameInstance->m_bitbotsDistribution.m_cooldownSkill_B_BitBots;
		}
	}
	return this->m_heroStat.m_cooldownReductionSkill_B.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetCooldownReductionSkill_C()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_cooldownReductionSkill_C.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue() + gameInstance->m_bitbotsDistribution.m_cooldownSkill_C_BitBots;
		}
	}
	return this->m_heroStat.m_cooldownReductionSkill_C.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
int32 ACustomRobot::GetCooldownReductionSkill_D()
{
	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			return this->m_heroStat.m_cooldownReductionSkill_D.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue() + gameInstance->m_bitbotsDistribution.m_cooldownSkill_D_BitBots;
		}
	}
	return this->m_heroStat.m_cooldownReductionSkill_D.GetValue() + this->m_heroStat.m_cooldownReductionAllSkills.GetValue();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateLeftWeaponStats(FLootInfo loot)
{
	this->m_equipment[0] = loot;
	this->UpdateHeroStats();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateRightWeaponStats(FLootInfo loot)
{
	this->m_equipment[1] = loot;
	this->UpdateHeroStats();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateMicrochipStats(FLootInfo loot)
{
	this->m_equipment[2] = loot;
	this->UpdateHeroStats();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateJetpackStats(FLootInfo loot)
{
	this->m_equipment[3] = loot;
	this->UpdateHeroStats();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateCellEnergyStats(FLootInfo loot)
{
	this->m_equipment[4] = loot;
	this->UpdateHeroStats();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateLootStats(TArray<FLootInfo> loots)
{
	for (int i = 0; i < loots.Num(); i++)
	{
		this->m_equipment[i] = loots[i];
	}
	this->UpdateHeroStats();
	this->UpdateMovementSpeedFromLoot();
	this->UpdateEnergyFromLoot();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateHeroStats()
{
#ifndef SHIPPING_GAME_VERSION
	print("UpdateHeroStats");
#endif  //SHIPPING_GAME_VERSION

	TArray<FBaseStat> baseStats;
	TArray<FPrimaryStat> primaryStats;
	TArray<FSecondaryStat> secondaryStats;
	TArray<FBonusStat> bonusStats;
	bool existFirstWeapon = false;
	bool existSecondWeapon = false;

	this->m_heroStat = FHeroStat();

	//  Get equipments
	for (int i = 0; i < this->m_equipment.Num(); i++)
	{
		if (this->m_equipment[i].m_baseStats.Num() > 0)
		{
			if (i == 0)
			{
				existFirstWeapon = true;
			}
			if (i == 1)
			{
				existSecondWeapon = true;
			}
			baseStats.Append(this->m_equipment[i].m_baseStats);
		}
		if (this->m_equipment[i].m_primaryStats.Num() > 0)
		{
			primaryStats.Append(this->m_equipment[i].m_primaryStats);
		}
		if (m_equipment[i].m_secondaryStats.Num() > 0)
		{
			secondaryStats.Append(this->m_equipment[i].m_secondaryStats);
		}
		if (m_equipment[i].m_bonusStats.Num() > 0)
		{
			bonusStats.Append(this->m_equipment[i].m_bonusStats);
		}
	}

	//	Base stats
	if (baseStats.Num() > 0)
	{
		for (auto i = 0; i < baseStats.Num(); i++)
		{
			switch (baseStats[i].m_stat)
			{
				case EBaseStat::BS_BaseDamage:
					this->m_heroStat.m_baseDamage += baseStats[i].m_value.GetValue();
					//m_heroStat.m_baseDamage += baseStats[i].m_value;
					continue;
				case EBaseStat::BS_WeaponColor:
					this->m_heroStat.m_weaponColor = baseStats[i].m_value.GetValue();
					//m_heroStat.m_weaponColor = baseStats[i].m_value;
					continue;
				case EBaseStat::BS_AttackSpeedWeapon:
					this->m_heroStat.m_attackSpeedWeapon += baseStats[i].m_value.GetValue();
					//m_heroStat.m_attackSpeedWeapon += baseStats[i].m_value;
			}
		}
		if (existFirstWeapon && existSecondWeapon)
		{
			this->m_heroStat.m_attackSpeedWeapon /= 2;
		}
	}

	//  Primary stats
	if (primaryStats.Num() > 0)
	{
		for (auto i = 0; i < primaryStats.Num(); i++)
		{
			switch (primaryStats[i].m_stat)
			{
			case EPrimaryStat::PS_AttackSpeedBonus:
				this->m_heroStat.m_attackSpeedBonus += primaryStats[i].m_value.GetValue();
				//m_heroStat.m_attackSpeedBonus += primaryStats[i].m_value;
				continue;
			case EPrimaryStat::PS_CriticalStrikeChance:
				this->m_heroStat.m_criticalStrikeChance += primaryStats[i].m_value.GetValue();
				//m_heroStat.m_criticalStrikeChance += primaryStats[i].m_value;
				continue;
			case EPrimaryStat::PS_CriticalStrikeDamage:
				this->m_heroStat.m_criticalStrikeDamage += primaryStats[i].m_value.GetValue();
				//m_heroStat.m_criticalStrikeDamage += primaryStats[i].m_value;
				continue;
			case EPrimaryStat::PS_IncreaseEnergy:
				this->m_heroStat.m_energyPoints += primaryStats[i].m_value.GetValue();
				//m_heroStat.m_energyPoints += primaryStats[i].m_value;
				continue;
			case EPrimaryStat::PS_IncreaseDynamicForce:
				this->m_heroStat.m_dynamicForcePoints += primaryStats[i].m_value.GetValue();
				//m_heroStat.m_dynamicForcePoints += primaryStats[i].m_value;
				continue;
			case EPrimaryStat::PS_EnergyPercent:
				//m_heroStat.m_energyPercent += primaryStats[i].m_value;
				this->m_heroStat.m_energyPercent += primaryStats[i].m_value.GetValue();
			}
		}
	}
	//  Secondary stats
	if (secondaryStats.Num() > 0)
	{
		for (auto j = 0; j < secondaryStats.Num(); j++)
		{
			switch (secondaryStats[j].m_stat)
			{
			case ESecondaryStat::SS_MovementSpeed:
				this->m_heroStat.m_movementSpeed += secondaryStats[j].m_value.GetValue();
				//m_heroStat.m_movementSpeed += secondaryStats[j].m_value;
				continue;
			case ESecondaryStat::SS_EnergySteal:
				this->m_heroStat.m_energySteal += secondaryStats[j].m_value.GetValue();
				//m_heroStat.m_energySteal += secondaryStats[j].m_value;
				continue;
			case ESecondaryStat::SS_EnergyPerHit:
				this->m_heroStat.m_energyPerhit += secondaryStats[j].m_value.GetValue();
				//m_heroStat.m_energyPerhit += secondaryStats[j].m_value;
				continue;
			case ESecondaryStat::SS_EnergyPerKill:
				this->m_heroStat.m_energyPerKill += secondaryStats[j].m_value.GetValue();
				//m_heroStat.m_energyPerKill += secondaryStats[j].m_value;
				continue;
			case ESecondaryStat::SS_EnergyPerSecond:
				this->m_heroStat.m_energyPerSecond += secondaryStats[j].m_value.GetValue();
				//m_heroStat.m_energyPerSecond += secondaryStats[j].m_value;
				continue;
			case ESecondaryStat::SS_DamageReduction:
				//m_heroStat.m_damageReduction += secondaryStats[j].m_value;
				this->m_heroStat.m_damageReduction += secondaryStats[j].m_value.GetValue();
			}
		}
	}

	//  Bonus stats
	if (bonusStats.Num() > 0)
	{
		for (int j = 0; j < bonusStats.Num(); j++)
		{
			switch (bonusStats[j].m_stat)
			{
			case EBonusStat::BS_BitBots:
				this->m_heroStat.m_bitbots += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_bitbots += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_RobotsKillGrantXP:
				this->m_heroStat.m_experiencePerKill += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_experiencePerKill += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_TechnologyFind:
				this->m_heroStat.m_technologyFind += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_technologyFind += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_CooldownReductionSkill_A:
				this->m_heroStat.m_cooldownReductionSkill_A += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_cooldownReductionSkill_A += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_CooldownReductionSkill_B:
				this->m_heroStat.m_cooldownReductionSkill_B += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_cooldownReductionSkill_B += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_CooldownReductionSkill_C:
				this->m_heroStat.m_cooldownReductionSkill_C += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_cooldownReductionSkill_C += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_CooldownReductionSkill_D:
				this->m_heroStat.m_cooldownReductionSkill_D += bonusStats[j].m_value.GetValue();
				//m_heroStat.m_cooldownReductionSkill_D += bonusStats[j].m_value;
				continue;
			case EBonusStat::BS_CooldownReductionAllSkills:
				//m_heroStat.m_cooldownReductionAllSkills += bonusStats[j].m_value;
				this->m_heroStat.m_cooldownReductionAllSkills += bonusStats[j].m_value.GetValue();
			}
		}
	}

	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			//	Update movement speed
			int32 movementSpeedPoints = this->m_heroStat.m_movementSpeed.GetValue() + gameInstance->m_bitbotsDistribution.m_movementSpeedBitBots;
			this->GetCharacterMovement()->MaxWalkSpeed = this->m_baseMovementSpeed + (this->m_baseMovementSpeed * static_cast<float>(movementSpeedPoints) / 100.0f);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetNewDamagePercentIfEquipped(int32 lootIndex, FLootInfo loot)
{
	this->UpdateHeroStats();
	int32 currentDamage = GetDamage();
	int32 differenceDamage = 0;
	int32 iBaseDamage = 0;
	int32 iAttackSpeedWeapon = 0;
	int32 iAttackSpeedBonus = 0;
	int32 iCriticalStrikeChance = 0;
	int32 iCriticalStrikeDamage = 0;
	int32 iDynamicForcePoints = 0;
	bool existFirstWeapon = false;
	bool existSecondWeapon = false;

	TArray<FBaseStat> baseStatsArray;
	TArray<FPrimaryStat> primaryStatsArray;

	//  Get equipments
	for (auto i = 0; i < m_equipment.Num(); i++)
	{
		if (lootIndex == i)
		{
			if (loot.m_baseStats.Num() > 0)
			{
				if (i == 0)
				{
					existFirstWeapon = true;
				}
				if (i == 1)
				{
					existSecondWeapon = true;
				}
				baseStatsArray.Append(loot.m_baseStats);
			}
			if (loot.m_primaryStats.Num() > 0)
			{
				primaryStatsArray.Append(loot.m_primaryStats);
			}
		}
		else
		{
			if (this->m_equipment[i].m_baseStats.Num() > 0)
			{
				if (i == 0)
				{
					existFirstWeapon = true;
				}
				if (i == 1)
				{
					existSecondWeapon = true;
				}
				baseStatsArray.Append(this->m_equipment[i].m_baseStats);
			}
			if (this->m_equipment[i].m_primaryStats.Num() > 0)
			{
				primaryStatsArray.Append(this->m_equipment[i].m_primaryStats);
			}
		}
	}

	//	Base
	if (baseStatsArray.Num() > 0)
	{
		for (auto i = 0; i < baseStatsArray.Num(); i++)
		{
			switch (baseStatsArray[i].m_stat)
			{
			case EBaseStat::BS_BaseDamage:
				iBaseDamage += baseStatsArray[i].m_value.GetValue();
				//iBaseDamage += baseStatsArray[i].m_value;
				continue;
			case EBaseStat::BS_AttackSpeedWeapon:
				iAttackSpeedWeapon += baseStatsArray[i].m_value.GetValue();
				//iAttackSpeedWeapon += baseStatsArray[i].m_value;
			}
		}
		if (existFirstWeapon && existSecondWeapon)
		{
			iAttackSpeedWeapon /= 2;
		}
	}

	//	Primary
	if (primaryStatsArray.Num() > 0)
	{
		for (auto i = 0; i < primaryStatsArray.Num(); i++)
		{
			switch (primaryStatsArray[i].m_stat)
			{
			case EPrimaryStat::PS_AttackSpeedBonus:
				iAttackSpeedBonus += primaryStatsArray[i].m_value.GetValue();
				//iAttackSpeedBonus += primaryStatsArray[i].m_value;
				continue;
			case EPrimaryStat::PS_CriticalStrikeChance:
				iCriticalStrikeChance += primaryStatsArray[i].m_value.GetValue();
				//iCriticalStrikeChance += primaryStatsArray[i].m_value;
				continue;
			case EPrimaryStat::PS_CriticalStrikeDamage:
				iCriticalStrikeDamage += primaryStatsArray[i].m_value.GetValue();
				//iCriticalStrikeDamage += primaryStatsArray[i].m_value;
				continue;
			case EPrimaryStat::PS_IncreaseDynamicForce:
				iDynamicForcePoints += primaryStatsArray[i].m_value.GetValue();
				//iDynamicForcePoints += primaryStatsArray[i].m_value;
			}
		}
	}

	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			iAttackSpeedBonus += gameInstance->m_bitbotsDistribution.m_attackSpeedBitBots;
			iCriticalStrikeChance += gameInstance->m_bitbotsDistribution.m_criticalStrikeChanceBitBots;
			iCriticalStrikeDamage += gameInstance->m_bitbotsDistribution.m_criticalStrikeDamageBitBots;
			iDynamicForcePoints += gameInstance->m_bitbotsDistribution.m_dynamicForceBitBots;
		}
	}

	float fWeaponDamage = static_cast<float>(iBaseDamage);
	float fItemBonusDamage = 0;
	float fAverageDamage = fWeaponDamage + fItemBonusDamage;

	float fWeaponAttackSpeed = static_cast<float>(iAttackSpeedWeapon) / 100.0f;
	float fAttackSpeedFromItens = static_cast<float>(iAttackSpeedBonus) / 100.0f;
	float fAttackSpeedFinal = fWeaponAttackSpeed * (1.0f + fAttackSpeedFromItens);

	float fDynamicForceStats = 1.0f + (static_cast<float>(iDynamicForcePoints) / 100.0f);
	float fCriticalStrikeDamage = static_cast<float>(iCriticalStrikeDamage) / 100.0f;
	float fCriticalStrikeChance = static_cast<float>(iCriticalStrikeChance) / 100.0f;
	float fCriticalFactor = 1.0f + (fCriticalStrikeDamage * fCriticalStrikeChance);

	float finalDamage = fAverageDamage * fDynamicForceStats * fCriticalFactor * fAttackSpeedFinal;

	int32 newDamage = static_cast<int32>(finalDamage);
	differenceDamage = newDamage - currentDamage;
	if (differenceDamage == 0 || currentDamage == 0 || newDamage == 0)
	{
		return 0;
	}
	float percent = static_cast<float>(differenceDamage) / static_cast<float>(currentDamage);
	return percent * 100.0f;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetNewEnergyIfEquipped(int32 lootIndex, FLootInfo loot)
{
	this->UpdateHeroStats();

	int32 currentMaxEnergy = GetMaxEnergy();
	int32 differenceMaxEnergy = 0;
	int32 iEnergyPercent = 0;
	int32 iEnergy = 0;
	bool existFirstWeapon = false;
	bool existSecondWeapon = false;

	TArray<FPrimaryStat> primaryStatsArray;
	
	//  Get equipments
	for (auto i = 0; i < m_equipment.Num(); i++)
	{
		if (lootIndex == i)
		{
			if (loot.m_primaryStats.Num() > 0)
			{
				primaryStatsArray.Append(loot.m_primaryStats);
			}
		}
		else
		{
			if (m_equipment[i].m_primaryStats.Num() > 0)
			{
				primaryStatsArray.Append(m_equipment[i].m_primaryStats);
			}
		}
	}

	//	Primary
	if (primaryStatsArray.Num() > 0)
	{
		for (auto i = 0; i < primaryStatsArray.Num(); i++)
		{
			switch (primaryStatsArray[i].m_stat)
			{
			case EPrimaryStat::PS_EnergyPercent:
				iEnergyPercent += primaryStatsArray[i].m_value.GetValue();
				//iEnergyPercent += primaryStatsArray[i].m_value;
				continue;
			case EPrimaryStat::PS_IncreaseEnergy:
				iEnergy += primaryStatsArray[i].m_value.GetValue();
				//iEnergy += primaryStatsArray[i].m_value;
			}
		}
	}

	//	TODO remove game instance from here
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
		if (gameInstance != nullptr)
		{
			iEnergy += gameInstance->m_bitbotsDistribution.m_EnergyBitBots;
		}
	}
	
	int32 newMaxEnergy = 0;
	float maxEnergy = static_cast<float>(m_baseEnergy) + static_cast<float>(iEnergy);
	maxEnergy += maxEnergy * (static_cast<float>(iEnergyPercent) / 100.0f);
	newMaxEnergy = static_cast<int32>(maxEnergy);

	differenceMaxEnergy = newMaxEnergy - currentMaxEnergy;
	if (differenceMaxEnergy == 0 || currentMaxEnergy == 0 || newMaxEnergy == 0)
	{
		return 0;
	}
	float percent = static_cast<float>(differenceMaxEnergy) / static_cast<float>(currentMaxEnergy);
	return percent * 100.0f;
}

//------------------------------------------------------------------------------------------------------------------
float ACustomRobot::GetNewResistanceIfEquipped(int32 lootIndex, FLootInfo loot)
{
	return 0;
}
#pragma endregion

#pragma region LOOT
//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::HaveSomeWeaponEquiped()
{
	if (this->m_equipment[0].m_baseStats.Num() > 0 || this->m_equipment[1].m_baseStats.Num() > 0)
	{
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateMovementSpeedFromLoot()
{
	this->GetCharacterMovement()->MaxWalkSpeed = this->m_baseMovementSpeed + (this->m_baseMovementSpeed * static_cast<float>(this->m_heroStat.m_movementSpeed.GetValue()) / 100.0f);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::UpdateEnergyFromLoot()
{
	this->m_maxEnergy = this->GetMaxEnergy();
}
#pragma endregion

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::AddAlly(class AEnemyRobot *robot)
{
	if (robot)
	{
		this->m_robotAllyes.Add(robot);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::RefreshAllies()
{
	for (int32 index = this->m_robotAllyes.Num() - 1; index >= 0; index--)
	{
		if (this->m_robotAllyes[index] == nullptr)
		{
			this->m_robotAllyes.RemoveAt(index, 1, true);
		}
	}
#ifndef SHIPPING_GAME_VERSION
	FString message = FString("Allies count ") + FString::FromInt(this->m_robotAllyes.Num());
	print(message);
#endif  //SHIPPING_GAME_VERSION
}

//------------------------------------------------------------------------------------------------------------------
class AEnemyRobot* ACustomRobot::GetNearAlly(FVector fromLocation)
{
	TArray<float> distances;
	float distance = 0;
	if (this->m_robotAllyes.Num() > 0)
	{
		for (int32 index = 0; index < this->m_robotAllyes.Num(); index++)
		{
			if (this->m_robotAllyes[index])
			{
				distance = FVector::Dist(fromLocation, this->m_robotAllyes[index]->GetActorLocation());
				distances.Add(distance);
			}
		}
		if (distances.Num() > 0)
		{
			distances.Sort();
			return this->m_robotAllyes[0];
		}
	}
	return nullptr;
}

//------------------------------------------------------------------------------------------------------------------
class AEnemyRobot* ACustomRobot::GetLessHealthAlly(FVector fromLocation) const
{
	//TArray<float> energyList;
	//if (m_robotAllyes.Num() > 0)
	//{
	//	for (int32 index = 0; index < m_robotAllyes.Num(); index++)
	//	{
	//		energyList.Add(m_robotAllyes[index]->m_currentEnergy);
	//	}
	//	energyList.Sort();
	//	ally = MakeShareable(m_robotAllyes[0]);
	//	return true;
	//}
	return nullptr;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::KillAllies()
{
	if (this->m_armyOfHeroesAllyes.Num() > 0)
	{
		for (int32 i = 0; i < this->m_armyOfHeroesAllyes.Num(); i++)
		{
			if (this->m_armyOfHeroesAllyes[i] != nullptr)
			{
				this->m_armyOfHeroesAllyes[i]->Explode();
				this->m_armyOfHeroesAllyes[i] = nullptr;
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::RefreshAllyTargets()
{
#ifndef SHIPPING_GAME_VERSION
	print("ACustomRobot::RefreshAllyTargets");
#endif  //SHIPPING_GAME_VERSION

	int32 maxTargets = 6;
	this->m_allyTargetsToShoot.Empty();

	//	Check for a minimum of N targets
	UWorld *world = this->GetWorld();
	if (world != nullptr)
	{
		for (TActorIterator<AEnemyRobot> ActorItr(world); ActorItr; ++ActorItr)
		{
			AEnemyRobot *robot = *ActorItr;
			if (robot != nullptr)
			{
				if (!robot->m_robotIsDead)
				{
					this->m_allyTargetsToShoot.Add(robot);
					if (this->m_allyTargetsToShoot.Num() > maxTargets)
					{
						break;
					}
				}
			}
		}
	}

	//	Check for dead actors
	if (this->m_allyTargetsToShoot.Num() > 0)
	{
		for (auto i = 0; i < this->m_allyTargetsToShoot.Num(); i++)
		{
			AEnemyRobot *robot = Cast<AEnemyRobot>(this->m_allyTargetsToShoot[i]);
			if (robot != nullptr)
			{
				if (robot->m_robotIsDead)
				{
					this->m_allyTargetsToShoot.RemoveAt(i, 1, true);
				}
			}
			//if (m_allyTargetsToShoot[i] == nullptr)
			//{
			//	m_allyTargetsToShoot.RemoveAt(i, 1, true);
			//}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
bool ACustomRobot::ExistTargetToAllyShoot()
{
	if (this->m_allyTargetsToShoot.Num() > 0)
	{
		for (auto i = 0; i < this->m_allyTargetsToShoot.Num(); i++)
		{
			AEnemyRobot *robot = Cast<AEnemyRobot>(this->m_allyTargetsToShoot[i]);
			if (robot != nullptr)
			{
				if (!robot->m_robotIsDead)
				{
					return true;
				}
			}
		}
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------
AActor* ACustomRobot::GetRandomTargetToAlly(AActor* oldTarget)
{
	//	TODO: optmize search

	if (this->m_allyTargetsToShoot.Num() > 0)
	{
		if (oldTarget != nullptr)
		{
			//	Check if old target still exist
			for (auto i = 0; i < this->m_allyTargetsToShoot.Num(); i++)
			{
				if (this->m_allyTargetsToShoot[i] == oldTarget)
				{
					AEnemyRobot *robot = Cast<AEnemyRobot>(this->m_allyTargetsToShoot[i]);
					if (robot != nullptr)
					{
						if (!robot->m_robotIsDead && robot->m_currentRobotBehavior != ERobotBehavior::RB_Fly)
						{
							return oldTarget;
						}
					}
				}
			}
		}

		//	Set new target
		TArray<int32> indexes;
		for (auto i = 0; i < this->m_allyTargetsToShoot.Num(); i++)
		{
			indexes.Add(i);
		}
		UUtility::Array_Shuffle(indexes);

		for (auto i = 0; i < indexes.Num(); i++)
		{
			AEnemyRobot *robot = Cast<AEnemyRobot>(this->m_allyTargetsToShoot[indexes[i]]);
			if (robot != nullptr)
			{
				if (!robot->m_robotIsDead && robot->m_currentRobotBehavior != ERobotBehavior::RB_Fly)
				{
					return robot;
				}
			}
		}
	}
	return nullptr;
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PlayPowerUpPickupSoundFX()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr && this->m_powerUpPickupSoundFX != nullptr)
	{
		//	Spawn Skill sound
		if (this->m_powerUpPickupSoundFX != nullptr)
		{
			float volume = 1.0f;
			UMercilessBotsGameInstance *gameInstance = Cast<UMercilessBotsGameInstance>(UGameplayStatics::GetGameInstance(world));
			if (gameInstance != nullptr)
			{
				volume = gameInstance->GetSoundFXVolume();
			}
			UAudioComponent* audioComponent = UGameplayStatics::SpawnSoundAttached(this->m_powerUpPickupSoundFX, this->GetRootComponent(),
				NAME_None, FVector(ForceInit), FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset, true, volume);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::SpawnPowerUpPickupFX()
{
	UWorld *world = this->GetWorld();
	if (world != nullptr && this->m_powerUpPickupFX != nullptr)
	{
		FTransform transform;
		transform.SetLocation(this->GetActorLocation());

		AActor* powerUpFX = world->SpawnActorDeferred<AActor>(this->m_powerUpPickupFX, transform);
		if (powerUpFX != nullptr)
		{
			//	Finish spawn actor
			UGameplayStatics::FinishSpawningActor(powerUpFX, transform);
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PlayTimeWarpPowerUpWidget()
{
	print("ACustomRobot::PlayTimeWarpPowerUpWidget");

	UFunction *playTimeWarpUMGFunction = this->FindFunction(FName("cl_PlayTimeWarpUMG"));
	if (playTimeWarpUMGFunction != nullptr)
	{
		this->ProcessEvent(playTimeWarpUMGFunction, nullptr);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PlayIncreaseDamagePowerUpWidget()
{
	print("ACustomRobot::PlayIncreaseDamagePowerUpWidget");

	UFunction *playIncreaseDamageUMGFunction = this->FindFunction(FName("cl_PlayIncreaseDamageUMG"));
	if (playIncreaseDamageUMGFunction != nullptr)
	{
		this->ProcessEvent(playIncreaseDamageUMGFunction, nullptr);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PlayIncreaseEnergyPowerUpWidget()
{
	print("ACustomRobot::PlayIncreaseEnergyPowerUpWidget");

	//	TODO: avoid multiples widgets
	UFunction *playIncreaseEnergyUMGFunction = this->FindFunction(FName("cl_PlayIncreaseEnergyUMG"));
	if (playIncreaseEnergyUMGFunction != nullptr)
	{
		this->ProcessEvent(playIncreaseEnergyUMGFunction, nullptr);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PlayIncreaseMovementSpeedPowerUpWidget()
{
	print("ACustomRobot::PlayIncreaseMovementSpeedPowerUpWidget");

	UFunction *playIncreaseMovementSpeedUMGFunction = this->FindFunction(FName("cl_PlayIncreaseMovementSpeedUMG"));
	if (playIncreaseMovementSpeedUMGFunction != nullptr)
	{
		this->ProcessEvent(playIncreaseMovementSpeedUMGFunction, nullptr);
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomRobot::PlayEnergyRegenerationPowerUpWidget()
{
	print("ACustomRobot::PlayEnergyRegenerationPowerUpWidget");
}
