//Cracked by Kafei
//tianluo-diwang.c ���޵����� by maco 1999/1/17

#include <combat.h>
#include <ansi.h>
inherit SKILL;

int ke_qz(object me, object victim, object weapon, int damage);

mapping *dodge_action = ({
([      "action" : "$n��֫��ڣ�����һ��ջ��ڷ���΢΢һ����б���Ʋ������ѱܿ���\n",
        "dodge"  : 10
]),
([      "action" : "$nչ���Ṧ�����������缲���ӵأ�����������˲Ϣ֮��������Σ������Բ֮����Ų��Ծ����$N�޴ӽ��У�\n",
        "dodge"  : 20
]),
([      "action" : "$n˳��$N���Ʊܹ�������һ�ϣ���Ȼ��$N���һ�Ӷ������������񣬲���΢�죬�����ÿ���\n",
        "dodge"  : 30
]),
([      "action" : "$n�Ų���ӯ������Ѹ�ݣ��Ṧʩչ��Բת���⣬��֮�죬���Ѱ������ز��Ų���������ɵرܹ�$N��һ�С�\n",
        "dodge"  : 40
]),
([      "action" : "ȴ��$n�������磬����΢��������ƮƮ�����ǻ������У���������ر��˿�ȥ������Ʈ�����ף��仯�򷽣�\n",
        "dodge"  : 50
]),
([      "action" : "$nչ����Ĺ���Ṧ��������ȥ��б�ܼ�ת���ݺ�Ʈ������$N����ȷ�����ֵķ�λ��\n",
        "dodge"  : 60
]),
([      "action" : "$n�½󵱷磬ƮƮȻ�����˷��ȥ��Խ��Խ����ݣ�������ȥ������ȫ��������$N������������׽����\n",
        "dodge"  : 70
]),
([      "action" : "$n˫��һ�ǣ������ڿն����������Ӵ���һ�㣬��س���ƽƽ�ӹ�������֮�£�$N�������ƺ�������һ����\n",
        "dodge"  : 80
]),
([      "action" : "$nչ����Ĺ���Ṧ���������ߣ�һ��ţ�������磬$N��Ȼ���治�ϣ����°������壡\n",
        "dodge"  : 90
]),
([      "action" : "$n������ǰһͦ����Ҳ�ƵĻ��˿�ȥ������$n������������ת���ۣ�ʵ��˲Ϣ֮��ͣ����$N�������ʽһһ��գ�\n",
        "dodge"  : 100
]),
});

mapping *action = ({
([      "action" :"$N������죬��һ��һʽ������������Գɶ��䣬��������΢����������$n$l����",
        "force" : 160,
        "dodge" : 0, 
        "parry" : 10, 
        "damage": 215,
        "damage_type" : "����"
]),
([      "action" :"$N�����ַ������������ᣬ�Ʒ���$n�����޾�չ�˿�������ö�ˣ�����Ī��",
        "force" : 220,
        "dodge" : 10, 
        "parry" : 5, 
        "damage": 220,
        "damage_type" : "����"
]),
([      "action" :"$N˫�ֻӳ�������һ�գ�����һ�ģ���$n������ȥ·ȫ����ס��˫����ߵ����Ǳ��ģ�$n���������ѳ���Ӱ��������֮��",
        "force" : 260,
        "dodge" : 25, 
        "parry" : 5, 
        "damage": 225,
        "damage_type" : "����"
]),
([      "action" :"$N˫�۷��裬��ֻ�������ƻ�����ǧ��ǧ�ƣ���$n�����Ų���Σ�ʼ�ձ�����$N����Χ�ɵ�Ȧ����",
        "force" : 280,
        "dodge" : 20, 
        "parry" : 15, 
        "damage": 230,
        "damage_type" : "����",
]),

([      "action" :"$N˫��һ����ƾ���ȥ����·�����޵����ơ����Ʒ�ʹ�������������ޱȣ������䲻���ۣ����ַ�Ѹ��������һ�С�����һ�ƣ�Ʈ���鶯֮��",
        "force" : 320,
        "dodge" : 20, 
        "parry" : 15, 
        "damage": 230,
        "damage_type" : "����",
]),
([      "action" :"$N���ֿ���ޱȣ�������֮�����Ǳ���޷���ץ��˺�������ù�������С�������м��ԡ����޵����ơ����Ʒ�����������",
        "force" : 350,
        "dodge" : 15, 
        "parry" : 5, 
        "damage": 235,

        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="dodge";}

int valid_combine(string combo) { return combo=="meinv-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����޵����Ʊ�����֡�\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 20)
          return notify_fail("�����Ů�ľ���򲻹����޷�ѧ���޵����ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tianluo-diwang",1);
        return action[random(sizeof(action))];
}

mapping query_dodge_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(dodge_action);
        level   = (int) me->query_skill("tianluo-diwang");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return dodge_action[random(zhaoshu)];
}

int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˡ�\n");
        me->receive_damage("jing", 25);
        me->add("neili", -10);
       
       return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_dodge_action(me, ob);

        return action["action"];
}


string perform_action_file(string action)
{
       return __DIR__"tianluo-diwang/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"�������ߣ��ж����������಻����һ��δ�ϣ������� !$n˫��һ����֪���룡\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"Ŀ��һ����һ��������ӳ� !$n һ�����ģ����������˼�ö��\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      
