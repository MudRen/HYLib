// shulin1.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", "ɽ������");
	set("long", @LONG
�������£������ȣ����о����ĵģ���˵�˼�����������Ҳ�ް�㣬Ψ
��������䣬ң��ͺ��������ٲ��������Ͽ�ȥ��ֻ���ٲ�֮��һ��ʯ�ڹ���
���񣬲�֪������ĳ弤ĥϴ���Ž������ʯ��ĥ�����ƽ����������ˮ����
�٣��Ž���Ƭ����������������ʯ��¶�˳�����
LONG
	);
        set("exits", ([
              "south" : __DIR__"donghubian",
	]));
        set("outdoors", "����"); 
	set("objects", ([
	   __DIR__"obj/yeguo" : 2,
	]));
 
	setup();
}

void init()
{
        add_action("do_move", "enter");
        add_action("do_move", "zuan");
}

int do_move(string arg)
{
	object me;
 	me = this_player();
    if (!arg || arg != "shucong" ) return 0;
	message_vision("$N�ǿ�Ұ�����ԣ������Ժ��߹�ȥ��\n" NOR, me);
	me->move(__DIR__"shuhou");
	return 1;
}
