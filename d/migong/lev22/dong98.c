#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����֮���"NOR);
	set("long", HIW @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG NOR);
	set("exits", ([
		"up" : __DIR__"dong99",
		"down" : __DIR__"dong97",
                	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/boss11": 1,
             __DIR__"npc/boss12": 1,
              __DIR__"npc/boss13": 1,
             __DIR__"npc/boss14": 1,
              __DIR__"npc/boss15": 1,
             __DIR__"npc/boss16": 1,
             __DIR__"npc/boss17": 1,
             __DIR__"npc/boss21": 1,
             __DIR__"npc/boss22": 1,
              __DIR__"npc/boss23": 1,
             __DIR__"npc/boss24": 1,
              __DIR__"npc/boss25": 1,
             __DIR__"npc/boss26": 1,
             __DIR__"npc/boss27": 1,
                ]));
set("no_npc",1);
	set("no_fight",1);
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}
