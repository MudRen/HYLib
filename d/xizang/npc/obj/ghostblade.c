#include <weapon.h>
#include <ansi.h> 
inherit BLADE; 
void create()
{
        set_name(BLK"ն��"NOR, ({ "ghost blade","blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѵ���������ڵĺ�������˸�Żް���Ѫ�⡣\n");
                set("value", 8000);
                set("material", "steel");
        set("wield_msg", "$N��������һ����������$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_blade(280);
}
