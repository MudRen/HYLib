// where.c
// 06-14-95

inherit F_CLEAN_UP;

int main()
{
	object me=this_player();
        if (query_heart_beat(me)){
        write("���������������!!\n");
//        return 0;
//        tell_object(me,"���������������"��\n"NOR);
}
else
{
	me->set_heart_beat(1);
	me->set_temp("netdead",0);
        write("�ָ��������!!\n");
//        tell_object(me,"�ָ��������.!"��\n"NOR);
}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: where <��ҵ� ID>

���ָ����������֪���Ŀǰ���ڵ�λ��.

HELP
	);
	return 1;
}

