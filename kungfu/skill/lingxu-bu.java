// lingxu-bu ���鲽

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ��ѩ�������������ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ
�ꡣ\n",
        "dodge"  : 40
]),
([      "action" : "$nһʽ��һ�����졹��˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����
$N���\n",
        "dodge"  : 60
]),
([      "action" : "$nһʽ�����л�Ӱ��������һ�Σ���ʱ��������Ӱһ���ӳ�����$N��
��ǰ��\n",
        "dodge"  : 80
]),
([      "action" : "$nһʽ���������ߡ���ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
        "dodge"  : 100
]),
([      "action" : "$nһʽ������Ʈ�졹�����弱ת����Ϊһ���׹⣬��ò����ĳ�����
$N����Χ��\n",
        "dodge"  : 120
]),
});


int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

