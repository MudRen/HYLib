#include <ansi.h>
#include "quarry.c"

void create()
{
        set_name(NOR + CYN "�ڹ�" NOR, ({ "wu gui", "wu", "gui" }));
	set("long", CYN "����һֻ���ڹ꣬����������С�ˡ�\n" NOR);
        set("no_auto_kill", 1);

	set("age", 28);
        set("str", 5);
        set("dex", 2);
        set("con", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("combat_exp", 1000);

        set("power", 5);


        set_temp("apply/attack", 15);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 200);

	setup();
}
