// xinyuegong.c ���¹�

inherit SKILL;

string *dodge_msg = ({
"�ƺ�$Nÿһ�ж�����$n������������$n���ǻ򷴴򡢻����ܣ�һһ��⿪ȥ��\n",
"ȴ��$nһ��ͷ����$N����������ȥ��������Ƹ���$n���ұۡ�\n",
"��֪$n����һ�ϣ��������ɵرܹ���$N�Ĺ�����\n",
"$n�������㣬����$N����һ�С�Ҷ�׷��ࡹ����Ϊ��\n"
});

string  *msg = ({
"$Nʹ�ϰ��С��������ԡ�������$w����$n�ظ�֮���ġ�����Ѩ��������׼������",
"$Nʹ�°��С��������ԡ�������$w���������$n���ĵġ���̨Ѩ��������׼������",
"$N���С��������ԡ�������������ֻһ�У������а������־�������������Ѩ�ĸ��ַ���",
"$N�������߶�ʮһ��$w�ӳ����̼�֮�£���һ�С��������ԡ�ֻʹ����һ�룬������׼ȷ����$n�ؿڵġ�����Ѩ��",
"$N����һ�С�����������������һ�$n����һ������֪��һ��ȴ�����У�$w�����������»���$n$l",
"$NͻȻ����$n���ף�������ͦ��ײ��$n������",
"$N�������㣬����$n��������һ�С�Ҷ�׷��ࡹ�ǻ��Եľ���֮һ�������Ƿ�",
"$N���һ��$n���ұۣ����������������ţ�˫����ץס$w��һ��һ�ͣ�����$n$l"
});

int valid_enable(string usage)
{
        return usage == "hammer" || usage == "parry" 
            || usage == "dodge" || usage == "staff" 
            || usage == "stick" || usage == "club";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                "damage":(random(2)+1)*20,
                "damage_type":random(2)?"����":"����",
                "dodge":-5+random(15),
                "force":50+random(80)
        ]);
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        return notify_fail("NPC�书��������ҿ��š�\n");
}