// tanzhi.c ��ָ��ͨ

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string *xue_name1 = ({ 
        "��׶Ѩ",
        "�ٻ�Ѩ",
        "־��Ѩ",
        "�羮Ѩ",
        "�͹�Ѩ",
        "�ڹ�Ѩ",
        "���Ѩ",
        "����Ѩ",
});
string *xue_name2 = ({
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�׺�Ѩ",
        "��̨Ѩ",
        "�縮Ѩ",
        "���Ѩ",
        "����Ѩ",
}); 
string *xue_name3 = ({
        "����Ѩ",
        "����Ѩ",
        "˿����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "����Ѩ",
        "����Ѩ",
}); 
string* xuedao = ({
	"�޹�Ѩ",
	"�ز�Ѩ",
	"�羮Ѩ",
	"�ճ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"����Ѩ",
	"�縮Ѩ",
	"����Ѩ",
	"�յ�Ѩ",
	"ǿ��Ѩ",
	"�ٺ�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��׵Ѩ",
	"��βѨ",
	"����Ѩ",
	"�͹�Ѩ",
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"������",
	"����Ѩ"
});

mapping *action = ({
([  "action" : "$N��ָ���˸���Ȧ��һʽ�������ѵء����϶��»���$n��ȫ��",
    "force" : 320,
    "dodge" : 15,
    "damage": 135,
    "lvl" : 20,
    "skill_name" : "�����ѵ�",
	"damage_type" : "����"
]),
([  "action" : "$N���ƻ��أ�һ�С��������ơ�����ָ��������ָ��$n�Ķ�ͷ",
    "damage": 155,
    "force" : 280,
    "dodge" : 20,
    "lvl" : 0,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N˫�������һʽ��ǧ����ָ������ָ��$n��$l",
    "damage": 105,
    "force" : 190,
    "dodge" : 15,
    "lvl" : 0,
    "skill_name" : "ǧ����ָ",
    "damage_type" : "����"
]),
([  "action" : "$N����һ̾��һ�С���ָ��������˫�ֻó�����ָӰ������$n��$l",
    "force" : 380,
    "dodge" : 50,
    "damage": 140,
    "lvl" : 50,
    "skill_name" : "��ָ����",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��Цָ���ϡ���������ʽ����ָ����һ��ָ�����$n��$l",
    "force" : 240,
    "dodge" : 35,
    "damage": 200,
    "lvl" : 10,
    "skill_name" : "Цָ����",
    "damage_type" : "����"
]),
([  "action" : "$N�ó�������һָ�����ȫ��������һָ����$n��$l",
    "force" : 420,
    "dodge" : 40,
    "damage": 330,
    "lvl" : 80,
    "skill_name" : "����һָ",
    "damage_type" : "����"
]),
([      "action" : "$N����ʳָ���͵�һ�����죬һ��ϸϸ��������$n"+xuedao[random(sizeof(xuedao))],
	"force" : 250,
	"dodge" : 0,
	"parry" : 0,
	"damage": 325,
	"lvl" : 5,
	"weapon": "ָ��", 
	"damage_type" : "����"
]),
([      "action" : "$N��ס��ָ���������������£�����ָ�������������۵�ֿ������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
	"force" : 300,
	"dodge" : 20,
	"parry" : 15,
	"damage": 240,
	"lvl" : 20,
	"weapon": "ָ��",
	"damage_type" : "����"
]),
([      "action" : "$N������ָ������ָ��һ�뵯������ָָ������$n"+xuedao[random(sizeof(xuedao))]+"������ָ�ϰ�������������Ϣ������"+xuedao[random(sizeof(xuedao))],
	"force" : 350,
	"dodge" : 25,
	"parry" : 20,
	"damage": 250,
	"lvl" : 40,
	"damage_type" : "����"
]),
([      "action" : "$N˫�㲻�����ˣ�̤�Ŷ�����ľ֮λ��ʳ�ж�ָ����סĴָ��һ����Х�����ֵ���������һ�������޼���ָ��������$n��"+xuedao[random(sizeof(xuedao))],
	"force" : 400,
	"dodge" : 30,
	"parry" : 15,
	"damage": 260,
	"lvl" : 60,
	"damage_type" : "����"
]),
([      "action" : "$N���һ����˫���������У���������һ�����ţ�����ָ����������Ϣ��Ϯ��$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"����ҪѨ",
	"force" : 450,
	"dodge" : 40,
	"parry" : 10,
	"damage": 280,
	"lvl" : 80,
	"weapon": "ָ��",
	"damage_type" : "����"
]),
([      "action" : "$N��ɫ���أ�������ת��ֻ��$N������ָ����Ϊ����ɫ����������$n��$nֻ���ؿ�һ�ϣ���һ��ɭ��֮����ָ��ѹ�ü�������Ҳ��������",
	"force" : 500,
	"dodge" : 50,
	"parry" : 10,
	"damage": 400,
	"lvl" : 100,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="lanhua-shou"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ָ��ͨ������֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��ָ��ͨ��\n");
	if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
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
	string xue;

    level   = (int) me->query_skill("tanzhi-shentong",1);
	xue = xuedao[random(sizeof(xuedao))];

        if (random(level) > 200 && me->query_skill("force") > 200 && me->query("neili") >= 500)
         {
	return ([
	"action": HIG"$N���ӵ�����Ĵ��˰��Ȧ�ӣ���������һ����������â���Ƴ��߰������������������ͻʢ������$n��"+xue+""NOR,
	"force" : 600,
	"dodge" : 140,
	"parry" : 140,
	"damage": 600,
	"weapon": HIG"ָ��"NOR,
	"damage_type":  "����"
]);
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
        return notify_fail("���������������Ϣһ�������ɡ�\n");
	if ((int)me->query("neili") < 20)
        return notify_fail("���������������ָ��ͨ��\n");
    me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl = me->query_skill("finger");
        string name1,name2, name3;
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
        name1 = xue_name1[random(sizeof(xue_name1))];
        name2 = xue_name2[random(sizeof(xue_name2))];
        name3 = xue_name3[random(sizeof(xue_name3))];
        if ( lvl > 200 
         && me->query("neili") > 300
         && !victim->is_busy()
         && random(10) > 5 && lvl > random( victim->query("dodge", 1)/2)){
              message_vision(HIR "$n��$N�����ˡ�"HIC + name1 + HIR"������Ϣ���ң�\n" NOR,me,victim);
              victim->start_busy(random(3)+1);
           if (random(lvl) > 200) {
              message_vision(HIY "$N��ָ΢�����ֵ�����$n�ġ�"HIC + name2 + HIY"����\n" NOR,me,victim);
              message_vision(HIY "$nֻ����ͷ΢΢��ѣ�������ܼ��У�\n" NOR,me,victim);
               if (userp(victim))
              victim->add("jing",- lvl); 
else victim->add("jing",- victim->query("jing")/4); 
              }
           if (random(lvl) > 200) {
              message_vision(HIG "$N�����ٵ���$n�ġ�"HIC + name3 + HIG"����\n" NOR,me,victim);
              message_vision(HIG "$n����һ���ʹ�������޷����ۣ�\n" NOR,me,victim);
              victim->add("neili",- lvl*2); }
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        string name1;
        int p,j,skill, neili, neili1, exp, exp1;
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("parry");
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");
        name1 = xue_name1[random(sizeof(xue_name1))];

        if(skill > 150
         && living(ob)
         && random(15) > 6 ) {
          if(wp1){
           msg = HIW"$N��æ�г����ָ����ʹ����ָ��ͨ��$n��$w��ȥ��\n"NOR;
           msg = replace_string(msg, "$w", wp1->name());
           if(neili >= random(neili1)+damage){
              if(random(me->query_dex()) > ob->query_str()/2 && skill > 140){
                  msg += HIR"$n����һ�ȣ�"+wp1->name()+HIR"�ɳ����ɣ�\n"NOR;
                  msg += HIR"$n�ؿ���Ѫ���ڣ��ƺ��ܵ���΢�����ˣ�\n"NOR;
                  wp1->unequip();
                  wp1->move(environment(ob));
                  j = -(damage);              }
              else{
                  ob->receive_damage("qi", damage/5);
                  ob->receive_wound("qi", damage/5);
                  p = ob->query("qi")*100/ob->query("max_qi");
                  msg += damage_msg(damage/20, "�˺�");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  j = -(damage/2+skill/2);
              }
           }
           else if(neili >= random(neili1)+damage){
              msg += GRN"�����$n�Ĺ�������һ�衣\n"NOR;              
              j = -(damage/2+skill/2);
           }
           else{
              j = damage/2+random(damage/2);
              if(j<damage/2) msg += GRN"�����$n��������ת�˿�ȥ��\n"NOR;
              else msg += GRN"�����$n��������ת�˿�ȥ��\n"NOR;
              j = -j;
           }
           message_vision(msg, me, ob);
           return j;
          }
          else{
           msg = HBMAG"$NΣ���У������ָ����$n�ġ�"HBRED + name1 + HBMAG"����\n"NOR;
           if(neili >= neili1+random(neili1)+damage){
              ob->receive_damage("qi", damage/5);
              ob->receive_wound("qi", damage/5);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*2+skill);
           }
           else if(neili >= random(neili1)+damage){
              msg += GRN"�����$n�Ĺ�������һ�衣\n"NOR;
              j = -(damage+skill);
           }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += GRN"�����$nһЩ����ת�ƿ�ȥ��\n"NOR;
              else msg += GRN"�����$nһЩ����ת�ƿ�ȥ��\n"NOR;
              j = -j;
           }           
           message_vision(msg, me, ob);
           return j;
          }
        }
}
