// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
	set_name(HIW "�׽����" NOR, ({ "earth badge","earthbadge"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIY"\n����һ��׽����,�������侫�¡������д�ص�����!\n"NOR);
		set("unit", "��");
                set("value", 50000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("wear_msg",HIY"һ���صĹ�â���� ��$N�����ϴ����˰׽���¡�\n"NOR);
                set("unequip_msg",HIY"$N�Ѱ׽�������¡���صĹ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor", 500);
	}
	setup();
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(5)==0)
{
message_vision(HIC"$N���ϵİ׽����ǰ�����˵���ì��������$nȫ��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3
&& ob->query("magicgift")==3)
{
if (!ob->is_busy())
ob->start_busy(2);
message_vision(HIC"$n����ì�̵Ĳ��ܶ���!\n"NOR, me,ob);
}
message_vision(HIC"$n���еĹ���ȫ����ì��ס��\n"NOR, me,ob);
return 0;
}	
else   return damage;
}