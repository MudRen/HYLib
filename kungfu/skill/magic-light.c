// magic-light

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ��ħ����\n");
        if( me->query_skill("magic-dark"))
        return notify_fail("���Ѿ�ѧϰ�˺ڰ�ħ����������ħ���޷�����!!\n");

	if( (int)me->query_skill("spells",1) < (int)me->query_skill("magic-light",1))
		return notify_fail("��Ļ���ħ����Ϊ�������޷����������Ĺ���ħ����\n");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"magic-light/" + action;
}

int practice_skill(object me)
{
	return notify_fail("ħ���޷�ͨ����ϰ���ɳ���\n");
}

