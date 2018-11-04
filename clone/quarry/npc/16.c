#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + WHT "Ұ��" NOR, ({ "ye lang", "ye", "lang" }));
	set("long", WHT "����һֻ�ײм�����Ұ�ǡ�\n" NOR);

	set("age", 1);
	set("str", 35);
	set("dex", 40);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("combat_exp", 25000);

        set("power", 25);
        set("item1", __DIR__"item/langrou");
        set("item2", __DIR__"item/langpi");

        set_temp("apply/parry", 150);
        set_temp("apply/dodge", 150);
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 200);

	setup();
}
