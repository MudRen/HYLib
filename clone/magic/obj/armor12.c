// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(HIB "ˮ֮����" NOR, ({ "water cloth","watercloth"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"\n����һ��ˮ֮����,�������侫�¡�������ˮ������!\n"NOR);
		set("unit", "��");
                set("value", 50000);
                set("treasure",1);       
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",HIB"һ����ɫ�Ĺ�â���� ��$N�����ϴ�����ˮ֮���¡�\n"NOR);
                set("unequip_msg",HIB"$N��ˮ֮�������¡���ɫ�Ĺ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor", 670);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(HIB"$N���ϵ�ˮ֮����ǰ�����˵���ǽ��������$Nȫ��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==1)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(HIB"$n��ˮǽ���Ĳ��ܶ���!\n"NOR, me,ob);
}
message_vision(HIB"$n���еĹ���ȫ��ˮǽ��ס��\n"NOR, me,ob);
return 0;
}	
else   return damage;
}