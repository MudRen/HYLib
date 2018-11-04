// Room: /d/tangmen/bingqiku.c
// BY congw

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long", @LONG
	���������ŵı����⣬������������ѷ��Ÿ��ָ����İ��������������ŵ���
���������ȡ�á����ﻹ�л�¯�������������Լ��������(da)���ڡ�
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang4",
		"west" : __DIR__"xingtang",
		"east" : __DIR__"xiaoxiao-lou",
	]));
	set("objects", ([
                "/d/jingzhou/obj/armor": 3,
		"/d/tangmen/obj/gangbiao1": 15,
		
	]));
	setup();
}
void init()
{
	add_action("do_da", "da");
	add_action("do_sheng", "sheng");
	
}


int do_da(string arg)
{
	object me;
        object ob;
	me = this_player();

	if ( !arg || ( arg != "biao" ) )
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->query_temp("marks/��")){
		if (me->query("qi")<10){write("���Ѿ�̫���ˣ���Ϣһ����ٴ�ɡ�\n");return 1;}
	me->receive_damage("qi", 5);

	message_vision("$N��ͷ�󺹣�������������\n", me);

	ob=new("/d/tangmen/obj/gangbiao1");
        ob->move(this_player());
        message_vision("$N�Ѿ������һö���ڡ�\n", me);
		return 1;
	}

	write("���Ѿ�Ϩ���ˣ��㻹�ǰѻ���������˵�ɡ�\n");

	return 1;
}
int do_sheng(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "huo" ) )
		return notify_fail("��Ҫ��ʲô��\n");
		if (me->query_temp("marks/��"))
	{write("���Ѿ������ˡ�\n");return 1;}
	message_vision("$N��¯������Щľ̿��������俪ʼ����\n", me);
	message_vision(HIR"¯������ȼ��������\n"NOR,me);
	this_player()->set_temp("marks/��",1);
        remove_call_out("fire");
        call_out("fire", 20, this_object());

	return 1;
}
void fire(object room)
{
    message("vision",HIY"ֻ��¯�������˼��£�Ϩ�ˡ�\n"NOR, room);
    this_player()->delete_temp("marks/��");
}
