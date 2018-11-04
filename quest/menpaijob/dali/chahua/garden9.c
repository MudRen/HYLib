//Cracked by Kafei
// Room: /d/dali/garden9.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);

	set("item_desc", ([
		"flower" : RED"ץ��������
�װ������ߵģ���������ױ�ع������ٰ����һĨ���Σ�һ
˿�����Ľ�����ץ����������������˿���ˣ����ǡ���魽����ˡ�
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("objects", ([
		__DIR__"npc/chahua" : random(2),
		]));

	set("exits", ([
		"south" : __DIR__"garden8",
		]));

	set("valid_startroom", 1);

    setup();
}

void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="chahua" || arg=="all" || arg=="cha hua") {
		if (!objectp(ob=present("cha", environment(me)))) {
			tell_object(me, "����ûʲô��Ʒ�ֵĲ軨ֵ�����ߡ�\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu") {
			tell_object(me, "��û�г��ֵĹ�������ֲ����軨��\n");
			return 1;
		}
		if (random(2)==1) {
			message_vision("$NС��������û�������軨�ĸ���������軨����������\n", me);
			ob->move(me);
		}
		else {
			message_vision("$N����ææ���ڲ軨��һ��С�İѸ��ڶ��ˣ��úõ�һ��軨�����ˡ�\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
