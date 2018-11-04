#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�뷿");
        set("long", @LONG
������С��Ĺ뷿��һ���������������һ����齷���ǽ�ǣ�����ϸɴ��
��С��������һ��ջ��ڳ�˼������������԰��
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan",
                "west" : __DIR__"huayuan",
        ]));

        set("objects", ([
                __DIR__"npc/shuanghua" : 1,
        ]));
        set("cost", 0);
        setup();
}

void init()
{
	add_action("do_biqi", "biqi");
	add_action("do_biqi", "bingqi");
}

int do_biqi()
{
	object me = this_player();
	if (!me->query_temp("jinboxunhua"))
		return 0;
	me->set_temp("biqi", 1);
	message_vision(HIG"$N����һ��������ס�˺�����\n"NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "south")
		me->delete_temp("biqi");
	return ::valid_leave(me, dir);
}