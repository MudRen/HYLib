// Room: /u/dubei/u/gumu/jqg/hhs
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����ש�ߵĴ�Ҥ��Խ��ש�ڣ����ȸ�ʢ�������ֹ���
�ڰ�Ѳ�̿����������ಲ������ֻ��һ��ţͷ�̿㣬أ��ȫ��
�����졣
LONG
	);

	set("exits", ([
                "west" : __DIR__"zl1",
                "enter" : __DIR__"hhs1",
	]));

        set("objects", ([
		__DIR__"npc/puren" : 1,
	 ]));
	setup();
	replace_program(ROOM); 
}

