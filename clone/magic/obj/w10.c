// ������
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIG"����Ũ���"NOR, ({"magic clubc", "mclubc"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"����һ������Ũ���,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",40);
        }
     init_club(480);
        setup();
}       