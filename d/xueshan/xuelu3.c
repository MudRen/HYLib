 //      xuelu3.c ��ѩС·

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"��ѩС·"NOR);
        set("long",@LONG 
����һ������ѩ��С·���������ϣ������Ͷ������У�����������ѩ��һ
��һ����·һ���ǿ������׵�ɽ�ȣ�ɽ���Х������������ңң��׹�����һ
����С��ˤ����ȥ......
LONG);
        set("exits",([
                "eastdown" : __DIR__"xuelu2",
                "northup": __DIR__"shanpo"

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
