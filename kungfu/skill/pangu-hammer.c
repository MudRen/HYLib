// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N���ֻ���һ��ԲȦ�������е�$wһ�У������ķ�����$n��$l��ȥ��",
                "force":               700,
                "dodge":                600,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�����е�$w��һ�У�����ɽ�ӣݣ����е�$w��$n��$l����������¡�",
                "damage":               150,
                "dodge":                400,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�����ڿշ�����̩ɽѹ��֮ʽ���£����е�$w���ź������һ�У�ǧ��һ���ݻ���$n��$l��",

                "damage":               70,
		"force" :		200,
                "dodge":                500,
                "parry":                700,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���е�$wһת��һ�Уۿ�籩��ݴ�����˷�����$n��$l",
                "damage":               40,
		"force" :		200,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nһ�����е�$w��һ�У����տ����ݻó�һƬ���⽣Ӱ������ʵʵ�Ļ���$n��$l",
                "force":               100,
		"damage" : 		50,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_neili") / 10 < 55 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("���������һ�������������Ƶ��������������̹ž�ʽ��\n");

        if( (int)me->query("qi") < 60 )
                return 
notify_fail("��������������̹ž�ʽ����������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("qi", 60);
        return 1;
}
int effective_level() { return 20;}
 
string *parry_msg = ({
        "$n����һ����һ�У۵����س������е�$v�͵�����$N��$w��\n",
	"$n����΢�٣����е�$vһ�У�Χ�����ԣݷ���$N�ıؾ�֮����\n",
	"$n���е�$v�������ϼ��ӣ�һ�У۶�����ݿĿ���$N���е�$w\n",
});

string *unarmed_parry_msg = ({
	"$nһ�У��ӹ������ݣ����е�$v��ƫ�����$N��̫����Ѩ��\n",
	"$n���е�$v�����ң�һ�Уۺ�ɨǧ���ݷ�ס��$N�Ĺ��ơ�\n",
	"$n�����������һ�У���ɳ�������е�$v����$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 50;
}
int practice_bonus()
{
	return -100;
}
int black_white_ness()
{
	return 10;
}


string perform_action_file(string action)
{
        return __DIR__"pangu-hammer/" + action;
}
