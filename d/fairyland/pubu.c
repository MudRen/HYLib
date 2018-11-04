// Room: /u/qingyun/jyzj/pubu.c
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"�ٲ�"NOR);
	set("long", @LONG
�������߳������·��ֻ���ͱ�����һ�����ٲ�������£�������ѩ�ڶ�
�ɣ���������������һ������������׳���������ٲ�к��һ���峺���̵���̶
(pool)֮�У�̶ˮȴҲ����������������йˮ��ȥ·��̶ˮ�в�ʱ������һβ
����㣬�ƺ����ֿɵá�
LONG	);
	set("exits", ([
		"east" : __DIR__"cuigu",
	]));
        set("item_desc", ([
		"pool" : "ֻ�����̵�ˮ��ʮ���������(fish)�����ζ��š�\n"
	]));
	set("resource/water", 1);
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("fish_count", 20);
	setup();
}

void init()
{
	add_action("do_catch", ({"catch", "zhua", "zuo"}));
}

int do_catch(string arg)
{
	object me = this_player();

	if (arg == "fish" || arg == "white fish" || arg == "yu") {
		if (query("fish_count")) {
			if (!present("zhi tiao", me))
				message_vision("̶��Ծ��һβ����㣬$Næ����ȥץ����Ȼ����������ȴһ�������ˡ�\n", me);
			else {
				message_vision("һβ���������ˮ�棬$N��һ����֦ʹ��������ȥ����������\n", me);
				add("fish_count", -1);
				new(__DIR__"obj/fish")->move(me);
			}
			return 1;
		}
		else
			return notify_fail("̶��İ��㶼����ץ���ˡ�\n");
	}
	return 0;
}
