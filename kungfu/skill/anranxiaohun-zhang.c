//anranxiaohun-zhang.c ��Ȼ������
// By hxsd@ CuteRabbit Studio 99-4-16 16:22 new
#include <ansi.h>
//inherit F_SSERVER;
inherit SKILL;

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action": ""+(order[random(13)])+"$N���۸�����ĿԶ���������鸡����ǰ�Ż�������ȫ����������ѧ�и������޲��Ǻϡ�$n��һ���ɣ�������Ϊ$N��������"NOR"",
        "dodge": 30,
        "force": 400,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 5,
        "damage_type": "����"
]),
([      "action": "$Nһ��"+(order[random(13)])+"���ľ�������"NOR"��С�����������ͬʱ�ؿ�����������ٿ�ص���ӭ��$n��˫ȭ",
        "dodge": 15,
        "force": 380,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 25,
        "damage_type": "����"
]),
([	"action": "$Nһʽ"+(order[random(13)])+"��������졹"NOR"��̧ͷ���죬��$n��������������������һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ����£ס$nȫ��",
	"dodge": 10,
	"force": 320,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 35,
	"damage_type": "ץ��"
]),
([	"action": "$NͻȻ�����붯��һʽ"+(order[random(13)])+"���������С�"NOR"�������䣬˫��ͷ���������ر�������������ʽ��������һ����������",
        "dodge": 15,
	"force": 160,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 45,
	"damage_type": "����"
]),
([	"action": "$Nһʽ"+(order[random(13)])+"�������ˮ��"NOR"����������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬��������ɱ����ֱ��$n��$l",
	"dodge": 30,
	"force": 230,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 55,
	"damage_type": "����"
]),
([	"action": "$N��Ӱ��ת������Ȱ��ǰ����˲��˲�ң�һʽ"+(order[random(13)])+"���ǻ��չȡ�"NOR"�Ʒ�����$n��$l",
	"dodge": 10,
	"force": 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 65,
	"damage_type": "ץ��"
]),
([	"action": "$N��̾һ������ɣƣ�����������أ�ȴ��һ��"+(order[random(13)])+"���������ġ�"NOR"���յ�$nȫ������֮�ʣ�����ֱ�����Ŵ�Ѩ",
	"dodge": 10,
	"force": 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 75,
	"damage_type": "����"
]),
([	"action": "$N��Ŀ��Ȼ����ֱ֫ͦ���������ۣ�����"+(order[random(13)])+"����ʬ���⡹"NOR"�㣬���۽��ȣ���նֱ��$n��$l",
	"dodge": 25,
	"force": 500,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 85,
	"damage_type": "����"
]),
([	"action": "$Nһʽ"+(order[random(13)])+"��ӹ�����š�"NOR"�����ִ��أ�һ�߻��ײ�ֹ������ȴҲ��ٿ�����Ƶ������������㱩��$n�ĺ���",
	"dodge": 20,
	"force": 430,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 105,
	"damage_type": "����"
]),
([	"action": ""+(order[random(13)])+"$NͻȻͷ�½��ϣ��������ӣ������������У��ִ����У������ֹ���˫�����δ����˫�ֻ������������$n������"NOR"",
	"dodge": 10,
	"force": 360,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 125,
	"damage_type": "����"
]),
([	"action": ""+(order[random(13)])+"$N��Ȼ��Ц��ֹ�����ֵ߿�������Ц���䣬$n���������䶯�����Գ������$N��һ�ȹ���$n��$l"NOR"",
	"dodge": 20,
	"force": 400,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 145,
	"damage_type": "����"
]),
([	"action": ""+(order[random(13)])+"ȴ��$N����������˫�ֺ�ʮ��Ĭ�̾��ģ��������Ƴ��ְ�������У�ƾ������$n,�������ˣ��޷�Ӳ��"NOR"",
	"dodge": 20,
	"force": 450,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 165,
	"damage_type": "����"
]),
([	"action" : "$Nһ��"HIW"�������"NOR"̧ͷ���죬��������������һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ��������$n��$l��",
	"force" : 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 120,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"HIG"��������"NOR"�ֱ��´������ް�������ʽ��ͻȻ�������붯���������䡢˫��ͷ���������ر�������������ʽ����ײ��$n.",
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 100,
	"force" : 250,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 10,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"HIB"�����ˮ"NOR"��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬�����빥$n��",
	"force" : 250,
	"dodge" : 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 20,
	"skill_name" : "�����ˮ",
	"damage_type" : "����"
]),

([	"action" : "$Nһ��"HIY"��������"NOR"�����ո���ͷ�������£��Ų����ص�����$n,���������������$n��$l��",
	"force" : 300,
	"damage" : (int)this_player()->query("age")*8,
	"dodge" : 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"lvl" : 30,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIR"��ʬ����"NOR"�߳�һ�š���һ�ŷ���ʱ�л��㱣�����ԼԼ���������޵�����$n",
	"force" : 250,
	"damage" : (int)this_player()->query("age")*8,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 100,
	"lvl" : 40,
	"skill_name" : "��ʬ����",
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�У�һ��"HIM"ӹ������"NOR"û����ɵ�����$n��$l.",
	"force" : 250,
	"dodge" : 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 50,
	"skill_name" : "ӹ������",
            "damage_type" : "����"
]),
([	"action" : "$Nһ��"RED"������ʩ"NOR"ͻȻ�������࣬ͷ�½��ϣ��������ӣ�һ������$n��$l",
	"force" : 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 100,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 60,
	"skill_name" : "������ʩ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"YEL"�ľ�����"NOR"��ĿԶ���������鸡����ǰ�Ż�������ȫ����ʽ����ѧ�и������޲��Ǻϡ�",
	"force" : 300,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 120,
	"damage" : (int)this_player()->query("age")*9,
	"lvl" : 70,
	"skill_name" : "�ľ�����",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"BLU"������ʳ"NOR"�����鸡�����缸�첻�Բ�˯��ĽŲ��ʲյ�Ϯ��$n�����ԣ�������ȭ����$n��$l��",
	"force" : 300,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*10,
	"lvl" : 80,
	"skill_name" : "������ʳ",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIC"�ǻ��չ�"NOR"���Ҵ�����ʵʵ�Ĺ���$n��$l��",
	"force" : 300,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*11,
	"lvl" : 90,
	"skill_name" : "�ǻ��չ�",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"CYN"��������"NOR"����������״������бб����$n��$l��",
	"force" : 350,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*12,
	"lvl" : 100,
	"skill_name" : "��������",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"MAG"���񲻰�"NOR"�������ݼ�ת��չ���ṦΧ��$n�������ߣ���Ȼ�����������$n��$l��",
	"force" : 400,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*13,
	"lvl" : 110,
	"skill_name" : "���񲻰�",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"WHT"��;ĩ·"NOR"����$n���ԣ����ƾٵ���ǰƽ�ƶ�������������бб����$n��$l��",
	"force" : 450,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*14,
	"lvl" : 120,
	"skill_name" : "��;ĩ·",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIY"����ľ��"NOR"˫Ŀֱֱ�Ķ���$n�����嶯Ҳ����һ�µķ���$n",
	"force" : 500,
	"dodge" : 150,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*15,
	"lvl" : 130,
	"skill_name" : "����ľ��",
           "damage_type" : "����"
]),
([	"action" : "$N��ͷڤ�룬һ��"HIB"������ʧ"NOR"��������ƽƽ����$n��$l��",
	"force" : 500,
	"dodge" : 150,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*16,
	"lvl" : 140,
	"skill_name" : "������ʧ",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIB"��ͨ�˴�"NOR"˫�ƻγ�ǧ����Ӱ��$n����������֮�¡�",
	"force" : 580,
	"dodge" : 160,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*17,
	"lvl" : 150,
	"skill_name" : "��ͨ�˴�",
           "damage_type" : "����"
]),
([	"action" : "$N����ǰ��һ��"HIB"¹��˭��"NOR"�������ȣ��Կ������һ��ת���Ѿ�ת����$n�������ָ������$n�Ĵ�׵Ѩ��",
	"force" : 600,
	"dodge" : 160,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*18,
	"lvl" : 160,
	"skill_name" : "¹��˭��",
           "damage_type" : "��Ѩ"
]),
([      "action" : "$Nһ�С�"HIW"�������"NOR"��̧ͷ���죬��������������һ��"
                   "���Լ�ͷ���տ��ĳ�������б�£��������ɻ�\n"
                   "�Σ���ɢ��������$n��$l",
        "force"  : 250,
        "attack" : 40,
        "dodge"  : 40,
        "damage" : 120,
        "lvl"    : 0,
        "skill_name" : "�������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIG"��������"NOR"���ֱ��´������ް�������ʽ��"
                   "ͻȻ�������붯���������䡢˫��ͷ��������\n"
                   "�ر�������������ʽ����ײ��$n",
        "force"  : 260,
        "attack" : 45,
        "dodge"  : 45,
        "damage" : 125,
        "lvl"    : 10,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIB"�����ˮ"NOR"����������Ʈ����������ˮ������"
                   "ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬����\n"
                   "�빥$n",
        "force"  : 280,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 130,
        "lvl"    : 20,
        "skill_name" : "�����ˮ",
        "damage_type": "����"
]),

([      "action" : "$Nһ�С�"HIY"��������"NOR"�������ո���ͷ�������£��Ų���"
                   "�أ����������������$n��$l",
        "force"  : 300,
        "attack" : 55,
        "dodge"  : 55,
        "damage" : 135,
        "lvl"    : 40,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIR"��ʬ����"NOR"���߳�һ�š���һ�ŷ���ʱ�л��"
                   "㱣�����ԼԼ���������޵�����$n",
        "force"  : 330,
        "attack" : 60,
        "dodge"  : 60,
        "damage" : 140,
        "lvl"    : 60,
        "skill_name" : "��ʬ����",
        "damage_type": "����"
]),
([      "action" : "$N˫��ƽ�У�һ�С�"HIM"ӹ������"NOR"��û����ɵ�����$n��$l",
        "force"  : 360,
        "attack" : 70,
        "dodge"  : 65,
        "damage" : 145,
        "lvl"    : 80,
        "skill_name" : "ӹ������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"RED"������ʩ"NOR"��ͻȻ�������࣬ͷ�½��ϣ�����"
                   "���ӣ�һ������$n��$l",
        "force"  : 390,
        "attack" : 80,
        "dodge"  : 70,
        "damage" : 50,
        "lvl"    : 100,
        "skill_name" : "������ʩ",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"YEL"�ľ�����"NOR"����ĿԶ���������鸡����ǰ�Ż�"
                   "������ȫ����ʽ����ѧ�и������޲��Ǻ�",
        "force"  : 420,
        "attack" : 90,
        "dodge"  : 75,
        "damage" : 155,
        "lvl"    : 120,
        "skill_name" : "�ľ�����",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"BLU"������ʳ"NOR"�������鸡�����缸�첻�Բ�˯��"
                   "�ĽŲ��ʲյ�Ϯ��$n�����ԣ����ƺ���ȭ��\n"
                   "��$n��$l",
        "force"  : 460,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 160,
        "lvl"    : 140,
        "skill_name" : "������ʳ",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIC"�ǻ��չ�"NOR"�����Ҵ�����ʵʵ�Ĺ���$n��$l",
        "force"  : 490,
        "attack" : 110,
        "dodge"  : 85,
        "damage" : 65,
        "lvl"    : 160,
        "skill_name" : "�ǻ��չ�",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"CYN"��������"NOR"������������״������бб����$n��$l",
        "force"  : 520,
        "attack" : 55,
        "dodge"  : 90,
        "damage" : 190,
        "lvl"    : 70,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"MAG"���񲻰�"NOR"���������ݼ�ת��չ���ṦΧ��$n"
                   "�������ߣ���Ȼ�����������$n��$l",
        "force"  : 550,
        "attack" : 50,
        "dodge"  : 95,
        "damage" : 175,
        "lvl"    : 200,
        "skill_name" : "���񲻰�",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"WHT"��;ĩ·"NOR"������$n���ԣ����ƾٵ���ǰƽ"
                   "�ƶ�������������бб����$n��$l",
        "force"  : 570,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 180,
        "lvl"    : 220,
        "skill_name" : "��;ĩ·",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIY"����ľ��"NOR"��˫Ŀֱֱ�Ķ���$n�����嶯Ҳ��"
                   "��һ�µķ���$n",
        "force"  : 590,
        "attack" : 55,
        "dodge"  : 55,
        "damage" : 185,
        "lvl"    : 240,
        "skill_name" : "����ľ��",
        "damage_type": "����"
]),
([      "action" : "$N��ͷڤ�룬һ�С�"HIB"������ʧ"NOR"����������ƽƽ����$n"
                   "��$l",
        "force"  : 520,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 190,
        "lvl"    : 260,
        "skill_name" : "������ʧ",
        "damage_type": "����"
]),
([      "action" : "$Nһ�С�"HIB"��ͨ�˴�"NOR"��˫�ƻγ�ǧ����Ӱ��$n��������"
                   "��֮��",
        "force"  : 650,
        "attack" : 165,
        "dodge"  : 115,
        "damage" : 95,
        "lvl"    : 280,
        "skill_name" : "��ͨ�˴�",
        "damage_type": "����"
]),
([      "action" : "$N����ǰ��һ�С�"HIB"¹��˭��"NOR"���������ȣ��Կ������"
                   "һ��ת���Ѿ�ת����$n�������ָ����\n"
                   "��$n�Ĵ�׵Ѩ",
        "force"  : 580,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 100,
        "lvl"    : 300,
        "skill_name" : "¹��˭��",
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }


int valid_learn(object me)
{
	if(!me->query("couple/have_couple")) 
		return notify_fail("�㻹û���������ˣ�����������еľ�Ҫ��\n");
//	if (me->query("gender") != "����") 
//                return notify_fail("����᲻������˼��һ���˵����顣\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");
	if ((int)me->query_str()< 30)
		return notify_fail("��ı���̫�����޷�����Ȼ�����ơ�\n");	
	if ((int)me->query_con() < 30 )
		return notify_fail("��û���ۺ�������޷���Ȼ�����ơ�\n");
        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("����Ṧ̫��޷�����Ȼ�����ơ�\n");
        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("�����Ů�������̫ǳ��\n");
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

string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}
 
mapping query_action(object me, object weapon)
{
    int i, j, level, adjust, tmp;
//    object target; 
string msg;            
    level   = (int) me->query_skill("anranxiaohun-zhang",1);
    for(i = sizeof(action); i > 0; i--) {
        if(level > action[i-1]["lvl"]) {
            j = NewRandom(i, 20, level/5);
//            target = offensive_target(me);    
              switch(random(3)){
                  case 0: msg = HIC"$N���������ң�û����ɵĻ��������ĳ�һ�ƣ�ֻ�����۵�һ������һ�����û���$n��ͷ"NOR; break;
                  case 1: msg = HIY"$N���������ң�û����ɵĻ��������ĳ�һ�ƣ�ֻ�����۵�һ������һ�����û���$n��ͷ"NOR; break;
                  case 2: msg = HIR"������$N�߳�һ�š���һ�ŷ���ʱ�л��㱣�����ԼԼ���������ޡ����һ�죬��$n�ؿ�Ϯȥ"NOR; break;
                  default: msg = HIC"$N���������ң�û����ɵĻ��������ĳ�һ�ƣ�ֻ�����۵�һ������һ�����û���$n��ͷ"NOR; break;
              }


            if (me->query_temp("anran")
               && me->query("jiali") >= 50 
               && random(10) >= 5
               && me->query_skill("yunv-xinfa",1)>10) {                
                    return ([  
                      "action":msg, 
                    "force" : action[j]["force"]+30,
                    "dodge":action[j]["dodge"]+50,
                    "damage": level+700,
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"��Ȼ���Ʒ�":"��Ȼ������",
                    "damage_type" : random(2)?"����":"����",
                    ]);
               }
            if (level >= 130 && random(6) > 4
               && me->query("jiali") >= 50 
               && random(10) >= 5
               && me->query_skill("yunv-xinfa",1)>10) {                
                    return ([  
                      "action":msg, 
                    "force" : action[j]["force"],
                    "dodge":action[j]["dodge"],
                    "damage": level/2+600,
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"�Ʒ�":"��Ȼ����",
                    "damage_type" : "����",
                    ]);
               }
if(!me->query_skill("yunv-xinfa"))
{
    action[j]["force"]  = action[j]["force"]/2;
    action[j]["dodge"] = action[j]["dodge"]/2;
    action[j]["parry"]  = action[j]["parry"]/2;
    action[j]["attack"] = action[j]["attack"]/2;
    action[j]["damage"] = action[j]["damage"]/2;
}
            return action[j];
        }
    }
} 


int practice_skill(object me)
{
	if (me->query_skill("anranxiaohun-zhang",1) > 100
	&& (int)me->query_skill("yunv-xinfa", 1) < (int)me->query_skill("anranxiaohun-zhang",1) )
		return notify_fail("������ֻ����learn����ѧ��Ȼ�����ơ�\n");	
	if ((int)me->query("jing") < 100)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query_str() < 30 )
		return notify_fail("��û����׳�ı����޷���Ȼ�����ơ�\n");
	if ((int)me->query_con() < 30 )
		return notify_fail("��û���ۺ�������޷���Ȼ�����ơ�\n");
        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("����Ṧ̫��޷�����Ȼ�����ơ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("���������������Ȼ�����ơ�\n");
        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("�����Ů�������̫ǳ��\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("�����Ů�����̫ǳ��\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("������޵������̫ǳ��\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���̫ǳ��\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("�����չ÷���̫ǳ��\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("�������������̫ǳ��\n");



        me->receive_damage("jing", 70);
	me->receive_damage("qi", 70);
	me->add("neili", -70);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j;
    j = me->query_skill("anranxiaohun-zhang", 1);
    if( damage_bonus < 100 ) return 0;
    if( !random(8) && !victim->is_busy() && j > 140
     && me->query_skill_mapped("parry") == "anranxiaohun-zhang"
     && me->query("neili") > 1000 && me->query("max_neili") > 1500 
     && j > random(victim->query_skill("dodge",1))
     && (int)me->query_skill("yunv-xinfa", 1) > 10
     && me->query_skill_mapped("force") == "yunv-xinfa"){
          switch(random(3)){
            case 0 :
               msg = YEL"$Ņͷ���죬��������������һ����ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ���£�\n"NOR;
               msg += HIR"���$n����һ�С�������졹���ñ�˵����������վ���Ų�Ҳ�ǲ��ܡ�\n"NOR; 
               if (!victim->is_busy())victim->start_busy(4);
               break;
            case 1 :
               msg = HIB"$N��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣡\n"NOR;
               msg += HIR"���$n����һ�С������ˮ�������������ݺ��ξ��ˣ�����ײײ��\n"NOR;
               if (!victim->is_busy())victim->start_busy(4);               
               break;
            case 2 :
               msg = HIG"ͻȻ��$N�����붯���������䡢˫��ͷ���������ر�������������ʽ������\n"NOR;
               msg += HIR"���$n����һ�С��������С���������ȫȻ�������ľ��ء�\n"NOR;
               if (!victim->is_busy())victim->start_busy(4);
               break;               
          }         
          message_vision(msg, me, victim);
    }
	if( damage_bonus < 100 ) return 0;
	if( damage_bonus/2 > victim->query_str() ) {
if((int)me->query_skill("yunv-xinfa", 1) > 10 || random(10) > 5
&& me->query_skill_mapped("force") == "yunv-xinfa")
{
if (me->query_skill_mapped("unarmed") == "anranxiaohun-zhang")
{
		victim->receive_wound("qi", (random(j)) / 2+20 );
		victim->receive_damage("qi", (random(j)) /2+20 );
		return HIR "ֻ�������ۡ���һ����"+ victim->name()+"�����һ�����Ѫ��\n" NOR;
}
}
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

string perform_action_file(string action)
{
	return __DIR__"anranxiaohun-zhang/" + action;
}


string query_description()  
{
        return 
        "����Ժ�С��Ů�ھ���ȶϳ���ǰ���֣����ñ����������ں���֮��������"
        "����֮�󣬳����ڹ�ѭ�򽥽�֮�⣬����޿��������������ռ�˼��С��Ů��"
        "����������������������Ȥ��һ���ں�����Ȼ���ã���������֮������ȭ���"
        "�ߣ���ʱ���ڹ�����ѵ���һ���־��߼�������������һ�ƣ�����̲��һֻ��"
        "����ı��Ǵ�÷��顣���ɴ���˼��������һ���������Ʒ���������Ѱ���书"
        "���죬����֮����ȫ��������һ����һʮ���С�����ƽ�ܹ�������ѧ���ҵ�ָ"
        "�㣬��ȫ���ѧ�����������ڹ��Ŀھ�����С��Ůѧ�á���Ů�ľ������ڹ�Ĺ"
        "�м����������澭����ŷ�����Ը�󡹦����ת���������߹���������Դ򹷰�"
        "������ҩʦ���Ե�ָ��ͨ�����｣��������һ��ָ֮�⣬��а����������ؤ��"
        "����ͨ����ѧ��������������Ĺ�ɵ���ѧ����������֮����辶����ʱ��"
        "���ͨ������׿Ȼ�ɼҡ�ֻ������ʣһ�ۣ����Բ��������仯ȡʤ����������"
        "����ѧͨ���෴�����������Ƴ�����Ϊ����Ȼ�����ơ���ȡ���ǽ��͡��𸳡�"
        "����һ�䡰��Ȼ�����ߣ�Ψ������ӡ�֮�⡣";
}
