#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(NOR + CYN "��˿" HIY "����" NOR, ({ "zhensi baojia", "zhensi", "baojia" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + CYN "����һ�����������ף����ֳ�"
                            "�أ�����֮�º������ۡ�\n" NOR);
                set("treasure", 1);
                set("value", 8000);
                set("material", "silk");
                set("armor_prop/armor", 500);
                set("stable", 300);
        }
        setup();
}
