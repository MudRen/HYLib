inherit SKILL;

string *dodge_msg = ({
"ͻȻ$n����$N���ᴵ�˿�����$Nֻ����������棬æ����ݳ�����ܿ���\n",
"$Nֻ����ǰ�׹�һ����$n����Ӱ�Ѿ�վ�����ɿ��⣬$N����ʽȫ�����ڿմ���\n",
"$n����һ�Σ�$N����ǰ��ʱ�������ĸ�$n�����Σ����治֪�ĸ������ĸ��Ǽ١�\n",
"$n����һת������������࣬�ڵ���ʯ֮��ƹ���$N�Ĺ�����\n",
"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
"$N�۾�һ������û��$n����Ӱ����ͷһ����$n�Ѿ�վ��$N�����\n",
"$nһ����Ц�����ӵ��ݳ�ȥ�����뿪$N������Զ������ͷ��$N���ӣ�һ�Բ�����\n"
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") || (usage == "move"); 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 40 )
                return notify_fail("�������̫���ˣ�������ϰ������Ӱ����\n");
        me->receive_damage("jing", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-feiying/" + action;
}