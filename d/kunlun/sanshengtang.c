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
"northdown" : __DIR__"lang2",
"north" : __DIR__"liangong",
"northwest" : __DIR__"jiuqulang2",
]));

                 set("objects",([

                                __DIR__"npc/kl-dizi1.c" :   2,
                                __DIR__"npc/kl-dizi3.c" :   2,
                                "quest/menpaijob/kunlun/shi" :   1,
                ]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
        "/clone/board/kunlun_b"->foo();
        }

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");
        if (dir == "north" && objectp(present("ban shuxian", environment(me))))
           if((!fam || fam["family_name"] != "������") && !me->query_temp("kl_pass"))
        {
                return notify_fail("�������ס�㣬˵�����������ܹ���������һ�أ������������ټѴ���\n");
        }
        if (dir == "south" && me->query("kl_pass"))
           me->delete_temp("kl_pass");
                  return ::valid_leave(me, dir);
}
