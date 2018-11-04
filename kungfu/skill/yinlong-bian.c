#include <ansi.h>
inherit SKILL;
mapping *action = ({
([     "action": HIG"$N��$w������Բ��һʽ��Բת���⡹��$w�ѽ�$n$l��ס"NOR,
       "dodge": 50,
       "damage": 100,
       "force":  300,
       "lvl" : 0,
       "skill_name" : "Բת����",
       "damage_type":  "����"
]),
([     "action": HIW"$N��$w��$n����������������Ȼһ�С��������ס���$n$l����������"NOR,
       "dodge": 50,
       "damage": 150,
       "force": 400,
       "lvl" : 60,
       "skill_name" : "��������",
       "damage_type":  "����"
]),
([     "action": HIM"$N�������������$w��Ȼ��ɱ�ֱ��һʽ����������������$nֱ�̹�ȥ"NOR,
       "dodge": 50,
       "damage": 180,
       "force": 450,
       "lvl" : 90,
       "skill_name" : "��������",
       "damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
       object weapon;
	if (!me->query("jiuyin/full") && !me->query("jiuyin/xia") && !me->query("jiuyin/emei"))
                return notify_fail("�����ڲ���ѧϰ���������ޡ�\n");
       if( (int)me->query("max_neili") < 1000 )
               return notify_fail("���������Ϊ���㣬û�а취�����������ޡ�\n");
       if ( !objectp(weapon = me->query_temp("weapon"))
       || ( string)weapon->query("skill_type") != "whip" )
               return notify_fail("���������һ�����Ӳ������޷���\n");
       return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me)
{
        int i, level;
        level   = (int) me->query_skill("yinlong-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if( (int)me->query_skill("yinlong-bian", 1 ) < 150 )
		return notify_fail("�����ڲ�����ϰ���������ޡ�\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("����������������������ޡ�\n");
	if ((int)me->query("neili") < 100 )
		return notify_fail("����������������������ޡ�\n");
	me->receive_damage("qi",20);
	me->add("neili",-20);
	return 1;
}

string perform_action_file(string action)
{
               return __DIR__"yinlong-bian/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
 object weapon, weapon1;    
  int  wp, wp1, wp2,we1,we2;  
  weapon=me->query_temp("weapon");
     weapon1=victim->query_temp("weapon");
     if(objectp(weapon) && objectp(weapon1)){
        wp = weapon->query("rigidity");
        wp1 = weapon1->query("sharpness");
        wp2 = weapon1->query("rigidity");
     if (random(me->query_skill("yinlong-bian",1)<100))
         return 0;
     if (random(10)>4) return 0;    
             if(wp > 10) wp = 10;
             if(wp1 > 10) wp1 = 10;
             if(wp2 > 10) wp2 = 10;
             if( wp > 0 && wp > wp1 && wp > wp2 &&
              random(me->query("str")) > victim->query("str")/2){
              message_vision(HIY "ֻ������ৡ���һ�����죬$N���е�"+weapon1->name()+WHT"�Ѿ���"+weapon->name()+WHT"��Ϊ���أ�\n"NOR, victim );
               weapon1->unequip();
               weapon1->move(environment(victim));
               weapon1->set("name", "�ϵ���" + weapon1->query("name"));
               weapon1->set("value", 49);
               weapon1->set("weapon_prop", 0);
               victim->reset_action();
                } 
              if (wp==0)  {
                we1=me->query_str()+(int)me->query("jiali")+(int)me->query_skill("parry")/3;         
                we2=victim->query_str()+(int)victim->query("jiali")+(int)victim->query_skill("parry")/3;
                if (random(we1)>random(we2))
              {
 message_vision(HIY "ֻ�������������죬$N���е�"+weapon1->name()+HIY"�Ѿ���"+weapon->name()+"����һ���ѳֲ������ַɳ���\n"NOR, victim );
if (!victim->is_busy()) victim->start_busy(random(3));
               weapon1->move(environment(victim));
               }
              }      
              }
       return 0;
}
