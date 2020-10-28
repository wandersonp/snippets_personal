//==================================================================================================================
//
//	File:	CustomPlayerController.h
//	Date:	30-12-2016
//	Author:	wandersonp@gmail.com
//
//	Description:    
//
//==================================================================================================================

#pragma once

#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

//------------------------------------------------------------------------------------------------------------------
UCLASS()
class CUSTOMGAME_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACustomPlayerController();
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void ShowMissionCompleteUMG();
	void ShowMissionFailedUMG();

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void UsePrimarySkill();
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void UseSecondarySkill();
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void UseSkill_A();
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void UseSkill_B();
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void UseSkill_C();
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void UseSkill_D();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> m_missionCompleteWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> m_missionFailedWidget;

protected:
	UPROPERTY()
	UUserWidget* m_missionCompleteUMG;
	
	UPROPERTY()
	UUserWidget* m_missionFailedUMG;
};