// sanshengtang.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "ǰ��");
		  set("long",@long
�����������������ܴ��ߣ�ʮ�ֵļ���׳�������ڰڼ��Ÿ߱����Σ�
һ�Ű������������ǽӴ����˵ĵط�,����Ͷ���Ҳ�ǿ�����������ЪϢ��
����һ������ͨ����档
long);
		 set("exits",([
"north" : __DIR__"pingfeng",
"south" : __DIR__"shilu1",
"west" : __DIR__"wlang01",
"east" : __DIR__"elang01",

]));

	 set("objects",([
         "/kungfu/class/kunlun/xihuazi.c" :  1,
        		]));

	set("valid_startroom", 1);
	set("no_clean_up", 0);
	setup();
//      replace_program(ROOM);
	//"/clone/board/kunlun_b"->foo();
	}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if ((!fam || fam["family_name"] != "������") && dir == "south" &&
		objectp(present("xi huazi", environment(me))))
		return notify_fail("��������ס�㣬˵���������������ɵĵ��̣���Ҫ�����Ҵ���\n");

		  return ::valid_leave(me, dir);
}
