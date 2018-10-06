// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "Widgets/Input/SSearchBox.h"
#include "DetailWidgetRow.h"

class FDetailWidgetRow;

/**
 * Base class for all Custom Row Helpers.
 * Makes sure that the ToolTips and Display Names are in sync with the PropertyHandle and the SWidget that is represented by.
 */
class FBase_CustomRowHelper
{
	typedef FBase_CustomRowHelper Self;
public:
	FBase_CustomRowHelper(FDetailWidgetRow* InDetailWidgetRow, TSharedPtr<IPropertyHandle> InPropertyHandle);
	virtual ~FBase_CustomRowHelper() {}

	/** Sets the localized display name of the property. */
	Self* SetDisplayName(const FText& InDisplayName)
	{
		DisplayName = InDisplayName;
		return this;
	}

	/** Sets the localized tooltip of the property. */
	Self* SetToolTip(const FText& InToolTip)
	{
		ToolTip = InToolTip;
		return this;
	}

	/** Sets the visibility of this property. */
	Self* SetVisibility(const TAttribute<EVisibility>& InVisibility)
	{
		DetailWidgetRow->Visibility(InVisibility);
		return this;
	}

	/** Set the optional utils */
	Self* SetPropertyUtils(TSharedPtr<IPropertyUtilities> Utils)
	{
		PropertyUtils = Utils;
		return this;
	}

	/** Update the full property row. */
	void Update();

protected:
	/** Internal update method that must be implemented. Called after Update finishes. */
	virtual void UpdateInternal() = 0;

protected:
	/** The custom widget row this represents */
	FDetailWidgetRow* DetailWidgetRow = nullptr;

	/** Helpers class  */
	TSharedPtr<IPropertyUtilities> PropertyUtils;

	/** The Property handle of what this row represents */
	TSharedPtr<IPropertyHandle> PropertyHandle;

	/** The NameContent Widget. */
	TSharedPtr<SWidget> NameContentWidget;

	/** Texts used for this property row. */
	FText DisplayName;
	FText ToolTip;
};
