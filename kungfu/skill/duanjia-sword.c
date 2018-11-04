// duanjia-sword.c �μҽ�

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 

mapping *action = ({
([      "action" : "$N�������˸�����������$wƽƽ�ݳ���һʽ"+(order[random(13)])+"�������Ͻ�"NOR"ֱ��$n��ǰ��",
        "force" : 150,
        "dodge" : 15,
        "damage" : 160,
        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ��$w��һ���벻���ĽǶ�ͻȻ������һʽ"+(order[random(13)])+"���̼�������"NOR"ֱ��$n������",
        "force" : 180,
        "dodge" : 15,
        "damage" : 185,
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"�������ڿա�"NOR"������Ծ�ڰ�գ�$w��������� ��ֱ��$n��ͷ��",
        "force" : 220,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 35,
        "damage_type" : "����"
]),
([      "action" : "$N����б�ӣ�����ָ��$n�ĸ�����һ��"+(order[random(13)])+"����Ԩ���ԡ�"NOR"�����¶��ϣ�����$n",
        "force" : 270,
        "dodge" : 15,
        "damage" : 170,
        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N˫����أ�б�ɶ�����$w����$n��$l,��һ��"+(order[random(13)])+"��Цָ���ϡ�"NOR"",
        "force" : 330,
        "dodge" : 15,
        "damage" : 190,
        "lvl" : 55,
        "damage_type" : "����"
]),
([      "action" : "$N��Хһ�����ὣ�������͸������֮�⣬���ǶμҲ���֮��"+(order[random(13)])+"����¹��ԭ��"NOR"��������ס$n��ȫ��",
        "force" : 380,
        "dodge" : 15,
        "damage" : 300,
        "lvl" : 65,
        "damage_type" : "����"

]),
([  "action" : "$N��ǰ����һ����һ��"+(order[random(13)])+"���ƺ����롹"NOR"������$w����������$n��$l
������ȥ",
    "force" : 150,
    "dodge" : 130,
    "damage" : 125,
    "lvl" : 0,
    "skill_name" : "�ƺ�����",
    "damage_type" : "����"
]),
([  "action" : "$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ"+(order[random(13)])+"������
ֱ�¡�"NOR"ֱ��$n��$l",
    "force" : 200,
    "dodge" : 115,
    "damage" : 140,
    "lvl" : 9,
    "skill_name" : "����ֱ��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"��ѩӿ���ء�"NOR"��$w�����������⣬���¶��Ϸ���$n��$l",
    "force" : 220,
    "dodge" : 115,
    "damage" : 165,
    "lvl" : 19,
    "skill_name" : "ѩӿ����",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"�����ͻ��"NOR"������$w���ƺ�ɨʵ��б��������$n��$l",
    "force" : 250,
    "dodge" : 110,
    "damage" : 85,
    "lvl" : 29,
    "skill_name" : "���ͻ��",
    "damage_type" : "����"
]),
([  "action" : "$Nʹ��"+(order[random(13)])+"��ҹ��̽����"NOR"��$w����������������಻�ϻ���$n��$l",
    "force" : 280,
    "dodge" : 115,
    "damage" : 100,
    "lvl" : 39,
    "skill_name" : "ҹ��̽��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"��̩ɽѹ����"NOR"������һ�󽣾�������$w���϶����������
��ֱ��$n��$l������ȥ",
    "force" : 300,
    "dodge" : 115,
    "damage" : 120,
    "lvl" : 89,
    "skill_name" : "̩ɽѹ��",
    "damage_type" : "����"
]),
([  "action" : "$Nһ��"+(order[random(13)])+"������滨��"NOR"�����ڰ�գ�$w�س飬���ֹ���$n��$l",
    "force" : 350,
    "dodge" : 110,
    "damage" : 140,
    "lvl" : 99,
    "skill_name" : "����滨",
    "damage_type" : "����"
]),
([  "action" : "$N��Ӱһ��, �Ƶ�$n����һ��"+(order[random(13)])+"����¹��ԭ��"NOR"��������$n��$l����",
    "force" : 400,
    "dodge" : 115,
    "damage" : 250,
    "lvl" : 100,
    "skill_name" : "��¹��ԭ",
    "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
       return notify_fail("�������������\n");
    if ((int)me->query_skill("kurong-changong", 1) < 20)
       return notify_fail("��Ŀ����������̫ǳ��\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("duanjia-sword",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "sword")
       return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
       return notify_fail("��������������μҽ���\n");
    me->receive_damage("qi", 20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"duanjia-sword/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N ����һ������ʩչ��һ��ָ�����Դ���ָ���鲼ȫ��! ��ɫ������ˡ�\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"��$N�Ĵ���ָ������! ��������� "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n��������̫��ȭ������������������\n",  
           message_vision(msg, me, ob);
           return j;
}      
}
