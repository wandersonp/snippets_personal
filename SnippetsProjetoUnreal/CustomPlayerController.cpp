//==================================================================================================================
//
//	File:	CustomPlayerController.cpp
//	Date:	30-12-2016
//	Author:	wandersonp@gmail.com
//
//	Description:    
//
//==================================================================================================================

#include "CustomGame.h"
#include "CustomPlayerController.h"

//------------------------------------------------------------------------------------------------------------------
ACustomPlayerController::ACustomPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	static ConstructorHelpers::FClassFinder<UUserWidget> missionCompleteWidget(TEXT("/Game/Menu/UI/UMG/Widget/Gameplay/Widget_MissionComplete"));
	if (missionCompleteWidget.Succeeded())
	{
		m_missionCompleteWidget = missionCompleteWidget.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> missionFailedWidget(TEXT("/Game/Menu/UI/UMG/Widget/Gameplay/Widget_MissionFailed"));
	if (missionFailedWidget.Succeeded())
	{
		m_missionFailedWidget = missionFailedWidget.Class;
	}

	//static ConstructorHelpers::FObjectFinder<UBlueprint> missionCompleteBP(TEXT("/Game/PrototipoGame/Asset/FX/MissionComplete/BP_MissionComplete_01"));
	//if (missionCompleteBP.Object != nullptr)
	//{
	//	//m_missionCompleteBP = (UClass*)missionCompleteBP.Object;
	//	m_missionCompleteBP = (UClass*)missionCompleteBP.Object->GeneratedClass;
	//}

	//static ConstructorHelpers::FObjectFinder<UBlueprint> missionFailedBP(TEXT("/Game/PrototipoGame/Asset/FX/MissionFailed/BP_MissionFailed_01"));
	//if (missionFailedBP.Object != nullptr)
	//{
	//	m_missionFailedBP = (UClass*)missionFailedBP.Object->GeneratedClass;
	//}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (m_missionCompleteWidget != nullptr)
	{
		m_missionCompleteUMG = CreateWidget<UUserWidget>(this, m_missionCompleteWidget);
		if (m_missionCompleteUMG != nullptr)
		{
			m_missionCompleteUMG->SetVisibility(ESlateVisibility::Hidden);
			//m_missionCompleteUMG->AddToViewport();
		}
	}

	if (m_missionFailedWidget != nullptr)
	{
		m_missionFailedUMG = CreateWidget<UUserWidget>(this, m_missionFailedWidget);
		if (m_missionFailedUMG != nullptr)
		{
			m_missionFailedUMG->SetVisibility(ESlateVisibility::Hidden);
			//m_missionFailedUMG->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
			//m_missionFailedUMG->AddToViewport();
		}
	}
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//InputComponent->BindAction(TEXT("MoveUp"), IE_Pressed, this, &ACustomPlayerController::MoveUp);
	//InputComponent->BindAction(TEXT("MoveDown"), IE_Pressed, this, &ACustomPlayerController::MoveDown);
	//InputComponent->BindAction(TEXT("MoveLeft"), IE_Pressed, this, &ACustomPlayerController::MoveLeft);
	//InputComponent->BindAction(TEXT("MoveRight"), IE_Pressed, this, &ACustomPlayerController::MoveRight);
	//InputComponent->BindAction(TEXT("PrimarySkill"), IE_Pressed, this, &ACustomPlayerController::UsePrimarySkill);
	//InputComponent->BindAction(TEXT("SecondarySkill"), IE_Pressed, this, &ACustomPlayerController::UseSecondarySkill);
	//InputComponent->BindAction(TEXT("Skill_A"), IE_Pressed, this, &ACustomPlayerController::UseSkill_A);
	//InputComponent->BindAction(TEXT("Skill_B"), IE_Pressed, this, &ACustomPlayerController::UseSkill_B);
	//InputComponent->BindAction(TEXT("Skill_C"), IE_Pressed, this, &ACustomPlayerController::UseSkill_C);
	//InputComponent->BindAction(TEXT("Skill_D"), IE_Pressed, this, &ACustomPlayerController::UseSkill_D);
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::MoveLeft()
{
	//print("Move Left");
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::MoveRight()
{
	//print("Move Right");
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::MoveUp()
{
	//print("Move Up");
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::MoveDown()
{
	//print("Move Down");
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::UsePrimarySkill()
{
	//print("Using Primary Skill");
	//	TODO: skill activation code
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::UseSecondarySkill()
{
	//print("Using Secondary Skill");
	//	TODO: skill activation code
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::UseSkill_A()
{
	//print("Using Skill A");
	//	TODO: skill activation code
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::UseSkill_B()
{
	//print("Using Skill B");
	//	TODO: skill activation code
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::UseSkill_C()
{
	//print("Using Skill C");
	//	TODO: skill activation code
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::UseSkill_D()
{
	//print("Using Skill D");
	//	TODO: skill activation code
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::ShowMissionCompleteUMG()
{
	m_missionCompleteUMG->SetVisibility(ESlateVisibility::Visible);
	m_missionCompleteUMG->AddToViewport();
}

//------------------------------------------------------------------------------------------------------------------
void ACustomPlayerController::ShowMissionFailedUMG()
{
	m_missionFailedUMG->SetVisibility(ESlateVisibility::Visible);
	m_missionFailedUMG->AddToViewport();
}