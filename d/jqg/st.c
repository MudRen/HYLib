// Room: /u/dubei/u/gumu/jqg/st
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰһ�����䳯���İ�ʯ���������й��ӵļ�ɽ��ʯ����
�ܱ�ֲ��Ƥ�ɣ������Ǿ��ڣ�ֻ�����������׶���ִ������վ
����ǰ��
LONG
	);

	set("exits", ([
                "east" : __DIR__"hc11",
                "northup" : __DIR__"sl1",
                "westup" : __DIR__"sqx",
                "south" : __DIR__"qzy",
	]));
	set("objects", ([
		__DIR__"npc/boy" : 2,
	 ]));

        set("outdoors", "����");
	setup();
	replace_program(ROOM); 
}

