//jiashan.c ��ɽ

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIW"��ɽ"NOR);
        set("long", @LONG
һ���������ļ�ɽ��ʯ��������������Ȫˮ��ɽ�ı�����һ��С������
���ƺ�������ʲô�����ڸ������곱ʪ����С����������ڴ򻬵Ķ���ʯ�ϡ�
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "west" : __DIR__"quqiao1",
        "east" : __DIR__"quqiao3",
        "north" : __DIR__"quqiao4",
        "south" : __DIR__"quqiao2",

        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "�Խ�ɽׯ");

        setup();
}

