// cw_hat
//by steel
#include "ansi.h"
#include "armor.h"
inherit HEAD;
void create()
{	
  set_name(HIR"����֮��"NOR, ({ "fire hat", "firehat" }) );
  set_weight(1000);	
   if( clonep() )
  set_default_object(__FILE__);
  else {
		set("unit", "��");
set("long", HIR"����һ������֮��,�������侫�¡���������Ų�֮һ��\n"NOR);
		set("no_put", 1);
//		//set("value", 100000);
set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-fire",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("wear_msg",HIR"һ����Ĺ�â���� ��$N��ͷ�϶����һ������֮����\n"NOR);
                set("unequip_msg",HIR"$N�ѻ���֮�����¡����Ĺ�âҲ������ʧ�ˡ�\n"NOR);
		set("armor_prop/armor",200);
		set("armor_prop/damage", 200);
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
message_vision(HIR"$Nͷ�ϵĻ���֮�����������⣬һ�����������$n��\n"NOR, me,ob);
 if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
a = (int)me->query_skill("magic-fire", 1);
a=300+a*4;
                ob->receive_damage("qi", a);
a=300+a;
                ob->receive_wound("qi", a);
message_vision(HIR"$nȫ����������!\n"NOR, me,ob);
}
else message_vision(HIG"��������$n��໮����$n�������ˡ�!\n"NOR, me,ob);
}
else   return damage;
}