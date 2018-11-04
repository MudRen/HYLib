// jiuyang-shengong.c ������
// cleansword
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
int valid_enable(string usage)
{ 
        object me = this_player();
        int lvl;
        lvl = (int)this_player()->query_skill("jiuyang-shengong", 1);

        if (lvl >= 280 && me->query("jiuyangok"))    
                return usage == "force" || usage == "unarmed" || usage =="parry"
                    || usage == "sword" || usage =="blade";
        else
                return usage == "force";
       
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang-shengong", 1);

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����񹦡�\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
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
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
	return 1;
}

mapping *actionf = ({
([      "action": "$N����һԾ��������Ȼ�ӿ죬����$n$l���ٹ�����ʮȭ",
        "force" : 510,
        "attack": 190,
        "dodge" : 100,
        "parry" : 90,
        "damage": 280,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N����������һȭ����$n��ɲ�Ǽ䣬$Nȫ�����ֳ�һ�����",
        "force" : 510,
        "attack": 185,
        "dodge" : 90,
        "parry" : 120,
        "damage": 275,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N���������˾��ڱۣ�һ�������ն����������һ�����ȵĻ�â",
        "force" : 530,
        "attack": 175,
        "dodge" : 90,
        "parry" : 110,
        "damage": 200,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N�粽��ǰ������΢΢һչ��˫�ƶ�׼$n$lһ������",
        "force" : 525,
        "attack": 185,
        "dodge" : 85,
        "parry" : 115,
        "damage": 285,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N���߾������ھ����͵�һȭ�ں�Х���ж�Ȼ�ӻ�����",
        "force" : 530,
        "attack": 165,
        "dodge" : 90,
        "parry" : 115,
        "damage": 300,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$Nһ�����ȣ�ʮָĺ���ſ���һ���ۺ���ھ����ȶ���",
        "force" : 540,
        "attack": 200,
        "dodge" : 115,
        "parry" : 120,
        "damage": 280,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action" : "$N���ƺ��������裬$w�仯�޳���׽��������$n������ȥ",
        "force" : 330,
        "attack": 140,
        "dodge" : 35,
        "parry" : 85,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$N���е�$wͻ������ɭ�ϣ�����ǧ�������۶�����$w����һ����â����$n",
        "force" : 310,
        "attack": 120,
        "dodge" : 25,
        "parry" : 25,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w����ʱ��â���ǣ����罾���һ�ֱ����$n��ȥ",
        "force" : 340,
        "attack": 115,
        "dodge" : 20,
        "parry" : 25,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N����$w�û���һ��һ��ԲȦ����ʱ������Ȧ��$n���Ű�Χ",
        "force" : 285,
        "attack": 110,
        "dodge" : 25,
        "parry" : 25,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N��ת$wңָ$n����ʱ$w���˶�ʱ͸��һ�����²����Ļ�⣬�������",
        "force" : 330,
        "attack": 118,
        "dodge" : 10,
        "parry" : 20,
        "damage": 420,
        "damage_type": "����"
]),
});
mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}

mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	ap = (int)me->query("combat_exp",1)+(int)victim->query_skill("parry",1);

        dp = victim->query("combat_exp",1);
        if (objectp(weapon1))
                dp += victim->query_skill("dodge");
if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("neili") < me->query("max_neili")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(HIR"$N��������񹦣�ȫ������ԴԴ���ϵ�ӿ��!\n"NOR,me, victim);
me->add("neili",random(me->query_skill("jiuyang-shengong",1))+100);
}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("qi") < me->query("max_qi")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)
{
message_vision(RED"$N��������񹦣����ϵ��˺��˺ܶ�!\n"NOR,me, victim);
me->add("qi",random(me->query_skill("jiuyang-shengong",1))+180);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",random(me->query_skill("jiuyang-shengong",1))+180);
}


if (random(me->query_skill("qiankun-danuoyi",1)) > 120
&& me->is_busy()
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0
)
{
message_vision(HIC"$N����Ǭ����Ų�ƣ�����æ�ҵĶ�����������!\n"NOR,me, victim);
me->start_busy(1);
}
        if ( random(ap) > dp/3 
        && me->query("jiuyangok")
        && (int)me->query_temp("shield")
        && me->query_skill_mapped("force") == "jiuyang-shengong"
        ) {
                if ( objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
				damage_bonus=-damage/3;
                                result = HIM"$n����һ�࣬��$N�����ϵ�����жȥ��롣\n"NOR;
                        }
                        else {
				result = MAG"$n����һ�࣬��$N�����ϵ�����жȥ��롣\n"NOR;
				damage_bonus=-damage/3;
			}
                }
                else if(!objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
				damage_bonus=-damage/2;
			        result = HIG"$n��������Ȼ��Ȼ������������$N������һ����\n"NOR;                      
			}
                	else {
				result = MAG"$n��������Ȼ��Ȼ������������$N������һ����\n"NOR;
				damage_bonus=-damage/2;
			}
		}	

	}
if (result)
        message_vision(result,me,victim);
        return damage;
}



string perform_action_file(string action)
{
        return __DIR__"jiuyang-shengong/perform/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("jiuyang-shengong", 1);

        if (damage_bonus < 50
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
		|| !me->query("jiuyangok") )
		return 0;

        if (damage_bonus / 5 > victim->query_con() || random(10)==0)
        {
	        me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 80) / 2+10, me);
                return random(2) ? HIR "ֻ��$N" HIR "�����ھ������ڱŷ�����������ʽ"
                                   "���������ݻ���$n" HIR "����Ԫ��\n" NOR:

                                   HIR "$N" HIR "�����񹦵�Ǳ�������˳�����ͻȻ��$n"
                                   HIR "ֻ�к���һ�����һ����Ѫ��\n" NOR;
        }
}