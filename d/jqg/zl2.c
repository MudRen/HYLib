// Room: /u/dubei/u/gumu/jqg/zl2
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����ŵĻ��ȣ����滭���������˵��黭��
LONG
	);

	set("exits", ([
                "south" : __DIR__"xf",
                "northeast" : __DIR__"zl1",
                "north" : __DIR__"df",
	]));
	set("objects", ([
		__DIR__"npc/puren1" : 1,
	 ]));
 	setup();
	 
}
int valid_leave(object me, string dir)
{
          if (!me->query("jqg_pass")&&
          present("pu ren", environment(me)) &&
	  (dir=="north"))
          return notify_fail("������ס��˵��������û������ͬ�⣬���������롣\n");
          return ::valid_leave(me, dir);
}
