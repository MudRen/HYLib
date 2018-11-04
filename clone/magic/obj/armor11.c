// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(RED "��֮�ᾧ" NOR, ({ "fire armor","firearmor"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"\n����һ����֮�ᾧ����,�������侫�¡������л��׵�����!\n"NOR);
		set("unit", "��");
                set("value", 500000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",RED"һ����׵Ĺ�â���� ��$N�����ϴ����˻������ס�\n"NOR);
                set("unequip_msg",RED"$N����֮�ᾧ�������¡����׵Ĺ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor", 660);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(RED"$N���ϵ���֮�ᾧǰ�����˵����ף�������$Nȫ��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==2)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(WHT"$n�������յĲ��ܶ���!\n"NOR, me,ob);
}
message_vision(HIG"$n���еĹ���ȫ�����׵�ס��\n"NOR, me,ob);
return 0;
}	
else   return damage;
}