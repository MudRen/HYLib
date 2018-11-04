#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(HIW "����" NOR, ({ "yin lang", "yin", "lang" }));
	set("long", HIW "����һֻȫ��ѩ�׵����ǡ�\n" NOR);

	set("age", 3);
	set("str", 35);
	set("dex", 50);
	set("max_qi", 2200);
	set("max_jing", 2200);
	set("combat_exp", 80000);

        set("power", 40);
        set("item1", __DIR__"item/langrou");
        set("item2", __DIR__"item/langpi2");

        set_temp("apply/parry", 180);
        set_temp("apply/dodge", 180);
        set_temp("apply/attack", 160);
        set_temp("apply/defense", 160);
        set_temp("apply/unarmed_damage", 220);
        set_temp("apply/armor", 220);

	setup();
}
