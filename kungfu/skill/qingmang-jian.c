// qingmang-jian.c ������(��)��
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
string *dodge_msg = ({
"�ƺ�$Nÿһ�ж�����$n������������$n���ǻ򷴴򡢻����ܣ�һһ��⿪ȥ��\n",
"ȴ��$nһ��ͷ����$N����������ȥ��������Ƹ���$n���ұۡ�\n",
"��֪$n����һ�ϣ��������ɵرܹ���$N�Ĺ�����\n",
"$n�������㣬����$N����һ�С�Ҷ�׷��ࡹ����Ϊ�ء�\n"
});

string  *msg = ({
"$Nˢˢˢ�������У�ʹ�����������š�������$w������������������һ�㣬��֪Ҫ����δ�",
"$N�������ˣ�����һ�У�$wֱ��$n���ţ��Ƶ�$n��æ��ͷ����",
"$N�������$nС����һɨ���뽫$n�赹������$wһ������ָס$n�ʺ�",
"$Nһ����Ц������$wӭ�濳�£�ֱ��$n$l",
"$Nһ�³嵽$n��ǰ��ͻȻ֮��γ�$w������$nͷ�Ͽ�����ȥ",
"$NͻȻһ�°�$w�ӻ�������ͻ���������ж����ǿ켫��$nȫ�����ܵ���ԣ",
"$N$wͦ����һ�С����߳���������$n������ȥ���Ƶ����Ǿ���",
"$N���������ã���$wȦת������$n$l",
"$Nһ�С��������š���$w�����ޱȵ���$n��$l"
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry" 
            || usage == "dodge" || usage == "blade" 
            || usage == "axe" || usage == "dagger"
            || usage == "hook";
}

mapping query_action(object me, object weapon)
{
        int i, level;
        object target;

        level   = (int) me->query_skill("qingmang-jian",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");
    if (!userp(me) || (int)me->query_skill("qingmang-jian", 1) > 10)
{
	if( random(8)==1 && random(level) > 260)
	{
		return ([
		"action": HIR"�� ˲��ɱ! ��"+HIM"$Nʹ�������ٵ����ؼ��콣�ε�������$nδ��ʹ��ǰ����������!"NOR,
		"force" : 850+random(200),
		"dodge" : 250,
		"damage": 850+random(200),
	        "skill_name" : "˲��ɱ!",
		"damage_type" : "����" ]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIR"���������!��"+HIY"$N�������������ɵ���������ȼ��,��������������,��ȫ�ٻٶ���!!"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "�����",
		"damage_type": random(2)?"����":"����"]);
	}
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIB"��������!��"+HIY"$N��ץס����ʱ,���������������ڲصĻ�ҩ"NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}

         if( random(8)==1 && random(level) > 150)
	{
		return ([

		"action" : HIM"���ؽ�.����!��"+HIY"$N�������е��,�����ͬʱ����ն���ͻ��գ� "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
 
 	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIG"��Ӱ���Ź���!��"+HIY"$N����֮һ���������Լ�,ʹ�Լ����ű��������޵�,��������Ǳ��,������ǿ������ "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "Ӱ���Ź���",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 150)
	{
		return ([
		"action" : HIC"��������!��"+HIY"$N�����ֵĵ��ڱ��󽻸�����,���üٶ�������Ԥ�ϲ����ĵط����� �� "NOR,
        	"force" : 850,
        	"dodge" : 150,
        	"damage": 850,
        	"skill_name" : "������",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 250)
	{
		return ([
		"action" : HIW"��������ƽ��!��"+HIY"$N��[һ,��,ʮ]���������[ƽ]�ֽ��������,����ķ�$n,����$n�޷������� "NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "������ƽ��",
		"damage_type": random(2)?"����":"����"]);
	}
  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIC"�����콣������!��"+HIW"$N����С̫��,������ˮ��ʽ�̳�,�����ٱ�����,˲������С� "NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "���콣������",
		"damage_type": random(2)?"����":"����"]);
	}

  	if( random(8)==1 && random(level) > 200)
	{
		return ([
		"action" : HIG"������˫��!��"+HIW"$N˫���ݺ�ʮ�� ����С̫��ʮ�ֽ������������ƵĹ���$n ��"NOR,
		"force" : 650,
        	"dodge" : 150,
        	"damage": 650,
        	"skill_name" : "����˫��!",
		"damage_type": random(2)?"����":"����"]);
	}
}

        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(6)+3)*80,
                "damage_type":random(2)?"����":"����",
                "dodge":random(80),
                "force":300+random(600)
        ]);
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
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
        level = (int) me->query_skill("blade",1);
	jiali = me->query("jiali");
if (userp(me)) return;
if (!me) return;
if (!victim) return;
if (!weapon) return;
if (!jiali) jiali=10;
	if( damage_bonus > 30 && random(level2)>80 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"ֻ��$n$l����Ѫ�񱼣��ѱ�"+weapon->name()+HIR"ն���������������˿���!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("qingmang-jian", 1);


        if( damage < 60 ) return 1;
    if (userp(me)) return 1;


        if (  random(level) > 150
         && me->query_skill_mapped("parry") =="qingmang-jian"
         && weapon
           ){
         msg = HIG"$N���$n�Ĺ��ơ�����һ����ͻ������!!!��\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"�� ˲��ɱ! ����$Nʹ�������ٵ����ؼ��콣�ε�������$nδ��ʹ��ǰ����������!!��\n"NOR;
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
         msg = HIR"���������!����$N�������������ɵ���������ȼ��,��������������,��ȫ�ٻ�$n!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
msg += damage_msg(damage, "����");
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
msg += damage_msg(damage, "����");
}
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"�����콣������!����$N����С̫��,������ˮ��ʽ�̳�,�����ٱ�����,˲�������!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
msg += damage_msg(damage, "����");
}
else
{
ob->add("qi",-3000);
ob->add("qi",-3000);
msg += damage_msg(damage, "����");
}
            }
else
           msg = HIG"$n�ϵ���������,���˿�������������!��\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
