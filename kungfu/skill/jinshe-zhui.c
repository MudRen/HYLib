// jinshe-zhui.c

inherit SKILL;
string* xuedao = ({
        "�İ�Ѩ",
        "�ز�Ѩ",
        "��ӭѨ",
        "Ͽ��Ѩ",
        "ͷάѨ",
        "�¹�Ѩ",
        "����Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "�ػ�Ѩ",
	"�ٳ�Ѩ",
        "�ٺ�Ѩ",
        "ͨ��Ѩ",
        "����Ѩ",
        "ӡ��Ѩ",
        "����Ѩ",
        "��ҺѨ",
        "����Ѩ",
        "����Ѩ",
        "�ٻ�Ѩ",
        "��̨Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "����Ѩ"
});

mapping *action = ({
        ([      "name":		"ǧ����",
                "action":"$N˫��һ�Σ�һ�С�ǧ���򻯡������е�$w�ó������⣬
��һ�����������$n��$l",
                "dodge":	120,
                "force":	200,
                "damage":	600,
		"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "name":		"���Ī��",
                "action":"$N����һ����һ�����ð����ֻһɲ�Ǽ䣬����$wѸ�װ�Խ
�����ֵ�$w������һ�С����Ī�⡹�����ȷ���$n��$l",
                "dodge":	140,
                "force":	300,
                "damage":	500,
                "post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
                "damage_type":  "����"
        ]),
([	"action":"$N����һö$w����׼$nһ���֣���$w��ֱ����$n��"+xuedao[random(sizeof(xuedao))],
	"force" : 120,
        "dodge" : 20,
	"damage": 320,
	"number": -1,
	"lvl" : 0,
]),
([	"action":"$N˫�����ӣ���ö$w���ź�Х���������ɶ�������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
	"force" : 180,
        "dodge" : 30,
	"damage": 340,
	"number": -2,
	"lvl" : 5,
]),
([	"action":"$N����Ծ�𣬾Ӹ�������$n������ö$w��ֱȡ$n��˫Ŀ��"+xuedao[random(sizeof(xuedao))],
	"force" : 220,
        "dodge" : 30,
	"damage": 360,
	"number": -3,
	"lvl" : 15,
]),
([	"action":"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö$w�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ",
	"force" : 260,
        "dodge" : 15,
	"damage": 340,
	"number": -1,
	"lvl" : 25,
]),
([	"action":"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
	"force" : 300,
        "dodge" : 25,
	"damage": 350,
	"number": -1,
	"lvl" : 35,
]),
([      "action":"$NһЦ���ˣ�����ȴ������һ�ģ���ö$w����ǰ��Ȼ�������ȡ$n���ʺ�"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 470,
        "number": -2,
        "lvl" : 45,

]),
([      "action":"$N˫��ͬ�ӷ�����ö$w����$n˫Ŀ���ſ�һ������һö$w���������ϵس�Խǰ��ö$w������������$n��"+xuedao[random(sizeof(xuedao))],
	"force" : 380,
        "dodge" : 30,
        "damage": 485,
        "number": -3,
        "lvl" : 45,
]),
([      "action":"$N����һö$w����׼$nһ���֣���$w��ֱ����$n��"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 520,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"$N˫�����ӣ���ö$w���ź�Х���������ɶ�������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
        "force" : 180,
        "dodge" : 30,
        "damage": 540,
        "number": -2,
        "lvl" : 5,
]),
([      "action":"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö$w�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ",
        "force" : 260,
        "dodge" : 15,
        "damage": 540,
        "number": -1,
]),
([      "action":"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
        "force" : 300,
        "dodge" : 25,
        "damage": 550,
        "number": -1,
        "lvl" : 35,
]),
([      "action":"$NһЦ���ˣ�����ȴ������һ�ģ���ö$w����ǰ��Ȼ�������ȡ$n���ʺ�"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 570,
        "number": -2,
        "lvl" : 45,
]),
([      "action":"$N����һö$w����׼$nһ���֣���$w��ֱ����$n��"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 520,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö$w�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ",
        "force" : 260,
        "dodge" : 15,
        "damage": 540,
        "number": -1,
]),
([      "action":"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
        "force" : 300,
        "dodge" : 25,
        "damage": 550,
        "number": -1,
        "lvl" : 35,
]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������������û�а취������׶����\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "throwing" )
                return notify_fail("���������һЩ��������������׶����\n");

        return notify_fail("����׶��û�����ڡ�\n");
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||      (int)me->query("neili") < 500 )
                return 
notify_fail("�����������������û�а취��ϰ����׶����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
        //write("�㰴����ѧ����һ�����׶����\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhui/" + action;
}
 
