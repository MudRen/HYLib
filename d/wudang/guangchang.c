//Room: guangchang.c �䵱�㳡
//Date: Sep 22 1997
#include <ansi.h>
inherit ROOM;
int do_zhao(string arg);

void create()
{
      set("short","�䵱�㳡");
      set("long",@LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص㡣
��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�ɨ��
�ϱ�������������
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/daotong": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "eastdown"   : __DIR__"tyroad1",
          "east"       : __DIR__"shanlu2",
      ]));
//      set("no_clean_up", 0);
set("chu_count", 2);
      set("outdoors", "wudang");
      setup();
//      replace_program(ROOM);
}

void init()
{
	add_action("do_zhao", ({"zhao","find"}));
}

int do_zhao(string arg)
{
	object me;
	me=this_player();
	if ( arg != "yao chu" )
	    return notify_fail("��Ҫ��ʲô��\n");
	if (present("yao chu", me))
	   return notify_fail("��������ȥ�������Լ�ԭ���Ѿ����ˣ�\n");
	if (objectp(present("yao chu", environment(me))))
	   return notify_fail("���Ͼ��У��㻹��ʲô����\n");

	if (query("chu_count") > 0)
	  {
	   add("chu_count", -1);
	   new(__DIR__"obj/yaochu")->move(me);
	   message_vision("$N��ǽ�ŵ�������﷭����ȥ�ҳ�һ��ҩ����\n", me);
	   me->start_busy(random(2));

	  }
	else
	   message_vision("$N��ǽ�ŵ�������﷭����ȥʲôҲû���š�\n", me);
     return 1;
}
