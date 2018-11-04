// taxue-wuhen.c ̤ѩ�޺� 

#include <combat.h>
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "$nһʽ������ƽɳ�����������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ�ԡ�\n",
        "$nһʽ���������𡹣������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
        "$nһʽ���������ڡ���������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
        "$nһʽ�����ɵ��ҡ���ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
        "$nһʽ����ѩ��̲�����ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
        "$nһʽ����˿���꡹��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
        "$nһʽ��������ѩ�������в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
        "$nһʽ������ǱԾ������Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
        "$nһʽ��̤ѩ�޺ۡ������μ�����ת�����¾ͻ�������֮�⡣\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 60 )
                return notify_fail("�������̫���ˣ�������̤ѩ�޺ۡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������̫���ˣ�������ϰ̤ѩ�޺ۡ�\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{       
        return __DIR__"taxue-wuhen/" + action;
}

mixed valid_damage(object me, object victim, int damage, object weapon)
{
        int ap, dp, level;
        object weapon1 = me->query_temp("weapon");
        mapping prepare;
        string result, attack_skill;

        if ( victim->query_skill("taxue-wuhen", 1) < 100
         || victim->query_skill_mapped("force") != "xuantian-wuji" 
         || victim->query_skill("xuantian-wuji", 1) < 100 
         || victim->query_skill("mantian-huayu", 1) < 100 
        || !living(victim) )
                return;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
          if( victim->query_skill_mapped("force") == "xuantian-wuji" )
                dp += COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);

        ap = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
        prepare = me->query_skill_prepare();
        if( !prepare ) prepare = ([]);

        if( objectp(weapon1) ) attack_skill = weapon1->query("skill_type");
        else switch( sizeof(prepare) )
        {
                case 0: attack_skill = "unarmed"; break;
                case 1: attack_skill = (keys(prepare))[0]; break;
                case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
        }

        ap += COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        ap /= 100;
        dp /= 100;

        if ( random(ap+dp) > ap ) {
                result =  "$n����һ������һ�ߣ�����������״��$N��ͷһ����һʱ�е���æ���ң�\n";
                result += "$n���л��ɳã����̶�$N�������ƣ�\n" ;

                return ([ "msg" : result, "damage" : -damage ]);
        }
         else if ( random(ap+dp) > ap ) {
                result = HIW "ֻ��$n��������,�Լ�����������Ӱ������裬����������״��$N��ͷһ����һʱ�е���æ���ң�\n" NOR;
                result += "$n׽��ʱ�������̶�$N�������ƣ�\n" ;
                COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"));
                victim->add("jingli", random(-20));

                return ([ "msg" : result, "damage" : -damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = "$n����һ������һ�ߣ���Ȼ���׵رܿ���$N�Ĺ�����\n" ;

                return ([ "msg" : result, "damage" : -damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = "$n����һ������һ�ߣ�$Nֻ��������������ȫ�ޡ�\n";
      
                return ([ "msg" : result, "damage" : -damage ]);
        }
        else 
                return;
}

