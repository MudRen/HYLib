// TIE@FY3
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
        ([      "action":               
"$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l��",
                "damage":               140,
                "dodge":                40,
                "parry":                40,
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l��",
                "damage":               140,
                "dodge":                20,
                "parry":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������������֣�һ��"+(order[random(13)])+"����������"NOR"����ץ��$n��$l��",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��Ю��һ���ȳ�֮������$n��$l��",
                "damage":               200,
                "dodge":                10,
                "parry":                40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������ɽ��һʽ"+(order[random(13)])+"���������"NOR"��˫ȭ���ƶ���������$n��$l��",
                "damage":               110,
                "dodge":                100,
                "parry":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������أ�����������һʽ"+(order[random(13)])+"��ľ�ѳ��ۡ�"NOR"��������$n�Ƴ���",
                "damage":               120,
                "dodge":                10,
                "parry":                20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������飬����������ޣ�һʽ"+(order[random(13)])+"��ˮ�����¡�"NOR"����$n�޿ɶ���",
                "damage":               100,
                "dodge":                10,
                "parry":                20,
                "damage_type":  "����"
        ]),
                        ([      "action":               "$Nʹһ��"+(order[random(13)])+"���ڻ����ġ�"NOR"����׼$n��$l"+(order[random(13)])+"������"NOR"��һȭ",
                                "force":                80,
                                "parry":                60,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����ȭͷ��һ��"+(order[random(13)])+"��̩ɽѹ����"NOR"����$n��$l�к���ȥ",
                                "force":                60,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������Σ���ȭ"+(order[random(13)])+"���й�ֱ����"NOR"����$n��$l����",
                                "force":                60,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ������ȭ��������ȭʹ��"+(order[random(13)])+"���Ϻ��Ƴ���"NOR"����$n$l",
                                "force":                60,
                                "parry":                80,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$Nʹһ��"+(order[random(13)])+"�����ɹ��¡�"NOR"����׼$n��$l"+(order[random(13)])+"������"NOR"��һȭ",
                                "dodge":                40,
                                "parry":                40,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����ȭͷ��һ��"+(order[random(13)])+"����ѩ��÷��"NOR"����$n��$l�к���ȥ",
                                "dodge":                30,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
                        ([      "action":               "$N������Σ���ȭ"+(order[random(13)])+"���������Ρ�"NOR"��$n��$l����",
                                "dodge":                30,
                                "parry":                30,
                "damage":               100,

                           "damage_type":  "����"
                        ]),
                        ([      "action":               "$N����һ������ȭ��������ȭʹ��"+(order[random(13)])+"����ɽ������"NOR"����$n$l",
                                "dodge":                30,
                                "parry":                30,
                "damage":               100,

                                "damage_type":  "����"
                        ]),
});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("����å��ȭ������֡�\n");

       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("��ı����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("��ı����Ṧ̫���ˡ�\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("liumang-quan", 1))
               return notify_fail("���ͨ��������̫���ˡ�\n");



        return 1;
}

int valid_enable(string usage)
{
        return (usage=="cuff") || (usage=="parry");
}
int valid_combine(string combo) { return combo=="tiezhang-zhangfa"; }


mapping query_action(object me)
{
        if (random(8) ==0 &&
            me->query_skill("liumang-quan") > 70 &&
            me->query("neili") > 100 ) {
                me->add("neili", -100);
                return ([
                "action": HIR"$Nһ������Ծ�����ɣ��ۼ�ȫ�����������$n"NOR,
                "damage": 500,
                                "dodge":                30,
                                "parry":                30,
                "force": 500,
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
         if( (int)me->query("qi") < 130 )
                return 
notify_fail("�����������������ȭ������������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("qi", 80);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$nһʽ"+(order[random(13)])+"���һ�׶��"NOR"��˫�������»���ȭ�����棬����$N��$w��\n",
	"$n�ڿշ���һʽ"+(order[random(13)])+"���˷��꡹"NOR"��˫��˫�����,������$N��$w��\n",
});

string *unarmed_parry_msg = ({
 "$nһʽ"+(order[random(13)])+"���һ�׶��"NOR"��˫�������»���ȭ�����棬����$N��$w��\n",
	"$n�ڿշ���һʽ"+(order[random(13)])+"���˷��꡹"NOR"��˫��˫�����,������$N��$w��\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"liumang-quan/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lev,damage, i;
        object weap;
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
       int badint=0; 
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N����һ������������һƬ��Ҷ���Ʈ��,$nͷһ�裬��֪����!\n"NOR;

victim->start_busy(3);

                return msg;
}
 
//        if( damage_bonus < 10 ) return 0;
        badint = me->query_skill("liumang-quan",1);
        if (random(6)==0 ) {
                if(badint) {
                        victim->receive_wound("qi",badint);
                        switch(random(3)) {
                                case 0: return HIR"$N���һ����ȫ����������$n��ǽ������˫����ȥ��\n"NOR;
                                case 1: return HIG"$N�������������������������뷢��$n��$l������������һ�����죡\n"NOR;
                                case 2: return HIB"ֻ����$n��$l��������һ�� ������\n"NOR;
                                }
                }
        }
}  