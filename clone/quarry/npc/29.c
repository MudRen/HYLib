#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "Ұ��" NOR, ({ "ye tu", "ye", "tu" }));
	set("long", WHT "����һֻë���׵�Ұ���á�\n" NOR);
        set("no_auto_kill", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 30);
	set("max_qi", 200);
	set("max_jing", 200);
	set("combat_exp", 1000);

        set("power", 5);
        set("item1", __DIR__"item/turou");

        set_temp("apply/dodge", 80);
        set_temp("apply/defense", 80);

	setup();
}
