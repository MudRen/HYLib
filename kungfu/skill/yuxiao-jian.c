// yuxiao-jian.c ���｣��
// modified by Venus Oct.1997
// Made by deaner
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
	"ȴ��$n����΢ת�����赭д����$W���ᵲ��$w���ڴ�δ����ߣ�������δ��Ƭ��ͣ�͡�\n",
});

mapping *action = ({
([      "action" : "$N����һ��������$wһ��ʹ��һ��"+(order[random(13)])+"��ɽ��������"NOR"��Ȧת����$w��������������Ȼ����һ����$w���ã���۵�ֿ�㼲��$n��$l",
	"force" : 100,
	"dodge" : 10,
	"parry" : -15,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "ɽ������",
	"damage_type" : "����"
]),
([      "action" : "$N$wһ�ᣬʹ��һʽ"+(order[random(13)])+"����������"NOR"�����潣�ߣ�Ԣ���ڹ�����$n����ʽ���ǲ������ܣ���ֱ����$n��$l",
	"force" : 120,
	"dodge" : -10,
	"parry" : 15,
	"damage": 30,
	"lvl" : 5,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����$w�������裬ʹ��һ��"+(order[random(13)])+"�����¥̨��"NOR"������һ���̳�����;��������ü�����λ������$n��$l",
	"force" : 140,
	"dodge" : 10,
	"parry" : -5,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "���¥̨",
	"damage_type" : "����"
]),
([      "action" : "$N����$w��Ȼһ����ʹ��һ��"+(order[random(13)])+"�����亮����"NOR"��$w�����°�ɻ�Ȧת��ٿ��һչ�����ʯ������$n��$l",
	"force" : 170,
	"dodge" : 5,
	"parry" : -10,
	"damage": 35,
	"lvl" : 10,
	"skill_name" : "���亮��",
	"damage_type" : "����"
]),
([      "action" : "$Nͦ����$w����$n���̴̵�������һ��"+(order[random(13)])+"������������"NOR"��������˸������΢��������$w��������֮��������$n�������Ѩ",
	"force" : 190,
	"dodge" : -10,
	"parry" : -5,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����һ����˳��ʹ��һ��"+(order[random(13)])+"������ˮ�ơ�"NOR"���������࣬�������磬����һմ���ߣ������������裬ƮȻ����$n��$l",
	"force" : 210,
	"dodge" : 20,
	"parry" : -5,
	"damage": 45,
	"lvl" : 20,
	"skill_name" : "����ˮ��",
	"damage_type" : "����"
]),
([      "action" : "$N��ָ��$w��һ�����һ�����죬һ��"+(order[random(13)])+"������������"NOR"��$w�й�ֱ��������˿�����ɣ�������ǰ�Ĵ���$n��$l",
	"force" : 230,
	"dodge" : 0,
	"parry" : 45,
	"damage": 55,
	"lvl" : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����չ����ʹ��һʽ"+(order[random(13)])+"����ʷ������"NOR"������$w��ز���裬�������ƿ�һ�㣬����$n��$l����̬Ʈ�ݣ���������",
	"force" : 250,
	"dodge" : 10,
	"parry" : 0,
	"damage": 45,
	"lvl" : 25,
	"skill_name" : "��ʷ����",
	"damage_type" : "����"
]),
([      "action" : "$N����һ�䣬���μ������ˣ�һʽ"+(order[random(13)])+"���ɻ���䡹"NOR"������ɭɭ�����������컨��һ�㣬������˷�����������ʵ�����˱��޿ɱ�",
	"force" : 280,
	"dodge" : 0,
	"parry" : 10,
	"damage": 50,
	"lvl" : 30,
	"skill_name" : "�ɻ����",
	"damage_type" : "����"
]),
([      "action" : "$N��̤������Է�λ���������֣�����ʹ��һ��"+(order[random(13)])+"�������˪��"NOR"������$wбָ������$n����������ʵʵ��Ӧ�����ң���ͨ��������ྶͥ",
	"force" : 300,
	"dodge" : -5,
	"parry" : 5,
	"damage": 50,
	"lvl" : 35,
	"skill_name" : "�����˪",
	"damage_type" : "����"
]),
([      "action" : "$N����$w�ɻ���һ��"+(order[random(13)])+"����©��������"NOR"������$n��ȥ���䲻��������ȴռ���Ȼ�����$n�������߷�Բ֮�ؾ�����ס",
	"force" : 320,
	"dodge" : 0,
	"parry" : 5,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "��©������",
	"damage_type" : "����"
]),
([      "action" : "$N�Ų��������ģ�������ҡҡ��׹��ʵ����ȾŹ���һ��"+(order[random(13)])+"�����������ѡ�"NOR"������ƽƽ�������������޵ش���$n��$l",
	"force" : 350,
	"dodge" : 0,
	"parry" : 5,
	"damage": 65,
	"lvl" : 45,
	"skill_name" : "����������",
	"damage_type" : "����"
]),
([      "action" : "$N�Ʋ����Σ�һ��"+(order[random(13)])+"����ɽ��ס�"NOR"��$w���ַɳ�������$n��$l������ʹ������׽Ӱ��������������$w���ù�������ָΪ��������$n",
	"force" : 380,
	"dodge" : 10,
	"parry" : -10,
	"damage": 75,
	"lvl" : 50,
	"skill_name" : "��ɽ���",
	"damage_type" : "����"
]),
([      "action" : "$Nһ����Х������ԴԴ����ע�뽣��������â��ʢ��һʽ"+(order[random(13)])+"������ֹϢ��"NOR"������������һ��ƥ��Ҳ�ƵĽ���Ю��ɭɭ�����ƿն���������ӵ�к����ȻĪ��",
	"force" : 400,
	"dodge" : -10,
	"parry" : -20,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "����ֹϢ",
	"damage_type" : "����"
]),
([      "action" : "$N�Ųȷ�����ʮ���Է�λ�����Ƽӿ죬ʹ��һ��"+(order[random(13)])+"���Ǻ�ǧ���衹"NOR"��ֻ��һƬãã�����У�������ɫ��Ȧ��ӿ���������֮��$n��û�뽣��֮��",
	"force" : 420,
	"dodge" : 10,
	"parry" : 10,
	"damage": 95,
	"lvl" : 70,
	"skill_name" : "�Ǻ�ǧ����",
	"damage_type" : "����"
]),
([      "action" : "$N����һ����$w��ǰ�ݳ���������֮һ����̫������֮һ����̫��������һʽ"+(order[random(13)])+"�����ʶ���ۡ�"NOR"����������������ƣ���Ͼ�޹�",
	"force" : 450,
	"dodge" : 0,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "���ʶ����",
	"damage_type" : "����"
]),
([      "action" : "$N����������һ��"+(order[random(13)])+"��Ӣ�������Ҷ��С�"NOR"��ƮȻ����$n��ǰ���漴����$w΢��
���⼲����$n��$l",
        "force" : 150,
        "dodge" : 20,
        "damage" : 30,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nб��һ����ʹ��һʽ"+(order[random(13)])+"����Ů�鳤ֻ�޶̡�"NOR"���ӽ��������һ��һ�̵Ĺ�Ӱ
ֱ��$n��$l",
        "force" : 175,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"����Ȼ��ȥ��˼�项"NOR"��$w��Ȼ���������̻ص������У��漴ת����Ȼ
��ȥ��$n��ʱ�Ÿо�����һ�ɾ��������Լ���$l",
        "force" : 200,
        "dodge" : 25,
        "damage" : 40,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N˫�־ٽ����죬һ��"+(order[random(13)])+"������Ⱥ�������塹"NOR"��$w���������ף����϶�����
$n��ͷ­��ȥ",
        "force" : 225,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : "$Nʩչ��"+(order[random(13)])+"�����һЦ������"NOR"������$w���΢΢һЦ��$nֻ����һ����ȴ��
һ����Ӱ�������ΰ�Ϯ���Լ���$l�����Լ�ȴû����$N��ʱ�����֣���",
        "force" : 250,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N���̤ʵ���ҽ���㣬һ��"+(order[random(13)])+"��һ����ϳ�᡹"NOR"��$w����һ�Ž�����Ʈ��
�����ر���$n��$l",
        "force" : 270,
        "dodge" : 55,
        "damage" : 85,
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"������Ū������项"NOR"�������ḧ$w���漴�͵�һ����������ǰһ�ݣ�
ֻ��һ����˸�����Ľ�ӰѸ�ٴ���$n��$l",
        "force" : 290,
        "dodge" : 55,
        "damage" : 100,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N������ף���ɫ��Ȼ��һ��"+(order[random(13)])+"��������Թ���˳���"NOR"��$w�������Ʋ����ش���
$n��$l",
        "force" : 310,
        "dodge" : 55,
        "damage" : 120,
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N�������棬һ��"+(order[random(13)])+"���˽�������������"NOR"������$wб���»�����$n΢����֣�����
�ɼ䣬ȴ��$N���е�$w�ѷ������ϣ�ֱ���Լ����ʺ�",
        "force" : 330,
        "dodge" : 55,
        "damage" : 180,
        "lvl" : 80,
        "damage_type" : "����"
]),
([  "action" : "$N��Ȼ��¶΢Ц��һ��"+(order[random(13)])+"����������Ц���ա�"NOR"������$wһ����������Ž�������$n
����������·",
        "force" : 360,
        "dodge" : 55,
        "damage" : 200,
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$N����ʳָ����$w��һ��"+(order[random(13)])+"���������������项"NOR"��$w����һ���������������ƣ�$n
ֻ���õ���ǰһ�ƣ�һ����͵ľ��������Լ�",
        "force" : 390,
        "dodge" : 55,
        "damage" : 220,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N����΢��һ��"+(order[random(13)])+"��������������ϡ�"NOR"������$w����������һ����������ĺ�����
ɲ�Ǽ��ɳ��ʯ��$n����һ�Ž���������£�������֧����",
        "force" : 420,
        "dodge" : 55,
        "damage" : 350,
        "lvl" : 110,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 500) ||
        ((int)me->query_skill("bibo-shengong", 1) < 100) ||
        !(me->query("couple/have_couple")))
       return notify_fail("��ҩʦ˵��: ���｣����ֻ����Ե���㲻���������ˡ�\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("yuxiao-jian",1);
        if (random(level) > 240 && me->query_skill("force") > 200 && me->query("neili") >= 500)
         {
	return ([
	"action":HIG"$N���ӵ�����Ĵ��˰��Ȧ�ӣ�$w"NOR+HIG"һͦ����������һ��������$w"+HIG"������������������â���Ƴ��߰�������������ؽ�âͻʢ������$n��$l��"NOR,
	"force" : 500,
	"dodge" : 140,
	"parry" : 140,
	"damage": 500,
	"weapon": HIG"��â"NOR,
	"damage_type":  "����"
]);
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
    if ((int)me->query("qi") < 50)
       return notify_fail("����������������｣����\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"yuxiao-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$Nʩչ����������,$n����һ��,������$l�������Ѫ��!!\n";
        }
 
 
       if( random(10) >= 5 
        && !me->is_busy() 
        && !victim->is_busy() 
        && j > 120
        && k > 120
        && me->query_skill_mapped("parry") == "yuxiao-jian"
        && j > random(victim->query_skill("dodge",1))){
          switch(random(3)){
            case 0 :
               msg = HIW"$Nʩչ�����Ž�·�����������ճ��棡\n"NOR;
               msg+= HIW"$n�������ˣ�ȫ���мܣ��������У�\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
               break;
            case 1 :
               msg = HIW"$N���²������Ų�����һ���Ӵ̳��ü�����\n"NOR;
               msg+= HIW"$n�����ֲ������һ�����飬��һ����ʵ������ͣ�¹��ƣ������Ż���\n"NOR;
               victim->start_busy(2);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 0);
               break;
            case 2 :
               msg = HIW"$N��۵糸������$n���ܣ�������������ֱ�����㲻��صķ���һ�㣡\n"NOR;
               msg+= HIW"$n����$Nת��תȥ����Ū���ۻ����ң�ҡҡ��׹��\n"NOR;
               victim->start_busy(3);
               message_vision(msg, me, victim);
               COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
               break;
          }         
       }
}
