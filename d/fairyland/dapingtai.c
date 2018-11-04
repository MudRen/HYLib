// Room: /u/qingyun/jyzj/dapingtai.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ƽ̨");
	set("long", @LONG
����һ������Կյļ��ߵ�ƽ̨��ƽ̨��ʮ���ɷ�԰�����ǰ����ٿգ���
�Ȳ��У����಻�ܣ���ǰֻ��ãã�ƺ�������ȥ·��ƽ̨֮���е��ǰװ�����
��ѩ��������ľ������Ұ�ޡ���ʱ�㿴��ƽ̨�����ɽ�ڴ���һ���������ɽ
��(dong)��
LONG	);
	set("exits", ([
		"west" : __DIR__"dashibi",
	]));
	set("outdoors", "kunlun");
        set("item_desc", ([
		"dong" : "һ���������ɽ�����ƺ�������(zuan)��ȥ��\n"
	]));
	setup();
}

void init()
{
	add_action("do_zuan", "zuan");
	add_action("do_jump", ({"jump", "tiao", "yue"}));
}

int do_zuan(string arg)
{
	object me = this_player();

	if (arg == "dong") {
		message("vision", me->name() + "һ�����������ɽ����\n", environment(me), ({me}));
		write("�㼱��ææ������˶��ͷײ����ɽʯ��ֱʹ������۴�С�\n");
		me->move(__DIR__"shandong");
		message("vision", me->name() + "���˽�����ͷ��ײ����ɽʯ�ϡ�\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "down"){
		message("vision", me->name() + "������������ȥ��\n", environment(me), ({me}));
		write("�㲻�������������ȥ��\n");
		me->move(__DIR__"xuedi");
		write(HIR"\n��......�������ˤ��������ˤ�û�����ʹ���������ˡ�\n\n"NOR);
                me->set_temp("last_damage_from", "��������ˤ");
                me->receive_damage("qi", me->query("max_qi"));
                me->receive_wound("qi", me->query("max_qi") / 2);
		message("vision", me->name() + "������ˤ��������\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
