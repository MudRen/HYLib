// qiankundanuoyi.c Ǭ����Ų��
// by King 97.05

inherit SKILL;

string *parry_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *dodge_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

/*
int valid_learn(object me)
{
        int lvl = (int)me->query_skill("qiankundanuoyi", 1);

        if ( me->query("gender") == "����" && lvl > 99)
                return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ô������ڹ�����ѧǬ����Ų�ƣ�\n");

	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("����ô����������ѧǬ����Ų�ƣ�\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");

	if ((int)(me->query("max_neili", 1)/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��\n");

        return 1;
}
*/

int valid_learn(object me)
{
	return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");
}

int practice_skill(object me)
{
	return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų��>>�ķ���ߡ�\n");
}

