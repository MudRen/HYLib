#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + CYN "��ȸ" NOR, ({ "ma que", "ma", "que" }));
	set("long", CYN "����һֻС��ȸ������ؼ��������¡�\n" NOR);
        set("no_auto_kill", 1);
        set("aves", 1);

	set("age", 1);
	set("str", 5);
	set("dex", 28);
	set("max_qi", 80);
	set("max_jing", 80);
	set("combat_exp", 1000);

        set("power", 3);

        set_temp("apply/dodge", 60);
        set_temp("apply/defense", 60);

	setup();
}
