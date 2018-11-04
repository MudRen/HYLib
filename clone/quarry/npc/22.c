#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(HIW "��¹" NOR, ({ "mi lu", "mi", "lu" }));
	set("long", HIW "����һֻ�ж����ݵ���¹��\n" NOR);
        set("no_auto_kill", 1);

	set("age", 3);
	set("str", 20);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("combat_exp", 20000);

        set("power", 15);
        set("item1", __DIR__"item/lurou");


        set_temp("apply/parry", 100);
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 100);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 120);

	setup();
}
