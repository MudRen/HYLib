// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit SHIELD;

void create()
{
	set_name(RED "�־�֮��" NOR, ({ "dark shield","darkshield"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"\n����һ��־�֮��,�������侫�¡������кڰ�������!\n"NOR);
		set("unit", "��");
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

        set("armor_prop/intelligence",10);
         set("armor_prop/strength",10);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",RED"һ��Ѫ��Ĺ�â���� ��$N�����϶���һ��־�֮�ܡ�\n"NOR);
                set("unequip_msg",RED"$N�ѿ־�֮�����¡�Ѫ��Ĺ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor", 500);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(4)==0)
{
message_vision(HIR"$N���ϵĿ־�֮��ǰ��������ħ�������С�͵ĺڶ�����$nȫ��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==6)
{
if (!ob->is_busy())
ob->start_busy(3);
a=350+damage;
if (ob->query("qi") > a)
{
ob->receive_damage("qi", a);
a=200+damage;
ob->receive_wound("qi", a);
}
message_vision(HIC"$n�����ں�������Ĳ��ܶ���!\n"NOR, me,ob);
}
message_vision(HIC"$n���еĹ���ȫ���־�֮�ܵ�ס��\n"NOR, me,ob);
return 0;
}	
else   return damage;
}