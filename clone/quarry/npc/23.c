#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "���" NOR, ({ "ban jiu", "ban", "jiu" }));
	set("long", WHT "����һֻС��𣚣����ؼ��������¡�\n" NOR);
        set("no_auto_kill", 1);
        set("aves", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 28);
	set("max_qi", 120);
	set("max_jing", 120);
	set("combat_exp", 1000);

        set("power", 3);

        set_temp("apply/dodge", 60);
        set_temp("apply/defense", 60);

	setup();
}
