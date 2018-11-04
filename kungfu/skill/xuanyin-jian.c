// ��������
#include <ansi.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

mapping *action = ({
([      "action" : HIB"$Nһ�����е�$w����ǰֱ��������һ�С�������·��ֱָ$n��$l"NOR,
        "force" : 300,
        "dodge" : 50,
        "damage" : 130,
        "skill_name" : "������·",
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : HIM"$Nʹ���������ֻء���$w����ҡ�ڲ�����ҡҡ�λεô���$n��$l"NOR,
        "force" : 380,
        "dodge" : 70,
        "damage" : 150,
        "skill_name" : "�����ֻ�",
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : HIW"$Nһ�С�����Ϯ�塹��$nһ����$l�Ѿ���$N����"NOR,
        "force" : 400,
        "dodge" : 100,
        "damage" : 170,
        "skill_name" : "����Ϯ��",
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : HIC"$NԾ�����࣬����$w���˸����ߣ�бб���£����������졹������$n��$l"NOR,
        "force" : 500,
        "dodge" : 120,
        "damage" : 190,
        "skill_name" : "��������",
        "lvl" : 70,
        "damage_type" : "����"
]),
([  "action" : HIG"$N�������֣�ͻȻ��$w���ö��ϣ�һʽ������������Ѹ���ޱȵĹ���$n��$l"NOR,
        "force" : 600,
        "dodge" : 150,
        "damage" : 210,
        "skill_name" : "������",
        "lvl" : 90,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if (!me->query("jiuyin/full") && !me->query("jiuyin/xia"))
                return notify_fail("�����ڲ���ѧϰ����������\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
                return notify_fail("��ľ����湦���̫ǳ��\n");
        return 1;
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
        int i, j, level;

        level   = (int) me->query_skill("xuanyin-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        return ([  
                        "action" : action[j]["action"],
                        "force" : action[j]["force"],
                        "dodge" : action[j]["dodge"],
                        "damage" : action[j]["damage"],
                        "damage_type" : action[j]["damage_type"],
                        ]);
                }
}

int practice_skill(object me)
{
	object weapon;

	if( (int)me->query_skill("xuanyin-jian", 1 ) < 150 )
		return notify_fail("�����ڲ�����ϰ����������\n");
        if (!(weapon = me->query_temp("weapon")))
                return notify_fail("����ʱ�޷�������������\n");
        if ((string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ��޷�������������\n");
        if ((int)me->query("jing") < 40)
                return notify_fail("�����������������������\n");
        me->receive_damage("jing", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuanyin-jian/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        string msg;
        int p,j,skill, neili, neili1, exp, exp1;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("xuanyin-jian", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");

        if( me->query("jiali")
	&& me->query_skill("jiuyin-zhengong", 1) > 100
         && skill+50 > random(ob->query_skill("parry", 1)/3)
         && objectp(wp) && wp->query("skill_type")== "sword"
         && skill > 100
         && me->query_skill_mapped("parry") == "xuanyin-jian"
         && living(ob)){
          if(wp1){
           msg = HIW"$N����һ�⣬��������湦һ��\n"NOR;
           msg = replace_string(msg, "$w", wp1->name());
           if(neili >= random(neili1+damage)){
              if(random(me->query_str()) > ob->query_str()/3 && skill > 120){
                  msg += HIW"$n����"+wp1->name()+HIW"��$Nһ�𣬼��䵽�������⣡\n"NOR;
                  wp1->unequip();
                  wp1->move(environment(ob));
                  j = -(damage);
              }
              else{
                  if (damage < 10) damage=10;
                  ob->receive_damage("qi", damage/10);
                  ob->receive_wound("qi", damage/10);
                  p = ob->query("qi")*100/ob->query("max_qi");
                  msg += damage_msg(damage/20, "�˺�");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  j = -(damage/2+skill/2);
              }
           }
           else if(neili >= random(neili1)+damage){
              msg += "�����$n�Ĺ�������һ�衣\n";              
              j = -(damage/2+skill/2);
           }
           else{
              j = damage/2+random(damage/2);
              if(j<damage/2) msg += "�������������$n��������������ȥ��\n";
              else msg += "����Ծ���������$n��������������ȥ��\n";
              j = -j;
           }
           message_vision(msg, me, ob);
           return j;
          }
          else{
           msg = HIY"$N����һת����$n�й�ֱ����\n"NOR;
           if(neili >= neili1+random(neili1)+damage){
                  if (damage < 10) damage=10;
              ob->receive_damage("qi", damage/10);
              ob->receive_wound("qi", damage/10);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*2+skill);
           }
           else if(neili >= random(neili1)+damage){
              msg += "�����$n�Ĺ�������һ�衣\n";              
              j = -(damage+skill);
           }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += "�������������$nһЩ����ת�ƿ�ȥ��\n";
              else msg += "�������������$nһЩ����ת�ƿ�ȥ��\n";
              j = -j;
           }           
           message_vision(msg, me, ob);
           return j;
          }
        }
}
