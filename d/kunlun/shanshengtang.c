// sanshengtang.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "������ʥ��");
                  set("long",@long
������ʥ���ˡ�������ʥ�������������ԭΪ���������ԣ�������������
������������׳������Զ�����������������ɾ������£��Ӵ���·����Ӣ
�۵ĵط�����������ʥ��Ҳֻ�����ٰ��������ˡ�
long);
                 set("exits",([
"west" : __DIR__"jiuqulang1",
"south" : __DIR__"shanmen",
"north" : __DIR__"liangong",
"northwest" : __DIR__"jiuqulang2",
]));

                 set("objects",([
                                "/kungfu/class/kunlun/banshuxian.c" :   1,
                                __DIR__"npc/kl-dizi1.c" :   1,
                                __DIR__"npc/kl-dizi3.c" :   1,
                ]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
        }

int valid_leave(object me, string dir)
{

        if (!me->query_temp("kl_pass") && dir == "north" &&
                objectp(present("ban shuxian", environment(me))))
        {
                return notify_fail("�������ס�㣬˵�����������ܹ���������һ�أ������������ټѴ���\n");
        }
                  return ::valid_leave(me, dir);
}
