// taizu-quan ̫�泤ȭ
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";


mapping *action = ({
([     "action" : "$Nһʽ��ǧ����С���˫��ֱ��ֱ�£��͹���ǰ������$n��$l",
       "force" : 100,
        "dodge" : 20,
        "parry" : 50,
       "damage": 200,
       "lvl" : 0,       
       "damage_type" : "����"
]),
([     "action" : "$N����ǰ�㣬��ȭֱ������һ������$n������һ�С�����ն����",
       "force" : 135,
        "dodge" : 20,
       "damage": 200,
       "lvl" : 0,
        "damage_type" : "����"
]),
([     "action" : "$Nʹ�С���˷����������������һ�������ȭ����$n",
       "force" : 240,
        "dodge" : 10,
        "parry" : 25,
       "damage": 200,
       "lvl" : 10,
        "damage_type" : "����"
]),
([     "action" : "$N˫ȭ����������������飬���͡�������ͨ��֮��",
       "force" : 350,
        "dodge" : 35,
        "parry" : 330,
       "damage": 200,
       "lvl" : 10,
        "damage_type" : "����"
]),
([     "action" : "$N������������һת�������غ�˫ȭ���������$n��$l��������������",
       "force" : 400,
        "dodge" : 110,
        "parry" : 335,
        	"damage": 200,
       "lvl" : 30,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }



string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    object ob;
    ob = me->select_opponent();
       level   = (int) me->query_skill("taizu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
    level   = (int) me->query_skill("taizu-quan",1)/10;
    if (!userp(me) || (int)me->query_skill("taizu-quan", 1) > 10)
{
if (  !me->is_busy()
&&living(ob)
&& !me->query_temp("dsauto")
&& !me->query_temp("sc_hama")
&& random(me->query_skill("taizu-quan",1))> 180
)
{
	 message_vision(HIW"\n�����ؾ�!��$N�Լ����ٵ�����,�ڵ�һ����,$nû�����ֿ���ʱ����ڶ���! \n"NOR, me,ob);
me->set_temp("dsauto",1);
	me->add_temp("apply/attack", (level*2));
	me->add_temp("apply/damage", (level*4));
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	me->add_temp("apply/attack", -(level*2));
	me->add_temp("apply/damage", -(level*4));
me->delete_temp("dsauto");
}
}

}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("�������������̫�泤ȭ��\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}



int valid_learn(object me)
{
        return notify_fail("NPC�书��������ҿ��š�\n");
}





mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taizu-quan",1);
	jiali = me->query("jiali");
if (userp(me)) return;
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>80 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫ�񱼣��ѱ������������˿���!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("taizu-quan", 1);

//        if( me->is_busy()) return 1;

        if( userp(me)) return 1;
        if( damage < 10 ) return 1;
    if (userp(me)) return 1;

        if (  random(level) > 150
         

           ){
         msg = HIG"$N���$n�Ĺ��ơ�����һ����ͻ������!!!��\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"�� ���ջ���! ����$N�����ؾ�����������Զ��������$n,�����ֲ�Զ���빥���Ĳ��� ��\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/15);
}
else
{
ob->add("qi",-5000);
ob->add("qi",-5000);
}
msg += damage_msg(damage, "����");



            }
else  if (random(3)==1 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"���ɺ׷���!����$Nʹ�����ֱ�Ӵ��ڵ�ȭ��֮һ����$n! ���߷��Ѷ���һ��!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
}

msg += damage_msg(damage, "����");
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"���������!����$Nθװ�ʹ�,�û�ʯ�Ƶļ�������������,$n������Ļ������!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
}
else
{
ob->add("qi",-3500);
ob->add("qi",-3500);
}
msg += damage_msg(damage, "����");
            }
else
           msg = HIG"$n�ϵ���������,���˿�������������!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
