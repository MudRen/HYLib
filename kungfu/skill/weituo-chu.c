#include <ansi.h>
inherit SKILL;
 
mapping *action = ({
([
"action":"$NԾ�ڰ�գ�һ�С��ɺ�չ������ɽ��������$w�ѻ���������Ӱ����$n�ۻ����ң���֪���룬��������",
         "force" : 380,
         "dodge" : 20,
         "parry" : 20,
        "damage": 620,
         "lvl" : 0,
         "skill_name" : "�ɺ�չ������ɽ",
         "damage_type":"����"
]),
([
"action":"$Nͦ$w��$n����ʽ��ס��˳��һ�С������λ����ɹ�����$w�������ҷɿ������������ߣ���$nѹ������",
         "force" : 300,
         "dodge" : 10,
         "parry" : 15,
        "damage": 630,
         "lvl" : 30,
         "skill_name" : "�����λ����ɹ�",
         "damage_type":"����"
]),
([
"action":"$Nһ�С���¹̤�����ɲݡ�����ϥ��������$w����$n���̣�ȴδ���������ϣ��͵�һ�ᣬ��$n���ظ����ȥ",
         "force" : 320,
         "dodge" : 15,
         "parry" : 20,
        "damage": 640,
         "lvl" : 60,
         "skill_name" : "��¹̤�����ɲ�",
         "damage_type":"����"
]),
([
"action":"$NͻȻ�����ڵأ�$n��㵼䣬һ�С�����ԾˮǱ��ء�������$n�����´ܹ���������ͷ��$w����ɨ��$n��$l",
         "force" : 640,
         "dodge" : 120,
         "parry" : 25,
        "damage": 660,
         "lvl" : 80,
         "skill_name" : "����ԾˮǱ���",
         "damage_type":"����"
]),
([
"action":"$Nһ�С���Գ�׹�����������������磬����$n�ɿ챼�ܣ�����$wһ�п���һ�У�ɲ�Ǽ���$n�����ʮ����",
         "force" : 680,
         "dodge" : 130,
         "parry" : 30,
        "damage": 680,
         "lvl" : 100,
         "skill_name" : "��Գ�׹�������",
         "damage_type":"����"
]),
([
"action":"$N��̤����ǰ������˫�ۣ�����$w�󿪴��أ�����������һ�С���ӥ����ɨǬ����ɨ��$n������",
         "force" : 660,
         "dodge" : 130,
         "parry" : 40,
        "damage": 600,
         "lvl" : 120,
         "skill_name" : "��ӥ����ɨǬ��",
         "damage_type":"����"
]),
([
"action":"$N���һ����һ�С�������ˮ�����桹��$w���ַɳ������ž�������$n��ǰ�ģ��漴����$n����������ְ�$w��������",
         "force" : 600,
         "dodge" : 120,
         "parry" : 30,
        "damage": 680,
         "lvl" : 130,
         "skill_name" : "������ˮ������",
         "damage_type":"����"
]),
([
"action":"$N˫ĿԲ��������Ĭ�����ԣ�һ�С�������ƺ���������$w����ǧ����������ֻ�����$n�ĵ�ͷ����",
         "force" : 550,
         "dodge" : 120,
         "parry" : 30,
        "damage": 500,
         "lvl" : 150,
         "skill_name" : "������ƺ�����",
         "damage_type":"����"
]),
});
 
int valid_enable(string usage) { return  (usage == "club") || (usage =="parry"); }
 
int valid_learn(object me)
{
           mapping fam  = me->query("family");
         if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������������\n");
         if ((int)me->query_skill("yijinjing", 1) < 160)
                return notify_fail("����׽�ڹ����̫ǳ��\n");
         if((int)me->query_skill("zui-gun",1) <120)
      		return notify_fail("����������㣬��������Τ���ơ�\n");
         if((int)me->query_skill("zui-gun",1) <120)
      		return notify_fail("����������㣬��������Τ���ơ�\n");

         if((int)me->query_skill("longzhua-gong",1) <120)
      		return notify_fail("�����צ�����㣬��������Τ���ơ�\n");

         if((int)me->query_skill("weituo-gun",1) <120)
      		return notify_fail("���Τ�Թ����㣬��������Τ���ơ�\n");
         return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"weituo-chu/" + action;
}
string query_skill_name(int level)
{
         int i;
         for(i = sizeof(action)-1; i >= 0; i--)
                 if(level >= action[i]["lvl"])
                         return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("weituo-chu",1);
         lvl = (int)me->query_skill("longzhua-gong", 1);
         
         
         if ( level >= 200 && lvl >= 200 && random(level) > lvl / 2
         &&  !me->is_busy()
         && objectp(target = me->select_opponent())
         && objectp(weapon = me->query_temp("weapon"))
         && me->query_skill_mapped("claw") == "longzhua-gong" 
         && me->query_skill_prepared("claw") == "longzhua-gong" 
         && me->query("neili") > 300 && me->query("jing") > 100 ) {
         	pre = me->query_skill_prepare();
        	skill = keys(pre);     
        	for (i=0; i<sizeof(skill); i++){
                	if(skill[i]=="claw") continue; 
                	a = skill[i];
                	b = pre[skill[i]];
                	me->prepare_skill(skill[i]);
        	}
        	
                weapon->unequip();
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
                weapon->wield();
                me->prepare_skill(a,b);
                me->add("neili", -25);
  
         }
        


         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}
 mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return HIR"ֻ��$n$l�ƺ�һ�����³�һ����Ѫ���ѱ��׽�Ļ�������������!\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("weituo-chu",1)) > 50 ) 
{
	  victim->receive_wound("qi", (damage_bonus)/2+120);
        return HIR "$n������ľ������У�����һ������������\n" NOR;
}
}

int practice_skill(object me)
{
         object weapon;
         if((int)me->query_skill("zui-gun",1) <=120)
      		return notify_fail("����������㣬��������Τ���ơ�\n");

         if((int)me->query_skill("longzhua-gong",1) <=120)
      		return notify_fail("�����צ�����㣬��������Τ���ơ�\n");

         if((int)me->query_skill("weituo-gun",1) <=120)
      		return notify_fail("���Τ�Թ����㣬��������Τ���ơ�\n");
      		
         if (!objectp(weapon = me->query_temp("weapon"))
                  || (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԡ�\n");
         if ((int)me->query("jing") < 70)
                return notify_fail("�������������Τ�ӹ���\n");
         if ((int)me->query("neili") < 40)
                return notify_fail("�������������Τ�ӹ���\n");
                
 me->receive_damage("jing", 30);           
         if((int)me->query_skill("weituo-chu",1)> 200)
 me->add("neili",-10);

         return 1;
}
