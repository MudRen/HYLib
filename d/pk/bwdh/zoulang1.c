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
        "west" : __DIR__"caodi1",
        "east" : __DIR__"caodi2",
        "north" : __DIR__"quqiao2",
        "south" : __DIR__"qianting",
        ]));
        
        set("no_death",1);set("bwdhpk",1);

        setup();
}

