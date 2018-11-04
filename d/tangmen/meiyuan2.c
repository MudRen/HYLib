// Room: /d/tangmen/meiyuan2.c

inherit ROOM;

void create()
{
	set("short", "÷԰");
	set("long", @LONG
	���������е�һ��Ƭ÷�֣�ÿ����԰÷�����ţ�����Ϯ�ˣ����˾���������
ˬ��԰����һ��÷���Ķ�׮��Ҳ���÷��״��׮��ʮ��ƽ��������������������Ծ
(tiao)��
LONG
	);
	
set("outdoors", "tangmen");
	set("exits", ([
		
		"west" : __DIR__"meiyuan1",
		"east" : __DIR__"zhanmeige",
	]));

	setup();
}

void init()
{
	add_action("do_tiao", "tiao");
	
}


int do_tiao(string arg)
{
	object me;

	me = this_player();

	if ( !arg || ( arg != "zhuang" ) )
		return notify_fail("���ֲ��Ǻ��ӣ��ұ������ĸ�ʲô��\n");
		
	me->receive_damage("qi", 20);

	message_vision("$N����һԾ������÷��׮��\n", me);

	if ( (int)me->query_skill("dodge", 1) < 60)
	{
		me->improve_skill("dodge", me->query("int"));
		write("����÷��׮��������һȦ�����ö�����������Щ�˽⡣\n");
		return 1;
	}

	write("������Ҳû���ˡ�\n");

	return 1;
}
