// art.c �����黭
// cck 3/7/97
//cool 10/10/98

inherit SKILL;

int valid_enable(string usage)
{
        return (usage == "magic");
}


int valid_learn(object me)
{
        if( (int)me->query_skill("lamaism",1) < (int)me->query_skill("kwan-yin-spells",1)) {
                return notify_fail("������ڷ���Ϊ�������޷����������Ĺ����������䡣\n");
        }

        if (me->query_skill("yujiamu-quan",1) < 120)
                return notify_fail("�����ڵĽ�����ĸȭ������ѧϰ�ɡ�\n");
        if (me->query_skill("dashou-yin",1) < 120)
                return notify_fail("���������ڴ���ӡ������ѧϰ�ɡ�\n");
        if (me->query_skill("xiangmo-chu",1) < 120)
                return notify_fail("�����ڵĽ�ս�ħ�Ʋ�����ѧϰ�ɡ�\n");
        if (me->query_skill("mingwang-jian",1) < 120)
                return notify_fail("�����ڵĲ���������������ѧϰ�ɡ�\n");
        if (me->query_skill("shenkong-xing",1) < 120)
                return notify_fail("�����ڵ�����в���������ѧϰ�ɡ�\n");





	return 1;
}



string perform_action_file(string action)
{
    return __DIR__"kwan-yin-spells/" + action;
}


int practice_skill(object me)
{       
        object bug; 
        if (me->query_skill("kwan-yin-spells",1) < 120)
                return notify_fail("�����ڵ�������������ϰ������ѧϰ�ɡ�\n");

        if (me->query_skill("yujiamu-quan",1) < 120)
                return notify_fail("�����ڵĽ�����ĸȭ������ѧϰ�ɡ�\n");
        if (me->query_skill("dashou-yin",1) < 120)
                return notify_fail("���������ڴ���ӡ������ѧϰ�ɡ�\n");
        if (me->query_skill("xiangmo-chu",1) < 120)
                return notify_fail("�����ڵĽ�ս�ħ�Ʋ�����ѧϰ�ɡ�\n");
        if (me->query_skill("mingwang-jian",1) < 120)
                return notify_fail("�����ڵĲ���������������ѧϰ�ɡ�\n");
        if (me->query_skill("shenkong-xing",1) < 120)
                return notify_fail("�����ڵ�����в���������ѧϰ�ɡ�\n");

          if( (int)me->query("neili") < 110 )
                return notify_fail("��ķ���������\n"); 
        if( (int)me->query("jing") < 100 )
                return notify_fail("��ľ����޷����С�\n"); 
        me->add("neili", -50);
        me->receive_damage("jing", 50); 
        write("���Ŀ�����������⣬��ʼ��ϰ������������....\n");
        return 1;
}       
