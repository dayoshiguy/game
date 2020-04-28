//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef OPTIONS_SUB_AUDIO_H
#define OPTIONS_SUB_AUDIO_H
#ifdef _WIN32
#pragma once
#endif

#include "vgui_controls/PropertyPage.h"
#include <language.h>
#include "vgui_controls/Frame.h"
#include <vgui_controls/CvarSlider.h>
#include "vgui/KeyCode.h"

class CLabeledCommandComboBox;

//-----------------------------------------------------------------------------
// Purpose: Audio Details, Part of OptionsDialog
//-----------------------------------------------------------------------------
class COptionsSubAudio : public vgui::PropertyPage
{
	DECLARE_CLASS_SIMPLE( COptionsSubAudio, vgui::PropertyPage );

public:
	COptionsSubAudio(vgui::Panel *parent);
	~COptionsSubAudio();

	virtual void OnResetData();
	virtual void OnCommand( const char *command );
    static char* GetUpdatedAudioLanguage() { return m_pchUpdatedAudioLanguage; }

private:
	MESSAGE_FUNC_PTR( OnControlModified, "ControlModified", panel );
	MESSAGE_FUNC_PTR( OnTextChanged, "TextChanged", panel )
	{
		OnControlModified(panel);
	}

	MESSAGE_FUNC( RunTestSpeakers, "RunTestSpeakers" );

	vgui::ComboBox				*m_pSpeakerSetupCombo;
	vgui::ComboBox				*m_pSoundQualityCombo;
	vgui::CvarSlider					*m_pSFXSlider;
	vgui::CvarSlider					*m_pMusicSlider;
	vgui::ComboBox				*m_pCloseCaptionCombo;
	bool						   m_bRequireRestart;
   
   vgui::ComboBox				*m_pSpokenLanguageCombo;
   MESSAGE_FUNC( OpenThirdPartySoundCreditsDialog, "OpenThirdPartySoundCreditsDialog" );
   vgui::DHANDLE<class COptionsSubAudioThirdPartyCreditsDlg> m_OptionsSubAudioThirdPartyCreditsDlg;
   ELanguage         m_nCurrentAudioLanguage;
   static char             *m_pchUpdatedAudioLanguage;

    vgui::CvarToggleCheckButton *m_pMuteLoseFocus;

    ConVarRef m_cvarSubtitles, m_cvarCloseCaption, m_cvarSndSurroundSpeakers, m_cvarSndPitchQuality, m_cvarDSPSlowCPU, m_cvarDSPEnhanceStereo;
};


//-----------------------------------------------------------------------------
// Purpose: third-party audio credits dialog
//-----------------------------------------------------------------------------
class COptionsSubAudioThirdPartyCreditsDlg : public vgui::Frame
{
	DECLARE_CLASS_SIMPLE( COptionsSubAudioThirdPartyCreditsDlg, vgui::Frame );
public:
	COptionsSubAudioThirdPartyCreditsDlg( vgui::VPANEL hParent );

	virtual void Activate();
	void OnKeyCodeTyped(vgui::KeyCode code);
};


#endif // OPTIONS_SUB_AUDIO_H
