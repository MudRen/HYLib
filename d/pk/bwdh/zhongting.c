//zhongting ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"����"NOR);
        set("long", @LONG
����һ��С�ɶ����µ�¥����¥�²��õ����С�������鷿�����м���
һ��С��ľ���������Ա߰����İ����ӣ�������һ����������������˱�ī
��̨���������Ϸ��˼����顣�����Ա���һ��ܣ����ϰ����˸�ʽ�������顣
վ������ǰ������ȥ������Կ�������İŽ��ͳ�����һ�ǡ�
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([        
        "west" : __DIR__"caodi3",
        "east" : __DIR__"caodi4",
        "north" : __DIR__"zoulang2",
        "south" : __DIR__"quqiao4",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
     
        setup();
}

