// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

//inherit ARMOR;
inherit CLOTH;
void create()
{
	set_name(HIW "ˮ������" NOR, ({ "water armor","waterarmor"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW"\n����һ��ˮ������,�������侫�¡���������Ų�֮һ!\n"NOR);
		set("unit", "��");
		set("no_put", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
          set("armor_prop/intelligence",15);
          set("armor_prop/dexterity",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-water",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("wear_msg",HIW"һ��ˮɫ�Ĺ�â���� ��$N�����ϴ�����ˮ�����ס�\n"NOR);
                set("unequip_msg",HIW"$N��ˮ���������¡�ˮɫ�Ĺ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor", 1600);
		set("armor_prop/defense", 30);	
set("armor_prop/damage", 150);
	}
	setup();
}

void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

int ob_hit(object ob, object me, int damage)
{
   int neili,a;
if (random(4)==0)
{
message_vision(HIW"$N���ϵ�ˮ������ǰ�����˵����ڣ�������$Nȫ��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
if (!ob->is_busy())
ob->start_busy(4);
message_vision(WHT"$n�����Ĳ��ܶ���!\n"NOR, me,ob);
}
message_vision(HIG"$n���еĹ���ȫ�����˱����ϣ�\n"NOR, me,ob);
return 0;
}
else   return damage;
}