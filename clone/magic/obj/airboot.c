// shoe.c
//by steel
#include "armor.h"
#include "ansi.h"

inherit BOOTS;

void create()
{
	set_name(HIC "���սѥ" NOR, ({ "air boot", "airboot"}) );
       	set("long", HIC"����һ˫���սѥ,�������侫�¡���������Ų�֮һ��\n"NOR);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "˫");
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                       set("armor_prop/dexterity",15);
       set("armor_prop/constitution",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-ice",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
		set("armor_prop/armor",150);
		set("armor_prop/damage", 250);
                set("wear_msg",HIC"һ�������Ĺ�â���� ��$N�Ľ��϶����һ˫���սѥ��\n"NOR);
                set("unequip_msg",HIC"$N�����սѥ���¡������Ĺ�âҲ������ʧ�ˡ�\n"NOR);
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
message_vision(HIC"$N���ϵ����սѥ����ҫ�۵Ĺ�â��һ���������$n��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
a = (int)me->query_skill("magic-ice", 1);
a=300+a*2;
                ob->receive_damage("qi", a);
a=300+a;
                ob->receive_wound("qi", a);
message_vision(HIR"$n����û����ܣ�һ������˶���������$n!\n"NOR, me,ob);
}
else message_vision(HIR"������$n��໮����$n�������ˡ�!\n"NOR, me,ob);
}
if (random(4)==1)
{
message_vision(HIC"$n���ϵ����սѥ����ҫ�۵Ĺ�â��Χ��$n��\n"NOR, ob,me);
if (me->is_busy())
{
me->start_busy(1);
message_vision(HIC"$nԭ����̫�����ж����ָ��ˣ�\n"NOR, ob,me);
}
}
else   return damage;
}