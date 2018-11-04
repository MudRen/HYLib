// duanyun-fu.c ���Ƹ�
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N����ڿ�Ծ��˫�ֽ���$w����׼$n��ͷ�������϶��µؿ�����ȥ��
ֻ�ڰ��������һ�ž޴�ĺ�Ӱ",
    "damage": 500,
    "force": 300,
    "dodge" : 50,
    "damage_type" : "����",
    "lvl" : 0,
    "skill_name" : "����ٵ�"
]),
([  "action" : "$NͻȻ��һ��������ǰ����������$w���¶��Ϸ���$n����·��$n����
һ������ɫ����Ӱ�����Լ�����֪�����æ�м�",
    "damage": 525,
    "force": 300,
    "dodge" : 45,
    "damage_type" : "����",
    "lvl" : 10,
    "skill_name" : "��������"
]),
([  "action" : "$N��Ȼ����һ��������б����ǰ�����һ��������΢�Σ�����$w�ڿ�
�л���һ����Ӱ�����ٺ�ɨ$n���Ҽ磬��������",
    "damage": 550,
    "force": 300,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl" : 20,
    "skill_name" : "��ɨǧ��"
]),
([  "action" : "$NͻȻ�������ҹ������漴���𣬾��������һ˲�䣬�ѵ�������$w
����$n�����ߣ����ּȿ��Һ�",
    "damage": 590,
    "force": 300,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl" : 30,
    "skill_name" : "����Ϊ��"
]),
([  "action" : "$N˫�ֺ��$w��ƽɨ$nǰ�أ���ʽδʹ�Ͼ��Ѵ�ס�Ȼ���У�����ֱ
ײ$n��С����",
    "damage": 530,
    "force": 300,    
    "dodge" : 40,
    "damage_type" : "����",
    "lvl" : 42,
    "skill_name" : "��ײ��"
]),
([  "action" : "$N����������ת��΢�ף�$n��$N¶����������æ������ȴͻȻ����$N
��������ת����������$w��Ѹ�͵�ɨ���Լ�������",
    "damage": 680,
    "force": 500,
    "dodge" : 130,
    "parry" : 54,
    "damage_type" : "����",
    "lvl" : 55,
    "skill_name" : "�ط�ת��"
]),
([  "action" : "$N����΢��������ͬһʱ�������������ҿ����師��$n�����$w�Ӳ�
ͬ�ķ�λ�����Լ���һʱ�侹��֪������м�",
    "damage": 580,
    "dodge" : 125,
    "force": 500,
    "parry" : 66,
    "damage_type" : "����",
    "lvl" : 68,
    "skill_name" : "�師����"
]),
([  "action" : "$Nǰ���͵�������һ�٣����Ҳ΢΢һ�𣬽��ž���ͷ��ͷ����ת
��Ȧ��$w����������֮��ƽֱ�����ȵ�Ϯ��$n��$n������δ����㣬
�ܿ����������Լ�����һ�ߣ����ɴ�ʧɫ",
    "damage": 680,
    "force": 500,
    "parry" : 155,
    "dodge" : 65,
    "damage_type" : "����",
    "lvl" : 80,
    "skill_name" : "һ������"
])
});

int valid_enable(string usage) { return usage=="axe" ||  usage=="parry"; }      

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("����ڹ��ķ���򲻹����޷�ѧ���Ƹ���\n");
    if ((int)me->query("max_neili") < 150)
   return notify_fail("�������̫�����޷������Ƹ���\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("�����ѩ����̫���ˡ�\n");
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
    int i, level;
    level = (int)me->query_skill("duanyun-fu", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "axe")
   return notify_fail("��ʹ�õ��������ԡ�\n");    if ((int)me->
query("qi") < 30)
    if ((int)me->query("qi") < 50)
    return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("����������������Ƹ���\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tiexue-hammer", 1)+100) < (int)me->query_skill("duanyun-fu", 1))
               return notify_fail("�����ѩ����̫���ˡ�\n");


    me->receive_damage("qi", 25);
return 1;
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N����һ������������һƬ��Ҷ���Ʈ��,$nͷһ�裬��֪����!\n"NOR;

victim->start_busy(3);

                return msg;
}
        weapon = me->query_temp("weapon");

level2= (int) me->query_skill("duanyun-fu",1);             
if (weapon)
{

        if (random(5)==1 && me->query_skill("duanyun-fu",1)>100
        && (string)weapon->query("skill_type") == "axe"
        && me->query_skill_mapped("force") == "guiyuan-tunafa")
        {
        if (!victim->is_busy())
        victim->start_busy(3);
        return HIR"$N�����,$n�޷�����Ҳ�޷�����!!\n"NOR;
        }
        if( damage_bonus > 30 && random(level2)>60
        && (string)weapon->query("skill_type") == "axe"
        && random(2)==0
        && me->query_skill_mapped("force") == "guiyuan-tunafa") {
        victim->receive_wound("qi", (random(damage_bonus)+150));
        return HIB"$n��������$lҪ����Ѫ����һ��!!\n"NOR;
        }
}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level,level2, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("duanyun-fu", 1);
level2 = me->query_skill("duanyun-fu", 1);
if (weapon)
{
        if (  level2 > 100
        && random(5)==1
        && (string)weapon->query("skill_type") == "axe"){
 
            msg = HIC"$n����ʱ��$N����󸫣�$n�޷�����Ҳ�޷�����!!\n"NOR;
   if (!ob->is_busy())
             ob->start_busy(3);
message_vision(msg, me, ob);
               }

}
}








string perform_action_file(string action)
{
    return __DIR__"duanyun-fu/" + action;
}

