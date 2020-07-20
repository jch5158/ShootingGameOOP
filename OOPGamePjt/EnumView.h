#pragma once

// 오브젝트 태그
enum class ObjTagList { PLAYERTAG, ENEMYTAG, PLAYERBULLETTAG, ENEMYBULLETTAG };


// 총알 타입
enum class BulletTypeList { PLAYERBULLET, ENEMYBULLET };


// 사용자 키보드 컨트롤러
enum class KeyList { KEYUP, KEYDOWN, KEYRIGHT, KEYLEFT, KEYSHOTBULLET };


// 씬 
enum class SceneList { SCENETITLE, SCENELOADING, SCENEGAME, SCENEOVER };
