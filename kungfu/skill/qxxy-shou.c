// �����������ࡢ���������ᡢ��Ȩ����⡢������ҡ�"NOR"����߿�����ɣ���ת�ڱ�
// ������Χ�����У���������Ȩ����Ϊ���������ҡ�"NOR"�Ϊ�񡣡�ʷ�ǡ�����顷��
// �ء��������ǣ���ν�����⣬������������Я���ǣ�����϶���������ס���

#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([      "action": "$Nһָ�������һ��"+(order[random(13)])+"���������"NOR"�й�ֱ����ָ����$nѹ�ô���������",
        "force" : 90,
        "dodge" : 5,
        "damage": 115,
        "lvl"   : 0,
        "damage_type" : "��Ѩ",
        "skill_name"  : "�������"
]),
([      "action": "$N���β�����һ��"+(order[random(13)])+"�����ǻ�ۡ�"NOR"������$n��һ��ԥ��$N����ָ�Ѵ����Լ�",
        "force" : 140,
        "attack": 5,
        "parry" : 5,
        "dodge" : 5,
        "damage": 120,
        "lvl"   : 40,
        "damage_type" : "��Ѩ",
        "skill_name"  : "���ǻ��"
]),
([      "action": "ֻ��$Nһת������һʽ"+(order[random(13)])+"�����Ʊ�����"NOR"��һָ��в�´���������$n��$l",
        "force" : 155,
        "attack": 10,
        "parry" : 7,
        "dodge" : 5,
        "damage": 130,
        "lvl"   : 40,
        "damage_type" : "��Ѩ",
        "skill_name"  : "���Ʊ���"
]),
([      "action": "ֻ��$Nһ��"+(order[random(13)])+"��ƫ�����ǡ�"NOR"��ʮָ�紩������һ�����·��ɣ�ȫȫ����$n",   
        "force" : 170,
        "attack": 20,
        "parry" : 11,
        "dodge" : 9,
        "damage": 140,
        "lvl"   : 60,
        "damage_type" : "��Ѩ",
        "skill_name"  : "ƫ������"
]),
([      "action": "ֻ��$N���΢Ц�����ֶ�����һ��"+(order[random(13)])+"�����Ƿ�׹��"NOR"��$n�پ�һ��ָ��ֱ�˶���",
        "force" : 190,
        "attack": 30,
        "parry" : 12,
        "dodge" : 10,
        "damage": 150,
        "lvl"   : 80,
        "damage_type" : "��Ѩ",
        "skill_name"  : "���Ƿ�׹"
]),
([      "action": "����$Nһ����߳��һ��"+(order[random(13)])+"�������ǳ���"NOR"�����ֻ��˸��뻡��ʳָ��������$n",
        "force" : 250,
        "attack": 40,
        "parry" : 23,
        "dodge" : 25,
        "damage": 157,
        "lvl"   : 100,
        "damage_type" : "��Ѩ",
        "skill_name"  : "�����ǳ�"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"���ǹ���á�"NOR"��˫ȭ����, ����$n��$l",
        "force"  : 120,
        "dodge"  : 10,
        "damage" : 2,
        "lvl"    : 0,
        "skill_name" : "�ǹ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��ҡ�"NOR"���λ��"NOR"��һȭ��ɨ��������磬����$n��$l",
        "force"  : 140,
        "dodge"  : 12,
        "damage" : 115,
        "lvl"    : 20,
        "skill_name" : "ҡ�"NOR"���λ",
        "damage_type" : "����"
]),
([      "action" : "$N��Ӱ��Ʈ��������΢Ц��һ��"+(order[random(13)])+"���ǹ����ա�"NOR"����ȭ��������$n��$l",
        "force"  : 150,
        "dodge"  : 16,
        "damage" : 115,
        "lvl"    : 40,
        "skill_name" : "�ǹ�����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��Ⱥ����˸��"NOR"��˫ȭ�������ϣ�$nֻ��������$N��ȭӰ",
        "force"  : 160,
        "dodge"  : 18,
        "damage" : 122,
        "lvl"    : 60,
        "skill_name" : "Ⱥ����˸",
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ��"+(order[random(13)])+"��ǧ���򻯡�"NOR"����$nһת���������ߣ�ȭ����磬��ס�Ļ���$n��",
        "force"  : 170,
        "dodge"  : 21,
        "damage" : 126,
        "lvl"    : 80,
        "skill_name" : "ǧ����",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$NͻȻ�Ϳ��������ѵ�$n��ǰ����ȭ������Ѹ����ף�"
                   "һ��"+(order[random(13)])+"�������꡹"NOR"����$n��ǰ��",
        "force"  : 220,
        "dodge"  : 22,
        "damage" : 130,
        "lvl"    : 100,
        "skill_name" : "��ʯ�ɽ�",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"���������ɡ�"NOR"��ȭӰ����������һ�빥��$n��",
        "force"  : 250,
        "dodge"  : 25,
        "damage" : 135,
        "lvl"    : 120,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action": "$N������ָ�ֿ���΢΢һ����һʽ"+(order[random(13)])+"������ָ��"NOR"����$n������ҪѨ",
        "force" : 100,
        "dodge" : 15,
        "damage": 115,
        "lvl"   : 0,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$N��������$n��һʽ"+(order[random(13)])+"������ָ��"NOR"��������ָ����$n����ǰ��Ѩ",
        "force" : 130,
        "dodge" : 20,
        "damage": 130,
        "lvl"   : 30,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$Nʹһʽ"+(order[random(13)])+"������ָ��"NOR"�������鹥����ָбǰ����������$n�ļ羮Ѩ",
        "force" : 170,
        "dodge" : 25,
        "damage": 140,
        "lvl"   : 60,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$N΢΢�������ƹ��ϣ�һʽ"+(order[random(13)])+"����Ȩָ��"NOR"����������$n����ͻѨ",
        "force" : 190,
        "dodge" : 25,
        "damage": 145,
        "lvl"   : 80,
        "damage_type" : "����",
        "skill_name" : "��Ȩָ"
]),
([      "action": "$Nʹһʽ"+(order[random(13)])+"�����ָ��"NOR"����Ӱ����������$n����͵�����$n�Ĵ�׵Ѩ",
        "force" : 220,
        "dodge" : 30,
        "damage": 150,
        "lvl"   : 100,
        "damage_type" : "����",
        "skill_name" : "���ָ"
]),
([      "action": "$Nʩ��"+(order[random(13)])+"������ָ��"NOR"��˫������һ��������$n�Ļ��ǡ���ᡢ�Ϲ�������Ѩ",
        "force" : 250,
        "dodge" : 35,
        "damage": 155,
        "lvl"   : 120,
        "damage_type" : "����",
        "skill_name" : "����ָ"
]),
([      "action": "$Nһʽ"+(order[random(13)])+"��ҡ�"NOR"�ָ��"NOR"���Ӹ����£�����һ����������$n�İٻ��Ѩ",
        "force" : 280,
        "dodge" : 40,
        "damage": 165,
        "lvl"   : 140,
        "damage_type" : "����",
        "skill_name" : "ҡ�"NOR"�ָ"
]),
([      "action": "$Nʩչ��"+(order[random(13)])+"����Ὺ�ơ�"NOR"��˫�ּ�����һ�����ľ�������$n�������¸���ҪѨ",
        "force" : 320,
        "dodge" : 45,
        "damage": 170,
        "lvl"   : 160,
        "damage_type" : "����",
        "skill_name" : "��Ὺ��"
])
});

int valid_enable(string usage)
{
	return usage == "hand" ||  usage == "parry";
}

int valid_combine(string combo)
{
	return combo == "canhe-zhi";
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����������ֱ�����֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("���Ľ�ݽ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");
        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹����޷�ѧ���������֡�\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("�������̫�����޷������������֡�\n");

        if ((int)me->query_skill("hand", 1) < 80)
                return notify_fail("��Ļ����ַ�̫��޷�ѧϰ���������֡�\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("qxxy-shou", 1))
                return notify_fail("������ַ���򲻹����޷�������������������֡�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        string msg;
        level   = (int) me->query_skill("qxxy-shou",1);
        
        if (me->query_skill("qxxy-shou",1) > 200
             && me->query_skill("hand",1) > 80
             && random(6) ==0 ){
                switch(random(4)){
                        case 3: msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ"NOR; break;
                        case 2: msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С��"NOR; break;
                        case 1: msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ��"NOR; break;
                        case 0: msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ���"NOR; break;
                      
                }    
                return([      
                        "action": msg,        
                        "force" : 500+random(150),
                        "dodge" : 20,
                        "damage" : 500+random(150),
                        "damage_type" : me->query_temp("mr_riyue")?"����":"����",
                ]);
        }
            
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}



int practice_skill(object me)
{
        if ((int)me->query("qi") < 100)
                return notify_fail("�������̫���ˣ��޷������������֡�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������̫���ˣ��޷������������֡�\n");
                
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");
                
        me->receive_damage("qi", 80);
        me->add("neili", -53);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qxxy-shou/" + action;
}
mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(4)==0) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return HIG "ֻ��$nһ���Һ����³�һ����Ѫ��\n" NOR;	
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