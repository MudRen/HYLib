#include <weapon.h>
#include <armor.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(BLK"����"NOR, ({"si dao","blade"}) );
        set_weight(2000);
        set("long","һ����״���صĶ̵���Ѫ�ۼ��֣�������һ����������Ϣ͸����\n" NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1000);
                set("cant_sell","����ѵ���˭���ģ���С��ɲ������ۣ�\n");
                set("material", "steel");
                set("armor_prop/armor",20);
        }
        init_blade(300);
        set("wield_msg", "$N��ৡ���һ�����һ�����λε�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        setup();
}
