// shiwu.c ��ʯ��
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIW"��ʯ��"NOR);
            set("long",@LONG
һ�������ʯ�ݳ�������ǰ��ֻ�����������׶���ִ������վ��ʯ����ǰ��
ʯ�ݶ����Ǿ������£����곤�ھ������������ú�ïʢ����ʯ���ڵ�����ʵʵ
�ģ�ԶԶ������������������������л�����ʯ�ݡ�
LONG
       );
            set("exits",([
              "south": __DIR__"qsroad",
              "enter": __DIR__"dating",
            ]));

            set("outdoor","�����");
            set("objects",([
               __DIR__"npc/fan": 1,
               __DIR__"npc/tonger2": 2,
            ]));
	    setup();
}

int valid_leave(object me, string dir)
{
        if ( present("fan yiweng", environment(me)) 
           && dir =="enter")
         return notify_fail("��һ����ס���ȥ·����ȭ����������н�ֹ���ɵ��ӽ��롣\n");
         return ::valid_leave(me, dir);
}
