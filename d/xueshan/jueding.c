 //      jueding.c ��������

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"����"NOR);
        set("long",@LONG 
�����Ǵ�ѩɽ���壬�˼������������޶�������Ӱ������ž���Ω�ŷ�����
������ɽ������絶��͸�Ǳ�����ƽ����ֻ����һС��͵ñ�������
LONG);
//        set("objects", ([__DIR__("npc/obj/zanghonghua") : 1 ]));
	set("exits", ([
		"down" : __DIR__"shanpo",
	]));
        set("objects",([
                __DIR__"npc/obj/zanghonghua": 1,
        ]));

        setup();
}

void init()
{
        mixed *local;
    
        local = localtime(time() * 60);
        if (local[2] < 11 || local[2] > 13) {
	message_vision(HIW
"������ѩ����ͷ�������˹���������$N�������ۡ�ͻȻ��ɽ�±�����һ����ѩ��$N��������������ͷ�ϣ�\n"NOR,this_player());
	message_vision(HIR"$N���²��ȣ�˳��ɽ�µ�����ȥ��\n"NOR,this_player());
    this_player()->move(__DIR__"xuegu");
    this_player()->unconcious();
        }
}
