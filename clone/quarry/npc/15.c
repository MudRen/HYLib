#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "����" NOR, ({ "ji zi", "ji", "zi" }));
	set("long", CYN "����һֻ�ж����ݵ��䡣\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 10);
	set("dex", 25);
	set("max_qi", 400);
	set("max_jing", 400);
	set("combat_exp", 3000);

        set("power", 7);
        set("item1", __DIR__"item/jizirou");

        set_temp("apply/parry", 60);
        set_temp("apply/dodge", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 60);
        set_temp("apply/unarmed_damage", 40);
        set_temp("apply/armor", 40);

	setup();
}
