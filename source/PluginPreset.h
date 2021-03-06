//
// PluginPreset.h - MrsWatson
// Created by Nik Reiman on 1/13/12.
// Copyright (c) 2011 Teragon Audio. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#include "CharString.h"
#include "Plugin.h"

#ifndef MrsWatson_PluginPreset_h
#define MrsWatson_PluginPreset_h

typedef enum {
  PRESET_TYPE_INVALID,
  PRESET_TYPE_FXP,
  NUM_PRESET_TYPES
} PluginPresetType;

typedef boolean (*OpenPresetFunc)(void*);
typedef boolean (*LoadPresetFunc)(void*, Plugin);
typedef void (*FreePresetDataFunc)(void*);

typedef struct {
  PluginPresetType presetType;
  CharString presetName;
  unsigned int compatiblePluginTypes;

  OpenPresetFunc openPreset;
  LoadPresetFunc loadPreset;
  FreePresetDataFunc freePresetData;

  void* extraData;
} PluginPresetMembers;

typedef PluginPresetMembers* PluginPreset;

PluginPresetType guessPluginPresetType(const CharString presetName);
PluginPreset newPluginPreset(PluginPresetType presetType, const CharString presetName);
// Consider this "protected"
void _setPresetCompatibleWithPluginType(PluginPreset pluginPreset, PluginInterfaceType interfaceType);
boolean isPresetCompatibleWithPlugin(const PluginPreset pluginPreset, const Plugin plugin);
void freePluginPreset(PluginPreset pluginPreset);

#endif
