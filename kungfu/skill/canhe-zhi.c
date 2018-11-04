// canhe-zhi.c �κ�ָ
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
//inherit F_SSERVER;
inherit SKILL;
string *xue_name = ({ 
        "�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
        "����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",
});

string *xue2_name = ({
        MAG "$NĬ����Ԫ�񹦣�������������ָ��ƽƽ�������޻��εص���$n������Ѩ" NOR,
        YEL "$N�������ϣ�����΢�飬������֮���ţ�����˫��ʳָ����һ��������ָ��ͬʱϮ��$n" NOR,
        WHT "$N��������ָ������ָ��ϳ�һ�ɽ�����ֱ��$n��ȥ"NOR,
        RED "$N�������֣���ָ���ǻ��ţ��ٻ���£ָ��ȭ����ʱ��������������Ľ�������" NOR,
        HIR "$Nָ��Ϭ������һ�����ν�������$n�������ڣ�$nֻ���ؿ�һʹ��ȫ��������к����" NOR
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



mapping *action = ({
([      "action" : "$N���缤����˫ָ������ã�һ��"+(order[random(13)])+"��Ŀ��ʶ����"NOR"�׺ݵ���$n��$l��ȥ",
        "force" : 100,
        "dodge" : 15,
        "damage": 209,
		"lvl" : 0,
		"weapon" : "ָ��",
        "skill_name" : "Ŀ��ʶ��",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����ʮָ���·ַɣ�һ��"+(order[random(13)])+"�������㾦��"NOR"��˫ֱָȡ$n��$l",
        "force" : 130,
        "dodge" : 18,
		"damage": 315,
		"weapon" : "ָ��",
        "lvl" : 20,
        "skill_name" : "�����㾦",
        "damage_type" : "����"
]),
([      "action" : "$Nʮָ���������ʵ��һ��"+(order[random(13)])+"����˷���롹"NOR"��ǰ�����ң�˲Ϣ����$n����������",
        "force" : 170,
        "dodge" : 15,
		"damage": 320,
		"weapon" : "ָ��",
        "lvl" : 40,
        "skill_name" : "��˷����",
        "damage_type" : "����",
]),
([      "action" : "$N�����ڿն���һ��"+(order[random(13)])+"���ܳ�������"NOR"��������죬��$n��$l�Ͳ���ȥ",
        "force" : 200,
        "dodge" : 10,
        "damage": 325,
		"weapon" : "ָ��",
		"lvl" : 60,
        "skill_name" : "�ܳ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�������������ߵ�$n��ǰ��һ��"+(order[random(13)])+"�����ϲ�����"NOR"������$n��$l",
        "force" : 220,
        "dodge" : 15,
		"damage": 330,
		"weapon" : "ָ��",
        "lvl" : 70,
        "skill_name" : "���ϲ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"���˱����᡹"NOR"������һȭ���������ƻ�ָ��һ��һָ��ջ���$n��$l",
        "force" : 200,
        "dodge" : 20,
        "damage": 230,
        "lvl" : 80,
        "skill_name" : "�˱�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ�ָ��ָ�д��ƣ�˫�����ƣ�һ��"+(order[random(13)])+"����н������"NOR"��һ����ɽ������������ֱ��$n$l",
        "force" : 260,
        "dodge" : 25,
        "damage": 130,
        "lvl" : 90,
        "skill_name" : "��н����",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ���м�ת��һ��"+(order[random(13)])+"�����μ���"NOR"��ʮָ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 220,
        "dodge" : 25,
        "damage": 330,
        "lvl" : 100,
        "skill_name" : "���μ�",
        "damage_type" : "����"
]),
([      "action": "$N˫ָ��£���������ϡ�"NOR + MAG "���÷�ָ" NOR "����"
                  "��" NOR + MAG "����ָ" NOR "��Ϊһʽ����ʱһ���ֱ��$n",
        "force" : 280,
        "attack": 50,
        "parry" : 50,
        "dodge" : 55,
        "lvl" : 200,
        "damage": 160,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      "action": "$N˫ָ���������ϡ�" HIG "����ָ" NOR "������" HIG "����Ҷ"
                  "ָ" NOR "��Ϊһʽ����ʱ����������$nȫ�����",
        "force" : 260,
        "attack": 50,
        "parry" : 50,
        "dodge" : 55,
        "lvl" : 200,
        "damage": 180,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      
        "action": "ֻ��$Nʮָ���ţ�����ָָ��㣬����" HIY "�������ָ" NOR "����"
                  "��" HIY "������ָ" NOR "���ľ�����ʽͬʱʹ����\n��ʱ�����ݺᣬ��"
                  "ɰ���𣬱���$n��ȥ",
        "force" : 260,
        "attack": 50,
        "parry" : 55,
        "dodge" : 55,
        "lvl" : 200,
        "damage": 180,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      
        "action": "ֻ��$N����Ծ�𣬳�Хһ������ն��£���" HIM "���ǽ���" NOR "������"
                  "��$nȫ�����",
        "force" : 260,
        "attack": 20,
        "parry" : 25,
        "dodge" : 25,
        "lvl" : 300,
        "damage": 200,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      "action": "$N�����ָ����ָ��������������������ָ��͸������" HIW "��ڤ����" NOR
                  "������$n�����Ѩ",
        "force" : 260,
        "attack": 20,
        "parry" : 30,
        "dodge" : 25,
        "lvl" : 300,
        "damage": 200,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
]),
([      "action": "ң��$N���һָ�������$n��ָδ������" HIR "�κϽ���" NOR "���ѽ�$nѹ"
                  "��͸��������",
        "force" : 280,
        "attack": 20,
        "parry" : 30,
        "dodge" : 35,
        "lvl" : 300,
        "damage": 240,
        "weapon" : HIR "�κ����彣��" NOR,
        "damage_type" : "����"
])
});


int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qxxy-shou" || combo=="xingyi-zhang"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���κ�ָ������֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ�κ�ָ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����κ�ָ��\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (random(2)==0 && random(me->query_dex()) >= 25 && me->query_skill("canhe-zhi",1) > 200 &&
             me->query_skill("parry",1) > 80 
             && random(10)>5
             ) {
                me->add("neili", -30);
                return ([
                "action": HIY "$NĬ����Ԫ�񹦣�ָ����ƮƮ�ص���$n��һ���ھ�������Ϣ������$n�����Ѩ��"NOR,
                "force": 650,
                "dodge": 35,
                "damage": 635,
                "damage_type": "����"]);
        }
        if (random(2)==0 && random(me->query_dex()) >= 30 && me->query_skill("canhe-zhi",1)> 200 &&
                me->query_skill("parry",1) > 120 
                && random(10)>5){
                me->add("qi",-30);            
                me->add("neili", -50);
                return ([
                "action": HIY "$Nָ��Ϭ������һ�����ν�������$n�������ڣ�$nֻ����ǰ����������ãȻ��֪���롣"NOR,
                "force": 780,
                "dodge": 45,
                "damage": 735,
                "damage_type": "����"]);
        }
        level   = (int) me->query_skill("canhe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        int lvl = me->query_skill("canhe-zhi", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["canhe-zhi"])
                while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jing") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("��������������κ�ָ��\n");
        me->receive_damage("jing", 20);
        me->add("neili", -10);
		return 1;
}
string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];

	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(3)==0 ) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return HIY "ֻ��һ���Һ���һ����Ѫ��$n��ָ�е��˿������\n" NOR;	
}

                if (random(5)==0 && (me->query("neili") > 200) && random(me->query_skill("canhe-zhi", 1)) > 60)
                {
                        victim->start_busy(2);
                        me->add("neili",-30);
                        victim->receive_wound("qi", damage_bonus / 2 + 30);
                        if (victim->query("neili") <= (damage_bonus / 2 + 30))
                                victim->set("neili", 0);
                        else
                                victim->add("neili", - damage_bonus / 2 + 30);
                                
                        return HIW "$NĬ����Ԫ�񹦣�ָ����ƮƮ�ص���$n��һ���ھ�������Ϣ������$n�����Ѩ��\n"
                               HIW "$nֻ��ȫ��һ�飬�ѱ�һ�е��С�" HIR + name + HIW "����\n" NOR;
                } 

}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"����������$n�͹����ʹ������������$n�ĳ�����������$n�������������У�\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"ʹ�����ƶ�ת��$n����Ī�����������;ת�˷���ֱ���Լ�Ϯ��!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}