#include <ansi.h>
#include "quarry.c"

void create()
{
	set_name(NOR + YEL "�ϻ�" NOR, ({ "lao hu", "lao", "hu" }));
	set("long", YEL "����һֻ����ͻ������ͼ��ˡ�\n" NOR);

	set("age", 3);
	set("str", 35);
	set("dex", 50);
	set("max_qi", 3000);
	set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
	set("combat_exp", 200000);

        set("power", 40);
        set("item1", __DIR__"item/hurou");
        set("item2", __DIR__"item/hupi");

        set_temp("apply/parry", 180);
        set_temp("apply/dodge", 180);
        set_temp("apply/attack", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/unarmed_damage", 220);
        set_temp("apply/armor", 220);

	setup();
}
