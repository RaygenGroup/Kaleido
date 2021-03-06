#pragma once
// For editor use only, contains the actual text pieces for the editor help and other stuff.

inline const char* txt_about = R"(
MIT License

Copyright (c) 2019-2020 John Moschos, Harry Katagis

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
)";

// this text autowraps around 70 chars for optimal reading
inline const char* txt_help = R"(
The editor is designed primarily for debugging and advanced users. Multiple properties can be set to "incorrect" values and rarely some may crash your system. You can for example set a negative texture size, or a 128k by 128k one so use responsibly.
Also note that the editor has not been thoroughly profiled and may introduce slight performance penalties while the windows are open and visible. The editor can be toggled at any time using the ` key.

Scene saving and loading is available and the scene format is in json.
All the reflected properties of nodes are automatically serialized and restored upon loading. Any asset referenced in the scene file is stored relative to the Kaleido/assets/ folder and the scene will fail to load if it is not found.
Editing the json files by hand is possible but not recommended.
)";

inline const char* help_Outliner = R"(
Outliner provides an outline of the current world hierarchy.

Select nodes by clicking to open their property editor.
Right click nodes to open their context menu.
Drag-n-drop a node onto another to change the hierarchy.
)";

inline const char* help_PropertyEditor = R"(
Instance editor allows viewing and editing the name and transform of the node.
Transform can be edited in local or world space and the full matrix can also be edited.

Right-clicking on scale provides an additional locked scale mode.


Property editor (below) enables editing any reflected variable of the selected node.

No filtering is done to the input and illegal values can be set to some properties that may cause system instability (eg: negative texture sizes).
Asset references can also be edited inline.

Note:
All values are updated bidirectionaly in realtime
)";

inline const char* help_AssetView = R"(
Assets panel provides an overview of all the currently registered assets.

The data residing in memory can be unloaded and reloaded at will.
)";

inline const char* help_EditorCamera = R"(
Editor camera is a special node managed by the editor to allow for editor specific extra functionality.

Keybinds for editor camera are:
W,A,S,D,Q,E movement
Right-click drag: facing
Shift, Ctrl: Speed up, speed down
X: toggle between axis aligned, view based movement
C: reset orientation (resets roll too)
F: Focus currently selected node
Shift+F: Toggle Piloting selected node.

The editor camera differs from other nodes in the following ways:

* It is not saved or loaded in scene files
* It updates even when the world is not updating
* It is automatically removed or added when toggling world updates
* It cannot have children
* It automatically moves its parent
* Context actions are disabled
)";

inline const char* help_UpdateWorld = R"(
Enables the update functions of the world nodes, and disables the editor camera.
Some editor functionality like piloting may not work because they require the editor camera.

To discard the state after running updates, use restore update state.
)";

inline const char* help_RestoreWorld = R"(
Toggles automatic reloading of the world state after 'stoping' updating.
)";

inline const char* help_AssetUnloadAll = R"(
Unloads all currently filtered assets. 
Some assets may reload instantly because they are accessed.
)";

inline const char* help_AssetReloadUnloaded = R"(
Reloads any filtered assets currently unloaded.
)";

inline const char* help_AssetReloadAll = R"(
Reloads all currently filtered assets.
)";

inline const char* help_AssetFilter = R"(
Filter assets, can accept multiple terms by ',' and negative matches by '-'
eg: '-mat, .gltf'
)";

inline const char* help_AssetSearchGltf = R"(
Opens the gltf file list window.
)";

inline const char* help_GltfWindowRefresh = R"(
This window contains all .gtlf files found in assets/ folders.
Duplicate names are shown once.

Contents of this window are cached, refresh to detect new files / changes in the filesystem.
)";

inline const char* help_PropPodEditing = R"(

WARNING:
Editing asset pod properties is currently only partially supported.

The cpu side data are edited in real time, but even the provided renderers will not reflect the changes on most cases.
Also any changes to the pods do not get saved in scene files and will be lost when the asset reloads from disk.

Right-clicking here brings up the extra pod handle context actions.
)";


inline const char* help_PropMassEditMats = R"(
Toggles parallel editing of materials in this list by editing any one of them.
Only the edited properties will propagate to the rest of the materials.
)";

inline const char* help_PropMassRestoreMats = R"(
Mass reloads the materials to restore their original state after mass editing.
)";
