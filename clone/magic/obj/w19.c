// ����ϣ�����
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIY"ʥ��֮ǹ"NOR, ({"magic clube", "mclube"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"����һ��ʥ��֮ǹ,�������侫��!\n"NOR);
                set("unique", 1);
                set("armor_prop/constitution",15);
                set("value", 165000);
		set("armor_prop/armor",80);
        }
     init_club(800);
        setup();
}       