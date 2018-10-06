// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "IDetailCustomization.h"

/**
 * How the details customization panel looks for the DlgDialogue object.
 * See FDlgSystemEditorModule::StartupModule for usage.
 */
class FDialogue_Details : public IDetailCustomization
{
	typedef FDialogue_Details Self;
public:
	// Makes a new instance of this detail layout class for a specific detail view requesting it
	static TSharedRef<IDetailCustomization> MakeInstance() { return MakeShareable(new Self); }

	// IDetailCustomization interface
	/** Called when details should be customized */
	void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
};
