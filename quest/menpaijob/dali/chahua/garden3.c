//Cracked by Kafei
// Room: /d/dali/garden3.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : RED"ʮ��ѧʿ
ʮ��ѧʿ�������µļ�Ʒ��һ���Ϲ���ʮ�˶仨�������ɫ
��ɫ��ͬ����ľ���ȫ�죬�ϵı���ȫ�ϣ����ް�ֻ��ӡ�
����ʮ�˶仨��״ҵ��䲻ͬ�����и��������ʱ�뿪л
ʱ��л��
 "NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"garden5",
  "southwest" : __DIR__"garden2",
]));


        set("objects", ([
                __DIR__"npc/huajiang": 1,
                __DIR__"npc/huachu": 2,
        ]));                                                                  
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
	if (me->query_temp("garden_working"))      
 	  return notify_fail("û�����������û�Ŷ���\n");  
          return ::valid_leave(me, dir);
}                                                                             
