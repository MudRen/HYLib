// shiguan.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ʯ����");
        set("long", 
"�׸��ڲ��ƺ�д�����֣���Ŀ��ȥ��������ʮ�������֣���"HIR"��Ů�ľ�����
ѹȫ�档����һ����������ˡ�"NOR"����ʮ��������Ũī���飬�����Ծ���������
����ʱ�׸�ֻ�ƿ���һ�룬��б�ۿ�ȥ���������������\n"
        );

        set("exits", ([
                "out" : __DIR__"lingshi",
        ]));

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_tang",  ({ "tang" }));
	add_action("do_search",  ({ "search" }));
	add_action("do_turn",  ({ "turn" }));
}

int do_tang (string arg)
{
	object me = this_player();
	
	if( !arg || arg!="shiguan" )
		return notify_fail("��Ҫ�������\n");
	message_vision(HIY"$N�ɽ���ʯ�ף���������ת���ŵأ�\n", me);
	if (!present("fire", me)) {
		message_vision("�������һ�ţ�$NʲôҲ��������\n"NOR, me);
		return 1;
	}
	message_vision("ֻ�������� ---����һ����$N���������еĻ��ۡ�\n"NOR, me);
	write("\n�ٿ���ʮ������ʱ��ֻ�����д�������С�֣��ƽ���Ů�ľ�֮��������֮\n�ڴ���֮�£�������Ե��һ�۱�֪ .....�������� ....\n\n");
	me->set_temp("jiuyin/gumu", 1);
	return 1;
}

int do_search()
{
	object me = this_player();

	if (me->query_temp("jiuyin/gumu") < 1)
		return 0;
	message_vision("$N�������ۣ���ϸ����ʯ��������������\n", me);
	if (random(10) == 0) {
		message_vision("$N��������һ������Ȼ����������һ�ֵİ�(ao)����\n", me);
		me->set_temp("jiuyin/gumu", 2);
	}
	return 1;
}

int do_turn (string arg)
{
	object me = this_player();
	
	if (me->query_temp("jiuyin/gumu") < 2)
		return 0;
	if( !arg || (arg!="left" && arg!="right"))
		return notify_fail("������ʲô����ת��\n");
	if (arg == "right")
		return notify_fail("�㽫��������ת�����£�����ʲôҲû�з�����\n");
	message_vision("$N����������ת�����£���Ȼ��Щ�ɶ���\n", me);
	message_vision(HIY"\n$N������ס�˰�������һ��,ֻ������һ�죬�׵�ʯ��Ӧ�ֶ���\n$N⧲���������������²�ʯ�ҡ�\n"NOR, me);
	me->set_temp("jiuyin/gumu", 3);
	me->move(__DIR__"shishi");
	return 1;
}
