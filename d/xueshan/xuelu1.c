
//      xuelu1.c ��ѩС·

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
                "northup" : __DIR__"xuelu2",
                "eastdown": __DIR__"shanmen"

        ]));

        setup();
}
void init()
{
        if(NATURE_D->query_daytime() != "event_noon"){
        	message_vision(HIW"\n������ѩ����ͷ�������˹���������$N�������ۡ�ͻȻ��ɽ�±�����һ����ѩ��$N��������������ͷ�ϣ�\n\n"NOR,this_player());
        	message_vision(HIR"$N���²��ȣ�˳��ɽ�µ�����ȥ��\n"NOR,this_player());
    		this_player()->move(__DIR__"xuegu");
    		this_player()->unconcious();
       		}
}
