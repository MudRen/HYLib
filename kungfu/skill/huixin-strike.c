//Edit By Vin On 13/2/2001

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([  "action": "$Nʹ��һ�С��ٻ����㡹��������ɣ�����ֱ��$n��$l",
    "force" : 220,
    "attack": 25,
    "dodge" : 10,
    "parry" : 16,
    "damage": 10,
    "lvl"   : 0,
    "skill_name" : "�ٻ�����" ,
    "damage_type" : "����"
]),
([  "action": "$Nʹ��һ�С���ľ�Կݡ���˫�Ƽ��������������������Ʒ�ֱ��$n��$l",
    "force" : 280,
    "attack": 55,
    "dodge" : 15,
    "parry" : 19,
    "damage": 25,
    "lvl"   : 30,
    "skill_name" : "��ľ�Կ�" ,
    "damage_type" : "����"
]),
([  "action": "$N����һԾ����һ���ֽУ�һ�С������ɢ����˫������ǵذ�����$n",
    "force" : 340,
    "attack": 67,
    "dodge" : 20,
    "parry" : 25,
    "damage": 35,
    "lvl"   : 60,
    "skill_name"  : "�����ɢ" ,
    "damage_type" : "����"
]),
([  "action": "$N��Ȼһ����Х��һ�С��ջ����ǡ���˫����Ȼ���£�ֱ��$n��Ҫ��",
    "force" : 440,
    "attack": 85,
    "dodge" : 20,
    "parry" : 38,
    "damage": 60,
    "lvl"   : 90,
    "skill_name" : "�ջ�����" ,
    "damage_type" : "����"
]),
([  "action": "$N���һ��������һ���죬˫�ۺ�Ȼ�������ߣ�һ�С�����׷�꡹ֱֱ����$n��$l",
    "force" : 470,
    "attack": 90,
    "dodge" : 40,
    "parry" : 43,
    "damage": 65,
    "lvl"   : 120,
    "skill_name" : "����׷��" ,
    "damage_type" : "����"
]),
([  "action": "$Nһ�С��ѹǴ��ġ���˫���ͷ��ĳ�������������Ӱ����Ȼ��һ����Ѹ���ޱȵ�����$n",
    "force" : 480,
    "attack": 126,
    "dodge" : 40,
    "parry" : 55,
    "damage": 80,
    "lvl"   : 150,
    "skill_name" : "�ѹǴ���" ,
    "damage_type" : "����"
]),
});

// string main_skill() { return "jiuyin-shengong"; }

int valid_enable(string usage) { return  usage == "strike" || usage == "unarmed" || usage == "parry"; }

int valid_combine(string combo) { return combo=="piaoxue-hand"; }

int valid_learn(object me)
{

        /*
        if ((int)me->query_skill("jiuyin-shengong", 1))
                return notify_fail("���ѽ������澭�ϵ��书ȫ���ڻ��ͨ�������ٷֿ�ѧϰ�ˡ�\n");
        */

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("�����Ҵ����Ʊ�����֡�\n");

        if ((int)me->query_skill("jinding-zhang", 1) < 100)
                return notify_fail("��Ľ����ƻ��̫ǳ��\n");
                
        if ((int)me->query_skill("tiangang-zhi", 1) < 100)
                return notify_fail("������ָѨ�����̫ǳ��\n");                

        if ((int)me->query_skill("force") < 100)
            return notify_fail("����ڹ�̫��޷���ϰ���Ҵ����ơ�\n");

        if ((int)me->query("max_neili") < 1200)
            return notify_fail("���������Ϊ̫ǳ���޷���ϰ���Ҵ����ơ�\n");

        if ((int)me->query_skill("unarmed", 1) < 100)
                return notify_fail("��Ļ���ȭ�����ޣ��޷������Ҵ����Ƶ�Ҫ�衣\n");



        if ((int)me->query_skill("strike", 1) < 100)
            return notify_fail("��Ļ����Ʒ�̫��޷������Ҵ����ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("huixin-strike", 1))
            return notify_fail("��Ļ����Ʒ���򲻹����޷���������Ķ��Ҵ����ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action); i > 0; i--)
                if (level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("huixin-strike",1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 5, level/5)];
}

int practice_skill(object me)
{
        /*
        if ((int)me->query_skill("jiuyin-shengong", 1))
                return notify_fail("���ѽ������澭�ϵ��书ȫ���ڻ��ͨ�������ٷֿ���ϰ�ˡ�\n");
        */

        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 350)
                return notify_fail("�������������\n");

        me->receive_damage("qi", 80);
        me->add("neili", -300);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("huixin-strike", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") && random(3)==0)
{
            victim->apply_condition("cuixin_zhang",5+(int)random(lvl/10));
        		victim->receive_damage("qi", random(lvl/3)+1);
        victim->start_busy(3);
        {
                return HIR "ֻ��$n" HIR "�ƺ���һ�����������ܵ��˶��Ҵ������ƾ��ĸ��ţ�\n" NOR;
        }
}
}

string perform_action_file(string action)
{
        return __DIR__"huixin-strike/" + action;
}


int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N �������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!��\n"NOR;
msg += "$N��ɫһ��,�ָ���Щ������\n",  
           message_vision(msg, me, ob);
           return j;
} 
}