//Room:/d/lingshedao/shanyao.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������������������ɽ��,�����Ŀ���ɽ�����ƺ��л��˼�,����
�ֲ�����.Զ�����·ת,��������,��������֮��.�����ƺ�����
��ɽ��·.
LONG );        
        set("exits", ([
                "eastdown"    : __DIR__"lsroad4",
                "northup"  : __DIR__"migong1",
                "southdown" : __DIR__"lsroad3",
        ]));
        
        set("no_clean_up",0);
        set("outdoors","lingshedao");           
        setup();
}

void init()
{
        object ob;
        ob=this_player();       if(environment(ob)!=environment())
        message_vision(HIB"\nͻȻ��������ɽ���ϴ���һ����У���������,
\n��������,�����в���һ��:��˭��������֮����?\n"NOR,ob);
        else
        return;
}
