#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ת��ɽ��,ǰ���ɳ̲��ɽ�����ں���һ��,��ʧ�ڲ�����ӿ�ĺ�
ˮ��,�����Ѱ�,�������¡¡�ľ���.ǰ��������·��ͨ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"underhill2",
]));
	set("objects",([
		__DIR__"npc/man4":1,
	]));
	setup();
}
void init()
{
        add_action("do_break","break");
}
int do_break(string arg)
{
        object me;
        me = this_player();
        if (arg != "ɽ��" ) return 0;
        if (me->query("force_factor") < 50 || me->query("str") < 15)
                return notify_fail(HIR"�����ɽ�������˼���,���ʲô��ӳ��û��..\n"NOR);
        if (me->query_skill("dodge") < 50 )
                return notify_fail(HIR"�����ɽ�������˼���,���ɽ�ϵ�����һ����ʯͷ,�������˸���Ѫ��ͷ..\n"NOR);
                me->add("eff_kee",-10);
        message_vision("$N����ɽ�������˼���,��������д���һ�������ص�ɽ��.\n",me);
        me->add("kee",-10);
        me->start_busy(2);
        set("exits/enter", __DIR__"dong");
        return 1;
}
