// �������� damen.c
// zly 99.6.21

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        object con, item;
       set("short",MAG"��������"NOR);
       set("long", @LONG
�����ǽ��������������ס�������Ĵ��ţ�������ŵ����Ϸ���һ
����ֺڵ׵ĳ��ң����顰�������������֣��ſ��������������ʯʨ
���������䡣�����������Ĵ����������ǡ�
LONG);    
        set("exits", ([
            "north" : __DIR__"dating",
                "southeast" : "/d/huanghe/huanghe7",
        ]));    
        set("no_fight", 1);

        set("objects",([
            __DIR__"obj/flower" : 1,
            __DIR__"npc/zhang" : 1,
            __DIR__"obj/pin" : 1,
        ]));         
        setup();        
        con = present("flower", this_object());
        item= present("jin chai", this_object());
        item->move(con);
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("yyd_jinchai") && dir == "north" )
        return notify_fail("����ôһ����Ҳ������\n");
        return ::valid_leave(me, dir);
}
