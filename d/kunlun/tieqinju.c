// tieqinju.c ���پ�

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","���پ�");
        set("long",@long
������ǡ�������������̫��ľӴ������������Ϊ���ɣ���Ʒ��������
�����ǲ�ͬ�����������ɵ��������������������ɫ������ͨ����ʥ�ã���
��ͨ�����ҡ�
long);

set("objects",([
"/kungfu/class/kunlun/hetaichong.c" :   1,
"/kungfu/class/kunlun/banshuxian.c" :   1,
__DIR__"npc/kl-dizi2.c" :   1,
__DIR__"npc/kl-dizi4.c" :   1,
]));

set("exits", ([
                        "east" : __DIR__"jiuqulang1",
                        "west" : __DIR__"sleeproom",
]));

          set("no_clean_up", 0);
                create_door("west", "С��", "east", DOOR_CLOSED);
          setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");

        if (dir == "west" && objectp(present("he taichong", environment(me))))
           if((!fam || fam["family_name"] != "������") && !me->query_temp("kl_pass"))
                return notify_fail("��̫����ס�㣬˵�������Ϊ�ھ��ס�������������Ϊ�ǡ�\n");

                  return ::valid_leave(me, dir);
}
