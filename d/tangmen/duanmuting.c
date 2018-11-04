// Room: /d/tangmen/duanmuting.c 

inherit ROOM;

void create()
{
	set("short", "��ľͤ");
	set("long", @LONG
	�����Ƕ�ľͤ���ѷ������ִ�����ɣ��м������ŵ��Ӿ�Ȼ����������ľ
���۵���ͷ�󺹡������߾��ǳ�������һ���󷹲˵�����������
LONG
	);

	set("exits", ([
		"north" : __DIR__"chufang",
		"west" : __DIR__"changlang16",
		"east" : __DIR__"guajiantang",
	]));

	
	set("objects",([

		__DIR__"npc/tang_meng" : 1,

	]));

	 setup();
}

void init()
{
	add_action("do_pi", "pi");
	
}


int do_pi(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "chai" ) )
		return notify_fail("��Ҫ��ʲô��\n");
		
	me->receive_damage("qi", 20);

	message_vision("$N���������������ɡ�\n", me);

	if ( (int)me->query_skill("strike", 1) < 60)
	{
		me->improve_skill("strike", me->query("int"));
		write("��������һ������ɣ������Լ�����������ǿ��һ�㡣\n");
		return 1;
	}

	write("��������Ѿ������ˣ��������������������ɡ�\n");

	return 1;
}

