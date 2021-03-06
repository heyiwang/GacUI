#include "GuiControlTemplates.h"
#include "../ListControlPackage/GuiListControls.h"

namespace vl
{
	namespace presentation
	{
		namespace templates
		{
			using namespace collections;
			using namespace controls;
			using namespace compositions;
			using namespace elements;

/***********************************************************************
GuiTemplate
***********************************************************************/

			GuiTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_IMPL)

			controls::GuiControlHost* GuiTemplate::GetControlHostForInstance()
			{
				return GetRelatedControlHost();
			}

			void GuiTemplate::OnParentLineChanged()
			{
				GuiBoundsComposition::OnParentLineChanged();
				OnControlHostForInstanceChanged();
			}

			GuiTemplate::GuiTemplate()
			{
				GuiTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_EVENT_INIT)
			}

			GuiTemplate::~GuiTemplate()
			{
				FinalizeInstanceRecursively(this);
			}

/***********************************************************************
Item GuiListItemTemplate
***********************************************************************/

			void GuiListItemTemplate::OnInitialize()
			{
			}

			GuiListItemTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_IMPL)

			GuiListItemTemplate::GuiListItemTemplate()
			{
				GuiListItemTemplate_PROPERTIES(GUI_TEMPLATE_PROPERTY_EVENT_INIT)
			}

			GuiListItemTemplate::~GuiListItemTemplate()
			{
				FinalizeAggregation();
			}

			void GuiListItemTemplate::BeginEditListItem()
			{
				listControl->GetItemProvider()->PushEditing();
			}

			void GuiListItemTemplate::EndEditListItem()
			{
				CHECK_ERROR(listControl->GetItemProvider()->PopEditing(), L"GuiListItemTemplate::EndEditListItem()#BeginEditListItem and EndEditListItem calls are not paired.");
			}

			void GuiListItemTemplate::Initialize(controls::GuiListControl* _listControl)
			{
				CHECK_ERROR(listControl == nullptr, L"GuiListItemTemplate::Initialize(GuiListControl*)#This function can only be called once.");
				listControl = _listControl;
				OnInitialize();
			}

/***********************************************************************
Template Declarations
***********************************************************************/

			GUI_CONTROL_TEMPLATE_DECL(GUI_TEMPLATE_CLASS_IMPL)
			GUI_ITEM_TEMPLATE_DECL(GUI_TEMPLATE_CLASS_IMPL)
		}
	}
}