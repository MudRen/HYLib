// /d/kunming/pubu
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "ԭʼɭ��" NOR);
        set("long", @LONG
�������ֻ������ˮ��Խ��Խ����о���һ������������Ϯ
������ľ����ϡ�٣�����ȴ�����������������򴩹�����(huacong)
�ƺ�����С·���߹�ȥ��
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"yunnan4", 
                
        ]));

             
        setup();
       
}


void init()
{
        add_action("do_enter", "poke");
	UPDATE_D->check_user(this_player());
}


int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="huacong" ) 
	{
		message("vinson", HIY "��ο��������˽�ȥ\n\n" NOR, this_player());

                me->move(__DIR__"pubu");
                
		return 1;
	}
}	


