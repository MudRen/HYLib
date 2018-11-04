// taixuan-gong.c ���͵�̫����
// Jay 4/5/96
// modified by Venus Oct.1997
//2000/6/10�� ��lywin�����������������Զ�pfm

#include <ansi.h>
//inherit FORCE;
inherit SKILL;

string *dodge_msg = ({
    "$n�����ĳ������絽������$N��һ�ߡ�\n",
    "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
    "$n������ţ���Ծ��������������ʮ�����⡣\n",
    "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});
mapping *actionw = ({
([      "action" : "$N������磬���ƷǷ���$w�������֣�׽��������$n������ȥ",
        "force" : 510,
        "attack": 180,
        "dodge" : 85,
        "parry" : 175,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$N���е�$w�������������糤��������������$n����",
        "force" : 510,
        "attack": 108,
        "dodge" : 72,
        "parry" : 115,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w�����緭������ֱ����$n��ȥ",
        "force" : 532,
        "attack": 125,
        "dodge" : 60,
        "parry" : 102,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N����$w�ó�һ�����⻷����ʱ��$n���Ű�Χ",
        "force" : 565,
        "attack": 110,
        "dodge" : 75,
        "parry" : 105,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N�����������$w����������ؾ���$n",
        "force" : 550,
        "attack": 108,
        "dodge" : 70,
        "parry" : 120,
        "damage": 420,
        "damage_type": "����"
]),
});

mapping *action = ({
([      "action":"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���",
        "force" : 540,
        "attack": 50,
        "dodge" : 50,
        "parry" : 120,
        "damage": 355,
        "damage_type":  "����"
]),
([      "action":"$N�����������ʱһ�������������Ϯ��$n",    
        "force" : 560,
        "attack": 60,
        "dodge" : 60,
        "parry" : 90,
        "damage": 330,
        "damage_type":  "����"
]),
([      "action":"$N���һ��������һ������ʱһ��������$n����ӿȥ",
        "force" : 570,
        "attack": 75,
        "dodge" : 75,
        "parry" : 135,
        "damage": 360,
        "damage_type":  "����"
]),
([      "action":"$N�����ϣ�ȫ������������˫���͵�����$n",
        "force" : 580,
        "attack": 80,
        "dodge" : 80,
        "parry" : 75,
        "damage": 395,
        "damage_type":  "����"
]),
([      "action":"$N�����죬������֣�ͻȻ��$N˫�������ĳ�������̫���ھ�������$n",
        "force" : 580,
        "attack": 95,
        "dodge" : 90,
        "parry" : 125,
        "damage": 360,
        "damage_type":  "����"
]),
([      "action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
        "force" : 580,
        "attack": 100,
        "dodge" : 100,
        "parry" : 145,
        "damage": 580,
        "damage_type":  "����"
]),
});

int valid_enable(string usage)
{
      return usage == "unarmed" || usage == "hand" || usage == "dodge" ||usage == "parry" || usage == "force";
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("taixuan-gong",1)) > 300 && me->query("neili") > 100)
	{
		me->add("neili", -50);
		return ([
	"action": HIR "$N������ͻȻһƬãȻ��ֻ���þ�������������������ڴ�����ȥ���ѹ��ǳ���
���²������룬˳����������һ��ȭ����ߣ����ܶ�ʱ������쩣��ò����֣�"NOR,
	"damage": 1000,
	"dodge" : 100,
	"force" : 500,
	"damage_type": "����"]);
	}
	return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return notify_fail("̫�����޷�ͨ����ϰ���ɳ���\n");
}

int valid_learn(object me)
{
	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	||  me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ̫���񹦣���\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");

        if (me->query("gender") == "����")
                return notify_fail("���޸����ԣ����������������������̫������\n");

        if ((int)me->query("int") < 30)
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if ((int)me->query("dex") < 30)
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

    if (random(this_player()->query("int")) > 25)
        return 1;
    return notify_fail("���˼���ã�����һͷ��ˮ���������ã���\n");

}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"taixuan-gong/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        string result;
        int ap, dp, mp;
        ap = (int)me->query("combat_exp");
        dp = (int)ob->query("combat_exp");
j=damage;
if (me->query_skill_mapped("force") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return damage;
if (me->query_skill_mapped("parry") != "taixuan-gong")
return damage;
        if ((int)me->query_skill("literate", 1)> 5 )	
return damage;

if (me->query("neili") < 500)
return damage;
 if (objectp(weapon = me->query_temp("weapon"))
        )
return damage;

             
  if (random(ap) < dp/2  
  && random(2)==0)
        {

                switch (random(2))
                {
                case 0:
                        result =  HIR "$n" HIR "Ĭ��̫�����ھ���̫����"
                                            "�������ȫ��$N" HIR "ֻ�����й���"
                                            "$n" HIR "����\n����������ͭǽ����һ�㣬"
                                            "˿���������á�\n"NOR;
                        break;
                case 1:
                        result =  HIR "$N" HIR "һ�л���$n" HIR "����"
                                            "����ȴ�������ͭǽ������һ��\n��������ʱ"
                                            "��ʧ����Ӱ���١�\n" NOR;
                        break;
                default:
                        result =  HIR "����$n" HIR "һ����Х����������"
                                            "�Ľ�����$N" HIR "��һ�У�\nȴû���ܵ�"
                                            "����˺���\n" NOR;
                        break;
                }
message_vision(result,ob,me);
                                    if (!ob->is_busy()) ob->start_busy(3);
if ((int)me->query("qi") < (int)me->query("eff_qi")*2)
me->add("qi",damage/5+200);
if ((int)me->query("eff_qi") < (int)me->query("max_qi")*2)
me->add("eff_qi",damage/5+200);
            damage=100;
            j=100;
            return j;

        }

}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;
if (me->query_skill_mapped("parry") != "taixuan-gong")
return 0;
        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                   "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                   HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                   "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
}
}