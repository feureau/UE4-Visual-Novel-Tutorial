// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Interface.h"

#include "DlgDialogueParticipant.generated.h"


UINTERFACE(BlueprintType, Blueprintable)
class DLGSYSTEM_API UDlgDialogueParticipant : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};
inline UDlgDialogueParticipant::UDlgDialogueParticipant(const FObjectInitializer& ObjectInitializer) {}

/**
 * Interface that each Dialogue participant must implement
 */
class DLGSYSTEM_API IDlgDialogueParticipant
{
	GENERATED_IINTERFACE_BODY()

	// Participant informations:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	FName GetParticipantName() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	FText GetParticipantDisplayName(FName ActiveSpeaker = NAME_None) const;

	/** May be used for formatted node texts, check https://docs.unrealengine.com/en-us/Gameplay/Localization/Formatting for more information */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	ETextGender GetParticipantGender() const;

	/**
	* @param	ActiveSpeaker: name of the active speaker at the time of the call (might or might not this participant)
	* @param	ActiveSpeakerState: state of the active participant (might or might not belong to this participant)
	*			If it is not displayed in editor it has to be turned on in the dialogue settings
	* @return	Participant icon to display
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	UTexture2D* GetParticipantIcon(FName ActiveSpeaker = NAME_None, FName ActiveSpeakerState = NAME_None) const;

	// Conditions:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool CheckCondition(const FName& ConditionName) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	float GetFloatValue(const FName& ValueName) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	int32 GetIntValue(const FName& ValueName) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool GetBoolValue(const FName& ValueName) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	FName GetNameValue(const FName& ValueName) const;


	// Events:

	 /** @return value: irrelevant */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool OnDialogueEvent(const FName& EventName);

	/** 
	 * @param	bDelta Whether we expect the value to be set or modified
	 * @return	Irrelevant, ignored
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool ModifyFloatValue(const FName& ValueName, bool bDelta, float Value);

	/**
	 * @param	bDelta Whether we expect the value to be set or modified
	 * @return	Irrelevant, ignored
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool ModifyIntValue(const FName& ValueName, bool bDelta, int32 Value);

	/** @return value: irrelevant */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool ModifyBoolValue(const FName& ValueName, bool bNewValue);

	/** @return value: irrelevant */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = DialogueCallback)
	bool ModifyNameValue(const FName& ValueName, const FName& NameValue);
};
