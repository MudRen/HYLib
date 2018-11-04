// chousui-duzhang.c  ������, based on xianglong-zhang.c
// modified by Venus Oct.1997
// by yucao

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": ""+(order[random(13)])+"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l"NOR"",
    "dodge": 30,
    "force": 160,
    "damage": 200,
//      "poison": 80,
    "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l"NOR"",
    "dodge": 100,
    "force": 160,
    "damage": 200,
//      "poison": 60,
    "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l"NOR"",
    "dodge": 200,
    "force": 150,
    "damage": 200,
//      "poison": 100,
    "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$N˫��Ю��һ���ȳ�֮������$n��$l"NOR"",
    "dodge": 100,
    "force": 160,
    "damage": 200,
//      "poison": 80
    "damage_type": "����"
]),
([      "action": ""+(order[random(13)])+"$N�߶�����������Ӷ���˫��Ю��һ���ȳ�֮��һǰһ������$n��$l"NOR"",
        "dodge": 115,
        "force": 130,
        "damage" : 200,
        "lvl" : 0,
        "damage_type": "����"
]),

([      "action": ""+(order[random(13)])+"$N˫��һ��һ�䣬������ת����, ͻȻ��˫�Ʒ���������$n��$l"NOR"",
        "dodge": 115,
        "force": 140,
        "damage" : 200,
        "lvl" : 0,
        "damage_type": "����"
]),

([      "action": ""+(order[random(13)])+"$N����Ʈ����Χ��$nһȦȦ���ߣ�ͬʱ˫�����ģ��������󾢷紵��$n"NOR"",
        "dodge": 225,
        "force": 170,
        "damage" : 200,
        "lvl" : 30,
        "damage_type": "����"
]),

([      "action": ""+(order[random(13)])+"$NͻȻ������ȣ�Ծ�ڰ�գ������縫������������$n������������"NOR"",
        "weapon" : "�Ʒ�",
        "dodge": 210,
        "force": 320,
        "damage" : 220,
        "lvl" : 50,
        "damage_type": "����"
]),

([      "action": ""+(order[random(13)])+"$N����΢����ǰһ��������ʮ�ɹ��������һ�����뷢��ţ�����һ������$n��ȥ"NOR"",
        "dodge": 222,
        "force": 260,
        "damage" : 300,
        "lvl" : 70,
        "damage_type": "����"
]),

([      "action": ""+(order[random(13)])+"$N��¶�����Ц�ݣ��͵���ǰ�������׼$n��$l����һ�������ޱȵġ������ơ�"NOR"",
        "dodge": 22,
        "force": 220,
        "damage" : 310,
        "lvl" : 95,
        "damage_type": "����"
]),

([      "action": ""+(order[random(13)])+"$N����һת������������һ�С��������צ�������������������ץ��$n��$l"NOR"",
        "weapon" : "��צ",
        "damage" : 330,
        "dodge": 10,
        "force": 290,
        "lvl" : 120,
        "damage_type": "ץ��"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry"; }   

int valid_combine(string combo) { return combo=="sanyin-wugongzhao"; }


mapping query_action(object me)
{
        if (present("huo yan", environment(me))){
        if (random(me->query_skill("chousui-zhang")) > 280 &&
            me->query("neili") > 1000 ) {
                me->add("neili", -100);
                return ([
        "action":BLU"$N��ɫ�ҵ������ִ򿪷��٣������´����������ϣ�������ҧ��⣬"+HIR+"һ����"
                    "Ѫ���������ȥ��\n�ǻ������һ����"+HIW+"�漴��Ϊ������$N�͵����Ӽ���������"
                    "�ݰ���ת��ʮ���Ȧ�ӣ�"+HIR+"�����������������Ѷ��ز��𣬱���һ����ǽ����$nѹ��ȥ"NOR,
                "force": 800,
                "dodge": 50,
                "weapon": "����",
                "damage": 650,
                "damage_type": "����"]);
        }
        if (random(me->query_skill("chousui-zhang")) > 250 &&
            me->query("neili") > 800 ) {
                me->add("neili", -75);
                return ([
        "action":HIG"$N������ȣ�������ʢ���̻�ͻȻ����һ��"+HIR+"����Ļ�����$n���������ʹ�����ͣ�ȥ����죬"+HIG+"ֻ��һ���̵Ļ����ڿ��й�µµ��Ѹ��ת��"NOR,
                "force": 600,
                "dodge": 25,
                "weapon": "����",
                "damage": 550,
                "damage_type": "����"]);
        }
        if (random(me->query_skill("chousui-zhang")) > 200 &&
            me->query("neili") > 600 ) {
                me->add("neili", -50);
                return ([
        "action":HIR"$N����һ����һ�ɾ���ֱ�������֮�У�"+HIG+"�������ֳַ�һ��ϸϸ���̻𣬱���һ��ˮ�߰㣬"
                 +HIW+"$N����Ӷ������ɾ����Ϯ$n����"NOR,
                "force": 500,
                "dodge": 10,
                "weapon": HIG"�̻�"NOR,
                "damage": 500,
                "damage_type": "����"]); 
        }
        if (random(me->query_skill("chousui-zhang")) > 180 &&
            me->query("neili") > 500 ) {
                me->add("neili", -20);
                return ([
        "action":HIR"$N�漴����б�ĳ�һ��"+HIG+"�̻�"+HIR+"��$n��ȥ���������ڣ�"+HIG+"����һ����ɫ���ߺ��Կռʣ�����ڶ���"
                    +HIR+"��ɫ�������ޣ�"+BLU+"���ǹ��죬��â��˸����"+HIG+"��ӳ��$nͷ���Ա�"NOR,
                "force": 480,
                "dodge": 20,
                "weapon": HIG"�̻�"NOR,
                "damage": 400,
                "damage_type": "����"]); 
        }
         if (random(me->query_skill("chousui-zhang")) > 150 &&
            me->query("neili") > 400 ) {
                me->add("neili", -10);
                return ([
        "action":HIR"$NͻȻ��˫ü����һ��������ʳָ�����㣬������������������죬"+HIG+"��������𻨣���������һ�㣬"
                    "��$N���������£��ִ�����Ϯ��$n������Ѹ��֮��"NOR,
                "force": 450,
                "dodge": 10,
                "damage": 400,
                "weapon": "��",
                "damage_type": "����"]);
        }
    }
    if (random(me->query_skill("unarmed",1)) > 220 &&
        me->query_skill("force",1) > 200 &&
        me->query("neili") > 220 ) {
             me->add("neili", -50);
             return ([
                  "action": ""+(order[random(13)])+"$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n"NOR"",
                  "force": 500,
                  "damage": 500,
                  "damage_type": "����"]);
    }
    return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail("�������Ʊ�����֡�\n");
    if ((int)me->query_skill("huagong-dafa", 1) < 10)
       return notify_fail("��Ļ����󷨻�򲻹����޷��������ơ�\n");
    if ((int)me->query("max_neili") < 60)
       return notify_fail("�������̫�����޷��������ơ�");
    return 1;
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 8)
        return notify_fail("������������������ơ�\n");
    if (me->query_skill("chousui-zhang", 1) < 50)
        me->receive_damage("qi", 20);
    else
        me->receive_damage("qi", 30);
         me->add("neili", -5);
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("chousui-zhang", 1);
        flvl = me->query("jiali");
        if (lvl < 100 || ! damage_bonus ||
            me->query_skill_mapped("force") != "huagong-dafa" ||
            me->query("neili") < 300)
                return;
        if (random(5)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-600);
                return HIY "$n" HIY "�е�������ѩ���ڻ�һ������ʧ�ˡ���\n" NOR;
        }
else
        if (random(5)==0)
        {
if (victim->query("qi") > 500)
victim->add("qi",-250);
victim->add("eff_qi",-(50+random(200)));
victim->apply_condition("xx_poison",20);
victim->apply_condition("x2_sandu",20);
victim->apply_condition("sanpoison",20);
victim->apply_condition("sanxiao_poison",3);
                return HIY "$n" HIY "�е��������Ƹ���һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ������\n" NOR;
        }
}
string perform_action_file(string action)
{
    return __DIR__"chousui-zhang/" + action;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("huagong-dafa",1);
        level2= (int) me->query_skill("huagong-dafa",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/7;
if (damage2>= 5000) damage2 = 5000;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "huagong-dafa")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIY"$Nʹ��������,$n��������ѩ���ڻ�һ������ʧ�ˡ���\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}