//huilang.c ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"����"NOR);
        set("long", @LONG
����һ���ľ��Ļ��ȣ����������˻��ܣ�����Щҩ�ģ��Ե÷ǳ����ľ���
��ǰ�ǳ�������ʯ·��С·һ�˵ľ�ͷ�ƺ���һ��СԲ�ţ�·�����Ǽ��䷿
�ӡ�
LONG
        );
        set("exits", ([
        "south" : __DIR__"zhongting",
        "southwest" : __DIR__"caodi3",
        "southeast" : __DIR__"caodi4",
        "north" : __DIR__"houting",

        ]));
        
        set("no_death",1);set("bwdhpk",1);

        setup();
}

