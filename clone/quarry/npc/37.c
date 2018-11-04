#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "���" NOR, ({ "zhang zi", "zhang", "zi" }));
	set("long", CYN "����һֻ�ж����ݵ�⯡�\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 10);
	set("dex", 25);
	set("max_qi", 500);
	set("max_jing", 500);
	set("combat_exp", 5000);

        set("power", 9);
        set("item1", __DIR__"item/zhangrou");

        set_temp("apply/parry", 60);
        set_temp("apply/dodge", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 60);
        set_temp("apply/unarmed_damage", 50);
        set_temp("apply/armor", 30);

	setup();
}
