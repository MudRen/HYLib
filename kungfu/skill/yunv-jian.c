// yunv-jian.c ��Ů��
#include <ansi.h>

#include <combat.h>
inherit F_DBASE;
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
int ke_qz(object me, object victim, object weapon, int damage);
mapping *action = ({
([      "action" : "$Nһ��"+(order[random(13)])+"������б����"NOR"������б�ɣ�����$w�������$n��$l",
        "force" : 160,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 155,
	"post_action": (: ke_qz :),	
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N��Ծ����"+(order[random(13)])+"���׺羭�졹"NOR"��$w��Ȼ�´�",
        "force" : 170,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 140,
	"post_action": (: ke_qz :),	
        "lvl" : 4,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"���˼����ġ�"NOR"���ӽ�ֱ���������ɵ�",
        "force" : 180,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 145,
        "lvl" : 9,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nʹ"+(order[random(13)])+"����ǰ���¡�"NOR"һ�����϶��²�����ģ����ֺ�ա�����̵صĹ�
��",
        "force" : 190,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 150,
        "lvl" : 14,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N����$w���������ʻ���չ���ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪��
�ι���",
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 155,
        "lvl" : 19,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"������С�á�"NOR"�������𣬽�����ָ�����������ƣ�ֱ��$n��
$l",
        "force" : 110,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 160,
        "lvl" : 24,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N����$w��������һ�̣�������������ʹ��"+(order[random(13)])+"��ɨѩ��衹"NOR"��",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 165,
        "lvl" : 29,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N���ƺ����ǰ��������$w����ӷ���ȴ��һ��"+(order[random(13)])+"�����ٰ�����"NOR"",
        "force" : 130,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 170,
        "lvl" : 34,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"�����¶��ġ�"NOR"��$w���������һ���󻡣�����$n��$l",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 175,
        "lvl" : 39,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N����������ң�������Ϊ������$n��ȴ��һ��"+(order[random(13)])+"���رߵ��ס�"NOR"",
        "force" : 150,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 180,
        "lvl" : 44,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��������Ʈ��"NOR"��$w����ػ�������Բ������$n��$l��ȥ",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 185,
        "lvl" : 49,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��С԰�վա�"NOR"������$wѸ����$n��������������",
        "force" : 170,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 190,
        "lvl" : 54,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"������ҹ����"NOR"������$w�й�ֱ�룬����$n��$l",
        "force" : 180,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 195,
        "lvl" : 59,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N��������ҵͣ�һ��"+(order[random(13)])+"���������䡹"NOR"��$w�ڿ��л���һ���⻷������
$n",
        "force" : 190,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 200,
        "lvl" : 64,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N����$w���¶��Ͼ��������������һ�㣬ȴ��"+(order[random(13)])+"�������ٳء�"NOR"",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 205,
        "lvl" : 70,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N������״��һ��"+(order[random(13)])+"��ľ�����㡹"NOR"������$wֱ��$n��$l",
        "force" : 210,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 210,
        "lvl" : 76,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N���ֽ���һ�죬����$wƽƽ����$n��$l����һ��"+(order[random(13)])+"��˫���Իء�"NOR"",
        "force" : 220,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 215,
        "lvl" : 82,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N����$w�����̣�һ��"+(order[random(13)])+"�����Ƴ��ԡ�"NOR"��ֱָ$n��$l",
        "force" : 230,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 220,
        "lvl" : 88,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"�������չȡ�"NOR"��$w���������һ�ӣ���$n����˼��ĽǶȹ���
",
        "force" : 240,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 225,
        "lvl" : 94,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��"+(order[random(13)])+"���軨��·��"NOR"��һʱ����о���$w��Ӱ�ӣ���$n��֪��εֵ�
",
        "force" : 250,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 230,
        "lvl" : 100,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��İ·��ɣ��"NOR"��$w�������㣬����$n��$l",
        "force" : 260,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 235,
        "lvl" : 99,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�̶�������һ��"+(order[random(13)])+"������������"NOR"��$w���¶��ϴ���$n",
        "force" : 270,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 240,
        "lvl" : 106,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N���Ų�������$wͻȻ���Լ������´̳���ȴ��һ��"+(order[random(13)])+"�����Ľ�����"NOR"
",
        "force" : 280,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 245,
        "lvl" : 112,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N������ˮ�滬��һ�㣬һ��"+(order[random(13)])+"��������ҹ��"NOR"��ƽƽ����$n��$l��ȥ",
        "force" : 290,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 250,
        "lvl" : 118,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"���������"NOR"������$w�̵�$n������",
        "force" : 300,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 255,
        "lvl" : 124,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"��ĵ�����᡹"NOR"��$w�Ƴ�������Ȧ��ƽƽ����$n��$l��ȥ",
        "force" : 310,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 260,
        "lvl" : 131,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$N��������棬������ǰһ�ˣ�һ��"+(order[random(13)])+"����ҩ���项"NOR"��$w��$n��$l��
ȥ",
        "force" : 320,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 265,
        "lvl" : 138,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"����ǰ���ࡹ"NOR"������Ծ������$wɨ��$n��$l",
        "force" : 330,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 265,
        "lvl" : 145,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),

([  "action" : "$N������Ȼ֮ɫ������һ��"+(order[random(13)])+"������Բԡ�"NOR"��$w����$n��$l",
        "force" : 380,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 275,
        "lvl" : 159,
	"post_action": (: ke_qz :),
        "damage_type" : "����"
]),
([      "action":"$N����$w���϶��£�һ��"+(order[random(13)])+"����ǰ���¡�"NOR"��$w���������ʻ���չ���У����ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪���н��Ӻδ�����",
        "force" : 160,
        "dodge" : 50,
        "parry" : 50,
        "damage": 215,
        "lvl" :  0,
        "skill_name" : "��ǰ����",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$N$w΢�ڣ�һ��"+(order[random(13)])+"�����ٰ��"NOR"���������ѣ����˴�Լ���������¼����Ȼ���ҷ緶",
        "force" : 180,
        "dodge" : 50,
        "parry" : 50,
        "damage": 125,
        "lvl" : 9,
        "skill_name" : "���ٰ���",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$Nһ��"+(order[random(13)])+"��ɨѩ��衹"NOR"��������ţ����ζ���������Ͷ���ƮƮ�г���֮�룬$w���������潣�𣬴���$n$l",
        "force" : 200,
	"dodge" : 50,
        "parry" : 50,
        "damage": 260,
        "lvl" : 15,
        "skill_name" : "ɨѩ���",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action": "$Nһ��"+(order[random(13)])+"������С�á�"NOR"������$w������������ָ�����������ƣ�������������$n$l������֮�֣�������˼",
        "force" : 240,
	"dodge" : 55,
        "parry" : 255,
        "damage": 140,
        "lvl" : 25,
        "skill_name" : "����С��",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$N�Ų�΢��������̤������������һ��"+(order[random(13)])+"�����¶��ġ�"NOR"������Ѹ�ݣ��鶯��ã������������������ҷ������ף���ʽ���",
        "force" : 280,
	"dodge" : 58,
        "parry" : 58,
        "damage": 70,
        "lvl" : 33,
        "skill_name" : "���¶���",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$N����΢�ڣ�һ��"+(order[random(13)])+"���رߵ��ס�"NOR"��$w����$n$l����һ��ȥ�ƿ����ǳ۵��������ҷ��˴�Լ��Ʈ���ޱ�",
        "force" : 300,
        "dodge" : 50,
        "parry" : 50,
        "damage": 255,
        "lvl" : 35,
        "skill_name" : "�رߵ���",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$N$w���Ʈ���������̬ƮƮ���ɣ�������$n��$l�������㣬ȴ��һ��"+(order[random(13)])+"��С԰�վա�"NOR"",
        "force" : 310,
        "dodge" : 55,
        "parry" : 55,
        "damage": 165,
        "lvl" : 45,
        "skill_name" : "С԰�վ�",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$N�������ܣ�һʽ"+(order[random(13)])+"������ҹ����"NOR"����̨�γ�����·��Խ��Խ��������ȴ�ް�������$wʹ�þ���Ѹ������ȥ����",
        "force" : 320,
	"dodge" : 5,
        "parry" : 5,
	"damage": 275,
	"lvl" : 55,
	"skill_name" : "����ҹ��",
	"post_action": (: ke_qz :),
	"damage_type":  "����"
]),
([      "action":"$N$w����������ʮ������⣬����һ��"+(order[random(13)])+"�����¿��ˡ�"NOR"��ת˲�佣���ѽ�$n�ϰ���������",
        "force" : 330,
        "dodge" : 8,
	"parry" : 8,
        "damage": 280,
        "lvl" : 60,
        "skill_name" : "���¿���",
	"post_action": (: ke_qz :),        
        "damage_type":  "����"
]),
([      "action":"$N����һ����һʽ"+(order[random(13)])+"���ʱʻ�ü��"NOR"��$w΢΢�������ὣб��$n$l�������������ɰ���",
        "force" : 360,
	"dodge" : 50,
        "parry" : 50,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "�ʱʻ�ü",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$N��ƮƮ���������ˣ�һ��"+(order[random(13)])+"�����İ�ͨ��"NOR"��$w���ط�ת���̣���������ʮ���¼��죬�������ø��ֵķ�����ָҲ����˼���",
        "force" : 380,
	"dodge" : 10,
        "parry" : 10,
        "damage": 385,
        "lvl" : 75,
        "skill_name" : "���İ�ͨ",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
([      "action":"$Nһ��$w����ʱ����������$w�������߰��������ߣ�һ��"+(order[random(13)])+"���������"NOR"��$n�����������ǰ�ӹ����Ѿ�$l��һ��",
        "force" : 400,
	"dodge" : 20,
        "parry" : 20,
        "damage": 450,
        "lvl" : 80,
        "skill_name" : "�������",
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query_skill("yunv-xinfa", 1) < 85)
                return notify_fail("�����Ů�ķ���򲻵����޷�ѧϰ��Ů������\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("�����Ů�����̫ǳ��\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("������޵������̫ǳ��\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���̫ǳ��\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("�������������̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yunv-jian",1);

	if (random(level) > 220 && me->query("neili") > 1000 )
return ([      "action":HIW"$N���˼�������������������$w"+HIW"Ʈ����ȥ��������������һ·��Ů��������ʹ��Ӣ��ˬ�ʣ��������ˣ�"NOR,
        "force" : 550 + random(level),
	"dodge" : 20,
        "parry" : 20,
        "damage": 550 + random(level),
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]);

        if (random(me->query_skill("yunv-jian",1)) > 160 && me->query_skill("yunv-xinfa",1) > 100 &&
        me->query("neili") > 200)
{
	me->add("neili", -50);
	if (me->query("gender")== "����") {
return ([      "action":HIG"$N�������飬�ж����������಻��������������������������ɣ����н��������ӵ�ȹ�����̬֮��"NOR,
        "force" : 550 + me->query_skill("yunv-jian"),
	"dodge" : 100,
        "parry" : 100,
        "damage": 500,
        "lvl" : 175,
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]);
}
	else {
return ([      "action":HIY"$N�������ߣ�$w"+HIY"��һ��δ�ϣ������������г���ʱ�������󣬽��еֵ�ʱ����ת�ң����ƽ��ǽ��������ˣ������ⲻ������$n��֮������Ȼ��"NOR,
        "force" : 550 + me->query_skill("yunv-jian"),
	"dodge" : 100,
        "parry" : 100,
        "damage": 500,
        "lvl" : 175,
	"post_action": (: ke_qz :),
        "damage_type":  "����"
]);
	}
//	return action[random(sizeof(action))];
}
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
        if ((int)me->query("qi") < 45)
                return notify_fail("���������������Ů������\n");
        if ((int)me->query("neili") < 15)
                return notify_fail("�����������������Ů������\n");
        if ((int)me->query_skill("yunv-xinfa", 1) < 85)
                return notify_fail("�����Ů�ķ���򲻵����޷�ѧϰ��Ů������\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("�����Ů�����̫ǳ��\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("������޵������̫ǳ��\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���̫ǳ��\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("�������������̫ǳ��\n");

        me->receive_damage("qi", 26);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}
int ke_qz(object me, object victim, object weapon, int damage)
{
        string str;
        int skill,v_parry;
	object weapon2;
	weapon2 = victim->query_temp("weapon");
	skill = me->query_skill("yunv-jian",1);

        if(skill > 80 ){
	if (damage==RESULT_DODGE
	&& victim->query_skill_mapped("dodge") == "jinyan-gong" 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("jinyan-gong",1))
	&& random(3)==0
	&& me->query_skill("yunv-xinfa",1) > 50) {

	message_vision(HIW"��֪$N��Ϥ���㹦����������������Ź�������������$n����֮������ϵ�˿˿��ۣ�$n��$Pһ������������ˤ����\n"NOR, me,victim );
        if (!victim->is_busy())
	victim->start_busy(3);
	if (victim->query("qi") > skill*2)
	victim->receive_damage("qi", random(skill)+skill);
        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
	}
	else if (damage==RESULT_PARRY 
	&& ( objectp(weapon2 = victim->query_temp("weapon")) 
&& victim->query_skill_mapped("sword") == "quanzhen-jian" &&(string)weapon2->query("skill_type") == "sword")
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry",1))
&& random(2)==0
&& me->query_skill("yunv-xinfa",1) > 50) {

	message_vision(HIW"$nͻ���Լ�����"+weapon2->name()+HIW"��ͦ���죬����$N����"+weapon->name()+HIW"��˹�ȥ��һ��֮�£����������ضᡣ\n"NOR, me,victim );
	message_vision(HIW"˫�����ᣬֻ΢һ���֣�$NͻȻ�ſ�"+weapon->name()+HIW"��˫��ֱ�ۣ��ͻ�$nǰ�أ�ͬʱ"+weapon->name()+HIW"��������������˫��һ������·����������֮����\n"NOR, me,victim );
	if (random(me->query("combat_exp")) > random(victim->query("combat_exp"))){
	message_vision(HIW"$nֻ������"+weapon2->name()+HIW"�����ֺ��أ�����һ�У�\n"NOR, me,victim );
        weapon2->unequip();
	weapon2->move(environment(me));
	}
        weapon->unequip();
        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/damage", skill);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/attack", -skill/4);
        me->add_temp("apply/damage", -skill);
        weapon->wield();
        message_vision("\n$N��Ӧ��ݣ����ѳ���"+weapon->name()+"�������У�\n", me,victim );
        me->add("neili",-20);
}
	else if (damage==RESULT_PARRY 
	&& ( !objectp(weapon2 = victim->query_temp("weapon")) 
&& ((victim->query_skill_mapped("parry") == "quanzhen-jian" )
|| (victim->query_skill_mapped("parry")== "haotian-zhang")
|| (victim->query_skill_mapped("unarmed")== "haotian-zhang")
|| (victim->query_skill_mapped("sword")== "quanzhen-jian"))
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry",1)) )
&& random(2)==0
&& me->query_skill("yunv-xinfa",1) > 50) {

	message_vision(HIW"����$N�漴ͦ��һ�̣��ؽ��ȿ���׼��ֱ��$n���ƣ�����ȫ���书����������֮����$n���´󾪣���æ���֣��������ƣ�$N����������\n"NOR, me,victim );
        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/damage", skill);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/attack", -skill/4);
        me->add_temp("apply/damage", -skill);
	me->add("neili",-20);
		}
	}
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
        level  = (int) me->query_skill("yunv-jian",1);

	if( (victim->query_temp("qzjtong") )
	&& random(me->query("combat_exp")*2) > victim->query("combat_exp")
	&& level > 100
	&& random(3)==0 
	&& me->query_skill("yunv-xinfa",1) > 50) {
       if (!victim->is_busy())
	victim->start_busy(1+random(1));
if (victim->query("neili") > 200)
	victim->add("neili",-200);
if (victim->query("neili") > 200)
if (victim->query("qi") > level*2)
{
	victim->receive_wound("qi", level+random(level));
	victim->receive_damage("qi", level*2);
}
	return HIR"$nͻȻ˫Ŀֱ�ɣ����һ��������ˤ�����������˼��صİ��ˣ�ͬ�齣����Ȼ���ƣ�\n"NOR;
			}
	
	if( (victim->query_temp("powerupxtg") )
	&& random(me->query("combat_exp")*2) > victim->query("combat_exp")
	&& level > 100
	&& random(3)==0 
	&& me->query_skill("yunv-xinfa",1) > 50) {
       if (!victim->is_busy())
	victim->start_busy(1+random(1));
if (victim->query("neili") > 200)
	victim->add("neili",-200);
if (victim->query("neili") > 200)
if (victim->query("qi") > level*2)
{
	victim->receive_wound("qi", level+random(level));
	victim->receive_damage("qi", level*2);
}
	return HIR"$nͻȻ˫Ŀֱ�ɣ����һ��������ˤ�����������˼��صİ��ˣ��������Ȼ���ƣ�\n"NOR;
			}
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
