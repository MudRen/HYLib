// dongkou.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

string look_huan();
void create()
{
	set("short", "����");
	set("long", @LONG
�ߵ�ʮ�ಽ����������˿����������������ƽ������������ʯ��·��һ����
���е�·���Ǿ����˹�������ֻ�ǵ�·��ס��������б������Խ��Խ��ͻȻ֮
�䣬������ʲô����Բ������һ�£�����������ԭ���Ǹ��Ż�(huan)
LONG
	);
        set("exits", ([
		"out" : __DIR__"shibi",
        ]));
        set("outdoors", "����");
	set("item_desc", ([
             "huan" : "�Ż���һ�ȴ����ϣ����Ը������ɣ������沢δ���ϡ�\n",
	]));

	setup();
}

void init()
{
        add_action("do_knock", "knock");
        add_action("do_knock", "qiao");
        add_action("do_enter", "push");
        add_action("do_enter", "tui");
}

int do_knock(string arg)
{
	object me;
 	me = this_player();
        if (!arg ||arg!="huan") return 0;
	message_vision("$N�����Ż���������һ�£����������˴�Ӧ��\n" , me);
        me->set_temp("knock_door", 1);
	return 1;
}

int do_enter(string arg)
{
	object me = this_player();
        if (!arg ||arg!="huan") return 0;
        if ( me->query_temp("knock_door")){
        message_vision("$N�־�ʹ����ȥ�����ű㻺���Ŀ��ˡ�\n"  , me);
	set("exits/enter", __DIR__"dong1");
        return 1; 
        }
      return notify_fail("������óȻ���벻̫�ðɡ�\n");
}
