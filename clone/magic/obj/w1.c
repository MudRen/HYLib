// ��ɫ��ǹ
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(RED"����ս�"NOR, ({"fire sting", "firesting"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"����һ�˻���ս�,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_club(450);
        setup();
}       