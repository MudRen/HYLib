// Room: /u/dubei/u/gumu/jqg/sqx
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ���ȹ�����͵ĵط�������ǽ���Ϲ�������鷨
ͼ�����Ŵ��Ը������Σ������ǻ��ȡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"sf",
                "eastdown" : __DIR__"st",
                "south" : __DIR__"jt",
                "southwest": __DIR__"zl1",
	]));
	set("objects", ([
		__DIR__"npc/gsz" : 1,
	 ]));

       setup();
 
}
int valid_leave(object me, string dir)
{
          if (!me->query("jqg_pass")&&
          present("gongsun zhi", environment(me)) &&
	  (dir =="south" || dir =="north" || dir=="southeast"))
          return notify_fail("����ֹŭ�⵽������Ϊ����С��Ů�������Ҿ���������ܣ���\n");
          return ::valid_leave(me, dir);
}
