// ����֮��
#include <ansi.h>
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
        set_name(HIC"��ʹ���"NOR, ({"ice limb", "icelimb"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", HIC"����һ˫��ʹ���,�������侫�¡���������յ�����!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("treasure",1);       
                set("wear_msg",HIC"һ������ɫ�Ĺ�â���� ��$N�ı������һ˫��ʹ���\n"NOR);
                set("unequip_msg",HIC"$N���𱳺����ʹ�������ɫ�Ĺ�âҲ������ʧ�ˡ�\n"NOR);
	set("armor_prop/armor", 250);
	set("armor_prop/damage", 250);
	set("armor_type", TYPE_ARMOR);
        }
        setup();
}       


int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(3)==0)
{
message_vision(HIC"$N�������ʹ����ȳ�һ�����磬������$nȫ��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==4)
{
a = (int)me->query_skill("magic-ice", 1);
a=420+a*2;
if (ob->query("qi") > a)
                ob->receive_damage("qi", a);
a=420+a;
if (ob->query("eff_qi") > a)
                ob->receive_wound("qi", a);
}
message_vision(HIC"$n���صı��������ˣ�\n"NOR, me,ob);
return damage;
}	
else   return damage;
}